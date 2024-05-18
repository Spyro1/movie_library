#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include "memtrace.h"

template<typename T>
class List {
    struct List_member {
        T data;
        List_member* next;
        List_member() : next(nullptr) {}
//        ~List_member() { delete data; }
    };
    List_member* first;
    size_t size_; // A külső function neve legyen inkább sima size()
public:
    List<T>() {
        first = nullptr;
        size_ = 0;
    }
    size_t size() const { return size_; }
    T& operator[](size_t i) {
        if(i >= size_) throw std::out_of_range("Tulindexelt.");
        List_member* current = first;
        for(size_t j = 0; j < i; j++) {
            if (current == nullptr)
                throw std::out_of_range("Tulindexelt.");
            current = current->next;
        }
        return current->data;
    }
    void add(const T dat) {
        List_member* new_node = new List_member;
        new_node->data = dat;
//        new_node->next = nullptr;
        if(first == nullptr)
            first = new_node;
        else {
            List_member* current = first;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
//        new_node->next = nullptr;
        size_++;
    }
    void del(const T dat) {
        if(first->data == dat) {
            List_member* temp = first->next;
            delete first;
            first = temp;
            size_--;
            return;
        }
        List_member* current = first->next;
        List_member* prev = first;
        while (current != nullptr) {
            if (current->data == dat) {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
        size_--;
    }
    ~List() {
        List_member* current = first;
        while(current != nullptr) {
            List_member* next = current->next;
            delete current;
            current = next;
        }
    }
};

#endif // LIST_HPP_INCLUDED
