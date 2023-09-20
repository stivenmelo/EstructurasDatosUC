#include <stdlib.h>
#include <stdio.h>
#define localizar (struct nodo *) malloc(sizeof(struct nodo))

void Insertar(struct nodo **);
void Eliminar(struct nodo **);
void Imprimir(struct nodo *);

struct nodo
{
	int info;
	struct nodo *sig;	
};

main ()
{
	struct nodo *cab = NULL;
	int opc;
	while (opc != 3)
	{
		printf("\n1. Insertar \n2. Eliminar \n3. Salir \n");
		scanf("%d", &opc);
		
		if(opc == 1)
		{
			Insertar(&cab);
		}
		if(opc == 2)
		{
			Eliminar(&cab);
		}
	}
	getchar();
}

void Insertar (struct nodo **cab)
{
	int num;
	struct nodo *q;
	
	printf("Escriba el dato:\t");
	scanf("%d", &num);
	
	if(*cab == NULL)
	{
		q = localizar;
		*cab = q;
		q->info = num;
		q->sig = NULL;
		
	}
	
	else
	{
		q = localizar;
		q->info = num;
		q->sig = *cab;
		*cab = q;
	}
	Imprimir(*cab);
}

void Eliminar (struct nodo **cab)
{
	struct nodo *q;
	
	if(*cab == NULL)
	{
		printf("\nLista vacia\n");
		
	}
	else
	{
		q=*cab;
		if(q->sig == NULL)
		{
			printf("\nEl valor eliminado es: %d\n", q->info);	
			//	free (q);
			delete q;
			*cab = NULL;
		}
		else
		{
			printf("\nEl valor eliminado es: %d\n", q->info);	
			*cab=q->sig;
			free (q);	 // libera el valor de la memoria que no se va a utilizar
		}	
	}
	Imprimir(*cab);
}

void Imprimir(struct nodo *cab)
{
	printf ("La lista es:\n");
	while (cab != NULL)
	{
		printf("\n%d\n", cab->info);
		cab = cab->sig;
	}
}
