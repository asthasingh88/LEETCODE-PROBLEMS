class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> cnt(k, 0);

        // available servers
        set<int> available;
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finish_time, server_id}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            busy;

        for (int i = 0; i < arrival.size(); i++) {
            int start = arrival[i];

            // free completed servers
            while (!busy.empty() && busy.top().first <= start) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty())
                continue;

            int target = i % k;

            auto it = available.lower_bound(target);
            if (it == available.end()) {
                it = available.begin(); // wrap around
            }

            int server = *it;
            available.erase(it);

            cnt[server]++;
            busy.push({(long long)arrival[i] + load[i], server});
        }

        int mx = *max_element(cnt.begin(), cnt.end());

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (cnt[i] == mx)
                ans.push_back(i);
        }

        return ans;
    }
};