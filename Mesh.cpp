#include "Mesh.h"

#include <vector>

#include <glm/gtc/constants.hpp>

#include "Material.h"

Mesh::Mesh() : fvf(FVF::Position), nVertices(0), nIndeces(0)
{

}

void Mesh::SetVertexArray(void* vertices, unsigned int size, int FVF, const std::vector<unsigned int>& indices) {
	fvf = FVF;
	nIndeces = indices.size();

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
}
Mesh* Mesh::c1(float x, float y, float z, float width, float height) {
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	vertices.resize(24);

	int s;

	auto v = vertices.begin();
	//1
	for (s = 0; s < 4; s++) {
		float vy = 0;
		float vx = 0;
		if (s < 2 == 0)
			vy = y;
		else
			vy = y + height;
		if (s % 2 == 0)
			vx = x;
		else
			vx = x + width;

		float const vz = z;

		Vertex v_temp;
		v_temp.position = vec3(vx, vy, vz);
		v_temp.normal = glm::normalize(vec3(vx, vy, vz));
		v_temp.texcoord = vec2(s % 2, s / 2);

		*v++ = v_temp;
	}
	//2
	for (s = 0; s < 4; s++) {
		float vy = 0;
		float vx = 0;
		if (s < 2 == 0)
			vy = y;
		else
			vy = y + height;
		if (s % 2 == 0)
			vx = x;
		else
			vx = x + width;

		float const vz = z - width;

		Vertex v_temp;
		v_temp.position = vec3(vx, vy, vz);
		v_temp.normal = glm::normalize(vec3(vx, vy, vz));
		v_temp.texcoord = vec2(s % 2, s / 2);

		//v_temp.texcoord = vec2(s, r);

		*v++ = v_temp;
	}

	indices.push_back(2);
	indices.push_back(1);
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);

	indices.push_back(4);
	indices.push_back(5);
	indices.push_back(6);
	indices.push_back(7);
	indices.push_back(6);
	indices.push_back(5);
	Mesh* mesh = new Mesh();
	mesh->fvf = FVF::Position | FVF::Normal | FVF::TexCoord;
	mesh->nVertices = vertices.size();
	mesh->nIndeces = indices.size();

	glGenBuffers(1, &mesh->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glGenBuffers(1, &mesh->IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
	return mesh;
}
Mesh* Mesh::c2(float x, float y, float z, float width, float height)
{
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	vertices.resize(24);

	int s;

	auto v = vertices.begin();
	//3
	for (s = 0; s < 4; s++) {
		float vy = y + height;
		float vx = 0;

		if (s % 2 == 0)
			vx = x;
		else
			vx = x + width;

		float vz = 0;
		if (s / 2 == 0)
			vz = z;
		else
			vz = z - width;

		Vertex v_temp;
		v_temp.position = vec3(vx, vy, vz);
		v_temp.normal = glm::normalize(vec3(vx, vy, vz));
		v_temp.texcoord = vec2(s % 2, s / 2);

		*v++ = v_temp;
	}
	//4
	for (s = 0; s < 4; s++) {
		float vy = y;
		float vx = 0;

		if (s % 2 == 0)
			vx = x;
		else
			vx = x + width;

		float vz = z;
		if (s / 2 == 0)
			vz = z;
		else
			vz = z - width;

		Vertex v_temp;
		v_temp.position = vec3(vx, vy, vz);
		v_temp.normal = glm::normalize(vec3(vx, vy, vz));
		v_temp.texcoord = vec2(s % 2, s / 2);

		*v++ = v_temp;
	}
	indices.push_back(2);
	indices.push_back(1);
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);

	indices.push_back(4);
	indices.push_back(5);
	indices.push_back(6);
	indices.push_back(7);
	indices.push_back(6);
	indices.push_back(5);
	Mesh* mesh = new Mesh();
	mesh->fvf = FVF::Position | FVF::Normal | FVF::TexCoord;
	mesh->nVertices = vertices.size();
	mesh->nIndeces = indices.size();

	glGenBuffers(1, &mesh->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glGenBuffers(1, &mesh->IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
	return mesh;
}
Mesh* Mesh::c3(float x, float y, float z, float width, float height)
{
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	vertices.resize(24);

	int s;

	auto v = vertices.begin();

	//5
	for (s = 0; s < 4; s++) {
		float vy = 0;
		float vx = x;
		float vz = 0;
		if (s < 2 == 0)
			vy = y;
		else
			vy = y + height;
		if (s % 2 == 0)
			vz = z - width;
		else
			vz = z;


		Vertex v_temp;
		v_temp.position = vec3(vx, vy, vz);
		v_temp.normal = glm::normalize(vec3(vx, vy, vz));
		v_temp.texcoord = vec2(s % 2, s / 2);

		*v++ = v_temp;
	}
	//6
	for (s = 0; s < 4; s++) {
		float vy = 0;
		float vx = x + width;
		float vz = 0;
		if (s < 2 == 0)
			vy = y;
		else
			vy = y + height;
		if (s % 2 == 0)
			vz = z - width;
		else
			vz = z;

		Vertex v_temp;
		v_temp.position = vec3(vx, vy, vz);
		v_temp.normal = glm::normalize(vec3(vx, vy, vz));
		v_temp.texcoord = vec2(s % 2, s / 2);

		*v++ = v_temp;
	}
	indices.push_back(2);
	indices.push_back(1);
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);

	indices.push_back(4);
	indices.push_back(5);
	indices.push_back(6);
	indices.push_back(7);
	indices.push_back(6);
	indices.push_back(5);

	Mesh* mesh = new Mesh();
	mesh->fvf = FVF::Position | FVF::Normal | FVF::TexCoord;
	mesh->nVertices = vertices.size();
	mesh->nIndeces = indices.size();

	glGenBuffers(1, &mesh->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glGenBuffers(1, &mesh->IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
	return mesh;

}
Mesh* Mesh::GenerateCube(float x, float y, float z, float width, float height) {
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	vertices.resize(24);

	int s;

	auto v = vertices.begin();
	//1
	for (s = 0; s < 4; s++) {
		float vy = 0;
		float vx = 0;
		if (s < 2 == 0)
			vy = y;
		else
			vy = y + height;
		if (s%2==0)
			vx = x;
		else
			vx = x + width;

		float const vz = z;

		Vertex v_temp;
		v_temp.position = vec3(vx, vy, vz);
		v_temp.normal = glm::normalize(vec3(vx, vy, vz));
		v_temp.texcoord = vec2(s%2, s/2);

		*v++ = v_temp;
	}
	//2
	for (s = 0; s < 4; s++) {
		float vy = 0;
		float vx = 0;
		if (s < 2 == 0)
			vy = y;
		else
			vy = y + height;
		if (s%2==0)
			vx = x;
		else
			vx = x + width;

		float const vz = z-width;

		Vertex v_temp;
		v_temp.position = vec3(vx, vy, vz);
		v_temp.normal = glm::normalize(vec3(vx, vy, vz));
		v_temp.texcoord = vec2(s%2, s/2);

		//v_temp.texcoord = vec2(s, r);

		*v++ = v_temp;
	}
	
	

	indices.push_back(2);
	indices.push_back(1);
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);

	indices.push_back(4);
	indices.push_back(5);
	indices.push_back(6);
	indices.push_back(7);
	indices.push_back(6);
	indices.push_back(5);
	

	indices.push_back(4);
	indices.push_back(2);
	indices.push_back(0);
	indices.push_back(4);
	indices.push_back(6);
	indices.push_back(2);

	indices.push_back(1);
	indices.push_back(3);
	indices.push_back(5);
	indices.push_back(3);
	indices.push_back(7);
	indices.push_back(5);

	indices.push_back(2);
	indices.push_back(6);
	indices.push_back(7);
	indices.push_back(2);
	indices.push_back(7);
	indices.push_back(3);

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(4);
	indices.push_back(4);
	indices.push_back(1);
	indices.push_back(5);

	Mesh* mesh = new Mesh();
	mesh->fvf = FVF::Position | FVF::Normal | FVF::TexCoord;
	mesh->nVertices = vertices.size();
	mesh->nIndeces = indices.size();

	glGenBuffers(1, &mesh->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glGenBuffers(1, &mesh->IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	return mesh;
	/*glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), v, GL_STATIC_DRAW);

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/
}
Mesh* Mesh::GenerateGround(float height, float width) {

	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	vertices.resize(4);

	int r, s;

	auto v = vertices.begin();
	for (r = 0; r < 2; r++) for (s = 0; s < 2; s++) {
		float const y = -0.5;
		float const x = width*s-50;
		float const z = height*r-50;
		Vertex v_temp; 
		v_temp.position = vec3(x, y, z);
		v_temp.normal = glm::normalize(vec3(x, y, z));
		v_temp.texcoord = vec2(s, r);

		*v++ = v_temp;
	}
	indices.resize(6);
	std::vector<GLuint>::iterator i = indices.begin();
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(3);
	indices.push_back(2);
	indices.push_back(3);
	indices.push_back(0);
	
	Mesh* mesh = new Mesh();
	mesh->fvf = FVF::Position | FVF::Normal | FVF::TexCoord;
	mesh->nVertices = vertices.size();
	mesh->nIndeces = indices.size();

	glGenBuffers(1, &mesh->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glGenBuffers(1, &mesh->IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
	return mesh;

}

Mesh* Mesh::draw_cylinder(GLfloat radius, GLfloat height, GLfloat x, GLfloat y, GLfloat z)
{
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;

	int r, s;

	vertices.resize(126);
	auto v = vertices.begin();

	Vertex v_temp2;
	v_temp2.position = vec3(x, y, z);
	v_temp2.normal = glm::normalize(vec3(x, y, z));
	v_temp2.texcoord = vec2(1, 1);

	*v++ = v_temp2;

	Vertex v_temp3;
	v_temp3.position = vec3(x, y + height, z);
	v_temp3.normal = glm::normalize(vec3(x, y+height, z)); 
	v_temp3.texcoord = vec2(1, 1);

	*v++ = v_temp3;

	//down circle
	for (s = 0; s < 62; s++) {
		float const cy = y;
		float const cx = x+cos(360 / 62 * s) * radius;
		float const cz = z+sin(360 / 62 * s) * radius;

		Vertex v_temp;
		
		v_temp.position = vec3(cx, cy, cz);
		v_temp.normal = glm::normalize(vec3(cx, cy, cz));
		v_temp.texcoord = vec2(0, 0);

		*v++ = v_temp;
	}

	//upside circle
	for (s = 0; s < 62; s++) {
		float const cy = y + height;
		float const cx = x+cos(360 / 62 * s) * radius;
		float const cz = z+sin(360 / 62 * s) * radius;

		Vertex v_temp;

		v_temp.position = vec3(cx, cy, cz);
		v_temp.normal = glm::normalize(vec3(cx, cy, cz));
		v_temp.texcoord = vec2(0, 0);

		*v++ = v_temp;
	}

	indices.resize(124*3);
	std::vector<GLuint>::iterator i = indices.begin();

	for (r = 0; r < 62; r++) {
		indices.push_back(0);
		indices.push_back(r+2);
		if (r == 61)
			indices.push_back(2);
		else
			indices.push_back(r+3);

	}
	for (r = 62; r < 124; r++) {
		indices.push_back(1);
		indices.push_back(r + 2);
		if (r == 123)
			indices.push_back(64);
		else
			indices.push_back(r + 3);
	}

	Mesh* mesh = new Mesh();
	mesh->fvf = FVF::Position | FVF::Normal | FVF::TexCoord;
	mesh->nVertices = vertices.size();
	mesh->nIndeces = indices.size();

	glGenBuffers(1, &mesh->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glGenBuffers(1, &mesh->IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	/*GLfloat x = 0.0;
	GLfloat y = 0.0;
	GLfloat angle = 0.0;
	GLfloat angle_stepsize = 0.1;

	//Draw the tube
	glColor3ub(R - 40, G - 40, B - 40);
	glBegin(GL_QUAD_STRIP);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		glVertex3f(x, y, 0.0);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glVertex3f(radius, 0.0, 0.0);
	glEnd();

	//Draw the circle on top of cylinder
	glColor3ub(R, G, B);
	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glEnd();

	glColor3ub(R, G, B);
	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, 0);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, 0);
	glEnd(); */
	return mesh;
}
Mesh* Mesh::draw_cylinder2(GLfloat radius, GLfloat height, GLfloat x, GLfloat y, GLfloat z)
{
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;

	//	float const R = 1. / (float)(rings - 1);
	//	float const S = 1. / (float)(sectors - 1);
	int r, s;

	vertices.resize(124);
	auto v = vertices.begin();

	//circle
	for (s = 0; s < 62; s++) for(r=0; r<2; r++){
		float const cy = y+height*r;
		float const cx = x+cos(360 / 62 * s) * radius;
		float const cz = z+sin(360 / 62 * s) * radius;

		Vertex v_temp;

		v_temp.position = vec3(cx, cy, cz);
		v_temp.normal = glm::normalize(vec3(cx, cy, cz));
		if(r==0)
			v_temp.texcoord = vec2(s / 62, 0.0);
		else
			v_temp.texcoord = vec2(s / 62, 1.0);

		*v++ = v_temp;
	}

	indices.resize(124 * 3);
	std::vector<GLuint>::iterator i = indices.begin();

	for (r = 0; r < 62; r++) for (s = 0; s < 2; s++) {
		if (s == 0) {
			indices.push_back(2*r);
			indices.push_back(2*r+1);
			if (r == 61)
				indices.push_back(0);
			else
				indices.push_back(2*r+2);
		}
		else {
			indices.push_back(2*r + 1);
			
			if (r == 61) {
				indices.push_back(1);
				indices.push_back(0);
			}
			else {
				indices.push_back(2 * r + 3);
				indices.push_back(2 * r + 2);
			}
		}

	}
	/*for (r = 64; r < 126; r++) {
		indices.push_back(1);
		indices.push_back(r + 2);
		if (r == 123)
			indices.push_back(64);
		else
			indices.push_back(r + 3);

	}*/

	Mesh* mesh = new Mesh();
	mesh->fvf = FVF::Position | FVF::Normal | FVF::TexCoord;
	mesh->nVertices = vertices.size();
	mesh->nIndeces = indices.size();

	glGenBuffers(1, &mesh->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glGenBuffers(1, &mesh->IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	/*GLfloat x = 0.0;
	GLfloat y = 0.0;
	GLfloat angle = 0.0;
	GLfloat angle_stepsize = 0.1;

	//Draw the tube
	glColor3ub(R - 40, G - 40, B - 40);
	glBegin(GL_QUAD_STRIP);
	angle = 0.0;
	while (angle < 2 * PI) {
	x = radius * cos(angle);
	y = radius * sin(angle);
	glVertex3f(x, y, height);
	glVertex3f(x, y, 0.0);
	angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glVertex3f(radius, 0.0, 0.0);
	glEnd();

	//Draw the circle on top of cylinder
	glColor3ub(R, G, B);
	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * PI) {
	x = radius * cos(angle);
	y = radius * sin(angle);
	glVertex3f(x, y, height);
	angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glEnd();

	glColor3ub(R, G, B);
	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * PI) {
	x = radius * cos(angle);
	y = radius * sin(angle);
	glVertex3f(x, y, 0);
	angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, 0);
	glEnd(); */
	return mesh;
}
Mesh* Mesh::cone(GLfloat radius, GLfloat height, GLfloat x, GLfloat y, GLfloat z) {
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;

	int r, s;

	vertices.resize(64);
	auto v = vertices.begin();

	Vertex v_temp3;
	v_temp3.position = vec3(x, y, z);
	v_temp3.normal = glm::normalize(vec3(x, y , z));
	v_temp3.texcoord = vec2(1, 1);

	*v++ = v_temp3;

	Vertex v_temp2;
	v_temp2.position = vec3(x, y+height, z);
	v_temp2.normal = glm::normalize(vec3(x, y+height, z));
	v_temp2.texcoord = vec2(1, 1);

	*v++ = v_temp2;

	//down circle
	for (s = 0; s < 62; s++) {
		float const cy = y;
		float const cx = x + cos(360 / 62 * s) * radius;
		float const cz = z + sin(360 / 62 * s) * radius;

		Vertex v_temp;

		v_temp.position = vec3(cx, cy, cz);
		v_temp.normal = glm::normalize(vec3(cx, cy, cz));
		v_temp.texcoord = vec2(0, 0);

		*v++ = v_temp;
	}

	indices.resize(124 * 3);

	std::vector<GLuint>::iterator i = indices.begin();

	for (r = 0; r < 62; r++) {
		indices.push_back(0);
		indices.push_back(r + 2);
		if (r == 61)
			indices.push_back(2);
		else
			indices.push_back(r + 3);
	}

	for (r = 0; r < 62; r++) {
		indices.push_back(1);
		indices.push_back(r + 2);
		if (r == 61)
			indices.push_back(2);
		else
			indices.push_back(r + 3);
	}
	Mesh* mesh = new Mesh();
	mesh->fvf = FVF::Position | FVF::Normal | FVF::TexCoord;
	mesh->nVertices = vertices.size();
	mesh->nIndeces = indices.size();

	glGenBuffers(1, &mesh->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glGenBuffers(1, &mesh->IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
	return mesh;

}
Mesh* Mesh::GenerateSphere(float radius, unsigned int rings, unsigned int sectors) {
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;

	float const R = 1. / (float)(rings - 1);
	float const S = 1. / (float)(sectors - 1);
	int r, s;

	vertices.resize(rings * sectors);
	auto v = vertices.begin();
	for (r = 0; r < rings; r++) for (s = 0; s < sectors; s++) {
		float const y = 5+sin(-glm::half_pi<float>() + glm::pi<float>() * r * R);
		float const x = cos(2 * glm::pi<float>() * s * S) * sin(glm::pi<float>() * r * R);
		float const z = sin(2 * glm::pi<float>() * s * S) * sin(glm::pi<float>() * r * R);

		Vertex v_temp;
		v_temp.position = vec3(x * radius, y * radius, z * radius);
		v_temp.normal = glm::normalize(vec3(x * radius, y * radius, z * radius));
		v_temp.texcoord = vec2(s*S, r*R);

		*v++ = v_temp;
	}

	indices.resize(rings * sectors * 6);
	std::vector<GLuint>::iterator i = indices.begin();
	for (r = 0; r < rings - 1; r++)
		for (s = 0; s < sectors - 1; s++) {
			int curRow = r * sectors;
			int nextRow = (r + 1) * sectors;
			int nextS = (s + 1) % sectors;

			indices.push_back(nextRow + nextS);
			indices.push_back(nextRow + s);
			indices.push_back(curRow + s);

			indices.push_back(curRow + nextS);
			indices.push_back(nextRow + nextS);
			indices.push_back(curRow + s);
		}

	Mesh* mesh = new Mesh();
	mesh->fvf = FVF::Position | FVF::Normal | FVF::TexCoord;
	mesh->nVertices = vertices.size();
	mesh->nIndeces = indices.size();

	glGenBuffers(1, &mesh->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glGenBuffers(1, &mesh->IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	return mesh;
}
 
void Mesh::Render(float dt) {
	if (material)
		material->Use();

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	glEnableVertexAttribArray(0);
	if (fvf & FVF::Normal)
		glEnableVertexAttribArray(1);
	if (fvf & FVF::TexCoord)
		glEnableVertexAttribArray(2);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	if (fvf & FVF::Normal)
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)12);
	if (fvf & FVF::TexCoord)
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)24);

	glDrawElements(GL_TRIANGLES, nIndeces, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}
