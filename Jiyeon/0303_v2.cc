#include <iostream>
#include <vector>
using namespace::std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> nodes;

bool isValidBST(TreeNode* root) {
    TreeNode* _root = root;
    TreeNode* pre;

    while((_root != NULL) || (!nodes.empty())) {
        while(_root != NULL) {
            nodes.push_back(_root);
            _root = _root->left;
        }
        _root = nodes.back();
        nodes.pop_back();
        if(pre != NULL) {
            if(pre->val >= _root->val)    
                return false;
        }
        pre = _root;
        _root = _root->right;
    }
    return true;
} 


int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right= new TreeNode(10);
    root->right->left = new TreeNode(6);
    root->right->right= new TreeNode(20);
    if(isValidBST(root))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}
