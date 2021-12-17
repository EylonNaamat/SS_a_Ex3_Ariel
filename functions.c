#include "functions.h"
#include <stdio.h>
#define TXT 1024
#define WORD 30
#define DIFFUPPER 65
#define DIFFLOWER 97

int checkWordGeo(char *word)
{
    int sum=0;
    while(*word != '\0')
    {
        if((65<=*word )&&(*word<=90))
        {
            sum = sum+*word-64;
        }
        if((97<= *word)&&(*word<=122))
        {
            sum = sum+*word-96;  
        }
        word++;
    }
    return sum;
}

void checkFromGeo(char *text, int needSum,int* flag)
{
    int sum=0;
    char* start= text;
    int count = 0;
    while((sum<needSum)&&(*text!='\0') )
    {
        if((65<=*text)&&(*text<=90))
        {
            sum = sum + *text-64;
        }
        if((97<=*text)&&(*text<=122))
        {
            sum = sum + *text -96;
        }
        text++;
        count++;
    }
    if(sum == needSum)
    {
        if(*flag!=0)
        {
           printf("~"); 
        }
        else
        {
            *flag = 1;
        }
        while(count>0)
        {
            printf("%c",*start);
            count--;
            start++;
        }
    }
}

void gematrias(char *word, char *text)
{
    int geo = checkWordGeo(word);
    int flag = 0;
    while(*text!='\0')
    {
        if(((65<=*text)&&(*text<=90))||((97<=*text)&&(*text<=122)))
        {
            checkFromGeo(text,geo,&flag);
        }
        text++;
    }
}

int fullArrAndlength(char *word,int chars[])
{
    int sum = 0;
    while(*word != '\0')
    {
        chars[(int)*word]++;
        sum++;
        word++;
    }
    return sum;
}
void myCopyArr(int src[],int dest[])
{
    for(int i=0 ; i<256 ; i++)
    {
        dest[i]=src[i];
    }
}
void checkFromAnag(char *text, int coChars[], int length,int *flag)
{
    char *start = text;
    int count =0;
    while ((*text !='\0')&&(length>0))
    {
        if((*text != '\n') && (*text != '\t') &&(*text != ' '))
        {
            coChars[(int)*text]--;
            length--;
        }
        text++;
        count++;
    }
    if(length!=0)
    {
        return;
    }
    for(int i=0;i<256;i++)
    {
        if(coChars[i]!=0)
        {
            return;
        }
        coChars[i]=0;
    }
    if(*flag!=0)
        {
           printf("~"); 
        }
        else
        {
            *flag = 1;
        }
    while(count>0)
    {
        printf("%c", *start);
        start++;
        count--;
    }
    
}

void anagram(char *word,char *text)
{
    int flag = 0;
    int chars[256]={0};
    int length = fullArrAndlength(word,chars);
    int copychars[256];
    while(*text!='\0')
    {
        if(((65<=*text)&&(*text<=90)) || ((97<=*text)&&(*text<=122)))
        {
            myCopyArr(chars,copychars);
            checkFromAnag(text,copychars,length,&flag);
        }
        text++;
    }
}


void atbash(char* word, char* text)
{
    char atbash [WORD] = {0};
    char reverseAtbabsh [WORD] = {0};
    atbashWord(word, atbash);
    reverseAtbash(atbash, reverseAtbabsh);
    int flag = 0;
    while(*text != 0){
        if(*text == *atbash){
            checkNprint(text, atbash, arraySize(atbash), &flag);
        }
        if(*text == *reverseAtbabsh){
            checkNprint(text, reverseAtbabsh, arraySize(reverseAtbabsh), &flag);
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

    if(*flag != 0){
        printf("%c", '~');
    }
    else
    {
        *flag = 1;
    }
    while(counter != 0){
        printf("%c", *start);
        start++;
        counter--;
    }
}
