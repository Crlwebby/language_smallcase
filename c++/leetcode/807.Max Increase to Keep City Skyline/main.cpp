#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int m=4,n=4,sum=0;
    vector<vector<int> > grid(m);
    //点格矩阵
    vector<int> Row(n,0);
    //创建行最大值向量
    vector<int> Column(m,0);
    //创建列最大值向量

    for(int i=0;i<(int)grid.size();i++)
    //创建二维向量
    {
        grid[i].resize(n);
    }


    for(unsigned int i=0;i<grid.size();i++)
    {
        for(unsigned int j=0;j<grid[i].size();j++)
        {
            cin>>grid[i][j];
        }
    }

    for(unsigned int i=0;i<grid.size();i++)
    //收集行向量最大值数据
    {
        for(unsigned int j=0;j<grid[i].size();j++)
            Row[i]=max(Row[i],grid[i][j]);
    }


    for(unsigned int i=0;i<grid[0].size();i++)
    //收集列向量最大值数据
    {
        for(unsigned int j=0;j<grid.size();j++)
            Column[i]=max(Column[i],grid[j][i]);
    }


    for(unsigned int i=0;i<grid.size();i++)
    {
        for(unsigned int j=0;j<grid[i].size();j++)
            cout <<' '<<grid[i][j]<<' ' ;
        cout << endl;
    }


    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            sum=sum+min(Column[j],Row[i])-grid[i][j];
            grid[i][j]=min(Column[j],Row[i]);
        }
    }

    cout<<endl;

    for(unsigned int i=0;i<grid.size();i++)
    {
        for(unsigned int j=0;j<grid[i].size();j++)
            cout <<' '<<grid[i][j]<<' ' ;
        cout << endl;
    }
    cout<<sum<<endl;
    return 0;
}
