
#ifndef PT2313_h
#define PT2313_h

#include "Arduino.h"
#include "Wire.h"

#define PT2313_ADDR            0x44
#define PT2313_DEFVOL          35


#define PT2313_VOL_REG        0x00 //00000000
#define PT2313_L_ATT_REG      0xC0 //11000000
#define PT2313_R_ATT_REG      0xE0 //11100000
#define PT2313_BASS_REG       0x60 //01101111
#define PT2313_TREBLE_REG     0x70 //01110000

class PT2313 {
	
public:
    void    initialize(byte source=0,bool muted=true);
	void	source	(byte val);
	void	volume	(byte val);
	void	equalize(bool band,int val);
	void	equalize(int bss,int trb);
	void	balance	(int val);
	void    gain    (byte val);
	void    loudness(bool val);
private:
	void    writeByte(byte val);
	int		boundary(int val,int min,int max);
	uint8_t	audioSwitch_reg;
};

#endif