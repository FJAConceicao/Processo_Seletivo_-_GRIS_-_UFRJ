#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	/*pedindo valor hexadecimal para o usuário*/
	char *hex;
	printf("Informe um valor em hexadecimal: ");
	scanf("%s", hex);

	//TASK: Validar valor hexadecinal
	
	char *strHex;
	int lenStrHex = strlen(hex);
	int resto = lenStrHex%6;

	if(resto != 0)
		lenStrHex += (6-resto);
	
	strHex = (char *)malloc(lenStrHex);
	strHex = hex;

	strcpy(strHex, '0'*(6-resto));	
	printf("hexadecimal: %s\n", strHex);

	return 0;
}
