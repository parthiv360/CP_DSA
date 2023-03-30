#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::pair;

constexpr int MOD = 1e9 + 7;

// some of the values here have different names than in the editorial, i hope that doesn't ruin things for you
class Tree {
    private:
        static const int ROOT = 0;

        const vector<vector<int>>& neighbors;
        const vector<int>& node_vals;
        vector<vector<long long>> sum_ways;
        int target;

        void process_sums(int at, int prev) {
            int val = node_vals[at];  // just a shorthand
            if (val <= target) {
                sum_ways[at][val]++;
            }
            for (int n : neighbors[at]) {
                if (n == prev) {
                    continue;
                }
                process_sums(n, at);
                if (val > target) {
                    continue;
                }
                for (int t = target; t >= 0; t--) {
                    int new_val = sum_ways[at][t];  // this is so the update can happen simultaneously
                    for (int a = 0; a <= t; a++) {
                        int b = t - a;
                        new_val = (
                            new_val + sum_ways[at][a] * sum_ways[n][b]
                        ) % MOD;
                    }
                    sum_ways[at][t] = new_val;
                }
            }
        }
    public:
        Tree(const vector<vector<int>>& neighbors,
             const vector<int>& node_vals,
             int target)
                : neighbors(neighbors),
                  node_vals(node_vals),
                  target(target),
                  sum_ways(neighbors.size(), vector<long long>(target + 1)) {
            assert(node_vals.size() == neighbors.size());
            process_sums(ROOT, ROOT);
        }

        long long sum_num(int n) {
            return sum_ways[n][target];
        }
};

/**
 * https://bit.ly/3itQFzv (actual url way too long i promise it's nothing sus)
 * (input ommitted due to length)
 */
int main() {
    int test_num;
    std::cin >> test_num;
    for (int t = 0; t < test_num; t++) {
        int node_num;
        int target;
        std::cin >> node_num >> target;
        vector<int> node_vals(node_num);
        for (int& v : node_vals) {
            std::cin >> v;
        }
        
        vector<vector<int>> neighbors(node_num);
        for (int e = 0; e < node_num - 1; e++) {
            int a;
            int b;
            std::cin >> a >> b;
            neighbors[--a].push_back(--b);
            neighbors[b].push_back(a);
        }

        Tree tree(neighbors, node_vals, target);
        long long total_sums = 0;
        for (int n = 0; n < node_num; n++) {
            total_sums = (total_sums + tree.sum_num(n)) % MOD;
        }
        cout << total_sums << endl;
    }
}