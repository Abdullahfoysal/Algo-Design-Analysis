#include<bits/stdc++.h>

using namespace std;

string L="abgkp",R="agfml";
#define mx 1000


int lcs[mx][mx];
bool visited[mx][mx];

void dfs(int i, int j)
{
	visited[i][j]=1;

	if(lcs[i][j]==0){
		cout<<"$";
		return;
	}

	if(lcs[i][j]==max(lcs[i][j-1],lcs[i-1][j]))
	{
		if(lcs[i][j]==lcs[i][j-1]) {if(!visited[i][j-1])dfs(i,j-1);}

 	     if(lcs[i][j]==lcs[i-1][j] &&!visited[i-1][j]) dfs(i-1,j);
		
		
	}
	else if(!visited[i-1][j-1]) {
		cout<<R[j-1];
		dfs(i-1,j-1);

	}

   // if(lcs[i][j]==lcs[i][j-1]) if(!visited[i][j-1])dfs(i,j-1);
   // if(lcs[i][j]==lcs[i-1][j]) if(!visited[i-1][j])dfs(i-1,j);
}

int main(int argc, char const *argv[])
{
	cin>>L>>R;
	// cout<<L<<R;
	int l=L.size(),r=R.size();
	for(int i=1;i<=l;i++){


		for(int j=1;j<=r;j++)
		{
			if(L[i-1]==R[j-1])
			{
				lcs[i][j]=lcs[i-1][j-1]+1;
				// cout<<lcs[i][j]<<" *";
			}
			else
			{
				lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
				// cout<<lcs[i][j]<<" $";
			}
		}
		
}
   cout<<lcs[l][r]<<endl;
   dfs(l,r);
	
	return 0;
}