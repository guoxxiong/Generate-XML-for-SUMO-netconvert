/*BEGIN_FILE_HDR
************************************************************************************
*NOTICE

************************************************************************************
*File Name:create_xml
************************************************************************************
*Project/Product:ROS VSLAM
*Title:
*Author:xiong.guo
************************************************************************************
*Description:
*
*(Requirements,pseudo code and etc.)
************************************************************************************
*Limitations:
*
*(limitations)
************************************************************************************

************************************************************************************
*Revision History:
*
*Version          Date         Initials        CR#          Descriptions
*--------     -----------     -----------   ---------     ----------------------
*1.0           05/07/18                       N/A            Original
*
************************************************************************************
*END_FILE_HDR*/

#include"nodconfig.h"
using namespace std;

typedef pcl::PointXYZRGB PointT;
typedef pcl::PointCloud<PointT> PointCloud;

unsigned char strid[32];
unsigned char strx[64];
unsigned char stry[64];
unsigned char strz[64];
unsigned char strtype[20]="priority";

int nodeid=1;

//point结构体
typedef struct point_t{
    int id1;
    double x1;
    double y1;
    double z1;
}nodepoint;


nodepoint node_point;
	

void node_point_init(PointT randpoint)
{
    node_point.id1=nodeid;
    node_point.x1=randpoint.x;
    node_point.y1=randpoint.y;
    node_point.z1=randpoint.z;
    nodeid++;
}

    

int main()
{
    //vector define
    vector< vector<PointT> > randSets(N);
    for (int i=0;i<randSets.size();i++)
    {
        randSets[i].resize(20);
    }

    srand((unsigned)time(NULL));//init random seeds
	for (int i=0;i<randSets.size();i++)
	{
		//generate rand numbers range in [1,500]
		for (int j=0;j<randSets[i].size();j++)
		{
			randSets[i][j].x=500*(rand()/double(RAND_MAX));
			randSets[i][j].y=randSets[i][j].x+rand()/double(RAND_MAX);
			randSets[i][j].z=0;
			randSets[i][j].r=0;
			randSets[i][j].g=0;
            randSets[i][j].b=0;
		}
	}
	for (int i=0;i<randSets.size();i++)
	{
	   for(int j=0;j<randSets[i].size();j++)
	   {
	      printf("(%lf,%lf,%lf)\n",randSets[i][j].x,randSets[i][j].y,randSets[i][j].z);
	   }
	}

    
    xmlDocPtr nodedoc = xmlNewDoc(BAD_CAST"1.0");//文档指针
    xmlNodePtr root_node = xmlNewNode(NULL,BAD_CAST"nodes");
    xmlDocSetRootElement(nodedoc,root_node);//设置根节点


    for(int i=0;i<randSets.size();i++)
    {
        for(int j=0;j<randSets[i].size();j++)
        {
            node_point_init(randSets[i][j]);
            
            //double convert to unsigned char
            sprintf((char*)strid, "%d", node_point.id1);
            sprintf((char*)strx, "%lf", node_point.x1);
            sprintf((char*)stry, "%lf", node_point.y1);
            sprintf((char*)strz, "%lf", node_point.z1);

            //add newnode
            xmlNodePtr new_node = xmlNewNode(NULL,BAD_CAST "node");
	        xmlAddChild(root_node,new_node);
	        xmlNewProp(new_node,BAD_CAST "id",strid);
            xmlNewProp(new_node,BAD_CAST "x",strx);
            xmlNewProp(new_node,BAD_CAST "y",stry);
            xmlNewProp(new_node,BAD_CAST "z",strz);
            xmlNewProp(new_node,BAD_CAST "type",strtype);
        }
    }
    //存储文档
    int nRel = xmlSaveFile(NODE_FILE,nodedoc);
	if (nRel != -1)
	{
		printf("一个nod.xml文档被创建，写入%d个字节\n", nRel);
	}

    xmlFreeDoc(nodedoc);
    return 0;
}
