typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
typedef char s8;
typedef short int u16;

#define CS0 (1<<7)

extern void delay_ms(unsigned int);
extern void delay_sec(unsigned int);
extern void delay_us(unsigned int);

extern void uart0_init(u32);
extern void uart0_tx(u8);
extern u8 uart0_rx(void);
extern void uart0_tx_string(char *);
extern void uart0_rx_string(char *, int);
extern void uart0_tx_integer(s32);
extern void uart0_tx_float(float);
extern void uart0_hex(int);
extern void gsm_rx(u8 *, s32);

extern void spi0_init(void);
extern u8 spi0(u8);
extern u16 mcp3204_adc_read(u8);