#include <ctype.h>
#include "functions.h"

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
	char option,opt_menu_assig,opt_menu_calc; /*sera la lectura de opciones*/
	char assignatures[MAX_ROW][MAX_COL];
	int i,j,pos,failures,min,max;
	int notes[MAX_ROW];
	float media;
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
							state = STATE_MENU_ASSIGNATURE;
							printf("Estoy en el Menu ASSIGNATURE\n");
							do
							{
								printf("Ingrese opcion:\n");
								scanf("%c",&opt_menu_assig);
								while(getchar()!='\n');
								switch(opt_menu_assig)
								{
									case SYMBOL_SUBMENU_ASSIG_ADD_ASSIG:
										/*puts("entre");*/
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
							do
							{
								print_menu_calc();
								scanf("%c",&opt_menu_calc);
								while(getchar()!='\n');
								switch(opt_menu_calc)
								{
									case SYMBOL_SUBMENU_CALC_MEDIA:
										pos = count_assignatures(assignatures);
										media = calc_media(notes,pos);
										print_media(media);
										break;

									case SYMBOL_SUBMENU_CALC_MIN:
										pos = count_assignatures(assignatures);
										min = calc_min(notes,pos);
										print_min(min);
										break;

									case SYMBOL_SUBMENU_CALC_MAX:
										pos = count_assignatures(assignatures);
										max = calc_max(notes,pos);
										print_max(max);
										break;

									case SYMBOL_SUBMENU_CALC_QUANTITY:
										pos = count_assignatures(assignatures);
										print_quantity(pos);
										break;

									case SYMBOL_SUBMENU_CALC_FAILURES:
										pos = count_assignatures(assignatures);
										failures = calc_failures(notes,pos);
										print_failures(failures);
										break;

									case SYMBOL_SUBMENU_CALC_BACK:
										break;

									default:
										fprintf(stderr,"Ninguna de las opciones ingresadas es correcta\n");
										return EXIT_FAILURE;
								}
							}while(opt_menu_calc!=SYMBOL_SUBMENU_CALC_BACK);
							state = STATE_MENU_PRINCIPAL;
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