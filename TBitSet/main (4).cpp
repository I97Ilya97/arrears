#include <bitset>
#include <iostream>
#include <string>

#define CHECK

#ifdef CHECK
#include "TBitSet.h"

template<size_t T>
using bitset = TBitSet<T>;

#else

template<size_t N>
using bitset = std::bitset<N>;

#endif // CHECK


#define assert(X) { \
	if(!(X)) {\
		std::cout << "see function:'" << __FUNCTION__ << "' line: " << __LINE__;\
		throw std::logic_error(#X); \
	}\
}

int main()
{
    {
        bitset<10> m;
        assert(m.none());

        m[0] = true;
        assert(m.any());
        m[0] = false;
        assert(!m.any());

        m.flip();
        assert(m.all());

        m.flip();
        m.set(1);
       // printf("%s\n", m.to_string().data());
        auto u = m.to_ulong();

        bitset<10> m1(u);
        //printf("%s|%s\n", m1.to_string().data(), m.to_string().data());
        //std::cout<<m1.to_ulong()<<"|"<<m.to_ulong()<<"\n";
        assert(m == m1);

        auto c = m1.count();
        
        assert(m1.count() == 1);
        assert((~m1).count() == 9);

        assert(m.reset(1).none());
    }
}
