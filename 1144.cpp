#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> v(N + 1, 0);
    for (int i = 0; i < N; ++i)
    {
        int k;
        cin >> k;
        if (k <= N && k >= 1)
        {
            v[k] = 1;
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        if (v[i] == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << N + 1 << endl;
    return 0;
}