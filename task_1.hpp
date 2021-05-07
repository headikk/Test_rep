#pragma once

#include <cstddef>
#include <stdexcept>
#include <string>

class Stack {
public:
  struct Node {
    std::string value;
    Node *next = nullptr;
  };

  Stack(size_t capacity) : _capacity(capacity) {}
  ~Stack();
  size_t GetCapacity() { return _capacity; }
  size_t GetSize() { return _size; }

  void Add(const std::string &value);
  void Delete();

  Node *GetHead() { return head; }
  const Node *GetHead() const { return head; }

private:
  size_t _size = 0;
  const size_t _capacity;
  Node *head = nullptr;
};

inline Stack::~Stack() {
  while (head) {
    Delete();
  }
}

inline void Stack::Add(const std::string &value) {
  if (_size == _capacity)
    throw std::runtime_error("Contaier is full/n");
  _size++;
  auto node = new Node{value};
  node->next = head;
  head = node;
}

inline void Stack::Delete() {
  if (head) {
    _size--;
    Node *new_head = head->next;
    delete head;
    head = new_head;
  }
}