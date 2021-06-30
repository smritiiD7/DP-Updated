#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool subset(int arr[],int sum,int n)
{
    bool t[n+1][sum+1];
    int i,j;
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<sum+1;j++)
        {
            if(i==0)
            t[i][j]=false;
            if(j==0)
            t[i][j]=true;
        }
    }
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            {
                t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
            }
            else
            t[i][j]=t[i-1][j];
        }
    }
    return t[i-1][j-1];
}
int main(){
    int arr[5]={8,6,8,8,7};
    int sum=9;
    bool ans=subset(arr,sum,5);
    cout<<ans;
     return 0;
}