#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define FF fflush(stdin)
#define LimpaTela system("cls")
#define Parar system("pause")

struct Lista {
  int info;
  Lista* ant;
  Lista* prox;  
};

Lista* inicializa (void);
Lista* insere (Lista* l, int v);
Lista* insere_apos (Lista* l, int v);
Lista* insere_fim (Lista* l, int v);
Lista* busca (Lista* l, int v);
void imprime (Lista* l);
Lista* retira (Lista* l, int v);
void libera (Lista* l);

int main (void) 
{
  int opcao,valor;
  Lista* L;
  Lista* P;
  L = inicializa();

  while (1)
  {
    LimpaTela;
    printf ("1- Inserir nodo no inicio da lista. \n");
    printf ("2- Inserir nodo apos um nodo desejado. \n");
    printf ("3- Inserir nodo no fim da lista. \n");
    printf ("4- Retirar nodo da lista. \n");
    printf ("5- Procurar nodo na lista. \n");
    printf ("6- Mostrar lista. \n");
    printf ("7- Sair!\n\n");
    printf ("Escolha uma das opcoes: \n");
    scanf ("%d",&opcao);
     
    if (opcao==7)
      break;      
    else if (opcao==1){
      printf("Entre com um numero: ");
      scanf("%d",&valor);
      FF;             
      L = insere(L,valor);
    }
    else if (opcao==2){
            
          L = insere_apos(L,valor);
	  

    }
    else if (opcao==3){
      printf("Entre com um numero: ");
      scanf("%d",&valor);
      FF;             
      L = insere_fim(L,valor);
    }
    else if (opcao==4)
    {
      printf("Entre com o número a ser retirado: ");
      scanf("%d",&valor);
      FF;
      L = retira(L,valor);    
    }
    else if (opcao==5)
    {
      printf("Entre com o numero a ser procurado: ");
      scanf("%d",&valor);
      FF;
      P = busca(L,valor);
      if (P == NULL)
      {
        printf("Valor nao encontrado.\n");
        Parar;
      }
      else
      {
        printf("O valor %d foi encontrado.\n",P->info);
        Parar;
      }
    }
    else if (opcao==6)
    {
      imprime(L);
      Parar;
    }
    else 
    {
      printf("OPCAO INVALIDA!!!!!!\n");
      Parar;
    }  
  }
  if (L != NULL)
    libera(L);
  return 0;
}

/* função de inicialização: retorna uma lista vazia */
Lista* inicializa (void)
{
  return NULL;
}

/* inserção no início */
Lista* insere (Lista* l, int v)
{
  Lista* novo = (Lista*) malloc(sizeof(Lista));
  novo->info = v;
  novo->prox = l;
  novo->ant = NULL;
  /* verifica se lista não está vazia */
  if (l != NULL)
    l->ant = novo;
  return novo;
}

/* inserção apos */
Lista* insere_apos (Lista* l, int v){
	
	int valordesejado, valor;
	  Lista *P;
	  printf("Entre com o numero do nodo desejado: ");
	  scanf("%d", &valordesejado);
	  FF;
	  P = busca(l,valordesejado);
	  if(P == NULL){
		  printf("Valor nao encontrado em um nodo\n");
		  Parar;
	  }  
	  else{
		  printf("O valor %d foi encontrado.\n\n", P->info);
          printf("Entre com um numero para ser inserido apos o nodo encontrado: ");
          scanf("%d",&valor);
      	  FF; 
	
          Lista* novo = (Lista*)malloc(sizeof(Lista));
          novo->info = valor;
	      novo->ant = P;
	      novo->prox = P->prox;
	      if(P->prox != NULL)
		  	  P->prox->ant = novo;
	      P->prox = novo;
	  }
	  return l;
}

/* inserção no fim */
Lista* insere_fim (Lista* l, int v){
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = NULL;
	if(l == NULL){ // se a lista estiver vazia insere no inicio
		novo->ant = NULL;
		l = novo;
	} 
	else{ // se a lista não estivar vazia
		Lista* aux = l;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
		novo->ant = aux;
	}
	return l;
}


/* função imprime: imprime valores dos elementos */
void imprime (Lista* l)
{
  Lista* p; /* variável auxiliar para percorrer a lista */
  for (p = l; p != NULL; p = p->prox)
    printf("info = %d\n", p->info);
}

/* função busca: busca um elemento na lista */
Lista* busca (Lista* l, int v)
{
  Lista* p;
  for (p=l; p!=NULL; p=p->prox)
    if (p->info == v)
      return p;
  return NULL; /* não achou o elemento */
}

/* função retira: retira elemento da lista */
Lista* retira (Lista* l, int v) {
  Lista* p = busca(l,v);
  if (p == NULL)
    return l; /* não achou o elemento: retorna lista inalterada */
  /* retira elemento do encadeamento */
  if (l == p)
    l = p->prox;
  else
    p->ant->prox = p->prox;
  if (p->prox != NULL)
    p->prox->ant = p->ant;
  free(p);
  return l;
}

void libera (Lista* l)
{
  Lista* p = l;
  while (p != NULL) 
  {
    Lista* t = p->prox; /* guarda referência para o próximo elemento*/
    free(p); /* libera a memória apontada por p */
    p = t; /* faz p apontar para o próximo */
  }
}