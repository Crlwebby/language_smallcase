class Solution {
//该实现的初步思想是，求出每一个海洋的最近陆地区域，然后记录下该距离，最后在所有这些值里头求最大值。
//第一步是遍历所有海洋，然后求出其对应的最小陆地距离
//第二步是在所有的值里求出最大值
public:
    static constexpr int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    //四个方向的遍历；
    static constexpr int MAX_N = 100 + 5;

    struct Coordinate {
        int x, y, step;
    };

    int n, m;
    vector<vector<int>> a;

    bool vis[MAX_N][MAX_N];

    int findNearestLand(int x, int y) {
        memset(vis, 0, sizeof vis);
        //这是我想到过的，但是在GO里不知道怎么使用。因为每次从一个点开始，换其它点了就要把vis数组清空一遍；
        queue <Coordinate> q;
        q.push({x, y, 0});
        //最开始的点扔进队列
        vis[x][y] = 1;
        while (!q.empty()) {
            auto f = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = f.x + dx[i], ny = f.y + dy[i];
                if (!(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1)) {
                //如果上下左右遍历的坐标超出范围了，就换下一个坐标；
                    continue;
                }
                if (!vis[nx][ny]) {
                    q.push({nx, ny, f.step + 1});
                    vis[nx][ny] = 1;
                    if (a[nx][ny]) {
                    //如果遇见的恰好是大陆，那就把距离增加1位（因为上下左右遍历，所以+1即可）
                        return f.step + 1;
                    }
                }
            }
        }
        return -1;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
    //这里是函数主体入口，对于每一个海洋，求一个值，然后顺带就计算出大小了。
        this->n = grid.size();
        this->m = grid.at(0).size();
        a = grid;
        int ans = -1;
    //ans为-1，代表只有陆地或只有海洋的情况
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!a[i][j]) {
                //如果某个点是海洋，那就扔进找大陆的流程。
                    ans = max(ans, findNearestLand(i, j));
                }
            }
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/di-tu-fen-xi-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//真的是完全不会做。。。感觉没什么下手点，但是题解还是很多的，这里就对官方题解做一个注释，不然看不太懂，而且可以避免下次忘了。