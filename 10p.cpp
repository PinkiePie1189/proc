//10-p 2xOk,12 WA,6 TLE
#include<stdio.h>
FILE*fin=fopen("proc.in","r");
FILE*fout=fopen("proc.out","w");
long long  jobs[66000];
int main()
{
    long long N,K1,K2,P;
    fscanf(fin,"%lld%lld%lld",&N,&K1,&P);
    K2=N-K1;
    long long nrproc=1;
    while(K2>0)
    {
        if(jobs[nrproc]+2*nrproc<=2*(nrproc+1)+jobs[nrproc+1])
        {
            jobs[nrproc]+=2*nrproc;
        }
        else
        {
            nrproc++;
            jobs[nrproc]+=2*nrproc;
        }
        K2--;
    }
    nrproc=1;
        while(K1>0)
    {
        if(jobs[nrproc]+nrproc<=(nrproc+1)+jobs[nrproc+1])
        {
            jobs[nrproc]+=nrproc;
        }
        else
        {
            nrproc++;
            jobs[nrproc]+=nrproc;
        }
        K1--;
    }
    long long ans=0;
    for(long long i=1;i<=P;i++)
    {
        //prlong longf("%lld ",jobs[i]);
        ans+=jobs[i];
    }
    fprintf(fout,"%lld",ans);
}
