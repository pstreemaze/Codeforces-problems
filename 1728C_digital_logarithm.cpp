#include <bits/stdc++.h>

using namespace std;

int f(int x)
{
    int ans = 0;
    while(x)
    {
        ans++;
        x/=10;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int64_t n;
        cin >> n;
        int64_t a[n],b[n];
        for(int i = 0;i < n;++i)
        {
            cin >> a[i];
        }
        for(int i = 0;i < n;++i)
        {
            cin >> b[i];
        }
        multiset<int> ax;
        multiset<int> bx;
        for(int i = 0;i < n;++i)
        {
            ax.insert(-a[i]);
        }
        for(int i = 0;i < n;++i)
        {
            bx.insert(-b[i]);
        }
        int res = 0;
        while(ax.size() || bx.size())
        {
            int c = -(*ax.begin());
            ax.erase(ax.begin());
            int c2 = -(*bx.begin());
            bx.erase(bx.begin());
            if(c != c2)
            {
                if(c > c2)
                {
                    c = f(c);
                }
                else
                    c2 =f(c2);
                ax.insert(-c);
                bx.insert(-c2);
                res++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}


