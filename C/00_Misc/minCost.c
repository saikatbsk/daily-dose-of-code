#include <stdio.h>
#include <stdlib.h>

int cost(int start, int end, int* g_from, int* g_to, int* g_weight, int g_edges) {
    for(int i=0 ; i<g_edges ; i++) {
        if(g_from[i]==start && g_to[i]==end) {
            return g_weight[i];
        }
    }

    return 0;
}

int min(int x, int y) {
    return ((x < y) ? x : y);
}

/* =============================================================================

Variables:
----------
g_nodes = number of nodes
g_edges = number of edges
g_weight[i] = weight of edge connecting nodes g_from[i] and g_to[i]
start = start from
end = end at

Input format:
-------------
Line 1: g_nodes g_edges
Line 2 to (g_edges+1): g_from[i] g_to[i] g_weight[i]
Line (g_edges+1)+1: start
Line (g_edges+1)+2: end


Example input #1:
-----------------
4 4
1 2 2
2 3 1
2 4 2
3 4 3
1
4

Expected output #1:
-------------------
4

============================================================================= */

int minCost(int g_nodes, int g_edges, int* g_from, int* g_to, int* g_weight, int start, int end) {
    int cost_start_end = cost(start, end, g_from, g_to, g_weight, g_edges);

    if(start == end) // reached end
        return 0;

    else if(cost_start_end > 0) // there exists an edge
        return cost_start_end;

    else {
        int pt1 = 0;
        int pt2 = 0;

        int cost1 = cost(start, start+1, g_from, g_to, g_weight, g_edges);
        int cost2 = cost(start, start+2, g_from, g_to, g_weight, g_edges);

        if(cost1 > 0)
            pt1 = (cost1 + minCost(g_nodes, g_edges, g_from, g_to, g_weight, start+1, end));

        if(cost2 > 0)
            pt2 = (cost2 + minCost(g_nodes, g_edges, g_from, g_to, g_weight, start+2, end));

        if(pt1 == 0)
            return pt2;
        else if(pt2 == 0)
            return pt1;
        else
            return min(pt2, pt1);
    }
}


int main() {
    int res;

    int _g_nodes = 0;
    int _g_edges = 0;

    scanf("%d %d\n", &_g_nodes, &_g_edges);

    int _g_from[_g_edges];
    int _g_to[_g_edges];
    int _g_weight[_g_edges];

    int _g_i;
    for (_g_i = 0; _g_i < _g_edges; _g_i++) {
    	scanf("%d %d %d\n", &_g_from[_g_i], &_g_to[_g_i], &_g_weight[_g_i]);
    }

    int _start;
    scanf("%d", &_start);

    int _end;
    scanf("%d", &_end);

    res = minCost(_g_nodes, _g_edges, _g_from, _g_to, _g_weight, _start, _end);
    printf("minCost = %d\n", res);

    return 0;
}
