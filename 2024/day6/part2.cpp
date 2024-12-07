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

    int ans = 0;
    queue<array<int, 3>> q;
    vector<vector<int>> vis(n , vector<int>(m , -1));
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

    auto tryRedirect = [&](array<int,3> old , array<int,3> cur){
        if(old == cur) return false;
        auto next = findDir(cur[0] , cur[1], cur[2]);

        if(!valid(next[0] , next[1]))
            return false;

            // cout << "YES\n";

        char temp = input[next[0]][next[1]]; 
        input[next[0]][next[1]] = '#';
        next = findDir(cur[0] , cur[1], cur[2]);
        input[next[0]][next[1]] = temp;
        
        cout << old[0] << ' ' << old[1] << ' ' << old[2] << '\n';
        cout << next[0] << ' ' << next[1] << ' ' << next[2] << "\n\n";



        return next == findDir(old[0] , old[1] , old[2]);
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
        dir = neww[2];
        

        q.push(neww);
        if(valid(ni , nj) && vis[ni][nj] == -1){
            vis[ni][nj] = dir;
        } else if (valid(ni , nj)) {
            // cout << ni << ' ' << nj << ' ' << dir << ' ' << '\n';
            ans += tryRedirect({ni , nj , vis[ni][nj]} , {ni , nj , dir});
        }
    }

    cout << ans << '\n';
    return 0;
}
