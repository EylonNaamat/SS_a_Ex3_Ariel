#include <string.h>
#include <stdio.h>
#define TXT 1024
#define WORD 30
#define DIFFUPPER 65
#define DIFFLOWER 97

void atbash(char* word, char* text)
{
    char atbash [WORD] = {0};
    char reverseAtbabsh [WORD] = {0};
    char ans [TXT] = {0};
    atbashWord(word, atbash);
    reverseAtbash(atbash, reverseAtbabsh);
    int flag = 0;
    while(*text != 0){
        if(*text == *atbash){
            checkNprint(text, atbash, arraySize(atbash), &flag);
        }
        if(*text == *reverseAtbabsh){
            checkNprint(text, reverseAtbabsh, arraySize(reverseAtbabsh));
        }
        text++;
    }

}

void atbashWord(char* word, char* atbash){
    int diff = 0;
    while(*word != 0){
        if(*word > 96 && *word < 123){
            diff = *word - DIFFLOWER;
            *atbash = 122 - diff;
        }
        else
        {
            if(* word > 64 && *word < 91)
            {
            diff = *word -DIFFUPPER;
            *atbash = 90 - diff;
            }
            else
            {
                *atbash = *word;
            }
        }
        word++;
        atbash++;
    }
}

void reverseAtbash(char* atb, char* reverseAt){
    int i = 0;
    while(* atb != 0){
        i++;
        atb++;
    }
    for(int j = i-1; j > 0; --j){
        *reverseAt = atb[j];
        reverseAt--;
    }
}

int arraySize(char* arr){
    int size = 0;
    while(*arr != 0){
        size++;
        arr++;
    }
    return size;
}

void checkNprint(char* text, char* word, int size, int* flag){
    int counter = 0;
    char* start = text;
    char* pointer = text;
    while(*pointer != 0){
        if(*pointer == *word){
            word++;
        }else{
            if((*pointer > 96 && *pointer < 123) || (*pointer > 64 && *pointer < 91)){
                return;
            }
        }
    counter++;    
    pointer++;
    }
    if(counter != size){
        return;
    }

    if(*flag > 0){
        printf("%c", '~');
    }
    *flag++;
    while(counter != 0){
        printf("%c", *start);
        start++;
        counter--;
    }
}
