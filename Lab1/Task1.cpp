#include<bits/stdc++.h>

using namespace std;
struct Word{
    string str="";
    int count=0;
};

#define mx 100
Word word[mx];
int ArraySize=mx;

int CreateKey(string ss){

    int key=0;
    for(int i=0;i<ss.size();i++)
    {
        if(isupper(ss[i]))
        key+=ss[i]-'A';
        else key+=ss[i]-'a';

    }
    return key%ArraySize;

}

void GenerateDivisionHash(string ss){

    int key=CreateKey(ss);

    if(word[key].count==0)
    {
        word[key].str=ss;
         word[key].count++;

    }
    else if( word[key].str==ss) word[key].count++;
    else{
        for(int i=key+1;i!=key;i++)
        {
           if(i>=ArraySize) i=0;

            if(word[i].count==0)
            {
                word[i].str=ss;
                 word[i].count++;
                 break;
            }
            else if( word[i].str==ss) {
                    word[i].count++;
                    break;
            }

        }
    }

}

int SearchWordCount(string ss,int key){
    if(word[key].str==ss)return word[key].count;

    for(int i=key+1;i!=key;i++){
            if(i>=ArraySize)i=0;

            if(word[i].str==ss) return word[i].count;

    }
    return -1; //nai kintu


}

void init()
{
    for(int i=0;i<mx;i++)word[i].count=0;

}
int main(){

    ///using Division method
    ///Unique word count


    int wordCount=0;

     init();
     string s,a;
     ///input string line
    getline(cin,s);
    for(int i=0;i<s.size();i++)if(s[i]==' ')wordCount++;

    ArraySize=wordCount+1;
    stringstream ss(s);

    while(ss>>a)
    {

        GenerateDivisionHash(a);


    }

    ///unique word count
    int unique=0;
    for(int i=0;i<ArraySize;i++)if(word[i].count>0) cout<<word[i].str<<endl,unique++;
    cout<<unique<<endl;





return 0;
}
