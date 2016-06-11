
#include"createArrow.h"

#include<osgDB/ReadFile>
#include<osgDB/WriteFile>

//���崢��ڵ���

osg::Vec3 _position0=osg::Vec3(0,0,0);     //��¼�ڵ����λ�ã�ȫ�ֱ���
osg::Vec3 _angle0=osg::Vec3(0,0,0);       //��¼�ڵ���ת�Ƕȣ�ȫ�ֱ���

class Part1:public osg::PositionAttitudeTransform    //�̳���osg::PositionAttitudeTransform ��
{
 
    public:
		Part1(osg::Node* node)
	  {
		
		  pat=createArrow(node);	    //������ͷ      
		  pat->setNodeMask(0x0);	    //���ü�ͷ��ʾ״̬
	      this->addChild(node);	        //����ӽڵ�
	      this->addChild(pat);           //��Ӽ�ͷ

		    //����Ĭ����ʾλ��
	      this->setPosition(osg::Vec3(-5000,0,6000));            
		   //����Ĭ������״̬
 		  this->setAttitude(osg::Quat(osg::DegreesToRadians(90.0),osg::Vec3(1,0,0),0,osg::Vec3(0,1,0),0,osg::Vec3(0,0,1))); 
		  angle=osg::Vec3(0,0,0);          //��ʼ����ת�Ƕ�
	  }
	
	  ~Part1(void){}; 


        //������ת�Ӻ���
	   void setRotation(osg::Vec3& rot)          
	   {
		   	previous_attitude=this->getAttitude();  	   //��ȡԭ��������
	        osg::Quat a(rot.x(),osg::Vec3(1,0,0),rot.y(),osg::Vec3(0,1,0),rot.z(),osg::Vec3(0,0,1));    

			 //������תΪ�������ת����ת�������ƾ�����������ת
	        this->setAttitude(a*previous_attitude);	       
	   }


      //��������϶�����λ���Ӻ���
	   void mousePosition(osg::Vec3 & pos)       
	   {
		   previous_attitude=this->getAttitude();	 

		   //�������ʹ������������϶�ʱ���������������ƶ��������ؾ��������ƶ�
	      this->setPosition(previous_attitude*pos+this->getPosition());       
	   }

      osg::PositionAttitudeTransform* pat;	 
	  osg::Vec3 angle;

    private:		
	 	osg::Quat previous_attitude;		      
  };	

