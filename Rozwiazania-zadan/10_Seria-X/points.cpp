#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>
struct Point {
  double x;
  double y;
  double z;
  int id;
};

template <class Rng> Point pointFactory(Rng &rng, int id) {
  std::uniform_real_distribution<> up(0, 2 * M_PI);
  std::uniform_real_distribution<> ut(-1, 1);
  double phi = up(rng);
  double theta = acos(ut(rng));
  double x = sin(theta) * cos(phi);
  double y = sin(theta) * sin(phi);
  double z = cos(theta);
  return Point{x, y, z, id};
}

Point meanPoint(std::vector<Point> &v) {
  Point p{0, 0, 0, 0};
  auto p2 = std::accumulate(v.begin(), v.end(), p, [](Point x, Point i) {
    x.x += i.x;
    x.y += i.y;
    x.z += i.z;
    x.id += i.id;
    return x;
  });
  p2.x /= v.size();
  p2.y /= v.size();
  p2.z /= v.size();
  return p2;
}

int main() {
  auto seed = std::chrono ::steady_clock ::now().time_since_epoch().count();
  std::default_random_engine rng(seed);
  // przykladowe inicjalizacje struktury
  Point p{0.1, 0.2, 0.3, 1};
  Point p2 = {0.5, 0.6, 0.7, 2};
  Point p3;
  // dostep do pol
  p3.x = 0.9;
  p3.y = 1;
  p3.z = 1.1;
  p3.id = 3;

  std::vector<Point> v(1000);
  for (int i = 0; i < v.size(); ++i) {
    v.at(i) = pointFactory(rng, i);
  }
  auto m = meanPoint(v);
  std::cout << m.x << " " << m.y << " " << m.z << std::endl;
}