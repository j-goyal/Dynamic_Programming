//Determine the maximum value obtainable by cutting up the rod and selling the pieces

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*int cutRod(int price[], int n) 
{ 
   if (n <= 0) 
     return 0; 
   int max_val = INT_MIN; 
  
   // Recursively cut the rod in different pieces and compare different  
   // configurations 
   for (int i = 0; i<n; i++) 
         max_val = max(max_val, price[i] + cutRod(price, n-i-1)); 
  
   return max_val; 
} 


int cutRod(int price[], int n) //dp 
{ 
   int val[n+1]; 
   val[0] = 0; 
   int i, j; 
  
   // Build the table val[] in bottom up manner and return the last entry 
   // from the table 
   for (i = 1; i<=n; i++) 
   { 
       int max_val = INT_MIN; 
       for (j = 0; j < i; j++) 
         max_val = max(max_val, price[j] + val[i-j-1]); 
       val[i] = max_val; 
   } 
  
   return val[n]; 
} 
*/
int rod_cut(int len[], int price[], int rodlen, int n)  //recursion
{
	if(n==0)
		return 0;
	
	if(len[n-1]<=rodlen)
		return max(price[n-1]+rod_cut(len,price,rodlen-len[n-1],n), rod_cut(len,price,rodlen,n-1));
	
	else
		return rod_cut(len,price,rodlen,n-1);
}

int main()
{
	int rodlen=8;
	int n=8;
	int len[]={1,2,3,4,5,6,7,8};
	int price[]={1,5,8,9,10,17,17,20};
	
	cout<<rod_cut(len,price,rodlen,n);
	return 0;  

}
