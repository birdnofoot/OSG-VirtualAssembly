#pragma once

#include <osgViewer/Viewer>
#include <osg/Camera>
#include <osg/Matrix>

#include <osgText/Text>
#include <osgText/Font>

#include <iostream>


class createhud                                 //����HUD�࣬��Ļ����ʾ����
	 {
	 public:
		 createhud(){}                        //���캯��
		 ~createhud(){}                      //��������
		 osg::Node* hud1(osgText::Text* updateText)             //����HUD
		 {
			 osg::Camera* hudcamera=new osg::Camera;

			 hudcamera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);     //���þ���֡������

			 hudcamera->setProjectionMatrixAsOrtho2D(0,1280,0,1024);          //������ͶӰ����

			 hudcamera->setViewMatrix(osg::Matrix::identity());     //������ͼ����

			 hudcamera->setRenderOrder(osg::Camera::POST_RENDER);    // ������Ⱦ˳����post

             hudcamera->setClearMask(GL_DEPTH_BUFFER_BIT);            //�����Ȼ���

 
			 std::string timesFont("fonts//cour.ttf");             // ����

			 //osg::Vec3 position(50,1000,0.0);                    //����λ��

			 osg::Geode*geode= new osg::Geode();     

			 osg::StateSet* stateset=geode->getOrCreateStateSet();  

			 stateset->setMode(GL_LIGHTING,osg::StateAttribute::OFF);         //�رչ���

			 stateset->setMode(GL_DEPTH_TEST,osg::StateAttribute::OFF);    //�ر���Ȳ���

 			 geode->addDrawable(updateText);

			 hudcamera->addChild(geode);

			 updateText->setCharacterSize(20.0f);

			 updateText->setFont(timesFont);

			// updateText->setColor(osg::Vec4(1.0f,1.0f,1.0f,1.0f));

			//updateText->setText(" ");

			// updateText->setPosition(position);

			 updateText->setDataVariance(osg::Object::DYNAMIC);       //�������ݱ���ΪDYNAMIC

			 return hudcamera;
		 }
	 };

