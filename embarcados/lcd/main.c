#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

// Define some device parameters
#define I2C_ADDR   0x27 // I2C device address

// Define some device constants
#define LCD_CHR  1 // Mode - Sending data
#define LCD_CMD  0 // Mode - Sending command

#define LINE1  0x80 // 1st line
#define LINE2  0xC0 // 2nd line

#define LCD_BACKLIGHT   0x08  // On
// LCD_BACKLIGHT = 0x00  # Off

#define ENABLE  0b00000100 // Enable bit

void lcd_init(void);
void lcd_byte(int bits, int mode);
void lcd_toggle_enable(int bits);

// added by Lewis
void lcdLoc(int line); //move cursor
void ClrLcd(void); // clr LCD return home
void typeln(const char *s);
void typeChar(char val);
int fd;  // seen by all subroutines

int main()   {

	if (wiringPiSetup () == -1) exit (1);

	fd = wiringPiI2CSetup(I2C_ADDR);

	//printf("fd = %d ", fd);

	lcd_init(); // setup LCD

	char array1[] = "Hello world!";

	printf("HELLO\n");
	while (1)   {

		lcdLoc(LINE1);
		typeln("Using wiringPi");
		delay(5000);


		printf("MESSAGE 2\n\n");
		lcdLoc(LINE2);
		typeln("Geany editor.");

		printf("-------> LOOP\n");
		break;

	}

	return 0;

}


// clr lcd go home loc 0x80
void ClrLcd(void)   {
	lcd_byte(0x01, LCD_CMD);
	lcd_byte(0x02, LCD_CMD);
}

// go to location on LCD
void lcdLoc(int line)   {
	lcd_byte(line, LCD_CMD);
}

// out char to LCD at current position
void typeChar(char val)   {

	lcd_byte(val, LCD_CHR);
}


// this allows use of any size string
void typeln(const char *s)   {
	while ( *s )
	{
		printf("ENTREI: (%c)\n", *s);
		lcd_byte(*(s++), LCD_CHR);
	}
}

void lcd_byte(int bits, int mode)   {

	//Send byte to data pins
	// bits = the data
	// mode = 1 for data, 0 for command
	int bits_high;
	int bits_low;
	// uses the two half byte writes to LCD
	bits_high = mode | (bits & 0xF0) | LCD_BACKLIGHT ;
	bits_low = mode | ((bits << 4) & 0xF0) | LCD_BACKLIGHT ;

	// High bits
	wiringPiI2CReadReg8(fd, bits_high);
	lcd_toggle_enable(bits_high);

	// Low bits
	wiringPiI2CReadReg8(fd, bits_low);
	lcd_toggle_enable(bits_low);
}

void lcd_toggle_enable(int bits)   {
	// Toggle enable pin on LCD display
	delayMicroseconds(500);
	wiringPiI2CReadReg8(fd, (bits | ENABLE));
	delayMicroseconds(500);
	wiringPiI2CReadReg8(fd, (bits & ~ENABLE));
	delayMicroseconds(500);
}


void lcd_init()   {
	// Initialise display
	lcd_byte(0x33, LCD_CMD); // Initialise
	lcd_byte(0x32, LCD_CMD); // Initialise
	lcd_byte(0x06, LCD_CMD); // Cursor move direction
	lcd_byte(0x0C, LCD_CMD); // 0x0F On, Blink Off
	lcd_byte(0x28, LCD_CMD); // Data length, number of lines, font size
	lcd_byte(0x01, LCD_CMD); // Clear display
	delayMicroseconds(500);
}
