/*
Ejercicio # 2
Una empresa tiene diez almacenes y necesita crear un programa que lea las ventas mensuales de los diez almacenes, 
calcular la media de ventas y obtener un listado de los almacenes cuyas ventas mensuales son superiores a la media.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;
struct procuccion{
  int aid;//id del almacen
  int mes;
  float totalventas;
};
int main() {
  int i,n=0;  
  float sumatotal=0,media,mayor;
  string almacenes =" ";
  ostringstream ssal; 
  ostringstream ssmsv;
  ostringstream ssmt;
  cout<<"Digite la cantidad datos que almacenara? ";
  cin>>n;
  
  procuccion ventas[n];
  /*Ingreso de Datos*/
  	for(i=0;i<n;i++){
    	cout<<"Ingrese el ID de Almacen: "<<endl;
    	cin>>ventas[i].aid;
    	cout<<"Ingrese Mes de la venta: "<<endl;
    	cin>>ventas[i].mes;
    	cout<<"Monto venido: "<<endl;
    	cin>>ventas[i].totalventas;
    	sumatotal=sumatotal+ventas[i].totalventas;
    	system("CLS");
  	}
  	
  	mayor=media;
  	
  	for(i=0;i<n;i++){

  		if(ventas[i].totalventas>media){
		  if(ventas[i].totalventas>mayor){
		  	
	  		ssal << ventas[i].aid;
	  		ssmsv << ventas[i].mes;
	  		ssmt << ventas[i].totalventas;
	  		
	  		almacenes=almacenes+"Almacen:"+ssal.str()+"-Mes:"+ ssmsv.str()+"-Monto:"+ssmt.str()+" / ";
	  		
	  		ssmsv.str("");
	  		ssmt.str("");
	  		ssal.str("");
	  		ssmsv.clear();
  			ssmt.clear();
  			ssal.clear();
			mayor=ventas[i].totalventas;
		  }			  			
  		}
	}
	
	cout<<"Promedio General: "<<media<<endl;
	cout<<"Mayores ventas:   "<<almacenes.substr(0,almacenes.length()-2)<<endl;
	
}
