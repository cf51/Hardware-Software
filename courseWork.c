#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<math.h>

// Course: Hardware-Software CW1
// Name: Callum Forsyth
// User: cf51 

// Structure that stores RGB values  
struct Pixels{
    int red, green, blue; 
};  

struct LinkedList{
    struct LinkedList * next;
    char * val;
};

// Structure that stores the PPM Data
struct PPM{
    char * P3;  
    struct LinkedList * commentVal; 
    int width, height, maxColour; 
    struct Pixels * matrix; 
}; 

struct PPM *getPPM(FILE * f){

    // Allocates dynamic memeory to PPM using malloc 
    struct PPM * image = (struct PPM *) malloc(sizeof(struct PPM)); 

    char *comment; 
    char character;
    // int P3, width, height, maxColour; 
    int c = 100; 
    struct LinkedList * head = NULL; 
    struct LinkedList * node = NULL; 
    int count; 

    image->P3 = (char *) malloc(2 * sizeof(char)); 
    image->P3[0] = getc(f); 
    image->P3[1] = getc(f); 
    //fprintf(stderr,"\n\n%c", image->P3);
    
    // Checking the PPM to make sure it is P3 (correct format)
    // printf("PPM image correct"); 

    // printf("%f", image->P3); 
    // Returning null if the PPM is not P3 
    if ((image->P3[0] != 'P') && (image->P3[1] != '3')){         
        fprintf(stderr,"Error not P3 format"); 
        exit(0); 
        
    }

    // Moving to the next character (Will be the new line) 
    character = getc(f); 
    // Moving to the next character (either # or number value)
    character = getc(f); 

    // Checking all lines that start with a '#' (A comment)
    while (character == '#'){   
        comment = (char *) malloc(sizeof(char)); 
        ungetc(character, f); // Taking a single character for file and putting it back into input stream 
        fscanf(f, "%[^\n]", comment); // Taking all characters in a single line of input 

        // Getting the comments and storing them as nodes in the linked list  
        if (head == NULL){
            head = (struct LinkedList *)malloc(sizeof(struct LinkedList)); 
            head->val = comment; 
            head->next = NULL; 
             //printf("%s\n", node->comment)

            image->commentVal = head; 
            node = head;
        }
        else{
            while(node->next != NULL){
                node = node-> next; 
            }

            node->next = (struct LinkedList *)malloc(sizeof(struct LinkedList));
            node = node-> next; 
            node->val = malloc(sizeof(comment)); 
            node->val = comment;
            node->next = NULL; 
        }

    // Moving to the next character (Skipping new line)
    character = getc(f); 
    // Moving to the next character (Will be the next line)
    character = getc(f); 

    }

    // Going back to the previously read character (This will give me the first digit of the width)
    ungetc(character, f);

    // Getting the width 
    fscanf(f, "%d", &image->width);

    // Getting the height 
    fscanf(f, "%d", &image->height);

    // Getting the max colour 
    fscanf(f, "%d", &image->maxColour);

    /*
    image->matrix = (struct Pixels *) malloc(image->width * image->height * sizeof(struct Pixels));

    while(count< image->height * image->width){
        fscanf(f, "%d", &image->matrix[count].red);
        fscanf(f, "%d", &image->matrix[count].green);
        fscanf(f, "%d", &image->matrix[count].blue);
        count++;
    }

    */


    return image; 
    
}; 


void showPPM(struct PPM * im){

    struct LinkedList * currentNode =  im->commentVal; 

    int i = 0; 
    // Calculating the size of the image (number of pixels)
    int allPixels = im->width * im->height; 

   
    // Printing the PPM image in the PPM format 
    printf("%c%c\n", im->P3[0], im->P3[1]);
    while(currentNode != NULL){

        printf("%s\n", currentNode->val);
        currentNode = currentNode->next;
    }
    printf("%d %d\n", im->width, im->height);
    printf("%d\n", im->maxColour);

    /*
    // Printing the RBG values 
    while (i < allPixels){
        i++; 
        printf("%d %d %d  ", im->matrix[i].red, im->matrix[i].green, im->matrix[i].blue);
        if((i+1)%im->width == 0 && i > 0){
          printf("\n");
        }

    }

    */ 

}

/*
struct PPM * encode(struct PPM * im, char * message, unsigned int mSize, unsigned int secret){

    int ascii[50];
    int j;  
    long long binary[mSize]; 

    // turning the message into ascii 
    for(int i=0; i<mSize;++i){
        ascii[i] = (int) message[i];
    }

    // getting the length of the message 
    for(int x=0; x<mSize; ++x){
        // storing the binary number in array 
       // binary[x] = convertToBinary(ascii[x]);
    }

}


char * decode(struct PPM * im, unsigned int secret){
    return 0; 
}
*/

int main(int argc, char** argv){

    FILE * f ;
    f = fopen(argv[1],"r");
    struct PPM *image ; 
    image =  (struct PPM *) malloc(sizeof(struct PPM));
    image = getPPM(f);
    showPPM(image);
    fclose(f);

    return 0; 

 
}