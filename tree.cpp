#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int k, TreeNode* l , TreeNode* r){
        key = k;
        left = l;
        right = r;
    }
    TreeNode(int k) : key(k), left(nullptr), right(nullptr){}
    
    ~TreeNode(){}
};

using tree = TreeNode*;

bool empty(tree root){
    return (root==nullptr);
}

void inorder(tree root , vector<int> &v){
    if(empty(root)) return;
    

    inorder(root->left);
    v.push_back(root->key);
    inorder(root->right);
}

void preorder(tree root , vector<int> &v){
    if(empty(root)) return;

    v.push_back(root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(tree root, vector<int> &v){
    if(root==nullptr) return;

    postorder(root->left);
    postorder(root->right);
    v.push_back(root->key);
}   

vector<int> BFS_order(tree root){
    if(empty(root)) return;

    vector<int> v;
    queue<tree> q;
    q.push(root);
    
    while(!q.empty()){
        tree node = q.front();
        v.push_back(node->key);
        q.pop();

        if(node->left != nullptr) q.push(node->left);
        if(node->right != nullptr) q.push(node->right);
    }

    return v;
}

int size(tree root){
    if(empty(root)) return 0;

    return (size(root->left) + size(root->right) + 1);
}

int height(tree root){
    if(empty(root)) return -1;

    return max(height(root->left) , height(root->right)) +1;
}

tree maximumBT(tree root){
    if(empty(root)) return nullptr;

    tree max = root;

    if( maximumBT(root->left) && root->left->key > max->key) max = root->left ;
    if( maximumBT(root->right) && root->right->key > max->key) max = root->right ;
    
    return max;
}

bool findPath(tree root , tree x , vector<int> &v){
    if(empty(root)) return false;

    v.push_back(root->key);

    if(findPath(root->left , x , v) || findPath(root->right , x , v) || (root->key == x->key)) return true;

    v.pop_back();
    
    return false;
}

bool findPathBack(tree root , tree x , vector<int> &v){
    if(empty(root)) return false;

    if(findPathBack(root->left,x,v) || findPathBack(root->right,x,v) || (root->key == x->key)){
        v.push_back(root->key);
        return true;
    }

    return false;
}

int LCA_BTiteration(tree root , tree p , tree q){
    if(empty(root)) return -1;
    vector<int> p_vec;
    vector<int> q_vec;
    int answer = -1;
    if(findPath(root,p,p_vec) && findPath(root,q,q_vec) ){
        if(p_vec > q_vec){
            for(int i = 0 ; i < q_vec.size() ; ++i){
                if(p_vec[i] == q_vec[i]) answer = p_vec[i];
            }
        }
        else{
            for(int i = 0 ; i < p_vec.size() ; ++i){
                if(p_vec[i] == q_vec[i]) answer = p_vec[i];
            }
        }
    }

    return answer;
}

int main(int args , char** argv){

}