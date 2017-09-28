#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

/*************************** Begin Prototypes  *************************/

int count_assignatures(char m[][MAX_COL]);
void add_assignature(char m[MAX_ROW][MAX_COL],int pos);
int add_notes(int notes[MAX_ROW],int pos);
void print_menu_principal();
void print_menu_calc();
void print_media(float media);
void print_min(int min);
void print_max(int min);
void print_quantity(int pos);
void print_failures(int pos);
float calc_media(int notes[MAX_ROW],int pos);
int calc_failures(int notes[MAX_ROW],int pos);
int calc_max(int notes[MAX_ROW],int pos);
int calc_min(int notes[MAX_ROW],int pos);
long int add_padron(long int* padron);
void finalize(char n[MAX_ROW_PERS_REG][MAX_COL_PERS_REG],int padron, float media, int notes[MAX_ROW],int courses, int failures);
void modify_assignatures(char a[MAX_ROW][MAX_COL],int notes[MAX_ROW], int pos);
void print_menu_pers_reg();
void add_last_name(char m[MAX_ROW_PERS_REG][MAX_COL_PERS_REG]);
void add_name(char m[MAX_ROW_PERS_REG][MAX_COL_PERS_REG]);
void add_career(char m[MAX_ROW_PERS_REG][MAX_COL_PERS_REG]);
void print_menu_assig(char assignatures[MAX_ROW][MAX_COL],int notes[MAX_ROW]);

/*************************** End Prototypes  *************************/
