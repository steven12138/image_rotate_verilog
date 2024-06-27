`define RAM_WIDTH 32 // Width of RAM
`define RAM_DEPTH 1024*1024 // Depth of RAM
`define ADDR_SZ 20 // Size of RAM address

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

    reg [7:0] x, next_x;
    reg [7:0] y, next_y;
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

    always @(posedge clk) begin
        $display("x: %d, y: %d, addr: %h, data_in: %h, data_out: %h, jump_out: %h", x, y, addr, mem_in, mem_out, jump_out);
        $display("start_in %b, mode %b, jump_in %b", start_in, mode, jump_in);
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            x <= 0;
            y <= 0;
            jump_out <= 0;
        end else begin
            x <= next_x;
            y <= next_y;
            jump_out <= (next_x == 0) ? 1'b1 : 1'b0; // Update jump_out only here
        end
    end

    always @(*) begin
        if (mode == 1'b0) begin
            if (x == 8'd255) begin
                next_x = 0;
                next_y = y + 1;
            end else begin
                next_x = x + 1;
                next_y = y;
            end
        end else begin
            if (x == 8'd255) begin
                next_x = 0;
                next_y = y + 1;
            end else begin
                next_x = x + 1;
                next_y = y;
            end
        end
    end

    assign addr = (mode == 1'b0) ? {4'b0, x, y} : {4'b0, y, x};
    assign mem_in = {8'b0, data_in};
    assign data_out = mem_out[23:0];

endmodule
