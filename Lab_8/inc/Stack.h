#pragma once

template<typename T>
class Stack
{
private:
    struct Node
    {
        T m_data;
        Node* m_next;
    };
    Node* m_top = nullptr;
    size_t m_size = 0;

public:
    Stack() = default;

    ~Stack()
    {
        while (!empty())
            this->pop();
    }
    void push(const T& data)
    {
        ++m_size;
        Node* newNode = new Node;
        newNode->m_data = data;
        newNode->m_next = m_top;
        m_top = newNode;
    }
    void pop()
    {
        if (!empty())
        {
            --m_size;
            Node* delNode = m_top->m_next;
            delete m_top;
            m_top = delNode;
        }
        else
            throw std::logic_error("Stack is empty!");
    }
    const size_t size()
    {
        if (!empty())
            return m_size;
        throw std::logic_error("Stack is empty!");
    }
    const T& top()
    {
        if (!empty())
            return m_top->m_data;
        throw std::out_of_range("No elements to extract!");
    }
    bool empty()
    {
        return m_top == nullptr;
    }
};