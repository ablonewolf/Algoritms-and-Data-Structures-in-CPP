class Node {
public:
    int value;
    Node *next;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};