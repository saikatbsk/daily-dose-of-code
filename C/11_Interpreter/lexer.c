#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "lexer.h"

int marker = 0;

int getWordFromLine(char* line, char* str, int* length);

long generateToken(struct word_t* Word) {
    int i;
    int letter;
    char* token = malloc(sizeof(char) * 3 * MAXWORDLEN);
    char* tmp = malloc(sizeof(char) * 3);

    for(i=0 ; i<Word->length ; i++) {
        letter = Word->word[i];
        sprintf(tmp, "%d", letter);
        strcat(token, tmp);
    }

    return atol(token);
}

int getWordFromLine(char* line, char* str, int* length) {
    int i = 0;
    char* string = malloc(sizeof(char) * MAXWORDLEN);

    while(line[marker] != '\0') {
        if(line[marker] == ' ' ) {
            marker++;
        }
        else {
            while(line[marker] != ' ') {
                string[i] = line[marker];
                i++;
                marker++;
            }

            *length = i;
            strcpy(str, string);

            return 0;
        }
    }

    return -1;
}

void splitWords(char* input, struct word_t* Word[], int* nWords) {
    int i = 0;
    int length;
    char* str;

    //-- append space and trailing zero
    size_t len = strlen(input);
    char* line = malloc(len+1+1);
    strcpy(line, input);
    line[len-1] = ' ';
    line[len] = '\0';

    for( ; ; ) {
        Word[i] = malloc(sizeof(struct word_t));

        //-- get a single word from line, break when line ends
        str = malloc(sizeof(char) * MAXWORDLEN);
        if(getWordFromLine(line, str, &length) == -1) {
            break;
        }

        Word[i]->word = str;
        Word[i]->length = length;
        i++;
    }

    //-- total number of words
    *nWords = i;

    return;
}
