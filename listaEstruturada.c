#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Pessoa{
    int id;
    char nome[30];
    int idade;
    struct Pessoa *prox;
}Pessoa;
//funcao que cria a lista vazia
Pessoa* criarListaVazia(){
     return NULL;
}

//criar uma nova pessoa
//retorna o endereco da nova pessoa
Pessoa* criarPessoa(){
    Pessoa *novaPessoa = (Pessoa*)malloc(sizeof(Pessoa));
    if(novaPessoa == NULL){
        //memoria insuficiente
        printf("Erro de alocacao");
        exit(EXIT_FAILURE);
    }
    novaPessoa->prox = NULL;
    return novaPessoa;//endereco de memoria alocado para nova pessoa
}

Pessoa* cadastrar(Pessoa *lista){
    Pessoa *novaPessoa = criarPessoa();
    //inserir as informacoes
    srand(time(NULL));
    novaPessoa->id = rand() % 100;
    printf("Digite o nome: ");
    fflush(stdin);
    fgets(novaPessoa->nome, sizeof(novaPessoa), stdin);
    fflush(stdin);
    printf("Digite a idade: ");
    fflush(stdin);
    scanf("%d", &novaPessoa->idade);
    fflush(stdin);


    //duas situacoes 1 - lista e vazia 2 - ja tem alguem na lista
    if(lista == NULL){
        return novaPessoa;
    }else{
        //percorrer a lista ate encontrar a pessoa que a ponta para NULL
        Pessoa *atual = lista; //ponteiro auxiliar
        while(atual->prox!= NULL){
             atual = atual->prox;
        }
        atual->prox = novaPessoa;
        return lista;
    }

}

main(){
    int opcao;
    Pessoa *lista = criarListaVazia();

    do{
       printf("\n1 - Cadastrar");
       printf("\n2 - Mostrar");
       printf("\n3 - Buscar");
       printf("\n4 - Alterar");
       printf("\n5 - Excluir");
       printf("\n0 - sair");
       scanf("%d", &opcao);
       switch(opcao){
            case 1:
                 lista = cadastrar(lista);
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
       }

    }while(opcao != 0);
}