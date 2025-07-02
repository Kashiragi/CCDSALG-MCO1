#include "globals.h"
#ifndef SORT_H
#define SORT_H


double computePolarAngle(Point p1, Point p2);
double computeDistance(Point p1, Point p2);
int comparePoints(Point a, Point b);

void selectionSort(Point points[], int n);
void mergeSort(Point points[], int n);
void mergeSortHelper(Point points[], Point temp[], int left, int right);
void merge(Point points[], Point temp[], int left, int mid, int right);

void findAndSetAnchor(Point points[], int n);
void sortPointsByPolarAngle(Point points[], int n, int useSelectionSort);

#endif // SORT_H

