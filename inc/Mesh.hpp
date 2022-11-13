#ifndef MESH_HPP_
#define MESH_HPP_

#include <cmath>
#include <vector>
#include <fstream>
#include <string>

#include "Vector.hpp"

#define ZOOM 100

struct Triangle{
    Vector3 vertices[3];
    Vector2 projectedVertices[3];

    void ProjectVertex(int vertexIndex, float fovFactor){
        projectedVertices[vertexIndex].x = vertices[vertexIndex].x*(fovFactor);
        projectedVertices[vertexIndex].y = vertices[vertexIndex].y*(fovFactor);
    }

    void RotateVertex(int vertexIndex, Vector3 rotation){
        vertices[vertexIndex].Rotate(rotation);
    }

    void TranslateVertex(int vertexIndex, Vector3 distance){//z -5
        vertices[vertexIndex].x -= distance.x;
        vertices[vertexIndex].y -= distance.y;
        vertices[vertexIndex].z += distance.z;//negative
    }
};


class Mesh{
private:
    //int MAX;
    int WIDTH,HEIGHT;
    size_t T_size;
    Vector3 cameraPosition{0,0,-10};

    Vector3 rotation{0,0,0};//0.01,0.01,0.01
    Vector3 rotationAmount{0.01,0.03,0.01};

    std::vector<Vector3> faces;
    std::vector<Vector3> vertices;
    std::vector<Triangle> triangles;

public:
    Mesh() = default;
    explicit Mesh(int _w,int _h):WIDTH(_w),HEIGHT(_h){}
    ~Mesh(){
        faces.clear();
        vertices.clear();
        triangles.clear();
    }

    void SetUp(std::string _file);
    void setFileObject(std::ifstream &_file);
    void Update();

    inline int returnX(int i,int j){
        return triangles[i].projectedVertices[j].x;
    }

    inline int returnY(int i,int j){
        return triangles[i].projectedVertices[j].y;
    }

    inline size_t GetSizeTriangle(){
        return this->T_size;
    }
};

#endif
