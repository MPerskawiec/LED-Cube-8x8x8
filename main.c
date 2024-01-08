#include <avr/io.h>

#include <stdlib.h>
#include <avr/interrupt.h>

#include "I2C_TWI/i2c_twi.h"
#include "funkcje.h"


#define I2C_KHZ 350		// ustalamy pr�dko�� na magistrali I2C od 50 kHz do 400 kHz (standard to 100 kHz)

int main(void)
{

	i2cSetBitrate(I2C_KHZ);

	DDRA = 0xFF; // Ustawienie portu A jako wyj�cia ( wsp�lne minus LED�W)
	PA = 0x00;

	napis();		// Wy�wietlanie napisu
	while(1){

    dol_gora();
    dol_gora();
    dol_gora_pelne();
    gora_dol_pelne();
    dol_gora_pelne();
    prawo_pelne();
    lewo_pelne();

	prawo_tyl();
	kolo();
//	tyl_gora();
//	DM(500);

	for(int i = 0; i<2 ; i++){
		d_glt();
		t_plg();
		l_pgp();
		g_dpp();
		p_tdp();
		p_ldp();
	}

		od_srodka();
		od_srodka();
		od_srodka();



	} // koniec p�tli while


} // Koniec pentli g��wnej



