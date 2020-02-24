//Programa que converte números em Hexadecimal para base64
#include <stdio.h>
#include <string.h>
#include <math.h>
/*define tabelaBase64[64] "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"*/

int main()
{	
	const char tabelaBase64[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	//criando string com tamanho maximo de 255 caracteres
	char string_hex[255];
	printf("Informe uma string em hexadecimal: ");
	scanf("%s", string_hex);
	
	//TODO: Fazer validação da string em hexadecimal
	
	//array com numeros de 1 ate 15 da base hexadecimal para a base binaria com 4 bits
	char hex_to_bin[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
	
	//variavel para armazenar a conversao da string hexadecimal para binario
	//int len_string_hex = (strlen(string_hex) * 4) + 20;
	char string_bin[1000] = "";
	
	//convertendo a string em hexadecimal e armazenando na string em binario
	int i;
	for(i = 0; string_hex[i] != '\0'; ++i)
	{
		if((string_hex[i] - '0') >= 0 && (string_hex[i] - '0') <= 9)
		{
			strcat(string_bin, hex_to_bin[string_hex[i] - '0']);
		}
		else
		{
			if(string_hex[i] == 'a' || string_hex[i] == 'A')
				strcat(string_bin, hex_to_bin[10]);
			else if(string_hex[i] == 'b' || string_hex[i] == 'B')
				strcat(string_bin, hex_to_bin[11]);
			else if(string_hex[i] == 'c' || string_hex[i] == 'C')
                                strcat(string_bin, hex_to_bin[12]);
			else if(string_hex[i] == 'd' || string_hex[i] == 'D')
                                strcat(string_bin, hex_to_bin[13]);
			else if(string_hex[i] == 'e' || string_hex[i] == 'E')
                                strcat(string_bin, hex_to_bin[14]);
			else if(string_hex[i] == 'f' || string_hex[i] == 'F')
                                strcat(string_bin, hex_to_bin[15]);
		}
	}

	//Essa parte acrescenta zeros na string binária até que ela seja divisivel por 6
	int cont = 0;
	while(strlen(string_bin)%6 != 0)
	{
		strcat(string_bin, "0");
		++cont;
	}

	/*
	printf("%ld\n", strlen(string_bin));	
	printf("String binária: %s\n", string_bin);
	*/
	
	int num;
	char stringConvertBase64[1000] = "";

	for(i = 0; i < strlen(string_bin); i += 6)
	{
		//Definindo uma substring com 6 bits da string_bin para converter para decimal e obter o valor na tabela de base64
		num = i;
		char byteInBase64[7] = "";
		while(num < (i + 6))
		{
			strncat(byteInBase64, &string_bin[num], 1);
			++num;
		}
		
		printf("Byte in Base 64: %s\n", byteInBase64);
		
		//converter byteInBase64 para decimal
		int j, numberOfCharInBase64 = 0;
		for(j = 0, num = 5; num >= 0; --num, ++j)
		{
			numberOfCharInBase64 += (pow(2, num) * (byteInBase64[j] - '0'));
		}

		printf("Number Of Char In Base 64: %d\n\n", numberOfCharInBase64);

		//concatenar numero correspondente ao numberOfCharInBase64 na tabela de base 64 com a variável que armazena a conversão para base 64
		strncat(stringConvertBase64, &tabelaBase64[numberOfCharInBase64], 1);
	}
	
	//colocando padding no final da conversão, caso seja necessário
	char padding = '=';
	strncat(stringConvertBase64, &padding, (int)(cont/2));

	printf("String hexadecimal: %s\n", string_hex);
	printf("String binária....: %s\n", string_bin);
	printf("String em base64..: %s\n", stringConvertBase64);

	return 0;
}
