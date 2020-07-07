/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings.
To scramble the string, we may choose any non-leaf node and swap its two children.
Check if 2 given strings are scrambled or not.
*/

#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

bool isScrambled(string a, string b)
{
	int n=a.length();
	int m=b.length();
	
	if(n!=m)
		return false;
	
	if(n==0 && m==0)
		return true;
		
	if(a.compare(b)==0)
		return true;
	
	
	bool flag = false;
	for(int i=1;i<=n-1;i++)
	{
		if((isScrambled(a.substr(0,i), b.substr(n-i,i)) && isScrambled(a.substr(i,n-i), b.substr(0,n-i)))) ///swap
		{
			flag=true;
			break;
		}
		
		if((isScrambled(a.substr(0,i), b.substr(0,i)) && isScrambled(a.substr(i,n-i), b.substr(i,n-i)))) //no swap
		{
			flag=true;
			break;
		}
	}
	
	return flag;
}

int main()
{

	string a,b;
	cin>>a>>b;      
	
	int n = a.length();
	cout<<isScrambled(a,b)<<endl;
	//cout<<isScrambled_DP(a,b)<<endl;
	//cout<<isScrambled_DP_opt(a,b)<<endl;

	
	return 0;  

}
