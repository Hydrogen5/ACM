//Rewards
#include <iostream>
using namespace std;
int main()
{
    int cups=0, medals=0;
    int n;
    for (int i = 1; i <= 3;i++)
    {
        cin>>n;
        cups += n;
    }
    for (int i = 1; i <= 3;i++)
    {
        cin>>n;
        medals += n;
    }
    cin>>n;
    if(n>=(cups+4)/5+(medals+9)/10) cout<<"YES\n";
    else
        cout << "NO\n";
}