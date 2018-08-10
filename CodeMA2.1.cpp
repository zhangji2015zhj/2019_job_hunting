#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    vector<int> a, b;
    int64 sum = 0;
    a.resize(n);
    b.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> b[i];
        int minnum = min(a[i], b[i]);
        if (minnum != 0)
        {
            a[i] -= minnum;
            b[i] -= minnum;
        }
    }
    int pos = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            if (a[i] > b[i])
            {
                int step = a[i] - b[i];
                pos = step;
                sum += pos * i;
            } //(a[i]<b[i])
            else
            {
                int step = b[i] - a[i];
                if (pos != 0)
                {
                    int minnum = min(step, pos);
                    step -= minnum;
                    pos -= minnum;
                    sum += minnum * i;
                }

                for (size_t j = i + 1; j <n && step > 0; j++)
                {
                    if (a[j] != 0)
                        if (a[j] >= step)
                        {
                            sum += (j + i) * step;
                            a[j] -= step;
                            // b[i] += step;
                            step = 0;
                            break;
                        }
                        else
                        {
                            sum += a[j] * (j + i);
                            //b[i] += a[j];
                            step -= a[j];
                            a[j] = 0;
                        }
                }
            }
        }
    }
    cout << sum;

    return 0;
}
