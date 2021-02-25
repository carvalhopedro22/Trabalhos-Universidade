`include "Principal.v"

module simulacao_traducao();

    reg clock, reset, ok, tom, in1, in2, in3;

    wire out1, out2, fim;

    tp2 simula(clock, reset, ok, tom, in1, in2, in3, out1, out2, fim);
    
    initial begin
        $dumpfile("simulacao.vcd");
        $dumpvars;
		#0 clock = 1'b0;
		
        #0 reset = 1'b1;
		
		#1 clock = 1'b1;
		
		#1 reset = 1'b0;
		
		#1 clock = 1'b0;
		
		
		
        #1 ok = 1'b1;
        #0 tom = 1'b0;
        #0 in1 = 1'b0;
        #0 in2 = 1'b0;
        #0 in3 = 1'b1;

        #1 clock = 1'b1;
        #1 clock = 1'b0;

        #1 tom = 1'b1;
        #0 in1 = 1'b1;
        #0 in2 = 1'b1;
        #0 in3 = 1'b0;

        #1 clock = 1'b1;
        #1 clock = 1'b0;

        #1 tom = 1'b0;
        #0 in1 = 1'b1;
        #0 in2 = 1'b1;
        #0 in3 = 1'b0;

        #1 clock = 1'b1;
        #1 clock = 1'b0;

        #1 tom = 1'b0;
        #0 in1 = 1'b1;
        #0 in2 = 1'b1;
        #0 in3 = 1'b1;

        #1 clock = 1'b1;
        #1 clock = 1'b0;

        #1 tom = 1'b1;
        #0 in1 = 1'b0;
        #0 in2 = 1'b0;
        #0 in3 = 1'b0;
		
		#1 clock = 1'b1;
        #1 clock = 1'b0;

		#1 $finish;
        
        
    end

endmodule