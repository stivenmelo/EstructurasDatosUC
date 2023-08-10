#include <iostream>       // Prueba de parámetros para función main
using namespace std;
int main() {
	 int v[10] ,i,suma = 0;
	 float media;
	 
	 for(i =0 ;i<10;i++){
	 	cout<<"Diite la posicion"<<i+1<<",";
	 	cin>>v[i];
	 }
	 
	 for(i =0 ;i<10;i++){
	 	suma = suma+v[i];
	 }
	 
	 media = (float) suma/10;
	 
	 int min =v[0];
	 
	 for(i =0 ;i<10 ;i++){
	 	if(min>v[i]){
	 		min = v[i];
		 }
	 }
	 
	 int max =v[0];
	 
	 for(i =0 ;i<10 ;i++){
	 	if(max<v[i]){
	 		max = v[i];
		 }
	 }
	 
	 
	 for(i =0 ;i<10 ;i++){
	 	cout<<"\n En la posicion"<<i+1<<"el valor es: "<<v[i];
	 }
	 
	 cout<<endl<<"La sumatorio de vector es: "<<suma;
	 cout<<endl<<"la media aritmetica del vector es: "<<media;
	 cout<<endl<<"el valor minimo del vector es:"<<min;
	 cout<<endl<<"el valor maximo del vector es:"<<max;
}
