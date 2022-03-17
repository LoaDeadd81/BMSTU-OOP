#ifndef EDGE_H
#define EDGE_H

#include "ErrorType.h"

#include <QGraphicsScene>

typedef struct edge_type
{
    int start_index, end_index;
} edge_type;

typedef struct edges_type
{
    edge_type *array;
    int len;
} edges_type;

edges_type init_edges();

void free_edges(edges_type &edges);

error_code check_edges(const edges_type &edges, int points_count);

error_code input_edges(edges_type &edges, const FILE *f);

error_code draw_edges(edges_type &edges, QGraphicsScene *scene);

#endif 
