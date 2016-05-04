#ifndef TREE_HPP
#define TREE_HPP

template <class T>
struct TNode {

  T k1, k2;

  TNode* l = nullptr;
  TNode* m = nullptr;
  TNode* r = nullptr;

  TNode(T data) : k1{data} {}
  ~TNode();
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
  void insert(TNode<T>* node, T data);

public:
  
  void insert(T data);
};

#endif
