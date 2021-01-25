//
// Created by akio on 2021/1/25.
//

template<class T>
class BST {
    struct Node {
        T data;
        Node *left;
        Node *right;
    };

    Node *root;

    Node *makeEmpty(Node *t) {
        if (t == nullptr) return nullptr;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        return nullptr;
    }

    Node *insert(Node *t, T x) {
        if (t == nullptr) {
            t = new Node;
            t->data = x;
            t->left = t->right = nullptr;
        } else if (x < t->data) {
            t->left = insert(t->left, x);
        } else if (x > t->data) {
            t->right = insert(t->right, x);
        }
        return t;
    }

    Node *find(Node *t, T x) {
        if (t == nullptr) return nullptr;
        if (x < t->data) return find(t->left, x);
        if (x > t->data) return find(t->right, x);
        return t;
    }

    Node *findMin(Node *t) {
        if (t == nullptr || t->left == nullptr) return t;
        return findMin(t->left);
    }

    Node *findMax(Node *t) {
        if (t == nullptr || t->right == nullptr) return t;
        return findMax(t->right);
    }

    Node *remove(Node *t, T x) {
        Node *temp;
        if (t == nullptr) return nullptr;
        else if (x < t->data) t->left = remove(t->left, x);
        else if (x > t->data) t->right = remove(t->right, x);
        else if (t->left && t->right) {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->right, t->data);
        } else {
            temp = t;
            if (t->left == nullptr) t = t->right;
            else if (t->right == nullptr) t = t->left;
            delete temp;
        }
        return t;
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(T x) {
        insert(root, x);
    }

    void remove(T x) {
        remove(root, x);
    }
};