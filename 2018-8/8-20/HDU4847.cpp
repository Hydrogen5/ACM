//Wow! Such Doge!
#include <iostream>
#include <cstdio>
using namespace std;
int main() 
{
    int ans=0;
    char c;
    int state;
    while((c=getchar())!=EOF)
    {   
        if(tolower(c)=='d')
            state=1;
        
        else if (state==1&&tolower(c)=='o')
        {
            state = 2;      
        }
        
        else if (state==2&&tolower(c)=='g')
        {
            state=3;    
        }
        
        else if (state==3&&tolower(c)=='e')
        {
            ans++;
            state = 0;
        }
        else
            state = 0;
    }
    printf("%d\n",ans);
    return 0;
}