#include <iostream>
#include <vector>
#include <list>
template <typename Iterator1, typename Iterator2>
auto merge( Iterator1 first1, Iterator1 last1, Iterator1 first2, Iterator1 last2, Iterator2 output ) {
    while (true) {
        if (first1==last1)
            return std::copy(first2,last2,output);

        if (first2==last2)
            return std::copy(first1,last1,output);

        *output++ = (*first2<*first1)? *first2++ : *first1++;
    }
}

int main() {
    std::vector<int> v1 = {1,5,7};

    std::list<int> m1 = {2,4,6};;


    std::vector<int> v2( v1.size() + m1.size() );
    std::vector<int>::iterator first1 = v1.begin(), last1 = v1.end(), output = v2.begin();
    std::list<int>::iterator first2 = m1.begin(), last2 = m1.end();

    merge<std::vector<int>::iterator, std::list<int>::iterator, std::vector<int>::iterator>(first1, last1, first2, last2, output);
    for(int i = 0; i < v2.size(); i++)
        std::cout << v2[i] << ' ';
}