//
//  bin.cpp
//  hw2_1
//
//  Created by 徐海翔 on 15/10/28.
//  Copyright © 2015年 徐海翔. All rights reserved.
//

#include <stdio.h>
/*
 //==================check======================================
 
 for (int i=0;i<graph_after_color.size();i++){
 vector<face> fcheck;
 vector<vertex> vcheck;
 vector<vertexn> vncheck;
 fcheck=graph_after_color[i].getFace();
 vcheck=graph_after_color[i].getVertex();
 vncheck=graph_after_color[i].getVertexN();
 //        for (int j=0;j<vcheck.size();j++){
 //            cout<<vcheck[j].x<<vcheck[j].y<<vcheck[j].z<<endl;
 //        }
 //Index mismatch, reference from face starts from 1.
 for (int j=0;j<fcheck.size();j++){
 cout<<"face: "<<fcheck[j].a<<" "<<fcheck[j].b<<" "<<fcheck[j].c<<endl;
 cout<<"verteces: "<<endl;
 cout<<vcheck[fcheck[j].a-1].x<<" "<<vcheck[fcheck[j].a-1].y<<" "<<vcheck[fcheck[j].a-1].z<<endl;
 cout<<vcheck[fcheck[j].b-1].x<<" "<<vcheck[fcheck[j].b-1].y<<" "<<vcheck[fcheck[j].b-1].z<<endl;
 cout<<vcheck[fcheck[j].c-1].x<<" "<<vcheck[fcheck[j].c-1].y<<" "<<vcheck[fcheck[j].c-1].z<<endl;
 cout<<"facen: "<<fcheck[j].an<<" "<<fcheck[j].bn<<" "<<fcheck[j].cn<<endl;
 cout<<"vectorN: "<<endl;
 cout<<vncheck[fcheck[j].an-1].x<<" "<<vncheck[fcheck[j].an-1].y<<" "<<vncheck[fcheck[j].an-1].z<<endl;
 cout<<vncheck[fcheck[j].bn-1].x<<" "<<vncheck[fcheck[j].bn-1].y<<" "<<vncheck[fcheck[j].bn-1].z<<endl;
 cout<<vncheck[fcheck[j].cn-1].x<<" "<<vncheck[fcheck[j].cn-1].y<<" "<<vncheck[fcheck[j].cn-1].z<<endl;
 cout<<endl;
 }
 
 for (int j=0;j<vcheck.size();j++){
 cout<<"v_color: "<<vcheck[j].x<<" "<<vcheck[j].y<<" "<<vcheck[j].z<<" "<<vcheck[j].w<<"\n";
 cout<<vcheck[j].R<<" "<<vcheck[j].G<<" "<<vcheck[j].B<<"\n";
 }
 }
 */


//after camera
//    for (int i=0;i<graph_after_camera.size();i++){
//        vector<vertex> vtest;
//        vtest=graph_after_camera[i].getVertex();
//        cout<<vtest.size()<<"\n";
//        vector<face> ftest;
//        ftest=graph_after_camera[i].getFace();
//        cout<<ftest.size()<<"\n";
//        for (int j=0;j<vtest.size();j++) {
//            cout<<"a_xyzw: "<<vtest[i].x<<vtest[i].y<<vtest[i].z<<vtest[i].w<<endl;
//            cout<<"a_RGB: "<<vtest[i].R<<vtest[i].G<<vtest[i].B<<endl;
//        }
//    }


//==================check======================================
/*
 for (int i=0;i<graph_after_NDC.size();i++){
 vector<face> fcheck;
 vector<vertex> vcheck;
 vector<vertexn> vncheck;
 
 fcheck=graph_after_NDC[i].getFace();
 vcheck=graph_after_NDC[i].getVertex();
 vncheck=graph_after_NDC[i].getVertexN();
 cout<<fcheck.size()<<"\n";
 cout<<vcheck.size()<<"\n";
 cout<<vncheck.size()<<"\n";
 //        for (int j=0;j<vcheck.size();j++){
 //            cout<<vcheck[j].x<<vcheck[j].y<<vcheck[j].z<<endl;
 //        }
 //Index mismatch, reference from face starts from 1.
 for (int j=0;j<fcheck.size();j++){
 cout<<"face: "<<fcheck[j].a<<" "<<fcheck[j].b<<" "<<fcheck[j].c<<endl;
 cout<<"verteces: "<<endl;
 cout<<vcheck[fcheck[j].a-1].x<<" "<<vcheck[fcheck[j].a-1].y<<" "<<vcheck[fcheck[j].a-1].z<<" "<<vcheck[fcheck[j].a-1].w<<endl;
 cout<<vcheck[fcheck[j].b-1].x<<" "<<vcheck[fcheck[j].b-1].y<<" "<<vcheck[fcheck[j].b-1].z<<" "<<vcheck[fcheck[j].b-1].w<<endl;
 cout<<vcheck[fcheck[j].c-1].x<<" "<<vcheck[fcheck[j].c-1].y<<" "<<vcheck[fcheck[j].c-1].z<<" "<<vcheck[fcheck[j].c-1].w<<endl;
 cout<<"facen: "<<fcheck[j].an<<" "<<fcheck[j].bn<<" "<<fcheck[j].cn<<endl;
 cout<<"vectorN: "<<endl;
 cout<<vncheck[fcheck[j].an-1].x<<" "<<vncheck[fcheck[j].an-1].y<<" "<<vncheck[fcheck[j].an-1].z<<" "<<vncheck[fcheck[j].an-1].w<<endl;
 cout<<vncheck[fcheck[j].bn-1].x<<" "<<vncheck[fcheck[j].bn-1].y<<" "<<vncheck[fcheck[j].bn-1].z<<" "<<vncheck[fcheck[j].bn-1].w<<endl;
 cout<<vncheck[fcheck[j].cn-1].x<<" "<<vncheck[fcheck[j].cn-1].y<<" "<<vncheck[fcheck[j].cn-1].z<<" "<<vncheck[fcheck[j].cn-1].w<<endl;
 cout<<endl;
 }
 
 for (int j=0;j<vcheck.size();j++){
 cout<<"v_color: "<<vcheck[j].x<<" "<<vcheck[j].y<<" "<<vcheck[j].z<<" "<<vcheck[j].w<<"\n";
 cout<<vcheck[j].R<<" "<<vcheck[j].G<<" "<<vcheck[j].B<<"\n";
 }
 }
 */