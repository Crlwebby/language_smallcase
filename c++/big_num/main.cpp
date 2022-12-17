#include <iostream>

using namespace std;

class Bnum{
public:
    int bit[200]={};
    int length;
    char mark;
    Bnum(int *a=NULL, char b='+',int l = 0){
        mark = b;
        length = l;
        if(a!=NULL)
            for(int i = 0; i < length; i++)
                bit[i] = a[i];
    }
    void print();
    void operator=(const Bnum &a1){
        for(int i = 0; i < a1.length; i++)
            bit[i] = a1.bit[i];
        length = a1.length;
    }

};

void Bnum::print(){
    for(int i = this->length - 1; i >= 0; i--)
        cout<<this->bit[i];
    cout<<endl;
}

Bnum operator+(const Bnum& a1, const Bnum& a2){
    Bnum temp;
    int prev = 0;
    int max = a1.length>a2.length?a1.length:a2.length;
    for(int i = 0; i<=max; i++){
        temp.bit[i] = (a1.bit[i] + a2.bit[i] + prev) % 10;
        prev = (a1.bit[i] + a2.bit[i] + prev) / 10;
    }
    if(temp.bit[max]!=0)
        temp.length = max + 1;
    else
        temp.length = max;
    return temp;
}



int main()
{
    int a[15] = {8,4,1,6,8,5,8,5};
    int b[17] = {6,0,0,7,4,7,8,5,6,8,8,2,9,9};
    Bnum test(a,'+',8);
    Bnum test2(b,'+',14);
    Bnum test3 = test + test2;
    test.print();
    test2.print();
    test3.print();
    cout << "Hello world!" << endl;
    return 0;
}
