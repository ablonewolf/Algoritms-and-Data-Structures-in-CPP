class PriorityNode {
public:
  int value;
  int priority;
  PriorityNode* next;

  PriorityNode(int value, int priority) {
    this->value = value;
    this->priority = priority;
    this->next = nullptr;
  }
};