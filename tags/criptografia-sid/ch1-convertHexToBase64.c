//Programa que converte números em Hexadecimal para base64
#include <stdio.h>
#include <string.h>
//#include <ctypes.h>

int main()
{	
	//criando string com tamanho maximo de 255 caracteres
	char string_hex[255];
	printf("Informe uma string em hexadecimal: ");
	scanf("%s", string_hex);

	//array com numeros de 1 ate 15 na base hexadecimal para a base binaria com 4 bits
	char hex_for_bin[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
	
	//variavel para armazenar a conversao da string hexadecimal para binario
	char string_bin[1000] = "";

	int i;

	//convertendo a string em hexadecimal e armazenando na string em binario
	for(i = 0; string_hex[i] != '\0'; i++)
	{
		if((string_hex[i] - '0') >= 0 && (string_hex[i] - '0') <= 9)
		{
			strcat(string_bin, hex_for_bin[string_hex[i] - '0']);
		}
		else
		{
			if(string_hex[i] == 'a' || string_hex[i] == 'A')
				strcat(string_bin, hex_for_bin[10]);
			else if(string_hex[i] == 'b' || string_hex[i] == 'B')
				strcat(string_bin, hex_for_bin[11]);
			else if(string_hex[i] == 'c' || string_hex[i] == 'C')
                                strcat(string_bin, hex_for_bin[12]);
			else if(string_hex[i] == 'd' || string_hex[i] == 'D')
                                strcat(string_bin, hex_for_bin[13]);
			else if(string_hex[i] == 'e' || string_hex[i] == 'E')
                                strcat(string_bin, hex_for_bin[14]);
			else
                                strcat(string_bin, hex_for_bin[15]);
		}
	}

	printf("String hexadecimal: %s\n", string_hex);
	printf("String binária....: %s\n", string_bin);

	return 0;
}
