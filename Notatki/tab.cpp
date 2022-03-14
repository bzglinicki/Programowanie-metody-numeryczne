#include <iostream>

int main ()
{
  int n;
  std::cin >> n;
  int tab[n];

  for (int i=0; i<n; i++)
  {
    std::cout << "Podaj wartość nr " << i+1 << ": ";
    std::cin >> tab[i];
  }

  for (int i=0; i<n; i++)
  {
    std::cout << "tab[" << i << "] = " << tab[i] << std::endl;
  }
  return 0;
}
