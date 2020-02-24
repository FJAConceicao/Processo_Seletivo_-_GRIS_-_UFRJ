#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	char strings[2][1000];
	char stringsInBinario[2][1000] = {};
	char binaryFinal[1000] = "";
	char resultXor[1000] = "";

	printf("Informe valores hexadecimais de mesmo tamanho para as strings abaixo: \n\n");

	printf("String 1: "); scanf("%s", strings[0]);
	printf("String 2: "); scanf("%s", strings[1]);
	
	//array com numeros de 1 ate 15 da base hexadecimal para a base binaria com 4 bits
        char hexToBin[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
	
	//CONVERTER AMBAS STRINGS PARA BINÁRIO E ARMAZENAR EM UM ARRAY COM 2 POSIÇÕES: 1 PARA CADA STRING
	int i, j, c;
	for(i = 0; strings[0][i] != '\0'; ++i)
	{
		for(j = 0; j <= 1; ++j)
		{
			if((strings[j][i] - '0') >= 0 && (strings[j][i] - '0') <= 9)
			{
				strcat(stringsInBinario[j], hexToBin[(strings[j][i] - '0')]);
			}
			else
			{
				if(strings[j][i] == 'a' || strings[j][i] == 'A')
					strcat(stringsInBinario[j], hexToBin[10]);
				else if(strings[j][i] == 'b' || strings[j][i] == 'B')
                                        strcat(stringsInBinario[j], hexToBin[11]);
				else if(strings[j][i] == 'c' || strings[j][i] == 'C')
                                        strcat(stringsInBinario[j], hexToBin[12]);
				else if(strings[j][i] == 'd' || strings[j][i] == 'D')
                                        strcat(stringsInBinario[j], hexToBin[13]);
				else if(strings[j][i] == 'e' || strings[j][i] == 'E')
                                        strcat(stringsInBinario[j], hexToBin[14]);
				else if(strings[j][i] == 'f' || strings[j][i] == 'F')
                                        strcat(stringsInBinario[j], hexToBin[15]);
			}
		}
	}

	//FAZER OPERAÇÃO XOR ENTRE AS DUAS STRINGS BIT A BIT
	char caracter;
	for(i = 0; stringsInBinario[0][i] != '\0'; ++i)
	{
		caracter = ((stringsInBinario[0][i] - '0')^(stringsInBinario[1][i] - '0')) + '0';
		strncat(binaryFinal, &caracter, 1);
	}
 	
	//CONVERTER binaryFinal PARA BASE 16
	int number = 0;
	char xor;
	for(i = 0; binaryFinal[i] != '\0'; i += 4)
	{
		for(c=i, j=3; j > -1; --j, ++c)
		{
			number += (pow(2, j) * (binaryFinal[c] - '0'));
		}
	
		if(number >= 0 && number <= 9)
		{
			xor = (number + '0');
			strncat(resultXor, &xor, 1);
		}
		else
		{
			if(number == 10){
				xor = 'a';
			       	strncat(resultXor, &xor, 1);
			}else if(number == 11){
				xor = 'b';
				strncat(resultXor, &xor, 1);
			}else if(number == 12){
                                xor = 'c';
                                strncat(resultXor, &xor, 1);
			}else if(number == 13){
                                xor = 'd';
                                strncat(resultXor, &xor, 1);
			}else if(number == 14){
                                xor = 'e';
                                strncat(resultXor, &xor, 1);
			}else if(number == 15){
                                xor = 'f';
                                strncat(resultXor, &xor, 1);
			}
		}
		number = 0;
	}
	
	printf("String 1 - Binaria: %s\n", stringsInBinario[0]);
	printf("String 2 - Binaria: %s\n", stringsInBinario[1]);
	printf("Str1 XOR Str2.....: %s\n", binaryFinal);
	printf("Resultado Final...: %s\n", resultXor);

	return 0;
}
