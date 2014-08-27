#include <stdio.h>

// drop ball from a building which has 100 floors
// choose a floor to drop it
// using minimum balls k to testify which floor is safe
// i.e from k'th floor shall not break but from k+1's floor shall break

int dp[101] = { 0 };  
  
void solve()  
{  
    int i , j , k;  
    for(i = 2 ; i < 101 ; ++i)  
    {  
        dp[i] = i;  
        for(j = 1 ; j < i ; ++j)  
        {  
            k = (j>=(1 + dp[i-j])) ? j : (1 + dp[i-j]);  
            if(dp[i] > k)  
                dp[i] = k;  
        }  
    }  
}  
  
int main(void)  
{  
    dp[0] = 0 , dp[1] = 1;  
    solve();  
    printf("%d\n",dp[100]);  
    getchar();
    getchar();
    return 0;  
}  