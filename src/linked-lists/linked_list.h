#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include <stdexcept>

namespace linked_lists {
    class LinkedList {
        class Node {
        public:
            int value;
            Node * next;

            Node() : Node(0) { }
            Node(int value) : Node(value, nullptr) { }
            Node(int value, Node * next) : value { value }, next { next } { }
        };

        Node * head = nullptr;
        int size = 0;
    public:
        void push_front(int value) {
            head = new Node(value, head);
            size++;
        }

        int pop_front() {
            if (head == nullptr) {
                throw std::underflow_error("List is empty");
            }

            int result = head->value;
            size--;

            Node * tmp = head;
            head = head->next;
            delete tmp;
            
            return result;
        }

        bool contains(int value) {
            Node * tmp = head;

            while (tmp != nullptr) {
                if (tmp->value == value) {
                    return true;
                }

                tmp = tmp->next;
            }

            return false;
        }
    };
}

#endif