#ifndef ILI9481_HPP
#define ILI9481_HPP

#include <hwlib.hpp>

//These define the ports and port bits used for the write, chip select (CS) and data/command (RS) lines


// Set WR low
	#define WR_L pinWR.write(0); pinWR.flush();

// Set WR high
	#define WR_H pinWR.write(0); pinWR.flush(); pinWR.write(1); pinWR.flush();

// Long write strobe, hold low for two periods then high
// Use in tight loops to avoid too narrow low pulses
	#define WR_STB pinWR.write(0);  pinWR.flush(); pinWR.write(0);  pinWR.flush(); pinWR.write(0); pinWR.flush(); pinWR.write(1); pinWR.flush();

// Short write strobe, hold low for one period then high
// Use where write is already set low during data setup
	#define WR_SB  pinWR.write(0); pinWR.flush(); pinWR.write(0); pinWR.flush(); pinWR.write(1); pinWR.flush();

// Chip select must be toggled during setup so these are a special case
	#define SETUP_CS_H pinCS.write(1); pinCS.flush();
	#define SETUP_CS_L pinCS.write(0); pinCS.flush();

// Chip select can optionally be kept low after setup
	#define CS_H pinCS.write(1); pinCS.flush();// CS high!
	#define CS_L pinCS.write(0); pinCS.flush();// CS Low

// Change RS line state
	#define RS_L pinRS.write(0); pinRS.flush();
	#define RS_H pinRS.write(1); pinRS.flush();

//	TFT			Due
//	D15			D29
//	D14			D28
//	D13			D27
//	D12			D26
//	D11			D25
//	D10			D24
//	D9			D23
//	D8			D22
//
//	D7			D30
//	D6			D31
//	D5			D32
//	D4			D33
//	D3			D34
//	D2			D35
//	D1			D36
//	D0			D37
//		
//	RS			D38
//	WR			D39
//	CS			D40
//	RST			D41

//
//
//	TFT	Mega	Due
//	D15	PA7	D.6
//	D14	PA6	D.3
//	D13	PA5	D.2
//	D12	PA4	D.1
//	D11	PA3	D.0
//	D10	PA2	A.15
//	D9	PA1	A.14
//	D8	PA0	B.26
//
//	D7	PC7	D.9
//	D6	PC6	A.7
//	D5	PC5	D.10
//	D4	PC4	C.1
//	D3	PC3	C.2 ,
//	D2	PC2	C.3
//	D1	PC1	C.4 ,
//	D0	PC0	C.5 ,
//		
//	RS	PD7	C.6
//	WR	PG2	C.7
//	CS	PG1	C.8
//	RST	PG0	C.9

/// @file
/// \brief
/// ILI9481 class
/// \details
/// This display is used to write anything to the display

class ILI9481{
private:
	int w;
	int h;
	int width =w;
	int height =h;
	hwlib::target::pin_out & pinoutD15;
	hwlib::target::pin_out & pinoutD14;
	hwlib::target::pin_out & pinoutD13;
	hwlib::target::pin_out & pinoutD12;
	hwlib::target::pin_out & pinoutD11;
	hwlib::target::pin_out & pinoutD10;
	hwlib::target::pin_out & pinoutD9;
	hwlib::target::pin_out & pinoutD8;
	hwlib::target::pin_out & pinoutD7;
	hwlib::target::pin_out & pinoutD6;
	hwlib::target::pin_out & pinoutD5;
	hwlib::target::pin_out & pinoutD4;
	hwlib::target::pin_out & pinoutD3;
	hwlib::target::pin_out & pinoutD2;
	hwlib::target::pin_out & pinoutD1;
	hwlib::target::pin_out & pinoutD0;
	hwlib::target::pin_out & pinRS;
	hwlib::target::pin_out & pinWR;
	hwlib::target::pin_out & pinCS;
	hwlib::target::pin_out & pinRST;
	
	
	hwlib::port_out_from_pins_t port_all_bits = hwlib::port_out_from( pinoutD15, pinoutD14, pinoutD13, pinoutD12, pinoutD11, pinoutD10, pinoutD9, pinoutD8, pinoutD7, pinoutD6, pinoutD5, pinoutD4, pinoutD3, pinoutD2, pinoutD1, pinoutD0);
	hwlib::port_out_from_pins_t D0_D7_bits = hwlib::port_out_from(pinoutD7, pinoutD6, pinoutD5, pinoutD4, pinoutD3, pinoutD2, pinoutD1, pinoutD0);
	hwlib::port_out_from_pins_t D8_D15_bits = hwlib::port_out_from(pinoutD15, pinoutD14, pinoutD13, pinoutD12, pinoutD11, pinoutD10, pinoutD9, pinoutD8);
	int pixelfg  = 0xFFFF;
	uint32_t fgA;
	uint32_t fgB;
	uint32_t fgC;
	uint32_t fgD;
	
public:
	/// \brief
	/// ILI9481 constructor 
	/// \details
	/// Needs width hight and all pins
	ILI9481(int w,int h,hwlib::target::pin_out & pinoutD15, hwlib::target::pin_out & pinoutD14, hwlib::target::pin_out & pinoutD13, hwlib::target::pin_out & pinoutD12, hwlib::target::pin_out & pinoutD11, hwlib::target::pin_out & pinoutD10, hwlib::target::pin_out & pinoutD9, hwlib::target::pin_out & pinoutD8, hwlib::target::pin_out & pinoutD7, hwlib::target::pin_out & pinoutD6, hwlib::target::pin_out & pinoutD5, hwlib::target::pin_out & pinoutD4, hwlib::target::pin_out & pinoutD3, hwlib::target::pin_out & pinoutD2 ,hwlib::target::pin_out & pinoutD1, hwlib::target::pin_out & pinoutD0, hwlib::target::pin_out & pinRS, hwlib::target::pin_out & pinWR, hwlib::target::pin_out & pinCS, hwlib::target::pin_out & pinRST);
	/// \brief
	/// init initializes the chip
	/// \details
	/// Init setups all of the pins and the chip so it uses the right volt inputs and pins.
	void init();
	/// \brief
	/// writecommad writes a command to chip
	/// \details
	/// Write command writes a command to the chip to setup the chip. 
	/// The write data after it are the parameters.
	void writecommand(uint8_t c);
	/// \brief
	/// writedata writes data to chip
	/// \details
	/// Writedata writes 8 bit data to chip. This can not  be a parameter for the previous used command.
	void writedata(uint8_t c);
	/// \brief
	/// writed16 writes data to chip
	/// \details
	/// Write16 writes 16 bit data to chip. 
	/// This can be a parameter for the previous used command. That needs to be 8 bit
	/// It is not used to write positions to the chip or colors
	void write16(uint16_t word);
	/// \brief
	/// fillrect makes a rectangle
	/// \details
	/// fillrect makes a rectangle and uses setaddrwindow and fghcolor to do so.
	void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
	/// \brief
	///  setwindow Defines an area
	/// \details 
	/// same as setAddrwindow defines an area to receive a stream of pixels.
	/// it also sets cs high afterwards to flush it
	/// its faster then a drawpixel loop
	void setWindow(int16_t x0, int16_t y0, int16_t x1, int16_t y1);
	/// \brief
	///  setAddrwindow Defines an area
	/// \details 
	/// setwindow defines an area to receive a stream of pixels.
	/// it does not set cs high afterwards to flush it
	/// mostly used as a private function
	void setAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
	/// \brief
	///  setRotation sets creen rotation
	/// \details 
	/// setRotation sets Rotation to landscape mode
	void setRotation();
	/// \brief
	///  drawPixel draws a pixel
	/// \details 
	/// drawPixel draws a pixel to a x and y coord
	void drawPixel(uint16_t x, uint16_t y, uint16_t color);
	/// \brief
	///  fgcolor sets the color
	/// \details 
	/// fgcolor sets the color and writes it to the chip in 16 bit
	void fgColor(uint16_t c);
	/// \brief
	///  swap swaps two values
	/// \details 
	/// swap swaps two 16 bit values x and y
	void swap(uint16_t& x,uint16_t& y);
	/// \brief
	///  common control word CASET
	/// \details 
	/// Writes CASET command to the chip. And set RS and WR low
	void caset();
	/// \brief
	///  common control word Paset
	/// \details 
	/// Writes paset command to the chip. And set RS and WR low
	void paset();
	/// \brief
	///  common control word Ramwr
	/// \details 
	/// Writes Ramwr command to the chip. And set RS and WR low
	void ramwr();
	
	/// \brief
	///  write8bits write 8 bits
	/// \details 
	/// write8bits writes the first 8 bits from  16bits can also be used as just 8 bits writer 
	void write8bits(uint16_t lo);
	
	/// \brief
	///  resetdisp resets the display
	/// \details 
	/// resetdisp resets the display fully and needs to initialized again
	void resetdisp();
};

#endif // ILI9481_HPP
