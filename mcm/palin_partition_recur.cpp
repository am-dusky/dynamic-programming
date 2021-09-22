#include<bits/stdc++.h>
using namespace std;

bool isPalindrone(string s,int i,int j){
    if(i>=j)
        return true;
    while(i<j){
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solve(string s,int i,int j){
    if(i>=j)
        return 0;
    if(isPalindrone(s,i,j))
        return 0;
    int mn=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp=1+solve(s,i,k)+solve(s,k+1,j);
        if(temp<mn)
            mn=temp; 
    }
    return mn;
}

int main(){
    int k;
    cin>>k;
    while(k--){
        string s;
        cout<<"Enter the string: ";
        cin>>s;
        cout<<"The min number of partitons are:  "<<solve(s,0,s.length()-1);
        cout<<"\n";
    }
    return 0;
}