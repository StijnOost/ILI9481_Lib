 #include "ILI9481.hpp"

ILI9481::ILI9481(int w,int h,hwlib::target::pin_out & pinoutD15, hwlib::target::pin_out & pinoutD14, hwlib::target::pin_out & pinoutD13, hwlib::target::pin_out & pinoutD12, hwlib::target::pin_out & pinoutD11, hwlib::target::pin_out & pinoutD10, hwlib::target::pin_out & pinoutD9, hwlib::target::pin_out & pinoutD8, hwlib::target::pin_out & pinoutD7, hwlib::target::pin_out & pinoutD6, hwlib::target::pin_out & pinoutD5, hwlib::target::pin_out & pinoutD4, hwlib::target::pin_out & pinoutD3, hwlib::target::pin_out & pinoutD2 ,hwlib::target::pin_out & pinoutD1, hwlib::target::pin_out & pinoutD0, hwlib::target::pin_out & pinRS, hwlib::target::pin_out & pinWR, hwlib::target::pin_out & pinCS, hwlib::target::pin_out & pinRST):
	w(w),
	h(h),
	pinoutD15(pinoutD15),
	pinoutD14(pinoutD14),
	pinoutD13(pinoutD13),
	pinoutD12(pinoutD12),
	pinoutD11(pinoutD11),
	pinoutD10(pinoutD10),
	pinoutD9(pinoutD9),
	pinoutD8(pinoutD8),
	
	pinoutD7(pinoutD7),
	pinoutD6(pinoutD6),
	pinoutD5(pinoutD5),
	pinoutD4(pinoutD4),
	pinoutD3(pinoutD3),
	pinoutD2(pinoutD2),
	pinoutD1(pinoutD1),
	pinoutD0(pinoutD0),
	
	pinRS(pinRS),
	pinWR(pinWR),
	pinCS(pinCS),
	pinRST(pinRST)

	{	
		pinRS.write(1);
		pinWR.write(1);
		pinCS.write(1);
		pinRS.flush();
		pinWR.flush();
		pinCS.flush();
	}


void ILI9481::init(){
	
	pinRST.write(1);
	pinRST.flush();
	hwlib::wait_ms(50);
	pinRST.write(0);
	pinRST.flush();
	hwlib::wait_ms(10);
	pinRST.write(1);
	pinRST.flush();
	hwlib::wait_ms(10);
	
	writecommand(0x11); 	//exit  sleep mode
	hwlib::wait_ms(20);
	writecommand(0xD0); 	//Power setting
	writedata(0x07); 		//use VC 1,2,3
	writedata(0x42);		//PON			BT[1]
	writedata(0x18);		//VCIRE			VRH[3]

	writecommand(0xD1);		//vcom control
	writedata(0x00); 
	writedata(0x07);
	writedata(0x10);

	writecommand(0xD2);
	writedata(0x01);
	writedata(0x02);

	writecommand(0xC0);
	writedata(0x10);
	writedata(0x3B);
	writedata(0x00);
	writedata(0x02);
	writedata(0x11);

	writecommand(0xC5);
	writedata(0x03);

	writecommand(0xC8);
	writedata(0x00);
	writedata(0x32);
	writedata(0x36);
	writedata(0x45);
	writedata(0x06);
	writedata(0x16);
	writedata(0x37);
	writedata(0x75);
	writedata(0x77);
	writedata(0x54);
	writedata(0x0C);
	writedata(0x00);

	writecommand(0x36);
	writedata(0x0A);

	writecommand(0x3A);
	writedata(0x55);

	writecommand(0x2A);
	writedata(0x00);
	writedata(0x00);
	writedata(0x01);
	writedata(0x3F);

	writecommand(0x2B);
	writedata(0x00);
	writedata(0x00);
	writedata(0x01);
	writedata(0xDF);

	hwlib::wait_ms(120);
	writecommand(0x29);
	hwlib::wait_ms(25);
}
	
	/***************************************************************************************
** Function name:           writecommand
** Description:             Send an 8 bit command to the TFT
***************************************************************************************/
void ILI9481::writecommand(uint8_t c)
{
	SETUP_CS_L;
	RS_L;
	write16(c);
	WR_STB;
	RS_H;
	SETUP_CS_H;
}

/***************************************************************************************
** Function name:           writedata
** Description:             Send a 8 bit data value to the TFT
***************************************************************************************/
void ILI9481::writedata(uint8_t c)
{
	SETUP_CS_L;
	write16(c);
	WR_STB;
	SETUP_CS_H;
}


/***************************************************************************************
** Function name:           Setup 16 bit value on TFT bus
** Descriptions:            Sets or clears the bits on the bus
***************************************************************************************/

void ILI9481::write16(uint16_t word)
{

	port_all_bits.write(0);
	port_all_bits.flush();
	pinWR.write(0);
	pinWR.flush();
  // The compiler efficiently codes this
  // so it is quite quick.                    Port.bit
	if (word&0x8000) {pinoutD15.write(1);  pinoutD15.flush();} // D.6
	if (word&0x4000) {pinoutD14.write(1);  pinoutD14.flush();} // D.3
	if (word&0x2000) {pinoutD13.write(1);  pinoutD13.flush();} // D.2
	if (word&0x1000) {pinoutD12.write(1);  pinoutD12.flush();} // D.1
	if (word&0x0800) {pinoutD11.write(1);  pinoutD11.flush();} // D.0
	if (word&0x0400) {pinoutD10.write(1);  pinoutD10.flush();} // A.15
	if (word&0x0200) {pinoutD9.write(1);   pinoutD9.flush();}  // A.14
	if (word&0x0100) {pinoutD8.write(1);   pinoutD8.flush();}  // B.26

  // so it is quite quick.                    Port.bit
	if (word&0x0080) {pinoutD7.write(1);  pinoutD7.flush();}  // D.9
	if (word&0x0040) {pinoutD6.write(1);  pinoutD6.flush();}  // A.7
	if (word&0x0020) {pinoutD5.write(1);  pinoutD5.flush();} // D.10
	if (word&0x0010) {pinoutD4.write(1);  pinoutD4.flush();} // C.1
	if (word&0x0008) {pinoutD3.write(1);  pinoutD3.flush();}  // C.2
	if (word&0x0004) {pinoutD2.write(1);  pinoutD2.flush();} // C.3
	if (word&0x0002) {pinoutD1.write(1);  pinoutD1.flush();}  // C.4
	if (word&0x0001) {pinoutD0.write(1);  pinoutD0.flush();}// C.5
}

void ILI9481::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
	setAddrWindow(x, y, x+w-1, y+h-1);
	
	uint32_t hw= h*w;
	fgColor(color);
    while (hw>47) { hw-=48; // Screen width/10
      WR_STB;WR_STB;WR_STB;WR_STB;
      WR_STB;WR_STB;WR_STB;WR_STB;
      WR_STB;WR_STB;WR_STB;WR_STB;
      WR_STB;WR_STB;WR_STB;WR_STB;
      WR_STB;WR_STB;WR_STB;WR_STB;
      WR_STB;WR_STB;WR_STB;WR_STB;
      WR_STB;WR_STB;WR_STB;WR_STB;
      WR_STB;WR_STB;WR_STB;WR_STB;
      WR_STB;WR_STB;WR_STB;WR_STB;
      WR_STB;WR_STB;WR_STB;WR_STB;
      WR_STB;WR_STB;WR_STB;WR_STB;
      WR_STB;WR_STB;WR_STB;WR_STB;
    }
    while (hw>15) { hw-=16;
      WR_STB;WR_STB;WR_STB;WR_STB;
      WR_STB;WR_STB;WR_STB;WR_STB;
      WR_STB;WR_STB;WR_STB;WR_STB;
      WR_STB;WR_STB;WR_STB;WR_STB;
    }

    while(hw--) { WR_STB;}
  CS_H;
}

void ILI9481::setWindow(int16_t x0, int16_t y0, int16_t x1, int16_t y1)
{
  setAddrWindow(x0, y0, x1, y1);
  CS_H;
}

void ILI9481::setAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
  if (x0>x1) swap(x0,x1);
  if (y0>y1) swap(y0,y1);
  CS_L;
  caset();
  write8bits(x0>>8);WR_SB;
  write8bits(x0);WR_SB;
  write8bits(x1>>8);WR_SB;
  write8bits(x1);WR_SB;
  paset();
  write8bits(y0>>8);WR_SB;
  write8bits(y0);WR_SB;
  write8bits(y1>>8);WR_SB;
  write8bits(y1);WR_SB;
  ramwr();
}

void ILI9481::setRotation()
{
	writecommand(0x36);
	writedata(0x20 | 0x08);
}

void ILI9481::drawPixel(uint16_t x, uint16_t y, uint16_t color)
{
  CS_L;
  caset();
  write8bits(x>>8);WR_SB;
  write8bits(x);WR_SB;
  write8bits(x>>8);WR_SB;
  write8bits(x);WR_SB;
  paset();
  write8bits(y>>8);WR_SB;
  write8bits(y);WR_SB;
  write8bits(y>>8);WR_SB;
  write8bits(y);WR_SB;
  ramwr();
  fgColor(color); WR_SB;
  CS_H;
}

void ILI9481::fgColor(uint16_t c)
{
	port_all_bits.write(0);
	port_all_bits.flush();
	pinWR.write(0);
	pinWR.flush();
	if (c&0x8000) {pinoutD15.write(1);  pinoutD15.flush();} 
	if (c&0x4000) {pinoutD14.write(1);  pinoutD14.flush();} 
	if (c&0x2000) {pinoutD13.write(1);  pinoutD13.flush();} 
	if (c&0x1000) {pinoutD12.write(1);  pinoutD12.flush();} 
	if (c&0x0800) {pinoutD11.write(1);  pinoutD11.flush();} 
	if (c&0x0400) {pinoutD10.write(1);  pinoutD10.flush();}
	if (c&0x0200) {pinoutD9.write(1);   pinoutD9.flush();}  
	if (c&0x0100) {pinoutD8.write(1);   pinoutD8.flush();}
	
	if (c&0x80){ pinoutD7.write(1);  pinoutD7.flush();}
	if (c&0x40){ pinoutD6.write(1);  pinoutD6.flush();}
	if (c&0x20){ pinoutD5.write(1);  pinoutD5.flush();}
	if (c&0x10){ pinoutD4.write(1);  pinoutD4.flush();}
	if (c&0x08){ pinoutD3.write(1);  pinoutD3.flush();}
	if (c&0x04){ pinoutD2.write(1);  pinoutD2.flush();}
	if (c&0x02){ pinoutD1.write(1);  pinoutD1.flush();}
	if (c&0x01){ pinoutD0.write(1);  pinoutD0.flush();}

}

void ILI9481::swap(uint16_t& x,uint16_t& y){
	int tmp = y;
	y=x;
	x=tmp;
}

void ILI9481::caset()
{
	D0_D7_bits.write(0);
	D0_D7_bits.flush();
	pinoutD5.write(1);
	pinoutD5.flush();
	pinRS.write(0);
	pinWR.write(0);
	pinRS.flush();
	pinWR.flush();
  //REG_PIOC_CODR = 0b00000000000000000000000011111110; // Clear RS and bits in C

	pinoutD3.write(1);
	pinoutD1.write(1);
	pinoutD3.flush();
	pinoutD1.flush();
  //REG_PIOC_SODR = 0b00000000000000000000000000010100; // Write the CASET specific bits

  WR_H;
  RS_H;
}

void ILI9481::paset()
{
  //                |       |       |       |         Ruler for byte MS bits 31, 23, 15 and 7
	D0_D7_bits.write(0);
	D0_D7_bits.flush();
  //REG_PIOA_CODR = 0b00000000000000000000000010000000; // Clear bits in A
 // REG_PIOD_CODR = 0b00000000000000000000011000000000; // Clear bits in D
	pinoutD5.write(1);
	pinoutD5.flush();
	
	pinRS.write(0);
	pinWR.write(0);
	pinRS.flush();
	pinWR.flush();
	//REG_PIOD_SODR = 0b00000000000000000000010000000000; // Set common bits in D
  //                                        WR        // Set WR and RS low
  //REG_PIOC_CODR = 0b00000000000000000000000011111110; // Clear RS and bits in C
	pinoutD3.write(1);
	pinoutD1.write(1);
	pinoutD0.write(1);
	pinoutD0.flush();
	pinoutD3.flush();
	pinoutD1.flush();
  //REG_PIOC_SODR = 0b00000000000000000000000000110100; // Write the PASET specific bits

  WR_H;
  RS_H;
}

void ILI9481::ramwr(void)
{
  //                |       |       |       |         Ruler for byte MS bits 31, 23, 15 and 7
 // REG_PIOA_CODR = 0b00000000000000000000000010000000; // Clear bits in A
 // REG_PIOD_CODR = 0b00000000000000000000011000000000; // Clear bits in D
  
  	D0_D7_bits.write(0);
	D0_D7_bits.flush();
	pinoutD5.write(1);
	pinoutD5.flush();
  //REG_PIOD_SODR = 0b00000000000000000000010000000000; // Set common bits in D
  //                                        WR        // Set WR and RS low
  
	pinRS.write(0);
	pinWR.write(0);
	pinRS.flush();
	pinWR.flush();
  //REG_PIOC_CODR = 0b00000000000000000000000011111110; // Clear RS and bits in C
	pinoutD3.write(1);
	pinoutD2.write(1);
	pinoutD3.flush();
	pinoutD2.flush();
  //REG_PIOC_SODR = 0b00000000000000000000000000001100; // Write the RAMWR specific bits
  WR_H;
  RS_H;
}


void ILI9481::write8bits(uint16_t lo)
{
		D0_D7_bits.write(0);
		D0_D7_bits.flush();
		
		pinWR.write(0);
		pinWR.flush();
  // The compiler efficiently codes this
  // so it is quite quick.                Port.bit
	if (lo&0x80){ pinoutD7.write(1);  pinoutD7.flush();}  // D.9
	if (lo&0x40){ pinoutD6.write(1);  pinoutD6.flush();}  // A.7
	if (lo&0x20){ pinoutD5.write(1);  pinoutD5.flush();} // D.10
	if (lo&0x10){ pinoutD4.write(1);  pinoutD4.flush();} // C.1
	if (lo&0x08){ pinoutD3.write(1);  pinoutD3.flush();}  // C.2
	if (lo&0x04){ pinoutD2.write(1);  pinoutD2.flush();} // C.3
	if (lo&0x02){ pinoutD1.write(1);  pinoutD1.flush();}  // C.4
	if (lo&0x01){ pinoutD0.write(1);  pinoutD0.flush();}// C.5
  
}

void ILI9481::resetdisp(){
	pinRST.write(1);
	pinRST.flush();
	hwlib::wait_ms(2);
	pinRST.write(0);
	pinRST.flush();
}

