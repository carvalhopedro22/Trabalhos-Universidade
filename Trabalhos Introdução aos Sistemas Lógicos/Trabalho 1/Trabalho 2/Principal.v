module tp2 (clock, reset, ok, tom, in1, in2, in3, out1, out2, fim);

    input clock, reset, ok, tom, in1, in2, in3;
    output reg out1, out2, fim;

    parameter inicio = 4'b0000;
    parameter letra1 = 4'b0001;
    parameter letra2 = 4'b0010;
    parameter adjetivo1 = 4'b0011;
    parameter adjetivo2 = 4'b0100;
    parameter adjetivoComparativo = 4'b0101;
    parameter adverbio = 4'b0110;
    parameter erro = 4'b0111;
    parameter fimAdj = 4'b1000;
    parameter fimAdjComp = 4'b1001;
    parameter fimAdv = 4'b1010;

    reg [3:0] state;
    reg [3:0] nextState;
		
    always @(posedge clock) begin 
        if(reset) state = inicio;
        else state = nextState;
    end 
	
    always @(tom or in1 or in2 or in3 or state) begin
		if(ok) begin
			case(state)
				inicio:
				begin
				  if((~tom && ~in1 && ~in2 && ~in3) || (tom && ~in1 && ~in2 && ~in3)) nextState = erro;
				  else nextState = letra1;
				end
				letra1:
				begin
				  if((~tom && ~in1 && ~in2 && ~in3) || (tom && ~in1 && ~in2 && ~in3)) nextState = erro;
				  else nextState = letra2;
				end
				letra2:
				begin
				  if(~tom && in1 && in2 && ~in3) nextState = adjetivo1;
				  else if(~tom && in1 && in2 && in3) nextState = adjetivo2;
				  else nextState = erro;
				end
				adjetivo1:
				begin
				  if(~tom && in1 && in2 && in3) nextState = adverbio;
				  else if(tom && ~in1 && ~in2 && in3) nextState = adjetivoComparativo;
				  else if((~tom && ~in1 && ~in2 && ~in3) || (tom && ~in1 && ~in2 && ~in3)) nextState = fimAdj;
				  else nextState = erro;
				end
				adjetivo2:
				begin
				  if(tom && ~in1 && in2 && ~in3) nextState = adjetivoComparativo;
				  else if((~tom && ~in1 && ~in2 && ~in3) || (tom && ~in1 && ~in2 && ~in3)) nextState = fimAdj;
				  else nextState = erro;
				end
				adverbio:
				begin
				  if((~tom && ~in1 && ~in2 && ~in3) || (tom && ~in1 && ~in2 && ~in3)) nextState = fimAdv;
				  else nextState = erro;
				end
				adjetivoComparativo:
				begin
				  if((~tom && ~in1 && ~in2 && ~in3) || (tom && ~in1 && ~in2 && ~in3)) nextState = fimAdjComp;
				  else nextState = erro;
				end
			endcase
		end 
	end 
	
    always @(state) begin 
        case(state)
            inicio:
            begin
              out1 <= 0;
              out2 <= 0;
              fim <= 0;
            end
            letra1:
            begin
              out1 <= 0;
              out2 <= 0;
              fim <= 0;
            end
            letra2:
            begin
              out1 <= 0;
              out2 <= 0;
              fim <= 0;
            end
            adjetivo1:
            begin
              out1 <= 0;
              out2 <= 1;
              fim <= 0;
            end
            adjetivo2:
            begin
              out1 <= 0;
              out2 <= 1;
              fim <= 0;
            end
            adjetivoComparativo:
            begin
              out1 <= 1;
              out2 <= 0;
              fim <= 0;
            end
            adverbio:
            begin
              out1 <= 1;
              out2 <= 1;
              fim <= 0;
            end
            fimAdj:
            begin
              out1 <= 0;
              out2 <= 1;
              fim <= 1; 
            end
            fimAdjComp:
            begin
              out1 <= 1;
              out2 <= 0;
              fim <= 1;
            end
            fimAdv:
            begin
              out1 <= 1;
              out2 <= 1;
              fim <= 1;
            end
            erro:
            begin
              out1 <= 0;
              out2 <= 0;
              fim <= 1;
            end
        endcase
	end 
endmodule