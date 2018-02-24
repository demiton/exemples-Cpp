#ifndef GRAPHOBJECT_H
#define GRAPHOBJECT_H
#include "vertexobject.h"
#include <QWidget>
#include <boost/graph/adjacency_list.hpp>
using namespace boost;
// Property Structures
struct VertexProperties
{
  string name;
  int id;
  VertexProperties() : name(""), id(0) {}
  VertexProperties(std::string const& n, unsigned i) : name(n), id(i) {}
};

typedef property<edge_weight_t, int> EdgeWeightProperty;


// Graph type
typedef adjacency_list<vecS, vecS, undirectedS,
  VertexProperties, EdgeWeightProperty> Graph;
// vertices type
typedef graph_traits<Graph>::vertex_descriptor Vertex;




class GraphObject
{
public:
    GraphObject();
    Vertex oneVertex(VertexProperties &);
    void newEdge(VertexProperties &,VertexProperties &);

private :
       Graph g;
       Vertex v0;

};

#endif // GRAPH_H
