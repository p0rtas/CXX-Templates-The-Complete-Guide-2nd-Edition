#include <cassert>
#include <vector>

template <typename T, typename Cont = std::vector<T>>
class Stack {
private:
    Cont elems; // elements

public:
    Stack() = default;
    Stack(T elem) // initialize stack with one element
        : elems({ elem })
    { // by value to decay on class tmpl arg deduction
    }
    void push(T const& elem); // push element
    void pop(); // pop element
    T const& top() const; // return top element
    bool empty() const
    { // return whether the stack is empty
        return elems.empty();
    }
};

template <typename T, typename Cont>
void Stack<T, Cont>::push(T const& elem)
{
    elems.push_back(elem); // append copy of passed elem
}

template <typename T, typename Cont>
void Stack<T, Cont>::pop()
{
    assert(!elems.empty());
    elems.pop_back(); // remove last element
}

template <typename T, typename Cont>
T const& Stack<T, Cont>::top() const
{
    assert(!elems.empty());
    return elems.back(); // return copy of last element
}
