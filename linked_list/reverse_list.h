/*
 * 给定一个链表的头指针，要求只遍历一次，将单链表中元素的顺序反转过来
 */

#ifndef ALGORITHM_DESIGN_ANALYSIS_REVERSE_LIST_H
#define ALGORITHM_DESIGN_ANALYSIS_REVERSE_LIST_H

#include <iostream>

struct Node {
    int data_;
    Node *next_;

    explicit Node(int data = 0) {
        data_ = data;
        next_ = nullptr;
    }

    ~Node() {
        next_ = nullptr;
    }

    void Print() {
        Node *p = this;
        while (p) {
            std::cout << p->data_ << "->";
            p = p->next_;
        }
        std::cout << std::endl;
    }
};

Node* ReverseList(Node *head) {
    if (!head)
        return nullptr;
    Node *p = head->next_;
    Node *temp;
    head->next_ = nullptr; // 此时 head 指向的节点变成尾节点
    while (p) {
        temp = p;
        p = p->next_;
        temp->next_ = head;
        head = temp;
    }
    return head;
}

void ReverseListTest() {
    // Init a list
    Node *head = new Node();
    Node *p = head;
    for (int i = 1; i < 10; i++) {
        Node *s = new Node(i);
        p->next_ = s;
        p = p->next_;
    }
    head->Print();
    head = ReverseList(head);
    head->Print();
    while (head) {
        p = head;
        head = head->next_;
        delete p;
    }
}

#endif //ALGORITHM_DESIGN_ANALYSIS_REVERSE_LIST_H


































