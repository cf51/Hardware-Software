#include<stdio.h>


// Course: Hardware-Software CW1
// Name: Callum Forsyth
// User: cf51 


struct PPM{

    int width, height, maxColour; 
    char comments[255]; 
    struct Pixels *pixels; 
}; 

struct Pixels{
    int red, green, blue; 
};  
