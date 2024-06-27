`define RAM_WIDTH 32 //Width of RAM
`define RAM_DEPTH 1024*1024 //Depth of RAM
`define ADDR_SZ 20 //Size of RAM address

module adapter(
    input mode,
    input clk_in,
    input start_in,
    input [23:0] data_in, // 8bit-rgb image
    input jump_in,

    output reg clk_out,
    output reg start_out,
    output reg [23:0] data_out,
    output reg jump_out
);

    initial begin
        $display("Hello World!");
    end

    assign clk_out = clk_in;
    assign start_out = mode & start_in;
    assign data_out = data_in;
    assign jump_out = jump_in;


endmodule: adapter
