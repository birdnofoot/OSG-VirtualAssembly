
#include"parts.h"
#include"handle.h"

// 坐标轴显示控制
osg::Node::NodeMask  p1=0x0,p2=0x0, p3=0x0, p4=0x0, p5=0x0, p6=0x0, p7=0x0, p8=0x0, p9=0x0, p10=0x0;
osg::Node::NodeMask  p11=0x0, p12=0x0, p13=0x0, p14=0x0, p15=0x0,p16=0,p17=0,p18=0,p19=0,p20=0,p21=0; 

 // 物体显示控制
osg::Node::NodeMask  q1=0x0,q2=0x0,q3=0x0,q4=0x0,q5=0x0,q6=0x0,q7=0x0,q8=0x0,q9=0x0,q10=0x0;
osg::Node::NodeMask  q11=0x0,q12=0x0,q13=0x0,q14=0x0,q15=0x0,q16=0,q17=0,q18=0,q19=0,q20=0,q21=0;


//创建总类
class Part:
	public osg::PositionAttitudeTransform
{
public:
	Part(void);
	~Part(void);

	void update(void);
    int  j;
private:
	Part1 *_part[21];    //创建 Part1类指针
};

//创建更新回调类
class UpdateCallback:public osg::NodeCallback
{
	virtual void operator()(osg::Node* node,osg::NodeVisitor* nv)
	{
		Part* part=dynamic_cast<Part*>(node);
		if(part!=NULL)
		{
			part->update();
		}
	}
};

Part::Part(void)
{	
	j=0;

	//加载各个文件并设置名称

	_part[0]=new Part1(osgDB::readNodeFile("prp//framepart.ive"));                     
	_part[0]->setName("part1");
	_part[0]->setPosition(osg::Vec3(0,0,0));
	
	_part[1]=new Part1(osgDB::readNodeFile("prp//axis_cylinder.ive"));	                    
	_part[1]->setName("part2");

	_part[2]=new Part1(osgDB::readNodeFile("prp//clamp_anvil_lower.ive"));             	
	_part[2]->setName("part3");

	_part[3]=new Part1(osgDB::readNodeFile("prp//clamp_anvil_upper.ive"));	       
	_part[3]->setName("part4");

	_part[4]=new Part1(osgDB::readNodeFile("prp//clamp_body_lower.ive"));	
	_part[4]->setName("part5");

	_part[5]=new Part1(osgDB::readNodeFile("prp//clamp_body_upper.ive"));	
	_part[5]->setName("part6");

	_part[6]=new Part1(osgDB::readNodeFile("prp//clamp_link_lower.ive"));	
	_part[6]->setName("part7");


	_part[7]=new Part1(osgDB::readNodeFile("prp//clamp_link_upper.ive"));	
	_part[7]->setName("part8");

	_part[8]=new Part1(osgDB::readNodeFile("prp//clamp_ped.ive"));	
	_part[8]->setName("part9");

	_part[9]=new Part1(osgDB::readNodeFile("prp//cylinder1_assemble.ive"));	
	_part[9]->setName("part10");

	_part[10]=new Part1(osgDB::readNodeFile("prp//cylinder2_assemble.ive"));	
	_part[10]->setName("part11");

	_part[11]=new Part1(osgDB::readNodeFile("prp//cylinder3_assemble.ive"));	
	_part[11]->setName("part12");

	_part[12]=new Part1(osgDB::readNodeFile("prp//front_arm.ive"));
	_part[12]->setName("part13");

	_part[13]=new Part1(osgDB::readNodeFile("prp//frontlink_assemble.ive"));	
	_part[13]->setName("part14");

	_part[14]=new Part1(osgDB::readNodeFile("prp//linkage_assemble.ive"));
	_part[14]->setName("part15");
	
	_part[15]=new Part1(osgDB::readNodeFile("prp//piston1_assemble.ive"));	
	_part[15]->setName("part16");

	_part[16]=new Part1(osgDB::readNodeFile("prp//piston2_assemble.ive"));
	_part[16]->setName("part17");

	_part[17]=new Part1(osgDB::readNodeFile("prp//piston3.ive"));	
	_part[17]->setName("part18");

	_part[18]=new Part1(osgDB::readNodeFile("prp//platform.ive"));	
	_part[18]->setName("part19");

	_part[19]=new Part1(osgDB::readNodeFile("prp//platform_bearing.ive"));	
	_part[19]->setName("part20");

	_part[20]=new Part1(osgDB::readNodeFile("prp//rear_arm.ive"));	
	_part[20]->setName("part21");
	

	//添加各个物体作为子节点
	for(j=0;j<=20;j++)
	{
		this->addChild(_part[j]);		
	
	}

	//设置更新回调
	this->setUpdateCallback(new UpdateCallback());
}
	
Part::~Part(void){}

void Part::update(void)
{

	// 物体显示状态
	switch(i)  
	{
	case 0:q1=0; break;
	case 1:q1=1;q2=0x0;break;
	case 2:q2=1;q3=0x0;break;
	case 3:q3=1;q4=0;  break;
    case 4:q4=1;q5=0x0;break;
	case 5:q5=1;q6=0x0;break;
	case 6:q6=1;q7=0x0;break;
	case 7:q7=1;q8=0x0;break;
	case 8:q8=1;q9=0x0;break;
	case 9:q9=1;q10=0x0;break;
	case 10:q10=1;q11=0x0;break;
	case 11:q11=1;q12=0x0;break;
	case 12:q12=1;q13=0x0;break;
	case 13:q13=1;q14=0x0;break;
	case 14:q14=1;q15=0x0;break;
	case 15:q15=1;q16=0x0;break; 
	case 16:q16=1;q17=0x0;break;
	case 17:q17=1;q18=0x0;break;
	case 18:q18=1;q19=0x0;break;
	case 19:q19=1;q20=0x0;break;
	case 20:q20=1;q21=0x0;break;
	case 21:q21=1;break;
	

	default:break;
	}

	

   //设置物体的显示状态
	_part[0]->setNodeMask(q1);
	_part[1]->setNodeMask(q2);
	_part[2]->setNodeMask(q3);
	_part[3]->setNodeMask(q4);
	_part[4]->setNodeMask(q5);
	_part[5]->setNodeMask(q6);
	_part[6]->setNodeMask(q7);
	_part[7]->setNodeMask(q8);
	_part[8]->setNodeMask(q9);
	_part[9]->setNodeMask(q10);
	_part[10]->setNodeMask(q11);
	_part[11]->setNodeMask(q12);
	_part[12]->setNodeMask(q13);
	_part[13]->setNodeMask(q14);
	_part[14]->setNodeMask(q15);	
	_part[15]->setNodeMask(q16);	
	_part[16]->setNodeMask(q17);
	_part[17]->setNodeMask(q18);	
	_part[18]->setNodeMask(q19);	
	_part[19]->setNodeMask(q20);
	_part[20]->setNodeMask(q21);


	//设置箭头的显示状态
	_part[0]->pat->setNodeMask(p1);
	_part[1]->pat->setNodeMask(p2);
	_part[2]->pat->setNodeMask(p3);
	_part[3]->pat->setNodeMask(p4);
	_part[4]->pat->setNodeMask(p5);
	_part[5]->pat->setNodeMask(p6);
	_part[6]->pat->setNodeMask(p7);
	_part[7]->pat->setNodeMask(p8);
	_part[8]->pat->setNodeMask(p9);
	_part[9]->pat->setNodeMask(p10);
	_part[10]->pat->setNodeMask(p11);
	_part[11]->pat->setNodeMask(p12);
	_part[12]->pat->setNodeMask(p13);
	_part[13]->pat->setNodeMask(p14);
	_part[14]->pat->setNodeMask(p15);
	_part[15]->pat->setNodeMask(p16);
	_part[16]->pat->setNodeMask(p17);	
	_part[17]->pat->setNodeMask(p18);
	_part[18]->pat->setNodeMask(p19);	
	_part[19]->pat->setNodeMask(p20);
    _part[20]->pat->setNodeMask(p21);


	
	j=-1;   //设置-1以保证没选择到的时候位置状态不会发生变化


	//选择物体与显示箭头

	if(wonderful=="part1"){ j=0; p1=1;} else p1=0; 
	if(wonderful=="part2"){ j=1; p2=1;} else p2=0; 
	if(wonderful=="part3"){ j=2; p3=1;} else p3=0; 
	if(wonderful=="part4"){ j=3; p4=1;} else p4=0; 
	if(wonderful=="part5"){ j=4; p5=1;} else p5=0; 
	if(wonderful=="part6"){ j=5; p6=1;} else p6=0; 
	if(wonderful=="part7"){ j=6; p7=1;} else p7=0; 
	if(wonderful=="part8"){ j=7; p8=1;} else p8=0; 
	if(wonderful=="part9"){ j=8; p9=1;} else p9=0;
	if(wonderful=="part10"){ j=9; p10=1;} else p10=0; 
	if(wonderful=="part11"){ j=10; p11=1;} else p11=0; 
	if(wonderful=="part12"){ j=11; p12=1;} else p12=0; 
	if(wonderful=="part13"){ j=12; p13=1;} else p13=0; 
	if(wonderful=="part14"){ j=13; p14=1;} else p14=0; 
	if(wonderful=="part15"){ j=14; p15=1;} else p15=0;
	if(wonderful=="part16"){ j=15; p16=1;} else p16=0; 
	if(wonderful=="part17"){ j=16; p17=1;} else p17=0; 
	if(wonderful=="part18"){ j=17; p18=1;} else p18=0;
	if(wonderful=="part19"){ j=18; p19=1;} else p19=0; 
	if(wonderful=="part20"){ j=19; p20=1;} else p20=0; 
	if(wonderful=="part21"){ j=20; p21=1;} else p21=0;
	
	
  //控制位移和角度函数
	
	if(j>=0&&j<=20)
	{

	  //设定角度
	   _part[j]->angle=_part[j]->angle+deltaAngle;  
        _angle0=osg::Vec3(osg::RadiansToDegrees(_part[j]->angle.x()),osg::RadiansToDegrees(_part[j]->angle.y()),osg::RadiansToDegrees(_part[j]->angle.z())); //记录角度     
		_part[j]->setRotation(deltaAngle);    //旋转函数
       //设定位置
		_part[j]->setPosition(_part[j]->getPosition()+deltaPosition);
		_part[j]->mousePosition(mousePosition);			
		_position0=_part[j]->getPosition();   //记录位置坐标
	}


	//将位置和角度的变化值归零
	deltaPosition=osg::Vec3(0,0,0);
	mousePosition=osg::Vec3(0,0,0);
	deltaAngle=osg::Vec3(0,0,0);
	
}

