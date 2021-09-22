#include<bits/stdc++.h>
using namespace std;

int lcs(string x,string y,int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(x[n-1]==y[m-1])
        return 1+lcs(x,y,n-1,m-1);
    else 
        return max(lcs(x,y,n,m-1),lcs(x,y,n-1,m));
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cout<<"Enter the first string : ";
        cin>>s1;
        cout<<"Enter the second string : ";
        cin>>s2;
        int m = s1.length(); 
        int n=s2.length(); 
        int s= lcs(s1,s2,m,n);
        cout<<s<<"\n";
    }
    return 0;
}