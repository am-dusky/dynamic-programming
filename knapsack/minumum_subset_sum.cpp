// divide the array into parts such that sum of difference between two parts is minimum
#include<bits/stdc++.h>
using namespace std;

int count_min_subset_sum(int arr[],int n){
    //initialization
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    bool t[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0)
                t[i][j]=false;
            if(j==0)
                t[i][j]=true;
        }
    }

    //code
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j)
                t[i][j]=((t[i-1][j-arr[i-1]])|| (t[i-1][j]));
            else 
                t[i][j]=t[i-1][j];
        }
    }
    int diff=INT_MAX;
    for(int j=sum/2;j>=0;j--){
        if(t[n][j]==true){
            diff=sum-2*j;
            break;
        }
    }
    return diff;
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
    int ans=count_min_subset_sum(arr,n);
    cout<<"The number of subset with minimum subset is: "<<ans<<"\n";
    cout<<endl;
    }
    return 0;
}
