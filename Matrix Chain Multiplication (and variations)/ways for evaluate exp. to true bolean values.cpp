/*
Given a boolean expression with following symbols.
Symbols
    'T' --- true 
    'F' --- false 
And following operators filled between symbols
Operators
    &   ---boolean AND
    |   --- boolean OR
    ^   --- boolean XOR 
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

*/
#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

//int dp[1001][1001];
unordered_map<string,int> mp;      // map because 3 variables are changing (also make 3d matrix)

int solve(string a, int i, int j, bool isTrue)
{
	if(i>j)
		return 0;
		
	if(i==j)                  // if you want true then return true, if you want false then return true;
	{
		if(isTrue==true)
			return a[i]=='T';
		else
			return a[i]=='F';
	}
		
	int k;
	int ans=0;
	for(k=i+1;k<=j-1;k=k+2)              // k points operator
	{
		int lt=solve(a,i,k-1,true);       // left and right subproblems ways for them to be true or false
		int lf=solve(a,i,k-1,false);
		int rt=solve(a,k+1,j,true);
		int rf=solve(a,k+1,j,false);
		
		if(a[k]=='&')            // no. of ways for and expression to be true or false
		{
			if(isTrue==true)
				ans = ans + lt*rt;
			else
				ans = ans + lt*rf + lf*rt + lf*rf;
		}
		
		else if(a[k]=='|')
		{
			if(isTrue==true)
				ans = ans + lt*rf + lf*rt + lt*rt;
			else
				ans = ans + lf*rf;
		}
		
		else if(a[k]=='^')
		{
			if(isTrue==true)
				ans = ans + lt*rf + lf*rt;
			else
				ans = ans + lf*rf + lt*rt;
		}
		
	}
	
	return ans;
}


int solve_DP(string a, int i, int j, bool isTrue)
{
	if(i>j)
		return 0;
		
	if(i==j)                  // if you want true then return true, if you want false then return true;
	{
		if(isTrue==true)
			return a[i]=='T';
		else
			return a[i]=='F';
	}
		
	string temp = to_string(i);
	temp.append(" ");
	temp.append(to_string(j));
	temp.append(" ");
	temp.append(to_string(isTrue));
	
	if(mp.find(temp)!=mp.end())
		return mp[temp];
		
	int k;
	int ans=0;
	for(k=i+1;k<=j-1;k=k+2)              // k points operator
	{
		int lt=solve_DP(a,i,k-1,true);       // left and right subproblems ways for them to be true or false
		int lf=solve_DP(a,i,k-1,false);
		int rt=solve_DP(a,k+1,j,true);
		int rf=solve_DP(a,k+1,j,false);
		
		if(a[k]=='&')            // no. of ways for and expression to be true or false
		{
			if(isTrue==true)
				ans = ans + lt*rt;
			else
				ans = ans + lt*rf + lf*rt + lf*rf;
		}
		
		else if(a[k]=='|')
		{
			if(isTrue==true)
				ans = ans + lt*rf + lf*rt + lt*rt;
			else
				ans = ans + lf*rf;
		}
		
		else if(a[k]=='^')
		{
			if(isTrue==true)
				ans = ans + lt*rf + lf*rt;
			else
				ans = ans + lf*rf + lt*rt;
		}
		
	}
	
	return mp[temp]=ans;
}


int main()
{
	
    mp.clear();
	string a;
	cin>>a;      
	
	int n = a.length();
	cout<<solve(a,0,n-1,true)<<endl;
	cout<<solve_DP(a,0,n-1,true)<<endl;
	//cout<<solve_DP_opt(a,0,n-1)<<endl;

	
	return 0;  

}
