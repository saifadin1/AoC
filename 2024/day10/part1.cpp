#include <bits/stdc++.h>
#include "helpers.h"
#define int long long

using namespace std;

int32_t main() {
    std::vector<std::string> g = readInput("../2024/day10/input.txt");

    int n = g.size();
    int m = g[0].size();

    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {1, -1, 0, 0};

    vector<vector<int>> vis(n , vector<int>(m, 0)); 
    

    auto valid = [&](int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    };


    int ans = 0;

    function<set<pair<int,int>>(int,int)> dfs = [&](int i , int j)->set<pair<int,int>>{
        set<pair<int,int>> s;
        if(g[i][j] == '9'){
            s.insert({i, j});
            return s;
        }

        for(int k = 0; k < 4; k++){
            int x = i + dx[k];
            int y = j + dy[k];

            if(valid(x, y) && g[x][y] - g[i][j] == 1){
                auto temp = dfs(x, y);
                s.insert(temp.begin(), temp.end());
            }
        }

        return s;
    };

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(g[i][j] == '0'){
                auto temp = dfs(i, j);
                ans += temp.size();
            }
        }
    }


    cout << ans << '\n';

    

    return 0;
}
