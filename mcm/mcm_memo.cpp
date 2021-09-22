#include<bits/stdc++.h>
using namespace std;

int static t[1001][1001];
int solve(int arr[],int i,int j){
    if(i>=j)
        return 0;
    if(t[i][j]!=-1)
        return t[i][j];
    int mn=INT_MAX;
    for(int k=i;k<j;k++){
        int temp = solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(temp<mn)
            mn=temp; 
        t[i][j]=mn;   
    }
    return t[i][j];
}

int main(){
    int k;
    cin>>k;
    while(k--){
    memset(t,-1,sizeof(t));
    int n;
    cout<<"Enter the limit: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The minimum cost is : "<<solve(arr,1,n-1);
    cout<<endl;
    }
    return 0;
}