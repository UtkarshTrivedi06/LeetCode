#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const int MAX_AIRPORTS = 301;
const int IATA_LEN = 3;

typedef struct {
    char to[4];
} Dest;

typedef struct {
    char from[4];
    Dest* dests;
    int count;
    int used_count;
} Airport;

Airport A[301];
int A_S = 0;

char** IT;
int IT_S = 0;
int TICKETS_COUNT;

int cmp_dest(const void *a, const void *b) {
    return strcmp(((Dest*)a)->to, ((Dest*)b)->to);
}

Airport* get_airport(const char* from) {
    for (int i = 0; i < A_S; i++) {
        if (strcmp(A[i].from, from) == 0) {
            return &A[i];
        }
    }
    if (A_S < MAX_AIRPORTS) {
        Airport* a = &A[A_S++];
        strcpy(a->from, from);
        a->dests = NULL;
        a->count = 0;
        a->used_count = 0;
        return a;
    }
    return NULL;
}

void dfs(char* u) {
    Airport* a = get_airport(u);
    if (a == NULL) return;
    
    while (a->used_count < a->count) {
        char* v = a->dests[a->used_count++].to;
        
        char next_u[4];
        strcpy(next_u, v);

        dfs(next_u);
    }

    IT[IT_S++] = strdup(u);
}

char** findItinerary(char*** tickets, int ticketsSize, int* ticketsColSize, int* returnSize) {
    TICKETS_COUNT = ticketsSize;
    IT = (char**)malloc((TICKETS_COUNT + 1) * sizeof(char*));
    IT_S = 0;
    A_S = 0; 
    
    for(int i = 0; i < TICKETS_COUNT; i++) {
        Airport* a = get_airport(tickets[i][0]);
        if (a) a->count++;
    }

    for (int i = 0; i < A_S; i++) {
        A[i].dests = (Dest*)malloc(A[i].count * sizeof(Dest));
        A[i].count = 0;
        A[i].used_count = 0;
    }

    for(int i = 0; i < TICKETS_COUNT; i++) {
        Airport* a = get_airport(tickets[i][0]);
        if (a) {
            strcpy(a->dests[a->count].to, tickets[i][1]);
            a->count++;
        }
    }

    for (int i = 0; i < A_S; i++) {
        if (A[i].count > 0) {
            qsort(A[i].dests, A[i].count, sizeof(Dest), cmp_dest);
        }
    }

    char start[] = "JFK";
    dfs(start);

    for (int i = 0; i < IT_S / 2; i++) {
        char* tmp = IT[i];
        IT[i] = IT[IT_S - 1 - i];
        IT[IT_S - 1 - i] = tmp;
    }

    for (int i = 0; i < A_S; i++) {
        if (A[i].dests) free(A[i].dests);
    }
    
    *returnSize = IT_S;
    return IT;
}