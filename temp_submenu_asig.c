void add_assignature_name(char assignatures[][MAX_COL], int position_row)
{
	char aux[MAX_STR];
	int pos, qualification;

	scanf("%s %d",aux,&qualification); /* FALTA VALIDAR SCANF*/
	while(getchar()!='\n');
	pos=strlen(aux);/*requiere string.h o stdlib.h*/
	aux[pos]='\0';
	strcpy(assignatures[position_row],aux);
}

void add_assignature_qualification(char assignatures[][MAX_COL], int position_row)
{
	char aux[MAX_STR];
	int pos, qualification;

	scanf("%s %d",aux,&qualification); /* FALTA VALIDAR SCANF*/
	while(getchar()!='\n');
	pos=strlen(aux);/*requiere string.h o stdlib.h*/
	aux[pos]='\0';
	strcpy(assignatures[position_row],aux);
}
/*while(state != STATE_BACK) ESTO VA A MAIN
{
	if(option_submenu_asig == '+')
	{

	}else
	{
		state = STATE_BACK;
	}
}  TODO ESTO VA EN MAIN*/