#include <stdio.h>
#include <string.h>
#include <math.h>

#define BASE16TABLE "0123456789abcdefABCDEF"

/* Função para converter number para base binária de 8 bits
 * Armazena a conversão em string
 */
void decimalToBinary(char *string, int number) {
    char temp[8] = "", digit;
    int index;
    
    //Converte número para base binária
    while(1) {
        
        digit = number%2 + '0';
        strncat(temp, &digit, 1);
        
        if(number/2 == 0)
            break;
        
        number /= 2;
    }
    
    //Adiciona 0`s ao final do número, caso o tamanho seja menor que 8
    digit = '0';
    while(strlen(temp) < 8) {
        strncat(temp, &digit, 1);
    }
    
    //invertendo numberInBinary com ajuda de outra variavel
    for(index = 7; index >= 0; --index) {
        string[7 - index] = temp[index];
    }
}

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
    /** Declaração de variaveis para serem utilizadas no programa **/
    int index, value, var, valueIntDigitResult;
    char character, stringInput[1024], stringInputInBinary[1024] = "";
    
    const char valuesInHexadecimalToBinary[16][5] = {"0000", "0001", "0010", "0011", 
                                                     "0100", "0101", "0110", "0111",
                                                     "1000", "1001", "1010", "1011", 
                                                     "1100", "1101", "1110", "1111"};

    /** Pedir string hexadecimal do teclado e armazenar em stringInput **/
    printf("Informe uma string em hexadecimal abaixo: \n\n");
    askForStringHexadecimal(stringInput, 1024);
    
    /** verificar se stringInput esta na base hexadecimal **/
    for(index = 0; stringInput[index] != '\0'; ++index) {
        if((strchr(BASE16TABLE, stringInput[index]) == NULL) && (stringInput[index] != ' ')) {
            printf("\n[ERRO --> BASE_INCORRETA!] Informe a string corretamente!\n");
            return 1;
        }
    }
    
     /** Removendo espaços em branco de stringInput, caso tenha **/
    for(value = 0, index = 0; stringInput[index] != '\0'; ++index) {
        if(stringInput[index] != ' ') {
            stringInput[value] = stringInput[index];
            ++value;
        }
    }
    stringInput[value] = '\0';
    
    /** Converter stringInput para a base binária e armazenar em stringInputInBinary **/
    for(index = 0; stringInput[index] != '\0'; ++index){
        if((stringInput[index] - '0') >= 0 && (stringInput[index] - '0') <= 9)
            strcat(stringInputInBinary, valuesInHexadecimalToBinary[(stringInput[index] - '0')]);
        else
            if(stringInput[index] == 'a' || stringInput[index] == 'A')
                strcat(stringInputInBinary, valuesInHexadecimalToBinary[10]);
            else if(stringInput[index] == 'b' || stringInput[index] == 'B')
                strcat(stringInputInBinary, valuesInHexadecimalToBinary[11]);
            else if(stringInput[index] == 'c' || stringInput[index] == 'C')
                strcat(stringInputInBinary, valuesInHexadecimalToBinary[12]);
            else if(stringInput[index] == 'd' || stringInput[index] == 'D')
                strcat(stringInputInBinary, valuesInHexadecimalToBinary[13]);
            else if(stringInput[index] == 'e' || stringInput[index] == 'E')
                strcat(stringInputInBinary, valuesInHexadecimalToBinary[14]);
            else if(stringInput[index] == 'f' || stringInput[index] == 'F')
                strcat(stringInputInBinary, valuesInHexadecimalToBinary[15]);
    }
    
    printf("\n\nResultados: \n\n");
    
    /* Fazer combinação XOR com stringInputInBinary com todas as 256 possibilidades de chaves
     * Mostrar cada chave seguida da mensagem descriptada gerada
     */
    for(value = 0; value <= 255; ++value) {
        
        //Criando variaveis para serem utilizadas nesse loop
        char stringResultOfXor[1024] = "", stringValueToBinary[9] = "";
        decimalToBinary(stringValueToBinary, value);

        printf("%s - ", stringValueToBinary); //Mostrando chave em valores binários
        
        //For para fazer combinação Xor entre stringValueToBinary com stringInputInBinary
        for(index = 0; stringInputInBinary[index] != '\0'; index += 8){
            
            //Variáveis para serem utilizadas nesse segundo loop
            int byteStringResultDecimal = 0;
            char byteString[9] = "";
            
            //Pegando 8 bits da esquerda para a direita e armazenando em byteString
            for(var = index; var < (index + 8); ++var) {
                strncat(byteString, &stringInputInBinary[var], 1);
            }
            
            //Fazer operação XOR bit a bit entre stringValueToBinary e byteString
            //e converter resultado para decimal na variavel byteStringResultDecimal
            for(var = 0; var < 8; ++var) {
                valueIntDigitResult = (byteString[var] - '0') ^ (stringValueToBinary[var] - '0');
                byteStringResultDecimal += pow(2, 7 - var) * valueIntDigitResult;
            }
            
            //Converter byteStringbyteStringResultDecimal para decimal 
            //e concatenar com stringResultOfXor
            character = (char)byteStringResultDecimal;            
            strncat(stringResultOfXor, &character, 1);
        }
        
        //Mostrar resultado da string descriptada na tela
        printf("%s\n\n", stringResultOfXor);
    }
    
    return 0;
}
