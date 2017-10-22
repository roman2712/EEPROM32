#ifndef EEPROM_32
#define EEPROM_32

#include <EEPROM.h>

void EEPROM_write(uint8_t address, byte size_data, size_t data)
{
  for (byte i = 0; i < size_data; ++i)
  {
    EEPROM.write(address + i, data % 256);
    data /= 256;
  }
}

size_t EEPROM_read(uint8_t address,  byte size_data)
{
  size_t data = 0;
  for (byte i = size_data - 1; i > 0; --i)
  {
    data = EEPROM.read(address + i);
    data *= 256;
  }
  data += EEPROM.read(address);
  return data;
}

void EEPROM_write_8(uint8_t address,size_t data)
{
  EEPROM_write(address,1, data);
}

int8_t EEPROM_read_8(uint8_t address)
{
  return EEPROM_read(address,1);
}

void EEPROM_write_16(uint8_t address,size_t data)
{
  EEPROM_write(address,2, data);
}

size_t EEPROM_read_16(uint8_t address)
{
  return EEPROM_read(address,2);
}

void EEPROM_write_32(uint8_t address,size_t data)
{
  EEPROM_write(address,4, data);
}

size_t EEPROM_read_32(uint8_t address)
{
  return EEPROM_read(address,4);
}

#endif 
