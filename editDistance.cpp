#include<bits/stdc++.h>

using namespace std;
#define gl(s)getline(cin,s)
#define mx 1000
string src="aeibcd",des="adeqijb";
int ed[mx][mx];
int l,r;

void init(){
	for(int i=0;i<1;i++)
		for(int j=0;j<=r;j++)ed[i][j]=j;

	for(int i=0;i<=l;i++)
		for(int j=0;j<1;j++)
			ed[i][j]=i;

}
void createEditDistance(){
	for(int i=1;i<=l;i++)
			for(int j=1;j<=r;j++)
			{
				if(src[i-1]==des[j-1])
				{
					ed[i][j]=min(min(ed[i][j-1]+1,ed[i-1][j]+1),ed[i-1][j-1]);
				}
				else{
					ed[i][j]=min(min(ed[i][j-1]+1,ed[i-1][j]+1),ed[i-1][j-1]+2);
				}
			}
}

void createLevenshteinDistance(){
	for(int i=1;i<=l;i++)
			for(int j=1;j<=r;j++)
			{
				if(src[i-1]==des[j-1])
				{
					ed[i][j]=min(min(ed[i][j-1]+1,ed[i-1][j]+1),ed[i-1][j-1]);
				}
				else{
					ed[i][j]=min(min(ed[i][j-1]+1,ed[i-1][j]+1),ed[i-1][j-1]+1);
				}
			}
}
void showTable(){

			for(int i=0;i<=l;i++){
				for(int j=0;j<=r;j++)
				{
					cout<<ed[i][j]<<" ";
				}
				cout<<endl;
			}

}
void operationCount(int i,int j){
	if(ed[i][j]==0)return;
	if(src[i-1]==des[j-1]){
		// cout<<src[i-1]<<" "<<des[j-1]<<endl;
		operationCount(i-1,j-1);
	}
	else{
		int mi=min(min(ed[i][j-1],ed[i-1][j]),ed[i-1][j-1]);

		if(mi==ed[i][j-1]){
			cout<<"insert "<<des[j-1]<<endl;
			operationCount(i,j-1);
		}
		else if(mi==ed[i-1][j]){
			cout<<"Delete "<<src[i-1]<<endl;
			operationCount(i-1,j);
		}
		else if(mi==ed[i-1][j-1]){
			cout<<"substitute "<<src[i-1]<<" -> "<<des[j-1]<<endl;//delete+insert
			operationCount(i-1,j-1);
		}
	}

}

int main(int argc, char const *argv[])
{
	gl(src);
	gl(des);

	 l=src.size();
	 r=des.size();
	
	
	 init();
	 // createEditDistance();
	 createLevenshteinDistance();
	 showTable();
	 // cout<<l<<" "<<r<<endl;
	  operationCount(l,r);
		




	
	return 0;
}