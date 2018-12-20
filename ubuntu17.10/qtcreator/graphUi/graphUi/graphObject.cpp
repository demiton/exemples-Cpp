#include "graphObject.h"

GraphObject::GraphObject()
{
    this->nItemMax=numberOfItem;

    //Initialisation tables
    for(int k = 0;k<this->nItemMax;k++){
        this->freeItemTab.push_back(k);
    }

    // on alloue la memoire par avance pour gagner en rapidité
    static const std::size_t vertex_count = this->nItemMax;
    this->g.m_vertices.reserve(vertex_count);
}

void GraphObject::Clear()
   {
       this->g.clear();
   }

Vertex GraphObject::oneVertex(struct VertexProperties &vp){
    return boost::add_vertex(vp,g);
}

void GraphObject::newEdge(struct VertexProperties vp1, struct VertexProperties vp2){
    Vertex v1 = boost::add_vertex(vp1,this->g);
    Vertex v2 = boost::add_vertex(vp2,this->g);
    add_edge(v1,v2,this->g);

}




void GraphObject::setGraph(){

    int nVertices = 10;

    srand(time(NULL));
    for(int i = 0;i<nVertices; i++){
        int rand_numberOfEdges = rand()%nVertices;
        VertexProperties vi("Noeud",i);
        unsigned j = i;
        cout<<" - "<<i<< " - unsigned i : "<<j<<" : ";
        for(int k =0;k<rand_numberOfEdges;k++){
            int rand_vertices = rand()%nVertices;
            VertexProperties vk("Noeud",k);
            this->newEdge(vi,vk);
            cout<<rand_vertices<<" ";

        }
        cout<<endl;
    }
    cout<<"find and print"<<endl;
    this->find_and_print("Noeud");
    cout<< "Nombres de vertices dans le graphe g : "<<num_vertices(this->g)<<endl;
    cout<< "Nombres d'arretes dans le graphe g : "<<num_edges(this->g)<<endl;
    cout<< "Infos du graphe : "<<endl;
    print_graph(this->g);

    cout<< " tie  g : "<<endl;
   // boost::graph_traits<GraphType>::viter,viterend;
    using VItr = boost::graph_traits<GraphType>::vertex_iterator; // Define Vertex iterator
    VItr viter,viterend,viter2,viterend2;
    string name_it=this->g[*viter].name;
    int id_it = this->g[*viter].id;
    for (boost::tie(viter, viterend) = vertices(this->g); viter != viterend; ++viter) {
        string name_it=this->g[*viter].name;
        int id_it = this->g[*viter].id;
        for (boost::tie(viter2, viterend2) = vertices(this->g); viter2 != viterend2; ++viter2) {
               if(this->g[*viter2].name == name_it && this->g[*viter2].id == id_it)
                   cout<<name_it<<" meme nom, meme id "<< id_it<<endl;
           }
       }

    //boost::tie(viter, viterend) = vertices(g);
}

inline void GraphObject:: find_and_print(string name){
    //Iterators
    typedef typename boost::graph_traits<GraphType>::vertex_iterator vert_it_t;
    vert_it_t it, end;
    boost::tie(it, end) = boost::vertices(this->g);
    //
    typedef typename boost::graph_traits<GraphType>::vertex_descriptor desc_t;
    for (; it != end; ++ it) {
        const desc_t desc = *it;
        const VertexProperties& vertex_prop = boost::get(boost::vertex_bundle, this->g)[desc];
        if(vertex_prop.name == name){
            std::cout<< vertex_prop.name  <<" id : "<<vertex_prop.id<<endl;
        }
    }


}

inline void GraphObject:: printVertex(){
    //Iterators
    typedef typename boost::graph_traits<GraphType>::vertex_iterator vert_it_t;
    vert_it_t it, end;
    boost::tie(it, end) = boost::vertices(this->g);
    //
    typedef typename boost::graph_traits<GraphType>::vertex_descriptor desc_t;
    for (; it != end; ++ it) {
    const desc_t desc = *it;
    const VertexProperties& vertex_prop = boost::get(boost::vertex_bundle, this->g)[desc];
    std::cout<< vertex_prop.name  <<" id : "<<vertex_prop.id<< endl;

    }
}
