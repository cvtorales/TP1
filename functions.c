#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "messages.h"
#include "functions.h"


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

void add_assignature(char assignatures[MAX_ROW][MAX_COL], int position_row)
{
	char aux[MAX_COL];
	int pos;
    if(fgets(aux, MAX_COL  + 1, stdin)!= NULL)
    {
    		pos=strlen(aux);  
			if(aux[pos] == '\n')	
				aux[pos]='\0';

			strcpy(assignatures[position_row],aux);
			printf("%s",assignatures[position_row]);
		
	}

}
void add_notes(int notes[MAX_ROW],int pos)
{
	int aux;

	scanf("%d",&aux);
	while(getchar()!='\n');	
	notes[pos] = aux;
}

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

void print_menu_principal()
{
	fprintf(stdout,"%s:\n",MSG_WELCOME_MENU_PPAL );
	fprintf(stdout,"%c) %s\n",SYMBOL_MENU_PERSONAL_REGISTER,MSG_OPTION_1_MENU_PPAL);
	fprintf(stdout,"%c) %s\n",SYMBOL_MENU_ASSIGNATURE,MSG_OPTION_2_MENU_PPAL);
	fprintf(stdout,"%c) %s\n",SYMBOL_MENU_CALC,MSG_OPTION_3_MENU_PPAL);
	fprintf(stdout,"%c) %s\n",SYMBOL_FINALIZE,MSG_OPTION_4_MENU_PPAL);
	fprintf(stdout,"%c) %s\n",SYMBOL_QUIT,MSG_OPTION_5_MENU_PPAL);
}