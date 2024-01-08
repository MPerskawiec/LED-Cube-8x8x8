#ifndef FUNKCJE_H_
#define FUNKCJE_H_

#define U1 0x40
#define U2 0x48
#define U3 0x42
#define U4 0x4A
#define U5 0x44
#define U6 0x4C
#define U7 0x46
#define U8 0x4E

#define PA PORTA
#define DM _delay_ms
#define TW TWI_write_int
#define CZAS_PRZESOWANIA_SCIAN 50

void zapal_w();
void zgas();
void zapal(uint8_t a1,uint8_t a2,uint8_t a3,uint8_t a4,uint8_t a5,uint8_t a6,uint8_t a7,uint8_t a8);

void dol_gora();
void dol_gora_pelne();
void gora_dol_pelne();
void lewo_pelne();
void prawo_pelne();
void prawo_tyl();
void tyl_gora();
void d_glt();
void t_plg();
void l_pgp();
void g_dpp();
void p_tdp();
void p_ldp();
void od_srodka();

void kolo();
void napis();


#endif /* FUNKCJE_H_ */
