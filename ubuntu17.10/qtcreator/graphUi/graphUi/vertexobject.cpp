#include "vertexobject.h"

VertexObject::VertexObject(){
    this->name="";
     this->id=0;
};

VertexObject::VertexObject(std::string const& n, unsigned i) {
    this->name=n;
    this->id=i;
};
