#ifndef __kdtree__
#define __kdtree__
#include <string>

class KDNode {
    private:
        double latitude;
        double longitude;
        std::string description;
        KDNode *left;
        KDNode *right;
        // perhaps you want to include `depth` as well

        // this function returs the distance in miles from lat, lon
        // to this object
        double distance(double lat, double lon);

    public:
        KDNode(double lat, double lon, const char *desc);
        ~KDNode();

    friend class KDTree;
};

class KDTree {
    private:
        unsigned int size;
        KDNode *root;

        void destroy(KDNode *p);

    public:
        KDTree();
        ~KDTree();

        unsigned int getSize();
        void insert(double lat, double lon, const char *desc);
        unsigned int printNeighbors(double lat, double lon, double rad, const char *filter);
        void insert2(KDNode *p);
};

#endif