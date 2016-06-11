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
	 osgViewer::Viewer* viewer= new osgViewer::Viewer();                  //创建Viewer对象，场景漫游器

	 //添加各类状态操作器
	 {
	      //状态设置操作器，可以用L键控制灯光
	      viewer->addEventHandler(new osgGA::StateSetManipulator(viewer->getCamera()->getOrCreateStateSet()));  
          //窗口尺寸 
	      viewer->addEventHandler(new osgViewer::WindowSizeHandler);  
		  //获得窗口状态    
	      viewer->addEventHandler(new osgViewer::StatsHandler);   
	      //添加camera位置记录
          viewer->addEventHandler(new osgViewer::RecordCameraPathHandler);          
	 }
	
	
    osg::Group* root= new osg::Group();
      

	//添加虚拟装配状态文本	
	osgText::Text* updatetext=new osgText::Text();     //定义Text指针变量
	updatetext->setPosition(osg::Vec3(10,1020,0));    //文字位置
	updatetext->setCharacterSize(20.0f);               //字体大小
	
	createhud *hudText=new createhud();            //  创建hudText   	
	root->addChild(hudText->hud1(updatetext));      //
	


   //创建事件处理器  PickHandler 并初始化
	PickHandler p(updatetext);           
	

	//创建总节点
	osg::PositionAttitudeTransform*assembly=dynamic_cast<osg::PositionAttitudeTransform*>(new Part);	
	 
	p.setPat(assembly);                //物体关联到事件处理器中	
	
	root->addChild(assembly);           //添加到场景

	viewer->addEventHandler(&p);        //添加PICK事件处理器


    //添加其它文本内容	
	osgText::Text* text1=new osgText::Text();     //定义Text指针变量
	text1->setText(L"Press h for help ");
	text1->setPosition(osg::Vec3(5,10,0));    //文字位置
	text1->setCharacterSize(20.0f);               //字体大小
	createhud *hudText1=new createhud();            //  创建hudText                  
	root->addChild((hudText1->hud1(text1)));	

	osgText::Text* text2=new osgText::Text();     //定义Text指针变量
	text2->setText("SJTU PRP: Virtual Assembly");
	text2->setPosition(osg::Vec3(950,990,0));    //文字位置
	text2->setCharacterSize(40.0f);               //字体大小
	text2->setColor(osg::Vec4(1.0f,0.0f,0.0f,1.0f));
	createhud *hudText2=new createhud();            //  创建hudText                  
	root->addChild((hudText2->hud1(text2)));
	
	
    //添加帮助文档
	ss->addChild(helpHUDText(),0);    
	root->addChild(ss);

	//优化场景数据
	osgUtil::Optimizer optimizer;       
	optimizer.optimize(root);

   //添加立体显示
    viewer->setDisplaySettings( displaysetting0 );

    viewer->setSceneData(root);
    viewer->realize();
    viewer->run();
   
    return 0;
}
