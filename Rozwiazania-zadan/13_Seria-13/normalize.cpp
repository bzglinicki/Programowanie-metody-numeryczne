#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template <typename T, typename ForwardIt, typename OutIt>
void Normalize(ForwardIt begin, ForwardIt end, OutIt out, T min, T max)
{
    /*
	 * Zapisujemy najmniejszy element zbioru danych zawartych między iteratorami begin i end
	 * w zmiennej mi, zaś największy - w zmiennej mx.
	 */
	auto [mi, mx] = std::minmax_element(begin, end);
    
	// Wyznaczamy współczynniki trasformacji liniowej.
	auto a = (max - min) * 1. / (*mx - *mi);
    auto b = max - a * (*mx);
	
	// Przekształcamy kolejne elementy zbioru danych i przekazujemy wyniki do iteratora out.
    for(; begin != end; ++begin, ++out)
    {
        *out = a * (*begin) + b;
    }
}

int main()
{
    // Wektor przechowujący dane do normalizacji.
	std::vector<double> data;
	
	// Wczytujemy dane do normalizacji ze standardowego wejścia.
	double x;
	std::cout << "Ciąg liczb do normalizacji:" << std::endl;
	while(std::cin >> x) data.push_back(x);
	
	// Nowe wartości najmniejsza i największa.
	double min, max;
	
	std::cout << "Nowa wartość najmniejsza: ";
	std::cin >> min;
	std::cout << std::endl << "Nowa wartość największa: ";
	std::cin >> max;
    std::cout << std::endl
	
	// Normalizujemy dane i wyposujemy je na ekranie - SPOSÓB I.
    std::vector<double> out;    // Wektor na dane wyjściowe.
    out.reserve(data.size());   // Rezerwujemy odpowiednią ilość miejsca w pamięci.
    Normalize(std::begin(data), std::end(data), std::back_inserter(out), min, max);
    std::for_each(std::begin(out), std::end(out), [](auto k) { std::cout << k << " "; });
    std::cout << std::endl;
	
	// Normalizujemy dane i wyposujemy je na ekranie - SPOSÓB II.
    Normalize(std::begin(data), std::end(data), std::ostream_iterator<int>(std::cout, ", "), min, max);
    std::cout << std::endl;
	
    return 0;
}