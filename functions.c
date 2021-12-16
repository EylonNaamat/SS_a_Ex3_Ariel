void gematrias(char *word, char *text)
{
    int geo = checkwordgeo(word);
}

int checkWordGeo(char* word)
{
    int sum=0;
    while(*word == '\0')
    {
        if(65<=*word<=90)
        {
            sum = sum + *word -65;
        }
        if(97<=*word<=122)
        {
            sum = sum + *word -97;  
        }
        word++;
    } 
}

int checkFromGeo(char* word, int needSum)
{
    int sum=0;
    char* start= word;
    int count = 0;
    while(sum<needSum)
    {
        if(65<=*word<=90)
        {
            sum = sum + *word -65;
            count++;
        }
        if(97<=*word<=122)
        {
            sum = sum + *word -97;
            count++;
        }
        word++;
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
