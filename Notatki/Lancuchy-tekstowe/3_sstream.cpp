#include <iostream>
#include <string>
#include <sstream>

int main()
{
   std::ostringstream out;
   out << "ABC " << 13 << " " << 3.14;
   
   std::string str = out.str();
   std::cout << str << std::endl;
   
   int i;
   double x;
   std::string txt;
   std::istringstream in(str);
   in >> txt >> i >> x;
   std::cout << txt << " " << i << " " << x << std::endl;
   
   return 0;
}