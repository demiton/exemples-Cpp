#ifndef VERTEXOBJECT_H
#define VERTEXOBJECT_H
#include <iostream>
using namespace std;

class VertexObject
{
public :
    VertexObject();
    VertexObject(string const& , unsigned );
private :
    unsigned id;
    string name;

};

#endif // VERTEXOBJECT_H
