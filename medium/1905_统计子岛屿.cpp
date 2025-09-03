/*
给你两个 m x n 的二进制矩阵 grid1 和 grid2 ，它们只包含 0 （表示水域）和 1 （表示陆地）。
一个 岛屿 是由 四个方向 （水平或者竖直）上相邻的 1 组成的区域。任何矩阵以外的区域都视为水域。

如果 grid2 的一个岛屿，被 grid1 的一个岛屿 完全 包含，
也就是说 grid2 中该岛屿的每一个格子都被 grid1 中同一个岛屿完全包含，
那么我们称 grid2 中的这个岛屿为 子岛屿 。

请你返回 grid2 中 子岛屿 的 数目 。
*/


class Solution {
private:
    static constexpr array<array<int, 2>, 4> dirs = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();

        auto bfs = [&](int sx, int sy) {
            queue<pair<int,int>> q;
            q.emplace(sx, sy);
            grid2[sx][sy] = 0;
            // 判断岛屿包含的每一个格子是否都在 grid1 中出现了
            bool check = grid1[sx][sy];
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dirs[d][0];
                    int ny = y + dirs[d][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid2[nx][ny] == 1) {
                        q.emplace(nx, ny);
                        grid2[nx][ny] = 0;
                        if (grid1[nx][ny] != 1) {
                            check = false;
                        }
                    }
                }
            }
            return check;
        };

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    ans += bfs(i, j);
                }
            }
        }
        return ans;
    }
};

