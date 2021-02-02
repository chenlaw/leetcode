int findSet(vector<int>& bc, int s) {
    if (s == bc[s])
        return s;
    else
        bc[s] = findSet(bc, bc[s]);
    return bc[s];
}
void unionSet(vector<int>& bc, int a, int b) {
    int aa = findSet(bc, a);
    int bb = findSet(bc, b);
    if (aa != bb) {
        bc[aa] = bb;
    }
}
int numIslands(vector<vector<char>>& grid) {
    int l = grid.size();
    int n = grid[0].size();
    vector<int> bc(l * n);
    for (int i = 0; i < l * n; i++) {
        bc[i] = i;
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n - 1;) {
            if (grid[i][j + 1] == '0') {
                j = j + 2;
            }
            else if (grid[i][j] == '0') {
                j++;
            }
            else {
                unionSet(bc, i * n + j, i * n + j + 1);
                j++;
            }
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < l - 1;) {
            if (grid[i + 1][j] == '0')
                i = i + 2;
            else if (grid[i][j] == '0')
                i++;
            else {
                unionSet(bc, i * n + j, (i + 1) * n + j);
                i++;
            }
        }
    }
    unordered_set<int> s;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') s.insert(findSet(bc, i * n + j));
        }

    }
    return s.size();
}