#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    int nDiscos,x,y,move,nJogadas=0,z,continuar =1;
    char play;
    while(continuar ==1){
        printf("**********************************************\n");
        printf("*            Torre de Hanoi Menu             *\n");
        printf("*                                            *\n");
        printf("* Para jogar digite: p  Para sair, digite: x *\n");
        printf("*                                            *\n");
        printf("* Para sair durante o jogo digite: 0         *\n");
        printf("*                                            *\n");
        printf("**********************************************\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%c",&play);

        if(play == 'p'){
            Pilha *p1 = criar();
            Pilha *p2 = criar();
            Pilha *p3 = criar();
            printf("Digite a quantidade de discos (Maximo: 999): \n");
            scanf("%d",&nDiscos);
            empilhar(p1,(nDiscos+1));
            empilhar(p2,(nDiscos+1));
            empilhar(p3,(nDiscos+1));
            for(x=0 ; x<nDiscos ; x++){
                empilhar(p1,nDiscos-x);
            }



            printf("Para movimentar os discos digite o pino de origem e o pino destino  \n");
            printf("EX: 12 Movera o disco do pino 1 para o pino 2\n");

            while(tamanho(p3) < (nDiscos +1)){
                nJogadas++;

                printf("Jogadas possiveis: \n");
                if(topo(p1)<topo(p2)){
                printf("* 12 -Movimenta disco do pino 1 ao pino 2 *\n");
                }
                if(topo(p1)<topo(p3)){
                    printf("* 13 -Movimenta disco do pino 1 ao pino 3 *\n");
                }
                if(topo(p2)<topo(p1)){
                    printf("* 21 -Movimenta disco do pino 2 ao pino 1 *\n");
                }
                if(topo(p2)<topo(p3)){
                    printf("* 23 -Movimenta disco do pino 2 ao pino 3 *\n");
                }
                if(topo(p3)<topo(p1)){
                    printf("* 31 -Movimenta disco do pino 3 ao pino 1 *\n");
                }
                if(topo(p3)<topo(p2)){
                    printf("* 32 -Movimenta disco do pino 3 ao pino 2 *\n\n");
                }
                printf("Digite o proximo passo: \n");
                scanf("%d",&move);

                switch (move)
                {
                   case 12 :
                       if((topo(p1) < topo(p2)) && tamanho(p1)>0){
                            empilhar(p2,desempilhar(p1));
                            printf("Movimento valido\n");
                       }else{
                            printf("Movimento invalido\n");
                       }

                        printf("Pino 1\n");
                        listar(p1);
                        printf("Pino 2\n");
                        listar(p2);
                        printf("Pino 3\n");
                        listar(p3);
                    break;

                    case 13 :
                        if((topo(p1) < topo(p3)) && tamanho(p1)>0){
                            empilhar(p3,desempilhar(p1));
                            printf("Movimento valido\n");

                        }else{
                            printf("Movimento invalido\n");
                        }

                        printf("Pino 1\n");
                        listar(p1);
                        printf("Pino 2\n");
                        listar(p2);
                        printf("Pino 3\n");
                        listar(p3);
                        break;

                   case 21 :
                     if((topo(p2) < topo(p1)) && tamanho(p2)>0){
                            empilhar(p1,desempilhar(p2));
                            printf("Movimento valido\n");

                       }else{
                            printf("Movimento invalido\n");
                       }
                    printf("Pino 1\n");
                    listar(p1);
                    printf("Pino 2\n");
                    listar(p2);
                    printf("Pino 3\n");
                    listar(p3);
                   break;

                   case 23 :
                     if((topo(p2) < topo(p3)) && tamanho(p1)>0){
                            empilhar(p3,desempilhar(p2));
                            printf("Movimento valido\n");

                       }else{
                            printf("Movimento invalido\n");
                       }
                    printf("Pino 1\n");
                    listar(p1);
                    printf("Pino 2\n");
                    listar(p2);
                    printf("Pino 3\n");
                    listar(p3);
                   break;

                   case 31 :
                     if((topo(p3) < topo(p1)) && tamanho(p3)>0){
                            empilhar(p1,desempilhar(p3));
                            printf("Movimento valido\n");
                       }else{
                            printf("Movimento invalido\n");
                       }
                    printf("Pino 1\n");
                    listar(p1);
                    printf("Pino 2\n");
                    listar(p2);
                    printf("Pino 3\n");
                    listar(p3);
                   break;

                   case 32 :
                     if((topo(p3) < topo(p2)) && tamanho(p3)>0){
                            empilhar(p2,desempilhar(p3));
                            printf("Movimento valido\n");

                       }else{
                            printf("Movimento invalido\n");
                       }
                    printf("Pino 1\n");
                    listar(p1);
                    printf("Pino 2\n");
                    listar(p2);
                    printf("Pino 3\n");
                    listar(p3);
                   break;

                   case 0:
                        return 0;

                   default:
                     printf("Movimento invalido\n");
                }
                printf("Numero de jogadas: %d\n",nJogadas);

            }
            printf("Parabens voce ganhou!\n");
            Pilha *aux = criar();
            int tamOriginal = tamanho(p3);
            for(z=1; z < tamOriginal; z++){
                empilhar(aux,desempilhar(p3));
            }

             for(z=1; z < tamOriginal; z++){
                empilhar(p1,desempilhar(aux));
            }

            printf("Pino 1\n");
            listar(p1);

            destruir(p1);
            destruir(p2);
            destruir(p3);
            destruir(aux);

        }
        printf("Para Jogar novamente digite: 1 \n");
        scanf("%d",&continuar);
        getchar();

}

	return 0;
}
