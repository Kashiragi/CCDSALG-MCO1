#ifndef SORT_H
#define SORT_H
#include <math.h>
#include "globals.h"

double computePolarAngle(Point p1, Point p2);
double computeDistance(Point p1, Point p2);
int comparePoints(Point a, Point b);

void selectionSort(Point points[], int n);
void mergeSort(Point points[], int n);

void mergeSortHelper(Point points[], Point temp[], int left, int right);
void merge(Point points[], Point temp[], int left, int mid, int right);

#endif 
