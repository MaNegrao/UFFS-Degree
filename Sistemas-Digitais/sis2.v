module pisca_leds(input clk1, output led1);

	reg [9:0]cont = 0;
	reg l = 0;
	assign led1 = l;

	always @(posedge clk1) begin
		cont = cont + 1;
		if(cont == 0) begin
			l = ~l;
		end
	end

endmodule

module testbench;
	wire led;
	reg clk = 0;

	pisca_leds leds1(clk, led);

	always #2 clk = ~clk;

	initial begin
		$dumpvars;
		#50000;
		$finish;
	end

endmodule
