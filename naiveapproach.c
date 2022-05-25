#include <stdio.h>
#include <string.h>

void search(char* pat, char* txt){
    int M = strlen(pat);
    int N = strlen(txt);
    int i;
    for (i = 0; i <= N - M; i++)
    {
        int j;

        for (j = 0; j < M; j++)
        {
            if (txt[i+j] != pat[j])
            {
                break;
            }
            
        }

        if (j==M)
        {
            printf("pattern found at indexr %d \n", i);
        }
        
        
    }
    
}

int main()
{
    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";
    search(pat, txt);
    return 0;
}