module si3(
    input CLOCK_50,
    input [3:0] KEY,
    input [9:0] SW,
    output [7:0]LEDG,
    output [9:0]LEDR    
);

reg [25:0]cont=0;
reg l=0;
assign LEDR = l;
always @(posedge  CLOCK_50) begin
    cont = cont + 1;
    if(cont == 0)begin
        l = ~l;
    end
end

endmodule