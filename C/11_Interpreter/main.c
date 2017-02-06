#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "lexer.h"
#include "token.h"
#include "functions.h"

void push(int number, int* stack, int* top);
int checkIfNumber(struct word_t* Word);
long checkIfKeyword(struct word_t* Word);

long checkIfKeyword(struct word_t* Word) {
    long token = 0;
    token = generateToken(Word);

    return token;
}

void push(int number, int* stack, int* top) {
    int t = *top;
    t++;

    stack[t] = number;
    *top = t;

    return;
}

int checkIfNumber(struct word_t* Word) {
    int i;

    for(i=0 ; i<Word->length ; i++) {
        if(!(Word->word[i] > 47 && Word->word[i] < 58)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int i;
    int number;
    long key;

    int nWords; //-- number of words
    struct word_t* myWord[MAXWORDS];

    int top = -1;
    int* stack = malloc(sizeof(int) * MAXWORDS);

    //-- take the input line
    char* input;
    input = malloc(sizeof(char) * MAXLINELEN);
    fgets(input, MAXLINELEN, stdin);

    //-- split the line into words
    splitWords(input, myWord, &nWords);

    for(i=0 ; i<nWords ; i++) {
        if(checkIfNumber(myWord[i])) {
            //-- convert string to int
            number = atof(myWord[i]->word);

            //-- push number to stack
            push(number, stack, &top);
        }
        else if((key = checkIfKeyword(myWord[i])) > 0) {
            //-- functions
            if(key == print) {
                pop(stack, &top);
            }
            else if(key == printl) {
                popl(stack, &top);
            }
            else if(key == endl) {
                endline();
            }
            else if(key == add) {
                addition(stack, &top);
            }
            else if(key == sub) {
                subtraction(stack, &top);
            }
            else if(key == mul) {
                multiplication(stack, &top);
            }
            else if(key == div) {
                division(stack, &top);
            }
            else {
                //-- ERROR!!
                printf("ERROR! `%s' does not compute!\n", myWord[i]->word);
                return -1;
            }
        }
    }
}
