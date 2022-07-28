#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N (int)1e5+10
#define M (int)1e5
long long a[N],x,res[N],base[N],tmp[N];
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cout<<"High-precision Power Calc  Copyright (C) 2022 Wang Jianlin\n";

    res[0]=1;
    base[0]=1;
    int resl=1;
    int basel=1;
    int tmpl=1;
    int al=1;

    cin>>base[0];
    cin>>x;

    while(x){
        if(x&1){
            //res*=base;
            memset(tmp,0,sizeof tmp);
            //tmp[0]=0;
            tmpl=1;
            for(int i=0;i<basel;i++){
                for(int j=0;j<resl;j++){
                    tmp[i+j]+=base[i]*res[j];
                    if(tmp[i+j]>=M){
                        tmp[i+j+1]+=tmp[i+j]/M;
                        tmp[i+j]%=M;
                    }
                }
            }
            for(int i=0;i<basel+basel+1;i++){
                if(tmp[i]>=M){
                    tmp[i+1]+=tmp[i]/M;
                    tmp[i]%=M;
                }
            }
            for(int i=basel+resl+1;i>=0;i--){
                if(tmp[i-1]!=0){
                    tmpl=i;
                    break;
                }
            }
            memset(res,0,sizeof res);
            resl=tmpl;
            for(int i=0;i<tmpl;i++){
                res[i]=tmp[i];
            }
        }
        //base*=base;
        memset(tmp,0,sizeof tmp);
        //tmp[0]=1;
        tmpl=1;
        for(int i=0;i<basel;i++){
            for(int j=0;j<basel;j++){
                tmp[i+j]+=base[i]*base[j];
                if(tmp[i+j]>=M){
                    tmp[i+j+1]+=tmp[i+j]/M;
                    tmp[i+j]%=M;
                }
            }
        }
        for(int i=0;i<basel+basel+1;i++){
            if(tmp[i]>=M){
                tmp[i+1]+=tmp[i]/M;
                tmp[i]%=M;
            }
        }
        for(int i=basel+basel+1;i>=0;i--){
            if(tmp[i-1]!=0){
                tmpl=i;
                break;
            }
        }
        memset(base,0,sizeof base);
        basel=tmpl;
        for(int i=0;i<tmpl;i++){
            base[i]=tmp[i];
        }
        x>>=1;
    }

    printf("%lld",res[resl-1]);
    for(int i=resl-2;i>=0;i--){
        printf("%04lld",res[i]);
    }
    
    getchar();

    return 0;
}
