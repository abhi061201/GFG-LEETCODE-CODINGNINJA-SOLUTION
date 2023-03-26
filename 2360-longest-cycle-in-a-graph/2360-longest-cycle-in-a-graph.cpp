class Solution {
public:
   int longestCycle(vector<int>& e) {
    int res = -1;
    vector<pair<int, int>> memo(e.size(), {-1, -1});
    for (int i = 0; i < e.size(); ++i)
        for (int j = i, dist = 0; j != -1; j = e[j]) {
            auto [dist_i, from_i] = memo[j];
            if (dist_i == -1)
                memo[j] = {dist++, i};
            else {
                if (from_i == i)
                    res = max(res, dist - dist_i);
                break;
            }
        }
    return res;
}
};