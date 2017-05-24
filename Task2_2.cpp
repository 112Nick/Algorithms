#include <iostream>
#include <stack>

class BinaryTree {
 public:
  ~BinaryTree() {
    std::stack<Node *> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
      Node *it = nodes.top();
      nodes.pop();
      if (it == nullptr) {
        continue;
      }
      nodes.push(it->right);
      nodes.push(it->left);
      delete it;
    }
  }

  void add(int value) {
    Node *node = new Node;
    node->value = value;
    if (root == nullptr) {
      root = node;
      return;
    }

    Node *it = root;

    while (true) {
      if (value < it->value) {
        if (it->left == nullptr) {
          it->left = node;
          break;
        }
        it = it->left;
      } else {
        if (it->right == nullptr) {
          it->right = node;
          break;
        }
        it = it->right;
      }
    }
  }

  void printPreOrder(std::ostream &os) const {
    std::stack<Node *> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
      Node *it = nodes.top();
      nodes.pop();
      if (it == nullptr) {
        continue;
      }
      os << it->value << ' ';
      nodes.push(it->right);
      nodes.push(it->left);
    }
    os << '\n';
  }

 private:
  struct Node {
    Node *left;
    Node *right;
    int value;
  };

  Node *root = nullptr;
};

int main() {
  size_t size;
  std::cin >> size;
  BinaryTree tree;
  int value;
  for (size_t i = 0; i < size; ++i) {
    std::cin >> value;
    tree.add(value);
  }
  tree.printPreOrder(std::cout);
  return 0;
}
