#ifndef TINY_RENDERER_H
#define TINY_RENDERER_H

#include "geometry.h"
#include "Bullet3Common/b3AlignedObjectArray.h"
#include "Bullet3Common/b3Vector3.h"
#include "LinearMath/btAlignedObjectArray.h"
#include "LinearMath/btVector3.h"


#include "tgaimage.h"

struct TinyRenderObjectData
{
    //Camera
    Matrix m_viewMatrix;
    Matrix m_projectionMatrix;
    Matrix m_viewportMatrix;

	btVector3 m_eye;
	btVector3 m_center;
	
    //Model (vertices, indices, textures, shader)
    Matrix m_modelMatrix;
    class Model*  m_model;
    //class IShader* m_shader; todo(erwincoumans) expose the shader, for now we use a default shader
            
    //Output
    int m_width;
    int m_height;
    TGAImage& m_rgbColorBuffer;
    b3AlignedObjectArray<float>& m_depthBuffer;
    
    TinyRenderObjectData(int width, int height,TGAImage& rgbColorBuffer,b3AlignedObjectArray<float>& depthBuffer);
    virtual ~TinyRenderObjectData();
    
    void loadModel(const char* fileName);
    void createCube(float HalfExtentsX,float HalfExtentsY,float HalfExtentsZ);
    void registerMeshShape(const float* vertices, int numVertices,const int* indices, int numIndices,
		unsigned char* textureImage=0, int textureWidth=0, int textureHeight=0);
	
	void registerMesh2(btAlignedObjectArray<btVector3>& vertices, btAlignedObjectArray<btVector3>& normals,btAlignedObjectArray<int>& indices);
    
    void* m_userData;
    int m_userIndex;
};


class TinyRenderer
{
    public:
        static void renderObject(TinyRenderObjectData& renderData);
};

#endif // TINY_RENDERER_Hbla
