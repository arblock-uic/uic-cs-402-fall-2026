
#include <vector>
#include <string>
#include <queue>
using namespace std;


// Struct for tree in first-child, next-sibling representation
struct ParseTreeNode {
    char val;
    ParseTreeNode* left_child;
    ParseTreeNode* right_child;
};



ParseTreeNode* build_parse_tree(const string& expr);

vector<vector<char>> level_order_tree(ParseTreeNode* root) {
    queue<ParseTreeNode*> q;
    vector<vector<char>> out = {};
    q.push(root);
    while(!q.empty()) {
        int curr_level = q.size();
        vector<char> level;
        for(int i = 0; i < curr_level; ++i) {
            ParseTreeNode* curr = q.front();
            q.pop();
            if(curr == nullptr) {
                level.emplace_back('#');
            }
            else {
                level.emplace_back(curr->val);
                q.push(curr->left_child);
                q.push(curr->right_child);
            }
        }
        out.push_back(level);
    }
    return out;
}

int main() {

    string test0 = "a|b";
    string test1 = "c|(a^b)";
    string test2 = "a|b^c";
    string test3 = "~(A^b)^(c|~z)";
    string test4 = "~(A^(c|~(d^e)^F)|~z)";
    string test5 = "a|b^c|d^~e|f";
    string test6 = "(a|(b^(c|(d^(~e|f)))))";
    string test7 = "~~A";
    string test8 = "c";
    string test9 = "~b";

    ParseTreeNode* ans0 = new ParseTreeNode(
        OR, 
        new ParseTreeNode('a'),
        new ParseTreeNode('b')
    );

    auto out0 = level_order_tree(ans0);


    return 0;
}
