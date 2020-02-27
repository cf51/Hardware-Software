#include<stdio.h>
#include<stdlib.h> 

// Course: Hardware-Software CW1
// Name: Callum Forsyth
// User: cf51 


// Structure that stores RGB values  
struct Pixels{
    int red, green, blue; 
};  

// Structure that stores the PPM Data
struct PPM{
    char P3[2]; 
    char comments;
    int width, height, maxColour; 
    struct Pixels *pixels; 
}; 



struct PPM *getPPM(FILE * f){

}


void showPPM(struct PPM * im){

}


struct PPM * encode(struct PPM * im, char * message, unsigned int mSize, unsigned int secret){

}


char * decode(struct PPM * im, unsigned int secret){
    return 0; 
}

int main(int argc, char** argv){
    return 0; 
}