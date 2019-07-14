#include<bits/stdc++.h>
int main()
{
    int k;
    std::cin>>k;
    double a=0.64;
    int m=100010;
    std::cout<<floor(m*(k*a-floor(k*a)))<<std::endl;
}
