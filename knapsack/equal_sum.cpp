// divide the array into subset such that sum of both subset is same
#include<bits/stdc++.h>
using namespace std;

bool subset(int arr[],int sum,int n){
    bool t[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0)
                t[i][j]=false;
            if(j==0)
                t[i][j]=true;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j)
                t[i][j]=((t[i-1][j-arr[i-1]]|| (t[i-1][j])));
            else 
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}

bool equal_sum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2!=0){
        return false;
    }
    else{
        subset(arr,sum/2,n);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool ans= equal_sum(arr,n);
    if(ans==true){
        cout<<"Possible!!!!\n";
    }
    else{
        cout<<"Not possible!!\n";
    }
    }
    return 0;
}
