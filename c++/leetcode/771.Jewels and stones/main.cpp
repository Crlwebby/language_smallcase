#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string J,S;
    int i=0,j=0,sum=0;
/*    while(J[i]!='\0')             //O(m*n)
    {
        j=0;
        while(S[j]!='\0')
        {
            if(J[i]==S[j])
                sum++;
            j++;
        }
        i++;
    }
*/
    cin >> J >> S;
    sort(J.begin(),J.end());
    sort(S.begin(),S.end());

    while(J[i]!='\0'&&S[j]!='\0')
    {
        if(S[j]==J[i])
        {
            sum++;
            j++;
        }
        else if(S[j]<J[i])
        {
            j++;
        }
        else
            i++;
    }
    cout << sum << endl;
   // cout << sum << endl;
    return 0;
}
