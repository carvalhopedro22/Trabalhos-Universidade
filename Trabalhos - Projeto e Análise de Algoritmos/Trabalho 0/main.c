#include <stdio.h>
#include <stdlib.h>

int numero, numero2, quantidade;
int main(){
    while(1){
        numero2 = 1;
        printf("            PROGRAMA GERADOR DE OBRA DE ARTE:               \n");
        printf("============================================================\n");
        printf("Escolha o tipo de figura a ser usada para criar a obra:    |\n");
        printf("1 - Asterisco Simples.                                     |\n");
        printf("2 - Simbolo de Soma com Asteriscos.                        |\n");
        printf("3 - Letra X com Asteriscos.                                |\n");
        printf("4 - Figuras Aleatórias.                                    |\n");
        printf("5 - Opção de Obra de Arte Criada por mim (Fantasminha).    |\n");
        printf("6 - Opção de Obra de Arte Criada por mim (Pac-Man).        |\n");
        printf("7 - Sair do programa.                                      |\n");
        printf("============================================================\n");
        printf("\n");
        printf("\n");
    
        printf("Digite a opção de figura desejada: ");
        scanf("%d",&numero);
        if(numero == 7) //A opção 7 sai do programa.
            break;
        
        printf("Digite a quantidade de figuras (menor ou igual a zero para quantidade aleatória, maior que 100 para quantidade igual a 100): ");
        scanf("%d",&quantidade);
        printf("\n");
        
        while(numero2==1){


            if(quantidade > 100 && (numero == 1 || numero == 2 || numero == 3 || numero == 4))
            //Se a quantidade for maior que 100 para as figuras básicas, será considerado 100 como quantidade.
                quantidade = 100; 
            else if (quantidade > 100 && (numero == 5 || numero == 6))
            //Se a quantidade for maior que 100 para as artes criadas por mim, será considerado um sorteio entre 1 e 35 por conta do tamanho deles.
                quantidade = (rand()%35)+1;  

            else if(quantidade <= 0){ //Se a quantidade for menor ou igual a 0:
                if(numero == 5){ //Se a opção for do fantasminha:
                    quantidade = (rand()%35)+1; //Será sorteado uma quantidade entre 0 e 35, para o fantasminha por conta do tamanho dele. 
                }else if (numero == 6){
                    quantidade = (rand()%35)+1; //Será sorteado uma quantidade entre 0 e 35, para o Pac-Man por conta do tamanho dele. 
                }else{
                    quantidade = (rand()%100) + 1; //Será sorteado uma quantidade entre 0 e 100 para as figuras asterisco, cruz, X. 
                } 
            }
          
            //Quadro -> Construção
            int i,j;
            char quadro[20][80] = { };
            for(i = 0; i < 20; i ++){
                for(j = 0; j < 80; j ++){
                    quadro[i][j]= ' ';
                }
            }
            for(i = 0; i < 20; i ++){
                quadro[i][0] = '|';
                quadro[i][79] = '|';
            }
            for(j = 0; j < 80; j++){
                quadro[0][j] = '-';
                quadro[19][j] = '-';
            }
          
            int a,b,c,figura;
            switch(numero){
                case 1:
                //Devemos gerrar uma posicao aleatória dentro do quadro.
                for(a = 0; a < quantidade; a ++){ // Aqui estamos interessados em gerar uma possição válida.
                    b = (rand() % 18) + 1; // Componente da linha.
                    c = (rand() % 78) + 1; // Componente da Coluna.
                    while (quadro[b][c] == '*'){ // Enquanto as posições geradas forem ocupadas, gere novas posições.
                        b = (rand() % 18) + 1; // Componente da linha.
                        c = (rand() % 78) + 1; // Componente da Coluna.
                    }
                    quadro[b][c] = '*'; // Coloca no quadro o caractere.
                }
                break;
                
                case 2:
                    for (a=0;a<quantidade;a++){
                        b = (rand()% 18) + 1;
                        c = (rand()% 78) + 1; 
                        while (quadro[b][c] == '*' || quadro[b+1][c] == '*' || quadro[b-1][c] == '*' || quadro[b][c+1] == '*' || quadro[b][c-1] == '*' || b-1==0 || b+1==19 || c-1 ==0 || c+1 == 79){ 
                            b = (rand()% 18) + 1;
                            c = (rand()% 78) + 1;
                        }
                        quadro[b][c] = '*';
                        quadro[b+1][c] = '*'; 
                        quadro[b-1][c] = '*';
                        quadro[b][c+1] = '*';
                        quadro[b][c-1] = '*';
                    }
                    break;

                case 3:
                    for(a = 0; a < quantidade; a ++){
                        b = (rand()% 18) + 1;
                        c = (rand()% 78) + 1;
                        while (quadro[b][c] == '*' || quadro[b-1][c+1] == '*' || quadro[b-1][c-1] == '*' || quadro[b+1][c-1]== '*' || quadro[b+1][c+1] == '*'|| b-1 == 0 || b+1 == 19 || c-1 == 0 || c+1 == 79 ){
                            b = (rand()% 18) + 1;
                            c = (rand()% 78) + 1;
                        }      
                        quadro[b][c] = '*';
                        quadro[b-1][c+1] = '*';
                        quadro[b-1][c-1] = '*';
                        quadro[b+1][c-1] = '*';
                        quadro[b+1][c+1] = '*';
                    }     
                    break;

                case 4:
                    for(a = 0; a < quantidade; a++){
                        b = (rand()% 18) + 1;
                        c = (rand()% 78) + 1;
                        figura = (rand()%3); //Exclusivo o último número

                        if(figura == 0){
                            while(quadro[b][c] == '*'){
                                b = (rand()% 18) + 1;
                                c = (rand()% 78) + 1;
                            }
                            quadro[b][c] = '*';  
                        }

                        else if(figura == 1){
                            while(quadro[b][c] == '*' || quadro[b+1][c]=='*' || quadro[b-1][c] == '*'|| quadro[b][c+1]=='*' || quadro[b][c-1]=='*' || b-1 == 0 || b+1 == 19 || c-1 == 0 || c+1 == 79 ){
                                b = (rand()% 18) + 1;
                                c = (rand()% 78) + 1;
                            }
                            quadro[b][c] = '*';
                            quadro[b+1][c] = '*'; 
                            quadro[b-1][c] = '*';
                            quadro[b][c+1] = '*';
                            quadro[b][c-1] = '*';
                        }

                        else if(figura == 2){
                            while (quadro[b][c] == '*' || quadro[b-1][c+1] == '*' || quadro[b-1][c-1] == '*' || quadro[b+1][c-1]== '*' || quadro[b+1][c+1] == '*'|| b-1 == 0 || b+1 == 19 || c-1 == 0 || c+1 == 79 ){
                            b = (rand()% 18) + 1;
                            c = (rand()% 78) + 1;
                            }      
                            quadro[b][c] = '*';
                            quadro[b-1][c+1] = '*';
                            quadro[b-1][c-1] = '*';
                            quadro[b+1][c-1] = '*';
                            quadro[b+1][c+1] = '*';
                        }    
                    }
                    break;


                case 5:
                    for (a=0;a<quantidade;a++){
                        b = (rand()% 18) + 1;
                        c = (rand()% 78) + 1; 
                    
                        while(quadro[b+1][c] == '-' || quadro[b+1][c] == '|' ||quadro[b+1][c] == '`'||quadro[b+1][c] == '^'||quadro[b+1][c] == 'O'||quadro[b+1][c] == '.' || 
                        
                        quadro[b+1][c-1] == '.' || quadro[b+1][c-1] == 'O' || quadro[b+1][c-1] == '^' || quadro[b+1][c-1] == '`' || quadro[b+1][c-1] =='|' || quadro[b+1][c-1] == '-' ||

                        quadro[b+2][c-2] == '-' || quadro[b+2][c-2] == '|' ||quadro[b+2][c-2] == '`'||quadro[b+2][c-2] == '^'||quadro[b+2][c-2] == 'O'||quadro[b+2][c-2] == '.' ||

                        quadro[b+3][c-2] == '-' || quadro[b+3][c-2] == '|' ||quadro[b+3][c-2] == '`'||quadro[b+3][c-2] == '^'||quadro[b+3][c-2] == 'O'||quadro[b+3][c-2] == '.' ||

                        quadro[b+4][c-2] == '-' || quadro[b+4][c-2] == '|' ||quadro[b+4][c-2] == '`'||quadro[b+4][c-2] == '^'||quadro[b+4][c-2] == 'O'||quadro[b+4][c-2] == '.'||
            
                        quadro[b+4][c-1] == '-' || quadro[b+4][c-1] == '|' ||quadro[b+4][c-1] == '`'||quadro[b+4][c-1] == '^'||quadro[b+4][c-1] == 'O'||quadro[b+4][c-1] == '.' ||

                        quadro[b+4][c]== '-' || quadro[b+4][c]== '|' ||quadro[b+4][c]== '`'||quadro[b+4][c]== '^'||quadro[b+4][c]== 'O'||quadro[b+4][c]== '.' ||

                        quadro[b+4][c+1] == '-' || quadro[b+4][c+1] == '|' ||quadro[b+4][c+1] == '`'||quadro[b+4][c+1] == '^'||quadro[b+4][c+1] == 'O'||quadro[b+4][c+1] == '.' ||

                        quadro[b+4][c+2] == '-' || quadro[b+4][c+2] == '|' ||quadro[b+4][c+2] == '`'||quadro[b+4][c+2] == '^'||quadro[b+4][c+2] == 'O'||quadro[b+4][c+2] == '.' ||

                        quadro[b+3][c+2] == '-' || quadro[b+3][c+2] == '|' ||quadro[b+3][c+2] == '`'||quadro[b+3][c+2] == '^'||quadro[b+3][c+2] == 'O'||quadro[b+3][c+2] == '.' ||

                        quadro[b+2][c+2] == '-' || quadro[b+2][c+2] == '|' ||quadro[b+2][c+2] == '`'||quadro[b+2][c+2] == '^'||quadro[b+2][c+2] == 'O'||quadro[b+2][c+2] == '.' ||

                        quadro[b+2][c]== '-' || quadro[b+2][c]== '|' ||quadro[b+2][c]== '`'||quadro[b+2][c]== '^'||quadro[b+2][c]== 'O'||quadro[b+2][c]== '.' ||

                        quadro[b+2][c+1] == '-' || quadro[b+2][c+1] == '|' ||quadro[b+2][c+1] == '`'||quadro[b+2][c+1] == '^'||quadro[b+2][c+1] == 'O'||quadro[b+2][c+1] == '.' ||

                        quadro[b+1][c+1]== '-' || quadro[b+1][c+1]== '|' ||quadro[b+1][c+1]== '`'||quadro[b+1][c+1]== '^'||quadro[b+1][c+1]== 'O'||quadro[b+1][c+1]== '.'){
                            b = (rand()%18)+1;
                            c = (rand()%78)+1;
                        }
                        quadro[b+1][c] = '-'; 
                        quadro[b+1][c-1] = '.'; 
                        quadro[b+2][c-2] = '|'; 
                        quadro[b+3][c-2] = '|'; 
                        quadro[b+4][c-2] = '`'; 
                        quadro[b+4][c-1] = '^'; 
                        quadro[b+4][c] = '^'; 
                        quadro[b+4][c+1] = '^'; 
                        quadro[b+4][c+2] = '`'; 
                        quadro[b+3][c+2] = '|'; 
                        quadro[b+2][c+2] = '|'; 
                        quadro[b+2][c] = 'O'; 
                        quadro[b+2][c+1] = 'O'; 
                        quadro[b+1][c+1] = '.';
                    }
                    break;


                    case 6: 
                        for (a=0;a<quantidade;a++){
                            b = (rand()% 18) + 1;
                            c = (rand()% 78) + 1; 
                    
                            while(quadro[b+1][c]== '.' || quadro[b+1][c] == '-' || quadro[b+1][c] == '/' || quadro[b+1][c] == '_' || quadro[b+1][c] == '`'||
                            quadro[b+1][c+1] == '-' || quadro[b+1][c+1] == '.' || quadro[b+1][c+1] == '/' || quadro[b+1][c+1] == '_' || quadro[b+1][c+1] == '`'||
                            
                            quadro[b+1][c+2] =='-' || quadro[b+1][c+2] == '.' || quadro[b+1][c+2] == '/' || quadro[b+1][c+2] == '_' || quadro[b+1][c+2] == '`'||
                            
                            quadro[b+1][c+3] == '.' || quadro[b+1][c+3] == '-' || quadro[b+1][c+3] == '/' || quadro[b+1][c+3] == '_' || quadro[b+1][c+3] == '`'||
                        
                            quadro[b+2][c+4] == '`' || quadro[b+2][c+4] == '-' || quadro[b+2][c+4] == '/' || quadro[b+2][c+4] == '_' || quadro[b+2][c+4] == '.'||
                            
                            quadro[b+2][c+3]=='-' || quadro[b+2][c+3] == '.' || quadro[b+2][c+3] == '/' || quadro[b+2][c+3] == '_' || quadro[b+2][c+3] == '`'||
                            
                            quadro[b+2][c+1] =='_' ||quadro[b+2][c+1] == '-' || quadro[b+2][c+1] == '/' || quadro[b+2][c+1] == '`' || quadro[b+2][c+1] == '.'||
                            
                            quadro[b+2][c+2]=='.' ||quadro[b+2][c+2] == '-' || quadro[b+2][c+2] == '/' || quadro[b+2][c+2] == '_' || quadro[b+2][c+2] == '`'||
                            
                            quadro[b+3][c+3]=='`' || quadro[b+3][c+3] == '-' || quadro[b+3][c+3] == '/' || quadro[b+3][c+3] == '_' || quadro[b+3][c+3] == '.'||
                            
                            quadro[b+3][c+5] == '.' ||quadro[b+3][c+5] == '-' || quadro[b+3][c+5] == '/' || quadro[b+3][c+5] == '_' || quadro[b+3][c+5] == '`'||
                            
                            quadro[b+3][c+4] == '-' || quadro[b+3][c+4] == '`' || quadro[b+3][c+4] == '/' || quadro[b+3][c+4] == '_' || quadro[b+3][c+4] == '.'||
                            
                            quadro[b+4][c+3]=='`' ||quadro[b+4][c+3] == '-' || quadro[b+4][c+3] == '/' || quadro[b+4][c+3] == '_' || quadro[b+4][c+3] == '.'||
                            
                            quadro[b+4][c+2] == '-' || quadro[b+4][c+2] == '`' || quadro[b+4][c+2] == '/' || quadro[b+4][c+2] == '_' || quadro[b+4][c+2] == '.'||
                            
                            quadro[b+4][c+1] == '-' ||quadro[b+4][c+1] == '`' || quadro[b+4][c+1] == '/' || quadro[b+4][c+1] == '_' || quadro[b+4][c+1] == '.'||
                            
                            quadro[b+4][c] == '`' ||quadro[b+4][c] == '-' || quadro[b+4][c] == '/' || quadro[b+4][c] == '_' || quadro[b+4][c] == '.'||
                            
                            quadro[b+3][c-1] == '`' ||quadro[b+3][c-1] == '-' || quadro[b+3][c-1] == '/' || quadro[b+3][c-1] == '_' || quadro[b+3][c-1] == '.'|| 
                            
                            quadro[b+2][c-1]== '/' || quadro[b+2][c-1] == '-' || quadro[b+2][c-1] == '`' || quadro[b+2][c-1] == '_' || quadro[b+2][c-1] == '.' || 
                            
                            c-1 == 0 || c== 0 || c+1 == 0 || c+2 == 0 || c+3 == 0 || c+4 == 0 || c+5 == 0 ||c-1 == 79 || c == 79|| c+1 == 79 ||c+2 == 79 || c+3 == 79 || c+4 == 79 || c+5 == 79){
                                b = (rand()%18)+1;
                                c = (rand()%78)+1;
                            }
                            quadro[b+1][c]= '.';
                            quadro[b+1][c+1] = '-';
                            quadro[b+1][c+2] ='-';
                            quadro[b+1][c+3] = '.';
                            quadro[b+2][c+4] = '`';
                            quadro[b+2][c+3] ='-';
                            quadro[b+2][c+1] ='_';
                            quadro[b+2][c+2] ='.';
                            quadro[b+3][c+3]='`';
                            quadro[b+3][c+5] = '.';
                            quadro[b+3][c+4] = '-'; 
                            quadro[b+4][c+3]='`';
                            quadro[b+4][c+2] = '-';
                            quadro[b+4][c+1] = '-';
                            quadro[b+4][c] = '`';
                            quadro[b+3][c-1] = '`';
                            quadro[b+2][c-1]= '/';
                        }
                        break;
                    }
          
        //Quadro -> Impressão
        for(i = 0; i < 20; i ++){
            for(j = 0; j < 80; j ++){
                printf("%c",quadro[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        printf("\n");  
    
        printf("===========================================================\n");
        printf("Deseja gerar o quadro novamente com os mesmos parâmetros? |\n");
        printf("1 - Sim                                                   |\n");
        printf("2 ou outro valor - Não                                    |\n");
        printf("===========================================================\n");
            
        printf("Digite a opção deseja (1 ou 2): ");
        scanf("%d",&numero2);
        printf("\n");
        printf("\n");
    }
  }
  return 0;

}