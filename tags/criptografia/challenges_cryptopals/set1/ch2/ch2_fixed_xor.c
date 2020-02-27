#include <stdio.h>
#include <string.h>
#include <math.h>

#define BASE16TABLE "0123456789abcdefABCDEF"

/*Função para pedir string hexadecimal*/
void askForStringHexadecimal(char *string, int size) {
    int lastCharacterIndex;
    if(fgets(string, size, stdin) != NULL) {
        lastCharacterIndex = strlen(string) - 1;
        if(string[lastCharacterIndex] == '\n')
            string[lastCharacterIndex] = '\0';
    }
}

int main()
{
    /** Criando variaveis que vão ser utilizadas ao longo do programa **/
    int col, lin, binaryResultXorOperationToDecimal = 0;
	char caracter, strings[2][1024], stringsInBinary[2][1024] = {}, binaryResultXorOperation[1024] = "", stringResultXor[1024] = "";
    
    const char valuesInHexadecimalToBinary[16][5] = {"0000", "0001", "0010", "0011", 
                                                     "0100", "0101", "0110", "0111", 
                                                     "1000", "1001", "1010", "1011", 
                                                     "1100", "1101", "1110", "1111"};
    
    /** Pedindo strings **/
	printf("Informe valores hexadecimais de mesmo tamanho para as strings abaixo: \n\n");
	printf("String 1 : "); askForStringHexadecimal(strings[0], 1024);
	printf("String 2 : "); askForStringHexadecimal(strings[1], 1024);
	
    //Verificar se as string possuem o mesmo tamanho
    if(strlen(strings[0]) != strlen(strings[1])) {
        printf("[ERRO --> TAMANHOS_DIFERENTES!] Informe strings de mesmo tamanho!\n");
        return 1;
    }
    
    /* Verificando se as strings estão na base correta
     * Se não, o programa mostra uma mensagem de erro e termina
     */
    for(col = 0; col <= 1; ++col) {
        for(lin = 0; strings[col][lin] != '\0'; ++lin) {
            if((strchr(BASE16TABLE, strings[col][lin]) == NULL) && (strings[col][lin] != ' ')) {
                printf("[ERRO --> BASE_INCORRETA!] Informe a(s) string(s) corretamente!\n");
                return 1;
            }
        }
    }
    
    /** Removendo espaços em branco das strings, caso tenha **/
    for(lin = 0; lin <= 1; ++lin) {
        int count = 0;
        for(col = 0; strings[lin][col] != '\0'; ++col) {
            if(strings[lin][col] != ' ') {
                strings[lin][count] = strings[lin][col];
                ++count;
            }
        }
        strings[lin][count] = '\0';
    }
    
	/** Converter ambas strings para binário e armazenar em um array com 2 posições: 1 para cada string **/
	for(col = 0; strings[0][col] != '\0'; ++col) {
		for(lin = 0; lin <= 1; ++lin) {
			if((strings[lin][col] - '0') >= 0 && (strings[lin][col] - '0') <= 9) {
				strcat(stringsInBinary[lin], valuesInHexadecimalToBinary[(strings[lin][col] - '0')]);
			} else {
				if(strings[lin][col] == 'a' || strings[lin][col] == 'A')
					strcat(stringsInBinary[lin], valuesInHexadecimalToBinary[10]);
				else if(strings[lin][col] == 'b' || strings[lin][col] == 'B')
                    strcat(stringsInBinary[lin], valuesInHexadecimalToBinary[11]);
				else if(strings[lin][col] == 'c' || strings[lin][col] == 'C')
                    strcat(stringsInBinary[lin], valuesInHexadecimalToBinary[12]);
				else if(strings[lin][col] == 'd' || strings[lin][col] == 'D')
                    strcat(stringsInBinary[lin], valuesInHexadecimalToBinary[13]);
				else if(strings[lin][col] == 'e' || strings[lin][col] == 'E')
                    strcat(stringsInBinary[lin], valuesInHexadecimalToBinary[14]);
				else if(strings[lin][col] == 'f' || strings[lin][col] == 'F')
                    strcat(stringsInBinary[lin], valuesInHexadecimalToBinary[15]);
			}
		}
	}
    
	/** Fazer operação xor entre as duas strings bit a bit **/
	for(col = 0; stringsInBinary[0][col] != '\0'; ++col) {
		caracter = ((stringsInBinary[0][col] - '0') ^ (stringsInBinary[1][col] - '0')) + '0';
		strncat(binaryResultXorOperation, &caracter, 1);
	}
    
	/** Converter binaryResultXorOperation para base 16 **/
	for(col = 0; binaryResultXorOperation[col] != '\0'; ) {
        
        //converte cada 4 bits de binaryResultXorOperation para decimal 
        for(lin = 3; lin >= 0 ; --lin) {
			binaryResultXorOperationToDecimal += (pow(2, lin) * (binaryResultXorOperation[col] - '0'));
            ++col;
		}
	
        //verifica qual valor binaryResultXorOperationToDecimal corresponde em hexadecimal
        //na macro BASE16TABLE e concatena com stringResultXor
        strncat(stringResultXor, &BASE16TABLE[binaryResultXorOperationToDecimal], 1);
		binaryResultXorOperationToDecimal = 0;
	}
	
	printf("Fixed XOR: %s\n", stringResultXor);

	return 0;
}
