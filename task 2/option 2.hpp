#ifndef OPTION_2_HPP_
#define OPTION_2_HPP_

#include <iostream>

template <typename T>
struct Node {
    Node *next;
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
        m->next = tail;
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
            m->next = tail;
            Node<T> *elem = tail->next;
            while (elem->next != tail) {
                elem = elem->next;
            }
            elem->next = m;
        }
        size_++;
    }

    // potential incorrect Node problem
    void erase(Node<T> *elem) {
        Node<T> *elem_ = elem;
        while (elem_->next != elem) {
            elem_ = elem_->next;
        }
        elem_->next = elem->next;
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

    int size() {
        return size_;
    }

    // potential dangling pointer problem
    Node<T> *find(T value_) {
        if (size_ == 0) { throw not_found_element_error(); }
        Node<T> *current_node = tail->next;
        while (current_node != tail) {
            if (current_node->value != value_) {
                current_node = current_node->next;
                continue;
            }
            return current_node;
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
            delete last_node;
        }
        size_ = 0;
    }
};

#endif