/*
* The MIT License (MIT)
* 
* Copyright (c) 2015 David Ogilvy (MetalPhreak)
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/


#include "driver/microwire_eeprom.h"

////////////////////////////////////////////////////////////////////////////////
//
// Function Name: func
//   Description: 
//    Parameters: 
//				 
////////////////////////////////////////////////////////////////////////////////

uint16 eeprom_BUSY(uint8 spi_no){
	if(spi_transaction(spi_no, 0, 0, 0, 0, 0, 0, 1, 0)){
		return 0;
	} else {
		return 1;
	}
}

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
// Function Name: func
//   Description: 
//    Parameters: 
//				 
////////////////////////////////////////////////////////////////////////////////

uint16 eeprom_READ(uint8 spi_no, uint8 size, uint8 org, uint16 addr){
	
	while(eeprom_BUSY(spi_no));

	if(org){
		return (uint16) spi_transaction(spi_no, 3, 0b110, 6+size, addr, 0, 0, 16, 0);
	} else {
		return (uint16) spi_transaction(spi_no, 3, 0b110, 7+size, addr, 0, 0, 8, 0);
	}
}

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
// Function Name: func
//   Description: 
//    Parameters: 
//				 
////////////////////////////////////////////////////////////////////////////////

void eeprom_WRITE(uint8 spi_no, uint8 size, uint8 org, uint16 addr, uint16 data){

	while(eeprom_BUSY(spi_no));

	if(org){
		spi_transaction(spi_no, 3, 0b101, 6+size, addr, 16, data, 0, 0);
	} else {
		spi_transaction(spi_no, 3, 0b101, 7+size, addr, 8, data, 0, 0);
	}
}

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
// Function Name: func
//   Description: 
//    Parameters: 
//				 
////////////////////////////////////////////////////////////////////////////////

void eeprom_ERASE(uint8 spi_no, uint8 size, uint8 org, uint16 addr){
	
	while(eeprom_BUSY(spi_no));

	if(org){
		spi_transaction(spi_no, 3, 0b111, 6+size, addr, 0, 0, 0, 0);
	} else {
		spi_transaction(spi_no, 3, 0b111, 7+size, addr, 0, 0, 0, 0);
	}
}

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
// Function Name: func
//   Description: 
//    Parameters: 
//				 
////////////////////////////////////////////////////////////////////////////////

void eeprom_WEN(uint8 spi_no, uint8 size, uint8 org){
	
	while(eeprom_BUSY(spi_no));

	if(org){
		spi_transaction(spi_no, 3, 0b100, 6+size, 3<<(4+size), 0, 0, 0, 0);
	} else {
		spi_transaction(spi_no, 3, 0b100, 7+size, 3<<(5+size), 0, 0, 0, 0);
	}
}

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
// Function Name: func
//   Description: 
//    Parameters: 
//				 
////////////////////////////////////////////////////////////////////////////////

void eeprom_WDS(uint8 spi_no, uint8 size, uint8 org){
	
	while(eeprom_BUSY(spi_no));

	if(org){
		spi_transaction(spi_no, 3, 0b100, 6+size, 0<<(4+size), 0, 0, 0, 0);
	} else {
		spi_transaction(spi_no, 3, 0b100, 7+size, 0<<(5+size), 0, 0, 0, 0);
	}
}

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
// Function Name: func
//   Description: 
//    Parameters: 
//				 
////////////////////////////////////////////////////////////////////////////////

void eeprom_ERAL(uint8 spi_no, uint8 size, uint8 org){
	
	while(eeprom_BUSY(spi_no));

	if(org){
		spi_transaction(spi_no, 3, 0b100, 6+size, 2<<(4+size), 0, 0, 0, 0);
	} else {
		spi_transaction(spi_no, 3, 0b100, 7+size, 2<<(5+size), 0, 0, 0, 0);
	}
}

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
// Function Name: func
//   Description: 
//    Parameters: 
//				 
////////////////////////////////////////////////////////////////////////////////

void eeprom_WRAL(uint8 spi_no, uint8 size, uint8 org, uint16 data){
	
	while(eeprom_BUSY(spi_no));

	if(org){
		spi_transaction(spi_no, 3, 0b100, 6+size, 1<<(4+size), 16, data, 0, 0);
	} else {
		spi_transaction(spi_no, 3, 0b100, 7+size, 1<<(5+size), 8, data, 0, 0);
	}
}

////////////////////////////////////////////////////////////////////////////////


/*///////////////////////////////////////////////////////////////////////////////
//
// Function Name: func
//   Description: 
//    Parameters: 
//				 
////////////////////////////////////////////////////////////////////////////////

void func(params){

}

///////////////////////////////////////////////////////////////////////////////*/


