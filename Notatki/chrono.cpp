#include <iostream>
#include <chrono>

int main()
{
    long suma = 0;
    const int NMAX = 10000000;

    // Początek mierzenia czasu
    auto t0 = chrono::high_resolution_clock::now();

    for(int i = 0; i < NMAX; i++) suma += i;

    // Koniec mierzenia czasu
    auto tk = chrono::high_resolution_clock::now();
	
	// Upływ czasu pomiędzy chwilami t0 i tk
    auto dt = chrono::duration_cast<chrono::nanoseconds>(tk - t0).count();

    std::cout << "Suma: " << suma << std::endl;
    std::cout << "Czas wykonania: " << dt << " ns" << std::endl;
    return 0;
}