
#include <vector>
#include <string>
using namespace std;


// Struct for tree in first-child, next-sibling representation
struct ParseTreeNode {
    char val;
    ParseTreeNode* first_child;
    ParseTreeNode* next_sibling;
};



ParseTreeNode* build_parse_tree(const string& expr);

int main() {

    return 0;
}
