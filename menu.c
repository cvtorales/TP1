#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mensajes.h"

typedef enum {
				STATE_MENU_WELCOME = 0,
				STATE_MENU_PRINCIPAL,
				STATE_MENU_PERSONAL_REGISTER,
				STATE_MENU_ASSIGNATURE,
				STATE_MENU_CALC,
				STATE_FINALIZE,
				STATE_QUIT
			} state_t;

int main (void)
{
	char option; /*sera la lectura de opciones*/
	state_t state;

	state = STATE_MENU_WELCOME; /* o tambien, STATE_INICIO */

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