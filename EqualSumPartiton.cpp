#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool EqualSumArray(int arr[],int n,int sum)
{
    if(sum%2!=0)
    return false;
    bool t[n+1][sum+1];
    int i,j;
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<sum+1;j++)
        {
            if(j==0)
            {
                t[i][j]=true;
            }
            if(i==0)
            {
                t[i][j]=false;
            }
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
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[i-1][j-1];
}
int main(){
    int arr[4]={1,5,11,5};
    int sum=10;
    cout<<EqualSumArray(arr,4,sum);
     return 0;
}