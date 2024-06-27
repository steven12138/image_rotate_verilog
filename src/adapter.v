`define RAM_WIDTH 32 //Width of RAM
`define RAM_DEPTH 1024*1024 //Depth of RAM
`define ADDR_SZ 20 //Size of RAM address

module adapter(
    input rst,
    input mode,
    input clk,
    input start_in,
    input [23:0] data_in, // 8bit-rgb image
    input jump_in,

    output reg [23:0] data_out,
    output reg jump_out
);

    initial begin
        $display("Hello World!");
    end

    //  [is_write, is_read, is_endl]
    parameter IDLE = 3'b000,
              WRITE_NEXT = 3'b100,
              READ_NEXT = 3'b010,
              WRITE_ENDLINE = 3'b101,
              READ_ENDLINE = 3'b011;

    reg [2:0] state, next_state;
    reg [7:0] x;
    reg [7:0] y;
    reg [19:0] addr;
    reg [31:0] mem_in;

    /* verilator lint_off UNUSEDSIGNAL */
    reg [31:0] mem_out;

    sram ram(
        .clk(clk),
        .en(1'b1),
        .we(~mode),
        .addr(addr),
        .data_in(mem_in),
        .data_out(mem_out)
    );

    always_ff @(posedge clk or posedge rst) begin
        if (rst) state <= IDLE;
        else state <= next_state;
    end

    assign addr = {4'b0, x, y};
    assign mem_in = {8'b0, data_in};
    assign data_out = mem_out[23:0];

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            next_state <= IDLE;
            x <= 0;
            y <= 0;
        end else begin
            case (state)
                IDLE: begin
                    if (start_in == 1'b1 && mode == 1'b0) begin
                        next_state <= WRITE_NEXT;
                        x <= 0;
                        y <= 0;
                    end
                    else if (start_in == 1'b1 && mode == 1'b1) begin
                        next_state <= READ_NEXT;
                        x <= 0;
                        y <= 0;
                    end
                    else begin
                        next_state <= IDLE;
                    end
                end
                READ_NEXT: begin
                    if (jump_in == 1'b1) begin
                        next_state <= READ_ENDLINE;
                        x <= 0;
                        y <= y + 1;
                    end
                    else begin
                        next_state <= READ_NEXT;
                        x <= x + 1;
                    end
                    jump_out <= 0;
                end
                READ_ENDLINE: begin
                    next_state <= READ_NEXT;
                    jump_out <= 1;
                end
                WRITE_NEXT: begin
                    if (jump_in == 1'b1) begin
                        next_state <= WRITE_ENDLINE;
                        x <= 0;
                        y <= y + 1;
                    end
                    else begin
                        next_state <= WRITE_NEXT;
                        x <= x + 1;
                    end
                end
                WRITE_ENDLINE: begin
                    next_state <= WRITE_NEXT;
                end
                default: next_state <= IDLE;
            endcase
        end
    end

endmodule: adapter
