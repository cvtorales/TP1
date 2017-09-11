#include <ctype.h>
#include "functions.h"
#include "functions.c" 

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
	char option,opt_menu_assig, opt_menu_pers_reg; /*sera la lectura de opciones*/
	char assignatures[MAX_ROW][MAX_COL];
	int i,j,pos;
	int notes[MAX_ROW];
	state_t state;

	state = STATE_MENU_WELCOME; /* o tambien, STATE_INICIO */
	j = 0;

	for(i=0;i<MAX_ROW;i++)
	{
		assignatures[i][j] = '\0';
		notes[i] = 0;
	} /* inicializo la matriz assignatures y el vector de notas*/


	while(state != STATE_QUIT)
	{
		switch(state)
		{
			case STATE_MENU_WELCOME:
				printf("%s\n",MSG_WELCOME); /*los MSGs estan en "messages.h" */
				state = STATE_MENU_PRINCIPAL;
				break;
			case STATE_MENU_PRINCIPAL:
				while(state != STATE_QUIT)
				{
					print_menu_principal();
					if(scanf("%c",&option)!=1)
						{
							fprintf(stderr,MSG_ERROR_SYMBOL);
						}
					while(getchar()!='\n');		 /* estas dos lineas, de scanf y toupper pueden ir en una funcion leer_opcion con todas sus validaciones */
					option = toupper(option); /* si utilizo toupper entonces el usr puede ingresa en minuscula y no pasa nada */

					switch(option)
					{
						case SYMBOL_MENU_PERSONAL_REGISTER:
							printf("Estoy en el Menu REG PERS\n");
							state = STATE_MENU_PERSONAL_REGISTER;
							do
							{
								printf("Ingrese opcion:\n");
								if(scanf("%c",&opt_menu_pers_reg)!=1)
								{
									fprintf(stderr,MSG_ERROR_SYMBOL);
								}
								while(getchar()!='\n');
								opt_menu_pers_reg = toupper(opt_menu_pers_reg);
								switch(opt_menu_pers_reg)
								{
									case SYMBOL_PERSONAL_REGISTER_APELLIDOYNOMBRE:
                                                printf("ingrese apellido y nombre\n");
                                             /*   if(scanf("%s %s",&personal_reg[0],&personal_reg[1])!=2)
						  {
						  	fprintf(stderr, MSJ_ERROR);
						  }
                                                while(getchar()!='\n');  */
                                                break;


                                    case SYMBOL_PERSONAL_REGISTER_PADRON:
                                                printf("ingrese padron\n");
                                              /* if(scanf("%s",&personal_reg[2])!=1)
					      	 {
						 	fprintf(stderr,MSJ_ERROR);
						 }
						/* validacion de si es un numero 
						j=strlen(personal_reg[2]);
						int i=0,sw=0;
						while(i<j, && sw==0)
						{
							if(isdigit(personal_reg[2][i]!=0
							{
								i++;
							}
							else
							{
								sw=1;
							}
						}
						return sw;
					
                                      	        while(getchar()!='\n'); */        
                                                break;

                                    case SYMBOL_PERSONAL_REGISTER_CARRERA:
                                                printf("ingrese carrera\n");
                                              /* if(scanf("%s",personal_reg[3])!=1)
					      	 {
						 	fprintf(stderr,MSJ_ERROR);
						 }
                                                while(getchar()!='\n'); */      /* validar */
                                                break;

                                    case SYMBOL_PERSONAL_REGISTER_BACK:
                                                break;
                                    default:
										printf("La opcion ingresada en el submenu registro personal es incorrecta\n");
										return EXIT_FAILURE;
								}
							}while(opt_menu_pers_reg!=SYMBOL_PERSONAL_REGISTER_BACK);
							state = STATE_MENU_PRINCIPAL;
						
							
							break;
					
						case SYMBOL_MENU_ASSIGNATURE:
							state = STATE_MENU_ASSIGNATURE;
							printf("Estoy en el Menu ASSIGNATURE\n");
							do
							{
								printf("Ingrese opcion:\n + para agregar materias \n 0 para volver\n");
								scanf("%c",&opt_menu_assig);
								while(getchar()!='\n');
						
								switch(opt_menu_assig)
								{
									case SYMBOL_SUBMENU_ASSIG_ADD_ASSIG:
										puts("entre");
										pos = count_assignatures(assignatures);
										if(pos == 0)
										{
											printf("No hay materias, agregue la primera\n");
											add_assignature(assignatures,pos);
											printf("Ingrese nota\n");
											add_notes(notes,pos);
										}else{
											printf("Ingrese materia\n");
											add_assignature(assignatures,pos);
											printf("Ingrese nota\n");
											add_notes(notes,pos);
										}
										state = STATE_MENU_ASSIGNATURE;
										break;

									case SYMBOL_SUBMENU_ASSIG_BACK:
										printf("Vuelve atras\n");
										break;

									default:
										printf("La opcion ingresada en el submenu assig es incorrecta\n");
										return EXIT_FAILURE;
								}
							}while(opt_menu_assig!=SYMBOL_SUBMENU_ASSIG_BACK);
							state = STATE_MENU_PRINCIPAL;
							break;
								/*i = 0;
								j = 0;
								while(assignatures[i][j] != '\0')
								{
									printf("%i) %s(%d)\n",i+1,assignatures[i],notes[i]);
									i++;
								}*/

						case SYMBOL_MENU_CALC:
							state = STATE_MENU_CALC;
							printf("Estoy en el Menu CALC\n");
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
