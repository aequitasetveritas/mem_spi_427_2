#ifndef spi_H
#define spi_H
#include <stdint.h>
#include <msp430fe427a.h>



#define MEM_CS BIT2 		// mem_negCS -> Latch(Q3) -> P1.2
#define LATCH_LE BIT0 		// Latch (LE) -> P2.0
#define NRF_CS BIT1			// nrf_negCS -> Latch(Q2) -> P1.1

void spi_inicializacion();
uint8_t spi_transferir(uint8_t dato); 						//Transmite un byte, devuelve el byte recibido.
uint8_t spi_transferir_multi(uint8_t * datos, uint8_t n); 	//Transmite un buffer de n datos y devuelve el ultimo byte recibido
uint8_t spi_recibir_multi(uint8_t * datos, uint8_t n);      //Transmite 0xFF's y llena el buffer "datos" con los n datos recibidos

inline void latch_habilitar_LE();									//Latch Enable
inline void latch_deshabilitar_LE();

inline void mem_habilitar_CS();								//Chip Select para la memoria
inline void mem_deshabilitar_CS();

#endif // spi_H
