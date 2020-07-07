// sort pair acc. to first argument then apply LIS on second value of pair to avoid clash

#include <bits/stdc++.h> 
using namespace std; 
  
// north-south coodinates 
// of each City Pair 
struct CityPairs 
{ 
    int north, south; 
}; 
  
// comparison function to sort 
// the given set of CityPairs 
bool compare(struct CityPairs a, struct CityPairs b) 
{ 
    if (a.north == b.north) 
        return a.south < b.south; 
    return a.north < b.north; 
} 
  
// function to find the maximum number 
// of bridges that can be built 
int maxBridges(struct CityPairs values[], int n) 
{ 
    int lis[n]; 
    lis[0]=1; 
          
    sort(values, values+n, compare); // sort values with first key then apply LIS on second key
    for(int i=0;i<n;i++)
    {
    	cout<<values[i].north<<" "<<values[i].south<<" ";
	}
    // logic of longest increasing subsequence 
    // applied on the northern coordinates 
    for(int i=1;i<n;i++)  
	{
		lis[i]=1;
		for(int j=0;j<i;j++)
		{
			if(values[j].south < values[i].south)
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
    struct CityPairs values[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}}; 
    int n = 4; 
    cout << "Maximum number of bridges = " 
             << maxBridges(values, n);     
    return 0; 
}  
