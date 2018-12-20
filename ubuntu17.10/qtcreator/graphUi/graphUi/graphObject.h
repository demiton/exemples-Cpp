#ifndef GRAPHOBJECT_H
#define GRAPHOBJECT_H
#include "vertexobject.h"
#include <QWidget>
#include <boost/graph/adjacency_list.hpp>
#include "item.h"
#include "directives.h"
#include <ctime>
#include <string>
#include<iostream>
#include <boost/utility/string_ref.hpp>
#include <boost/graph/graph_utility.hpp>


using namespace std;

using namespace boost;


// Vertex Property
struct VertexProperties
{
  string name;
  int id;
  VertexProperties() : name(""), id(0) {}
  VertexProperties(std::string const& n, unsigned i) : name(n), id(i) {}
  bool operator==(const VertexProperties& VP) const
  {
      return ((name == VP.name) && (id == VP.id));
  }

};
// Edges Property
typedef property<edge_weight_t, int> EdgeWeightProperty;
// Graph Type
typedef adjacency_list<vecS, vecS, boost::bidirectionalS,VertexProperties, EdgeWeightProperty> GraphType;
// Descriptor
typedef graph_traits<GraphType>::vertex_descriptor Vertex;
typedef typename graph_traits<GraphType>::edge_descriptor Edge;
typedef std::pair<Edge, Edge> EdgePair;



class GraphObject
{

public:
    GraphObject();
    Vertex oneVertex(VertexProperties &);
    void newEdge(struct VertexProperties ,struct VertexProperties );
    void setGraph();

    void Clear();
    inline void  find_and_print(std::string);
    inline void  printVertex();

private :
       GraphType g;
       Vertex v0;
       Item iTab[10000];
       vector <int> freeItemTab;
       vector <int> itemFileTab;
       int nItemMax;

};

#endif // GRAPH_H
