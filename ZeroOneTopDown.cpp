#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int knapsack(int wt[],int val[],int w,int n)
{
    int i,j;
    int t[n+1][w+1];
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<w+1;j++)
        {
            if(i==0||j==0)
            {
                t[i][j]=0;
            }
            else if(wt[i-1]<=w)
            {
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else 
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[i-1][j-1];
}
int main(){
    int val[]={60,100,120};
    int wt[]={10,20,30};
    int w=50;
    cout<<knapsack(wt,val,w,3);
     return 0;
}