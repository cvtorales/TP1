#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mensajes.h"

/*agregar todos los defines a el mensajes.h*/
#define MAX_ROW 200
#define MAX_COL 200
#define SYMBOL_PERSONAL_REGISTER_BACK '0'
#define SYMBOL_PERSONAL_REGISTER_APELLIDOYNOMBRE 'A'
#define SYMBOL_PERSONAL_REGISTER_PADRON '#'
#define SYMBOL_PERSONAL_REGISTER_CARRERA 'C'

typedef enum {
				STATE_MENU_WELCOME = 0,
				STATE_MENU_PRINCIPAL,
				STATE_MENU_PERSONAL_REGISTER,
				STATE_MENU_ASSIGNATURE,
				STATE_MENU_CALC,
				STATE_FINALIZE,
				STATE_BACK,
				STATE_QUIT
             } state_t;

int main (void)
{

	char option, option2; /*sera la lectura de opciones*/
	state_t state;
    char personal_reg[MAX_ROW][MAX_COL]; /*inicializo con datos por default para mostrar en pantalla y luego leer por teclado los datos ingresados" */

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


                        while(option2!=SYMBOL_PERSONAL_REGISTER_BACK)
                        {
                            switch(option)
                            {
                                case SYMBOL_MENU_PERSONAL_REGISTER:
do{
                                        printf("Estoy en el Menu REG PERS\n");
                                        scanf("%c",&option2);
                                        while(getchar()!='\n');		 /* estas dos lineas, de scanf y toupper pueden ir en una funcion leer_opcion con todas sus validaciones */
                                        option2 = toupper(option2); /* si utilizo toupper entonces el usr puede ingresa en minuscula y no pasa nada */

                                    switch(option2)
                                        {
                                            case SYMBOL_PERSONAL_REGISTER_APELLIDOYNOMBRE:
                                                printf("ingrese apellido y nombre\n");
                                                scanf("%s %s",&personal_reg[0],&personal_reg[1]);
                                                while(getchar()!='\n');
                                                break;


                                            case SYMBOL_PERSONAL_REGISTER_PADRON:
                                                printf("ingrese padron\n");
                                                scanf("%s",&personal_reg[2]);
                                                while(getchar()!='\n'); /* validar */
                                                break;

                                            case SYMBOL_PERSONAL_REGISTER_CARRERA:
                                                printf("ingrese carrera\n");
                                                scanf("%s",personal_reg[3]);
                                                while(getchar()!='\n'); /* validar */
                                                break;

                                            case SYMBOL_PERSONAL_REGISTER_BACK:
                                                break;
                                        }
}while(option2!=SYMBOL_PERSONAL_REGISTER_BACK);


                            /*state = STATE_MENU_PERSONAL_REGISTER;
                            break; */

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
                }
			break;
        }

    }
return EXIT_SUCCESS;
}

