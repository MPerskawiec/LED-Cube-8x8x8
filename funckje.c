#include <avr/io.h>

#include <stdlib.h>
#include <avr/interrupt.h>

#include "funkcje.h"
#include "I2C_TWI/i2c_twi.h"

uint8_t tab[8] ={U1, U2, U3, U4, U5, U6, U7, U8};
void zapal_w(){		// funkcja za³¹cza wszystkie anody od diód
	TW( U1, 0x00);
	TW( U2, 0x00);
	TW( U3, 0x00);
	TW( U4, 0x00);
	TW( U5, 0x00);
	TW( U6, 0x00);
	TW( U7, 0x00);
	TW( U8, 0x00);
}

void zgas(){		// funkcja wy³¹cza wszystkie anody diód
	TW( U1, 0xFF);
	TW( U2, 0xFF);
	TW( U3, 0xFF);
	TW( U4, 0xFF);
	TW( U5, 0xFF);
	TW( U6, 0xFF);
	TW( U7, 0xFF);
	TW( U8, 0xFF);
}

void zapal(uint8_t a1,uint8_t a2,uint8_t a3,uint8_t a4,uint8_t a5,uint8_t a6,uint8_t a7,uint8_t a8){
// jedna funkcja do wyboru stanu na wszystkich anodach
	TW( U1, a1);
	TW( U2, a2);
	TW( U3, a3);
	TW( U4, a4);
	TW( U5, a5);
	TW( U6, a6);
	TW( U7, a7);
	TW( U8, a8);

}

void dol_gora(){

	zapal_w();

	for(uint8_t i = 128; i > 0; i = (i>>1)){   // ca³y poziom idzie w gore od dolu
		PA = i;
		DM(100);
	}

	for(uint8_t i = 2; i < 128; i = (i<<1)){   // ca³y poziom idzie z gory na
		PA = i;
		DM(100);
	}

}

void dol_gora_pelne(){   // od do³u do³¹czaj¹ siê kolejne poziomy

	zapal_w();

	PA = 0x80;
	DM(100);
	PA = 0xC0;
	DM(100);
	PA = 0xE0;
	DM(100);
	PA = 0xF0;
	DM(100);
	PA = 0xF8;
	DM(100);
	PA = 0xFC;
	DM(100);
	PA = 0xFE;
	DM(100);
	PA = 0xFF;
	DM(100);
}

void gora_dol_pelne(){   // od gory do dolu dolaczaja sie kolejen poziomy

	zapal_w();
	PA = 0xFF;
	DM(100);
	PA = 0xFE;
	DM(100);
	PA = 0xFC;
	DM(100);
	PA = 0xF8;
	DM(100);
	PA = 0xF0;
	DM(100);
	PA = 0xE0;
	DM(100);
	PA = 0xC0;
	DM(100);
	PA = 0x80;
	DM(100);

}

void lewo_pelne(){

	zgas();

	PA = 0xFF;

	TW( U8, 0x00);
	DM(100);
	TW( U7, 0x00);
	DM(100);
	TW( U6, 0x00);
	DM(100);
	TW( U5, 0x00);
	DM(100);
	TW( U4, 0x00);
	DM(100);
	TW( U3, 0x00);
	DM(100);
	TW( U2, 0x00);
	DM(100);
	TW( U1, 0x00);
	DM(100);


}

void prawo_pelne(){
	PA = 0xFF;
	zapal_w();

	DM(100);
	TW( U1, 0xFF);
	DM(100);
	TW( U2, 0xFF);
	DM(100);
	TW( U3, 0xFF);
	DM(100);
	TW( U4, 0xFF);
	DM(100);
	TW( U5, 0xFF);
	DM(100);
	TW( U6, 0xFF);
	DM(100);
	TW( U7, 0xFF);
	DM(100);

}

void prawo_tyl(){
	PA = 0xFF;
	zgas();

	int czas = 80;

	TW( U1, 0x00);
	DM(czas);

	TW( U1, 0xF0);
	TW( U2, 0x0F);
	DM(czas);

	TW( U1, 0xFC);
	TW( U2, 0xE3);
	TW( U3, 0x9f);
	DM(czas);

	TW( U1, 0xFE);
	TW( U2, 0xF9);
	TW( U3, 0xE7);
	TW( U4, 0x9F);
	DM(czas);

	TW( U1, 0xFE);
	TW( U2, 0xFD);
	TW( U3, 0xFB);
	TW( U4, 0xF7);
	TW( U5, 0xCF);
	DM(czas);

	TW( U1, 0xFE);
	TW( U2, 0xFD);
	TW( U3, 0xFB);
	TW( U4, 0xFB);
	TW( U5, 0xF7);
	TW( U6, 0xEF);
	DM(czas);

	TW( U1, 0xFE);
	TW( U2, 0xFE);
	TW( U3, 0xFD);
	TW( U4, 0xFD);
	TW( U5, 0xFB);
	TW( U6, 0xFB);
	TW( U7, 0xF7);
	DM(czas);

	TW( U3, 0xFE);
	TW( U4, 0xFE);
	TW( U5, 0xFD);
	TW( U6, 0xFD);
	TW( U7, 0xFD);
	TW( U8, 0xFD);
	DM(czas);

	TW( U5, 0xFE);
	TW( U6, 0xFE);
	TW( U7, 0xFE);
	TW( U8, 0xFE);
	DM(czas);
}

void tyl_gora(){

	int czas = 800;

	PA = 0xFF;

	TW( U1, 0xFE);
	DM(czas);

	for(int i = 0; i<czas/2;i++){
	PA = 0x0F;
	TW( U1, 0xFE);
	DM(1);
	PA = 0xF0;
	TW( U1, 0xFD);
	DM(1);
	}

	for(int i = 0; i<czas/3;i++){
	PA = 0x03;
	TW( U1, 0xFE);
	DM(1);
	PA = 0x0c;
	TW( U1, 0xFD);
	DM(1);
	PA = 0x70;
	TW( U1, 0xFB);
	DM(1);
	}



}



void d_glt(){

	int czas = CZAS_PRZESOWANIA_SCIAN;

	for(uint8_t i = 128; i > 0; i = (i>>1)){

		for(int j =0; j<czas/2; j++){
		PA = i;
		zapal_w();
		DM(1);


		zgas();
		PA = 0xff;

		zapal(0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0x00);
		DM(1);
		}

	}

}


void t_plg(){

	int czas = CZAS_PRZESOWANIA_SCIAN;
	int a = 0;
	for(uint8_t i = 1; a < 8 ; i = (i<<1)){
		a++;
	for(int j =0; j<czas/3; j++){
	PA = 0x01;
	zapal_w();
	DM(1);


	zgas();
	PA = 0xff;
	TW( U8, 0x00);

	DM(1);

	PA = 0xFF;
	zgas();
	zapal(~i,~i,~i,~i,~i,~i,~i,~i);

	DM(1);
	}

	}
}

void l_pgp(){
	int czas = CZAS_PRZESOWANIA_SCIAN;

	for(uint8_t i = 0; i < 8 ; i ++){


	for(int j =0; j<czas/3; j++){
	PA = 0x01;
	zapal_w();
	DM(1);

	zgas();
	PA = 0xFF;
	zapal(0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F);
	DM(1);


	zgas();
	PA = 0xff;
	TW( tab[7-i], 0x00);

	DM(1);

	}

	}
}

void g_dpp(){


		int czas = CZAS_PRZESOWANIA_SCIAN;
		int a = 0;
		for(uint8_t i = 1; a < 8; i = (i<<1)){
			a++;
			for(int j =0; j<czas/2; j++){
			PA = i;
			zapal_w();
			DM(1);


			zgas();
			PA = 0xff;

			zapal(0x00,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F);
			DM(1);
			}

		}

	}


void p_tdp(){

	int czas = CZAS_PRZESOWANIA_SCIAN;
	int a = 0;
	for(uint8_t i = 128; a < 8 ; i = (i>>1)){
		a++;
	for(int j =0; j<czas/3; j++){
	PA = 0x80;
	zapal_w();
	DM(1);


	zgas();
	PA = 0xff;
	TW( U1, 0x00);

	DM(1);

	PA = 0xFF;
	zgas();
	zapal(~i,~i,~i,~i,~i,~i,~i,~i);

	DM(1);
	}

	}
}



void p_ldp(){

	int czas = CZAS_PRZESOWANIA_SCIAN;

	for(uint8_t i = 0; i < 8 ; i ++){


	for(int j =0; j<czas/3; j++){
	PA = 0x80;
	zapal_w();
	DM(1);

	zgas();
	PA = 0xFF;
	zapal(0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE);
	DM(1);


	zgas();
	PA = 0xff;
	TW( tab[i], 0x00);

	DM(1);

	}

	}

}


void od_srodka(){
	int czas = 100;
	zgas();
	DM(czas);

	PA = 0x18;
	TW( U4, 0xE7);
	TW( U5, 0xE7);
	DM(czas);

	PA = 0x3C;
	TW( U3, 0xC3);
	TW( U4, 0xC3);
	TW( U5, 0xC3);
	TW( U6, 0xC3);
	DM(czas);

	PA = 0x7E;
	zapal(0xFF,0x81,0x81,0x81,0x81,0x81,0x81,0xFF);
	DM(czas);

	PA = 0xFF;
	zapal_w();
	DM(czas);

	PA = 0x7E;
	zapal(0xFF,0x81,0x81,0x81,0x81,0x81,0x81,0xFF);
	DM(czas);

	zgas();
	PA = 0x3C;
	TW( U3, 0xC3);
	TW( U4, 0xC3);
	TW( U5, 0xC3);
	TW( U6, 0xC3);
	DM(czas);

	zgas();
	PA = 0x18;
	TW( U4, 0xE7);
	TW( U5, 0xE7);
	DM(czas);

}

void kolo(){
	int a = 0;


	zgas();
	PA = 0xff;

	int czas = 40;


	for(uint8_t i = 128; a < 8 ; i = (i>>1)){
		a++;
		TW( U1, ~i);
		DM(czas);

	}


	for(uint8_t i = 1; i < 8 ; i ++){
		zgas();
		TW( tab[i], 0xFE);
		DM(czas);
	}

	a = 0;
	for(uint8_t i = 2; a < 7 ; i = (i<<1)){
		a++;
		TW( U8, ~i);
		DM(czas);

	}

	for(uint8_t i = 1; i < 7 ; i ++){
		zgas();
		TW( tab[7-i], 0x7F);
		DM(czas);
	}





	zgas();
	a=0;
	czas = 30;

	for(uint8_t i = 128; a < 8 ; i = (i>>1)){
		a++;
		TW( U1, ~i);
		DM(czas);

	}


	for(uint8_t i = 1; i < 8 ; i ++){
		zgas();
		TW( tab[i], 0xFE);
		DM(czas);
	}

	a = 0;
	for(uint8_t i = 2; a < 7 ; i = (i<<1)){
		a++;
		TW( U8, ~i);
		DM(czas);

	}

	for(uint8_t i = 1; i < 7 ; i ++){
		zgas();
		TW( tab[7-i], 0x7F);
		DM(czas);
	}


	zgas();
	a=0;
	czas = 20;

	for(uint8_t i = 128; a < 8 ; i = (i>>1)){
		a++;
		TW( U1, ~i);
		DM(czas);

	}


	for(uint8_t i = 1; i < 8 ; i ++){
		zgas();
		TW( tab[i], 0xFE);
		DM(czas);
	}

	a = 0;
	for(uint8_t i = 2; a < 7 ; i = (i<<1)){
		a++;
		TW( U8, ~i);
		DM(czas);

	}

	for(uint8_t i = 1; i < 7 ; i ++){
		zgas();
		TW( tab[7-i], 0x7F);
		DM(czas);
	}


	zgas();
	a=0;
	czas = 10;

	for(uint8_t i = 128; a < 8 ; i = (i>>1)){
		a++;
		TW( U1, ~i);
		DM(czas);

	}


	for(uint8_t i = 1; i < 8 ; i ++){
		zgas();
		TW( tab[i], 0xFE);
		DM(czas);
	}

	a = 0;
	for(uint8_t i = 2; a < 7 ; i = (i<<1)){
		a++;
		TW( U8, ~i);
		DM(czas);

	}

	for(uint8_t i = 1; i < 7 ; i ++){
		zgas();
		TW( tab[7-i], 0x7F);
		DM(czas);
	}


	for(int c = 0; c<4; c++){
	zgas();
	a=0;
	czas = 7;

	for(uint8_t i = 128; a < 8 ; i = (i>>1)){
		a++;
		TW( U1, ~i);
		DM(czas);

	}


	for(uint8_t i = 1; i < 8 ; i ++){
		zgas();
		TW( tab[i], 0xFE);
		DM(czas);
	}

	a = 0;
	for(uint8_t i = 2; a < 7 ; i = (i<<1)){
		a++;
		TW( U8, ~i);
		DM(czas);

	}

	for(uint8_t i = 1; i < 7 ; i ++){
		zgas();
		TW( tab[7-i], 0x7F);
		DM(czas);
	}
	}

}

void napis(){

	int czas=30;

	zgas();
	for(uint8_t i = 128; i > 0; i = (i>>1)){
		PA = i;
		zapal(0x99,0x99,0x99,0x81,0x81,0x99,0x99,0x99);
		DM(czas);
	}

	DM(czas*7);
	zgas();

	for(uint8_t i = 128; i > 0; i = (i>>1)){
		PA = i;
		zapal(0x81,0x81,0x9F,0x81,0x81,0x9F,0x81,0x81);
		DM(czas);
	}

	DM(czas*7);
	zgas();

	for(uint8_t i = 128; i > 0; i = (i>>1)){
		PA = i;
		zapal(0x81,0x81,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F);
		DM(czas);
	}

	DM(czas*7);
	zgas();

	for(uint8_t i = 128; i > 0; i = (i>>1)){
		PA = i;
		zapal(0x81,0x81,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F);
		DM(czas);
	}

	DM(czas*7);
	zgas();

	for(uint8_t i = 128; i > 0; i = (i>>1)){
		PA = i;
		zapal(0xE7,0xC3,0x99,0x99,0x99,0x99,0xC3,0xE7);
		DM(czas);
	}
	DM(czas*7);
	zgas();

}
