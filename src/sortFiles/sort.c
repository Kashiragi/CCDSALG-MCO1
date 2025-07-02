#include "sort.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Define PI constant
#define PI 3.14159265358979323846

Point anchor;  // define the extern from sort.h

/**
 * computePolarAngle:
 *   Computes the angle (in radians) between the line from p1 to p2
 *   and the positive x-axis, normalized to [0, 2p).
 */
double computePolarAngle(Point p1, Point p2) {
    double dx = p2.x - p1.x, dy = p2.y - p1.y;
    double angle = atan2(dy, dx);
    if (angle < 0) angle += 2 * PI;
    return angle;
}

/**
 * computeDistance:
 *   Returns the Euclidean distance between p1 and p2.
 */
double computeDistance(Point p1, Point p2) {
    double dx = p2.x - p1.x, dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

/**
 * comparePoints:
 *   Compares two points a and b based on their polar angle
 *   around the global 'anchor' point, breaking ties by distance.
 */
int comparePoints(Point a, Point b) {
    double angleA = computePolarAngle(anchor, a);
    double angleB = computePolarAngle(anchor, b);
    if (angleA < angleB) return -1;
    if (angleA > angleB) return 1;
    double distA = computeDistance(anchor, a);
    double distB = computeDistance(anchor, b);
    if (distA < distB) return -1;
    if (distA > distB) return 1;
    return 0;
}

/**
 * selectionSort:
 *   A simple O(n²) “slow” sort that repeatedly selects the
 *   next-smallest point (by polar order) and swaps it into place.
 */
void selectionSort(Point points[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (comparePoints(points[j], points[minIdx]) < 0) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            Point tmp = points[i];
            points[i] = points[minIdx];
            points[minIdx] = tmp;
        }
    }
}

/**
 * mergeSort:
 *   A divide-and-conquer O(n log n) “fast” sort using merge sort.
 */
void mergeSort(Point points[], int n) {
    Point *temp = malloc(n * sizeof(Point));
    if (!temp) {
        fprintf(stderr, "mergeSort: out of memory\n");
        return;
    }
    mergeSortHelper(points, temp, 0, n - 1);
    free(temp);
}

void mergeSortHelper(Point points[], Point temp[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(points, temp, left, mid);
        mergeSortHelper(points, temp, mid + 1, right);
        merge(points, temp, left, mid, right);
    }
}

void merge(Point points[], Point temp[], int left, int mid, int right) {
    for (int i = left; i <= right; i++)
        temp[i] = points[i];
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (comparePoints(temp[i], temp[j]) <= 0)
            points[k++] = temp[i++];
        else
            points[k++] = temp[j++];
    }
    while (i <= mid) points[k++] = temp[i++];
    while (j <= right) points[k++] = temp[j++];
}

/**
 * findAndSetAnchor:
 *   Finds the lowest-then-leftmost point,
 *   swaps it into points[0], and sets the global anchor.
 */
void findAndSetAnchor(Point points[], int n) {
    if (n < 1) return;
    int minIdx = 0;
    anchor = points[0];
    for (int i = 1; i < n; i++) {
        if (points[i].y < anchor.y ||
           (points[i].y == anchor.y && points[i].x < anchor.x)) {
            anchor = points[i];
            minIdx = i;
        }
    }
    if (minIdx != 0) {
        Point tmp = points[0];
        points[0] = points[minIdx];
        points[minIdx] = tmp;
    }
}

/**
 * sortPointsByPolarAngle:
 *   1) findAndSetAnchor,
 *   2) then sort points[1..n-1] by polar angle
 *      using either selectionSort (slow) or mergeSort (fast).
 */
void sortPointsByPolarAngle(Point points[], int n, int useSelectionSort) {
    if (n < 2) return;
    findAndSetAnchor(points, n);
    if (useSelectionSort)
        selectionSort(points + 1, n - 1);
    else
        mergeSort(points + 1, n - 1);
}
