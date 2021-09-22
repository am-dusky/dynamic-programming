#include<bits/stdc++.h>
using namespace std;

int static t[102][102];

int knapsack(int wt[],int val[],int w,int n){
    if(n==0 || w==0)
        return 0;
    if(t[n][w]!=-1)
        return t[n][w];
    if(wt[n-1]<=w)
    {
        t[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
        return t[n][w];
    }
    else if(wt[n-1]>w)
        return knapsack(wt,val,w,n-1);
}

int main(){
    memset(t,-1,sizeof(t));
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    int wt[n],val[n],w;
    cout<<"Enter the weight of items: ";
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout<<"Enter the value of items: ";
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    cout<<"Enter the capacity of knapsack: ";
    cin>>w;
    cout<<"The total profit earned is : "<<knapsack(wt,val,w,n);
    return 0;
}