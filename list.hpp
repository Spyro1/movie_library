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
    T& operator[](int i) {
        List_member* current = first->next;
        for(int j = 0; j < i; j++) {
            if (current == nullptr) {
                throw std::out_of_range("Tulindexelt.");
        }
            current = current->next;
        }
        return current->data;
    }
    void add(const T& dat) {
        List_member* newNode = new List_member;
        newNode->data = dat;
        newNode->next = nullptr;
        if (first->next == nullptr)
            first->next = newNode;
        else {
            List_member* current = first->next;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    template<typename S>
    T* search(S s) {
        List_member* current = first->next;
        while (current != nullptr) {
            if (current->data == s)
                return &current->data;
            current = current->next;
        }
        return nullptr;
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
    class iterator {
    private:
        List_member* iter;
    public:
        iterator() : iter(nullptr) {}
        iterator(const List& list) : iter(list.first) {
            if(iter->first = nullptr)
                iter = nullptr;
        }
        iterator& operator++() {
            if(iter != nullptr) {
                iter = iter->next;
                if(iter->next == nullptr)
                    iter = nullptr;
            }
            return *this;
        }
        iterator operator++(int) {
            iterator temp = *this;
            operator++();
            return temp;
        }
        bool operator!=(const iterator &i) const {
            return iter!=i.iter;
        }
        T* operator*() {
            if(iter != nullptr)
                return iter->data;
            else
                throw "Nincs adat, hibas.";
        }
        T* operator->() {
            if(iter != nullptr)
                return &iter->data;
            throw "Nincs adat, hibas.";
        }
    };
    iterator begin() {
        return iterator(*this);
    }
    iterator end() {
        return iterator();
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
