#include <iostream>

template <typename T>
struct Node {
    Node *prev, *next;
    T value;
};

struct not_found_element_error : std::runtime_error {
    not_found_element_error() : std::runtime_error("Element was not found") {}
};

template <typename T>
struct List {
private:
    Node<T> *tail = new Node<T>();
    int size_ = 0;
    bool initialized = false;

public:
    void init(T value_) {
        Node<T> *m = new Node<T>();
        m->value = value_;
        m->prev = tail;
        m->next = tail;
        tail->prev = m;
        tail->next = m;
    }

    // potential value type problem
    void push_back(T value_) {
        if (!initialized) {
            init(value_);
            initialized = true;
        } else {
            Node<T> *m = new Node<T>();
            m->value = value_;
            m->prev = tail->prev;
            m->next = tail;
            tail->prev->next = m;
            tail->prev = m;
        }
        size_++;
    }

    // potential incorrect Node problem
    void erase(Node<T> *elem) {
        elem->prev->next = elem->next;
        elem->next->prev = elem->prev;
        delete elem;
        size_--;
    }

    // potential incorrect Node problem
    Node<T> *next(Node<T> *elem) {
        if (elem->next != tail) {
            return elem->next;
        }
        return elem->next->next;
    }

    // potential incorrect Node problem
    Node<T> *prev(Node<T> *elem) {
        if (elem->prev != tail) {
            return elem->prev;
        }
        return elem->prev->prev;
    }

    int size() {
        return size_;
    }

    // potential dangling pointer problem
    Node<T> *find(T value_) {
        if (size_ == 0) { throw not_found_element_error(); }
        Node<T> *elem = tail->next;
        while (elem != tail) {
            if (elem->value != value_) {
                elem = elem->next;
                continue;
            }
            return elem;
        }
        throw not_found_element_error();
    }

    void make_empty() {
        if (size_ == 0) { return; }
        Node<T> *current_node = tail->next;
        tail->next = nullptr;
        Node<T> *last_node;
        while (current_node != tail) {
            last_node = current_node;
            current_node = current_node->next;
            current_node->prev = nullptr;
            delete last_node;
        }
        size_ = 0;
    }
};