#include<iostream>
#include<Stack.h>

int main()
{
    Stack<int> stack;
    try
    {
        stack.push(5);
        stack.pop();
        std::cout << stack.top() << "\n";
//        srand(time(0));
//        for (int i = 0; i < 10; ++i)
//           stack.push(rand() % 100);
//
//        std::cout << "-------------" << "\n";
//        std::cout << stack.top() << " " << stack.size() << "\n";
//        std::cout << "-------------" << "\n";
//
//        while (!stack.empty())
//            stack.pop();
//        std::cout << stack.top() << " " << stack.size() << "\n";
    }
    catch(std::logic_error& ex)
    {
        std::cout << ex.what() << "\n";
    }
    catch(std::out_of_range& ex)
    {
        std::cout << ex.what() << "\n";
    }
    return 0;
}