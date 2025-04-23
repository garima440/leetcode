class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int total = 0;
        int count = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                if (grid[i][j] != 0)
                {
                    total++;
                }
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        int result = 0;

        while(!q.empty())
        {
            int k = q.size();
            count += k;
            
            while(k > 0)
            {
                k--;
                auto element = q.front();
                int x = element.first;
                int y = element.second;
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)
                    {continue;}

                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            if (!q.empty())
            {
                result++;
            }
        }
        if (total == count)
        {
            return result;
        }
        return -1;
    }
};