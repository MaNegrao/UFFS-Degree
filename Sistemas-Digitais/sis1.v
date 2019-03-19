module onda;

reg clock = 0;
reg x = 0;

initial begin
	$dumpvars(0, x, clock);
	#100 $finish;
end

always #2 begin
	clock = ~clock;	
end

always @(posedge clock) begin
	x = ~x;
end


endmodule
