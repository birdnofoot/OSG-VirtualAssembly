#pragma once
#include"createArrow.h"
#include"createHudText.h"

#include<osgViewer/Viewer>

#include<osgText/Text>
#include<osgFX/Scribe>

#include<osgGA/GUIEventHandler>
#include<osgGA/StateSetManipulator>
#include<osgViewer/ViewerEventHandlers>

#include<sstream>

osg::Vec3 deltaPosition=osg::Vec3(0,0,0);    //��¼λ�ñ仯��
osg::Vec3 mousePosition=osg::Vec3(0,0,0);     //���λ�ñ仯��
osg::Vec3 deltaAngle=osg::Vec3(0,0,0);        //�Ƕȱ仯��


class PickHandler:public osgGA::GUIEventHandler  //������ pick�¼�������
{
public:
	PickHandler(osgText::Text* updateText):_updateText(updateText),  //��ʼ��������
		_mx(0),_my(0),x_pick(0),y_pick(0),z_pick(0),leftButton(0)              
	{		
				
	}
	~PickHandler(){}
	bool handle(const osgGA::GUIEventAdapter&ea,osgGA::GUIActionAdapter& aa);    //  �¼�����
	
	void setLabel(const std::string& name)       //��ʾ����
	{
		_updateText->setText(name);
	}
	void setPat(osg::PositionAttitudeTransform *pat1)     //�������PositionAttitudeTransform�ർ������
	{
		pat=pat1;
	}
	void pick(osgViewer::View* view,float x,float y);   //ѡȡ����

	
	 float _mx;         //�������λ��
     float _my; 

   //�жϼ�ͷ��ѡ��״̬
	bool x_pick;          
	bool y_pick;
	bool z_pick;
	bool leftButton;

	int k;

protected:    	

	osgText::Text* _updateText;
	osg::PositionAttitudeTransform *pat; 	

	 osg::Node* node ;
    osg::Group* parent ;
	
};



