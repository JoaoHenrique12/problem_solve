import termios
import os
from time import sleep
import crc16  # You may need to install this library: pip install crc16

def calculate_crc(data):
    crc = crc16.crc16xmodem(data)
    return crc.to_bytes(2, byteorder='big')

def main():
    uarto_filestream = os.open(
        "/dev/serial0", os.O_RDWR | os.O_NOCTTY | os.O_NDELAY)

    [iflag, oflag, cflag, lflag] = [0, 1, 2, 3]

    attrs: termios._Attr = termios.tcgetattr(uarto_filestream)

    attrs[cflag] = termios.B115200 | termios.CS8 | termios.CLOCAL | termios.CREAD
    attrs[iflag] = termios.IGNPAR
    attrs[oflag] = 0
    attrs[lflag] = 0

    termios.tcflush(uarto_filestream, termios.TCIFLUSH)
    termios.tcsetattr(uarto_filestream, termios.TCSANOW, attrs)

    envia = b"\x01\x23\xA1"
    crc = calculate_crc(envia)

    # Append CRC to the message
    message = envia + crc

    print(f"Escreveu {envia} ({len(message)} bytes) com CRC: <{crc}>")
    os.write(uarto_filestream, message)

    sleep(1)

    received_data = os.read(uarto_filestream, 255)

    # Separate the received data and CRC
    received_message = received_data[:-2]
    received_crc = received_data[-2:]
    print(received_crc)

    # Verify CRC
    if calculate_crc(received_message) == received_crc:
        print(f"Leu {len(received_message)} bytes com CRC válido")
        print(f"Bytes da leitura: {received_message}")
    else:
        print("Erro: CRC inválido")

    os.close(uarto_filestream)

main()

