/**
 * Programowanie i metody numeryczne
 *
 * Równania różniczkowe zwyczajne
 * Przykład: rozwiązywanie równania ruchu oscylatora harmonicznego metodą punktu środkowego
 */
 
/*
Ruch oscylatora harmonicznego o częstości omega opisuje równanie
   x'' + omega^2 x = 0,
w którym szukana funkcja x = x(t). Równanie to należy do klasy
liniowych jednorodnych równań różniczkowych zwyczajnych drugiego rzędu.
Wprowadzając zmienną v = x' możemy zastąpić je równoważnym układem dwóch
równań pierwszego rzędu:
   x' = v,
   v' = - omega^2 x.
Właśnie ten układ równań różniczkowych zwyczajnych pierwszego rzędu
rozwiążemy numerycznie, posługując się metodą punktu środkowego.
Przyjmujemy warunki początkowe:
   x(0) = x0,
   v(0) = v0.
Znane jest analityczne rozwiązanie równania ruchu oscylatora harmonicznego.
Można je przedstawić w postaci
   x(t) = A sin(omega t) + B cos (omega t),
gdzie stałe A i B wyznaczone są przez warunku początkowe:
   A = v0 / omega,
   B = x0.
Porównamy otrzymane rozwiązanie numeryczne z rozwiązaniem analitycznym.

Program zapisze wyniki obliczeń w pliku oscylator_midpoint.dat w następującym formacie:

Oscylator harmoniczny - metoda punktu środkowego: [wartości parametrów]
t0 x0 v0 x_exact0
t1 x1 v1 x_exact1
t2 x2 v2 x_exact2
...

Tak więc pierwsza linia będzie zawierała tekst informujący o metodzie i wartościach parametrów,
zaś każda kolejna linia - oddzielone spacjami wartości, kolejno, czasu, położenia oscylatora
w tym czasie, prędkości oscylatora w tym czasie oraz położenia oscylatora w danym czasie
uzyskanego na podstawie rozwiązania analitycznego. Tak przygotowany plik może zostać
wykorzystany jako dane wejściowe do napisanego w języku Python skryptu oscylator_plot.py,
który zwizualizuje otrzymane rozwiązanie.
*/



#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>


class HarmonicOscillatorMidpoint
{
public:
	// Parametry symulacji:
	double omega;   // parametr omega występujący w równaniu oscylatora,
	double x0;      // położenie początkowe,
	double v0;      // prędkość początkowa,
	double tmax;    // czas trwania symulacji,
	double dt;      // krok czasowy.
	
	// Wektory, w których będą przechowywane wyniki obliczeń uzyskane w kolejnych iteracjach:
	std::vector<double> res_t;   // kolejne wartości czasu,
	std::vector<double> res_x;   // położenia oscylatora w kolejnych chwilach - wyniki numeryczne,
	std::vector<double> res_v;   // prędkości oscylatora w kolejnych chwilach - wyniki numeryczne.
	/*
	Kolejne elementy list będą sobie wzajemnie odpowiadały, np. res_x[3] będzie położeniem oscylatora
	w chwili res_t[3], zaś np. res_v[5] - prędkością oscylatora w chwili res_t[5].
	*/
	
	/*
	Dla zobraozwania dokładności metody numerycznej, którą stosujemy, obliczymy też dokładne wartości
	położenia oscylatora w kolejnych chwilach, uzyskane na podstawie rozwiązania analitycznego.
	Umieścimy je w poniższym wektorze.
	*/	
	std::vector<double> res_exact;
	
	// Konstruktor.
	HarmonicOscillatorMidpoint(double omega, double x0, double v0, double tmax, double dt)
		: omega(omega), x0(x0), v0(v0), tmax(tmax), dt(dt)
	{}
	
private:	
	// Metody pomocnicze
	
	// Prawa strona równania x' = v.
	double Fx(double, double, double);

	// Prawa strona równania v' = - omega^2 x.
	double Fv(double, double, double);

	// Wynik analityczny - położenie oscylatora w chwili t.
	double SolveExact(double);
	
public:	
	// Metoda SolveMidpoint: rozwiązywanie równania różniczkowego oscylatora metodą punktu środkowego.
	void SolveMidpoint();
};

double HarmonicOscillatorMidpoint::Fx(double t, double x, double v)
{
	return v;
}

double HarmonicOscillatorMidpoint::Fv(double t, double x, double v)
{
	return (- std::pow(omega, 2) * x);
}

double HarmonicOscillatorMidpoint::SolveExact(double t)
{
	double A = v0 / omega;
	double B = x0;
	
	return A * std::sin(omega * t) + B * std::cos(omega * t);
}

void HarmonicOscillatorMidpoint::SolveMidpoint()
{
	// W wektorach przechowujących wyniki obliczeń umieszczamy wartości początkowe.
	res_t.push_back(0.);
	res_x.push_back(x0);
	res_v.push_back(v0);
	res_exact.push_back(x0);
	
	/*
	Zmienne x i v będą przechowywały, odpowiednio, położenie i prędkość oscylatora
	w danej iteracji. Na początek przypisujemy im więc wartości początkowe.
	*/
	double x = x0;
	double v = v0;
	
	/*
	W zmiennych xn i vn będziemy umieszczać obliczone w każdej iteracji nowe wartości
	położnia i prędkości oscylatora.
	*/
	double xn;
	double vn;
	
	/*
	Wyrażenie definiujące krok iteracyjny w metodzie punktu środkowego jest nieco skomplikowane,
	dlatego w celu zwększenia czytelności kodu wprowadzimy dwie pomocnicze zmienne xn_aux oraz
	vn_aux i obliczymy wartości xn i vn w dwóch krokach.
	*/
	double xn_aux;
	double vn_aux;
	
	// Główna pętla przeprowadzająca kolejne iteracje algorytmu.
	for(double t = dt; t <= tmax; t += dt)
	{
		// Obliczamy nowe wartości położenia i prędkości oscylatora.
		xn_aux = x + dt * Fx(t, x, v) / 2.;
		vn_aux = v + dt * Fv(t, x, v) / 2.;
      
		xn = x + dt * Fx(t, xn_aux, vn_aux);
		vn = v + dt * Fv(t, xn_aux, vn_aux);
		
		// Dopisujemy obliczone wartości do wektorów przechowujących wyniki.		
		res_t.push_back(t);
		res_x.push_back(xn);
		res_v.push_back(vn);
		
		// Obliczamy również położenie oscylatora w danej chwili na podstawie
		// rozwiązania analitycznego i dopisujemy wynik do odpowiedniego wektora.
		res_exact.push_back(SolveExact(t));
		
		// Przygotowujemy się do kolejnej iteracji, aktualizując zmienne x i v.
		x = xn;
		v = vn;
	}
}

int main(int argc, char *argv[])
{
	// Odczytujemy parametry symulacji przekazane jako argumenty wywołania programu.
	
	double omega;
    std::istringstream(argv[1]) >> omega;
	
	double x0;
    std::istringstream(argv[2]) >> x0;
	
	double v0;
    std::istringstream(argv[3]) >> v0;
	
	double tmax;
    std::istringstream(argv[4]) >> tmax;
	
	double dt;
    std::istringstream(argv[5]) >> dt;
	
	// Tworzymy instancję klasy rozwiązującej równanie oscylatora i wywołujemy właściwą metodę.
	HarmonicOscillatorMidpoint osc {omega, x0, v0, tmax, dt};
	osc.SolveMidpoint();
	
	// Zapisujemy wyniki obliczeń do pliku.
	std::ofstream results("oscylator_midpoint.dat");
	
	results << "Oscylator harmoniczny - metoda punktu środkowego: "
		<< "$\\omega $ = " << osc.omega << ", "
		<< "$x_0$ = " << osc.x0 << ", "
		<< "$v_0$ = " << osc.v0 << ", "
		<< "$t_\\mathrm{max}$ = " << osc.tmax << ", "
		<< "$\\mathrm{d}t$ = " << osc.dt
		<< std::endl;
	for(size_t i = 0; i < osc.res_x.size(); ++i)
	{
		results << osc.res_t[i] << " " << osc.res_x[i] << " " << osc.res_v[i] << " " << osc.res_exact[i] << std::endl;
	}		
	
	results.close();
	
	return 0;
}