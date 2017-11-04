#include <IRLibSendBase.h>
#include <IRLib_P01_NEC.h>
#include <IRLib_P02_Sony.h>
#include <IRLibCombo.h>

IRsend mySender;

int dipPins[] = {8, 7, 6, 5};

int irCode[2][2][2][2] = {
	{
		{
			{0xff1ae5, 0xff9a65},
			{0xffa25d, 0xff2ad5}
		},
		{
			{0xffaa55, 0xff926d},
			{0xff0af5, 0xff8a75}
		}
	},
	{
		{
			{0xffb24d, 0xff38c7},
			{0xffb847, 0xff7887}
		},
		{
			{0xff22dd, 0xff12ed},
			{0xff32cd, 0xfff807}
		}
	}
};

int a, b, c, d;
void setup() {
	// sets the digital pin 2-5 as input
	int i;
	for (i = 0; i <= 3; i++) {
		pinMode(dipPins[i], INPUT);
	}
	delay(100);

	a = digitalRead(dipPins[3]);
	b = digitalRead(dipPins[2]);
	c = digitalRead(dipPins[1]);
	d = digitalRead(dipPins[0]);

	delay(100);
}

void loop() {
	mySender.send(NEC, irCode[a][b][c][d], 24);
	delay(500);
}
