
#include <cstdio>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <ros/ros.h>

#include<pcl/io/pcd_io.h>
#include<pcl/point_types.h>
#include<pcl/point_cloud.h>
#include<pcl/common/transforms.h>
#include<pcl/search/kdtree.h>
#include<pcl/segmentation/extract_clusters.h>

#include <libxml/tree.h>
#include <libxml/xmlmemory.h>

#define NODE_FILE   "generated.nod.xml"
#define EDGE_FILE   "generated.edg.xml"
#define N 2