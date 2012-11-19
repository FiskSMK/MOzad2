/*
**********************Autorzy******************
Dawid Pszczó³kowski
Pawe³ Sawicki
Adrian Smykowski
*********************Tresc*********************
Zadanie 2.12
Dla rownania f(x)=0,gdzie f(x)=3x+2-e^x, wczytac a,b nalezace do R takie, by a<b oraz f(a)*f(b)<0.
Nastepnie dopóki "uzytkownik sie nie znudzi" wczytywac wartosc 0<epsilon<1 i metoda polowienia na [a,b] przyblizyc 
z dokladnoscia epsilon rozwiazanie tego rownania. Rozwiazanie to przyblizyc rowniez metoda siecznych 
z x_0=a,x_1=b,przy czym,x_k bedzie dobrym przyblizeniem, gdy |x_k-x_k-1|<=epsilon.
Porownac ilosc krokow wykonanych metoda polowienia i metoda siecznych.
*/

#include<iostream>
#include<math.h>
#include<string.h>

int krok_polowienie;
int krok_sieczne;

//Stala wartosc e do 50 miejsc po przecinku
double const e=2.718281828459045235360287471352662497757247093699;

using namespace std;

//Definicje funkcji
double f(double x);
void polowienie(double a,double b,double epsilon);
void sieczne(double a,double b, double epsilon);

int main(int argc , char* argv[]){
	int a,b;
	cout<<"Podaj wartosci a i b takie, by a<b oraz by f(a)*f(b)<0."<<endl;
	while(1){
		cout<<"a=";
		cin>>a;
		cout<<"b=";
		cin>>b;
		if(f(a)*f(b)<0 && a<b){
			break;
		}
		else{
			if(a>=b) cout<<"Blad!!! a="<<a<<" jest wieksze badz rowne b="<<b<<"."<<endl;
			if(f(a)*f(b)>=0) cout<<"Blad!!! f(a)*f(b) jest wieksze badz rowne 0."<<endl;
			cout<<"Podaj ponownie wartosci - tym razem poprawnie."<<endl;
		}
	}
	char warunek[8];
	while(1){
		cout<<"\nJezeli chcesz zakonczyc program wpisz KONIEC, w przeciwnym wypadku wpisz LICZ.\nTwoj wybor:";
		cin>>warunek;
		if(strcmp(warunek,"KONIEC")==0)break;
		else{
			if(strcmp(warunek,"LICZ")==0){
				double epsilon;
				krok_polowienie=1;
				krok_sieczne=1;
				while(1){
					cout<<"\nPodaj epsilon taki, ze 0<epsilon<1 "<<endl;
					cout<<"epsilon=";
					cin>>epsilon;
					if(epsilon>0 && epsilon<1) break;
					else cout<<"Blad!!! - epsilon ma zla wartosc, podaj epsilon poprawnie."<<endl;
				}
				polowienie(a,b,epsilon);
				sieczne(a,b,epsilon);
				krok_polowienie=1;
				krok_sieczne=1;
			}
			else cout<<"Blad!!! - zle podany warunek dzialania programu, popraw sie."<<endl;
		}
	}


return 0;
}

//Funkcja f obliczajaca rownanie f(x)=3*x+2-e^x

double inline f(double x){
return 3*x+2-pow(e,x); 
}

//Funkcja polowienia

void polowienie(double a,double b,double epsilon){

	double x = ( a + b ) / 2;
	if(f(x)==0) cout<<"\nMETODA POLOWIENIA\npunkt P=("<<x<<",0) jest miejscem zerowym funkcji.\nMetoda ta potrzebowala "<<krok_polowienie<<" krok."<<endl;
	else{
		if((f(x)<0 && -f(x)<epsilon)||(f(x)>0 && f(x)<epsilon)){
			cout<<"\nMETODA POLOWIENIA\npunkt P=("<<x<<",0) jest miejscem zerowym funkcji.\nMetoda ta potrzebowala "<<krok_polowienie<<" krokow.\nPrzyblizenie = "<<(f(x)>0?f(x):-f(x))<<"."<<endl;
		}
		else{
			if(f(x)*f(a)<0){
				krok_polowienie++;
				polowienie(a,x,epsilon);
			}
			else if(f(x)*f(b)<0){
				krok_polowienie++;
				polowienie(x,b,epsilon);
			}
		}
	}
}

//Funkcja siecznych

void sieczne(double a,double b, double epsilon){
	if(fabs(b-a)<=epsilon) cout<<"\nMETODA SIECZNYCH\npunkt P=("<<b<<",0) jest miejscem zerowym funkcji.\nMetoda ta potrzebowala "<<krok_sieczne<<" krokow.\nPrzyblizenie = "<<(f(b)>0?f(b):-f(b))<<"."<<endl;
	else {
		double temp=b-(f(b)*(b-a))/(f(b)-f(a));
		a=b;
		b=temp;
		krok_sieczne++;
		sieczne(a,b,epsilon);
	}
}
