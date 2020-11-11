#include <iostream>
#include "dList.cpp"

int main()
{
    dList<int> d(0, 1);

    for(int i=1; i<=10; ++i)
    {
        d.insertBack(i);
    }

    for(dList<int>::const_iterator i = d.begin(); i!=d.end(); ++i)
    {
        std::cout << *i << " ";
    }
}