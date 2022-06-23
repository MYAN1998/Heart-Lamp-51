#include<reg52.h>
#include<intrins.h>
unsigned char led[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
unsigned char led_one_by_one[8]={0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00};
unsigned char led_one_by_one_verse[8]={0x7f,0x3f,0x1f,0x0f,0x07,0x03,0x01,0x00};
/*全亮*/
void all(){
	P0=0X00;
	P1=0X00;
	P2=0X00;
	P3=0X00;
}
/*全灭*/
void empty(){
	P0=0Xff;
	P1=0Xff;
	P2=0Xff;
	P3=0Xff;
}

/*延时100毫秒*/
void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 5;
	j = 52;
	k = 195;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


/*延时20毫秒*/
void Delay20ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 1;
	j = 216;
	k = 35;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


/*全亮全灭三次闪烁*/
void flash(){
	int m=0;
	for (m=0;m<3;m++){
		all();
		/*延时100ms*/
		Delay100ms();	
		empty();
		Delay100ms();	
	}
}
/*从左向右闪烁*/
void left(){
	int m=0;
	for (m=0;m<=7;m++){
		P1=led[m];
		Delay20ms();	
	}
	P1=0xff;
	for (m=0;m<=7;m++){
		P3=led[m];
		Delay20ms();	
	}
	P3=0xff;
	for (m=0;m<=7;m++){
		P2=led[m];
		Delay20ms();	
	}
	P2=0xff;
	for (m=0;m<=7;m++){
		P0=led[7-m];
		Delay20ms();	
	}
	P0=0xff;
}
/*从右向左*/
void right(){
	int m=0;
	for (m=0;m<=7;m++){
		P0=led[m];
		Delay20ms();	
	}
	P0=0xff;
	for (m=0;m<=7;m++){
		P2=led[7-m];
		Delay20ms();	
	}
	P2=0xff;
	for (m=0;m<=7;m++){
		P3=led[7-m];
		Delay20ms();	
	}
	P3=0xff;
	for (m=0;m<=7;m++){
		P1=led[7-m];
		Delay20ms();	
	}
	P1=0xff;
}
/*从左至右,从右至左*/
void turn(){	
	left();
	right();
	empty();
}
/*依次亮,左至右*/
void one_by_one_left(){
	int m=0;
	for (m=0;m<=7;m++){
		P1=led_one_by_one[m];
		Delay20ms();	
	}
	for (m=0;m<=7;m++){
		P3=led_one_by_one[m];
		Delay20ms();	
	}
	for (m=0;m<=7;m++){
		P2=led_one_by_one[m];
		Delay20ms();	
	}
	for (m=0;m<=7;m++){
		P0=led_one_by_one_verse[m];
		Delay20ms();	
	}
}

/*依次亮,右至左*/
void one_by_one_right(){
	int m=0;
	for (m=0;m<=7;m++){
		P0=led_one_by_one[m];
		Delay20ms();	
	}
	for (m=0;m<=7;m++){
		P2=led_one_by_one_verse[m];
		Delay20ms();	
	}
	for (m=0;m<=7;m++){
		P3=led_one_by_one_verse[m];
		Delay20ms();	
	}
	for (m=0;m<=7;m++){
		P1=led_one_by_one_verse[m];
		Delay20ms();	
	}
}
/*依次亮*/
void one_by_one(){
		one_by_one_left();
		empty();
		one_by_one_right();
		empty();
}
void main()
{
	while (1){
		flash();
		turn();
		one_by_one();	
	}
}