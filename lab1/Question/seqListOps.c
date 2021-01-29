/***********file:   Ops.c *********/
#include <stdio.h>
#include "storage.h"
#include "compare.h"

int nextfreeloc = 0;
Store st;

SeqList createlist()
{
    SeqList sl;
    sl.head = nextfreeloc++;
    sl.size = 0;
    st[sl.head].next = -1;
    return (sl);
}

void printJob(Job j)
{
    printf("JOB ID = %d, Priority = %d, Execution time = %d, Arrival time = %d \n", j.id, j.pri, j.et, j.at);
}

int inputJobs(JobList list)
{
    int i;
    int size;

    printf("\n Enter the Number of Jobs: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        printf("\nEnter job ID: ");
        scanf("%d", &list[i].id);
        printf("Enter Priority (from 0 - 2): ");
        scanf("%d", &list[i].pri);
        printf("Execution Time: ");
        scanf("%d", &list[i].et);
        printf("Arrival Time: ");
        scanf("%d", &list[i].at);
    }
    return size;
}

SeqList insert(Job j, SeqList sl)
{
    // Implement this function

    int i, pos;

    for (i = sl.head; st[i].next != -1; i = st[i].next)
    {
        if (compare(st[st[i].next].ele, j) == GREATER)
            break;
    }

    pos = nextfreeloc++;
    st[pos].ele = j;
    st[pos].next = st[i].next;
    st[i].next = pos;
    sl.size++;

    return sl;
}

void insertelements(JobList list, int size, SeqList s[3])
{
    // Implement this function

    // for (int i = 0; i < size; i++)
    // {
    //     switch (list[i].pri)
    //     {
    //     case PRI_0:
    //         s[0] = insert(list[i], s[0]);
    //         break;
    //     case PRI_1:
    //         s[1] = insert(list[i], s[1]);
    //         break;
    //     case PRI_2:
    //         s[2] = insert(list[i], s[2]);
    //         break;
    //     }
    // }

    // assignment task
    // traverse list three times, insert priority-wise
    for (int i = 2; i >= 0; i--) {
        for (int j = 0; j < size; j++) {
            if (list[j].pri == i)
                s[i] = insert(list[j], s[i]);
        }
    }
}

void copy_sorted_ele(SeqList s[3], JobList ele)
{
    // Implement this function
    int j, k, i = 0;

    for (j = 2; j >= 0; j--)
    {
        for (k = st[s[j].head].next; st[k].next != -1; k = st[k].next)
        {
            ele[i] = st[k].ele;
            i++;
        }
        ele[i] = st[k].ele;
        i++;
    }
}

void printlist(SeqList sl)
{
    // Implement this function

    for (int i = st[sl.head].next; st[i].next != -1; i = st[i].next)
        printJob(st[i].ele);
}

void printJobList(JobList list, int size)
{
    // Implement this function

    for (int i = 0; i < size; i++)
        printJob(list[i]);
}

void sortJobList(JobList list, int size)
{
    SeqList seq[3];
    seq[0] = createlist();
    seq[1] = createlist();
    seq[2] = createlist();
    insertelements(list, size, seq);
    // printlist(seq[0]);
    // printlist(seq[1]);
    // printlist(seq[2]);
    copy_sorted_ele(seq, list);
}
