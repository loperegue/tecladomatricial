#include "MKL25Z4.h"
#include "tecladomatricial.h"
#include "stdio.h"

#define passlong 5
char contrasenia[ passlong ];
char contrasenia_actual[ passlong ];

int main() {
    teclado_init();
    while(1){
        char key = teclado_key();
        if(key == "#"){
            printf("\n cambiar contraseña");
            for(int i=0; i< passlong ; i++){
                while(teclado_key() == "n"){
                    delay(4);
                }
                contrasenia[i] = teclado_key();
                printf("*");
                while(teclado_key() != "n"){
                    delay(1);
                }
            }
            printf("\n contraseña actualizada");
        }
        if(key != "#" && key != "n"){
            for(int i=0; i< passlong ; i++){
                while(teclado_key() == "n"){
                    delay(4);
                }
                contrasenia_actual[i] = teclado_key();
                printf(contrasenia_actual[i]);
                while(teclado_key() != "n"){
                    delay(1);
                }
            }
            for(int i=0; i< passlong ; i++){
                if(contrasenia[i] == contrasenia_actual[i]){
                }else{
                    i = 99;
                    printf("\n contraseña incorrecta");
                }
                if(i == passlong - 1){
                    printf("\n contraseña correcta");
                }
            }
        }
    }
}