#include<iostream> 
#include<cstdlib>

using std::endl; 
using std::cin; 
using std::cout; 
//funciones ejercicio 1
void scores(int [],int); 
void llenar(int [],const int);
void imprimir(int [],const int);  
void agregar(int [],const int, int); 

//funciones ejercicio 2

 


int main(int argc, char*argv[]){
	const int columnas=3; 
	const int filas =4; 
	const int tamanio=10; 
	int matriz[filas][columnas]; 
	int jugador[2][3]; 
	int score[tamanio];
	int think;  
	srand(time(NULL)); 
	int magic= rand()%1000-500; 
	cout<<magic<<endl; 	
	int contador=0; 
	llenar(score,tamanio); 
	char op; 
	//-----------------------------------inicio--------------------------------
	int ejercicio; 
	cout<<"Que ejercicio desea Jugar?? \n"
	    <<"1. Ejercicio 1\n2. Ejercicio 2"<<endl; 

	cin>>ejercicio; 
	if(ejercicio ==1){
	while(op != 's'){
	while(magic != think ){
		 cout<<"Ingrese el numero que piensa que es el correcto"<<endl; 
		 cin>>think; 
		if(think == magic){
			cout<<"Fuck You are WInner!!!!!!!"<<endl;
			break; 
			 	
		}
		if(magic>think){
			cout<<"mmmm .... es mas Grande la espuesta"<<endl; 
				
		}else{
			cout<<"mmmmm es mas Pequeña la respuesta la verdad"<<endl; 
		}

		contador++; 
		
	}	
		think=0;
		magic=rand()%1000-500;  	
		scores(score,tamanio);
		//---------------------------
		agregar(score,tamanio,contador); 
		contador=0; 	
		cout<<"Si desea Salir Envie s sino presione cualquier tecla"<<endl; 
		cin>>op; 
		
	}

	imprimir(score,tamanio); 
	}

	if(ejercicio==2){

		//llenar arreglo de columnas
		
		for(int i=0;i<filas;i++){
			matriz[i][0]=rand()%115+85;
		 }
		for(int i=0; i<filas;i++){
		        matriz[i][1]= rand()%75+50;
		}
		for(int i=0; i<filas;i++){
			matriz[i][2]=rand()%200+150;
	        }

		//Eleccion de jugador 1
		cout<<"Jugador 1: "<<endl; 
		for(int i=0; i<columnas;i++){
			jugador[0][i]=matriz[rand()%filas][i];
			
		}
		cout<<"ataque: "<<jugador[0][0]<<"  Defensa: "<<jugador[0][1]
		    <<"  Velocidad: "<<jugador[0][2]<<endl;  

		//Eleccion de jugador 2 

		cout<<"Jugador 2: "<<endl;
		for(int i=0; i<columnas;i++){
			 jugador[1][i]=matriz[rand()%filas][i];
	        }
		cout<<"ataque: "<<jugador[1][0]<<"  Defensa: "<<jugador[1][1]
		    <<"  Velocidad: "<<jugador[1][2]<<endl;

		//resta de defensa
		cout<<"Los puntos del Jugador 1: "<<jugador[0][0]-jugador[1][1]<<endl; 
		cout<<"Los puntos del jugador 2: "<<jugador[1][0]-jugador[0][1]<<endl; 

		if((jugador[0][0]-jugador[1][1])>(jugador[1][0]-jugador[0][1])){
			cout<<"El ganador es el jugado 1"<<endl
			    <<"Gano por diferencia de Ataque no por velocidad"<<endl
			    <<"La diferencia de puntos es: "<<(jugador[0][0]-jugador[1][1])-(jugador[1][0]-jugador[0][1])
			    <<endl; 	  
		}
		else{
		cout<<"El jugador ganador es el jugador 2"<<endl 	
			    <<"Gano por diferencia de ataque no por velocidad"<<endl
			    <<"La diferencia de putnos es: "<<(jugador[1][0]-jugador[0][1])-(jugador[0][0]-jugador[1][1])
			    <<endl; 
			 
		}
		
		if((jugador[0][0]-jugador[1][1])==(jugador[1][0]-jugador[0][1])){
			cout<<"EMPATE!!!!!"<<endl; 
			if(jugador[0][2]>jugador[1][2]){
				cout<<"El jugador 1. ha ganado por diferencia de velocidad"<<endl; 		
			}
			else
			{
				cout<<"El jugador 2. ha ganado por diferencia de velocidad"<<endl;
			}
		}
					 
			
	} // fin segundo if de la eleccion de los ejercicios

	return 0; 	


}

void llenar(int score[],const int a){
	for(int i=0; i<a;i++){
		score[i]=999;  	
	}
}

void imprimir(int score[],const int a)
{	
	cout<<"-------------------------------High Scores-------------------------------"<<endl;
	for(int i=0; i<a; i++){
		cout<<score[i]<<endl; 
	}
}
void scores(int score[], const int a){
	int temp=0; 
	for(int i=0; i<a;i++){
		for(int j=0; j<(a-1);j++){
			if(score[j] > score[j+1]){
				temp=score[j];
				score[j]=score[j+1];
				score[j+1]=temp;
			}
				
		}	
	}	
}

void agregar(int score[],const int a,int contador){
	for(int i=0; i<a;i++){
		if(contador<score[i]){
			score[i]=contador; 
			break; 	
		}
	}
}


