#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	
long int add_padron(void)
{
	size_t aux;

	int padron;
	char *temp;

	char line[100];

	fgets(line,100,stdin);
	aux=strlen(line);

	if( aux != 6 && aux != 7)
	{
		printf("%s\n", "mal"); /* poner un mensaje de error */
		return EXIT_FAILURE;
	}

	num=strtol(line, &temp, 10);	  
	if(*temp && *temp != '\n') 
	{/* entra cuando temp se queda apuntando a una letra */
		printf("%s\n", "mal");
		return EXIT_FAILURE;  
	}
	if (num < 0)
	{
		printf("%s\n", "mal");
		return EXIT_FAILURE; 
	}
	return padron;
}
