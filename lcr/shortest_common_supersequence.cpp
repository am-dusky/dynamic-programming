//find the length of shortest string that has both x,y

#include<bits/stdc++.h>
using namespace std;

int lcs(string x,string y,int n,int m){
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
    return (m+n-t[n][m]);
}


int main(){
    int k;
    cin>>k;
    while(k--){
        string s1,s2;
        cout<<"Enter the first string : ";
        cin>>s1;
        cout<<"Enter the second string : ";
        cin>>s2;
        int n=s1.length();
        int m=s2.length();
        int s= lcs(s1,s2,n,m);
        cout<<s<<"\n";
    }
    return 0;
}