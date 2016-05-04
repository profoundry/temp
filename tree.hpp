#ifndef TREE_HPP
#define TREE_HPP

template <class T>
struct TNode {

  int count = 0;
  bool is_leaf = true;

  T k1, k2;

  TNode* p = nullptr;
  TNode* l = nullptr;
  TNode* m = nullptr;
  TNode* r = nullptr;

  TNode(T data) : k1{data} { ++count; }
  ~TNode();

  void add(T data) { k2 = data; ++count; }
  bool is_full() { return count == 2; }
  void set_leaf() { is_leaf = !(l && m && r); }
  int find_low(T);
  void split(T);
};

template <class T>
TNode<T>::~TNode() {
  delete l;
  delete m;
  delete r;
}
template <class T>
int TNode<T>::find_low(T data) {
  if (data <= k1)
    return -1;
  if (data > k2)
    return 1;
  return 0;
}

template <class T>
void TNode<T>::split(T data) {
  // check if its root
  if (!parent) {
    // get the position where the key needs to go
    switch (find_low(data)) {
    case -1:
      parent = new TNode<T>(k1);
      parent->l = new TNode<T>(data);
      parent->m = this;
      k1 = k2;
      break;
    case 1:
      parent = new TNode<T>(k2);
      parent->m = new TNode<T>(data);
      parent->l = this;
      break;
    default:
      parent = new TNode<T>(data);
      parent->m = new TNode<T>(k2);
      parent->l = this;
    }
    --count;
  }
}

template <class T>
class _23Tree {
private:
  TNode<T>* root = nullptr;
  void insert(TNode<T>*, T);

public:
  _23Tree() {}
  ~_23Tree() { delete root; }
  
  void insert(T);
};

template <class T>
void _23Tree<T>::insert(T data) {
  if (!root)
    root = new TNode<T>(data);
  else
    insert(root, data);
}

template <class T>
void _23Tree<T>::insert(TNode<T>* node, T data) {
  // check if the node is a leaf
  if (node->is_leaf) {
    // check if the node is full
    if (node->is_full())
      node->split(data);
    else
      node->add(data);
  }
}


#endif
