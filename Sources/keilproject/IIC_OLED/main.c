#include "reg51.h"
#include "iic_oled.h"

#define u8 unsigned char 
#define u16 unsigned int
#define u32 unsigned long
	
void main(void)
{
  OLED_Init();//��ʼ��OLED
  OLED_Clear();//���� 
  while(1)
  {
		OLED_ShowChar(0, 0, 'a');
  };
}

