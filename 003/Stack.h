//
// Created by lxd on 2019/12/10.
//

#ifndef INC_003_STACK_H
#define INC_003_STACK_H


template<typename T>
struct Node {
    T data;
    Node<T> *next;

};

//用链表实现栈
//头节点，单向链表

template<typename T>
class Stack {
private:
    Node<T> *head;//头指针
    int _size;//栈的大小

public:
    Stack();

    int size();//返回栈的大小
    bool empty();//返回栈是否为空
    void push(T e);//插入一个元素
    //⬆踩坑：这里虽然理论上用指针传递更好，但是按照代码习惯，我们一般还是用值传递
    void pop();//弹出栈顶元素
    T top();//返回栈顶元素值

};


template<typename T>
int Stack<T>::size() {
    return this->_size;
}

template<typename T>
bool Stack<T>::empty() {
    return this->_size == 0;
}

template<typename T>
void Stack<T>::push(T e) {
    auto n = new Node<T>;
    n->data = e;
    n->next = this->head->next;
    this->head->next = n;
    this->_size++;
}

template<typename T>
void Stack<T>::pop() {
    if (!this->empty()) {
        auto p = head->next;
        head->next = head->next->next;
        delete p;
    }
    this->_size--;
}

template<typename T>
T Stack<T>::top() {
    if (!this->empty())
        return this->head->next->data;
}

template<typename T>
Stack<T>::Stack() {

    this->_size = 0;
    this->head = new Node<T>;
}



#endif //INC_003_STACK_H
