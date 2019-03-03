#include <iostream>
#include <vector>
using namespace::std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

vector<int> values;

void inorder(Node* root) {
    if(root == NULL)
        return;
    if(root->left != NULL)
        inorder(root->left);
    values.push_back(root->val);
    if(root->right != NULL)
        inorder(root->right);
}

bool isValidTree(Node* root) {
    inorder(root);
    for(int i=1; i<values.size(); i++) {
        if(values[i-1] >= values[i])
            return false;
    }
    return true;
}

int main() {
    cout << "테케만들기귀찮다" <<endl;
}
