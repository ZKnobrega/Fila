#include <iostream>
#include <stdlib.h>
#include <locale.h>
using namespace std;
//////FILA !!!!//////

struct valor{
    int num;
    struct valor *prox;
}valor;

typedef struct valor Elem;

struct fila{
    struct valor *inicio;
    struct valor *fim;
}fila;

typedef struct fila Fila;

Fila* cria_Fila(){
    Fila* fi = new Fila;
    if(fi != NULL){
        fi->fim = NULL;
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
    Elem *no = new Elem;
    if(no == NULL){
        return 0;}
    no->num = valor;
    no->prox = NULL;
    if(fi->fim == NULL){
        fi->inicio = no;}
    else{
        fi->fim->prox = no;}
    fi->fim = no;
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
        fi->fim = NULL;}
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
        cout << "Fila Vazia!!!";}
    Elem* no = fi->inicio;
    while(no != NULL){
        cout << no->num << endl;
        no = no->prox;
    }
}

int main(){
    int valor,insere,tamanho,remover,op;

    Fila *fi=cria_Fila();
    do{
    cout << "1 - Inserir\n2 - Listar\n3 - Remover\n4 - Tamanho\n5 - Sair\n" << endl;
    cout << "opcao: ";
    cin >> op;

    switch(op){

        case(1):
            cout << "Inserir: ";
            cin >> valor;
            insere= insere_Fila(fi,valor);
            if(insere=!1){
                cout << "Deu Merda....\n";
            }
        break;

        case(2):
        cout << "Fila:\n";
        imprime_Fila(fi);
        cout << "\n\n\n";
        break;

        case(3):
            remover = remove_Fila(fi);
            cout << "Removido com sucesso!\n\n\n";
        break;

        case(4):
            tamanho= tamanho_Fila(fi);
            cout << "Quantidade de elementos da fila: " << tamanho;
            cout << "\n";
        break;
        default:
            cout << "opicao invalida!\n\n\n";
        break;

        case(5):
        break;

    }
    }while(op!=5);
    return 0;
}
