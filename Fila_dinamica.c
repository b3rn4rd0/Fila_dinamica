#include <stdio.h>
#include <stdlib.h>

typedef struct no{
 int valor;
 struct no *prox;
 }No;

 typedef struct {
 No *ini, *fim;
 int tam;
 }Fila;
 /*---------------------------------------------*/
 void criar(Fila *fila){
  fila->ini =  NULL;
   fila->fim = NULL;
    fila->tam= 0;
 }
/*------------------------------------------------*/
void Inserir(Fila *fila, int num){
 No *aux, *novo = malloc(sizeof(No));
 if(novo){
    novo -> valor = num;
    novo -> prox = NULL;
    if(fila->ini == NULL){
        fila->ini = novo;
        fila->fim = novo;
    }
    else{
        fila->fim->prox=novo;
        fila->fim=novo;
       /* aux =*fila;  //este codigo servia antes de criar o inicio e fim
    while(aux->prox)
        aux = aux ->prox;
    aux ->prox=novo;*/
    }
    fila->tam++;
 }
 else
    printf("\nErro ao alocar memoria.");
 }
/*------------------------------------------*/
 No* Remover(Fila *fila){
   No *remover = NULL;
    if(fila->ini){
        remover = fila->ini;
        fila->ini = remover ->prox;
        fila->tam--;
    } else
    printf("\nFila vazia.");
    return remover;
 }
/*------------------------------------------*/
void Imprimir (Fila *fila){
    No *aux= fila->ini;
	printf("\nInicio da fila:\n");
	while(aux){
        printf("|%d |", aux->valor);
        aux = aux->prox;
	}
	printf("\nFim da fila.");
	return 0;
}
//-------------------------------------------------------
int Inicializar (Fila *fila){
	fila->ini = -1;
     fila->fim = -1;
	  fila->tam = 0;
	  No *aux= fila->ini;
	printf("\nInicio da fila:\n");
	while(aux){
        printf("|%d |", aux->valor);
        aux = aux->prox;
	}
	printf("\nFim da fila.");
	return 0;
}
//--------------------------------------------------------
int main()
{
   No *r;
   Fila fila;
   criar(&fila);
   int q, valor;
	do {
	    system("cls");
	    printf("Fila\n");
		printf("\n\nOpcoes:\n");
		printf("1 -> Inserir \n");
		printf("2 -> Remover\n");
		printf("3 -> Inicializar\n");
		printf("4 -> Imprimir \n");
		printf("5 -> Sair\n");
		scanf("%d", &q);
		switch(q) {
			case 1: printf("Dado a ser inserido na fila: ");
                    scanf("%d",&valor);
                     Inserir(&fila, valor);
                    system("pause");
					break;
            case 2: r = Remover(&fila);
                    if (r){printf("\nRemovido: %d\n", r->valor);
                        free(r);
                            }
                    system("pause");
                    break;
            case 3: Inicializar;
                    system("pause");
					break;
			case 4:if(q==3){
			    printf("\nFila vazia.");
			           }
			    else Imprimir(&fila);
                    system("pause");
					break;
			case 5: break;
			default: printf("\n\n Opcao nao valida\n");
		            }
		getchar();
	 } while ((q != 5) );
    return 0;
}
