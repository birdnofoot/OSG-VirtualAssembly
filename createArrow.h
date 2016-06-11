#pragma once
#include<osg/Node>
#include<osg/Group>
#include<osg/Geode>

#include<osg/PositionAttitudeTransform>
#include<osg/MatrixTransform>


//����һ����ͷ
osg::PositionAttitudeTransform *createArrow(osg::Node *node)
{  
	//��ͷ�ߴ����Χ��뾶�ɱ���
	
    float radius=node->getBound().radius();
	float r=0.02*radius;
	float l=radius;
	float h=0.1*radius;
	float d=0.05*radius;
	//����һ��Ҷ�ڵ����
	osg::Geode* geode = new osg::Geode();
	
	//����һ�����������
	osg::Geometry* geom1 = new osg::Geometry();
	osg::Geometry* geom2 = new osg::Geometry();

	//�����������飬���˳����ʱ��
	osg::Vec3Array* v1= new osg::Vec3Array();
	osg::Vec3Array* v2= new osg::Vec3Array();
  
   
	for(int phi=90; phi<271;phi++ )
	{
		v1->push_back(osg::Vec3(r*cos(phi*osg::PI/180),0.0f,r*sin(phi*osg::PI/180)));
	}
	v1->push_back(osg::Vec3(l,0.0f,-r));
	v2->push_back(osg::Vec3(l,0.0f,-d));
	v2->push_back(osg::Vec3(l+h,0.0f,0.0f));
	v2->push_back(osg::Vec3(l,0.0f,d));
	v1->push_back(osg::Vec3(l,0.0f,r));

	//���ö�������
	geom1->setVertexArray(v1);
	geom2->setVertexArray(v2);

	//������ɫ����
	osg::Vec4Array* vc = new osg::Vec4Array();
	//�������
	vc->push_back(osg::Vec4(1.0f,0.0f,0.0f,1.0f));
	
	//������ɫ����
	geom1->setColorArray(vc);
	geom2->setColorArray(vc);
	//������ɫ�İ󶨷�ʽΪ��������
	geom1->setColorBinding(osg::Geometry::BIND_OVERALL);
	geom2->setColorBinding(osg::Geometry::BIND_OVERALL);

	//������������
	osg::Vec3Array* nc = new osg::Vec3Array();
	//��ӷ���
	nc->push_back(osg::Vec3(0.0f,-1.0f,0.0f));

	//���÷�������
	geom1->setNormalArray(nc);
	geom2->setNormalArray(nc);

	//���÷��ߵİ󶨷�ʽΪȫ������
	geom1->setNormalBinding(osg::Geometry::BIND_OVERALL);
	geom2->setNormalBinding(osg::Geometry::BIND_OVERALL);

	//���ͼԪ����ͼ��ԪΪ�ı���
	geom1->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POLYGON,0,183));
	geom2->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POLYGON,0,3));

	//��ӵ�Ҷ�ڵ�
	geode->addDrawable(geom1);
	geode->addDrawable(geom2);

   osg::PositionAttitudeTransform *pat = new osg::PositionAttitudeTransform();
   pat->addChild(geode);
                 
	//x������
  osg::PositionAttitudeTransform*arrow_x= new osg::PositionAttitudeTransform;
  arrow_x->addChild(dynamic_cast<osg::PositionAttitudeTransform*> (pat->clone(osg::CopyOp::DEEP_COPY_ALL)));

   //y������
   osg::PositionAttitudeTransform*arrow_y= new osg::PositionAttitudeTransform;
   arrow_y->addChild(dynamic_cast<osg::PositionAttitudeTransform*> (pat->clone(osg::CopyOp::DEEP_COPY_ALL)));
   arrow_y->setAttitude(osg::Quat(0,osg::Vec3(1,0,0),0,osg::Vec3(0,1,0),osg::DegreesToRadians(90.0),osg::Vec3(0,0,1)));

   //z������
   osg::PositionAttitudeTransform*arrow_z=new osg::PositionAttitudeTransform;
   arrow_z->addChild(dynamic_cast<osg::PositionAttitudeTransform*> (pat->clone(osg::CopyOp::DEEP_COPY_ALL)));
   arrow_z->setAttitude(osg::Quat(0,osg::Vec3(1,0,0),osg::DegreesToRadians(270.0),osg::Vec3(0,1,0),0,osg::Vec3(0,0,1)));
   
   osg::PositionAttitudeTransform*arrow_final=new osg::PositionAttitudeTransform;
  
   arrow_final->addChild(arrow_y);   
   arrow_final->addChild(arrow_z);
   arrow_final->addChild(arrow_x);
   //arrow_final->addChild(node);

   arrow_x->setName("x");    
   arrow_y->setName("y");
   arrow_z->setName("z");
	
   return arrow_final;


}

