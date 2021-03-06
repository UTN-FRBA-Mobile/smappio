//  SmappioSoundBufferPrinter.h - Library for print sound buffer from I2S protocol 
//  Created by Smappio, May 6, 2018.

#ifndef SmappioSoundBufferPrinter_h
#define SmappioSoundBufferPrinter_h

#include "Arduino.h"
#include "Helper.h"

typedef enum {
    BITS            = 0,       // Solo bits
    BYTES           = 1,       // Solo bytes
    INTEGER         = 2,       // Solo resultado entero
    FULL_DETEAILED  = 3,       // El resultado formateado de todas las formas y detallado
} print_mode_t;

class SmappioSoundBufferPrinter
{
  public:
    SmappioSoundBufferPrinter();
    void print(int *buffer, int len, int signalBalancer, print_mode_t printMode, bool printBothChannels);
    void debug(char* msg);
    int32_t getSampleValue(int *buffer, int signalBalancer, bool printBothChannels);
    
  private:
    void printBits(size_t const size, void const *const p);
    void printBytes(size_t len, void *ptr);
    void printInteger(int frame);        
};


#endif