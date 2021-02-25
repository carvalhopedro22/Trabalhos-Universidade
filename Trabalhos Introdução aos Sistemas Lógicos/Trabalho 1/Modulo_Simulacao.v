`include "Modulo_Descricao.v"

module simulacao_traducao();

    reg iW, iX, iY, iZ;

    wire oA, oB, oC, oD, oE, oF, oG;

    traducao trad1(iW, iX, iY, iZ, oA, oB, oC, oD, oE, oF, oG);
    
    initial begin
        $dumpfile("simula_traducao.vcd");
        $dumpvars;
        $monitor("%g W=%b X=%b Y=%b Z=%b | a=%b b=%b c=%b d=%b e=%b f=%b g=%b", $time, iW, iX, iY, iZ, oA, oB, oC, oD, oE, oF, oG);

        #0 iW = 1'b0;
        #0 iX = 1'b0;
        #0 iY = 1'b0;
        #0 iZ = 1'b0;

        #1 iZ = 1'b1;

        #1 iY = 1'b1;
        #0 iZ = 1'b0;

        #1 iZ = 1'b1;

        #1 iX = 1'b1;
        #0 iY = 1'b0;
        #0 iZ = 1'b0;

        #1 iZ = 1'b1;

        #1 iY = 1'b1;
        #0 iZ = 1'b0;

        #1 iZ = 1'b1;

        #1 iW = 1'b1;
        #0 iX = 1'b0;
        #0 iY = 1'b0;
        #0 iZ = 1'b0;
        
        #1 iZ = 1'b1;

        #1 iY = 1'b1;
        #0 iZ = 1'b0;

        #1 iZ = 1'b1;

        #1 iX = 1'b1;
        #0 iY = 1'b0;
        #0 iZ = 1'b0;

        #1 iZ = 1'b1;

        #1 iY = 1'b1;
        #0 iZ = 1'b0;

        #1 iZ = 1'b1;
        
    end

endmodule