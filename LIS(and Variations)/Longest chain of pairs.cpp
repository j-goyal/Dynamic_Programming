// You are given n pairs of numbers. In every pair, the first number is always smaller than the second number. 
// A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. 
// Find the longest chain which can be formed from a given set of pairs.

#include <bits/stdc++.h> 
using namespace std; 
  

struct Pairs 
{ 
    int x, y; 
}; 
  
// comparison function to sort 
// the given set of CityPairs 
bool compare(struct Pairs a, struct Pairs b) 
{ 
    if (a.x == b.x) 
        return a.y < b.y; 
    return a.x < b.x; 
} 
  

int maxPairs(struct Pairs values[], int n) 
{ 
    int lis[n]; 
    lis[0]=1; 
          
    sort(values, values+n, compare); // sort values with first key then apply LIS on whole pair
    for(int i=0;i<n;i++)
    {
    	cout<<"("<<values[i].x<<","<<values[i].y<<")"<<" ";
	}
    
    for(int i=1;i<n;i++)  
	{
		lis[i]=1;
		for(int j=0;j<i;j++)
		{
			if(values[j].y < values[i].x)
				lis[i]=max(lis[i], lis[j]+1);
		}
	}
          
          
    int max = lis[0]; 
    for (int i=1; i<n; i++)
	{ 
        if (max < lis[i]) 
            max = lis[i]; 
	}    
             
    return max;         
} 
  
// Driver program to test above 
int main() 
{ 
    struct Pairs arr[] = {{5, 24}, {15, 25},{27, 40}, {50, 60}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Maximum number of pairs = " 
             << maxPairs(arr, n);     
    return 0; 
}  
