#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "sput.h"

typedef struct DymArr {
	int* Data;
	int Size;
	int CountElements;
}DymArr;

DymArr* CreateDymArray(int size);

void AddElements(DymArr* arr, int value);
void PrintArr(DymArr* arr);

void BubbleSortArr(DymArr* Arr);