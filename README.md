# Generate-XML-for-SUMO-netconvert
Generate some input files for SUMO netconvert.

create_nod.cpp:
   
In order to generate a nod.xml file with some liner random points,I have transplanted it to "create_edg.xml",it's a simple demo only.


create_edg.cpp:

Giving it some pointcloud data from a reference line of an edge,to generated an edg.xml and nod.xml file contains some elements like x,y,z,to,from,id,shape,etc... 


Up to now,we can use sumo netconvert to do:

input:nod.xml,edg.xml
output:net.xml,xodr(an opendrive format)
