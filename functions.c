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
	int longitude;
    if(fgets(aux, MAX_COL  + 1, stdin)!= NULL)
    {
    		longitude=strlen(aux);  
			if(aux[longitude] == '\n')	
				aux[longitude]='\0';

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

float calc_media(int notes[MAX_ROW],int pos)
{
	int i;
	float media;
	media = 0;

	for(i=0;i<pos;i++)
	{
		media += notes[i];
	}
	return media/(float)pos;
}

void print_media(float media)
{
	fprintf(stdout, "%s %.2f\n",MSG_MEDIA,media);
}

void print_quantity(int pos)
{
	fprintf(stdout,"%s %d\n",MSG_QUANTITY,pos);
}

void print_failures(int failures)
{
	fprintf(stdout,"%s %d\n",MSG_FAILURES,failures);
}

void print_min(int min)
{
	fprintf(stdout,"%s %d\n",MSG_MIN,min);
}

void print_max(int max)
{
	fprintf(stdout,"%s %d\n",MSG_MAX,max);
}

int calc_failures(int notes[MAX_ROW],int pos)
{
	int i,failures;
	failures = 0;
	for(i=0;i<pos;i++)
	{
		if(notes[i] <= 2 )
			failures++;
	}
	return failures;
}

int calc_max(int notes[MAX_ROW],int pos)
{
	int i,max;

	max = notes[0];

	for(i=1;i<pos;i++)
	{
		if(notes[i] > max)
			max = notes[i];
	}
	return max;
}

int calc_min(int notes[MAX_ROW],int pos)
{
	int i,min;

	min = notes[0];

	for(i=1;i<pos;i++)
	{
		if(notes[i] < min)
			min = notes[i];
	}
	return min;
}

void add_name(char m[MAX_ROW_PERS_REG][MAX_COL_PERS_REG])
{
	char aux[MAX_COL_PERS_REG];
	int longitude;
    if(fgets(aux, MAX_COL_PERS_REG  + 1, stdin)!= NULL)
    {
    		longitude=strlen(aux);  
			if(aux[longitude] == '\n')	
				aux[longitude]='\0';

			strcpy(m[POSITION_NAME],aux);
			printf("%s",m[POSITION_NAME]);
		
	}

}

void add_last_name(char m[MAX_ROW_PERS_REG][MAX_COL_PERS_REG])
{
	char aux[MAX_COL_PERS_REG];
	int longitude;
    if(fgets(aux, MAX_COL_PERS_REG  + 1, stdin)!= NULL)
    {
    		longitude=strlen(aux);  
			if(aux[longitude] == '\n')	
				aux[longitude]='\0';

			strcpy(m[POSITION_LAST_NAME],aux);
			printf("%s",m[POSITION_LAST_NAME]);
		
	}

}

void add_career(char m[MAX_ROW_PERS_REG][MAX_COL_PERS_REG])
{
	char aux[MAX_COL_PERS_REG];
	int longitude;
    if(fgets(aux, MAX_COL_PERS_REG  + 1, stdin)!= NULL)
    {
    		longitude=strlen(aux);  
			if(aux[longitude] == '\n')	
				aux[longitude]='\0';

			strcpy(m[POSITION_CAREER],aux);
			printf("%s",m[POSITION_CAREER]);
		
	}

}