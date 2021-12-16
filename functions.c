#define TXT 1024
#define WORD 30

void gematrias(char *word, char *text)
{
    int geo = checkwordgeo(word);
    while(*text!='\0')
    {
        if((*text != '\n') && (*text != '\t') &&(*text != ' '))
        {
            checkFromGeo(text,geo);
        }
        text++;
    }
}

int checkWordGeo(char *word)
{
    int sum=0;
    while(*word != '\0')
    {
        if(65<=*word<=90)
        {
            sum = sum + *word -64;
        }
        if(97<=*word<=122)
        {
            sum = sum + *word -96;  
        }
        word++;
    } 
    return sum;
}

void checkFromGeo(char *text, int needSum)
{
    int sum=0;
    char* start= text;
    int count = 0;
    while((sum<needSum)&&(*text!='\0') )
    {
        if(65<=*text<=90)
        {
            sum = sum + *text -64;
        }
        if(97<=*text<=122)
        {
            sum = sum + *text -96;
        }
        text++;
        count++;
    }
    if(sum == needSum)
    {
        while(count>0)
        {
            print("%c",*start);
            count--;
            start++;
        }
    }
}

void anagram(char *word,char *text)
{
    int chars[256]={0};
    int length = fullArrAndlength(word,chars);
    int copychars[256];
    while(*text!='\0')
    {
        if((*text != '\n') && (*text != '\t') &&(*text != ' '))
        {
            myCopyArr(chars,copychars);
            checkFromAnag(text,copychars,length);

        }
    }
}

int fullArrAndlength(char *word,int chars[])
{
    int sum = 0;
    while(*word != '\0')
    {
        chars[*word]++;
        sum++;
    }
}
void myCopyArr(int src[],int dest[])
{
    for(int i=0 ; i<256 ; i++)
    {
        dest[i]=src[i];
    }
}
void checkFromAnag(char *text, int coChars[], int length)
{
    char *start = text;
    int count =0;
    while ((*text !='\0')&&(length>0))
    {
        if((*text != '\n') && (*text != '\t') &&(*text != ' '))
        {
            coChars[*text]--;
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
    while(count!=0)
    {
        print("%c", *start);
        start++;
        count--;
    }
    
}

