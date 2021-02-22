#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
    string address = "255.100.50.0";
    string address_temp;
    string a;
    unsigned int i=0;
    while(i<address.length()){
        if(address[i]=='.'){
                address_temp.append("[.]");
                i++;
            }
            else{
                a=address[i++];
                address_temp.append(a);
            }
    }
    cout<<address_temp.c_str();
    return 0;
}
