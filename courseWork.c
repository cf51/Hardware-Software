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
    char *comment; 
    char character;
    char *c; 
    struct LinkedList *head = NULL; 
    struct LinkedList *node = NULL; 

    // Allocates dynamic memeory to PPM using malloc 
    struct PPM *image =  (struct PPM *) malloc(sizeof(struct PPM)); 

    // Checking the PPM to make sure it is P3 (correct format)
    fgets(image->P3, sizeof(image->P3), f);

    printf("%f", image->P3); 
    // Returning null if the PPM is not P3 
    if ((image->P3[0] != 'P') && (image->P3[1] != '3')){
        perror("Error not P3 format"); 
        return NULL; 
        
    }

    // Moving to the next character (Will be a space)
    character = getc(f); 

    // Moving to the next character (Will be the next line)
    character = getc(f); 

    // Checking all lines that start with a '#' (A comment)
    while (character == '#'){   
        comment = malloc(*c); 
        ungetc(character, f); // Taking a single character for file and putting it back into input stream 
        fscanf(f, "%[^\n", c); // Taking all characters in a single line of input 

        /*
        if (head == NULL){
            head = (struct LinkedList *)malloc(sizeof(struct LinkedList)); 
            head->num = comment; 
            head->next = NULL; 
        }
        */ 

    }
    
}; 


void showPPM(struct PPM * im){

}


struct PPM * encode(struct PPM * im, char * message, unsigned int mSize, unsigned int secret){

}


char * decode(struct PPM * im, unsigned int secret){
    return 0; 
}

int main(int argc, char** argv){

    getPPM(); 
}