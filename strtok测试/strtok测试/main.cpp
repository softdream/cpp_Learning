#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iostream>

const char string[] = "2021-01-19";
char seps[] = "-";


int main(void)
{
	char *token;
	char *str = new char[strlen(string) + 1];
	strcpy( str, string );
	//printf( "str = %s\r\n", str );
	std::cout << "str = " << str << std::endl;
	token = strtok(str, "-");
	printf("%s\n", token);
	printf("----------------------\n");
	/*while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, "-");
	}*/
	token = strtok(NULL, "-" );
	printf("%s\n", token);
	printf("----------------------\n");
	token = strtok(NULL, "-");
	printf("%s\n", token);
	printf("----------------------\n");

	getch();
	return 0;
}