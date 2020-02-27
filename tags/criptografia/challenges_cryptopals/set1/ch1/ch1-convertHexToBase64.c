#include <stdio.h>
#include <string.h>
#include <math.h>

#define BASE64TABLE "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
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
    
int main() {
    
    /** Criação das variaveis que vão ser utilizadas ao longo do programa **/
    int index, count = 0, var = 0;
    char stringHexadecimal[1024];
    char stringBinary[1024] = "";
    char stringInBase64[1024] = "";
    
	const char valuesInHexadecimalToBinary[16][5] = {"0000", "0001", "0010", "0011", 
                                                     "0100", "0101", "0110", "0111",
                                                     "1000", "1001", "1010", "1011", 
                                                     "1100", "1101", "1110", "1111"};
    
	/** Pedindo string hexadecimal para usuário **/
    printf("Informe uma string em base hexadecimal:\n\n");
	askForStringHexadecimal(stringHexadecimal, 1024);
    
    /* Verificando se stringHexadecimal esta na base correta
     * Se não, pedimos a string novamente até ela estar correta
     */
    while(var == 0) {
        var = 1;
        for(index = 0; stringHexadecimal[index] != '\0'; ++index) {
            if((strchr(BASE16TABLE, stringHexadecimal[index]) == NULL) && (stringHexadecimal[index] != ' ')) {
                var = 0;
                printf("\n[BASE_INCORRETA!] Informe a string corretamente ...\n\n");
                askForStringHexadecimal(stringHexadecimal, 1024);
                break;
            }
        }
    }
    
    /** Removendo espaços em branco da string em hexadecimal, caso tenha **/
    for(index = 0; stringHexadecimal[index] != '\0'; ++index) {
        if(stringHexadecimal[index] != ' ') {
            stringHexadecimal[count] = stringHexadecimal[index];
            ++count;
        }
    }
    stringHexadecimal[count] = '\0';
    
	/** Convertendo stringHexadecimal para binário e armazenando em stringBinary **/
	for(index = 0; stringHexadecimal[index] != '\0'; ++index) {
		if((stringHexadecimal[index] - '0') >= 0 && (stringHexadecimal[index] - '0') <= 9) {
			strcat(stringBinary, valuesInHexadecimalToBinary[stringHexadecimal[index] - '0']);
		}else{
			if(stringHexadecimal[index] == 'a' || stringHexadecimal[index] == 'A')
				strcat(stringBinary, valuesInHexadecimalToBinary[10]);
			else if(stringHexadecimal[index] == 'b' || stringHexadecimal[index] == 'B')
				strcat(stringBinary, valuesInHexadecimalToBinary[11]);
			else if(stringHexadecimal[index] == 'c' || stringHexadecimal[index] == 'C')
                                strcat(stringBinary, valuesInHexadecimalToBinary[12]);
			else if(stringHexadecimal[index] == 'd' || stringHexadecimal[index] == 'D')
                                strcat(stringBinary, valuesInHexadecimalToBinary[13]);
			else if(stringHexadecimal[index] == 'e' || stringHexadecimal[index] == 'E')
                                strcat(stringBinary, valuesInHexadecimalToBinary[14]);
			else if(stringHexadecimal[index] == 'f' || stringHexadecimal[index] == 'F')
                                strcat(stringBinary, valuesInHexadecimalToBinary[15]);
		}
	}
    
    count = 0;
    
	/** Acrescentando zeros na string binária até que ela seja divisivel por 6 **/
	while(strlen(stringBinary)%6 != 0){
		strcat(stringBinary, "0");
		++count;
	}
    
    /** Convertendo cada 6 bits da stringBinary para decimal, da esquerda para a direita 
     * e concatenando seu valor em base64 com stringInBase64 
     **/
	for(index = 0; stringBinary[index] != '\0'; index += 6) {
        
        //Definindo uma substring com 6 bits da stringBinary, a cada loop, e armazenando em byteInBase64
		char byteInBase64[6] = "";
        for(var = index; var < (index + 6); ++var)
            strncat(byteInBase64, &stringBinary[var], 1);
		
		//Converter byteInBase64 para decimal
		int numberOfCharInBase64 = 0;
		for(var = 5; var >= 0; --var) {
			numberOfCharInBase64 += (pow(2, var) * (byteInBase64[5 - var] - '0'));
		}

		//Concatenar numero correspondente ao numberOfCharInBase64 na tabela de base 64 com stringInBase64
		strncat(stringInBase64, &BASE64TABLE[numberOfCharInBase64], 1);
	}
    
	/** Colocando padding no final da conversão, caso seja necessário **/
	char padding = '=';
    count = count / 2;
    while(count > 0){
        strncat(stringInBase64, &padding, 1);
        --count;
    }
    
    printf("\nResultado da conversão para base 64: \n\n%s\n", stringInBase64);
    
	return 0;
}
