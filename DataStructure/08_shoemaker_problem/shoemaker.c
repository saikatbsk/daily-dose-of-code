/*
 * A shoemaker has N orders from customers that he must execute. The shoemaker can work on only one job each day.
 * For each job i, it takes Ti days for the shoemaker to finish the job, where Ti is an integer and (1 ≤ Ti ≤ 1000).
 * For each day of delay before starting to work for the job i, shoemaker pays a fine of Si (1 ≤ Si ≤ 10000) rupees.
 * Our task is to help the shoemaker find the sequence in which to complete the jobs so that his total fine is
 * minimized. If multiple solutions are possible, print the one that is lexicographically least
 * (i.e., earliest in dictionary order).
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXJOBS       100000
#define MAXTURNAROUND 1000
#define MAXPENALTY    10000

int N;                  //-- number of jobs to be done

typedef struct job_t {
    int id;             //-- job id
    int turnaround;     //-- turnaround time for job
    int penalty;        //-- penalty per day
} job_t;

void merge(job_t arr[], int start, int end) {
    int mid;
    int l, i, j;
    job_t tempArr[N];

    mid = (start + end) / 2;
    l = start;
    i = start;
    j = mid + 1;

    while(i <= mid && j <= end) {
        int p = arr[i].penalty * arr[j].turnaround;
        int q = arr[j].penalty * arr[i].turnaround;

        if(p < q) {
            tempArr[l++] = arr[i++];
        }
        else {
            tempArr[l++] = arr[j++];
        }
    }

    if(i > mid) {
        for(; j <= end ;) {
            tempArr[l++] = arr[j++];
        }
    }
    else if(j > end) {
        for(; i <= mid ;) {
            tempArr[l++] = arr[i++];
        }
    }

    for(l = start ; l <= end ; l++) {
        arr[l] = tempArr[l];
    }
}

/* we use merge sort as it is a stable sorting algorithm */
void mergeSort(job_t arr[], int start, int end) {
    int mid;

    if(start >= end) {
        return;
    }
    else {
        mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, end);
    }
}

int main() {
    int i;

    printf("Number of jobs? (<%d) ", MAXJOBS);
    scanf("%d", &N);

    if(N <= 0 || N > MAXJOBS) {
        printf("Number of jobs should be in range 1 to %d\n", MAXJOBS);
        exit(0);
    }

    job_t job[N];       //-- jobs are of type job_t

    printf("Enter turnaround and penalty for each job:\n");
    for(i = 0 ; i < N ; i++) {
        //printf("Enter for Job #%d: ", i);
        scanf("%d %d", &job[i].turnaround, &job[i].penalty);

        if(job[i].penalty <= 0 || job[i].penalty > MAXPENALTY ||
                job[i].turnaround <= 0 || job[i].turnaround > MAXTURNAROUND) {
            printf("Turnaround or penalty limit exceeded!\n");
            exit(0);
        }

        job[i].id = i + 1;
    }

    /*
     * we know that the higher the ratio of penalty to time, the earlier a job should be.
     */
    int LAST = N - 1;
    mergeSort(job, 0, LAST);

    printf("Jobs in sorted order:\n");
    while(LAST >= 0) {
        printf("%d\n", job[LAST].id);
        LAST--;
    }

    return 0;
}
