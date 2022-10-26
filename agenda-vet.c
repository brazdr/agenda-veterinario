#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NOME 50
#define QNT 5

typedef struct _dono{
  char* nomed;
  char telefone[18];
}dono;

typedef struct _animal{
  char *nomea;
  dono *nomed;
  int idade;
  float peso;
}animal;

typedef struct _veterinario{
  char *nomev;
  int CFMV;
}veterinario;

typedef struct _consulta{
  char data[21];
  int horario;
  veterinario *nomev;
  animal *nomea;
}consulta;

void ImprimirDono(dono *nomed) {
  printf("\nDono: %s", nomed->nomed);
  printf("\nTelefone:%s", nomed->telefone);
}

void ImprimirVeterinario(veterinario *nomev){
  printf("\nVeterinario: %s", nomev->nomev);
  printf("\n CFMV: %d", nomev->CFMV);
}

void ImprimirAnimal(animal *nomea) {
  printf("\nNome do PET: %s", nomea->nomea);
  printf("\nNome do dono: %s", nomea->nomed->nomed);
  printf("\nIdade %d", nomea->idade);
  printf("\nPeso: %.2f", nomea->peso);
}

int BuscarDono(dono *donos, int qd, char *bn){
  int i, id;
   for(i = 0; i < qd; i++ ){
    if(strcmp(donos[i].nomed, bn) == 0){
      id = i;
      return id;
    }
  }
  return -1;
}

int BuscarAnimal(animal *animais, int qa, char *bn){
  int i, id;
   for(i = 0; i < qa; i++ ){
    if(strcmp(animais[i].nomea, bn) == 0){
      id = i;
      return id;
    }
  }
  return -1;
}

int BuscarVeterinario(veterinario *veterinarios, int qv, char *bn){
  int i, id;
   for(i = 0; i < qv; i++ ){
    if(strcmp(veterinarios[i].nomev, bn) == 0){
      id = i;
      return id;
    }
  }
  return -1;
}  

//QUESTÃO 4
void CadastrarDono(dono *donos,int *qd){
  if (*qd<QNT){
   donos[*qd].nomed = (char*)malloc(50 * sizeof(char));
   printf("\nDados do dono: \n");
   printf("Nome do dono do PET: ");
   fflush(stdin);
   gets(donos[*qd].nomed);
   printf("Telefone de contato: ");
   fflush(stdin);
   gets(donos[*qd].telefone);
   (*qd)++;
  }
  else {
   printf("O maximo de donos possiveis foi atingido.");
}}

void CadastrarVeterinario(veterinario *veterinarios, int *qv){
  if(*qv < QNT){
   veterinarios[*qv].nomev = (char*)malloc(50 * sizeof(char));
   printf("\nDados do(a) Veterinario(a): \n");
   printf("Nome do(a) Veterinario(a): ");
   fflush(stdin);
   gets(veterinarios[*qv].nomev);
   fflush(stdin);
   printf("Numero CFMV: ");
   scanf("%d", &veterinarios[*qv].CFMV);
   (*qv)++;
  }
  else {
    printf("O maximo de veterinarios(as) foi atingido.");
}}

//QUESTÃO 5
void CadastrarAnimal(animal *animais, int *qa, dono *donos, int *qd){

  int op=1;
  char *db;

  animais[*qa].nomed = (dono*)malloc(1 * sizeof(dono));
   animais[*qa].nomea = (char*)malloc(50 * sizeof(char));
   animais[*qa].nomed->nomed = (char*)malloc(50 * sizeof(char));
  db = (char*)malloc(50 * sizeof(char));
  if (*qa<QNT){
    while(op==1){
    printf("\nDigite o Dono do animal: ");
    fflush(stdin);
    gets(db);
    if(BuscarDono(donos, *qd, db) < 0){
      printf("\nDono nao encontrado");
      printf("\nPressione:\n1- Se deseja tentar novamente;\n2- Cancelar cadastro.");
      printf("\n:");
      scanf("%d", &op);
   }
   
   else{
     printf("\nO nome foi encontrado!!\n");
    op=0;
   }}
    if (op == 2){
      printf("\nCancelando cadastro...");
      return;
    }
    strcpy(animais[*qa].nomed->nomed,db);
    printf("\nDados do PET: \n");
    printf("Nome do PET: ");
    fflush(stdin);
    gets(animais[*qa].nomea);
    printf("Idade do PET: ");
    fflush(stdin);
    scanf("%d", &animais[*qa].idade);
    printf("Peso do PET: ");
    fflush(stdin);
    scanf("%f", &animais[*qa].peso);
    (*qa)++;
  }
  else {
    printf("O maximo de animais possiveis foi atingido.");
  }
}

//QUESTÃO 6
  int HorarioDisponivel(consulta *consultas, int qc, int *hb, char*dtb){
  
    if(qc<0)
     return 1;
      if(strcmp(consultas[qc].data, dtb)==0 && (consultas[qc].horario==*hb))
      return 0;
  return HorarioDisponivel(consultas, qc-1, hb, dtb);
}  

//QUESTÃO 7
void AgendarConsulta(consulta *consultas,veterinario *veterinarios, animal *animais, int *qc, int *qa, int *qv){
int op= 1,po=1,pd=1;
char *vb,*ab,*bdt;
int*bhr, indice;


vb=(char*)malloc(50 * sizeof(char));
ab=(char*)malloc(50 * sizeof(char));
bdt=(char*)malloc(21 * sizeof(char));
bhr=(int*)malloc(sizeof(int));
if(*qc< QNT){
  while(op==1){
    printf("\nDigite o Veterinario do animal: ");
    fflush(stdin);
    gets(vb);
    if(BuscarVeterinario(veterinarios, *qv, vb) < 0){
      printf("\nVeterinario nao encontrado");
      printf("\nPressione:\n1- Se deseja tentar novamente;\n2- Cancelar agendamento.");
      printf("\n:");
      scanf("%d", &op);
   }
   
   else{
     printf("\nO nome foi encontrado!!\n");
    op=0;
   }}
    if (op == 2){
      printf("\nCancelando agendamento...");
      return;
    }
while(po==1){
    printf("\nDigite o nome do animal: ");
    fflush(stdin);
    gets(ab);
    if(BuscarAnimal(animais, *qa, ab) < 0){
      printf("\nAnimal nao encontrado");
      printf("\nPressione:\n1- Se deseja tentar novamente;\n2- Cancelar agendamento.");
      printf("\n:");
      scanf("%d", &po);
   }
   
   else{
     printf("\nO nome foi encontrado!!\n");
    po=0;
    indice=BuscarAnimal(animais, *qa,ab);
   }}
    if (po == 2){
      printf("\nCancelando agendamento...");
      return;
    }
while(pd==1){
    printf("\nDigite a data da consulta a ser marcada: ");
    fflush(stdin);
    gets(bdt);
    printf("\nDigite o Horario da consulta: ");
    fflush(stdin);
   scanf("%d", bhr);
    if(HorarioDisponivel(consultas, *qc, bhr, bdt) == 0){
      printf("\nData e hora da consulta nao disponivel");
      printf("\nPressione:\n1- Se deseja tentar novamente;\n2- Cancelar agendamento.");
      printf("\n:");
      scanf("%d", &pd);
   }
   
   else{
     printf("\nConsulta marcada!!\n");
    consultas[*qc].nomev=(veterinario*)malloc(1 * sizeof(veterinario));
    consultas[*qc].nomea=(animal*)malloc(1 * sizeof(animal));
    consultas[*qc].nomea->nomed=(dono*)malloc(50 * sizeof(dono));
     consultas[*qc].nomev->nomev=(char*)malloc(50 * sizeof(char));
    consultas[*qc].nomea->nomea=(char*)malloc(50 * sizeof(char));
    consultas[*qc].nomea->nomed->nomed=(char*)malloc(50 * sizeof(char));
     strcpy (consultas[*qc].data,bdt);
     strcpy (consultas[*qc].nomev->nomev,vb);
     strcpy (consultas[*qc].nomea->nomea,ab);
     strcpy (consultas[*qc].nomea->nomed->nomed,animais[indice].nomed->nomed);
     consultas[*qc].horario=*bhr;
    pd=0;
    (*qc)++;
   }}
    if (pd == 2){
      printf("\nCancelando agendamento...");
      return;
    }


}
else{
  printf("O maximo de Consultas foi atingido.");
}
}

//QUESTÃO 8
void imprimeEstrelinha(int e) {
for (int i =0 ; i <22+e; i++)
printf("*");
}

int MaiorS(int a,int b, int c, int d){
int m = -1;
if (a>m)m=a;
if(b>m)m=b;
if(c>m)m=c;
if(d>m)m=d;
return m;
}

void ImprimeEspaco(int a,int b){
for(int i=0;i<6+a-b;i++){
    printf(" ");
}
}

void VisualizarAgenda(consulta *consultas,int *qc ){
char *dt;
int esp=0;
dt=(char*)malloc(11 * sizeof(char));
printf("\nDigite a data da consulta: ");
fflush(stdin);
gets(dt);
for(int i=0;i<(*qc);i++){
  if (strcmp(consultas[i].data,dt)==0){ 
    printf("\n");
    esp=MaiorS(strlen(consultas[i].data), strlen(consultas[i].nomev->nomev), strlen(consultas[i].nomea->nomea), strlen(consultas[i].nomea->nomed->nomed));
    imprimeEstrelinha(esp);
    printf("\n| DATA........:");
    ImprimeEspaco(esp,strlen(consultas[i].data));
    printf("%s |",consultas[i].data);
    printf("\n| HORA........:");
    ImprimeEspaco(esp,snprintf(NULL,0,"%d",consultas[i].horario));
    printf("%d |", consultas[i].horario);
    printf("\n| VETERINARIO.:");
    ImprimeEspaco(esp,strlen(consultas[i].nomev->nomev));
    printf("%s |", consultas[i].nomev->nomev);
    printf("\n| PET.........:");
    ImprimeEspaco(esp,strlen(consultas[i].nomea->nomea));
    printf("%s |",consultas[i].nomea->nomea);
    printf("\n| DONO........:");
    ImprimeEspaco(esp,strlen(consultas[i].nomea->nomed->nomed));
    printf("%s |",consultas[i].nomea->nomed->nomed);
  }
}
printf("\n");
imprimeEstrelinha(esp);
printf("\n");
}

//QUESTÃO 9
int main(){
 
 dono donos[QNT]; 
 veterinario veterinarios[QNT];
 animal animais[QNT];
 consulta consultas[QNT];
 int menu = 1, nd=0, nv=0, na=0, nc=0,esp;
 char *bd,*ba,*bv;
  
  while(menu != 9){
  printf("\n\nBem vindo ao sistema de agendamentos!");
  printf("\nSelecione uma opcao: \n\n1- Cadastrar dono\n2- Cadastrar PET\n3- Cadastrar Veterinario(a)\n4- Buscar dono\n5- Buscar PET\n6- Buscar Veterinario(a)\n7- Agendar Consulta\n8- Visualizar agenda\n9- Sair\nDigite sua opcao: ");
  scanf("%d", &menu);

  switch (menu){

  case 1: 
  printf("\nVoce selecionou a opcao Cadastrar Dono: ");
  CadastrarDono(donos,&nd);
  break;
 
  case 2: 
  printf("\nVoce selecionou a opcao Cadastrar PET");
  CadastrarAnimal(animais, &na, donos, &nd);
  break;
  
  case 3: 
  printf("\nVoce selecionou a opcao Cadastrar Veterinario(a)");
  CadastrarVeterinario(veterinarios, &nv);
  break;

  case 4: 
  bd = (char*)malloc(50 * sizeof(char)); 
  printf("\nVoce selecionou a opcao Buscar Dono");
  printf("\nDigite o nome do Dono a ser buscado: ");
  fflush(stdin);
  gets(bd);
  if (BuscarDono(donos,nd,bd)>=0){
    ImprimirDono(&donos[BuscarDono(donos,nd,bd)]);
  }
  else{
    printf("Nome nao encontrado");
  }
  printf("\n");
  system("PAUSE");
  break;

  case 5: 
   ba = (char*)malloc(50 * sizeof(char)); 
  printf("\nVoce selecionou a opcao Buscar PET");
  printf("\nDigite o nome do PET a ser buscado: ");
  fflush(stdin);
  gets(ba);
  if (BuscarAnimal(animais,na,ba)>=0){
    ImprimirAnimal(&animais[BuscarAnimal(animais,na,ba)]);
  }
  else{
    printf("PET nao encontrado");
  }
  printf("\n");
  system("PAUSE");
  break;

  case 6: 
  bv = (char*)malloc(50 * sizeof(char)); 
  printf("\nVoce selecionou a opcao Buscar Veterinario(a)");
  printf("\nDigite o nome do veterinario a ser buscado: ");
  fflush(stdin);
  gets(bv);
   if (BuscarVeterinario(veterinarios,nv,bv)>=0){
    ImprimirVeterinario(&veterinarios[BuscarVeterinario(veterinarios,nv,bv)]);
  }
  else{
    printf("Veterinario nao encontrado");
  }
  printf("\n");
  system("PAUSE");
  break;

  case 7: 
  printf("\nVoce selecionou a opcao Agendar Consulta");
  AgendarConsulta(consultas, veterinarios, animais, &nc, &na, &nv);
  system("PAUSE");
  break;

  case 8: 
  printf("\nVoce selecionou a opcao Visualizar Agenda");
  VisualizarAgenda(consultas,&nc);
  system("PAUSE");
  break;

  case 9: 
  printf("\nSaindo...\n\n");
  break;

  default: 
  printf("Voce selecionou uma opcao invalida");
  break;
  }
}
}