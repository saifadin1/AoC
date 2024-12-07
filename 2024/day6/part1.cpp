#include <bits/stdc++.h>
#include "helpers.h"
#define int long long

using namespace std;

int32_t main() {
    std::vector<std::string> input = readInput("../2024/day6/input.txt");

    int n = input.size();
    int m = input[0].size();


    // 0 - up, 1 - right, 2 - down, 3 - left

    array<int, 3> st;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(input[i][j] == '^'){
                st = {i, j, 0};
                break;
            }
        }
    }

    int ans = 1;
    queue<array<int, 3>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    q.push(st);

    auto valid = [&](int i, int j){
        return i<n && i>=0 && j<m && j>=0;
    };

    function<array<int,3>(int ,int, int)> findDir = [&](int r , int c , int dir) -> array<int, 3>{
        if(dir == 0){
            if(!valid(r-1, c)){
                return {r-1, c, 0};
            } else if(input[r-1][c] == '#'){
                return findDir(r, c, 1);
            } else {
                return {r-1, c, 0};
            }
        } else if(dir == 1){
            if(!valid(r, c+1)){
                return {r, c+1, 1};
            } else if(input[r][c+1] == '#'){
                return findDir(r, c, 2);
            } else {
                return {r, c+1, 1};
            }
        } else if(dir == 2){
            if(!valid(r+1, c)){
                return {r+1, c, 2};
            } else if(input[r+1][c] == '#'){
                return findDir(r, c, 3);
            } else {
                return {r+1, c, 2};
            }
        } else {
            if(!valid(r, c-1)){
                return {r, c-1, 3};
            } else if(input[r][c-1] == '#'){
                return findDir(r, c, 0);
            } else {
                return {r, c-1, 3};
            }
        }
    };

    while(q.size()){
        auto [i, j, dir] = q.front();
        q.pop();

        if(!valid(i, j)){
            continue;
        }


        int ni , nj;
        auto neww = findDir(i, j, dir);
        ni = neww[0];
        nj = neww[1];
        

        q.push(neww);
        if(valid(ni , nj) && !vis[ni][nj]){
            vis[ni][nj] = true;
            ans++;
        }
    }


    cout << ans << '\n';

    return 0;
}
