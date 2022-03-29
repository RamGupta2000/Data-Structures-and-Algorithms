class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>> pq;

        for (int i = 0; i < points.size(); i++)
        {
            vector<vector<int>> v;
            v.push_back(points[i]);
            int x = v[0][0];
            int y = v[0][1];
            int root = x * x + y * y;

            pq.push({root, v[0]});
            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};