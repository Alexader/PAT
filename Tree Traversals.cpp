#include <cstdio>
#include<queue>
using namespace std;
const int maxn = 50;
int N;
struct node {
    int val;
    node *left;
    node *right;
    node(int v) :val(v), left(nullptr), right(nullptr) {};
};
int postOrder[maxn];
int inOrder[maxn];
node* tree = nullptr;
node* createTree(int postL, int postR, int inL, int inR) {
    if(postL > postR) return nullptr;
    node* root = new node(postOrder[postR]);
    int index = inL;
    // 在先序中找到根节点的下标
    for(;index<=inR;index++)
        if(inOrder[index] == postOrder[postR]) break;
    int leftNum = index - inL;
    int rightNum = inR - index;
    root->left = createTree(postL, postL+leftNum-1, inL, index-1);
    root->right = createTree(postL+leftNum, postR-1, index+1, inR);
    return root;
}

void level(node* root, queue<node*>& q) {
    if(root == nullptr) return;
    q.push(root);
    int num = 0;// 已经输出的节点数目
    while(!q.empty()) {
        node* temp = q.front();
            printf("%d", temp->val);
        num++;
        if(num < N) printf(" ");
        q.pop();
        if(temp->left != nullptr) q.push(temp->left);
        if(temp->right != nullptr) q.push(temp->right);
    }
}
int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        scanf("%d", &postOrder[i]);
    for(int i=0;i<N;i++)
        scanf("%d", &inOrder[i]);
    
    tree = createTree(0, N-1, 0, N-1);
    queue<node*> vi;
    level(tree, vi);
}