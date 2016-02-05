#include<iostream> 
#include<cstdlib>

using std::endl; 
using std::cin; 
using std::cout; 

void scores(int [],int); 
void llenar(int [],const int);
void imprimir(int [],const int);  
void agregar(int [],const int, int); 

int main(int argc, char*argv[]){
	const int tamanio=10; 
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
			
	}

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
