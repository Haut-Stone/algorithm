/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-20 21:54:35
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-20 21:56:18
*/

//f(x) = sigma{g(d)}其中x % d == 0，则g(x) = sigma{mu(d) * f(x/d)}
//f(x) = sigma{g(d)}其中d % x == 0，则g(x) = sigma{mu(d/x) * f(d)}

//莫比乌斯反演中mu(x) = 

//1   {x中含有偶数个不同的质因子}
//-1  {x中含有奇数个不同的质因子}
//0   {其他情况}

void Moblus()
{
    memset(check,false,sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for(int i = 2; i <= MAXN; i++)
    {
        if( !check[i] )
        {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot; j++)
        {
            if(i * prime[j] > MAXN) break;
            check[i * prime[j]] = true;
            if( i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
} 