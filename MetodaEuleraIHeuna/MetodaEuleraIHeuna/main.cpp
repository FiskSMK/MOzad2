/*
**********************Autorzy******************
Dawid Pszczó³kowski
Pawe³ Sawicki
Adrian Smykowski
*********************Tresc*********************
Zadanie 3.12
Zagadnienie ró¿niczkowe y'=sqrt(2x-y)-3x+2 , y(1)=1
rozwi¹zaæ na przedziale [1,3] metod¹ Eulera oraz udoskonalon¹ metod¹ Eulera, zwan¹ metod¹ Heuna.
Wyniki porównaæ z rozwi¹zaniem dok³adnym y(x)=2x-x^2.
*/

#include<iostream>
#include<math.h>

using namespace std;

//Deklaracja funkcji liczacej y' oraz liczacej dok³adne wyniki
double inline f(double x, double y);
double inline dokladne_wyniki(double x);

int main(int argc, char* argv[]){

//Wczytywanie kroku dla zwiekszania x																							??jaki warunek??
	
	double h;
	while(1){
		cout<<"Podaj rozmiar kroku dla jakiego bedzie dzialal program na przedziale [1,3],\n"<<"podana wartosc powinna byc wieksza od 0 a mniejsza od 2\n"<<"h= ";
		cin>>h;
		if(h<2 && h>0) break;
		else cout<<"Zle podana wartosc kroku!!- sprobuj jeszcze raz"<<endl;
	}

//Obliczanie wielkosc tablic

double koniec_przedzialu=3.0;
double poczatek_przedzialu=1.0;
int wielkosc_tab=1;

while(poczatek_przedzialu<=koniec_przedzialu){
	poczatek_przedzialu+=h;
	wielkosc_tab++;
}

//Deklaracja tablic dla wartosci x i y obliczanych metoda Eulera ,rozwiazaniem dokladnym y(x)=2x-x^2, oraz przyblizen y(x)-y
cout<<wielkosc_tab<<endl;
double *X =new double[wielkosc_tab]; 
double *Y=new double[wielkosc_tab];
double *DokladneY=new double[wielkosc_tab];
double *Porownania=new double[wielkosc_tab];


//Wypelnianie tablicy X i Y poczatkowymi wartosciami podanymi w warunkiach zadania y(1)=1
X[0]=1;
Y[0]=1;

//Wypelnianie tablicy X kolejnymi wartosciami
for(int i=1;i<wielkosc_tab;i++){
	X[i]=X[i-1]+h;
}

//Wypelnianie tablicy Y kolejnymi wartosciami 
for(int i=1;i<wielkosc_tab;i++){
	Y[i]=Y[i-1]+h*f(X[i-1],Y[i-1]);
}

//Wypelnianie tablicy DokladneY zgodnie ze wzorem y(x)=2x-x^2
for(int i=0;i<wielkosc_tab;i++){
	DokladneY[i]=dokladne_wyniki(X[i]);
}

//Wypelnianie tablicy Porownania wartosciami DokladneY - Y
for(int i=0;i<wielkosc_tab;i++){
	Porownania[i]=DokladneY[i]-Y[i];
	if(Porownania[i]<0) Porownania[i]=-Porownania[i];
}

////////////////////////////////////////////////////////////////////////////Wydruk kontrolny//////////////////////////////////////////////////////////
cout<<"\nX\n";
for(int i=0;X[i]<=koniec_przedzialu && i<wielkosc_tab;i++){
	cout<<i<<" "<<X[i]<<endl;
}
cout<<"\nY\n";
for(int i=0;i<wielkosc_tab;i++){
	cout<<i<<" "<<Y[i]<<endl;
}

cout<<"\nDokladne\n";
for(int i=0;i<wielkosc_tab;i++){
	cout<<i<<" "<<DokladneY[i]<<endl;
}

cout<<"\nPorownania\n";
for(int i=0;i<wielkosc_tab;i++){
	cout<<i<<" "<<Porownania[i]<<endl;
}

system("PAUSE");
return 0;
}

//y'
double inline f(double x, double y){
	return sqrt(2*x-y)-3*x+2;
}

//y(x)
double inline dokladne_wyniki(double x){
	return 2*x - pow(x,2.0);
}