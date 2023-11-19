#include <iostream>

#include <fstream>

#include <string>

using namespace std;
struct NotasEstudiante {
  double NotasAsignaturas[6];
  double NotaF;
  
  double NotaMinima1;
  double NotaMinima2;
  
  double definitiva1;
  double definitiva2;
  double definitiva3;
};

void Asignacion( NotasEstudiante Notas[3]) {
	ifstream Entrada("notasFinales.txt");
	  for (int i = 0; i < 3; i++) {
	  	for (int j = 0; j < 6; ++j) {
	        Entrada >> Notas[i].NotasAsignaturas[j];
	    }
	    Entrada >> Notas[i].NotaF;
	    Notas[i].NotaMinima1 = 0;
	    Notas[i].NotaMinima2 = 0;
	    Notas[i].definitiva1 = 0;
	    Notas[i].definitiva2 = 0;
	    Notas[i].definitiva3 = 0;
	  }
}

void Minimo( NotasEstudiante Notas[3]) {
	for (int i = 0; i < 3; i++) {
		double notaMinima1 = Notas[i].NotasAsignaturas[0];
		double notaMinima2 = Notas[i].NotasAsignaturas[3]; 
 
	    for (int j = 1; j < 3; ++j) {
	        if (Notas[i].NotasAsignaturas[j] < notaMinima1) {
	            notaMinima1 = Notas[i].NotasAsignaturas[j];
	        }
	    }

	    for (int k = 4; k < 6; ++k) {
	        if (Notas[i].NotasAsignaturas[k] < notaMinima2) {
	            notaMinima2 = Notas[i].NotasAsignaturas[k];;
	        }
	    }
		
  	}
}

void Definitiva( NotasEstudiante Notas[3]) {
	for (int i = 0; i < 3; i++) {
		double mayor1 = Notas[i].NotasAsignaturas[0]; 
	    double mayor2 = Notas[i].NotasAsignaturas[1];
	
	    if (mayor2 > mayor1) {
	        swap(mayor1, mayor2);
	    }
	
	    for (int j = 2; j < 3; ++j) {
	        if (Notas[i].NotasAsignaturas[j] > mayor1) {
	            mayor2 = mayor1;
	            mayor1 = Notas[i].NotasAsignaturas[j];
	        } else if (Notas[i].NotasAsignaturas[j] > mayor2) {
	            mayor2 = Notas[i].NotasAsignaturas[j];
	        }
	    }
	    
	    
	    double mayor3 = Notas[i].NotasAsignaturas[3]; 
	    double mayor4 = Notas[i].NotasAsignaturas[4]; 

	    if (mayor4 > mayor3) {
	        swap(mayor3, mayor4);
	    }
	
	    for (int k = 5; k < 6; ++k) {
	        if (Notas[i].NotasAsignaturas[k] > mayor3) {
	            mayor4 = mayor3;
	            mayor3 = Notas[i].NotasAsignaturas[k];
	        } else if (Notas[i].NotasAsignaturas[k] > mayor4) {
	            mayor4 = Notas[i].NotasAsignaturas[k];
	        }
	    }
	    Notas[i].definitiva1 = ((mayor1 + mayor2) / 2.0)*0.3;
	    Notas[i].definitiva2 = ((mayor3 + mayor4) / 2.0)*0.3;
	    Notas[i].definitiva3 = (Notas[i].NotasAsignaturas[4])*0.4;
  	}
}

void Imprimir(NotasEstudiante Notas[3]) {
  ofstream Salida("definitivas.txt");
  for (int i = 0; i < 3; i++) {
    Salida << "\t === definitivas estudiante ===";
    Salida << endl;
    Salida << endl;
    Salida << "Estudiante "<<i+1<<": ";
    Salida << endl;
    Salida << " Definitiva 1 30%: " << Notas[i].definitiva1;
    Salida << endl;
    Salida << " Definitiva 2 30%: " << Notas[i].definitiva2;
    Salida << endl;
    Salida << " Definitiva 3 40%: " << Notas[i].definitiva3;
    Salida << endl;
    Salida << endl;
  }
}

void Estadisticas(NotasEstudiante Notas[3]) {
  ofstream Salida("estadisticas.txt");
  for (int i = 0; i < 3; i++) {
  	double sumatoria = Notas[i].definitiva1 + Notas[i].definitiva2 + Notas[i].definitiva3;
  	double promedio = (Notas[i].definitiva1 + Notas[i].definitiva2 + Notas[i].definitiva3)/3;

  	
    Salida << "\t === estadisticas estudiante ===";
    Salida << endl;
    Salida << endl;
    Salida << "Estudiante "<<i+1<<": ";
    Salida << endl;
    Salida << " Sumatoria: " << Notas[i].definitiva1<<" + "<<Notas[i].definitiva2<<" + "<<Notas[i].definitiva1<<" = "<<sumatoria<< endl;
    Salida << " Promedio: " <<"("<< Notas[i].definitiva1<<" + "<<Notas[i].definitiva2<<" + "<<Notas[i].definitiva1<<")/3" <<" = "<<promedio;
    Salida << endl;
    Salida << endl;
  }
}



int main() {
  NotasEstudiante Notas[3];
  Asignacion(Notas);
  Minimo(Notas);
  Definitiva(Notas);
  Imprimir(Notas);
  Estadisticas(Notas);
  cout << endl;
  cout << endl;
  system("pause");
  return 0;
}
