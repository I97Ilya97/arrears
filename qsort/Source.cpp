#include <iostream>
#include <vector>
template<class It, class Cmp>
void qsort(It beg_in, It end_in, Cmp cmp)
{
    It beg = (beg_in>end_in)?end_in:beg_in;
    It end = (beg_in>end_in)?beg_in:end_in;
    if (beg < end)
    {
        end--;
        It left = beg;
        It right = end;
        It supply = beg;
        ++supply;
        while (left < right)
        {
            while (cmp(*left, *supply)) {
                left++;
            }
            while ((left < right )&& cmp(*supply, *right)) {
                right--;
            }
            if (left < right)
            {
                std::iter_swap(left, right);
                left++;
                right--;
            }
        }
        qsort(beg, left, cmp);
        qsort(right, end, cmp);
    }
}

int main()
{
    std::vector<int> a = { 4, 7, 2, 1, 0, 3, 8 };
    std::less<int> l;
    qsort(a.begin(), a.end(), l);
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout<<"\n";
    std::cout<<"Please, wait while /dev/zero copying to /dev/null ...\n";
    system("dd if=/dev/zero of=/dev/null");
    return 0;
}
