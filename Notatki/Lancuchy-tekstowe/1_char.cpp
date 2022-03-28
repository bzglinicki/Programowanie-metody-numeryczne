#include <iostream>
#include <limits>

int main()
{
   // Kod ASCII znaku 'A': 65.
   std::cout << ’A’ << std::endl;        // Wypisze: A
   std::cout << (int)’A’ << std::endl;   // Wypisze: 65
   std::cout << (char)41 << std::endl;   // Wypisze: A
   
   // Kod ASCII znaku 'B': 66.
   char chB = ’B’;
   std::cout << chB << std::endl;        // Wypisze: B
   std::cout << (int)chB << std::endl;   // Wypisze: 66
   
   // Kod ASCII znaku 'C': 67.
   char chC = 67;
   std::cout << chC << std::endl;        // Wypisze: C
   std::cout << (int)chC << std::endl;   // Wypisze: 67
   
   // Najmniejsza i największa wartość zmiennej typu char.
   std::cout << std::numeric_limits<char>::min() << std::endl;
   std::cout << std::numeric_limits<char>::max() << std::endl;
   
   char ch;
   
   // Odczyt znaku ze standardowego wejścia z pominięciem znaków białych
   std::cin >> ch;
   std::cout << ch << std::endl;
   
   // Odczyt znaku ze standardowego wejścia z uwzględnieniem znaków białych
   std::cin.get(ch);
   std::cout << ch << " " << (int)ch << std::endl;
   
   return 0;
}