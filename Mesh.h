#pragma once
#include <GL/glew.h>
#include <GL/glut.h>

#include <glm/glm.hpp>
#include <vector>

using namespace glm;

namespace FVF {
	enum { Position = 0x0, Normal = 0x10, TexCoord = 0x100 };
}

typedef struct Vertex {
	vec3 position;
	vec3 normal;
	vec2 texcoord;
};
#define PI 3.1415927

class Material;
class Mesh {
private:
	GLuint VBO;
	GLuint IBO;
	GLuint texture;
	mat4 world;
	Material* material;
	int fvf;

	int nVertices;
	int nIndeces;
public:
	Mesh();
	void SetVertexArray(void* vertices, unsigned int size, int FVF, const std::vector<unsigned int>& indices);
	void SetMaterial(Material* m) { material = m; };
	void SetMatrix(const mat4& m) { world = m; };
	const mat4& GetMatrix() { return world; };
	Material* GetMaterial() { return material; }
	virtual void Update(float dt) {};
	virtual void Render(float dt);

	static Mesh* GenerateSphere(float radius, unsigned int rings, unsigned int sectors);
	static Mesh* GenerateGround(float height, float width);
	static Mesh* GenerateCube(float x, float y, float z, float width, float height);
	static Mesh* c1(float x, float y, float z, float width, float height);
	static Mesh* c2(float x, float y, float z, float width, float height);
	static Mesh* c3(float x, float y, float z, float width, float height);
	static Mesh* draw_cylinder(GLfloat radius, GLfloat height, GLfloat x, GLfloat y, GLfloat z);
	static Mesh* draw_cylinder2(GLfloat radius, GLfloat height, GLfloat x, GLfloat y, GLfloat z);
	static Mesh* cone(GLfloat radius, GLfloat height, GLfloat x, GLfloat y, GLfloat z);
	
};