//created by coldestlin  email: coldestlin@qq.com

#include<osgViewer/Viewer>
#include<osgViewer/ViewerEventHandlers>

#include<osgGA/StateSetManipulator>
#include<osgGA/AnimationPathManipulator>

#include<osg/Node>
#include<osg/Group>
#include<osg/Geode>

#include<osgUtil/Optimizer>

#include"assembly.h"
#include"helpText.h"

int main()
{	
	 osgViewer::Viewer* viewer= new osgViewer::Viewer();                  //����Viewer���󣬳���������

	 //��Ӹ���״̬������
	 {
	      //״̬���ò�������������L�����Ƶƹ�
	      viewer->addEventHandler(new osgGA::StateSetManipulator(viewer->getCamera()->getOrCreateStateSet()));  
          //���ڳߴ� 
	      viewer->addEventHandler(new osgViewer::WindowSizeHandler);  
		  //��ô���״̬    
	      viewer->addEventHandler(new osgViewer::StatsHandler);   
	      //���cameraλ�ü�¼
          viewer->addEventHandler(new osgViewer::RecordCameraPathHandler);          
	 }
	
	
    osg::Group* root= new osg::Group();
      

	//�������װ��״̬�ı�	
	osgText::Text* updatetext=new osgText::Text();     //����Textָ�����
	updatetext->setPosition(osg::Vec3(10,1020,0));    //����λ��
	updatetext->setCharacterSize(20.0f);               //�����С
	
	createhud *hudText=new createhud();            //  ����hudText   	
	root->addChild(hudText->hud1(updatetext));      //
	


   //�����¼�������  PickHandler ����ʼ��
	PickHandler p(updatetext);           
	

	//�����ܽڵ�
	osg::PositionAttitudeTransform*assembly=dynamic_cast<osg::PositionAttitudeTransform*>(new Part);	
	 
	p.setPat(assembly);                //����������¼���������	
	
	root->addChild(assembly);           //��ӵ�����

	viewer->addEventHandler(&p);        //���PICK�¼�������


    //��������ı�����	
	osgText::Text* text1=new osgText::Text();     //����Textָ�����
	text1->setText(L"Press h for help ");
	text1->setPosition(osg::Vec3(5,10,0));    //����λ��
	text1->setCharacterSize(20.0f);               //�����С
	createhud *hudText1=new createhud();            //  ����hudText                  
	root->addChild((hudText1->hud1(text1)));	

	osgText::Text* text2=new osgText::Text();     //����Textָ�����
	text2->setText("SJTU PRP: Virtual Assembly");
	text2->setPosition(osg::Vec3(950,990,0));    //����λ��
	text2->setCharacterSize(40.0f);               //�����С
	text2->setColor(osg::Vec4(1.0f,0.0f,0.0f,1.0f));
	createhud *hudText2=new createhud();            //  ����hudText                  
	root->addChild((hudText2->hud1(text2)));
	
	
    //��Ӱ����ĵ�
	ss->addChild(helpHUDText(),0);    
	root->addChild(ss);

	//�Ż���������
	osgUtil::Optimizer optimizer;       
	optimizer.optimize(root);

   //���������ʾ
    viewer->setDisplaySettings( displaysetting0 );

    viewer->setSceneData(root);
    viewer->realize();
    viewer->run();
   
    return 0;
}
