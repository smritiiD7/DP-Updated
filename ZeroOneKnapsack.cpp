#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int knapsack(int wt[],int val[],int w,int n) // n is the number of items
{
    if(w==0||n==0)
    return 0;
    if(wt[n-1]<=w)
    {
        return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
    else if(wt[n-1]>w)
    return knapsack(wt,val,w,n-1);
}
int main(){
   int wt[4]={24,10,10,7};
   int val[4]={24,18,18,10};
   int w;
   cout<<"Enter the maximum weight of the knapsack";
   cin>>w;
   cout<<"The maximum profit is : "<<knapsack(wt,val,w,4);

     return 0;
}