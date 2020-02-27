#include <stdio.h>
#include <string.h>
#include <math.h>

void decimalToBinary(char *string, int number) {
    char temp[8] = "", digit;
    int ind;
    
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
    for(ind = 7; ind >= 0; --ind) {
        string[7 - ind] = temp[ind];
    }
}

int main()
{
    char stringInput[1024], stringInputInBinary[1024] = "";
    
    const char valuesInHexadecimalToBinary[16][5] = {"0000", "0001", "0010", "0011", 
                                                     "0100", "0101", "0110", "0111",
                                                     "1000", "1001", "1010", "1011", 
                                                     "1100", "1101", "1110", "1111"};
    
    int index;
    
    fgets(stringInput, 1024, stdin);
    
    /*converter entrada para a base binária*/
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
    
    //fazer combinação XOR com stringInputInBinary com todas as 256 possibilidades
    int value, aux;
    char c;
    
    for(value = 0; value <= 256; ++value) {
        
        printf("%d\n", value);
        
        char stringResultOfXor[1024] = "", stringValueToBinary[8] = "";
        //decimalToBinary(stringValueToBinary, value);
        
        int num = value;
        for (aux = 7; aux >= 0; aux--) {
            if (num % 2 == 0)
                stringValueToBinary[aux] = '0';
            else
                stringValueToBinary[aux] = '1';
            num = num / 2;
        }
        
        printf("%s\n", stringValueToBinary);
        
        for(index = 0; stringInputInBinary[index] != '\0'; index += 8){
            
            int decimal = 0, var = 0;
            char digitResult, byteString[8] = "";
            
            //pegando 8 bits da esquerda para a direita e armazenando em byteString
            for(var = index; var < (index + 8); ++var) {
                strncat(byteString, &stringInputInBinary[var], 1);
            }
            
            //Fazer operação XOR bit a bit entre string e byteString e armazenar resultado 
            for(var = 0; byteString[var] != '\0'; ++var) {
                digitResult = ((byteString[var] - '0') ^ (stringValueToBinary[var] - '0')) + '0';
                //strncat(stringResultOfXor, &digitResult, 1);
                decimal += pow(2, 7 - var) * (digitResult - '0');
            }
            
            c = (char)decimal;
            
            strncat(stringResultOfXor, &c, 1);
        }
        
        printf("%s\n\n", stringResultOfXor);
    }
    
    return 0;
}
