#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "messages.h"


int count_assignatures(char m[][MAX_COL]);
void add_assignature(char m[MAX_ROW][MAX_COL],int pos);
void add_notes(int notes[MAX_ROW],int pos);
void print_menu_principal();
/*void print_menu_reg_pers();
void print_menu_assignatures();*/
void print_menu_calc();
/*float calc_media(int notes[MAX_ROW]);*/

int count_assignatures(char m[][MAX_COL])
{
	int total,i,j;

	total = 0;
	j = 0;
	i = 0;

	while(m[i][j]!='\0' && (i<MAX_ROW))
	{
		total++;
		i++;
	}
	return total;
}

void add_assignature(char m[MAX_ROW][MAX_COL],int pos)
{
	char aux[MAX_COL];

	printf("entre a la funcion add_assignature\n");
	scanf("%s",aux);
	while(getchar()!='\n');	
	printf("pase el scanf\n");
	strcpy(m[pos],aux);
	printf("pase el strcpy\n");
}

void add_notes(int notes[MAX_ROW],int pos)
{
	int aux;

	scanf("%d",&aux);
	while(getchar()!='\n');	
	notes[pos] = aux;
}

void print_menu_principal()
{
	fprintf(stdout,"%s:\n",MSG_WELCOME_MENU_PPAL );
	fprintf(stdout,"%c) %s\n",SYMBOL_MENU_PERSONAL_REGISTER,MSG_OPTION_1_MENU_PPAL);
	fprintf(stdout,"%c) %s\n",SYMBOL_MENU_ASSIGNATURE,MSG_OPTION_2_MENU_PPAL);
	fprintf(stdout,"%c) %s\n",SYMBOL_MENU_CALC,MSG_OPTION_3_MENU_PPAL);
	fprintf(stdout,"%c) %s\n",SYMBOL_FINALIZE,MSG_OPTION_4_MENU_PPAL);
	fprintf(stdout,"%c) %s\n",SYMBOL_QUIT,MSG_OPTION_5_MENU_PPAL);
}

/*void print_menu_assignatures()
{

}*/

void print_menu_calc()
{
	fprintf(stdout,"%s:\n",MSG_WELCOME_MENU_CALC);
	fprintf(stdout,"%c) %s\n",SYMBOL_SUBMENU_CALC_MEDIA,MSG_OPTION_SUBMENU_CALC_MEDIA);
	fprintf(stdout,"%c) %s\n",SYMBOL_SUBMENU_CALC_MIN,MSG_OPTION_SUBMENU_CALC_MIN);
	fprintf(stdout,"%c) %s\n",SYMBOL_SUBMENU_CALC_MAX,MSG_OPTION_SUBMENU_CALC_MAX);
	fprintf(stdout,"%c) %s\n",SYMBOL_SUBMENU_CALC_QUANTITY,MSG_OPTION_SUBMENU_CALC_QUANTITY);
	fprintf(stdout,"%c) %s\n",SYMBOL_SUBMENU_CALC_FAILURES,MSG_OPTION_SUBMENU_CALC_FAILURES);
	fprintf(stdout,"%c) %s\n",SYMBOL_SUBMENU_CALC_BACK,MSG_OPTION_SUBMENU_CALC_BACK);
}

/*float calc_media(int notes[MAX_ROW],int pos)
{
	int i;
	float media;
	media = 0;

	for(i=0;i<pos;i++)
	{
		media += notes[i];
	}
	return media/(float)pos;
}*/