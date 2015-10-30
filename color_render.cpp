//
//  color_render.cpp
//  hw2
//
//  Created by 徐海翔 on 15/10/25.
//  Copyright © 2015年 徐海翔. All rights reserved.
//

#include <stdio.h>
#include "readobj.h"
#include <iostream>
#include <algorithm>

using namespace std;
using Eigen::MatrixXd;




Vector3f lighting(vertex P, vertexn n,
                  float diffuse[3], float ambient[3], float specular[3], float p,
                  vertex e, vector<light> lights){
    Vector3f c_v(1,1,1);
    
    Vector3f cd, ca, cs;
    cd<<diffuse[0],diffuse[1],diffuse[2];
    ca<<ambient[0],ambient[1],ambient[2];
    cs<<specular[0],specular[1],specular[2];
    Vector3f diffuse_sum=Vector3f::Zero(3);
    Vector3f specular_sum=Vector3f::Zero(3);
    
    Vector3f e_v, e_dir, P_v;
    e_v<<e.x,e.y,e.z;
    P_v<<P.x,P.y,P.z;
    e_dir=(e_v-P_v);
    e_dir=e_dir.normalized();
    
    for (int i=0;i<lights.size();i++){
        Vector3f lp,lc,ldir;
        lp<<lights[i].pos[0],lights[i].pos[1],lights[i].pos[2];
        lc<<lights[i].color[0],lights[i].color[1],lights[i].color[2];
        //cout<<"lights: "<<lights[i].pos[0]<<" "<<lights[i].pos[1]<<" "<<lights[i].pos[2]<<endl;
        //cout<<"light_color: "<<lights[i].color[0]<<" "<<lights[i].color[1]<<" "<<lights[i].color[2]<<endl;

        ldir=lp-P_v;
        float d; // attenuation distance;
        d=ldir.norm();
        float k=lights[i].k; //k value
        ldir=ldir.normalized();
        
        lc=lc*1/(1+k*d*d);// attenuation
        
        Vector3f n_v;
        n_v<<n.x,n.y,n.z;
        float temp1,temp2;
        temp1=n_v.dot(ldir);
        //cout<<temp1<<endl;
        if (temp1>0)
            temp2=temp1;
        else temp2=0;
        
        Vector3f ldiffuse;
        ldiffuse=lc*temp2;
        diffuse_sum=diffuse_sum+ldiffuse;
        
        temp1=n_v.dot((e_dir+ldir).normalized());
        temp2=(0>temp1)?0:temp1;
        Vector3f lspecular;
        lspecular=lc*pow(temp2,p);
        specular_sum=specular_sum+lspecular;
    }

    c_v=c_v.cwiseMin(ca+diffuse_sum.cwiseProduct(cd)+specular_sum.cwiseProduct(cs));
    
    return c_v;
}



Vector4f NDC2cam(vertex NDC, Matrix4f P){
    
    Vector4f v_ndc, v_cam;
    v_ndc<<NDC.x,NDC.y,NDC.z,NDC.w;
    v_cam=P.inverse()*v_ndc;
//    cout<<"ndc2cam"<<endl;
//    cout<<P.inverse()<<endl;
//    cout<<v_cam<<" ";
    return v_cam;

}

Vector4f cam2world(Vector4f v_cam, Matrix4f P){
    Vector4f v_world;
    v_world=P.inverse()*v_cam;
//    cout<<"cam2world"<<endl;
//    cout<<P.inverse()<<endl;
//    cout<<v_world<<" ";
    return v_world;
}




float compute_alpha(float xa, float ya, float xb, float yb, float xc, float yc, float x, float y){
    return ((yb-yc)*x+(xc-xb)*y+xb*yc-xc*yb)/((yb-yc)*xa+(xc-xb)*ya+xb*yc-xc*yb);
}

float compute_beta(float xa, float ya, float xb, float yb, float xc, float yc, float x, float y){
    return ((ya-yc)*x+(xc-xa)*y+xa*yc-xc*ya)/((ya-yc)*xb+(xc-xa)*yb+xa*yc-xc*ya);
}

float compute_gamma(float xa, float ya, float xb, float yb, float xc, float yc, float x, float y){
    return ((ya-yb)*x+(xb-xa)*y+xa*yb-xb*ya)/((ya-yb)*xc+(xb-xa)*yc+xa*yb-xb*ya);
}

