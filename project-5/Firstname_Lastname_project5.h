#ifndef FIRSTNAME_LASTNAME_PROJECT3
#define FIRSTNAME_LASTNAME_PROJECT3

#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int id;
    double delay;
    TreeNode* left_child;
    TreeNode* right_child;
};


inline float latency(TreeNode* v) {
    if(v == nullptr) return 0.0;
    return max(latency(v->left_child), latency(v->right_child))+v->delay;
}



pair<int, vector<int>> light_post_problem(int n, const vector<Edge>& edges, const vector<int>& costs);
vector<pair<unsigned int,string>> smallest_subset_sum(unsigned int n, unsigned int t, const vector<pair<unsigned int, string>>& values);
double tree_optimization(int n, TreeNode* root, vector<double>& node_upgrade, unsigned int upgrade_budget);


#endif
