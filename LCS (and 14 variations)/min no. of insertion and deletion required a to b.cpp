/* Minimum number of deletions and insertions to transform one string into another
Input : str1 = "geeksforgeeks", str2 = "geeks"
Output : Minimum Deletion = 8
        Minimum Insertion = 0 

*******APPROACH**********
str1 = heap
str2 = pea
LCS = ea
***str1(heap) -----> LCS(ea)  ------> str2(pea)
              (del 2)           (insert 1)
*/


#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int dp[1001][1001];

void min_steps_bottom_up_DP(string a, string b, int n, int m)         // bottom up
{
	//int dp[n+1][m+1];
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
				
			else if(a[i-1]==b[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			
			else if(a[i-1]!=b[j-1])
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	

	int len = dp[n][m];   // length of LCS
	
	cout<<"Min no. of deletions required is = "<<n-len<<endl;
	cout<<"Min no. of insertions required is = "<<m-len<<endl;
}


int main() 
{ 

	string a,b;
	cin>>a>>b;
	//getline(cin,a);
	//getline(cin,b);
	
	int n = a.length();
	int m = b.length();
	
	memset(dp,-1,sizeof(dp));
	
	min_steps_bottom_up_DP(a,b,n,m);
	
	return 0;

}
