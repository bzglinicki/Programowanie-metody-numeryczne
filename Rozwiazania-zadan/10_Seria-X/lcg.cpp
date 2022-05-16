#include <cmath>
#include <iostream>
#include <random>

class MyRng {
public:
  using result_type = size_t;
  size_t min() { return c == 0 ? 0 : 1; }
  size_t max() { return m - 1; }
  MyRng(size_t x, size_t a = 100, size_t c = 100, size_t m = 48271)
      : x(x), a(a), c(c), m(m) {}
  size_t operator()() {
    x = (a * x + c) % m;
    return x;
  }

private:
  size_t x;
  size_t a;
  size_t c;
  size_t m;
};

int main() {
  MyRng rng(1, 48271, 0, pow(2, 31) - 1);
  // std::ministd_rnd jest generatorem kongruencyjnym o argumentach jak wyżej
  // (patrz wiki)
  std::minstd_rand StdRng(1);
  std::cout << "MyRng: " << rng() << " minstd_rand: " << StdRng() << std::endl;
  std::uniform_int_distribution<> uni(1, 10);
  for (int i = 0; i < 10; ++i) {
    std::cout << uni(rng) << " " << uni(StdRng) << std::endl;
  }
  return 0;
}
