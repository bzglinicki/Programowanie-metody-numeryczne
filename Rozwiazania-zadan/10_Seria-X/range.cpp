#include <algorithm>
#include <iostream>
#include <iterator>

class RangeIterator {
public:
  RangeIterator(int i, int step) : i(i), step(step) {}
  int operator*() { return i; }
  RangeIterator &operator++() {
    i += step;
    return *this;
  };
  bool operator!=(const RangeIterator &other) { return i != other.i; };
  bool operator==(const RangeIterator &other) { return i == other.i; };
  using difference_type = long int;
  using value_type = int;
  using pointer = int *;
  using reference = int &;
  using iterator_category = std::input_iterator_tag;

private:
  int i;
  int step;
};

class Range {
public:
  Range(int max) : min(0), max(max) {}
  Range(int min, int max) : min(min), max(max) {}
  RangeIterator begin() { return RangeIterator(min, min < max ? 1 : -1); }
  RangeIterator end() { return RangeIterator(max, min < max ? 1 : -1); }

private:
  int min;
  int max;
};

int main() {
  for (const auto &i : Range(4, 0)) {
    std::cout << i << std::endl;
  }
  Range r(5);
  std::copy(std::begin(r), std::end(r),
            std::ostream_iterator<int>(std::cout, ", "));
  return 0;
}