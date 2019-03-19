module piscaleds(
input CLOCK_50, 
input [3:0] KEY, 
input [9:0] SW,
output [7:0]LEDG,
output [9:0]LEDR
);

//assign LEDG = KEY;
//assign LEDR = SW;

reg [27:0] contador = 0;
reg l = 0;

assign LEDG[0] = l;
assign LEDG[1] = l;
assign LEDG[2] = l;
assign LEDG[3] = l;
assign LEDG[4] = l;
assign LEDG[5] = l;
assign LEDG[6] = l;
assign LEDG[7] = l;

assign LEDR[0] = SW[0] * SW[1];
assign LEDR[1] = SW[0] * SW[1];
assign LEDR[2] = SW[0] * SW[1];
assign LEDR[3] = SW[0] * SW[1];
assign LEDR[4] = SW[0] * SW[1];
assign LEDR[5] = SW[0] * SW[1];
assign LEDR[6] = SW[0] * SW[1];
assign LEDR[7] = SW[0] * SW[1];
assign LEDR[8] = SW[0] * SW[1];
assign LEDR[9] = SW[0] * SW[1];


always @(posedge CLOCK_50) begin
    contador = contador + 1;
    if(SW[0] == 0 && SW[1] == 0) begin
        if(contador == 50000000) begin
        contador = 0;
        l = ~l;
        end
    end
    if(SW[0] ==0 && SW[1]==1) begin
        if(contador == 90000000)begin
        contador = 0;
        l = ~l; 
        end
    end
    if(SW[0] == 1 && SW[1]==0) begin
        if(contador == 25000000)begin
        contador = 0;
        l = ~l; 
        end
    end
end


endmodule