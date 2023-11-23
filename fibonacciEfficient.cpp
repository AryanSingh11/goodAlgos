#include<bits/stdc++.h>
using namespace std;

//theory: If we n times multiply the matrix M = {{1, 1},{1, 0}} 
//to itself (in other words calculate power(M, n )), 
//then we get the (n+1)th Fibonacci number as 
//the element at row and column (0, 0) in the resultant matrix.

const int mod=1e9+7;
#define ll long long

void multiply(ll f[2][2],ll m[2][2])
{
    ll a=(((f[0][0]*m[0][0])%mod)+((f[0][1]*m[1][0])%mod))%mod;
    ll b=(((f[0][0]*m[0][1])%mod)+((f[0][1]*m[1][1])%mod))%mod;
    ll c=(((f[1][0]*m[0][0])%mod)+((f[1][1]*m[1][0])%mod))%mod;
    ll d=(((f[1][0]*m[0][1])%mod)+((f[1][1]*m[1][1])%mod))%mod;
    f[0][0]=a;
    f[0][1]=b;
    f[1][0]=c;
    f[1][1]=d;
}

void power(ll f[2][2],int n)
{
  if(n==0 || n==1)return;
  ll m[2][2]={{1,1},{1,0}};
  power(f,n/2);
  multiply(f,f);
  if(n%2!=0)multiply(f,m);
}

int fib(int n)
{
  if(n==1)return 1;
  ll f[2][2]={{1,1},{1,0}};
  power(f,n-1);
  return f[0][0];
}

int main(){
    //enter the nth fibo you want to find
    int n;
    cout<<"enter the nth fibo you want to find"<<endl;
    cin>>n;
    cout<<fib(n)<<endl;

}