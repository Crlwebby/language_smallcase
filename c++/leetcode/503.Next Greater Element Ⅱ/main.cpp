#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int>::iterator it;
    vector<int>::iterator ij;
    vector<int> nums;
    vector<int> Output;
    int x=0;
    for(int i=0;i<10;i++){
        cin>>x;
        nums.push_back(x);
    }
    for(it=nums.begin();it!=nums.end();it++){
        ij=it+1;
        for(vector<int>::iterator t=nums.begin();t!=nums.end();t++){
            if(ij>=nums.end())
                ij=nums.begin();
            if(*ij>*it){
                Output.push_back(*ij);
                break;
            }
            ij++;
        }
        ij--;
        if(ij==it){
            Output.push_back(-1);
        }
    }
    for (unsigned int i=0;i<Output.size();i++)
        cout<<Output.at(i)<<endl;
    return 0;
}
