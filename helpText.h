#pragma once

#include <osg/Geode>
#include <osg/Camera>
#include <osg/Matrix>

#include <osgText/Text>
#include <osgText/Font>

#include <iostream>

osg::Camera* helpHUDText()
{
	osg::Camera* camera = new osg::Camera() ;

	//����ͶӰ����
	camera->setProjectionMatrix(osg::Matrix::ortho2D(0,1280,0,800));

	//������ͼ����ͬʱȷ��������������ͼ��λ�ñ任Ӱ�죬ʹ��
	//����֡����
	camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	camera->setViewMatrix(osg::Matrix::identity());

	//�����Ȼ���
	camera->setClearMask(GL_DEPTH_BUFFER_BIT);

	//������Ⱦ˳��ΪPOST
	camera->setRenderOrder(osg::Camera::POST_RENDER);

	//����Ϊ�������¼���ʼ�ղ��õ�����
	camera->setAllowEventFocus(false);

	osg::Geode* geode = new osg::Geode() ;
	osg::StateSet* stateset = geode->getOrCreateStateSet() ;
	//�رչ���
	stateset->setMode(GL_LIGHTING,osg::StateAttribute::OFF);
	//�ر���Ȳ���
	stateset->setMode(GL_DEPTH_TEST,osg::StateAttribute::OFF);

	//��������
	osgText::Text* text = new osgText::Text() ;

	osgText::Font* font = new osgText::Font();
    font = osgText::readFontFile("fonts//Vera.ttf") ;//"fonts//cour.ttf"

	text->setFont(font);

	 std::string gdlist=" ";   			
     std::ostringstream os;  //����һ�������			

	os<<std::endl;

   

	os<<"                                   Virtual Assembly Instrustion\n"<<std::endl;
    os<<"                               Warning: DO NOT CLICK THE WORDS\n\n"<<std::endl;


    os<<"Enter                     Display objects\n\n";   
	os<<"Backspace             Hide objects\n\n";
	os<<"Click to select object, drag to move, scroll to rotate, arrow_axis  selected dominates the orientation\n\n"; 

	os<<"Position Control:     Shift(L)   Ctrl(L)   Left   Right   Up   Down               Speed:       9        0 \n\n";
	os<<"Rotation Control:       j           k          n         m          ,           .                 Speed:      -        =  \n\n";	
	   

	os<<"h                  Onscreen help\n\n"; 
	os<<"l                   Toggle lighting\n\n";
	os<<"s                  On screen stats\n\n";
	os<<"f                  Toggle full screen\n\n";
	os<<"t                  Toggle texturing\n\n";
	os<<"w                 Change fill mode\n\n";
	os<<"z                  Toggle camera path record\n\n";
	os<<"Z                  Toggle camera path play back\n\n";
	os<<"F1                Toggle setreo display\n\n";
	
	os<<"Tips:if the arrow cannot display correctly,just press 'b'"<<std::endl;
	os<<"Created by coldestlin";
	
	 gdlist +=os.str();
	     
	text->setText(gdlist);
	
	text->setPosition(osg::Vec3(100,700,0));
	text->setCharacterSize(15.0f);
	text->setColor(osg::Vec4(1.0f,1.0f,1.0f,1.0f));
	//text->setDrawMode(osgText::Text::TEXT | osgText::Text::BOUNDINGBOX);

	geode->addDrawable(text);

	camera->addChild(geode);

	return camera ;
}
       
 