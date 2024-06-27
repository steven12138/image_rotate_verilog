module our(clk);
    input clk;
    initial begin
        if (clk) begin
            $display("Hello World");
        end

        $finish;
    end
endmodule : our
