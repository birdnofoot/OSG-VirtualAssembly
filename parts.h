
#include"createArrow.h"

#include<osgDB/ReadFile>
#include<osgDB/WriteFile>

//定义储存节点类

osg::Vec3 _position0=osg::Vec3(0,0,0);     //记录节点具体位置，全局变量
osg::Vec3 _angle0=osg::Vec3(0,0,0);       //记录节点旋转角度，全局变量

class Part1:public osg::PositionAttitudeTransform    //继承自osg::PositionAttitudeTransform 类
{
 
    public:
		Part1(osg::Node* node)
	  {
		
		  pat=createArrow(node);	    //创建箭头      
		  pat->setNodeMask(0x0);	    //设置箭头显示状态
	      this->addChild(node);	        //添加子节点
	      this->addChild(pat);           //添加箭头

		    //设置默认显示位置
	      this->setPosition(osg::Vec3(-5000,0,6000));            
		   //设置默认姿势状态
 		  this->setAttitude(osg::Quat(osg::DegreesToRadians(90.0),osg::Vec3(1,0,0),0,osg::Vec3(0,1,0),0,osg::Vec3(0,0,1))); 
		  angle=osg::Vec3(0,0,0);          //初始化旋转角度
	  }
	
	  ~Part1(void){}; 


        //定义旋转子函数
	   void setRotation(osg::Vec3& rot)          
	   {
		   	previous_attitude=this->getAttitude();  	   //获取原物体姿势
	        osg::Quat a(rot.x(),osg::Vec3(1,0,0),rot.y(),osg::Vec3(0,1,0),rot.z(),osg::Vec3(0,0,1));    

			 //设置旋转为相对自身转轴旋转，而非绕绝对坐标轴旋转
	        this->setAttitude(a*previous_attitude);	       
	   }


      //定义鼠标拖动控制位移子函数
	   void mousePosition(osg::Vec3 & pos)       
	   {
		   previous_attitude=this->getAttitude();	 

		   //矩阵相乘使得物体在鼠标拖动时沿其自身坐标轴移动，而非沿绝对坐标移动
	      this->setPosition(previous_attitude*pos+this->getPosition());       
	   }

      osg::PositionAttitudeTransform* pat;	 
	  osg::Vec3 angle;

    private:		
	 	osg::Quat previous_attitude;		      
  };	

