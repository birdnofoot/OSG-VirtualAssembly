#pragma once

#include <osgViewer/Viewer>
#include <osg/Camera>
#include <osg/Matrix>

#include <osgText/Text>
#include <osgText/Font>

#include <iostream>


class createhud                                 //创建HUD类，屏幕上显示文字
	 {
	 public:
		 createhud(){}                        //构造函数
		 ~createhud(){}                      //析构函数
		 osg::Node* hud1(osgText::Text* updateText)             //创建HUD
		 {
			 osg::Camera* hudcamera=new osg::Camera;

			 hudcamera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);     //设置绝对帧的引用

			 hudcamera->setProjectionMatrixAsOrtho2D(0,1280,0,1024);          //设置正投影矩阵

			 hudcamera->setViewMatrix(osg::Matrix::identity());     //设置视图矩阵

			 hudcamera->setRenderOrder(osg::Camera::POST_RENDER);    // 设置渲染顺序是post

             hudcamera->setClearMask(GL_DEPTH_BUFFER_BIT);            //清除深度缓存

 
			 std::string timesFont("fonts//cour.ttf");             // 字体

			 //osg::Vec3 position(50,1000,0.0);                    //设置位置

			 osg::Geode*geode= new osg::Geode();     

			 osg::StateSet* stateset=geode->getOrCreateStateSet();  

			 stateset->setMode(GL_LIGHTING,osg::StateAttribute::OFF);         //关闭光照

			 stateset->setMode(GL_DEPTH_TEST,osg::StateAttribute::OFF);    //关闭深度测试

 			 geode->addDrawable(updateText);

			 hudcamera->addChild(geode);

			 updateText->setCharacterSize(20.0f);

			 updateText->setFont(timesFont);

			// updateText->setColor(osg::Vec4(1.0f,1.0f,1.0f,1.0f));

			//updateText->setText(" ");

			// updateText->setPosition(position);

			 updateText->setDataVariance(osg::Object::DYNAMIC);       //设置数据变量为DYNAMIC

			 return hudcamera;
		 }
	 };

