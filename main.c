#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aux {
  int RA;
  char nome[50];
  char curso[50];
  int idade;
  struct aux *prox;
} aluno;

  aluno *inicio;

void criaAluno(){
  inicio = NULL;
}

int inserir(){
  
  aluno *a;
  a = (aluno *) malloc(sizeof(aluno));

    if (a==NULL){
      printf("Erro\n");
      return 0;
    }
  printf("Digite a matricula:");
  scanf("%d",&a->RA);

  printf("Digite o nome:");
  scanf(" %[^\n]",a->nome);

  printf("Digite o curso:");
  scanf(" %[^\n]",a->curso);

  printf("Digite a Idade:");
  scanf("%d",&a->idade);

  aluno *s=inicio;
  while(s!=NULL){
  if(a->RA==s->RA){
    printf("O aluno ja esta cadastrado no sistema!\n");
    return 1;
  }
  s=s->prox;
}

  a->prox = NULL;
    if (inicio==NULL)
     inicio = a; 
    else{
     a->prox = inicio;
     inicio  = a;
     }
   return 1;
}

void exibirLista(){
	aluno *a = inicio;
  if (a == NULL) {
    printf("A lista esta Vazia\n\n");
    return;
  }

  while (a !=NULL) {
    printf("RA    = %d\n",a->RA);
    printf("Nome  = %s\n",a->nome);
    printf("Curso = %s\n",a->curso);
    printf("idade = %d\n------------------\n",a->idade);
    a = a->prox;
  }

}

void exibirArquivo(){
	FILE *arq;
  char aux[50];
  
 	arq = fopen("bd.txt", "r");
  
  if(arq==NULL){
    printf("A lista esta Vazia\n\n");
    return;
  }
  while(fgets(aux, 20, arq) != NULL)
 	  printf("%s", aux);

 	fclose(arq);
}

void salvar (){
	aluno *a = inicio;
	FILE *arquivo = fopen("bd.txt","a");

	if(arquivo == NULL){
		printf("Vazio");
		exit(1);
	}

	while(a !=NULL){

		fprintf(arquivo,"%d %s %s %d\n",a->RA,a->nome,a->curso,a->idade);
		a = a->prox;
	}
	fclose(arquivo);
}

void tamanho(){
   FILE *arq;

    char aux, letra = '\n';

    int tam;

    arq = fopen("bd.txt","r");
        while(fread (&aux, sizeof(char), 1, arq)) {
            if(aux == letra) {
              tam++;
            }
        } 
    printf("           %i\n",tam);

    fclose(arq);

}

void exibirAlunoCurso(){
	aluno *a = inicio;
  char pesq[50];
  printf("Digite o curso que deseja consultar\n");
  scanf("%s",pesq);

  if (a == NULL) {
    printf("A lista esta Vazia\n\n");
    return;
  }

  while (a !=NULL) {
    if(strcmp(a->curso, pesq) == 0 ){  
      
      printf("RA    = %d\n",a->RA);
      printf("Nome  = %s\n",a->nome);
      printf("Curso = %s\n",a->curso);
      printf("idade = %d\n------------------\n",a->idade);
    }
  a = a->prox;
  }
}

void pesquisarRA(){

	aluno *a = inicio;
  int pesq;
  printf("Digite o RA que deseja consultar\n");
  scanf("%d",&pesq);

  if (a == NULL) {
    printf("A lista esta Vazia\n\n");
    return;
  }

  while (a !=NULL) {
    if(a->RA == pesq){    
      printf("RA    = %d\n",a->RA);
      printf("Nome  = %s\n",a->nome);
      printf("Curso = %s\n",a->curso);
      printf("idade = %d\n------------------\n",a->idade);
      a = a->prox;
    }
  }
}

void lerArquivo(){ 

  aluno *a = inicio;
  FILE *arq ;      
  arq = fopen("bd.txt","a"); 
  while(fscanf(arq,"%d %s %s %d",&a->RA,a->nome,a->curso,&a->idade) != EOF){
  inserir();
  }

  fclose(arq); 

}

  void excluirAluno(){
   aluno *a = inicio;
   aluno *s = inicio;

  int pesq;
  printf("Digite o RA do aluno que deseja excluir\n");
  scanf("%d",&pesq);

  while(s != NULL) {
    if(s->RA == pesq){

      if(s == a && s->prox == NULL){
        a = NULL;
        s = NULL;
          } 
      else if(s == a){
        a = s->prox;
          } 
      else {
        a->prox = s->prox;
        s = NULL;
      }
    } 
    else {
      a = s;
      s = s->prox;
    }
  }
}

void excluirAlunoCurso(){
   aluno *a = inicio;
   aluno *s = inicio;

  char pesq[50];
  printf("Digite o curso que deseja excluir\n");
  scanf("%s",pesq);

  while(s != NULL) {
    if(strcmp(s->curso , pesq)==0){

      if(s == a && s->prox == NULL){
        a = NULL;
        s = NULL;
          } 
      else if(strcmp(a->curso , pesq)==0){
        a = s->prox;
          } 
      else {
        a->prox = s->prox;
        s = NULL;
      }
    } 
    else {
      a = s;
      s = s->prox;
    }
  }
}

void ordenarListaNome(){

}

void ordenarListaRA(){
  aluno *a;
  aluno *s=inicio;
  aluno*aux=NULL;

  while(s!=NULL){
  if(a->RA<s->RA){

    aux->RA=s->RA;
    a->RA=s->RA;
    s->RA=aux->RA;

  
  }
  s=s->prox;
}
}

int main(){

  criaAluno();
  int x,count=0;
  printf("1 - Menu\n0 - Sair\n");
  scanf("%d",&x);
  system("clear");
  if(x==1){
    menu :

    printf("2 - Inserir um novo aluno\n");
    printf("3 - Ordenar lista por nome\n");
    printf("4 - Ordenar lista por RA\n");
    printf("5 - Exibir todos os alunos\n");
    printf("6 - Exibir todos os alunos de um curso\n");
    printf("7 - Pesquisar um aluno pelo RA\n");
    printf("8 - Excluir um aluno\n");
    printf("9 - Excluir todos os alunos de um curso\n");
    printf("10 - Total de alunos cadastrados\n");
    printf("11 - Salvar os dados para um arquivo\n");
    printf("12 - Ler os dados de um arquivo\n");
    
    scanf("%d",&x);
    system("clear");

    if(x==2){
      inserir();
      printf("-----------------\nAluno Cadastrado!\n-----------------\n");
    }

     if(x==3){
     ordenarListaNome();
     }

     if(x==4){
     ordenarListaRA();
     }

    if(x==5){
      printf("---------------------------\nAlunos Cadastrados na Lista\n---------------------------\n");
      exibirLista(); 
      printf("---------------------------\nCadastros salvos no Arquivo\n---------------------------\n");
      exibirArquivo();      
      printf("------------------\n");
    }

    if(x==6){
      exibirAlunoCurso();
    }

    if(x==7){
      pesquisarRA();
    }

    if(x==8){
      excluirAluno();
    }
    if(x==9){
      excluirAlunoCurso();
    }

    if(x==10){
      printf("------------------------\nTotal Alunos Cadastrados\n------------------------\n");
      tamanho();
      printf("------------------------\n");
    }

    if(x==0){
      system("clear");
      return 0;    
    }
    
    if(x==11){
    	salvar();
    	printf("Lista Salva!\n");
	  }

      if(x==12){
    	lerArquivo();
    	printf("Arquivo Carregado!\n");
	  }

    goto menu;
  }

  return 0;
}

