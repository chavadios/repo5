//********************************************************************//
//JOSE ARMANDO DIAZ CHAVARIN
//PRACTICA5 A
//********************************************************************//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0

typedef struct _tdato{
	int dato;
	struct _tdato *sig;
}stdato;
typedef stdato *Tdato;

void AddlistaC( Tdato *comienzo, Tdato *nuevo, Tdato *ultimo );
Tdato BorrarListaC( Tdato *comienzo, Tdato *ultimo, int num);
Tdato BuscarListaC(Tdato comienzo, int num);
void PrintlistaC( Tdato comienzo, Tdato ultimo );
void LiberarMemoria( Tdato *comienzo );
Tdato Gendatos();
void Servicio(Tdato temp);
int LeeNum(int ri, int rs, char *msg, char *msgError);
void menu();
//********************************************************************//
int main(){
	menu();
	return 0;
}
//********************************************************************//
void menu ()
{
    int choose, op, num,nums, flag=0;
    srand((0));
    Tdato nuevo=NULL, comienzo=NULL, ultimo=NULL, temp=NULL;
	printf("Practica #5-a lista Circular \n");
	do{
	printf("M  E  N  U\n");
	printf("1.- Agregar(Manual) \n");
	printf("2.- Eliminar \n");
	printf("3.- Buscar \n");
	printf("4.- Imprimir \n");
	printf("5.- Salir \n");
	choose=LeeNum(1,5,"\nEscoge una opcion","Opcion fuera del rango");
	  switch(choose)
	    {
               case 1:
		               	system ("cls");
		               	nums=LeeNum(340000,399999,"Introduce el numero", "FUERA DE RANGO");
		               	nuevo=Gendatos(nums);
		               	AddlistaC( &comienzo, &nuevo, &ultimo);
		               	
		               	printf( "Dato introducido agregado a la lista correctamente\n" );
		               	flag=1;
		                break;
               
               case 2:
		               	system ("cls");
		               	if( flag==0 )
		               	{
		               		printf( "No se han agregado datos a la lista \n" );
						}
						else
						{
							num=LeeNum( 340000, 349999, "Ingrese el dato que desea eliminar \n", "Error, dato invalido" );
							temp=BorrarListaC( &comienzo, &ultimo, num );
							if(temp)
							{
								printf( "Dato eliminado de la lista \n" );
							}
							else
							{
								
								printf( "No existe el dato en la lista \n" );
							}
						}
					   break;
			   
			   case 3:
					   	system ("cls");
					   	if( flag==0 )
		               	{
		               		printf( "No hay datos a la lista \n" );
						}
						else
						{
							num=LeeNum(340000, 349999, "Ingrese el dato que desea buscar \n", "Error, dato invalido");
							temp=BuscarListaC( comienzo, num );
							if(temp)
							{
								printf( "Datos encontrados en la lista: " );
								Servicio(temp);
							}
							else
							{
								printf( "No hay datos a la lista \n" );
							}
						}
					   break;
			   
			   case 4:
					   	system ("cls");
					   	printf( "Datos introducido en la lista \n" );
					   	if( flag==0 )
		               	{
		               		printf( "No hay datos a la lista \n" );
						}
						else
						{
							PrintlistaC( comienzo, ultimo );
						}
					    break;
			   
			   case 5:
					   	system ("cls");
					   	while( comienzo != ultimo )
					   	{
						   LiberarMemoria( &comienzo );
						}
						printf("Memoria liberada \n");
					   	op=1;
					    break;
					    
		                default:
		                printf( "Opcion  invalida \n" );
		                break;
		}
		system("pause");
		system("CLS");
	}while(op!=1);
	
}
//********************************************************************//
void AddlistaC( Tdato *comienzo, Tdato *nuevo, Tdato *ultimo){
	Tdato temp=NULL;
	if( !*comienzo ) 
	{
		*comienzo = *nuevo;
		*ultimo = *nuevo;
		(*ultimo)->sig = *comienzo;
	}
	else
	{
		if( (*nuevo)->dato < (*comienzo)->dato)
		{
			(*nuevo)->sig = *comienzo; 
			*comienzo = *nuevo; 
			( *ultimo )->sig = *comienzo;
		}
		else
		{
			if((*nuevo)->dato > (*ultimo)->dato) 
			{
				(*ultimo)->sig = *nuevo;
				*ultimo = *nuevo;
				( *ultimo)->sig = *comienzo;
			}
			else
			{
				temp = *comienzo;
				while ((temp->sig)->dato < (*nuevo)->dato)
				{
					temp = temp->sig;
				}
				(*nuevo)->sig = temp->sig;
				temp->sig = *nuevo;
				*nuevo = NULL;
			}
		}
	}
}
//********************************************************************//
Tdato BorrarListaC( Tdato *comienzo, Tdato *ultimo, int num){
	int band = FALSE;
	Tdato temp=NULL, nodo=NULL;
	if(*comienzo)
	{
		if( (*comienzo)->dato == num)
		{
			if(*comienzo == *ultimo)
			{
				nodo = *comienzo;
				*comienzo = NULL;
				*ultimo = NULL;
			}
			else
			{
				nodo = *comienzo;
				*comienzo = (*comienzo)->sig;
				(*ultimo)->sig = *comienzo;
				nodo->sig = NULL;
			}
		}
		else
		{
			temp = *comienzo;
			if((*ultimo)->dato < num)
			{
				return nodo;
			}
			else
			{
				band = FALSE;
				temp = (*comienzo);
			}
			do
			{
				if((temp->sig)->dato < num)
				{
					temp = temp->sig;
				}
				else
				{
					band = TRUE;
				}
			}while(band == FALSE);
			if(num == (temp->sig)->dato)
			{
				nodo = temp->sig;
				temp->sig = nodo->sig ;
				if(nodo == (*ultimo))
				{
					(*ultimo) = temp;
				}
				nodo->sig = NULL;
			}
			else
			{
				return nodo = NULL;
			}
		}
	}
}
//********************************************************************//
Tdato BuscarListaC(Tdato comienzo, int num)
{
  Tdato temp = NULL;
  temp = comienzo;
  if(temp)
    {
      do
        {
          if(temp->dato <= num)
            {
              if(temp->dato == num)
                {
                  return temp;
                }
              temp = temp->sig;
            }
          else
            {
              return temp = NULL;
            }
        }
      while(temp != comienzo);
    }
  return temp = NULL;
}
//********************************************************************//
void PrintlistaC(Tdato comienzo, Tdato ultimo){
	Tdato temp=NULL;
	temp = comienzo;
	if(temp)
	{
		do
		{
			Servicio(temp);
			temp = (temp)->sig;
		}while(temp != comienzo);
	}
}
//********************************************************************//
void LiberarMemoria( Tdato *comienzo )
{
	Tdato temp = NULL;
	temp = (*comienzo);
	(*comienzo) = temp->sig;
	free(temp);
}
//********************************************************************//
Tdato Gendatos(int num){
	Tdato nodo=NULL;
    nodo=(Tdato)malloc(sizeof(stdato));
    nodo->dato=num;
    nodo->sig=NULL;
    return nodo;
}
//********************************************************************//
void Servicio(Tdato temp){
	printf("%d\n",temp->dato);
}
//********************************************************************//
int LeeNum(int ri, int rs, char *msg, char *msgError)
{
	char xnum[30];
	int num;
	do
	{
		puts(msg);
		fflush(stdin);
		gets(xnum);
		num = atoi(xnum);
		if (num<ri || num>rs)
		{
			puts(msgError);
			system("pause");
		}
	} while (num<ri || num>rs);
	return num;
}
