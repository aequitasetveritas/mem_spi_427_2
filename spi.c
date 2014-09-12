#include "spi.h"

void spi_inicializacion(){
	U0CTL |= CHAR + SYNC + MM + SWRST; 	//8-bit SPI Master
	U0TCTL |= CKPL | SSEL1 | STC; 		//Inactive Alto, SMCLK, 3pin
	U0BR1 = 0x00;
	U0BR0 = 0x02;						//SMCLK/2
	U0MCTL = 0x00; 						//0 para SPI
	P1SEL |= BIT6 | BIT7;
	P2SEL |= BIT1; 						//Funcion secundaria para los pines spi.
	ME1 |= USPIE0; 						//Habilitar el módulo.
	U0CTL &= ~SWRST;
	ME1 |= USPIE0;
	U0CTL &= ~SWRST;
}

uint8_t spi_transferir(uint8_t dato){
	while(!(IFG1 & UTXIFG0));
	U0TXBUF = dato;
	while(!(IFG1 & URXIFG0));
	uint8_t recibido = U0RXBUF;
	return recibido;
}

uint8_t spi_transferir_multi(uint8_t * datos, uint8_t n){
	uint8_t i;
	uint8_t recibido = 0;

	for(i=0;i<n;i++){
		while(!(IFG1 & UTXIFG0));
		U0TXBUF = datos[i];
		while(!(IFG1 & URXIFG0));
		recibido = U0RXBUF;
	}

	return recibido;
}

uint8_t spi_recibir_multi(uint8_t * datos, uint8_t n){
	uint8_t i;

	for(i=0;i<n;i++){
		while(!(IFG1 & UTXIFG0));
		U0TXBUF = 0xFF;
		while(!(IFG1 & URXIFG0));
		datos[0] = U0RXBUF;
	}

	return datos[i];
}

inline void latch_habilitar_LE(){
	P2OUT |= LATCH_LE;
}
inline void latch_deshabilitar_LE(){
	P2OUT &= ~LATCH_LE;
}

inline void mem_habilitar_CS(){
	P1OUT &= ~MEM_CS;
	latch_habilitar_LE();
	latch_deshabilitar_LE();
}

inline void mem_deshabilitar_CS(){
	P1OUT |= MEM_CS;
	latch_habilitar_LE();
	latch_deshabilitar_LE();
}
