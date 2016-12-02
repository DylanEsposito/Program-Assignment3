#include "KDTree.h"
#include <math.h>

KDNode::KDNode(double lat, double lon, const char *desc) 
{
    left = NULL;
    right = NULL;
    description = desc;
    latitude = lat;
    longitude = lon;
}

KDNode::~KDNode() 
{

}

double KDNode::distance(double lat, double lon) 
{
    double param = M_PI / 180.0; // required for conversion from degrees to radians
    double rad = 3956.0;  // radius of earth in miles
    double d_lat = (lat - latitude) * param;
    double d_lon = (lon - longitude) * param;
    double dist = sin(d_lat/2) * sin(d_lat/2) + cos(latitude*param) * cos(lat*param) * sin(d_lon/2) * sin(d_lon/2);
    dist = 2.0 * atan2(sqrt(dist), sqrt(1-dist));
    return rad * dist;
}

KDTree::KDTree() 
{
    root = NULL;
    size = 0;
}

KDTree::~KDTree() 
{
    // TOD0
    destroy(root);
}

void KDTree::destroy(KDNode *p) 
{
    //TODO
    if (p) 
	{
		//If so I recursivelly call to the left 
        destroy(p->left);
		//Eles I recursievelly call to the right
        destroy(p->right);
		//Otherwise I detele the root if I reached a null Node 
        delete p;
	}
}


void KDTree::insert(double lat, double lon, const char *desc) 
{
    // TODO
    int dimen = 1;
    insert2(&p,lat,lon,desc,1);
}

void KDTree::insert2(KDNode *p, double lat2, double lon2, const char *desc, int depth)
{
    if (!p)
    {
        p = new KDNode(lat,lon,desc);
        size++;
    }
    else
    {
        //NEED TO ORGANIZE AROUND CUTTING DIMENSION
        //if(cuttingDim = 1)
            //if((p)->lat < lat2)
                //insert2(&((p)->right), lat, lon, desc, 2)
            //else:
                ////insert2(&((p)->right), lat, lon, desc, 2)
        //elseif(cuttingDim = 2)
            //if((p)->lon < lon2)
                //insert2(&((p)->right), lat, lon, desc, 1)
            //else:
                 //insert2(&((p)->left), lat, lon, desc, 1)

        //if the lat2 is greater than, go right
        if((p)->latitude < lat2)
            insert2(&((p)->right), lat, lon, desc); 
        //if the lat2 less than, go left
        if((p)->latitude > lat2)
            insert2(&((p)->left), lat, lon, desc);
        //if the lon2 is greater than we go right
        if((p)->longitude < lon2)
            insert2(&((p)->right), lat, lon, desc);
        //if the lon2 is less than we go left
        if((p)->longitude > lon2)
            insert2(&((p)->left), lat, lon, desc);
    }
}

unsigned int KDTree::printNeighbors(double lat, double lon, double rad, const char *filter) 
{
    // TODO
    return -1;
}

unsigned int KDTree::getSize() {
    // TODO
    return -1;
}