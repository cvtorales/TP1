#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "idioma.h"
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
    if(fgets(aux, MAX_COL  /*+ 1*/, stdin)!= NULL)
    {
    		longitude=strlen(aux);  
			if(aux[longitude-1] == '\n')	
				aux[longitude-1]='\0';

			strcpy(assignatures[position_row],aux);
	}

}

int add_notes(int notes[MAX_ROW],int pos)
{
	int cualification=0;
	char *temp;
	size_t aux;

	char line[MAX_STR_CUALIFICATION];
	
	if(fgets(line, MAX_STR_CUALIFICATION /* + 1*/, stdin)!= NULL)
	{
		aux=strlen(line);

		if( aux !=MIN_DIG_NOTE && aux != MAX_DIG_NOTE)
		{
			printf("%s\n",MSG_ERROR_NOTES);
			return SIGN_IN_AGAIN;
		}
		cualification = strtol(line, &temp,BASE);

		if(*temp && *temp != '\n') 
		{
			printf("%s\n",MSG_ERROR_NOTES);
			return SIGN_IN_AGAIN;  
		}

		if(cualification<MIN_NOTE || cualification>MAX_NOTE) 
		{
			printf("%s\n",MSG_ERROR_NOTES);
			return SIGN_IN_AGAIN;  
		}
		notes[pos] = cualification;
	}
	
	
	return EXIT_SUCCESS;
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
	fprintf(stdout, "%s %.2f\n",MSG_SUBMENU_CALC_MEDIA,media);
}

void print_quantity(int pos)
{
	fprintf(stdout,"%s %d\n",MSG_SUBMENU_CALC_QUANTITY,pos);
}

void print_failures(int failures)
{
	fprintf(stdout,"%s %d\n",MSG_SUBMENU_CALC_FAILURES,failures);
}

void print_min(int min)
{
	fprintf(stdout,"%s %d\n",MSG_SUBMENU_CALC_MIN,min);
}

void print_max(int max)
{
	fprintf(stdout,"%s %d\n",MSG_SUBMENU_CALC_MAX,max);
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
    if(fgets(aux, MAX_COL_PERS_REG /* + 1*/, stdin)!= NULL)
    {
    		longitude=strlen(aux);  
			if(aux[longitude-1] == '\n')	
				aux[longitude-1]='\0';

			strcpy(m[POSITION_NAME],aux);
			
	}

}

void add_last_name(char m[MAX_ROW_PERS_REG][MAX_COL_PERS_REG])
{
	char aux[MAX_COL_PERS_REG];
	int longitude;
    if(fgets(aux, MAX_COL_PERS_REG /*+ 1*/, stdin)!= NULL)
    {
    		longitude=strlen(aux);  
			if(aux[longitude-1] == '\n')	
				aux[longitude-1]='\0';

			strcpy(m[POSITION_LAST_NAME],aux);
	}

}

void add_career(char m[MAX_ROW_PERS_REG][MAX_COL_PERS_REG])
{
	char aux[MAX_COL_PERS_REG];
	int longitude;
    if(fgets(aux, MAX_COL_PERS_REG  /*+ 1*/, stdin)!= NULL)
    {
    		longitude=strlen(aux);  
			if(aux[longitude-1] == '\n')	
				aux[longitude-1]='\0';

			strcpy(m[POSITION_CAREER],aux);
	}

}

long int add_padron(long int* padron)
{
	size_t aux;

	long int aux_padron;
	char *temp;
	char line[MAX_STR_PADRON];

	*padron=0;
	
	if(fgets(line, MAX_STR_PADRON /*+ 1*/, stdin)!= NULL)
	{
		aux=strlen(line);

		if( aux != MIN_DIG_PADRON && aux != MAX_DIG_PADRON)
		{
			printf("%s\n",MSG_ERROR_PADRON); 
			return SIGN_IN_AGAIN;
		}

		aux_padron = strtol(line, &temp,BASE);	  
		if(*temp && *temp != '\n') 
		{/* entra cuando temp se queda apuntando a una letra */
			printf("%s\n",MSG_ERROR_PADRON);
			return SIGN_IN_AGAIN;  
		}
		if (aux_padron < NOT_POSITIVE_DIG_PADRON)
		{
			printf("%s\n",MSG_ERROR_PADRON);
			return SIGN_IN_AGAIN; 
		}

		*padron = aux_padron;
	}
	
	return EXIT_SUCCESS;
}

int validation_finalize(char n[MAX_ROW_PERS_REG][MAX_COL_PERS_REG],int padron, float media,int courses, int failures)
{
	int control,j;

	control = OK; /* puedo definir macro OK 0 NO_OK 1*/
	j = 0;
	
	if(n[POSITION_LAST_NAME][j] =='\0') /* puedo poner solo n[POSITION_LAST_NAME] sin ningun ==, asi comparo contra 0 */
	{
		fprintf(stderr,"%s\n",ERROR_MSG_EMPTY_LASTNAME);
		control = NOT_OK;
		return control;
	}
	if(n[POSITION_NAME][j] =='\0')
	{
		fprintf(stderr,"%s\n",ERROR_MSG_EMPTY_NAME);
		control = NOT_OK;
		return control;
	}
	if(n[POSITION_CAREER][j] =='\0')
	{
		fprintf(stderr,"%s\n",ERROR_MSG_EMPTY_CAREER);
		control = NOT_OK;
		return control;
	}
	if(padron == 0) /*hay que inicializar padron en 0*/
	{
		fprintf(stderr,"%s\n",ERROR_MSG_EMPTY_PADRON);
		control = NOT_OK;
		return control;
	}
	if(media == 0) /*hay que inicializar media en 0*/
	{
		fprintf(stderr,"%s\n",ERROR_MSG_EMPTY_NOTES);
		control = NOT_OK;
		return control;
	}
	if(failures == -1) /*hay que inicializar failures en -1, pues puede hacer failures =0, entonces no puedo inicializar*/
	{
		fprintf(stderr,"%s\n",ERROR_MSG_EMPTY_NOTES);
		control = NOT_OK;
		return control;
	}
	if(courses == 0) /*hay que inicializar courses en 0*/
	{
		fprintf(stderr,"%s\n",ERROR_MSG_EMPTY_COURSES);
		control = NOT_OK;
		return control;
	}
	return control;
}

void finalize(char n[MAX_ROW_PERS_REG][MAX_COL_PERS_REG],int padron, float media, int notes[MAX_ROW],int courses, int failures)
{
	int control;

	media = calc_media(notes,courses);
	failures = calc_failures(notes,courses);
	
	control = validation_finalize(n,padron,media,courses,failures);
	if(control == 0)
	{
		fprintf(stdout,"%s, %s, %d, %s, %d, %.2f, %d\n",n[POSITION_LAST_NAME],
			n[POSITION_NAME],
			padron,
			n[POSITION_CAREER],
			courses,
			media,
			failures);
	}
}

void print_menu_pers_reg()
{
	fprintf(stdout,"%s:\n",MSG_WELCOME_MENU_PERS_REG);
	fprintf(stdout,"%c) %s\n",SYMBOL_SUBMENU_PERSONAL_REGISTER_LASTNAME_NAME,MSG_OPTION_SUBMENU_PERSONAL_REGISTER_LASTNAME_NAME);
	fprintf(stdout,"%c) %s\n",SYMBOL_SUBMENU_PERSONAL_REGISTER_PADRON,MSG_OPTION_SUBMENU_PERSONAL_REGISTER_PADRON);
	fprintf(stdout,"%c) %s\n",SYMBOL_SUBMENU_PERSONAL_REGISTER_CAREER,MSG_OPTION_SUBMENU_PERSONAL_REGISTER_CAREER);
	fprintf(stdout,"%c) %s\n",SYMBOL_SUBMENU_PERSONAL_REGISTER_BACK,MSG_OPTION_SUBMENU_PERSONAL_REGISTER_BACK);
}

void print_menu_assig(char assignatures[MAX_ROW][MAX_COL],int notes[MAX_ROW])
{
	int i,j;

	i = 0;
	j = 0;
	if(assignatures[i][j] == '\0'){
		fprintf(stdout, "%s\n",MSG_SUBMENU_ASSIG_EMPTY);
	}else{
		fprintf(stdout, "%s:\n",MSG_SUBMENU_ASSIG_OPTIONS);
	}

	while(assignatures[i][j] != '\0')
	{
		printf("%i) %s(%d)\n",i+1,assignatures[i],notes[i]);
		i++;
	}
	fprintf(stdout,"%c) %s\n",SYMBOL_SUBMENU_ASSIG_ADD_ASSIG,MSG_OPTION_SUBMENU_ASSIG_ADD_ASSIG);
	fprintf(stdout,"%c) %s\n",SYMBOL_SUBMENU_ASSIG_BACK,MSG_OPTION_SUBMENU_ASSIG_BACK);
}

void modify_assignatures(char a[MAX_ROW][MAX_COL],int notes[MAX_ROW], int pos)
{
	printf("%s\n",MSG_MENU_ASSIGNATURE_ADD_ASSIGNATURE);
	add_assignature(a,pos);
	printf("%s\n",MSG_MENU_ASSIGNATURE_ADD_QUALIFICATION);
	add_notes(notes,pos);
}
