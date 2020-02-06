#include <stdio.h>
#include <string.h>
#define TAILLE 20


struct Chapitre {
    char name[40];
    char description[60];
    int gold;
    int hp;
    int id[30];
 };

 typedef struct Chapitre chapitre;
 chapitre lieux[TAILLE] = {{"Chapitre 1","Haut Hrotgard",+40,-20,{1,2}},{"Chapitre 2","Riften",+20,-20,{0,2}},{"Chapitre 3","Helgen",-20,-5,{0,1}}};

 
 
int deplacement(int* playerInput, int *pHP, int* pGold){
int temp;
int x;
temp=*playerInput;

  for (x = 0; x < 3; x++){
    printf("%d- Chapitre %d\n",x, lieux[*playerInput].id[x]);
  }
  printf("Quel chapitre souhaitez vous choisir ?\n");
  scanf("%d",playerInput);

    while (-0.1> *playerInput || *playerInput>1){
      printf("Désolé mais vous vous êtes prit une flèche dans le genoux\n" );
      scanf("%d",playerInput );
    }
	
	*pHP+=lieux[*playerInput].hp;
	*pGold+=lieux[*playerInput].gold;

  *playerInput=lieux[temp].id[*playerInput];

	if(*pHP>=100){
    *pHP=100;
  }
  

  if(*pGold<=0){
    *pGold=0;
  }
  

  printf("\nVous êtes arrivé à %s .\n%s \n %d gold %d PV\n",lieux[*playerInput].name, lieux[*playerInput].lieux, lieux[*playerInput].gold,  lieux[*playerInput].hp );
  printf("%dHP / %d Gold\n___________\n",*pHP, *pGold );
  }


int main(){
  int i;
  int playerInput;
  int pHP;
  pHP=100;
  int pGold;
  pGold=10;
do{

printf("%dPV / %d Gold\n___________\n",pHP, pGold );
printf("Chapitres disponibles :\n");
for (i = 0; i < 3; i++){
    printf("%d- %s\n", i,lieux[i].name);
}
printf("Entrez le numero du chapitre que vous souhaitez rejoindre\n");
scanf("%d",&playerInput );

while( -0.1> playerInput || playerInput>2 ){
  printf("Ce choix n'est pas valide\n" );
  scanf("%d",&playerInput );
}

pHP+=lieux[playerInput].hp;
pGold+=lieux[playerInput].gold;

if(pHP>=100){
  pHP=100;
}

if(pGold<=0){
  pGold=0;
}

printf("\n%s atteint.\n%s \n %d gold %d PV\n\n", lieux[playerInput].name, lieux[playerInput].lieux, lieux[playerInput].gold, lieux[playerInput].pv );
printf("%dPV / %d Gold\n___________\n",pHP, pGold );
lieux(&playerInput, &pHP, &pGold);

}while(pHP>0);

if (pHP=0){
	printf("Vous êtes mort \n");
}
}