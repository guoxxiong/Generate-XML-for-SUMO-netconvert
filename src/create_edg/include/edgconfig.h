
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <ros/ros.h>
#include <vector>

#include<pcl/io/pcd_io.h>
#include<pcl/point_types.h>
#include<pcl/point_cloud.h>
#include<pcl/common/transforms.h>
#include<pcl/search/kdtree.h>
#include<pcl/segmentation/extract_clusters.h>

#include <libxml/tree.h>
#include <libxml/xmlmemory.h>

#include<cstring>
#include <pcl/visualization/cloud_viewer.h>

#define NODE_FILE   "generated_true1.nod.xml"
#define EDGE_FILE   "generated_true1.edg.xml"
#define N 2

unsigned char strnumlanes[5] = "2";  //Define quantity of lanes
unsigned char strtypes[20] = "priority"; //Define element "type" for an edge
unsigned char strwidth[10] = "3.75";  //这里是车道的宽度，可以自己设置
unsigned char strspreadType[10] = "right"; //这是车道的展开方式，可以设置为"right"或者"center"，展开的方式是以shape为参考向右或者向左右两边展开
