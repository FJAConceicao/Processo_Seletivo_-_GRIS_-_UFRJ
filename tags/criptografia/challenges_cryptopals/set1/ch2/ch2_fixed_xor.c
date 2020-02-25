#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int column, line, binaryFinalToDecimal = 0;
	char caracter, strings[2][1000], stringsInBinario[2][1000] = {}, binaryFinal[1000] = "", resultXor[1000] = "";

    //array com numeros de 1 ate 15 da base hexadecimal para a base binaria com 4 bits
    const char hexToBin[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    
	printf("Informe valores hexadecimais de mesmo tamanho para as strings abaixo: \n\n");
	printf("String 1 : "); scanf(" %[^\n]s", strings[0]);
	printf("String 2 : "); scanf(" %[^\n]s", strings[1]);
	
	//CONVERTER AMBAS STRINGS PARA BINÁRIO E ARMAZENAR EM UM ARRAY COM 2 POSIÇÕES: 1 PARA CADA STRING
	for(column = 0; strings[0][column] != '\0'; ++column) {
		for(line = 0; line <= 1; ++line) {
			if((strings[line][column] - '0') >= 0 && (strings[line][column] - '0') <= 9) {
				strcat(stringsInBinario[line], hexToBin[(strings[line][column] - '0')]);
			} else {
				if(strings[line][column] == 'a' || strings[line][column] == 'A')
					strcat(stringsInBinario[line], hexToBin[10]);
				else if(strings[line][column] == 'b' || strings[line][column] == 'B')
                    strcat(stringsInBinario[line], hexToBin[11]);
				else if(strings[line][column] == 'c' || strings[line][column] == 'C')
                    strcat(stringsInBinario[line], hexToBin[12]);
				else if(strings[line][column] == 'd' || strings[line][column] == 'D')
                    strcat(stringsInBinario[line], hexToBin[13]);
				else if(strings[line][column] == 'e' || strings[line][column] == 'E')
                    strcat(stringsInBinario[line], hexToBin[14]);
				else if(strings[line][column] == 'f' || strings[line][column] == 'F')
                    strcat(stringsInBinario[line], hexToBin[15]);
			}
		}
	}

	//FAZER OPERAÇÃO XOR ENTRE AS DUAS STRINGS BIT A BIT
	for(column = 0; stringsInBinario[0][column] != '\0'; ++column) {
		caracter = ((stringsInBinario[0][column] - '0') ^ (stringsInBinario[1][column] - '0')) + '0';
		strncat(binaryFinal, &caracter, 1);
	}
    
	//CONVERTER binaryFinal PARA BASE 16
	for(column = 0; binaryFinal[column] != '\0'; ) {
		for(line = 3; line >= 0 ; --line) {
			binaryFinalToDecimal += (pow(2, line) * (binaryFinal[column++] - '0'));
		}
	
		if(binaryFinalToDecimal >= 0 && binaryFinalToDecimal <= 9) {
			caracter = (binaryFinalToDecimal + '0');
			strncat(resultXor, &caracter, 1);
		} else {
			if(binaryFinalToDecimal == 10){
                strcat(resultXor, "a");
			} else if(binaryFinalToDecimal == 11){
				strcat(resultXor, "b");
			} else if(binaryFinalToDecimal == 12){
                strcat(resultXor, "c");
			} else if(binaryFinalToDecimal == 13){
                strcat(resultXor, "d");
			} else if(binaryFinalToDecimal == 14){
                strcat(resultXor, "e");
			} else if(binaryFinalToDecimal == 15){
                strcat(resultXor, "f");
			}
		}
		binaryFinalToDecimal = 0;
	}
	
	printf("Fixed XOR: %s\n", resultXor);

	return 0;
}
