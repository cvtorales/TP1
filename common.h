#ifndef COMMON_H
#define COMMON_H

typedef enum {
				STATE_MENU_WELCOME = 0,
				STATE_MENU_PRINCIPAL,
				STATE_MENU_PERSONAL_REGISTER,
				STATE_MENU_ASSIGNATURE,
				STATE_MENU_CALC,
				STATE_FINALIZE,
				STATE_QUIT
			} state_t;

#endif

#define SYMBOL_MENU_PERSONAL_REGISTER 'R'
#define SYMBOL_MENU_ASSIGNATURE 'A'
#define SYMBOL_MENU_CALC 'M'
#define SYMBOL_FINALIZE '!'
#define SYMBOL_QUIT '0'

#define SYMBOL_SUBMENU_ASSIG_ADD_ASSIG '+'
#define SYMBOL_SUBMENU_ASSIG_BACK '0'
#define SYMBOL_SUBMENU_ASSIG_MODIFY_POS_1 '1'
#define SYMBOL_SUBMENU_ASSIG_MODIFY_POS_2 '2'
#define SYMBOL_SUBMENU_ASSIG_MODIFY_POS_3 '3'
#define SYMBOL_SUBMENU_ASSIG_MODIFY_POS_4 '4'
#define SYMBOL_SUBMENU_ASSIG_MODIFY_POS_5 '5'
#define SYMBOL_SUBMENU_ASSIG_MODIFY_POS_6 '6'
#define SYMBOL_SUBMENU_ASSIG_MODIFY_POS_7 '7'
#define SYMBOL_SUBMENU_ASSIG_MODIFY_POS_8 '8'
#define SYMBOL_SUBMENU_ASSIG_MODIFY_POS_9 '9'

#define SYMBOL_SUBMENU_CALC_MEDIA 'P'
#define SYMBOL_SUBMENU_CALC_MIN 'm'
#define SYMBOL_SUBMENU_CALC_MAX 'M'
#define SYMBOL_SUBMENU_CALC_QUANTITY '#'
#define SYMBOL_SUBMENU_CALC_FAILURES '2'
#define SYMBOL_SUBMENU_CALC_BACK '0'

#define MAX_ROW 10
#define MAX_COL 30
#define MAX_ROW_PERS_REG 3
#define MAX_COL_PERS_REG 50
#define POSITION_LAST_NAME 0
#define POSITION_NAME 1
#define POSITION_CAREER 2
#define MIN_NOTE 0
#define MAX_NOTE 10

#define FACTOR_CONVERTION_CHAR_TO_INT 48

#define SYMBOL_SUBMENU_PERSONAL_REGISTER_BACK '0'
#define SYMBOL_SUBMENU_PERSONAL_REGISTER_LASTNAME_NAME 'A'
#define SYMBOL_SUBMENU_PERSONAL_REGISTER_PADRON '#'
#define SYMBOL_SUBMENU_PERSONAL_REGISTER_CAREER 'C'