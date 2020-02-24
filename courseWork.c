#include<stdio.h>
#include<stdlib.h> 

// Course: Hardware-Software CW1
// Name: Callum Forsyth
// User: cf51 

// Structure that stores the PPM Data
struct PPM{
    int width, height, maxColour; 
    char comments[255]; 
    struct Pixels *pixels; 
}; 

// Structure that stores the Pixel Data 
struct Pixels{
    int red, green, blue; 
};  

struct PPM * getPPM(FILE * f){

}

showPPM(struct PPM * im){

}

struct PPM * encode(struct PPM * im, char * message, unsigned int mSize, unsigned int secret){

}

char * decode(struct ppm * im, unsigned int secret){

}