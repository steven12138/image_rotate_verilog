`define RAM_WIDTH 32 //Width of RAM
`define RAM_DEPTH 1024*1024 //Depth of RAM
`define ADDR_SZ 20 //Size of RAM address

module sram(
    clk,
    en, we,
    addr,
    data_in, data_out
);
    input clk, en, we;
    input [`ADDR_SZ-1:0] addr;
    input [`RAM_WIDTH-1:0] data_in;
    output reg [`RAM_WIDTH-1:0] data_out;

    reg [`RAM_WIDTH-1:0] mem [`RAM_DEPTH-1:0];

    always @(posedge clk) begin
        if (en) begin
            if (we) begin
                mem[addr] <= data_in;
            end
            else begin
                data_out <= mem[addr];
            end
        end
    end

endmodule : sram
