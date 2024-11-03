#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> randomG(int n)
{
    vector<vector<int>> adjmatr(n, vector<int>(n, 0));
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int randomValue = rand() % 2;
            adjmatr[i][j] = randomValue;
            adjmatr[j][i] = randomValue;
        }
    }

    return adjmatr;
}

bool tree(const vector<vector<int>>& adjmatr)
{
    int n = adjmatr.size();
    int edgeCount = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            edgeCount += adjmatr[i][j];
        }

    }
    if (edgeCount != n - 1) 
    {
        return false;
    }
    vector<bool> visited(n, false);
    vector<int> stack;
    stack.push_back(0);
    visited[0] = true;
    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();
        for (int v = 0; v < n; v++) {
            if (adjmatr[u][v] && !visited[v]) 
            {
                visited[v] = true;
                stack.push_back(v);
            }
        }
    }
    for (int i = 0; i < n; i++) 
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cout << "N=" << endl;
    cin >> n;
    vector<vector<int>> adjmatr = randomG(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjmatr[i][j] << ",";
        }
        cout << endl;
    }
    bool isTreeResult = tree(adjmatr);
    cout << "Is the graph a tree? " << (isTreeResult ? "Yes" : "No") << endl;
    return 0;
}
