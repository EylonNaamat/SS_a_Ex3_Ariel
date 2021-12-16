#include <string.h>
#include <stdio.h>
#include "functions.h"

#define TXT 1024
#define WORD 30

int main()
{
    char  word [WORD] = {0};
    char txt [TXT] = {0};
    for(int i = 0; i < WORD; ++i)
    {
        scanf("%c", &word[i]);
        if(word[i] == '\n' || word[i] == '\t' || word[i] == ' ')
        {
            word[i] = '\0';
            break;
        }
    }
    for(int i = 0; i < TXT; ++i)
    {
        scanf("%c", &txt[i]);
        if(txt[i] == '~'){
            txt[i] = '\0';
            break;
        }
    }

    gematrias(word, txt);
    atbash(word, txt);
    anagram(word, txt);

    //gergrereggerg
}