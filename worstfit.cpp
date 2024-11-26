#include <bits/stdc++.h>
using namespace std;
void worst_fit(vector<int> v1, vector<int> v2)
{
    map<int, int> mp;
    int n = v1.size();
    int m = v2.size();
    sort(v2.begin(), v2.end());
    for (int i = 0; i < n; i++)
    {
        int idx_j = -1;
        for (int j = m - 1; j >= 0; j--)
        {
            if (v1[i] < v2[j])
            {
                idx_j = j;
                break;
            }
        }
        if (idx_j == -1)
        {
            mp[v1[i]] = -1;
        }
        else
        {
            mp[v1[i]] = v2[idx_j];
            v2[idx_j] -= v1[i];
        }
    }
    cout << "\tWORST FIT ALGORITHM" << endl;
    cout << "PROCESS SIZE" << setw(10) << " MEMORY ALLOCATED" << endl;
    for (auto it : mp)
    {
        cout << it.first << setw(15) << it.second << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the number of processes" << endl;
    cin >> n;
    vector<int> v1;
    cout << "Enter the process size " << endl;
    int inp1 = 0;
    int inp2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> inp1;
        v1.push_back(inp1);
    }
    int m;
    cout << "Enter the number of spaces available in the memory" << endl;
    cin >> m;
    vector<int> v2;
    cout << "Enter the size for each memory" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> inp2;
        v2.push_back(inp2);
    }
    worst_fit(v1, v2);
}