#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main ()
{
  int n;
  std::cin >> n;

  std::srand(std::time(0));

  std::cout << setprecision(4) << std::fixed;

  for (int cnt=0; cnt<n ; cnt++)
  {
    std::cout << std::rand () / (RAND_MAX+1.) << std::endl;
  }

  time (0);

  cout << " Seconds = " << time(0) << endl;
  cout << " Minutes = " << (time(0)/60) << endl;
  cout << " Hours   = " << (time(0)/60/60) << endl;
  cout << " Days    = " << (time(0)/60/60/24) << endl;
  cout << " Years   = " << (time(0)/60/60/24/365) << endl;
  cout << " Current Year = " << ((time(0)/60/60/24/365)+1970) << endl;

  return 0;
}
