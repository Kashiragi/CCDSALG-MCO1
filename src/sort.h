/**
 * stack.h contains the functions for the sorting algorithms used in the graham scan.
 * 
 * @author Salao, Queenie
*/
#ifndef SORT_H
#define SORT_H
#include "globals.h"

/**
 * Computes the polar angle between two points 
 * 
 * @param p1 the first point
 * @param p2 the second point
 * 
 * @return angle of the two points 
 */
double computePolarAngle(Point p1, Point p2);

/**
 * Computes the distance between two points
 * 
 * @param p1 the first point
 * @param p2 the second point
 * 
 * @return distance of the two points 
 */
double computeDistance(Point p1, Point p2);

/**
 * Compares the two points with respect to their angle first. If their angles are the same,
 * then the next basis is the distance between the two points.
 * 
 * @param a the first point
 * @param b the second point
 * 
 * @return 1 if point a > point b (angle or distance), -1 if a < b; otherwise, 0
 */
int comparePoints(Point a, Point b);

/**
 * Sorts the points by polar angle, by taking the smallest element from the unsorted part
 * and swapping it with the first unsorted element.
 * 
 * @param points the array containing the points to be sorted
 * @param n the number of points to be sorted
 * 
 * @note Slow algorithm for Group 52
 */
void selectionSort(Point points[], int n);

/**
 * Sorts the points by polar angle, using a divide-and-conquer strategy. It recursively
 * divides the list into smaller sub-lists, sorts those, then merges all to form the sorted
 * list.
 * 
 * @param points the array containing the points to be sorted
 * @param n the number of points to be sorted
 * 
 * @note Fast algorithm for group 52
 */
void mergeSort(Point points[], int n);

/**
 * mergeSortHelper is a helper function that recursively divides the points
 * 
 * @param points the original array to be sorted
 * @param temp temporary array to be used during the sorting process
 * @param left the index of the left half of the "sub-list"
 * @param right the index of the right half of the "sub-list"
 */
void mergeSortHelper(Point points[], Point temp[], int left, int right);
/**
 * merge is a helper function that sorts the points based on the left, mid, right values
 * 
 * @param points the original array to be sorted
 * @param temp temporary array to be used during the sorting process
 * @param left the index of the left half of the "sub-list"
 * @param mid the index of the middle to determine division
 * @param right the index of the right half of the "sub-list"
 */
void merge(Point points[], Point temp[], int left, int mid, int right);

#endif // SORT_H

