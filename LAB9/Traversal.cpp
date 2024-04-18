#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
using namespace std;

void dfs(vector<vector<int>> adjList, int startNode, int *visited)
{
    stack<int> st;
    st.push(startNode);
    visited[startNode] = true;

    while (!st.empty())
    {
        int focusNode = st.top();
        int i = 0;
        while (true)
        {
            // adjList [focusedNode] [i]
            if (visited[adjList[focusNode][i] == 0])
            {
                visited[adjList[focusNode][i]] == 1;
                st.push(adjList[focusNode][i]);
                focusNode = st.top();
                cout << focusNode << " ";
                i = 0;
            }
            else
            {
                i++;
            }
            if (i >= adjList[focusNode].size())
            {
                break;
            }
        }
        st.pop();
    }
}

void bfs(vector<vector<int>> adjList, int startNode, int *visited)
{
    queue<int> qq;
    qq.push(startNode);
    visited[startNode] = true;
    int focusNode = qq.front();
    cout << focusNode << " ";
    while (!qq.empty())
    {
        focusNode = qq.front();
        qq.pop();
        cout << focusNode << " ";
        int i = 0;
        while (true)
        {
            // adjList [focusedNode] [i]
            if (visited[adjList[focusNode][i] == 0])
            {
                visited[adjList[focusNode][i]] == 1;
                qq.push(adjList[focusNode][i]);
                cout << focusNode << " ";
                i = 0;
            }
        }
    }
}

int main()
{
    int nNode;
    int pEdge;
    cin >> nNode >> pEdge;
    vector<vector<int>> adjList;
    for (int i = 0; i < pEdge; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        adjList.push_back({node1, node2});
        adjList.push_back({node2, node1});
    }

    dfs(adjList, startNode, visited);
    // reset  visited
    bfs(adjList, startNode, visited);

    return 0;
}