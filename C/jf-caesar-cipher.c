/************************************************
# COMSC210
# Description: Lab3: Caesar Cipher in C
# Language: C
# Date: 2/15/2023 
# Location: RWU
# Author: Joshua Farias
************************************************/

//Header files

#include <stdlib.h> //memory allocation
#include <stdio.h> //input-output
#include <string.h> //string manipulation
#include <ctype.h> //character classification

enum {MAX_LEN = 1024}; //defines max length for user input

//Main

int main(void) {
    size_t len; //declares variable to store length of text
    int shift; //declares variable to store shift amount for cipher
    char *text; //stores user input using a pointer to char
    char num[16]; //creates array to store shift number

    text = malloc(MAX_LEN); //allocates memory for text pointer
    if (text == NULL) { //check if memory allocation failed
        perror("malloc");
        exit(EXIT_FAILURE); //terminate program if error occurs
    }

    //user input prompt
    printf("Input text to be encrypted: "); 
    fflush(stdout); //flush std output stream to display prompt
    if (fgets(text, MAX_LEN, stdin) == NULL) //read text input and check for errors
        exit(EXIT_FAILURE); //terminate program if error occurs

    //calculate length of user input, removes newline character and updates length of str input
    len = strlen(text);
    if (text[len - 1] == '\n')
        text[len - 1] = '\0';
    len -= 1;

    //shift number input prompt
    printf("Choose shift number [1-26]: ");
    fflush(stdout);
    if (fgets(num, 16, stdin) == NULL)
        exit(EXIT_FAILURE);

    shift = (int) strtol(num, NULL, 0); //set shift value based on user input

    //error handling if user input for shift amount is out of range
    if (shift < 1 || shift > 26) {
        fprintf(stderr, "Shift number is out of range");
        exit(EXIT_FAILURE);
    }

    //iterates through user string, applies caesar cipher shift amount and prints encrypted text
    for (int i = 0; i < len; ++i) {
        if (islower(text[i])) {
            printf("%c", (((text[i] - 'a') + shift) % 26) + 'a');
        } else if (isupper(text[i])) {
            printf("%c", (((text[i] - 'A') + shift) % 26) + 'A');
        } else {
            printf("%c", text[i]);
        }
    }

    exit(EXIT_SUCCESS);
}
