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

osg::Vec3 deltaPosition=osg::Vec3(0,0,0);    //记录位置变化量
osg::Vec3 mousePosition=osg::Vec3(0,0,0);     //鼠标位置变化量
osg::Vec3 deltaAngle=osg::Vec3(0,0,0);        //角度变化量


class PickHandler:public osgGA::GUIEventHandler  //创建类 pick事件处理器
{
public:
	PickHandler(osgText::Text* updateText):_updateText(updateText),  //初始化各变量
		_mx(0),_my(0),x_pick(0),y_pick(0),z_pick(0),leftButton(0)              
	{		
				
	}
	~PickHandler(){}
	bool handle(const osgGA::GUIEventAdapter&ea,osgGA::GUIActionAdapter& aa);    //  事件处理
	
	void setLabel(const std::string& name)       //显示内容
	{
		_updateText->setText(name);
	}
	void setPat(osg::PositionAttitudeTransform *pat1)     //将具体的PositionAttitudeTransform类导入类中
	{
		pat=pat1;
	}
	void pick(osgViewer::View* view,float x,float y);   //选取函数

	
	 float _mx;         //保存鼠标位置
     float _my; 

   //判断箭头被选择状态
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



