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
        int depth;

        // this function returs the distance in miles from lat, lon
        // to this object
        double distance(double lat, double lon);

    public:
        KDNode(double lat, double lon, const char *desc, int depth);
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
        void insertHelper(KDNode *p, double lat2, double lon2, const char *desc, int depth);
        void printNeighborsHelper(KDNode *p, double lat, double lon, double rad, const char *filter, int depth);
};

#endif
