#include "graphObject.h"

GraphObject::GraphObject()
{

}

Vertex GraphObject::oneVertex(VertexProperties &vp){
  return boost::add_vertex(vp,g);
}

void GraphObject::newEdge(VertexProperties &vp1, VertexProperties &vp2){
    Vertex v1 = boost::add_vertex(vp1,this->g);
    Vertex v2 = boost::add_vertex(vp2,this->g);
    add_edge(v1,v2,this->g);
}
