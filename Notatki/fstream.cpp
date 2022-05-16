#include <iostream>
#include <fstream>

int main()
{
    // Tworzymy strumień zapisu związany z plikiem
	ofstream fout;
	
	// Otwieramy plik, do którego będziemy pisać
    fout.open("testowy_plik.txt");
	
    // Strumieniem f możemy posługiwać się analogicznie, jak strumieniem cout
    fout << "Hello world" << std::endl;
	
	// Na koniec musimy zamknąć plik
    f.close();
	
    return 0;
}

