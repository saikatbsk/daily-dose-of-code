#ifndef _LEXER_H_
#define _LEXER_H_

void splitWords(char* input, struct word_t* Word[], int* nWords);
long generateToken(struct word_t* Word);

#endif
