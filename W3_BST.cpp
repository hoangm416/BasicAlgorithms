//C++ 
#include <iostream> 
using namespace std;

struct BNode {
    int id;
    BNode* left;
    BNode* right;
};

BNode* makeNewNode(int item)
{
    BNode* newNode = new BNode();
    newNode -> id = item;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

BNode* insert(BNode* root, int k)
{
    if (root == NULL) {
        root = makeNewNode(k);
    }
    else if (k < root->id) {
        root->left = insert(root->left, k);
    }
    else if (k > root->id) {
        root->right = insert(root->right, k);
    }
    
    return root;
}

void preOrder(BNode* root) 
{
	if(root == NULL) return;
	cout << root->id << " ";
	preOrder(root->left);
	preOrder(root->right);
}

int main() 
{ 
    char command[12];
    BNode* root = NULL;
    
    while (cin >> command)
    {
        if (command[0] == '#')
            break;
        else
        {
            int k;
            cin >> k;
            root = insert(root, k);
        }
    }
    preOrder(root);
    return 0;
}

