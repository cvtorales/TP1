#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "messages.h"


int count_assignatures(char m[][MAX_COL]);
void add_assignature(char m[MAX_ROW][MAX_COL],int pos);
void add_notes(int notes[MAX_ROW],int pos);

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

void add_notes(int notes[MAX_ROW],int pos)
{
	int aux;

	scanf("%d",&aux);
	while(getchar()!='\n');	
	notes[pos] = aux;
}