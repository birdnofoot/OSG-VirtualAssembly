#pragma once
#include"PickHandler.h"


 int i=0;                 //  记录录入物体个数

 float r_speed=5;          //记录旋转速度
 float m_speed=125;          //记录移动速度


  //帮助文档的显示状态
 bool s=0;              
 osg::Switch* ss=new osg::Switch();

//立体显示状态初始化
osg::DisplaySettings *displaysetting0 = new osg::DisplaySettings(); 
 bool s0=0;


 std::string _axis;         //储存选到的坐标轴 
 std::string nodename;      //贮存选取到节点的名字
 std::string wonderful;    // 选取物体名称  

bool PickHandler::handle(const osgGA::GUIEventAdapter&ea,osgGA::GUIActionAdapter&aa)    //人机交互动作 函数定义
{

	osgViewer::View* view= dynamic_cast<osgViewer::View*>(&aa);
	if(!view) return false;

	switch(ea.getEventType())
	{
		
	case(osgGA::GUIEventAdapter::PUSH):    //点击鼠标
		{			

			if(ea.getButton()==1)
			{
				 _mx=ea.getX();     //记录鼠标位置
		         _my=ea.getY();  
                 leftButton=true;
 
		         pick(view,ea.getX(),ea.getY());     //获得选取对象，使其高亮或消除高亮 			
							
			}	
			break;

		 return false;

		}

   case(osgGA::GUIEventAdapter::DRAG):   //拖动物体
	   		  
		{
			if(leftButton)
			{
				if(x_pick)
				{
					mousePosition._v[0]=(ea.getX()-_mx)*m_speed;
					_mx=ea.getX();
				}
				else
				{
					mousePosition._v[0]=0;
					
					if(z_pick)
					{
						mousePosition._v[2]=(ea.getY()-_my)*m_speed; 
						_my=ea.getY();
					}
					else 
					{
						mousePosition._v[2]=0;
						if(y_pick)
						{
							mousePosition._v[1]=(ea.getY()-_my)*m_speed; 
						   _my=ea.getY();
						}
						else    mousePosition._v[1]=0;
					}
				}
			
				
				}
	           
			
			break;

			return false;			
		}
		
	
   case(osgGA::GUIEventAdapter::SCROLL):         //旋转物体
		{
			if(leftButton)
			{
				if(x_pick)deltaAngle._v[0]=osg::DegreesToRadians(r_speed);
				
				else
				{
					deltaAngle._v[0]=0;
					if(z_pick)deltaAngle._v[2]=osg::DegreesToRadians(r_speed);
					
					else 
					{
						deltaAngle._v[2]=0;
						if(y_pick)deltaAngle._v[1]=osg::DegreesToRadians(r_speed);
						else    deltaAngle._v[1]=0;
					}
				}					
			}
			break;
				return false;
		}
   

	case(osgGA::GUIEventAdapter::KEYDOWN):
		{
		   //位置
			if(ea.getKey()==0xFF51) deltaPosition._v[0]=-m_speed; 	     //key left
			if(ea.getKey()==0xFF53) deltaPosition._v[0]=m_speed;       //key right

			if(ea.getKey()==osgGA::GUIEventAdapter::KEY_Up) deltaPosition._v[2]=m_speed; 	     //key up

			if(ea.getKey()==osgGA::GUIEventAdapter::KEY_Down) deltaPosition._v[2]=-m_speed; 	     //key down	

			if(ea.getKey()==osgGA::GUIEventAdapter::KEY_Shift_R||ea.getKey()==osgGA::GUIEventAdapter::KEY_Home) deltaPosition._v[1]=m_speed; 	     //key home

			if(ea.getKey()==osgGA::GUIEventAdapter::KEY_Control_R||ea.getKey()==osgGA::GUIEventAdapter::KEY_End) deltaPosition._v[1]=-m_speed; 	     //key end	


			//旋转
			if(ea.getKey()=='j') deltaAngle._v[0]=-osg::DegreesToRadians(r_speed); 	     //key     "j"
			if(ea.getKey()=='k') deltaAngle._v[0]=osg::DegreesToRadians(r_speed);       //key       "k"

			if(ea.getKey()==',') deltaAngle._v[2]=-osg::DegreesToRadians(r_speed);  	     //key  ","

			if(ea.getKey()=='.') deltaAngle._v[2]=osg::DegreesToRadians(r_speed);  	     //key     "."

			if(ea.getKey()=='n') deltaAngle._v[1]=-osg::DegreesToRadians(r_speed);      //key      "n"

			if(ea.getKey()=='m') deltaAngle._v[1]=osg::DegreesToRadians(r_speed);  	     //key    "m"	


			//速度
			if(ea.getKey()=='-') r_speed=r_speed/5;  	     //key    "-"	  旋转速度为五分之一
			if(ea.getKey()=='=') r_speed=r_speed*5;  	     //key    "="	 旋转速度变五倍
		
			if(ea.getKey()=='9') m_speed=m_speed/5;  	     //key    "9"	  旋转速度为五分之一
			if(ea.getKey()=='0') m_speed=m_speed*5;  	     //key    "0"	 旋转速度变五倍


			//帮助文档
			if(ea.getKey()=='h') {
				if(s){ss->setAllChildrenOff(); s=0;} 
				else  { ss->setAllChildrenOn();s=1;}	}     //key    "h"  帮助文档


           // 显示物体
			if(ea.getKey()==osgGA::GUIEventAdapter::KEY_Return) i++;  	     //key    "Enter"	
			if(ea.getKey()==osgGA::GUIEventAdapter::KEY_BackSpace) if(i>0)i--; 


			//立体显示状态
			if(ea.getKey()==osgGA::GUIEventAdapter::KEY_F1){if(s0!=1) s0=1;else  s0=0;}
			 displaysetting0->setStereo(s0); 
	           

			break;
			return false;
		}
				
				
				
	case(osgGA::GUIEventAdapter::FRAME):  				

	{		  
		 
		   std::string gdlist=" ";   			
           std::ostringstream os;  //申请一个输出流			

		  os<<std::endl;	

		  os<<"Object:  "<<wonderful<<"  "<<"Select:  "<<_axis<<std::endl; 
		  os<<"Move speed:  "<<m_speed<<"  Rotate speed:  "<<r_speed<<std::endl;
		  os<<"Real Position: x="<<_position0._v[0]<<" y="<<_position0._v[1]<<" z="<<_position0._v[2]<<std::endl;
		  os<<"Rotated angle: x="<<_angle0._v[0]<<" y="<<_angle0._v[1]<<" z="<<_angle0._v[2]<<std::endl;	
		   if(i>21)i=21;       //使得物体显示数量不超过实际数量
		  os<<"Displayed:      "<< i;
		
		//  os<<"pathsize is  "<<k;
	      gdlist +=os.str();
	      setLabel(gdlist);   //设置实时显示坐标
	
		  return false;
		}			
		
	default:
		return false;
	}
}


void PickHandler::pick(osgViewer::View* view, float x, float y)
{
		 
		  osg::Group* parent2=new osg::Group();	

		  osg::PositionAttitudeTransform* nodepat=new osg::PositionAttitudeTransform();		
		  

			//创建一个线段交集检测函数
		  osgUtil::LineSegmentIntersector::Intersections intersections;
		  if (view->computeIntersections(x, y, intersections))
		  {
			  osgUtil::LineSegmentIntersector::Intersection intersection = *intersections.begin();
			  osg::NodePath& nodePath = intersection.nodePath;

			  //得到选择的物体
			  node = (nodePath.size()>=1)?nodePath[nodePath.size()-1]:0;
			  parent = (nodePath.size()>=2)?dynamic_cast<osg::Group*>(nodePath[nodePath.size()-2]):0;
			  parent2=(nodePath.size()>=3)?dynamic_cast<osg::Group*>(nodePath[nodePath.size()-3]):0;  
		    
			 
			  nodepat=dynamic_cast<osg::PositionAttitudeTransform*>(nodePath.at(3));//节点位置第三位
			   wonderful=nodepat->getName();	 		
			   
		      // k=nodePath.size();
           
			   nodename=node->getName();          //获取节点名称
			  _axis=parent2->getName();           //获取父节点名称
			  
			  if(_axis==wonderful)_axis=nodename;
			 
	
			//根据拾取情况对x_pick、y_pick、z_pick赋值	 
			 if(_axis=="x") x_pick=true; else x_pick=false;
			 
			 if(_axis=="y") y_pick=true;  else  y_pick=false;
			    	
			 if(_axis=="z") z_pick=true;  else   z_pick=false; 	

		     //用高亮显示物体来表明物体已经被选中
		     if (parent && node)  //如果选中
		       { 
			       
			        osgFX::Scribe* parentAsScribe1 = dynamic_cast<osgFX::Scribe*>(parent);    //高亮                 
				
			
			      if (!parentAsScribe1)                   //如果没有高亮，则高亮显示       
			          {							  
				          osgFX::Scribe* scribe = new osgFX::Scribe();
				          scribe->addChild(node);									  
				          parent->replaceChild(node,scribe);  
										 
			           }
			     else                                         //如果已经高亮，消除高亮
			      {				
				           osg::Node::ParentList parentList = parentAsScribe1->getParents();
				            for(osg::Node::ParentList::iterator itr=parentList.begin();
					       itr!=parentList.end();
					        ++itr)
							{
				      
					            (*itr)->replaceChild(parentAsScribe1,node);
							}
							
				  }
			 }
		  }
		  
}
						    
		
