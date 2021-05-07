#include <iostream>
#include <vector>

template <typename Iterator>
void quick_sort(Iterator first, Iterator last) {
  if (first != last) {
    auto left = first;
    auto right = last;
    auto pivot = left++;
    while (left != right) {
      if (*left < *pivot) {
        ++left;
      } else {
        while ( (left != --right) && (*pivot < *right) );
        std::iter_swap(left, right);
      }
    }
    --left;
    std::iter_swap(first, left);
    quick_sort(first, left);
    quick_sort(right, last);
  }
}

template <typename T> void Sort(std::vector<T> &v) {
  quick_sort(v.begin(), v.end());
}

/*int main() {
  
}*/