#include <stdio.h>
#include <unistd.h>  //Used for UART
#include <fcntl.h>   //Used for UART
#include <termios.h> //Used for UART
#include<string.h>

#include<crc16.h>

int main()
{
	int uart0_filestream = -1;

	uart0_filestream = open("/dev/serial0", O_RDWR | O_NOCTTY | O_NDELAY); // Open in non blocking read/write mode
	if (uart0_filestream == -1)
		printf("Erro - Não foi possível iniciar a UART.\n");
	else
		printf("UART inicializada!\n");

	struct termios options;
	tcgetattr(uart0_filestream, &options);
	options.c_cflag = B115200 | CS8 | CLOCAL | CREAD;
	options.c_iflag = IGNPAR;
	options.c_oflag = 0;
	options.c_lflag = 0;

	tcflush(uart0_filestream, TCIFLUSH);
	tcsetattr(uart0_filestream, TCSANOW, &options);

	unsigned char tx_buffer[20];

	tx_buffer[0] = 0x01;
	tx_buffer[1] = 0x23;
	tx_buffer[2] = 0xA1;

	tx_buffer[3] = 3;
	tx_buffer[4] = 6;
	tx_buffer[5] = 2;
	tx_buffer[6] = 0;

	short int crc = calcula_CRC(tx_buffer, 7);
	memcpy( &tx_buffer[7], &crc, sizeof(short) );

	if (uart0_filestream != -1)
	{
		printf("Escrevendo caracteres na UART : ");
		int count = write(uart0_filestream, &tx_buffer, 9);
		if (count <= 0)
			printf("UART TX error\n");
		else
			printf("%d elementos escritos.\n", count);
	}

	sleep(2);

	if (uart0_filestream != -1)
	{
		unsigned char rx_buffer[256];

		int rx_length = read(uart0_filestream, (void *)rx_buffer, 255);

		if (rx_length < 0)
			printf("Erro na leitura.\n");

		else if (rx_length == 0)
			printf("Nenhum dado disponível.\n");

		else
		{
			rx_buffer[rx_length] = '\0';
			printf("%i Bytes lidos : %s\n", rx_length, rx_buffer);
		}
	}

	close(uart0_filestream);
	return 0;
}

