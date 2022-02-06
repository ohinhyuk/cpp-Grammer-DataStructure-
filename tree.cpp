// struct를 이용한 binary tree 구현.
// 다양한 기능(함수)들을 만들기 위해 vector stl 과 queue stl를 사용하였다.
// doublinked list 의 기능을 사용하여 구현하였다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int key; // node 속 data 저장
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

// tree를 inorder 순서로 vector에 담는다.

void inorder(tree root , vector<int> &v){
    if(empty(root)) return;
    

    inorder(root->left, v);
    v.push_back(root->key);
    inorder(root->right , v);
}

// tree를 preorder 순서로 vector에 담는다.

void preorder(tree root , vector<int> &v){
    if(empty(root)) return;

    v.push_back(root->key);
    preorder(root->left, v);
    preorder(root->right, v);
}

// tree를 postorder 순서로 vector에 담는다.

void postorder(tree root, vector<int> &v){
    if(root==nullptr) return;

    postorder(root->left, v);
    postorder(root->right ,v);
    v.push_back(root->key);
}   

// tree를 BFSorder로 vector에 담아서 return한다.

vector<int> BFS_order(tree root){
    vector<int> v;

    if(empty(root)) return v;


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

// node 의 갯수 출력

int size(tree root){
    if(empty(root)) return 0;

    return (size(root->left) + size(root->right) + 1);
}

// tree의 높이 출력.

int height(tree root){
    if(empty(root)) return -1;

    return max(height(root->left) , height(root->right)) +1;
}

// 제일 큰 data를 가지고 있는 node 반환.

tree maximumBT(tree root){
    if(empty(root)) return nullptr;

    tree max = root;

    if( maximumBT(root->left) && root->left->key > max->key) max = root->left ;
    if( maximumBT(root->right) && root->right->key > max->key) max = root->right ;
    
    return max;
}

// root -> x 까지의 길을 vector v 에 저장한다.

bool findPath(tree root , tree x , vector<int> &v){
    if(empty(root)) return false;

    v.push_back(root->key);

    if(findPath(root->left , x , v) || findPath(root->right , x , v) || (root->key == x->key)) return true;

    v.pop_back();
    
    return false;
}

// x -> root 까지의 길을 vector v 에 저장한다.

bool findPathBack(tree root , tree x , vector<int> &v){
    if(empty(root)) return false;

    if(findPathBack(root->left,x,v) || findPathBack(root->right,x,v) || (root->key == x->key)){
        v.push_back(root->key);
        return true;
    }

    return false;
}

// p 와 q 노드 의 공동 상위 노드 중 가장 가까운 것의 data를 반환.
// iteration을 이용한 LCA_BT

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

// p 와 q 노드 의 공동 상위 노드 중 가장 가까운 것의 tree를 반환.
// recursion을 이용한 LCA_BT이다.

tree LCA_BT(tree root, tree p , tree q){
    if(empty(root)) return nullptr;

    if(root==p || root ==q) return root;

    tree left = LCA_BT(root->left , p, q);
    tree right = LCA_BT(root->right , p, q);

    if(left && right) return root;
    else if(left && !right) return left;
    else if(!left && right) return right;
    return nullptr;
}

// making tree using vector values into BFS order.

tree makeTree_BFS(tree root, vector<int> v){
    if(v.empty()) return nullptr;

    queue<tree> q;

    root->key = v[0];
    int i = 1;

    q.push(root);

    while(i < v.size()){
        tree Node = q.front();
        q.pop();
        Node->left = new TreeNode(v[i]);
        i++;
        q.push(Node->left);

        if(i >= v.size()) break;
        Node->right = new TreeNode(v[i]);
        i++;
        q.push(Node->right);
    }

    return root;
}

void printVector(vector<int> v){
    for(auto x : v){
        cout << x << ' ';
    }
    cout << endl;
}

int main(int args , char** argv){
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> result;
    tree n = new TreeNode(100);
    preorder(makeTree_BFS(n,v),result);
    printVector(result);
    printVector(BFS_order(n));
}