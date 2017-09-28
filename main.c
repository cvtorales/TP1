#include <stdio.h>
#include <ctype.h>
#include "idioma.h"
#include "functions.h"
#include "common.h"

int main (void)
{
	char option,opt_menu_assig, opt_menu_pers_reg,opt_menu_calc; /*sera la lectura de opciones*/
	char assignatures[MAX_ROW][MAX_COL];
	char personal_reg[MAX_ROW_PERS_REG][MAX_COL_PERS_REG];
	int i,j,pos,min,max,failures,modification_pos;
	int notes[MAX_ROW];
	float media;
	state_t state;
	int calif_control;
	long int padron,padron_control;

	state = STATE_MENU_WELCOME;
	j = 0;
	media = 0;
	padron = 0;
	pos = 0;
	failures = -1;

	for(i=0;i<MAX_ROW;i++)
	{
		assignatures[i][j] = '\0'; /*aca hay hardcodeo*/
		notes[i] = 0;
	} /* inicializo la matriz assignatures y el vector de notas*/

	for(i=0;i<MAX_ROW_PERS_REG;i++)
		personal_reg[i][j] = '\0';


	while(state != STATE_QUIT)
	{
		switch(state)
		{
			case STATE_MENU_WELCOME:
				puts(MSG_WELCOME);
				state = STATE_MENU_PRINCIPAL;
				break;
			case STATE_MENU_PRINCIPAL:
				while(state != STATE_QUIT)
				{
					print_menu_principal();
					if((scanf("%c",&option))!=1)
					{
						fprintf(stderr, "%s\n", MSG_ERROR_OPTION_MENU);
					/*	return EXIT_FAILURE;   */
					}
					while(getchar()!='\n');		 /* estas dos lineas, de scanf y toupper pueden ir en una funcion leer_opcion con todas sus validaciones */
					option = toupper(option); /* si utilizo toupper entonces el usr puede ingresa en minuscula y no pasa nada */

					switch(option)
					{
						case SYMBOL_MENU_PERSONAL_REGISTER:
							state = STATE_MENU_PERSONAL_REGISTER;
							do
							{
								print_menu_pers_reg();
								if((scanf("%c",&opt_menu_pers_reg))!=1)
								{
									fprintf(stderr, "%s\n", MSG_ERROR_OPTION_MENU);
									/*return EXIT_FAILURE;*/
								}
								while(getchar()!='\n');
								opt_menu_pers_reg = toupper(opt_menu_pers_reg);
								switch(opt_menu_pers_reg)
								{
									case SYMBOL_SUBMENU_PERSONAL_REGISTER_LASTNAME_NAME:
                                                puts(MSG_MENU_PERSONAL_REGISTER_ADD_SURNAME);
                                                add_last_name(personal_reg);
                                                puts(MSG_MENU_PERSONAL_REGISTER_ADD_NAME);
                                                add_name(personal_reg);
                                                break;

                                    case SYMBOL_SUBMENU_PERSONAL_REGISTER_PADRON:
                                                puts(MSG_MENU_PERSONAL_REGISTER_ADD_PADRON);
                                              	padron_control = add_padron(&padron);
												while(padron_control)
												{
												puts(MSG_MENU_PERSONAL_REGISTER_ADD_PADRON);
												padron_control = add_padron(&padron);
												}
                                                break;

                                    case SYMBOL_SUBMENU_PERSONAL_REGISTER_CAREER:
                                                puts(MSG_MENU_PERSONAL_REGISTER_ADD_CARRERA);
                                                add_career(personal_reg);
                                                break;

                                    case SYMBOL_SUBMENU_PERSONAL_REGISTER_BACK:
                                                break;
                                    default:
										fprintf(stderr, "%s\n", MSG_ERROR_OPTION_MENU);
										/*return EXIT_FAILURE;*/
								}
							}while(opt_menu_pers_reg!=SYMBOL_SUBMENU_PERSONAL_REGISTER_BACK);
							state = STATE_MENU_PRINCIPAL;


							break;

						case SYMBOL_MENU_ASSIGNATURE:
							state = STATE_MENU_ASSIGNATURE;
							do
							{
								print_menu_assig(assignatures,notes);
								if((scanf("%c",&opt_menu_assig))!=1)
								{
									fprintf(stderr, "%s\n", MSG_ERROR_OPTION_MENU);
									/*return EXIT_FAILURE;*/
								}
								while(getchar()!='\n');
								switch(opt_menu_assig)
								{
									case SYMBOL_SUBMENU_ASSIG_MODIFY_POS_1:
									case SYMBOL_SUBMENU_ASSIG_MODIFY_POS_2:
									case SYMBOL_SUBMENU_ASSIG_MODIFY_POS_3:
									case SYMBOL_SUBMENU_ASSIG_MODIFY_POS_4:
									case SYMBOL_SUBMENU_ASSIG_MODIFY_POS_5:
									case SYMBOL_SUBMENU_ASSIG_MODIFY_POS_6:
									case SYMBOL_SUBMENU_ASSIG_MODIFY_POS_7:
									case SYMBOL_SUBMENU_ASSIG_MODIFY_POS_8:
									case SYMBOL_SUBMENU_ASSIG_MODIFY_POS_9:
										pos = count_assignatures(assignatures);
										modification_pos = (int)opt_menu_assig-FACTOR_CONVERTION_CHAR_TO_INT-1;/* -48 para convertir a int y -1 para entrar en la posicion correcta dentro del arreglo*/
										if (pos && (modification_pos < pos))
										{
											modify_assignatures(assignatures,notes,modification_pos);
										}
										break;

									case SYMBOL_SUBMENU_ASSIG_ADD_ASSIG:
										pos = count_assignatures(assignatures);
										if(!pos)
										{
											puts(MSG_MENU_ASSIGNATURE_ADD_ASSIGNATURE);
											add_assignature(assignatures,pos);
											puts(MSG_MENU_ASSIGNATURE_ADD_QUALIFICATION);
											calif_control = add_notes(notes,pos);
											while(calif_control)
											{
												puts(MSG_MENU_ASSIGNATURE_ADD_QUALIFICATION);
												calif_control = add_notes(notes,pos);
											}

										}
										break;

									case SYMBOL_SUBMENU_ASSIG_BACK:
										break;

									default:
										fprintf(stderr, "%s\n", MSG_ERROR_OPTION_MENU);
										/*return EXIT_FAILURE;*/
								}
							}while(opt_menu_assig!=SYMBOL_SUBMENU_ASSIG_BACK);
							state = STATE_MENU_PRINCIPAL;
							break;

						case SYMBOL_MENU_CALC:
							state = STATE_MENU_CALC;
							do
							{
								print_menu_calc();
								if((scanf("%c",&opt_menu_calc))!=1)
								{
									fprintf(stderr, "%s\n", MSG_ERROR_OPTION_MENU);
									/*return EXIT_FAILURE;*/
								}
								while(getchar()!='\n');
								if(opt_menu_calc != SYMBOL_SUBMENU_CALC_MIN || opt_menu_calc !=SYMBOL_SUBMENU_CALC_MAX)
									opt_menu_calc=toupper(opt_menu_calc);
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
										fprintf(stderr, "%s\n", MSG_ERROR_OPTION_MENU);
										/*return EXIT_FAILURE;*/
								}
							}while(opt_menu_calc!=SYMBOL_SUBMENU_CALC_BACK);
							state = STATE_MENU_PRINCIPAL;
							break;


						case SYMBOL_FINALIZE:
							state = STATE_FINALIZE;
							pos = count_assignatures(assignatures);
							finalize(personal_reg,padron,media,notes,pos,failures);
							state = STATE_MENU_PRINCIPAL;
							break;

						case SYMBOL_QUIT:
							state = STATE_QUIT;
							break;

						default:
							fprintf(stderr, "%s\n", MSG_ERROR_OPTION_MENU);
						/*	return EXIT_FAILURE;*/
					}
				}
				break;

			default:
				fprintf(stderr, "%s\n", MSG_ERROR_OPTION_MENU);
			/*	return EXIT_FAILURE;  */
		}
	}

	return EXIT_SUCCESS;
}
