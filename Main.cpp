#include <GL/glew.h>
#include <GL/glut.h>

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"
#include "Material.h"
#include "Camera.h"
#include "Mesh.h"
#include "Texture.h"
#include "Terrain.h"

#define PI 3.1415927
GLfloat radius = 0.3;
GLfloat height = 1.0;
GLuint VBO;
GLuint IBO;

int menu = 0;

Shader shader;
Camera camera;

Mesh* cube;
Mesh* cube2;
Mesh* cube3;
Mesh* cube4;
Mesh* cube5;
Mesh* cube6;
Mesh* cube7;
Mesh* cube8;
Mesh* cube9;
Mesh* circle;
Mesh* tube;
Mesh* circle2;
Mesh* tube2;
Mesh* circle3;
Mesh* tube3;
Mesh* sphere;
Mesh* cone;
Mesh* cube1;
Mesh* cube21;
Mesh* cube31;
Mesh* cube41;
Mesh* cube51;
Mesh* cube61;
Mesh* cube71;
Mesh* cube81;
Mesh* cube91;
Mesh* circle1;
Mesh* tube1;
Mesh* circle21;
Mesh* tube21;
Mesh* circle31;
Mesh* tube31;
Mesh* sphere1;
Mesh* cone1;
Material* phong;
Material* terrainMaterial;
Material* cubeMaterial;
Material* cubeMaterial2;
Material* cubeMaterial3;
Material* cubeMaterial4;
Material* cubeMaterial5;
Material* cubeMaterial6;
Material* cubeMaterial7;
Material* cubeMaterial8;
Material* cubeMaterial9;
Material* cylinderMaterial1;
Material* cylinderMaterial2;
Material* cylinderMaterial3;
Material* cylinderMaterial4;
Material* cylinderMaterial5;
Material* cylinderMaterial6;
Material* coneMaterial;
Material* phong1;
Material* terrainMaterial1;
Material* cubeMaterial1;
Material* cubeMaterial21;
Material* cubeMaterial31;
Material* cubeMaterial41;
Material* cubeMaterial51;
Material* cubeMaterial61;
Material* cubeMaterial71;
Material* cubeMaterial81;
Material* cubeMaterial91;
Material* cylinderMaterial11;
Material* cylinderMaterial21;
Material* cylinderMaterial31;
Material* cylinderMaterial41;
Material* cylinderMaterial51;
Material* cylinderMaterial61;
Material* coneMaterial1;
Mesh* terrain;
Mesh* terrain1;
// Terrain* terrain;

using namespace glm;
void InitGeometry2() {

	sphere1 = Mesh::GenerateSphere(10, 16, 32);
	sphere1->SetMaterial(phong1);

	cube1 = Mesh::c1(-5.0f, 0.0f, 5.0f, 10.0f, 10.0f);
	cube1->SetMaterial(cubeMaterial1);
	cube21 = Mesh::c2(-5.0f, 0.0f, 5.0f, 10.0f, 10.0f);
	cube21->SetMaterial(cubeMaterial21);
	cube31 = Mesh::c3(-5.0f, 0.0f, 5.0f, 10.0f, 10.0f);
	cube31->SetMaterial(cubeMaterial31);

	cube41 = Mesh::c1(-30.f, 10.0f, 5.0f, 10.0f, 20.0f);
	cube41->SetMaterial(cubeMaterial41);
	cube51 = Mesh::c2(-30.f, 10.0f, 5.0f, 10.0f, 20.0f);
	cube51->SetMaterial(cubeMaterial51);
	cube61 = Mesh::c3(-30.f, 10.0f, 5.0f, 10.0f, 20.0f);
	cube61->SetMaterial(cubeMaterial61);

	cube71 = Mesh::c1(20.0f, 0.0f, 5.0f, 10.0f, 10.0f);
	cube71->SetMaterial(cubeMaterial71);
	cube81 = Mesh::c2(20.0f, 0.0f, 5.0f, 10.0f, 10.0f);
	cube81->SetMaterial(cubeMaterial81);
	cube91 = Mesh::c3(20.0f, 0.0f, 5.0f, 10.0f, 10.0f);
	cube91->SetMaterial(cubeMaterial91);

	terrain1 = Mesh::GenerateGround(100, 100);
	terrain1->SetMaterial(terrainMaterial1);

	circle1 = Mesh::draw_cylinder(2.0f, 5.0f, 0.0f, 10.0f, 0.0f);
	circle1->SetMaterial(cylinderMaterial11);
	tube1 = Mesh::draw_cylinder2(2.0f, 5.0f, 0.0f, 10.0f, 0.0f);
	tube1->SetMaterial(cylinderMaterial21);
	//-30.f, 10.0f, 5.0f
	circle21 = Mesh::draw_cylinder(2.0f, 10.0f, -25.0f, 0.0f, 0.0f);
	circle21->SetMaterial(cylinderMaterial31);
	tube21 = Mesh::draw_cylinder2(2.0f, 10.0f, -25.0f, 0.0f, 0.0f);
	tube21->SetMaterial(cylinderMaterial41);
	//20.0f, 0.0f, 5.0f, 10.0f, 10.0f
	circle31 = Mesh::draw_cylinder(2.0f, 5.0f, 22.0f, 10.0f, 0.0f);
	circle31->SetMaterial(cylinderMaterial51);
	tube31 = Mesh::draw_cylinder2(2.0f, 5.0f, 22.0f, 10.0f, 0.0f);
	tube31->SetMaterial(cylinderMaterial61);

	cone1 = Mesh::cone(4.0f, 10.0f, 0.0f, 0.0f, 20.0f);
	cone1->SetMaterial(coneMaterial1);
}
void vertexNormal() {

	// Phong shading
	phong1 = new Material();
	phong1->SetTexture(new Texture());

	Shader* phongShader = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	phongShader->AddUniformVar("gWVP");
	phongShader->AddUniformVar("gWorld");
	phongShader->AddUniformVar("gLightDirection");

	phong1->SetShader(phongShader);

	cubeMaterial1 = new Material();
	cubeMaterial1->SetTexture(new Texture());

	Shader* cubeShader = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	cubeShader->AddUniformVar("gWVP");
	cubeShader->AddUniformVar("gWorld");
	cubeShader->AddUniformVar("gLightDirection");

	cubeMaterial1->SetShader(cubeShader);

	cubeMaterial21 = new Material();
	cubeMaterial21->SetTexture(new Texture());

	Shader* cubeShader2 = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	cubeShader2->AddUniformVar("gWVP");
	cubeShader2->AddUniformVar("gWorld");
	cubeShader2->AddUniformVar("gLightDirection");

	cubeMaterial21->SetShader(cubeShader2);

	cubeMaterial31 = new Material();
	cubeMaterial31->SetTexture(new Texture());

	Shader* cubeShader3 = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	cubeShader3->AddUniformVar("gWVP");
	cubeShader3->AddUniformVar("gWorld");
	cubeShader3->AddUniformVar("gLightDirection");

	cubeMaterial31->SetShader(cubeShader3);

	cubeMaterial41 = new Material();
	cubeMaterial41->SetTexture(new Texture());

	Shader* cubeShader4 = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	cubeShader4->AddUniformVar("gWVP");
	cubeShader4->AddUniformVar("gWorld");
	cubeShader4->AddUniformVar("gLightDirection");

	cubeMaterial41->SetShader(cubeShader4);

	cubeMaterial51 = new Material();
	cubeMaterial51->SetTexture(new Texture());

	Shader* cubeShader5 = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	cubeShader5->AddUniformVar("gWVP");
	cubeShader5->AddUniformVar("gWorld");
	cubeShader5->AddUniformVar("gLightDirection");

	cubeMaterial51->SetShader(cubeShader5);

	cubeMaterial61 = new Material();
	cubeMaterial61->SetTexture(new Texture());

	Shader* cubeShader6 = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	cubeShader6->AddUniformVar("gWVP");
	cubeShader6->AddUniformVar("gWorld");
	cubeShader6->AddUniformVar("gLightDirection");

	cubeMaterial61->SetShader(cubeShader6);

	cubeMaterial71 = new Material();
	cubeMaterial71->SetTexture(new Texture());

	Shader* cubeShader7 = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	cubeShader7->AddUniformVar("gWVP");
	cubeShader7->AddUniformVar("gWorld");
	cubeShader7->AddUniformVar("gLightDirection");

	cubeMaterial71->SetShader(cubeShader7);

	cubeMaterial81 = new Material();
	cubeMaterial81->SetTexture(new Texture());

	Shader* cubeShader8 = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	cubeShader8->AddUniformVar("gWVP");
	cubeShader8->AddUniformVar("gWorld");
	cubeShader8->AddUniformVar("gLightDirection");

	cubeMaterial81->SetShader(cubeShader8);

	cubeMaterial91 = new Material();
	cubeMaterial91->SetTexture(new Texture());

	Shader* cubeShader9 = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	cubeShader9->AddUniformVar("gWVP");
	cubeShader9->AddUniformVar("gWorld");
	cubeShader9->AddUniformVar("gLightDirection");

	cubeMaterial91->SetShader(cubeShader9);

	terrainMaterial1 = new Material();
	terrainMaterial1->SetTexture(new Texture());

	Shader* terrainShader = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	terrainShader->AddUniformVar("gWVP");
	terrainShader->AddUniformVar("gWorld");
	terrainShader->AddUniformVar("gLightDirection");

	terrainMaterial1->SetShader(terrainShader);
	//
	cylinderMaterial11 = new Material();
	cylinderMaterial11->SetTexture(new Texture());

	Shader* cylinderShader = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	cylinderShader->AddUniformVar("gWVP");
	cylinderShader->AddUniformVar("gWorld");
	cylinderShader->AddUniformVar("gLightDirection");

	cylinderMaterial11->SetShader(cylinderShader);
	//
	cylinderMaterial21 = new Material();
	cylinderMaterial21->SetTexture(new Texture());

	Shader* cylinderShader2 = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	cylinderShader2->AddUniformVar("gWVP");
	cylinderShader2->AddUniformVar("gWorld");
	cylinderShader2->AddUniformVar("gLightDirection");

	cylinderMaterial21->SetShader(cylinderShader2);
	//
	cylinderMaterial31 = new Material();
	cylinderMaterial31->SetTexture(new Texture());

	Shader* cylinderShader3 = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	cylinderShader3->AddUniformVar("gWVP");
	cylinderShader3->AddUniformVar("gWorld");
	cylinderShader3->AddUniformVar("gLightDirection");

	cylinderMaterial31->SetShader(cylinderShader3);
	//
	cylinderMaterial41 = new Material();
	cylinderMaterial41->SetTexture(new Texture());

	Shader* cylinderShader4 = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	cylinderShader4->AddUniformVar("gWVP");
	cylinderShader4->AddUniformVar("gWorld");
	cylinderShader4->AddUniformVar("gLightDirection");

	cylinderMaterial41->SetShader(cylinderShader4);
	//
	cylinderMaterial51 = new Material();
	cylinderMaterial51->SetTexture(new Texture());

	Shader* cylinderShader5 = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	cylinderShader5->AddUniformVar("gWVP");
	cylinderShader5->AddUniformVar("gWorld");
	cylinderShader5->AddUniformVar("gLightDirection");

	cylinderMaterial51->SetShader(cylinderShader5);
	//
	cylinderMaterial61 = new Material();
	cylinderMaterial61->SetTexture(new Texture());

	Shader* cylinderShader6 = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	cylinderShader6->AddUniformVar("gWVP");
	cylinderShader6->AddUniformVar("gWorld");
	cylinderShader6->AddUniformVar("gLightDirection");

	cylinderMaterial61->SetShader(cylinderShader6);

	coneMaterial1 = new Material();
	coneMaterial1->SetTexture(new Texture());

	Shader* coneShader = new Shader(std::string("shaders/vertex.vs"), std::string("shaders/vertex.fs"), std::string("shaders/vertex.gs"));

	coneShader->AddUniformVar("gWVP");
	coneShader->AddUniformVar("gWorld");
	coneShader->AddUniformVar("gLightDirection");

	coneMaterial1->SetShader(coneShader);

	InitGeometry2();

}
void faceNormal() {

	// Phong shading
	phong1 = new Material();
	phong1->SetTexture(new Texture());

	Shader* phongShader = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	phongShader->AddUniformVar("gWVP");
	phongShader->AddUniformVar("gWorld");
	phongShader->AddUniformVar("gLightDirection");

	phong1->SetShader(phongShader);

	cubeMaterial1 = new Material();
	cubeMaterial1->SetTexture(new Texture());

	Shader* cubeShader = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	cubeShader->AddUniformVar("gWVP");
	cubeShader->AddUniformVar("gWorld");
	cubeShader->AddUniformVar("gLightDirection");

	cubeMaterial1->SetShader(cubeShader);

	cubeMaterial21 = new Material();
	cubeMaterial21->SetTexture(new Texture());

	Shader* cubeShader2 = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	cubeShader2->AddUniformVar("gWVP");
	cubeShader2->AddUniformVar("gWorld");
	cubeShader2->AddUniformVar("gLightDirection");

	cubeMaterial21->SetShader(cubeShader2);

	cubeMaterial31 = new Material();
	cubeMaterial31->SetTexture(new Texture());

	Shader* cubeShader3 = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	cubeShader3->AddUniformVar("gWVP");
	cubeShader3->AddUniformVar("gWorld");
	cubeShader3->AddUniformVar("gLightDirection");

	cubeMaterial31->SetShader(cubeShader3);

	cubeMaterial41 = new Material();
	cubeMaterial41->SetTexture(new Texture());

	Shader* cubeShader4 = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	cubeShader4->AddUniformVar("gWVP");
	cubeShader4->AddUniformVar("gWorld");
	cubeShader4->AddUniformVar("gLightDirection");

	cubeMaterial41->SetShader(cubeShader4);

	cubeMaterial51 = new Material();
	cubeMaterial51->SetTexture(new Texture());

	Shader* cubeShader5 = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	cubeShader5->AddUniformVar("gWVP");
	cubeShader5->AddUniformVar("gWorld");
	cubeShader5->AddUniformVar("gLightDirection");

	cubeMaterial51->SetShader(cubeShader5);

	cubeMaterial61 = new Material();
	cubeMaterial61->SetTexture(new Texture());

	Shader* cubeShader6 = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	cubeShader6->AddUniformVar("gWVP");
	cubeShader6->AddUniformVar("gWorld");
	cubeShader6->AddUniformVar("gLightDirection");

	cubeMaterial61->SetShader(cubeShader6);

	cubeMaterial71 = new Material();
	cubeMaterial71->SetTexture(new Texture());

	Shader* cubeShader7 = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	cubeShader7->AddUniformVar("gWVP");
	cubeShader7->AddUniformVar("gWorld");
	cubeShader7->AddUniformVar("gLightDirection");

	cubeMaterial71->SetShader(cubeShader7);

	cubeMaterial81 = new Material();
	cubeMaterial81->SetTexture(new Texture());

	Shader* cubeShader8 = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	cubeShader8->AddUniformVar("gWVP");
	cubeShader8->AddUniformVar("gWorld");
	cubeShader8->AddUniformVar("gLightDirection");

	cubeMaterial81->SetShader(cubeShader8);

	cubeMaterial91 = new Material();
	cubeMaterial91->SetTexture(new Texture());

	Shader* cubeShader9 = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	cubeShader9->AddUniformVar("gWVP");
	cubeShader9->AddUniformVar("gWorld");
	cubeShader9->AddUniformVar("gLightDirection");

	cubeMaterial91->SetShader(cubeShader9);

	terrainMaterial1 = new Material();
	terrainMaterial1->SetTexture(new Texture());

	Shader* terrainShader = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	terrainShader->AddUniformVar("gWVP");
	terrainShader->AddUniformVar("gWorld");
	terrainShader->AddUniformVar("gLightDirection");

	terrainMaterial1->SetShader(terrainShader);
	//
	cylinderMaterial11 = new Material();
	cylinderMaterial11->SetTexture(new Texture());

	Shader* cylinderShader = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	cylinderShader->AddUniformVar("gWVP");
	cylinderShader->AddUniformVar("gWorld");
	cylinderShader->AddUniformVar("gLightDirection");

	cylinderMaterial11->SetShader(cylinderShader);
	//
	cylinderMaterial21 = new Material();
	cylinderMaterial21->SetTexture(new Texture());

	Shader* cylinderShader2 = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	cylinderShader2->AddUniformVar("gWVP");
	cylinderShader2->AddUniformVar("gWorld");
	cylinderShader2->AddUniformVar("gLightDirection");

	cylinderMaterial21->SetShader(cylinderShader2);
	//
	cylinderMaterial31 = new Material();
	cylinderMaterial31->SetTexture(new Texture());

	Shader* cylinderShader3 = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	cylinderShader3->AddUniformVar("gWVP");
	cylinderShader3->AddUniformVar("gWorld");
	cylinderShader3->AddUniformVar("gLightDirection");

	cylinderMaterial31->SetShader(cylinderShader3);
	//
	cylinderMaterial41 = new Material();
	cylinderMaterial41->SetTexture(new Texture());

	Shader* cylinderShader4 = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	cylinderShader4->AddUniformVar("gWVP");
	cylinderShader4->AddUniformVar("gWorld");
	cylinderShader4->AddUniformVar("gLightDirection");

	cylinderMaterial41->SetShader(cylinderShader4);
	//
	cylinderMaterial51 = new Material();
	cylinderMaterial51->SetTexture(new Texture());

	Shader* cylinderShader5 = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	cylinderShader5->AddUniformVar("gWVP");
	cylinderShader5->AddUniformVar("gWorld");
	cylinderShader5->AddUniformVar("gLightDirection");

	cylinderMaterial51->SetShader(cylinderShader5);
	
	cylinderMaterial61 = new Material();
	cylinderMaterial61->SetTexture(new Texture());

	Shader* cylinderShader6 = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	cylinderShader6->AddUniformVar("gWVP");
	cylinderShader6->AddUniformVar("gWorld");
	cylinderShader6->AddUniformVar("gLightDirection");

	cylinderMaterial61->SetShader(cylinderShader6);

	coneMaterial1 = new Material();
	coneMaterial1->SetTexture(new Texture());

	Shader* coneShader = new Shader(std::string("shaders/face.vs"), std::string("shaders/face.fs"), std::string("shaders/face.gs"));

	coneShader->AddUniformVar("gWVP");
	coneShader->AddUniformVar("gWorld");
	coneShader->AddUniformVar("gLightDirection");

	coneMaterial1->SetShader(coneShader);
	InitGeometry2();

}
void Render() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	static float test = 0;
	test += 0.001;

	//camera.RotateY(test);

	// Box
	mat4 world = glm::translate(mat4(), vec3(-2, 0, 0));
	
	shader.Use();
	glUniformMatrix4fv(shader.GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * world)[0][0]);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	glDrawElements(GL_TRIANGLES, 48, GL_UNSIGNED_INT, 0);
	
	glDisableVertexAttribArray(0);

	// Sphere
	static vec3 lightDirection = vec3(1, 1,1);
	lightDirection = vec3(glm::rotate(mat4(1.0f), 0.01f, vec3(0, 1, 0)) * glm::rotate(mat4(1.0f), 0.01f, vec3(0, 0, 1)) * vec4(lightDirection, 0));

	sphere->GetMaterial()->Use();
	glUniformMatrix4fv(phong->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &sphere->GetMatrix()[0][0]);
	glUniformMatrix4fv(phong->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * sphere->GetMatrix())[0][0]);
	if(menu==10) 
		glUniform3fv(phong->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);
	
	sphere->Render(0);

	cube->GetMaterial()->Use();
	glUniformMatrix4fv(cubeMaterial->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube->GetMatrix()[0][0]);
	glUniformMatrix4fv(cubeMaterial->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(cubeMaterial->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

	cube->Render(0);


	cube2->GetMaterial()->Use();
	glUniformMatrix4fv(cubeMaterial2->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube2->GetMatrix()[0][0]);
	glUniformMatrix4fv(cubeMaterial2->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(cubeMaterial2->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

	cube2->Render(0);


	cube3->GetMaterial()->Use();
	glUniformMatrix4fv(cubeMaterial3->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube3->GetMatrix()[0][0]);
	glUniformMatrix4fv(cubeMaterial3->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(cubeMaterial3->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

	cube3->Render(0);

	cube4->GetMaterial()->Use();
	glUniformMatrix4fv(cubeMaterial4->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube4->GetMatrix()[0][0]);
	glUniformMatrix4fv(cubeMaterial4->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube4->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(cubeMaterial4->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

	cube4->Render(0);


	cube5->GetMaterial()->Use();
	glUniformMatrix4fv(cubeMaterial5->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube5->GetMatrix()[0][0]);
	glUniformMatrix4fv(cubeMaterial5->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube5->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(cubeMaterial5->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

	cube5->Render(0);


	cube6->GetMaterial()->Use();
	glUniformMatrix4fv(cubeMaterial6->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube6->GetMatrix()[0][0]);
	glUniformMatrix4fv(cubeMaterial6->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube6->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(cubeMaterial6->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

	cube6->Render(0);

	cube7->GetMaterial()->Use();
	glUniformMatrix4fv(cubeMaterial7->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube7->GetMatrix()[0][0]);
	glUniformMatrix4fv(cubeMaterial7->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube7->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(cubeMaterial7->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

	cube7->Render(0);


	cube8->GetMaterial()->Use();
	glUniformMatrix4fv(cubeMaterial8->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube8->GetMatrix()[0][0]);
	glUniformMatrix4fv(cubeMaterial8->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube8->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(cubeMaterial8->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

	cube8->Render(0);


	cube9->GetMaterial()->Use();
	glUniformMatrix4fv(cubeMaterial9->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube9->GetMatrix()[0][0]);
	glUniformMatrix4fv(cubeMaterial9->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube9->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(cubeMaterial9->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

	cube9->Render(0);
	
	terrain->GetMaterial()->Use();
	glUniformMatrix4fv(terrainMaterial->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &terrain->GetMatrix()[0][0]);
	glUniformMatrix4fv(terrainMaterial->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * terrain->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(terrainMaterial->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[0]);

	terrain->Render(0);

	circle->GetMaterial()->Use();
	glUniformMatrix4fv(cylinderMaterial1->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &circle->GetMatrix()[0][0]);
	glUniformMatrix4fv(cylinderMaterial1->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * circle->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(cylinderMaterial1->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

	circle->Render(0);

	tube->GetMaterial()->Use();
	glUniformMatrix4fv(cylinderMaterial2->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &tube->GetMatrix()[0][0]);
	glUniformMatrix4fv(cylinderMaterial2->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * tube->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(cylinderMaterial2->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

	tube->Render(0);
	
	circle2->GetMaterial()->Use();
	glUniformMatrix4fv(cylinderMaterial3->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &circle2->GetMatrix()[0][0]);
	glUniformMatrix4fv(cylinderMaterial3->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * circle2->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(cylinderMaterial3->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

	circle2->Render(0);

	tube2->GetMaterial()->Use();
	glUniformMatrix4fv(cylinderMaterial4->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &tube2->GetMatrix()[0][0]);
	glUniformMatrix4fv(cylinderMaterial4->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * tube2->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(cylinderMaterial4->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[0]);

	tube2->Render(0);

	circle3->GetMaterial()->Use();
	glUniformMatrix4fv(cylinderMaterial5->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &circle3->GetMatrix()[0][0]);
	glUniformMatrix4fv(cylinderMaterial5->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * circle3->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(cylinderMaterial5->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

	circle3->Render(0);

	tube3->GetMaterial()->Use();
	glUniformMatrix4fv(cylinderMaterial6->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &tube3->GetMatrix()[0][0]);
	glUniformMatrix4fv(cylinderMaterial6->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * tube3->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(cylinderMaterial6->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

	tube3->Render(0);

	cone->GetMaterial()->Use();
	glUniformMatrix4fv(coneMaterial->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cone->GetMatrix()[0][0]);
	glUniformMatrix4fv(coneMaterial->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cone->GetMatrix())[0][0]);
	if (menu == 10)
		glUniform3fv(coneMaterial->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[0]);

	cone->Render(0);

	if (menu == 4 || menu == 6) {

			// Sphere
			static vec3 lightDirection = vec3(1, 1, 10);
			lightDirection = vec3(glm::rotate(mat4(1.0f), 0.01f, vec3(0, 1, 0)) * glm::rotate(mat4(1.0f), 0.01f, vec3(0, 0, 1)) * vec4(lightDirection, 0));

			sphere1->GetMaterial()->Use();
			glUniformMatrix4fv(phong1->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &sphere1->GetMatrix()[0][0]);
			glUniformMatrix4fv(phong1->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * sphere1->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(phong1->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

			sphere1->Render(0);

			cube1->GetMaterial()->Use();
			glUniformMatrix4fv(cubeMaterial1->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube1->GetMatrix()[0][0]);
			glUniformMatrix4fv(cubeMaterial1->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube1->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(cubeMaterial1->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

			cube1->Render(0);


			cube21->GetMaterial()->Use();
			glUniformMatrix4fv(cubeMaterial21->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube21->GetMatrix()[0][0]);
			glUniformMatrix4fv(cubeMaterial21->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube21->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(cubeMaterial21->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

			cube21->Render(0);


			cube31->GetMaterial()->Use();
			glUniformMatrix4fv(cubeMaterial31->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube31->GetMatrix()[0][0]);
			glUniformMatrix4fv(cubeMaterial31->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube31->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(cubeMaterial31->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

			cube31->Render(0);

			cube41->GetMaterial()->Use();
			glUniformMatrix4fv(cubeMaterial41->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube41->GetMatrix()[0][0]);
			glUniformMatrix4fv(cubeMaterial41->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube41->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(cubeMaterial41->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

			cube41->Render(0);


			cube51->GetMaterial()->Use();
			glUniformMatrix4fv(cubeMaterial51->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube51->GetMatrix()[0][0]);
			glUniformMatrix4fv(cubeMaterial51->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube51->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(cubeMaterial51->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

			cube51->Render(0);


			cube61->GetMaterial()->Use();
			glUniformMatrix4fv(cubeMaterial61->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube61->GetMatrix()[0][0]);
			glUniformMatrix4fv(cubeMaterial61->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube61->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(cubeMaterial61->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

			cube61->Render(0);

			cube71->GetMaterial()->Use();
			glUniformMatrix4fv(cubeMaterial71->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube71->GetMatrix()[0][0]);
			glUniformMatrix4fv(cubeMaterial71->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube71->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(cubeMaterial71->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

			cube71->Render(0);


			cube81->GetMaterial()->Use();
			glUniformMatrix4fv(cubeMaterial81->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube81->GetMatrix()[0][0]);
			glUniformMatrix4fv(cubeMaterial81->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube81->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(cubeMaterial81->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

			cube81->Render(0);


			cube91->GetMaterial()->Use();
			glUniformMatrix4fv(cubeMaterial91->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cube91->GetMatrix()[0][0]);
			glUniformMatrix4fv(cubeMaterial91->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cube91->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(cubeMaterial91->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

			cube91->Render(0);

			terrain1->GetMaterial()->Use();
			glUniformMatrix4fv(terrainMaterial1->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &terrain1->GetMatrix()[0][0]);
			glUniformMatrix4fv(terrainMaterial1->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * terrain1->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(terrainMaterial1->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[0]);

			terrain1->Render(0);

			circle1->GetMaterial()->Use();
			glUniformMatrix4fv(cylinderMaterial11->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &circle1->GetMatrix()[0][0]);
			glUniformMatrix4fv(cylinderMaterial11->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * circle1->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(cylinderMaterial11->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

			circle1->Render(0);

			tube1->GetMaterial()->Use();
			glUniformMatrix4fv(cylinderMaterial21->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &tube1->GetMatrix()[0][0]);
			glUniformMatrix4fv(cylinderMaterial21->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * tube1->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(cylinderMaterial21->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

			tube1->Render(0);

			circle21->GetMaterial()->Use();
			glUniformMatrix4fv(cylinderMaterial31->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &circle21->GetMatrix()[0][0]);
			glUniformMatrix4fv(cylinderMaterial31->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * circle21->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(cylinderMaterial31->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

			circle21->Render(0);

			tube21->GetMaterial()->Use();
			glUniformMatrix4fv(cylinderMaterial41->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &tube21->GetMatrix()[0][0]);
			glUniformMatrix4fv(cylinderMaterial41->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * tube21->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(cylinderMaterial41->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[0]);

			tube21->Render(0);

			circle31->GetMaterial()->Use();
			glUniformMatrix4fv(cylinderMaterial51->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &circle31->GetMatrix()[0][0]);
			glUniformMatrix4fv(cylinderMaterial51->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * circle31->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(cylinderMaterial51->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

			circle31->Render(0);

			tube31->GetMaterial()->Use();
			glUniformMatrix4fv(cylinderMaterial61->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &tube31->GetMatrix()[0][0]);
			glUniformMatrix4fv(cylinderMaterial61->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * tube31->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(cylinderMaterial61->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[1]);

			tube31->Render(0);

			cone1->GetMaterial()->Use();
			glUniformMatrix4fv(coneMaterial1->GetShader()->GetUniformVar("gWorld"), 1, GL_FALSE, &cone1->GetMatrix()[0][0]);
			glUniformMatrix4fv(coneMaterial1->GetShader()->GetUniformVar("gWVP"), 1, GL_FALSE, &(camera.GetProj() * camera.GetView() * cone1->GetMatrix())[0][0]);
			if (menu == 10)
				glUniform3fv(coneMaterial1->GetShader()->GetUniformVar("gLightDirection"), 1, &lightDirection[0]);

			cone1->Render(0);
	}
	
	glutSwapBuffers();
}

void InitGeometry() {
		if (menu == 4) {
			faceNormal();

		}
		else if (menu == 6) {
			vertexNormal();
		}

	sphere = Mesh::GenerateSphere(10, 16, 32);
	sphere->SetMaterial(phong);
	
	cube = Mesh::c1(-5.0f, 0.0f, 5.0f, 10.0f, 10.0f);
	cube->SetMaterial(cubeMaterial);
	cube2 = Mesh::c2(-5.0f, 0.0f, 5.0f, 10.0f, 10.0f);
	cube2->SetMaterial(cubeMaterial2);
	cube3 = Mesh::c3(-5.0f, 0.0f, 5.0f, 10.0f, 10.0f);
	cube3->SetMaterial(cubeMaterial3);

	cube4 = Mesh::c1(-30.f, 10.0f, 5.0f, 10.0f, 20.0f);
	cube4->SetMaterial(cubeMaterial4);
	cube5 = Mesh::c2(-30.f, 10.0f, 5.0f, 10.0f, 20.0f);
	cube5->SetMaterial(cubeMaterial5);
	cube6 = Mesh::c3(-30.f, 10.0f, 5.0f, 10.0f, 20.0f);
	cube6->SetMaterial(cubeMaterial6);

	cube7 = Mesh::c1(20.0f, 0.0f, 5.0f, 10.0f, 10.0f);
	cube7->SetMaterial(cubeMaterial7);
	cube8 = Mesh::c2(20.0f, 0.0f, 5.0f, 10.0f, 10.0f);
	cube8->SetMaterial(cubeMaterial8);
	cube9 = Mesh::c3(20.0f, 0.0f, 5.0f, 10.0f, 10.0f);
	cube9->SetMaterial(cubeMaterial9);


	/*
	cube = Mesh::GenerateCube(-5.0f, 0.0f, 5.0f, 10.0f, 10.0f);
	cube->SetMaterial(cubeMaterial);
	
	cube2 = Mesh::GenerateCube(-30.f, 0.0f, 5.0f, 10.0f, 10.0f);
	cube2->SetMaterial(cubeMaterial2);

	cube3 = Mesh::GenerateCube(20.0f, 0.0f, 5.0f, 10.0f, 10.0f);
	cube3->SetMaterial(cubeMaterial3);*/

	terrain = Mesh::GenerateGround(100, 100);
	terrain->SetMaterial(terrainMaterial);

	/*terrain = new Terrain("textures/Korea2.jpg", (float)1 / (float)32);
	terrain->SetMaterial(terrainMaterial);*/

	circle = Mesh::draw_cylinder(2.0f, 5.0f, 0.0f, 10.0f, 0.0f);
	circle->SetMaterial(cylinderMaterial1);
	tube = Mesh::draw_cylinder2(2.0f, 5.0f, 0.0f, 10.0f, 0.0f);
	tube->SetMaterial(cylinderMaterial2);
	//-30.f, 10.0f, 5.0f
	circle2 = Mesh::draw_cylinder(2.0f, 10.0f, -25.0f, 0.0f, 0.0f);
	circle2->SetMaterial(cylinderMaterial3);
	tube2 = Mesh::draw_cylinder2(2.0f, 10.0f, -25.0f, 0.0f, 0.0f);
	tube2->SetMaterial(cylinderMaterial4);
	//20.0f, 0.0f, 5.0f, 10.0f, 10.0f
	circle3 = Mesh::draw_cylinder(2.0f, 5.0f, 22.0f, 10.0f, 0.0f);
	circle3->SetMaterial(cylinderMaterial5);
	tube3 = Mesh::draw_cylinder2(2.0f, 5.0f, 22.0f, 10.0f, 0.0f);
	tube3->SetMaterial(cylinderMaterial6);

	cone = Mesh::cone(4.0f, 10.0f, 0.0f, 0.0f, 20.0f);
	cone->SetMaterial(coneMaterial);

}
void InitFlat() {

	shader.LoadShader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));
	shader.AddUniformVar("gWVP");

	// Phong shading
	phong = new Material();
	phong->SetTexture(new Texture());

	Shader* phongShader = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	phongShader->AddUniformVar("gWVP");
	phongShader->AddUniformVar("gWorld");
	phongShader->AddUniformVar("gLightDirection");

	phong->SetShader(phongShader);

	cubeMaterial = new Material();
	cubeMaterial->SetTexture(new Texture());

	Shader* cubeShader = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	cubeShader->AddUniformVar("gWVP");
	cubeShader->AddUniformVar("gWorld");
	cubeShader->AddUniformVar("gLightDirection");

	cubeMaterial->SetShader(cubeShader);

	cubeMaterial2 = new Material();
	cubeMaterial2->SetTexture(new Texture());

	Shader* cubeShader2 = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	cubeShader2->AddUniformVar("gWVP");
	cubeShader2->AddUniformVar("gWorld");
	cubeShader2->AddUniformVar("gLightDirection");

	cubeMaterial2->SetShader(cubeShader2);

	cubeMaterial3 = new Material();
	cubeMaterial3->SetTexture(new Texture());

	Shader* cubeShader3 = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	cubeShader3->AddUniformVar("gWVP");
	cubeShader3->AddUniformVar("gWorld");
	cubeShader3->AddUniformVar("gLightDirection");

	cubeMaterial3->SetShader(cubeShader3);

	cubeMaterial4 = new Material();
	cubeMaterial4->SetTexture(new Texture());

	Shader* cubeShader4 = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	cubeShader4->AddUniformVar("gWVP");
	cubeShader4->AddUniformVar("gWorld");
	cubeShader4->AddUniformVar("gLightDirection");

	cubeMaterial4->SetShader(cubeShader4);

	cubeMaterial5 = new Material();
	cubeMaterial5->SetTexture(new Texture());

	Shader* cubeShader5 = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	cubeShader5->AddUniformVar("gWVP");
	cubeShader5->AddUniformVar("gWorld");
	cubeShader5->AddUniformVar("gLightDirection");

	cubeMaterial5->SetShader(cubeShader5);

	cubeMaterial6 = new Material();
	cubeMaterial6->SetTexture(new Texture());

	Shader* cubeShader6 = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	cubeShader6->AddUniformVar("gWVP");
	cubeShader6->AddUniformVar("gWorld");
	cubeShader6->AddUniformVar("gLightDirection");

	cubeMaterial6->SetShader(cubeShader6);

	cubeMaterial7 = new Material();
	cubeMaterial7->SetTexture(new Texture());

	Shader* cubeShader7 = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	cubeShader7->AddUniformVar("gWVP");
	cubeShader7->AddUniformVar("gWorld");
	cubeShader7->AddUniformVar("gLightDirection");

	cubeMaterial7->SetShader(cubeShader7);

	cubeMaterial8 = new Material();
	cubeMaterial8->SetTexture(new Texture());

	Shader* cubeShader8 = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	cubeShader8->AddUniformVar("gWVP");
	cubeShader8->AddUniformVar("gWorld");
	cubeShader8->AddUniformVar("gLightDirection");

	cubeMaterial8->SetShader(cubeShader8);

	cubeMaterial9 = new Material();
	cubeMaterial9->SetTexture(new Texture());

	Shader* cubeShader9 = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	cubeShader9->AddUniformVar("gWVP");
	cubeShader9->AddUniformVar("gWorld");
	cubeShader9->AddUniformVar("gLightDirection");

	cubeMaterial9->SetShader(cubeShader9);

	terrainMaterial = new Material();
	terrainMaterial->SetTexture(new Texture());

	Shader* terrainShader = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	terrainShader->AddUniformVar("gWVP");
	terrainShader->AddUniformVar("gWorld");
	terrainShader->AddUniformVar("gLightDirection");

	terrainMaterial->SetShader(terrainShader);
	//
	cylinderMaterial1 = new Material();
	cylinderMaterial1->SetTexture(new Texture());

	Shader* cylinderShader = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	cylinderShader->AddUniformVar("gWVP");
	cylinderShader->AddUniformVar("gWorld");
	cylinderShader->AddUniformVar("gLightDirection");

	cylinderMaterial1->SetShader(cylinderShader);
	//
	cylinderMaterial2 = new Material();
	cylinderMaterial2->SetTexture(new Texture());

	Shader* cylinderShader2 = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	cylinderShader2->AddUniformVar("gWVP");
	cylinderShader2->AddUniformVar("gWorld");
	cylinderShader2->AddUniformVar("gLightDirection");

	cylinderMaterial2->SetShader(cylinderShader2);
	//
	cylinderMaterial3 = new Material();
	cylinderMaterial3->SetTexture(new Texture());

	Shader* cylinderShader3 = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	cylinderShader3->AddUniformVar("gWVP");
	cylinderShader3->AddUniformVar("gWorld");
	cylinderShader3->AddUniformVar("gLightDirection");

	cylinderMaterial3->SetShader(cylinderShader3);
	//
	cylinderMaterial4 = new Material();
	cylinderMaterial4->SetTexture(new Texture());

	Shader* cylinderShader4 = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	cylinderShader4->AddUniformVar("gWVP");
	cylinderShader4->AddUniformVar("gWorld");
	cylinderShader4->AddUniformVar("gLightDirection");

	cylinderMaterial4->SetShader(cylinderShader4);
	//
	cylinderMaterial5 = new Material();
	cylinderMaterial5->SetTexture(new Texture());

	Shader* cylinderShader5 = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	cylinderShader5->AddUniformVar("gWVP");
	cylinderShader5->AddUniformVar("gWorld");
	cylinderShader5->AddUniformVar("gLightDirection");

	cylinderMaterial5->SetShader(cylinderShader5);
	//
	cylinderMaterial6 = new Material();
	cylinderMaterial6->SetTexture(new Texture());

	Shader* cylinderShader6 = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	cylinderShader6->AddUniformVar("gWVP");
	cylinderShader6->AddUniformVar("gWorld");
	cylinderShader6->AddUniformVar("gLightDirection");

	cylinderMaterial6->SetShader(cylinderShader6);

	coneMaterial = new Material();
	coneMaterial->SetTexture(new Texture());

	Shader* coneShader = new Shader(std::string("shaders/flat.vs"), std::string("shaders/flat.fs"));

	coneShader->AddUniformVar("gWVP");
	coneShader->AddUniformVar("gWorld");
	coneShader->AddUniformVar("gLightDirection");

	coneMaterial->SetShader(coneShader);

}
void InitSmooth() {

	shader.LoadShader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));
	shader.AddUniformVar("gWVP");

	// Phong shading
	phong = new Material();
	phong->SetTexture(new Texture());

	Shader* phongShader = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	phongShader->AddUniformVar("gWVP");
	phongShader->AddUniformVar("gWorld");
	phongShader->AddUniformVar("gLightDirection");

	phong->SetShader(phongShader);

	cubeMaterial = new Material();
	cubeMaterial->SetTexture(new Texture());

	Shader* cubeShader = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	cubeShader->AddUniformVar("gWVP");
	cubeShader->AddUniformVar("gWorld");
	cubeShader->AddUniformVar("gLightDirection");

	cubeMaterial->SetShader(cubeShader);

	cubeMaterial2 = new Material();
	cubeMaterial2->SetTexture(new Texture());

	Shader* cubeShader2 = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	cubeShader2->AddUniformVar("gWVP");
	cubeShader2->AddUniformVar("gWorld");
	cubeShader2->AddUniformVar("gLightDirection");

	cubeMaterial2->SetShader(cubeShader2);

	cubeMaterial3 = new Material();
	cubeMaterial3->SetTexture(new Texture());

	Shader* cubeShader3 = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	cubeShader3->AddUniformVar("gWVP");
	cubeShader3->AddUniformVar("gWorld");
	cubeShader3->AddUniformVar("gLightDirection");

	cubeMaterial3->SetShader(cubeShader3);

	cubeMaterial4 = new Material();
	cubeMaterial4->SetTexture(new Texture());

	Shader* cubeShader4 = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	cubeShader4->AddUniformVar("gWVP");
	cubeShader4->AddUniformVar("gWorld");
	cubeShader4->AddUniformVar("gLightDirection");

	cubeMaterial4->SetShader(cubeShader4);

	cubeMaterial5 = new Material();
	cubeMaterial5->SetTexture(new Texture());

	Shader* cubeShader5 = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	cubeShader5->AddUniformVar("gWVP");
	cubeShader5->AddUniformVar("gWorld");
	cubeShader5->AddUniformVar("gLightDirection");

	cubeMaterial5->SetShader(cubeShader5);

	cubeMaterial6 = new Material();
	cubeMaterial6->SetTexture(new Texture());

	Shader* cubeShader6 = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	cubeShader6->AddUniformVar("gWVP");
	cubeShader6->AddUniformVar("gWorld");
	cubeShader6->AddUniformVar("gLightDirection");

	cubeMaterial6->SetShader(cubeShader6);

	cubeMaterial7 = new Material();
	cubeMaterial7->SetTexture(new Texture());

	Shader* cubeShader7 = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	cubeShader7->AddUniformVar("gWVP");
	cubeShader7->AddUniformVar("gWorld");
	cubeShader7->AddUniformVar("gLightDirection");

	cubeMaterial7->SetShader(cubeShader7);

	cubeMaterial8 = new Material();
	cubeMaterial8->SetTexture(new Texture());

	Shader* cubeShader8 = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	cubeShader8->AddUniformVar("gWVP");
	cubeShader8->AddUniformVar("gWorld");
	cubeShader8->AddUniformVar("gLightDirection");

	cubeMaterial8->SetShader(cubeShader8);

	cubeMaterial9 = new Material();
	cubeMaterial9->SetTexture(new Texture());

	Shader* cubeShader9 = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	cubeShader9->AddUniformVar("gWVP");
	cubeShader9->AddUniformVar("gWorld");
	cubeShader9->AddUniformVar("gLightDirection");

	cubeMaterial9->SetShader(cubeShader9);

	terrainMaterial = new Material();
	terrainMaterial->SetTexture(new Texture());

	Shader* terrainShader = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	terrainShader->AddUniformVar("gWVP");
	terrainShader->AddUniformVar("gWorld");
	terrainShader->AddUniformVar("gLightDirection");

	terrainMaterial->SetShader(terrainShader);
	//
	cylinderMaterial1 = new Material();
	cylinderMaterial1->SetTexture(new Texture());

	Shader* cylinderShader = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	cylinderShader->AddUniformVar("gWVP");
	cylinderShader->AddUniformVar("gWorld");
	cylinderShader->AddUniformVar("gLightDirection");

	cylinderMaterial1->SetShader(cylinderShader);
	//
	cylinderMaterial2 = new Material();
	cylinderMaterial2->SetTexture(new Texture());

	Shader* cylinderShader2 = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	cylinderShader2->AddUniformVar("gWVP");
	cylinderShader2->AddUniformVar("gWorld");
	cylinderShader2->AddUniformVar("gLightDirection");

	cylinderMaterial2->SetShader(cylinderShader2);
	//
	cylinderMaterial3 = new Material();
	cylinderMaterial3->SetTexture(new Texture());

	Shader* cylinderShader3 = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	cylinderShader3->AddUniformVar("gWVP");
	cylinderShader3->AddUniformVar("gWorld");
	cylinderShader3->AddUniformVar("gLightDirection");

	cylinderMaterial3->SetShader(cylinderShader3);
	//
	cylinderMaterial4 = new Material();
	cylinderMaterial4->SetTexture(new Texture());

	Shader* cylinderShader4 = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	cylinderShader4->AddUniformVar("gWVP");
	cylinderShader4->AddUniformVar("gWorld");
	cylinderShader4->AddUniformVar("gLightDirection");

	cylinderMaterial4->SetShader(cylinderShader4);
	//
	cylinderMaterial5 = new Material();
	cylinderMaterial5->SetTexture(new Texture());

	Shader* cylinderShader5 = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	cylinderShader5->AddUniformVar("gWVP");
	cylinderShader5->AddUniformVar("gWorld");
	cylinderShader5->AddUniformVar("gLightDirection");

	cylinderMaterial5->SetShader(cylinderShader5);
	//
	cylinderMaterial6 = new Material();
	cylinderMaterial6->SetTexture(new Texture());

	Shader* cylinderShader6 = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	cylinderShader6->AddUniformVar("gWVP");
	cylinderShader6->AddUniformVar("gWorld");
	cylinderShader6->AddUniformVar("gLightDirection");

	cylinderMaterial6->SetShader(cylinderShader6);

	coneMaterial = new Material();
	coneMaterial->SetTexture(new Texture());

	Shader* coneShader = new Shader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));

	coneShader->AddUniformVar("gWVP");
	coneShader->AddUniformVar("gWorld");
	coneShader->AddUniformVar("gLightDirection");

	coneMaterial->SetShader(coneShader);


}
void InitShader() {

	shader.LoadShader(std::string("shaders/shader.vs"), std::string("shaders/shader.fs"));
	shader.AddUniformVar("gWVP");

	// Phong shading
	phong = new Material();
	phong->SetTexture(new Texture("textures/sphere.jpg"));

	Shader* phongShader = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));
	
	phongShader->AddUniformVar("gWVP");
	phongShader->AddUniformVar("gWorld");
	if(menu==10)
		phongShader->AddUniformVar("gLightDirection");

	phong->SetShader(phongShader);

	cubeMaterial = new Material();
	cubeMaterial->SetTexture(new Texture("textures/cube.png"));
	
	Shader* cubeShader = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	cubeShader->AddUniformVar("gWVP");
	cubeShader->AddUniformVar("gWorld");
	if (menu == 10)
		cubeShader->AddUniformVar("gLightDirection");

	cubeMaterial->SetShader(cubeShader);

	cubeMaterial2 = new Material();
	cubeMaterial2->SetTexture(new Texture("textures/cube.png"));

	Shader* cubeShader2 = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	cubeShader2->AddUniformVar("gWVP");
	cubeShader2->AddUniformVar("gWorld");
	if (menu == 10)
		cubeShader2->AddUniformVar("gLightDirection");

	cubeMaterial2->SetShader(cubeShader2);

	cubeMaterial3 = new Material();
	cubeMaterial3->SetTexture(new Texture("textures/cube.png"));

	Shader* cubeShader3 = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	cubeShader3->AddUniformVar("gWVP");
	cubeShader3->AddUniformVar("gWorld");
	if (menu == 10)
		cubeShader3->AddUniformVar("gLightDirection");

	cubeMaterial3->SetShader(cubeShader3);

	cubeMaterial4 = new Material();
	cubeMaterial4->SetTexture(new Texture("textures/cube.png"));

	Shader* cubeShader4 = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	cubeShader4->AddUniformVar("gWVP");
	cubeShader4->AddUniformVar("gWorld");
	if (menu == 10)
		cubeShader4->AddUniformVar("gLightDirection");

	cubeMaterial4->SetShader(cubeShader4);

	cubeMaterial5 = new Material();
	cubeMaterial5->SetTexture(new Texture("textures/cube.png"));

	Shader* cubeShader5 = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	cubeShader5->AddUniformVar("gWVP");
	cubeShader5->AddUniformVar("gWorld");
	if (menu == 10)
		cubeShader5->AddUniformVar("gLightDirection");

	cubeMaterial5->SetShader(cubeShader5);

	cubeMaterial6 = new Material();
	cubeMaterial6->SetTexture(new Texture("textures/cube.png"));

	Shader* cubeShader6 = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	cubeShader6->AddUniformVar("gWVP");
	cubeShader6->AddUniformVar("gWorld");
	if (menu == 10)
		cubeShader6->AddUniformVar("gLightDirection");

	cubeMaterial6->SetShader(cubeShader6);

	cubeMaterial7 = new Material();
	cubeMaterial7->SetTexture(new Texture("textures/cube.png"));

	Shader* cubeShader7 = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	cubeShader7->AddUniformVar("gWVP");
	cubeShader7->AddUniformVar("gWorld");
	if (menu == 10)
		cubeShader7->AddUniformVar("gLightDirection");

	cubeMaterial7->SetShader(cubeShader7);

	cubeMaterial8 = new Material();
	cubeMaterial8->SetTexture(new Texture("textures/cube.png"));

	Shader* cubeShader8 = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	cubeShader8->AddUniformVar("gWVP");
	cubeShader8->AddUniformVar("gWorld");
	if (menu == 10)
		cubeShader8->AddUniformVar("gLightDirection");

	cubeMaterial8->SetShader(cubeShader8);

	cubeMaterial9 = new Material();
	cubeMaterial9->SetTexture(new Texture("textures/cube.png"));

	Shader* cubeShader9 = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	cubeShader9->AddUniformVar("gWVP");
	cubeShader9->AddUniformVar("gWorld");
	if (menu == 10)
		cubeShader9->AddUniformVar("gLightDirection");

	cubeMaterial9->SetShader(cubeShader9);

	terrainMaterial = new Material();
	terrainMaterial->SetTexture(new Texture("textures/Korea2.jpg"));

	Shader* terrainShader = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	terrainShader->AddUniformVar("gWVP");
	terrainShader->AddUniformVar("gWorld");
	if (menu == 10)
		terrainShader->AddUniformVar("gLightDirection");

	terrainMaterial->SetShader(terrainShader);
//
	cylinderMaterial1 = new Material();
	cylinderMaterial1->SetTexture(new Texture("textures/circle.png"));

	Shader* cylinderShader = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	cylinderShader->AddUniformVar("gWVP");
	cylinderShader->AddUniformVar("gWorld");
	if (menu == 10)
		cylinderShader->AddUniformVar("gLightDirection");

	cylinderMaterial1->SetShader(cylinderShader);
//
	cylinderMaterial2 = new Material();
	cylinderMaterial2->SetTexture(new Texture("textures/circle.png"));

	Shader* cylinderShader2 = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	cylinderShader2->AddUniformVar("gWVP");
	cylinderShader2->AddUniformVar("gWorld");
	if (menu == 10)	
		cylinderShader2->AddUniformVar("gLightDirection");

	cylinderMaterial2->SetShader(cylinderShader2);
//
	cylinderMaterial3 = new Material();
	cylinderMaterial3->SetTexture(new Texture("textures/circle.png"));

	Shader* cylinderShader3 = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	cylinderShader3->AddUniformVar("gWVP");
	cylinderShader3->AddUniformVar("gWorld");
	if (menu == 10) 
		cylinderShader3->AddUniformVar("gLightDirection");

	cylinderMaterial3->SetShader(cylinderShader3);
//
	cylinderMaterial4 = new Material();
	cylinderMaterial4->SetTexture(new Texture("textures/circle.png"));

	Shader* cylinderShader4 = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	cylinderShader4->AddUniformVar("gWVP");
	cylinderShader4->AddUniformVar("gWorld");
	if (menu == 10)	
		cylinderShader4->AddUniformVar("gLightDirection");

	cylinderMaterial4->SetShader(cylinderShader4);
//
	cylinderMaterial5 = new Material();
	cylinderMaterial5->SetTexture(new Texture("textures/circle.png"));

	Shader* cylinderShader5 = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	cylinderShader5->AddUniformVar("gWVP");
	cylinderShader5->AddUniformVar("gWorld");
	if (menu == 10) 	
		cylinderShader5->AddUniformVar("gLightDirection");

	cylinderMaterial5->SetShader(cylinderShader5);
//
	cylinderMaterial6 = new Material();
	cylinderMaterial6->SetTexture(new Texture("textures/circle.png"));

	Shader* cylinderShader6 = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	cylinderShader6->AddUniformVar("gWVP");
	cylinderShader6->AddUniformVar("gWorld");
	if (menu == 10)	
		cylinderShader6->AddUniformVar("gLightDirection");

	cylinderMaterial6->SetShader(cylinderShader6);

	coneMaterial = new Material();
	coneMaterial->SetTexture(new Texture("textures/circle.png"));

	Shader* coneShader = new Shader(std::string("shaders/phong.vs"), std::string("shaders/phong.fs"));

	coneShader->AddUniformVar("gWVP");
	coneShader->AddUniformVar("gWorld");
	if (menu == 10)	
		coneShader->AddUniformVar("gLightDirection");

	coneMaterial->SetShader(coneShader);
}
void Resize(int width, int height) {
	float ratio;
	if (width > height)
		ratio = (GLfloat)width / (GLfloat)height;
	else
		ratio = (GLfloat)height / (GLfloat)width;

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	camera.SetProj(glm::perspective(glm::radians(60.f), ratio, 1.f, 1000.f));
}
void Init() {
	glEnable(GL_DEPTH_TEST);

	camera.SetView(vec3(0, 25, 50), vec3(0, 0, 0), vec3(0, 1, 0));
}
void Keyboard(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP:
		camera.GoForward(1.0f);
		break;
	case GLUT_KEY_DOWN:
		camera.GoForward(-1.0f);
		break;
	case GLUT_KEY_LEFT:
		camera.TurnAround(-0.01f);
		break;
	case GLUT_KEY_RIGHT:
		camera.TurnAround(0.01f);
		break;
	default:
		return;
	}
}
void DoMenu(int value) 
{
	switch (value) {
	case 1:
		menu = 1;
		InitFlat();
		InitGeometry();
		glutPostRedisplay();
		break;
	case 2:
		menu = 2;
		InitSmooth();
		InitGeometry();
		glutPostRedisplay();
		break;
	case 3:
		menu = 3;
		InitShader();
		InitGeometry();
		glutPostRedisplay();
		break;
	case 4:
		menu = 4;
		InitGeometry();
		glutPostRedisplay();
		break;
	case 5:
		menu = 5;
		InitGeometry();
		glutPostRedisplay();
		break;
	case 6:
		menu = 6;
		InitGeometry();
		glutPostRedisplay();
		break;
	case 7:
		//
		break;
	case 8:
		menu = 8;
		InitGeometry();
		glutPostRedisplay();
		break;
	case 9:
		menu = 9;
		InitShader();
		InitGeometry();
		glutPostRedisplay();
		break;
	case 10:
		menu = 10;
		InitShader();
		InitGeometry();
		glutPostRedisplay();
		break;
	case 11:
		menu = 11;
		InitFlat();
		InitGeometry();
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL");

	// glutCreateWindow 함수 뒤에 호출
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		std::cout << "Error: " << glewGetErrorString(res) << std::endl;
		return 1;
	}
	// 서브 메뉴 미리 준비
	GLint shading = glutCreateMenu(DoMenu);
	glutAddMenuEntry("FLAT", 1);
	glutAddMenuEntry("SMOOTH", 2);
	glutAddMenuEntry("NONE", 3);

	GLint face = glutCreateMenu(DoMenu);
	glutAddMenuEntry("Normal Visualization - On", 4);
	glutAddMenuEntry("Normal Visualization - Off", 5);

	GLint visual = glutCreateMenu(DoMenu);
	glutAddMenuEntry("Per Vertex Normals", 6);
	glutAddMenuEntry("Per Vertex Normals Weighted", 7);

	GLint vertex = glutCreateMenu(DoMenu);
	glutAddSubMenu("Normal Visualizaion - On", visual);
	glutAddMenuEntry("Normal Visualization - Off", 8);

	GLint on = glutCreateMenu(DoMenu);
	glutAddMenuEntry("Replace", 9);
	glutAddMenuEntry("Modulate", 10);

	GLint texturing = glutCreateMenu(DoMenu);
	glutAddSubMenu("On", on);
	glutAddMenuEntry("Off", 11);

	// 메인 메뉴 생성
	glutCreateMenu(DoMenu);

	// 서브 메뉴를 메인 메뉴에 붙인다.
	glutAddSubMenu("Shading", shading);
	glutAddSubMenu("Per Face Normal Vectors", face);
	glutAddSubMenu("Per Vertex Normal Vectors", vertex);
	glutAddSubMenu("Texturing", texturing);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	Init();
	//vectorNormal();
	//faceNormal();
	InitShader();
	//InitFlat();
	//InitSmooth();
	//InitGeometry2();
	InitGeometry();

	glutSpecialFunc(Keyboard);
	glutDisplayFunc(Render);
	glutIdleFunc(Render);
	//glutIdleFunc(Render2);
	//glutDisplayFunc(Render2);
	glutReshapeFunc(Resize);

	glClearColor(255.0f, 255.0f, 255.0f, 0.0f);

	glutMainLoop();

	return 0;
}