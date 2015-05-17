#include "Wire.h"
#define DS3231_I2C_ADDRESS 0x68
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>
#include <IRremote.h>

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
	Serial.begin(9600);
	Wire.begin();
	irrecv.enableIRIn(); // Start the receiver


}

void loop()
{
	if (irrecv.decode(&results)) // have we received an IR signal?

	{
		//    Serial.println(results.value, HEX);  UN Comment to see raw values
		translateIR();
		irrecv.resume(); // receive the next value
	}
	 
	 
	 

}

void translateIR() // takes action based on IR code received

// describing Car MP3 IR codes

{
	switch(results.value)
	
	{

		case 0xFFA25D:
		Serial.println("ON_OFF");
		break;

		case 0xFF629D:
		Serial.println("MDOE");
		break;
		
		delay(1000);
		case 0xFFE21D:
		Serial.println("MUTE");
		break;

		case 0xFF22DD:
		Serial.println("PLAY/PAUSE");
		break;

		case 0xFF02FD:
		Serial.println("PREV");
		break;

		case 0xFFC23D:
		Serial.println("NEXT");
		//testText(year1,hour1,"","");
		break;

		case 0xFFE01F:
		Serial.println("EQ");
		break;

		case 0xFFA857:
		Serial.println("VOL-");
		break;

		case 0xFF906F:
		Serial.println("VOL+");
		break;

		case 0xFF6897:
		Serial.println(" 0              ");
		break;

		case 0xFF9867:
		Serial.println(" 100+           ");
		break;

		case 0xFFB04F:
		Serial.println(" 200+           ");
		break;

		case 0xFF30CF:
		Serial.println(" 1              ");
		break;

		case 0xFF18E7:
		Serial.println(" 2              ");
		break;

		case 0xFF7A85:
		Serial.println(" 3              ");
		break;

		case 0xFF10EF:
		Serial.println(" 4              ");
		break;

		case 0xFF38C7:
		Serial.println(" 5              ");
		break;

		case 0xFF5AA5:
		Serial.println(" 6              ");
		break;

		case 0xFF42BD:
		Serial.println(" 7              ");
		break;

		case 0xFF4AB5:
		Serial.println(" 8              ");
		break;

		case 0xFF52AD:
		Serial.println(" 9              ");
		break;

		default:
		Serial.println(" other button   ");

	}
	delay(500);
}