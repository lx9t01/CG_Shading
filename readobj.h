#pragma once
#include <string>
#include <vector>
#include </usr/local/include/Eigen/Dense>
#include <stdio.h>

using namespace Eigen;
using namespace std;


struct RGB{
    float R,G,B;
};


struct vertex {
  float x, y, z, w;
  vertex(float x1, float y1, float z1, float w1) {
    x = x1;
    y = y1;
    z = z1;
    w = w1;
  }
};

struct vertexn{
    float x, y, z, w;
    vertexn(float x1, float y1, float z1 , float w1) {
        x = x1;
        y = y1;
        z = z1;
        w = w1;
    }
};

struct face {
  int a, b, c;
    int an, bn, cn;
    RGB a_color, b_color, c_color;
  face(int a1, int a2, int b1, int b2, int c1, int c2) {
    a = a1;
    b = b1;
    c = c1;
      an=a2;
      bn=b2;
      cn=c2;
  }
};

struct light{
    float pos[3];
    int color[3];
    float k;
};



class GraphObj {
 public:
  GraphObj(char* s);
  GraphObj();
  bool readObj(char const* s);
  Matrix4f readTrans(char const* s);
  Matrix4f rotation (float a, float b, float c, float d);
  Matrix4f translation (float a, float b, float c);
  Matrix4f scaling (float a, float b, float c);
    
    //readobj.cpp
  string getName();
  unsigned int getNumber();
  bool setName(string s);
  bool setNumber(unsigned int n);
    string getPrintName();
    bool setPrintName(string s);
    int dupMore();
    int getDupNumber();
    
  Matrix4f matrix=Matrix4f::Identity(4,4);
    Matrix4f inv_matrix=Matrix4f::Zero(4,4);
    Matrix4f n_matrix=Matrix4f::Identity(4,4);
    Matrix4f inv_n_matrix=Matrix4f::Zero(4,4);
    
    //readtrans.cpp
    vector<vertex> getVertex();
    vector<face> getFace();
    bool setVertex(vector<vertex> v1);
    bool setFace(vector<face> f1);//color render
    bool setVertex_NDC(vector<vertex> v1);
    vector<vertex> getVertex_NDC();
    vector<vertexn> getVertexN();
    bool setVertexN(vector<vertexn>);
    
    //readobj.cpp
    bool setAmbient(float r, float g,float b);
    bool setDiffuse(float r, float g, float b);
    bool setSpecular(float r, float g, float b);
    bool setShininess(float p);
    float ambient[3];
    float diffuse[3];
    float specular[3];
    float shininess;


 private:
  string objname;
    string printname;
  unsigned int objnumber;
  int dupnumber=0;
  vector<vertex> v;
  vector<face> f;
    vector <vertex> v_NDC;
    vector<vertexn> vn;

    
    
};

class camera{
    
public:
    Matrix4f setInvC(float cam_p[3], float cam_o[4]);
    Matrix4f getInvC();
    
private:
    Matrix4f inv_C=Matrix4f::Identity(4,4);
    
};

Vector3f lighting(vertex P, vertexn n,
                  float diffuse[3], float ambient[3], float specular[3], float p,
                  vertex e, vector<light> lights);

Vector4f NDC2cam(vertex v_ndc, Matrix4f P);

Vector4f cam2world(Vector4f v_cam, Matrix4f P);

float compute_alpha(float xa, float ya, float xb, float yb, float xc, float yc, float x, float y);

float compute_beta(float xa, float ya, float xb, float yb, float xc, float yc, float x, float y);

float compute_gamma(float xa, float ya, float xb, float yb, float xc, float yc, float x, float y);


