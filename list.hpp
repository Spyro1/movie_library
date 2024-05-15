#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

template<typename T>
class List {
private:
    struct List_member {
        T data;
        List_member* next;
        List_member(List_member* n = nullptr) : next(n) {}
    };
    List_member* first;
public:
    List<T>() {
        first = nullptr;
    }
    T& operator[](size_t i) {
        List_member* current = first;
        for(size_t j = 0; j < i; j++) {
            if (current == nullptr)
                throw std::out_of_range("Tulindexelt.");
            current = current->next;
        }
        return current->data;
    }
    void add(const T& dat) {
        List_member* newNode = new List_member;
        newNode->data = dat;
        newNode->next = nullptr;
        if(first == nullptr)
            first = newNode;

        else {
            List_member* current = first->next;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    void del(const T& dat) {
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
