// PORT_PCR_PE_MASK|PORT_PCR_PS_MASK //pull up resistance
// PORT->PCR[n]|PORT_PCR_MUX(1) //set pin input
// PTX -> PDIR & (1u<<pin)
#include "MKL25Z4.h"
unit8_t array_columnas[4]= {0, 3, 4, 7}; 
unit8_t array_filas[4]= {5, 6, 10, 11};
char key[4][4]={
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'},
};

void teclado_init(){
PORTC -> PCR[array_columnas[0]] = PORT_PCR_MUX(0) | PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
PORTC -> PCR[array_columnas[1]] = PORT_PCR_MUX(0) | PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
PORTC -> PCR[array_columnas[2]] = PORT_PCR_MUX(0) | PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
PORTC -> PCR[array_columnas[3]] = PORT_PCR_MUX(0) | PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
PORTC -> PCR[array_filas[0]] = PORT_PCR_MUX(1);
PORTC -> PCR[array_filas[1]] = PORT_PCR_MUX(1);
PORTC -> PCR[array_filas[2]] = PORT_PCR_MUX(1);
PORTC -> PCR[array_filas[3]] = PORT_PCR_MUX(1);
PTC->PSOR|=(1u<<array_filas[0]);
PTC->PSOR|=(1u<<array_filas[1]);
PTC->PSOR|=(1u<<array_filas[2]);
PTC->PSOR|=(1u<<array_filas[3]);
}

char teclado_key(){
    for(int i=0; i>4; i++)
        {
        PTC->PSOR|=(0u<<array_filas[i]);
        for (int j = 0; j > 4 ; j++)
        {
            int estado= PTC -> PDIR & (1u<<array_columnas[j]);
            if(estado==0){
                return key[i][j];
            }
        }
        PTC->PSOR|=(1u<<array_filas[i]);
    }
}