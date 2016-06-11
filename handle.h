#pragma once
#include"PickHandler.h"


 int i=0;                 //  ��¼¼���������

 float r_speed=5;          //��¼��ת�ٶ�
 float m_speed=125;          //��¼�ƶ��ٶ�


  //�����ĵ�����ʾ״̬
 bool s=0;              
 osg::Switch* ss=new osg::Switch();

//������ʾ״̬��ʼ��
osg::DisplaySettings *displaysetting0 = new osg::DisplaySettings(); 
 bool s0=0;


 std::string _axis;         //����ѡ���������� 
 std::string nodename;      //����ѡȡ���ڵ������
 std::string wonderful;    // ѡȡ��������  

bool PickHandler::handle(const osgGA::GUIEventAdapter&ea,osgGA::GUIActionAdapter&aa)    //�˻��������� ��������
{

	osgViewer::View* view= dynamic_cast<osgViewer::View*>(&aa);
	if(!view) return false;

	switch(ea.getEventType())
	{
		
	case(osgGA::GUIEventAdapter::PUSH):    //������
		{			

			if(ea.getButton()==1)
			{
				 _mx=ea.getX();     //��¼���λ��
		         _my=ea.getY();  
                 leftButton=true;
 
		         pick(view,ea.getX(),ea.getY());     //���ѡȡ����ʹ��������������� 			
							
			}	
			break;

		 return false;

		}

   case(osgGA::GUIEventAdapter::DRAG):   //�϶�����
	   		  
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
		
	
   case(osgGA::GUIEventAdapter::SCROLL):         //��ת����
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
		   //λ��
			if(ea.getKey()==0xFF51) deltaPosition._v[0]=-m_speed; 	     //key left
			if(ea.getKey()==0xFF53) deltaPosition._v[0]=m_speed;       //key right

			if(ea.getKey()==osgGA::GUIEventAdapter::KEY_Up) deltaPosition._v[2]=m_speed; 	     //key up

			if(ea.getKey()==osgGA::GUIEventAdapter::KEY_Down) deltaPosition._v[2]=-m_speed; 	     //key down	

			if(ea.getKey()==osgGA::GUIEventAdapter::KEY_Shift_R||ea.getKey()==osgGA::GUIEventAdapter::KEY_Home) deltaPosition._v[1]=m_speed; 	     //key home

			if(ea.getKey()==osgGA::GUIEventAdapter::KEY_Control_R||ea.getKey()==osgGA::GUIEventAdapter::KEY_End) deltaPosition._v[1]=-m_speed; 	     //key end	


			//��ת
			if(ea.getKey()=='j') deltaAngle._v[0]=-osg::DegreesToRadians(r_speed); 	     //key     "j"
			if(ea.getKey()=='k') deltaAngle._v[0]=osg::DegreesToRadians(r_speed);       //key       "k"

			if(ea.getKey()==',') deltaAngle._v[2]=-osg::DegreesToRadians(r_speed);  	     //key  ","

			if(ea.getKey()=='.') deltaAngle._v[2]=osg::DegreesToRadians(r_speed);  	     //key     "."

			if(ea.getKey()=='n') deltaAngle._v[1]=-osg::DegreesToRadians(r_speed);      //key      "n"

			if(ea.getKey()=='m') deltaAngle._v[1]=osg::DegreesToRadians(r_speed);  	     //key    "m"	


			//�ٶ�
			if(ea.getKey()=='-') r_speed=r_speed/5;  	     //key    "-"	  ��ת�ٶ�Ϊ���֮һ
			if(ea.getKey()=='=') r_speed=r_speed*5;  	     //key    "="	 ��ת�ٶȱ��屶
		
			if(ea.getKey()=='9') m_speed=m_speed/5;  	     //key    "9"	  ��ת�ٶ�Ϊ���֮һ
			if(ea.getKey()=='0') m_speed=m_speed*5;  	     //key    "0"	 ��ת�ٶȱ��屶


			//�����ĵ�
			if(ea.getKey()=='h') {
				if(s){ss->setAllChildrenOff(); s=0;} 
				else  { ss->setAllChildrenOn();s=1;}	}     //key    "h"  �����ĵ�


           // ��ʾ����
			if(ea.getKey()==osgGA::GUIEventAdapter::KEY_Return) i++;  	     //key    "Enter"	
			if(ea.getKey()==osgGA::GUIEventAdapter::KEY_BackSpace) if(i>0)i--; 


			//������ʾ״̬
			if(ea.getKey()==osgGA::GUIEventAdapter::KEY_F1){if(s0!=1) s0=1;else  s0=0;}
			 displaysetting0->setStereo(s0); 
	           

			break;
			return false;
		}
				
				
				
	case(osgGA::GUIEventAdapter::FRAME):  				

	{		  
		 
		   std::string gdlist=" ";   			
           std::ostringstream os;  //����һ�������			

		  os<<std::endl;	

		  os<<"Object:  "<<wonderful<<"  "<<"Select:  "<<_axis<<std::endl; 
		  os<<"Move speed:  "<<m_speed<<"  Rotate speed:  "<<r_speed<<std::endl;
		  os<<"Real Position: x="<<_position0._v[0]<<" y="<<_position0._v[1]<<" z="<<_position0._v[2]<<std::endl;
		  os<<"Rotated angle: x="<<_angle0._v[0]<<" y="<<_angle0._v[1]<<" z="<<_angle0._v[2]<<std::endl;	
		   if(i>21)i=21;       //ʹ��������ʾ����������ʵ������
		  os<<"Displayed:      "<< i;
		
		//  os<<"pathsize is  "<<k;
	      gdlist +=os.str();
	      setLabel(gdlist);   //����ʵʱ��ʾ����
	
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
		  

			//����һ���߶ν�����⺯��
		  osgUtil::LineSegmentIntersector::Intersections intersections;
		  if (view->computeIntersections(x, y, intersections))
		  {
			  osgUtil::LineSegmentIntersector::Intersection intersection = *intersections.begin();
			  osg::NodePath& nodePath = intersection.nodePath;

			  //�õ�ѡ�������
			  node = (nodePath.size()>=1)?nodePath[nodePath.size()-1]:0;
			  parent = (nodePath.size()>=2)?dynamic_cast<osg::Group*>(nodePath[nodePath.size()-2]):0;
			  parent2=(nodePath.size()>=3)?dynamic_cast<osg::Group*>(nodePath[nodePath.size()-3]):0;  
		    
			 
			  nodepat=dynamic_cast<osg::PositionAttitudeTransform*>(nodePath.at(3));//�ڵ�λ�õ���λ
			   wonderful=nodepat->getName();	 		
			   
		      // k=nodePath.size();
           
			   nodename=node->getName();          //��ȡ�ڵ�����
			  _axis=parent2->getName();           //��ȡ���ڵ�����
			  
			  if(_axis==wonderful)_axis=nodename;
			 
	
			//����ʰȡ�����x_pick��y_pick��z_pick��ֵ	 
			 if(_axis=="x") x_pick=true; else x_pick=false;
			 
			 if(_axis=="y") y_pick=true;  else  y_pick=false;
			    	
			 if(_axis=="z") z_pick=true;  else   z_pick=false; 	

		     //�ø�����ʾ���������������Ѿ���ѡ��
		     if (parent && node)  //���ѡ��
		       { 
			       
			        osgFX::Scribe* parentAsScribe1 = dynamic_cast<osgFX::Scribe*>(parent);    //����                 
				
			
			      if (!parentAsScribe1)                   //���û�и������������ʾ       
			          {							  
				          osgFX::Scribe* scribe = new osgFX::Scribe();
				          scribe->addChild(node);									  
				          parent->replaceChild(node,scribe);  
										 
			           }
			     else                                         //����Ѿ���������������
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
						    
		
