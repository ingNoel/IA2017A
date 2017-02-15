// IA2017A.cpp: 

#include "stdafx.h"
template <typename T>
struct DYNARRAY
{
	T *pBasePointer; //Puntero base
	int nsize;		//Numero de elmentos en el arreglo
	int nAllocated; // Espacio de elementos reservados en el arreglo.
	int nGrow;		//Porcentaje de crecimiento
	static void DYNARRAY* Create(int nInitialSize, int nInitialGrow);
	{
		DYNARRAY *pNew = new DYNARRAY;
		pNew->pBasePointer = new T[nInitialiSize];
		pNew->nSize = nInitialiSize;
		pNew->nGrow = nInitialGrow;
		return pNew;
	}
	static void Destroy(DYNARRAY* pToDestroy);
	{
		delete[] pToDestroy->pBasePointer;
		delete pToDestroy;
	}
	void PushBack(T Value);
	{
		if ((nSize + 1) > nAllocated)//no hay espacio
		{
			//redimensonar el arreglo
			nAllocated = nAllocated + nAllocated*nGrow / 100;
			T* pNewArray = new T[nAllocated];
			memcpy(pNewArray, pBasePointer, nSize * sizeof(T));
			delete[] pBasePointer;
			pBasePointer = pNewArray; 
		}
		pBasePointer[nsize++] = Value; //Incremento y copia (insertar al final de un arreglo, cambia su tamaño automáticamente)
	}
	T& operator[] (int nIndex);
	{
		return pBasePointer[int nIndex];
		//ó return *(T*)((char*)pBasePointer + sizeof(T)*nIndex);
	}
};



int main()
{
	DYNARRAY <float> *pMyArray = DYNARRAY <float>::Create(10, 10); //Los quieres flotantes? arre
	pMyArray->PushBack(3.4);
	pMyArray->PushBack(0.4);
	pMyArray->PushBack(-3.4);
	pMyArray->PushBack(1);
	pMyArray->PushBack(3.4);
	pMyArray->PushBack(3.4);
	pMyArray->PushBack(3.4);
	pMyArray->PushBack(3.4);
	pMyArray->PushBack(3.4);
	pMyArray->PushBack(3.4);
	pMyArray->PushBack( 3.4);
	//Si quieres meter un dato en la 11ava posición estás violando las condiciones del arreglo, para ello se usa:

    return 0;
}

