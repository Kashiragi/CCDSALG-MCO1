#include "sort.h"

// contains the slow and fast sorting algo

// Function implementation

/**
 * computePolarAngle:
 *   Computes the angle (in radians) between the line from p1 to p2
 *   and the positive x-axis, normalized to [0, 2π).
 */
double computePolarAngle(Point p1, Point p2) {
    double dx = p2.x - p1.x, dy = p2.y - p1.y;
    double angle = atan2(dy, dx);
    if (angle < 0) {
        angle += 2 * M_PI;
    }
    return angle;
}

/**
 * computeDistance:
 *   Returns the Euclidean distance between p1 and p2.
 */
double computeDistance(Point p1, Point p2) {
    double dx = p2.x - p1.x, dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

/**
 * comparePoints:
 *   Compares two points a and b based on their polar angle
 *   around the global 'anchor' point, breaking ties by distance.
 *
 *   Returns:
 *     <0 if a comes before b,
 *      0 if they are equivalent,
 *     >0 if b comes before a.
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


// slow sorting algo

/**
 * selectionSort:
 *   A simple O(n²) “slow” sort that repeatedly selects the
 *   next-smallest point (by polar order) and swaps it into place.
 */
void selectionSort(Point points[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (comparePoints(points[j], points[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Point tmp = points[i];
            points[i] = points[minIndex];
            points[minIndex] = tmp;
        }
    }
}


// fast sorting algo

/**
 * mergeSort:
 *   A divide-and-conquer O(n log n) “fast” sort using merge sort.
 */
void mergeSort(Point points[], int n) {
    Point *temp = malloc(n * sizeof(Point));
    if (!temp) {
        fprintf(stderr, "Error: Memory allocation failed in mergeSort\n");
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
    for (int i = left; i <= right; i++) {
        temp[i] = points[i];
    }
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (comparePoints(temp[i], temp[j]) <= 0) {
            points[k++] = temp[i++];
        } else {
            points[k++] = temp[j++];
        }
    }
    while (i <= mid) {
        points[k++] = temp[i++];
    }
    while (j <= right) {
        points[k++] = temp[j++];
    }
}
