#ifndef KAMMYU_AHO_CORASIC
#define KAMMYU_AHO_CORASIC

#include <functional>
#include <queue>
#include <vector>

namespace kammyu
{
  namespace aho_corasic
  {
    constexpr int AHO_SIZE = 26;
    struct AhoCorasic
    {
    private:
      struct Node
      {
      private:
        int val = -1;

        Node* get(std::vector<int>::const_iterator left, std::vector<int>::const_iterator right)
        {
          Node* curr = this;
          while (left != right)
          {
            curr = curr->get(*left);
            left++;
          }
          return curr;
        }

      public:
        std::vector<Node*> children;
        Node* parent;
        Node* failure;
        Node* next;
        int label = -1;

        Node() : parent(nullptr), failure(nullptr), children(AHO_SIZE, nullptr) {}
        Node(Node* par, int v) : val(v), parent(par), children(AHO_SIZE, nullptr), failure(nullptr) {}

        Node* get(int c)
        {
          if (children[c] == nullptr)
            children[c] = new Node(this, c);
          return children[c];
        }
        Node* get(const std::vector<int>& s)
        {
          return get(s.begin(), s.end());
        }
        bool has_child(int c) { return children[c] != nullptr; }
      };
      Node root;
      int size = 0;

    public:
      AhoCorasic() : root() {}
      void insert(const std::vector<int>& s) { root.get(s)->label = size++; }

      void build()
      {
        std::queue<Node*> que;
        que.push(&root);
        root.failure = &root;
        root.next = &root;

        while (!que.empty())
        {
          Node* q = que.front();
          que.pop();
          for (int c = 0; c < AHO_SIZE; c++)
          {
            if (q->has_child(c))
            {
              Node* node = q->failure;
              if (q == &root)
                q->children[c]->failure = &root;
              else
              {
                while (node != &root && !node->has_child(c))
                  node = node->failure;
                q->children[c]->failure = node->has_child(c) ? node->children[c] : &root;
              }
              q->children[c]->next = q->children[c]->failure;
              if (q->children[c]->next->label == -1 && q->children[c]->next != &root)
                q->children[c]->next = q->children[c]->next->next;
              que.push(q->children[c]);
            }
          }
        }
      }

      Node* next(Node* from, int val, void (*find)(int))
      {
        while (from != &root && !from->has_child(val))
          from = from->failure;
        if (from->has_child(val))
          from = from->children[val];

        Node* temp = from;
        do
          if (temp->label != -1)
            find(temp->label);
        while ((temp = temp->next) != &root);
        return from;
      }

      Node* get_root() { return &root; }
    };
  }; // namespace aho_corasic
}; // namespace kammyu

#endif // KAMMYU_AHO_CORASIC