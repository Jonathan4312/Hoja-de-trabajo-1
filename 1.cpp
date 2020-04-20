/*Descripción de problema:  Escribir una función Salario que calcule los salarios de un trabajador 
para un número dado de horas trabajadas y un salario hora. Las horas que superen las 40 horas semanales 
se pagarán como extras con un salario hora 1,5 veces el salario ordinario.
Así mismo se deberá calcular el monto 
a pagar de IGSS por cada trabajador.

El programa debera contener un menu para:
1) Invocar dicha funcion y grabar datos a un archivo,
2) Adicionalmente deberá tener una opción para leer el archivo y grabar los datos en memoria. 
3) Una opción para mostrar cuanto se paga de total de planilla e IGSS.

*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;
struct empleado{
	int codigoempleado;
	string nombre;
	float salarioordinario;
	float salariop;
	float costoh;
	float costo_horas_extra;
	int horastrabajadas;
	int horase;
	float igss;		
};


void insertar_datos_archivo();
void read_file();
void salario(empleado& ingreso);
void mp();


int main(){
	mp();
}

void salario(empleado& ingreso){
	ofstream archivo;
	string nombreArchivo;
	fflush(stdin); 
	cout<<"Indique nombre de archivo: ";
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::app);

	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	system("CLS");
	float salarioordinario,igss,salariop,costoho,costo_horas_extra;	
	string nombre;
	int horastrabajadas,horase,codigoempleado;
	//Ingreso de datos
	cout<<"Ingrese Codigo de Empleado: "<<endl;
	cin>>codigoempleado;
	fflush(stdin);
	cout<<"Ingrese Nombre de Empleado: "<<endl;
	getline(cin,nombre,'\n');//,ingreso.nombre);
	cout<<"Ingrese Salario Ordinario: "<<endl;
	cin>>salarioordinario;
	cout<<"Ingrese Horas Trabajadas: "<<endl;
	cin>>horastrabajadas;
	/*Calculos*/
	costoho = salarioordinario/30/8;
	if (horastrabajadas>40)//calculo de horas extras
		horase= horastrabajadas-40;
	igss = ((horastrabajadas-horase)*costoho) * 0.0483;
	costo_horas_extra = (horase *costoho)*1.5;
	salariop = ((horastrabajadas-horase)*costoho + costo_horas_extra)-igss;
	/*Graba datos en la estructura*/
	ingreso.codigoempleado = codigoempleado;
	ingreso.nombre = nombre;
	ingreso.salarioordinario = salarioordinario;
	ingreso.salariop = salariop;
	ingreso.costoh = costoho;
	ingreso.costo_horas_extra= costo_horas_extra;
	ingreso.igss =  igss;
	ingreso.horastrabajadas = horastrabajadas;
	ingreso.horase = horase;
	/*Graba datos al archivo*/
	archivo<<codigoempleado<<"\t"<<nombre<<"\t"<<salarioordinario<<"\t"<<salariop<<"\t"<<costoho<<"\t"<<costo_horas_extra<<"\t"<<igss<<"\t"<<horastrabajadas<<"\t"<<horase<<endl;	
	archivo.close();
} 

void mp(){
	int i;
	empleado datos;
	
	do {
		system("CLS");
		cout<<"-------------------"<<"\n";
		cout<<"Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<"1 - Ingresar Empleado "<<"\n";
		cout<<"2 - Leer archivo"<<"\n";
		cout<<"3 - Reporte"<<"\n";
		cout<<"4 - Salir"<<"\n";
		cout<<"-------------------\n";
		cout<<"Seleccione su opcion: ";
		cin>>i;
		if (i==1)
			salario(datos);
		else if (i==2)
			read_file();			
		else if (i==3) 	
			read_file();
		else if (i==4)
			break;
		else 
			break;
		
	} while(i!=4);	
}


void read_file(){
	ifstream archivo; //leer archivo
	string nombreArchivo;
	fflush(stdin);
	cout<<"Indique nombre de archivo: ";
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}
	
	int lineas;
	string s;
	while (getline(archivo, s))
        lineas++;
        
    archivo.close();
    system("CLS");
	cout<<"Lineas: "<<lineas<<endl;
	empleado recordset[lineas];
		
	archivo.open(nombreArchivo.c_str(),ios::in);
		if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}
	
	for(int i=0; i< lineas; i++)
    {
        archivo>>recordset[i].codigoempleado;
		getline(archivo, recordset[i].nombre, ',');
    }
	for(int i=0; i< lineas; i++)
		cout<<recordset[i].codigoempleado<<" "<<recordset[i].nombre<<" "<<recordset[i].salarioordinario;
	
	archivo.close();
	system("Pause");
	
}

void insertar_datos_archivo(){
	cout<<"Insertando datos\n\n";
	system("PAUSE");
	system("CLS");
}
