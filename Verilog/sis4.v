module si4(
    input CLOCK_50,
    input [3:0] KEY,
    input [9:0] SW,
    output [7:0]LEDG,
    output [9:0]LEDR    
);

reg [27:0]cont=0;
reg l0=0;
reg l1 = 0;
reg l2 = 0;
reg l3 = 0;
reg l4 = 0;
reg l5 = 0;
reg l6 = 0;
reg l7 = 0;
assign LEDR[0] = l0;
assign LEDR[1] = l1;
assign LEDR[2] = l2;
assign LEDR[3] = l3;
assign LEDR[4] = l4;
assign LEDR[5] = l5;
assign LEDR[6] = l6;
assign LEDR[7] = l7;

always @(posedge  CLOCK_50) begin
    cont = cont + 1;
    if(cont == 33554432)begin
        l0 = ~l0;
    end
    if(cont == 67108854)begin
        l1 = ~l1;
    end
    if(cont == 100663296)begin
        l2 = ~l2;
    end
    if(cont == 134217728)begin
        l3 = ~l3;
    end
    if(cont == 167772160)begin
        l4 = ~l4;
    end
    if(cont == 201326592)begin
        l5 = ~l5;
    end
    if(cont == 234881024)begin
        l6 = ~l6;
    end
    if(cont == 268435456)begin
        l7 = ~l7;
    end
end

endmodule