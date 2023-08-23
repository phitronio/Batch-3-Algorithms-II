class Solution
{
public:
    bool vis[100][100];
    int n, m;
    vector<pair<int, int>> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isValid(int cI, int cJ)
    {
        if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
            return true;
        else
            return false;
    }
    void dfs(int si, int sj, int scolor, int clr, vector<vector<int>> &image)
    {
        vis[si][sj] = true;
        if (image[si][sj] == scolor)
        {
            image[si][sj] = clr;
        }
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> p = path[i];
            int ci = si + p.first;
            int cj = sj + p.second;
            if (isValid(ci, cj) && !vis[ci][cj] && image[ci][cj] == scolor)
            {
                dfs(ci, cj, scolor, clr, image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        n = image.size();
        m = image[0].size();
        dfs(sr, sc, image[sr][sc], color, image);
        return image;
    }
};