#include "Edge.h"

error_code input_tmp_edges(edges_type &edges, FILE *f);

error_code check_edge(const edge_type &edge, int points_count);

error_code draw_edge(const edge_type &edge, const points_type &points, QGraphicsScene *scene);

error_code draw_line(const point_type &start, const point_type &end, QGraphicsScene *scene);

error_code alloc_edges_array(edges_type &edges, int num);

edges_type init_edges()
{
    return {nullptr, 0};
}

void free_edges(edges_type &edges)
{
    free(edges.array);
}

error_code check_edges(const edges_type &edges, int points_count)
{
    error_code rc = SUCCESS;
    if (edges.array == nullptr)
        rc = ACCESS_ERROR;
    else
    {
        for (int i = 0; rc == SUCCESS && i < edges.len; i++)
            rc = check_edge(edges.array[i], points_count);
    }
    return rc;
}

error_code input_edges(edges_type &edges, FILE *f)
{
    error_code rc = SUCCESS;
    if (f == nullptr)
        rc = ACCESS_ERROR;
    else
    {
        edges_type tmp_edges = init_edges();
        rc = input_tmp_edges(tmp_edges, f);
        if (rc == SUCCESS)
            edges = tmp_edges;
    }
    return rc;
}

error_code draw_edges(const edges_type &edges, const points_type &points, QGraphicsScene *scene)
{
    error_code rc = SUCCESS;
    if (edges.array == nullptr || points.array == nullptr || scene == nullptr)
        rc = ACCESS_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < edges.len; i++)
            rc = draw_edge(edges.array[i], points, scene);
    return rc;
}

error_code deep_copy(edges_type &dst, const edges_type &src)
{
    error_code rc = SUCCESS;
    if(src.array == nullptr)
        rc = ACCESS_ERROR;
    else
    {
        rc = alloc_edges_array(dst, src.len);
        if(rc == SUCCESS)
            for (int i = 0; i < src.len; i++)
                dst.array[i] = src.array[i];
    }
    return rc;
}

error_code input_edges_num(int &num, FILE *f);

error_code input_edges_array(edges_type &edges, int num, FILE *f);

error_code input_edge(edge_type &edge, FILE *f);

error_code input_tmp_edges(edges_type &edges, FILE *f)
{
    int num = 0;
    error_code rc = SUCCESS;
    if (f == nullptr)
        rc = ACCESS_ERROR;
    else
        rc = input_edges_num(num, f);
    if (rc == SUCCESS)
    {
        rc = alloc_edges_array(edges, num);
        if (rc == SUCCESS)
        {
            rc = input_edges_array(edges, num, f);
            if (rc != SUCCESS)
                free_edges(edges);
        }
    }
    return rc;
}

error_code input_edges_num(int &num, FILE *f)
{
    error_code rc = SUCCESS;
    if (fscanf(f, "%d", &num) != 1 || num < 1)
        rc = BAD_MODEL_DATA;
    return rc;
}

error_code input_edges_array(edges_type &edges, int num, FILE *f)
{
    error_code rc = SUCCESS;
    if (edges.array == nullptr || f == nullptr || num < 1)
        rc = ACCESS_ERROR;
    else
        for (int i = 0; i < rc == SUCCESS && i < num; i++)
            rc = input_edge(edges.array[i], f);
    return rc;
}

error_code alloc_edges_array(edges_type &edges, int num)
{
    error_code rc = SUCCESS;
    if (num < 1)
        return MEM_ERROR;
    else
    {
        edges.array = (edge_type *) malloc(sizeof(edge_type) * num);
        if (edges.array == nullptr)
            rc = MEM_ERROR;
        else
            edges.len = num;
    }
    return rc;
}

error_code input_edge(edge_type &edge, FILE *f)
{
    error_code rc = SUCCESS;
    if (fscanf(f, "%d %d", &edge.start_index, &edge.end_index) != 3)
        rc = BAD_MODEL_DATA;
    return rc;
}

error_code check_edge(const edge_type &edge, int points_count)
{
    error_code rc = SUCCESS;
    if (edge.start_index < 0 || edge.start_index >= points_count ||
        edge.end_index < 0 || edge.end_index >= points_count ||
        edge.start_index == edge.end_index)
        rc = BAD_MODEL_DATA;
    return rc;
}

error_code draw_edge(const edge_type &edge, const points_type &points, QGraphicsScene *scene)
{
    error_code rc = SUCCESS;
    if (points.array == nullptr || scene == nullptr)
        rc = ACCESS_ERROR;
    else
        rc = draw_line(points.array[edge.start_index], points.array[edge.end_index], scene);
    return rc;
}

error_code draw_line(const point_type &start, const point_type &end, QGraphicsScene *scene)
{
    error_code rc = SUCCESS;
    if (scene == nullptr)
        rc = ACCESS_ERROR;
    else
        scene->addLine(start.x, -start.y, end.x, -end.y);
    return rc;
}


