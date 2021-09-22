#include<bits/stdc++.h>
using namespace std;


string rev(string x){
    reverse(x.begin(),x.end());
    return x;
}


int lcs(string x,int n){
    int m=n;
    string y =rev(x);
    int t[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
                t[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1])
                t[i][j]=1+(t[i-1][j-1]);
            else 
                t[i][j]=max(t[i][j-1],t[i-1][j]);
        }
    }
    return n-t[n][m];
}


int main(){
    int k;
    cin>>k;
    while(k--){
        string s1,s2;
        cout<<"Enter the first string : ";
        cin>>s1;
        int n=s1.length();
        int s= lcs(s1,n);
        cout<<s<<"\n";
    }
    return 0;
}


