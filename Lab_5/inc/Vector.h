#pragma once
#include<bitset>

void printBinaryForm(int a)
{
    const int n = 8;
    //std::cout << std::bitset<n>(a) << " " << a << "\n";
    std::cout << std::bitset<n>(a) << "\n";
}

std::string binary(unsigned x)
{
    std::string s;
    do
    {
        s.push_back('0' + (x & 1));
    } while (x >>= 1);
    std::reverse(s.begin(), s.end());
    return s;
}

template<typename T>
class Vector
{

};

void Packer(unsigned char& pack, bool val)
{
    unsigned char mask = pack;
    if (val)
        pack = (mask >> 1) | 0b10000000;
    else
        pack = (mask >> 1);
}

bool between(size_t left, size_t right, size_t middle)
{
    if (middle > left && middle < right)
        return true;
    else
        return false;
}

template<>
class Vector<bool>
{
private:
    size_t m_countBoolean = 0;
    size_t m_cap = 1;
    size_t m_countBlock = 0; //как index -> всегда блоков на 1 больше
    unsigned char* vec = nullptr;
    int byte = 8;
public:
    Vector()
    {
        vec = new unsigned char [m_cap];
         memset(vec, 0, m_cap);
    }
    ~Vector()
    {
        if (vec != nullptr)
            delete[] vec;
    }

    void reserve(size_t cap)
    {
        if (cap <= m_cap)
            return;

        unsigned char* tmp = new unsigned char[cap];
        std::memset(tmp, 0, cap);
        std::copy(vec, vec + m_countBlock, tmp);
        delete[] vec;
        m_cap = cap;
        vec = tmp;
    }

    void push_back(bool val)
    {
        if (m_countBoolean % byte == 0 && m_countBoolean != 0)
            ++m_countBlock;
        if (m_cap > m_countBlock + 1)
        {
            Packer(vec[m_countBlock], val);
            ++m_countBoolean;
        }
        else
        {
            reserve(m_countBlock * 2);
            Packer(vec[m_countBlock], val);
            ++m_countBoolean;
        }
    }

    void insert(int index, bool val)
    {
        bool tmp = this->operator[](static_cast<int>(m_countBoolean) - 1);
        for (int i = static_cast<int>(m_countBoolean) - 1; i > index; --i)
        {
            edit(i, this->operator[](i - 1));
        }
        if (m_cap > m_countBlock + 1)
        {
            ++m_countBoolean;
            edit(index, val);
        }
        else
        {
            edit(index, val);
            this->push_back(tmp);
        }
    }

    void erase(int index)
    {
        for (int i = index; i < m_countBoolean - 1; ++i)
        {
            edit(i, this->operator[](i + 1));
        }
        --m_countBoolean;
        if (!between(m_countBlock * byte, (m_countBlock + 1) * byte, m_countBoolean))
            --m_countBlock;
    }

    bool operator[] (int index)
    {
        return (vec[index / byte] & (1 << (byte - 1 - (index % byte)))) != 0;
    }

    /*auto at(int index)
    {
        return vec[index];
    }*/

    void edit(int index, bool val)
    {
        if (val)
            vec[index / byte] |= (1 << (byte - 1 - (index % byte)));
        else
            vec[index / byte] = vec[index / byte] & ~(1 << (byte - 1 - (index % byte)));
    }

    size_t size() const
    {
        return m_countBoolean;
    }

    size_t capacity() const
    {
        return m_cap;
    }

    void Info() const
    {
        std::cout << "size: " << size() << " " << "cap: " << capacity() << " "
        << "countBlock: " << m_countBlock + 1 << "\n";
    }

    void Print()
    {
        for (int i = 0; i < this->size(); ++i)
        {
            std::cout << this->operator[](i);
            if ((i + 1) % byte == 0)
                std::cout << "\n";
        }
        std::cout << "\n";
    }
};
