bool adj[9][9];     // adjacency matrix
int visit[9];       // 記錄DFS遍歷過的點
int order[9], n;    // 儲存一個合理的排列順序
 
bool cycle;         // 記錄DFS的過程中是否偵測到環
 
void DFS(int s)
{
    // back edge，有環。
    if (visit[s] == 1) {cycle = true; return;}
    // forward edge、cross edge。
    if (visit[s] == 2) return;
 
    visit[s] = 1;
    for (int t=0; t<9; ++t)
        if (adj[s][t])
            DFS(t);
    visit[s] = 2;
 
    order[n--] = s;     // 記錄合理的排列順序
}
 
void topological_ordering()
{
    // 初始化
    for (int i=0; i<9; i++) visit[i] = 0;
    cycle = false;
    n = 9-1;
 
    // 進行DFS
    for (int s=0; s<9; ++s)
        if (!v[s])
            DFS(s);
 
    // 輸出結果
    if (cycle)
        cout << "圖上有環";
    else
        // 印出一個合理的排列順序
        for (int i=0; i<9; ++i)
            cout << order[i];
}
