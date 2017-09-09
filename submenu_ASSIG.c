#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "mensajes.h"

typedef enum {
				STATE_MENU_WELCOME = 0,
				STATE_MENU_PRINCIPAL,
				STATE_MENU_PERSONAL_REGISTER,
				STATE_MENU_ASSIGNATURE,
				STATE_MENU_CALC,
				STATE_FINALIZE,
				STATE_QUIT,
				STATE_BACK
			} state_t;

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

int main (void)
{
	char option,opt_menu_assig; /*sera la lectura de opciones*/
	char assignatures[MAX_ROW][MAX_COL];
	int i,j,pos;
	state_t state;

	state = STATE_MENU_WELCOME; /* o tambien, STATE_INICIO */
	j = 0;

	for(i=0;i<MAX_ROW;i++)
	{
		assignatures[i][j] = '\0';
	} /* inicializo la matriz assignatures*/


	while(state != STATE_QUIT)
	{
		switch(state)
		{
			case STATE_MENU_WELCOME:
				printf("%s\n",MSG_WELCOME); /*los MSGs estan en "mensajes.h" */
				state = STATE_MENU_PRINCIPAL;
				break;
			case STATE_MENU_PRINCIPAL:
				while(state != STATE_QUIT)
				{
					printf("IMPRIMIR MENU PRINCIPAL\n"); /* esto va en una funcion: imprimir_menu_PRINCIPAL que despliega las opciones, no recibe argumentos
											y puede llegar a devolver un status_t para informar que salio todo bien */
					scanf("%c",&option);
					while(getchar()!='\n');		 /* estas dos lineas, de scanf y toupper pueden ir en una funcion leer_opcion con todas sus validaciones */
					option = toupper(option); /* si utilizo toupper entonces el usr puede ingresa en minuscula y no pasa nada */

					switch(option)
					{
						case SYMBOL_MENU_PERSONAL_REGISTER:
							printf("Estoy en el Menu REG PERS\n");
							state = STATE_MENU_PERSONAL_REGISTER;
							break;
					
						case SYMBOL_MENU_ASSIGNATURE:
							printf("Estoy en el Menu ASSIGNATURE\n");
							state = STATE_MENU_ASSIGNATURE;
							while(state != STATE_BACK)
							{
								printf("Ingrese opcion:\n");
								i = 0;
								j = 0;
								while(assignatures[i][j] != '\0')
								{
									printf("%i) %s\n",i+1,assignatures[i]);
									i++;
								}
								scanf("%c",&opt_menu_assig);
								switch(opt_menu_assig)
								{
									case SYMBOL_SUBMENU_ASSIG_ADD_ASSIG:
										puts("entre");
										pos = count_assignatures(assignatures);
										if(pos == 0)
										{
											printf("No hay materias, agregue la primera\n");
											add_assignature(assignatures,pos);
										}else{
											printf("Ingrese materia\n");
											add_assignature(assignatures,pos);
										}
										state = STATE_MENU_ASSIGNATURE;
										break;

									case SYMBOL_SUBMENU_ASSIG_BACK:
										printf("Vuelve atras\n");
										state = STATE_BACK;
										break;

									default:
										printf("La opcion ingresada en el submenu assig es incorrecta\n");
										return EXIT_FAILURE;
								}
							}
							state = STATE_MENU_PRINCIPAL;/*pude no ir*/
							break;

						case SYMBOL_MENU_CALC:
							printf("Estoy en el Menu CALC\n");
							state = STATE_MENU_CALC;
							break;

						case SYMBOL_FINALIZE:
							printf("Estoy en FINALIZE\n");
							state = STATE_FINALIZE;
							break;

						case SYMBOL_QUIT:
							printf("Estoy en QUIT\n");
							state = STATE_QUIT;
							break;

						default:
							printf("La opc ingresada no es correcta\n");
							return EXIT_FAILURE;
					}
				}
				break;

			default:
				printf("Hubo algun error con los enum\n");
				return EXIT_FAILURE;
		}	
	}

	return EXIT_SUCCESS;
}