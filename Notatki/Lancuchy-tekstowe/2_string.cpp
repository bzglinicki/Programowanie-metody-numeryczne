#include <iostream>
#include <string>

int main()
{
   std::string str = "Programowanie i metody numeryczne";
   std::cout << str << std::endl;
   
   for (int i = 0; i < str.length(); ++i) std::cout << str[i];
   std::cout << std::endl;
   
   // Konwersje pomiędzy łańcuchami tekstowymi a liczbami
   int num1 = 13;
   std::string num1_str = std::to_string(num1);
   std::cout << num1 << " " << num1_str << std::endl;
   
   double num2 = 5.76;
   std::string num2_str = std::to_string(num2);
   std::cout << num2 << " " << num2_str << std::endl;
   
   std::string num3_str = "31";
   int num3 = std::stoi(num3_str);
   std::cout << num3 << " " << num3_str << std::endl;
   
   std::string num4_str = "3.14";
   double num4 = std::stod(num4_str);
   std::cout << num4 << " " << num4_str << std::endl;
   
   // Odczyt ze standardowego wejścia pojedynczego słowa
   // (tzn. łańcucha aż do pierwszego znaku białego)
   std::string word;
   std::cin >> word;
   std::cout << word << std::endl;
   
   // Odczyt ze standardowego wejścia pojedynczego słowa
   // (tzn. łańcucha aż do naciśnięcia [Enter])
   std::string line;
   std::getline(std::cin, line);
   std::cout << line << std::endl;
   
   // Konwersja łańcuchów C-string
   char *p = "Programowanie i metody numeryczne";
   std::string p_str = p;
   std::cout << *p << std::endl << p_str << std::endl;
   
   // Konwersja argumentów wywołania programu
   for (int n = 0; n < argc; ++n)
   {
      std::string arg = argv[n];
      std::cout << arg << " ";
   }
   std::cout << std::endl;
   
   return 0;
}