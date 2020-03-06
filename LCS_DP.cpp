#include<bits/stdc++.h>
using namespace std;

int dp[50][50];
char track[50][50];

int main()
{
    string a = "ABCBDAB", b ="BDCABA";
    // string a = "stone",b="longest";
    // string a = "bd", b ="abcd";
    int n = a.size();
    int m = b.size();
    // cin >> a >> b;
    a = '0' + a;
    b = '0' + b;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                track[i][j] = 'd';
            }

            else if( dp[i-1][j] >= dp[i][j-1]) 
            {
                dp[i][j] = dp[i-1][j];
                track[i][j] = 'u';
            }

            else
            {
                dp[i][j] = dp[i][j-1] ;
                track[i][j] = 'l';
            }
        }
    cout << dp[n][m] << endl; // Answer


    //Print LCS
    int cnt=0;
    for(int i=n;i>=0;){
        for(int j=m;j>=0;){
            if(track[i][j] == 'l')
                j--;

            else if(track[i][j] == 'u')
                i--;

            else if (track[i][j] == 'd'){
                cout << b[j]<< " ";
                i--;j--;
                cnt++;
            }

            else {i--;j--;}

        }
    }
    cout << endl;
    return 0;
}
