#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include <iomanip>

using namespace std;
#define mx 1000
int lis[mx];
int arr[mx];

int binary_upper(int l,int r,int value)
{
	int m=(l+r)/2;

	if(l<r)
	{
		if(lis[m]==value)
		{
		  if(m+1<=r && lis[m+1]!=value) return m;
		  else return binary_upper(m+1,r,value);
		}

		if(value<lis[m]) return binary_upper(l,m-1,value);
		return binary_upper(m+1,r,value);


	}
}

int main(int argc, char const *argv[])
{
	// memset(lis,-1,sizeof(lis));
	for(int i=0;i<mx;i++)lis[i]=1;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j])
			{
				if(lis[j]+1>lis[i])
				{
				  lis[i]=max(lis[j]+1,lis[i]);

				}
			}
		}
	}
	int ma=*max_element(lis,lis+n);
	cout<<ma<<endl;
	for (int i = 0; i < n; ++i)
	{	
		
		int k=binary_upper(i,n-1,lis[i]);
		i=k;
		cout<<arr[k]<<" ";
		if(lis[k]==ma)break;
	}
	// cout<<binary_upper(0,8,2);

	
	return 0;
}





