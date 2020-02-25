#include <stdio.h>
#include <string.h>
#include <math.h>

#define BASE64TABLE "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
#define BASE16TABLE "0123456789abcdefABCDEF"

int main()
{
    /**Criando variaveis que vão ser utilizadas ao longo do programa**/
    int index, count = 0, var = 0;

    char stringBinary[1000] = "", stringInBase64[1000] = "";
    
    //array com numeros de 1 ate 15 da base hexadecimal para a base binaria com 4 bits
	const char hexadecimalToBinary[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    
	/**criando string hexadecimal que irá guardar entrada do usuário à ser pedida logo na 2ª linha abaixo**/
	char stringHexadecimal[255];
    printf("Informe uma string em base hexadecimal:\n\n");
	scanf(" %[^\n]s", stringHexadecimal);
    
    //removendo espaços da string em hexadecimal, caso tenha
    for(index = 0; stringHexadecimal[index] != '\0'; ++index) {
        if(stringHexadecimal[index] != ' ') {
            stringHexadecimal[count] = stringHexadecimal[index];
            ++count;
        }
    }
    stringHexadecimal[count] = '\0';
    
    /*
    *parte que verifica se string informada pelo usuário esta correta
    *se não estiver correta, mostra uma mensagem de erro e pede a string novamente
    */
    while(var == 0) {
        var = 1;
        for(index = 0; stringHexadecimal[index] != '\0'; ++index) {
            if(strchr(BASE16TABLE, stringHexadecimal[index]) == NULL) {
                var = 0;
                printf("\n[BASE_INCORRETA!] Informe a string corretamente ...\n\n");
                scanf(" %[^\n]s", stringHexadecimal);
                break;
            }
        }
    }
	
	/*convertendo a string em hexadecimal para binário*/
	for(index = 0; stringHexadecimal[index] != '\0'; ++index) {
		if((stringHexadecimal[index] - '0') >= 0 && (stringHexadecimal[index] - '0') <= 9) {
			strcat(stringBinary, hexadecimalToBinary[stringHexadecimal[index] - '0']);
		}else{
			if(stringHexadecimal[index] == 'a' || stringHexadecimal[index] == 'A')
				strcat(stringBinary, hexadecimalToBinary[10]);
			else if(stringHexadecimal[index] == 'b' || stringHexadecimal[index] == 'B')
				strcat(stringBinary, hexadecimalToBinary[11]);
			else if(stringHexadecimal[index] == 'c' || stringHexadecimal[index] == 'C')
                                strcat(stringBinary, hexadecimalToBinary[12]);
			else if(stringHexadecimal[index] == 'd' || stringHexadecimal[index] == 'D')
                                strcat(stringBinary, hexadecimalToBinary[13]);
			else if(stringHexadecimal[index] == 'e' || stringHexadecimal[index] == 'E')
                                strcat(stringBinary, hexadecimalToBinary[14]);
			else if(stringHexadecimal[index] == 'f' || stringHexadecimal[index] == 'F')
                                strcat(stringBinary, hexadecimalToBinary[15]);
		}
	}
    
    count = 0;
    
	/*Essa parte acrescenta zeros na string binária até que ela seja divisivel por 6*/
	while(strlen(stringBinary)%6 != 0){
		strcat(stringBinary, "0");
		++count;
	}
    
    /*Parte que na stringBinary converte cada 6 bits para decimal da esquerda para a direita e concatena seu valor em base64 com stringInBase64*/
	for(index = 0; stringBinary[index] != '\0'; index += 6) {
        
        //definindo uma substring com 6 bits da stringBinary para converter para decimal e obter o valor na tabela de base64
		char byteInBase64[6] = "";
        for(var = index; var < (index + 6); ++var)
            strncat(byteInBase64, &stringBinary[var], 1);
		
		//converter byteInBase64 para decimal
		int numberOfCharInBase64 = 0;
		for(var = 5; var >= 0; --var) {
			numberOfCharInBase64 += (pow(2, var) * (byteInBase64[5 - var] - '0'));
		}

		//concatenar numero correspondente ao numberOfCharInBase64 na tabela de base 64 com a variável que armazena a conversão para base 64
		strncat(stringInBase64, &BASE64TABLE[numberOfCharInBase64], 1);
	}
	
	//colocando padding no final da conversão, caso seja necessário
	char padding = '=';
	strncat(stringInBase64, &padding, (int)(count/2));

	printf("\nResultado da conversão para base 64: \n\n%s\n", stringInBase64);

	return 0;
}
