/**
 * Programowanie II R
 *
 * Programowanie współbieżne - przykład 1.
 *
 *
 * Opracowano na podstawie:
 *    https://github.com/PacktPublishing/The-Modern-Cpp-Challenge/blob/master/Chapter07/problem_61/main.cpp
 *    Copyright (c) 2018 Packt
 *    Licencja MIT
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>
#include <chrono>
#include <thread>

template <typename It, typename F>
void T1(It begin, It end, F f)
{
	std::transform(begin, end, begin, f);
}


template <typename It, typename F>
void T2(It begin, It end, F f)
{
      std::vector<std::thread> threads;
      int thread_count = std::thread::hardware_concurrency();
	  auto part_size = std::distance(begin, end) / thread_count;
      
	  auto part_begin = begin;
      auto part_end = begin;
      for (int i = 0; i < thread_count; ++i)
      {
         part_begin = part_end;
         if (i == thread_count - 1)
		 {
			 part_end = end;
		 }
         else
		 {
			 std::advance(part_end, part_size);
		 }
		 
		 threads.push_back(std::thread([part_begin, part_end, f]() { std::transform(part_begin, part_end, part_begin, f); }));
      }

      for (auto &t : threads) t.join();
}

int main()
{
   const size_t size = 10000000;
   std::vector<int> v1(size);
   std::vector<int> v2(size);
   
   std::random_device rd; 
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> dis(1, 1000);
   std::generate(v1.begin(), v1.end(), [&](){ return dis(gen); });
   std::generate(v2.begin(), v2.end(), [&](){ return dis(gen); });
   
   auto start = std::chrono::system_clock::now();
   T1(v1.begin(), v1.end(), [](int const x) {return x * x; });
   auto end = std::chrono::system_clock::now();
   auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
   std::cout << "Wywołanie sekwencyjne: " << time.count() << " ms" << std::endl;
   
   start = std::chrono::system_clock::now();
   T2(v2.begin(), v2.end(), [](int const x) {return x * x; });
   end = std::chrono::system_clock::now();
   time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
   std::cout << "Wywołanie współbieżne: " << time.count() << " ms" << std::endl;

   return 0;
}
