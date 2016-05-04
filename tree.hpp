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

  bool is_full() { return count == 2; }
  void set_leaf() { is_leaf = !(l && m && r); }
};

template <class T>
TNode<T>::~TNode() {
  delete l;
  delete m;
  delete r;
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
      node->split();
    else
      node->k2 = data;
  }
}


#endif
