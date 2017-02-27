#include<bits/stdc++.h>
using namespace std;
#define d 1000000007
#define phi 500000001
#define ma 200010
long long int infact[ma+1];
long long int fact[ma+1];
long long powfi(long long int a, long long int b, long long int m)
{
    long long c=1LL;
    while(b>0)
    {
        if(b%2==1)
        c=(c*a)%m;
        a=(a*a)%m;
        b=b/2;
    }
    return c;
}
void preinfact()
{
    infact[0]=1LL;
    long long int i;
    for(i=1;i<ma;i++)
    {
        infact[i]=(infact[i-1]*((powfi(i,phi,d-1))))%(d-1);
    }
}

void factorial()
{
    long long int i;
    fact[0]=1LL;
    for(i=1;i<ma;i++)
    fact[i]=(fact[i-1]*i)%(d-1);

}
int main()
{
    factorial();
    preinfact();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int a,b,n;
        scanf("%lld %lld %lld",&a,&b,&n);
        long long int ans;
    	 long long int k=2*n;
    	 long long int c=(fact[k]*((infact[n]*infact[n])%(d-1)))%(d-1);
    	 long long int res=powfi(c,b,d-1);
    	 ans=powfi(a,res,d);

        printf("%lld\n",ans);
    }
}
