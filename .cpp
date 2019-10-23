#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//////FILA !!!!

struct elemento{
    int num;
    struct elemento *prox;
};

typedef struct elemento Elem;

struct fila{
    struct elemento *inicio;
    struct elemento *final;
};

typedef struct fila Fila;

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int consulta_Fila(Fila* fi, int valor){
    if(fi == NULL){
        return 0;}
    if(fi->inicio == NULL){
        return 0;}
    valor = fi->inicio->num;
    return 1;
}

int insere_Fila(Fila* fi,int valor){
    if(fi == NULL){
        return 0;}
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;}
    no->num = valor;
    no->prox = NULL;
    if(fi->final == NULL){
        fi->inicio = no;}
    else{
        fi->final->prox = no;}
    fi->final = no;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL){
        return 0;}
    if(fi->inicio == NULL){
        return 0;}
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL){
        fi->final = NULL;}
    free(no);
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL){
        return 0;}
    int cont=0;
    Elem* no = fi->inicio;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL){
        return 1;}
    if(fi->inicio == NULL){
        return 1;}
    return 0;
}


int imprime_Fila(Fila* fi){
    if(fi == NULL){
        return ;}
    Elem* no = fi->inicio;
    while(no != NULL){
        printf("%d\n",no->num);
        no = no->prox;
    }
}

int main(){
    int valor,insere,tamanho,remover,opt;

    Fila *fi=cria_Fila();
    do{
    printf("0. Sair:\n");
    printf("1. Listar fila:\n");
    printf("2. Inserir na fila:\n");
    printf("3. Remover da fila:\n");
    printf("4. Tamanho da fila:\n");
    printf("opcao:");
    scanf("%i",&opt);
    switch(opt){
        case(0):
        break;
        case(1):
        printf("Fila:\n");
        imprime_Fila(fi);
        printf("\n\n\n");
        break;
        case(2):
            printf("entre com um numero:\n");
            scanf("%i",&valor);
            insere= insere_Fila(fi,valor);
            if(insere==1){
                printf("inserido com sucesso!\n\n\n");
            }
            else{
                printf("problemas ao inserir!\n");
            }

        break;
        case(3):
            remover = remove_Fila(fi);
            printf("Removido com sucesso!\n\n\n");
        break;
        case(4):
            tamanho= tamanho_Fila(fi);
            printf("Quantidade de elementos da fila:%d\n",tamanho);
        break;
        default:
            printf("opicao invalida!\n\n\n");
        break;
    }
    }while(opt!=0);
    return 0;
}
