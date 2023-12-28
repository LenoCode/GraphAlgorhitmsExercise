#include <vector>
#include <queue>

struct Edge{
    int v,w;
    Edge(int v = -1,int w = -1):v(v),w(w){}
};


//he simplest interface that supports the basic graph-processing operations that we wish to consider
class Graph{

    private:
        //Implementation-dependet code

    public:
        virtual ~Graph(){};

        virtual int V() const = 0;
        virtual int E() const = 0;

        virtual bool directed() const = 0;

        virtual bool cycle() const = 0;

        virtual int insert(Edge) = 0;
        virtual int remove(Edge) = 0;

        virtual bool edge(int,int) = 0;

};