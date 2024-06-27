`define RAM_WIDTH 32 // Width of RAM
`define RAM_DEPTH 1024*1024 // Depth of RAM
`define ADDR_SZ 20 // Size of RAM address

module adapter(
    input rst,
    input mode,
    input clk,
    input [23:0] data_in, // 8bit-rgb image

    output reg [23:0] data_out,
    output reg jump_out,
    output reg output_done // New output signal
);

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
        $display("x: %d, y: %d, addr: %h, data_in: %h, data_out: %h, jump_out: %h, output_done: %b", x, y, addr, mem_in, mem_out, jump_out, output_done);
        $display("mode %b, next_x: %d, next_y: %d", mode, next_x, next_y);
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            x <= 0;
            y <= 0;
            jump_out <= 0;
            output_done <= 0; // Initialize output_done
        end else begin
            x <= next_x;
            y <= next_y;
            jump_out <= (next_x == 8'd255) ? 1'b1:1'b0;
            output_done <= (next_x == 8'd255 && next_y == 8'd255 && mode == 1'b1) ? 1'b1:0;
        end
    end

    always @(*) begin
        if (mode == 1'b0) begin
            if (x == 8'd255) begin
                next_x = 0;
                next_y = y+1;
            end else begin
                next_x = x+1;
                next_y = y;
            end
        end else begin
            if (x == 8'd255) begin
                next_x = 0;
                next_y = y+1;
            end else begin
                next_x = x+1;
                next_y = y;
            end
        end
    end

    // Transform the address for 90-degree rotation
    assign addr = (mode == 1'b0) ? {4'b0, x, y}:{4'b0, y, 8'd255-x};
    assign mem_in = {8'b0, data_in};
    assign data_out = mem_out[23:0];

endmodule
