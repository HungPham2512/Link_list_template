#include <iostream>

//Dinh nghia class template Node

template <typename T>
class Node
{
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr){}

    ~Node(){}
};


template <typename T>
class Link_list
{
private:
    int list_size;
    Node<T>* head_ptr;

public:
    Link_list() : head_ptr(nullptr), list_size(0){}

    ~Link_list()
    {
        list_clear();
    }

    bool list_empty()
    {
        return list_size == 0;
    }

    int size_of_list()
    {
        return list_size;
    }

    void add_front(T value)
    {
        Node<T>* new_node = new Node<T>(value);
        new_node->next = head_ptr;
        head_ptr = new_node;
        list_size++;
    }

    void pop_head()
    {
        if(list_empty()==false)
        {
            Node<T>* temp = head_ptr;
            head_ptr = head_ptr->next;
            list_size--;
            delete temp;
        }
    }

    void list_clear()
    {
        while(list_empty()==false)
        {
            pop_head();
        }
    }

    bool list_search(T value)
    {
        Node<T>* current = head_ptr;
        while(current != nullptr)
        {
            if(current->data==value)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void insert_list(T value, int place)
    {
        if(place == 0)
        {
            add_front(value);
        } else if (place <= list_size) {
            Node<T>* new_node = new Node<T>(value);
            Node<T>* current = head_ptr;

            for (int i = 1; i< place; i++)
            {
                current = current->next;
            }

            new_node->next = current->next;
            current->next = new_node;
            list_size++;
            }
    }

    void list_display()
    {
        Node<T>* current = head_ptr;
        while(current != nullptr)
        {
            std::cout << current->data <<std::endl;
            current = current->next;
        }
    }
};

int main()
{
    Link_list<int> test_list;

    test_list.add_front(10);
    test_list.add_front(20);
    test_list.add_front(30);
    test_list.add_front(40);

    test_list.list_display();

    std::cout << std::endl;
    test_list.pop_head();
    test_list.insert_list(100,2);

    test_list.list_display();

    std::cout << std::endl;
    test_list.list_clear();

    test_list.list_display();

    return 0;
}
