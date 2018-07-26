#include <cstdio>
#include<vector>
using namespace std;
int N;
vector<int> arr;
vector<int> pre;
vector<int> preM;
vector<int> post;
struct node {
    int val;
    node *left;
    node *right;
    node(int v) :val(v), left(nullptr), right(nullptr) {};
};
vector<int> postM;
node *tree = nullptr;
void insert(node *&root, int val) {
    if(root == nullptr)
        root = new node(val);
    else if(val >= root->val)
        insert(root->right, val);
    else
        insert(root->left, val);
}
void preOrder(node *&root, vector<int> &vi) {
    if(root == nullptr) return;
    else {
        vi.push_back(root->val);
        preOrder(root->left, vi);
        preOrder(root->right, vi);
    }
}
void preOrderMirror(node *&root, vector<int> &vi) {
    if(root == nullptr) return;
    else {
        vi.push_back(root->val);
        preOrderMirror(root->right, vi);
        preOrderMirror(root->left, vi);
    }
}
void postOrder(node *&root, vector<int> &vi) {
    if(root == nullptr) return;
    else {
        postOrder(root->left, vi);
        postOrder(root->right, vi);
        vi.push_back(root->val);
    }
}
void postOrderMirror(node *&root, vector<int> &vi) {
    if(root == nullptr) return;
    else {
        postOrderMirror(root->right, vi);
        postOrderMirror(root->left, vi);
        vi.push_back(root->val);
    }
}
int main() {
    scanf("%d", &N);
    int temp;
    for(int i=0;i<N;i++) {
        scanf("%d", &temp);
        arr.push_back(temp);
        insert(tree, temp);
    }
    preOrder(tree, pre);
    preOrderMirror(tree, preM);
    postOrder(tree, post);
    postOrderMirror(tree, postM);
    if(pre == arr) {
        printf("YES\n");
        for(int i=0;i<N;i++) {
            if(i!=N-1)
                printf("%d ", post[i]);
            else   
                printf("%d", post[i]);
        }
    } else if(preM == arr) {
        printf("YES\n");
        for(int i=0;i<N;i++) {
            if(i!=N-1)
                printf("%d ", postM[i]);
            else   
                printf("%d", postM[i]);
        }
    } else
    printf("NO");
}