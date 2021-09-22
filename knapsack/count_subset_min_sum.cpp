// count the number of subset with given sum of difference is diff
#include<bits/stdc++.h>
using namespace std;

int count_of_subset_sum(int arr[],int sum,int n){
    int t[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0)
                t[i][j]=0;
            if(j==0)
                t[i][j]=1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j)
                t[i][j]=((t[i-1][j-arr[i-1]]+(t[i-1][j])));
            else 
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}


int count (int arr[],int n,int diff){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if((sum+diff) % 2 == 1 || sum < diff) return 0;
    int s=(diff+sum)/2;

    return count_of_subset_sum(arr,s,n);
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
    int diff;
    cout<<"Enter the difference: ";
    cin>>diff;
    int ans=count(arr,n,diff);
    cout<<"The number of subset with minimum difference is: "<<ans<<"\n";
    cout<<endl;
    }
    return 0;
}