#include "geometry.h"
#include <vector>

Geometry::Geometry()
{
}

Geometry::~Geometry()
{
	glDeleteVertexArrays(1, &mVao);
	glDeleteBuffers(1, &mPosVbo);
	glDeleteBuffers(1, &mUvVbo);
	glDeleteBuffers(1, &mEbo);
	glDeleteBuffers(1, &mNormalVbo);
}

Geometry* Geometry::creatBox(float size)
{
	Geometry* geometry = new Geometry();
	geometry->mIndicesCount = 36;
	float halfsize = size / 2.0f;
	float positions[] = {
		 -halfsize, -halfsize,  halfsize,  // Bottom left
	 halfsize, -halfsize,  halfsize,  // Bottom right
	 halfsize,  halfsize,  halfsize,  // Top right
	-halfsize,  halfsize,  halfsize,  // Top left

	// Back face
	-halfsize, -halfsize, -halfsize,  // Bottom left
	 halfsize, -halfsize, -halfsize,  // Bottom right
	 halfsize,  halfsize, -halfsize,  // Top right
	-halfsize,  halfsize, -halfsize,  // Top left

	// Left face
	-halfsize, -halfsize, -halfsize,  // Bottom front
	-halfsize, -halfsize,  halfsize,  // Bottom back
	-halfsize,  halfsize,  halfsize,  // Top back
	-halfsize,  halfsize, -halfsize,  // Top front

	// Right face
	 halfsize, -halfsize, -halfsize,  // Bottom front
	 halfsize, -halfsize,  halfsize,  // Bottom back
	 halfsize,  halfsize,  halfsize,  // Top back
	 halfsize,  halfsize, -halfsize,  // Top front

	 // Top face
	 -halfsize,  halfsize, -halfsize,  // Bottom left
	  halfsize,  halfsize, -halfsize,  // Bottom right
	  halfsize,  halfsize,  halfsize,  // Top right
	 -halfsize,  halfsize,  halfsize,  // Top left

	 // Bottom face
	 -halfsize, -halfsize, -halfsize,  // Bottom left
	  halfsize, -halfsize, -halfsize,  // Bottom right
	  halfsize, -halfsize,  halfsize,  // Top right
	 -halfsize, -halfsize,  halfsize,  // Top left
	};
	float uvs[] = {
	0.0f, 0.0f,  // Bottom left
	1.0f, 0.0f,  // Bottom right
	1.0f, 1.0f,  // Top right
	0.0f, 1.0f,  // Top left

	// Back face
	1.0f, 0.0f,  // Bottom left
	0.0f, 0.0f,  // Bottom right
	0.0f, 1.0f,  // Top right
	1.0f, 1.0f,  // Top left

	// Left face
	0.0f, 0.0f,  // Bottom front
	1.0f, 0.0f,  // Bottom back
	1.0f, 1.0f,  // Top back
	0.0f, 1.0f,  // Top front

	// Right face
	0.0f, 0.0f,  // Bottom front
	1.0f, 0.0f,  // Bottom back
	1.0f, 1.0f,  // Top back
	0.0f, 1.0f,  // Top front

	// Top face
	0.0f, 0.0f,  // Bottom left
	1.0f, 0.0f,  // Bottom right
	1.0f, 1.0f,  // Top right
	0.0f, 1.0f,  // Top left

	// Bottom face
	0.0f, 0.0f,  // Bottom left
	1.0f, 0.0f,  // Bottom right
	1.0f, 1.0f,  // Top right
	0.0f, 1.0f,  // Top left
		};

	int indices []= {
				
	 0, 1, 2,  0, 2, 3,

	 // Back face
	 4, 5, 6,  4, 6, 7,

	 // Left face
	 8, 9, 10,  8, 10, 11,

	 // Right face
	 12, 13, 14,  12, 14, 15,

	 // Top face
	 16, 17, 18,  16, 18, 19,

	 // Bottom face
	 20, 21, 22,  20, 22, 23
		};
	float normals[] = {
		0.0f,0.0f,1.0f,
		0.0f,0.0f,1.0f,
		0.0f,0.0f,1.0f,
		0.0f,0.0f,1.0f,

		0.0f,0.0f,-1.0f,
		0.0f,0.0f,-1.0f,
		0.0f,0.0f,-1.0f,
		0.0f,0.0f,-1.0f,

		0.0f,1.0f,0.0f,
		0.0f,1.0f,0.0f,
		0.0f,1.0f,0.0f,
		0.0f,1.0f,0.0f,

		0.0f,-1.0f,0.0f,
		0.0f,-1.0f,0.0f,
		0.0f,-1.0f,0.0f,
		0.0f,-1.0f,0.0f,

		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,

		-1.0f,0.0f,0.0f,
		-1.0f,0.0f,0.0f,
		-1.0f,0.0f,0.0f,
		-1.0f,0.0f,0.0f,

	};
	GLuint& posVbo = geometry->mPosVbo, uvVbo = geometry->mUvVbo, normalVbo = geometry->mNormalVbo;
		glGenBuffers(1, &posVbo);
		glBindBuffer(GL_ARRAY_BUFFER, posVbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

		glGenBuffers(1, &uvVbo);
		glBindBuffer(GL_ARRAY_BUFFER, uvVbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);

		glGenBuffers(1, &normalVbo);
		glBindBuffer(GL_ARRAY_BUFFER, normalVbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);

		glGenVertexArrays(1, &geometry->mVao);
		glBindVertexArray(geometry->mVao);

		glBindBuffer(GL_ARRAY_BUFFER, posVbo);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);

		glBindBuffer(GL_ARRAY_BUFFER, uvVbo);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);
		
		glBindBuffer(GL_ARRAY_BUFFER, normalVbo);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);

	
		glGenBuffers(1, &geometry->mEbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geometry->mEbo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glBindVertexArray(0); 
		return geometry;
}

Geometry* Geometry::creatSphere(float radius)
{
	Geometry* geometry = new Geometry();
	std::vector<GLfloat> positions{};
	std::vector<GLfloat> uvs{};
	std::vector<GLuint> indices{};

	int numLatiLines = 60;
	int numLongLines = 60;
	for (int i = 0; i <= numLatiLines; ++i) {
		for (int j = 0; j <= numLongLines; ++j) {
			float phi = i*glm::pi<float>() / numLatiLines;
			float theta = 2 * j * glm::pi<float>() / numLongLines;
			float y = radius * cos(phi);
			float x = radius * sin(phi) * cos(theta);
			float z = radius * sin(phi) * sin(theta);

			positions.push_back(x);
			positions.push_back(y);
			positions.push_back(z);

			float u = 1.0 - (float)j / (float)numLongLines;
			float v = 1.0 - (float)i / (float)numLatiLines;

			uvs.push_back(u);
			uvs.push_back(v);

		}
	}

	for (int i = 0; i < numLatiLines; ++i) {
		for (int j = 0; j < numLongLines; ++j) {
			int p1 = i * (numLatiLines + 1) + j;
			int p2 = p1 + numLongLines + 1;
			int p3 = p1 + 1;
			int p4 = p2 + 1;

			indices.push_back(p1);
			indices.push_back(p2);
			indices.push_back(p3);

			indices.push_back(p3);
			indices.push_back(p2);
			indices.push_back(p4);
		}
	}

	GLuint& posVbo = geometry->mPosVbo, uvVbo = geometry->mUvVbo;
	glGenBuffers(1, &posVbo);
	glBindBuffer(GL_ARRAY_BUFFER, posVbo);
	glBufferData(GL_ARRAY_BUFFER, positions.size()*sizeof(float), positions.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &uvVbo);
	glBindBuffer(GL_ARRAY_BUFFER, uvVbo);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(float), uvs.data(), GL_STATIC_DRAW);


	glGenBuffers(1, &geometry->mEbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geometry->mEbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

	glGenVertexArrays(1, &geometry->mVao);
	glBindVertexArray(geometry->mVao);

	glBindBuffer(GL_ARRAY_BUFFER, posVbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, uvVbo);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geometry->mEbo);

	glBindVertexArray(0);
	geometry->mIndicesCount = indices.size();
	return geometry;
}

Geometry* Geometry::creatPlane(float width, float height)
{
	Geometry* geometry = new Geometry();
	geometry->mIndicesCount = 6.0f;

	float halfW = width / 2.0f;
	float halfH = height / 2.0f;

	float positions[] = {
		-halfW,-halfH,0.0f,
		halfW,-halfH,0.0f,
		halfW,halfH,0.0f,
		-halfW,halfH,0.0f,
	};

	float uvs[] = {
		0.0f,0.0f,
		1.0f,0.0f,
		1.0f,1.0f,
		0.0f,1.0f,
	};

	unsigned int indices[] = {
		0,1,2,
		2,3,0,
	};

	GLuint& posVbo = geometry->mPosVbo, uvVbo = geometry->mUvVbo;
	glGenBuffers(1, &posVbo);
	glBindBuffer(GL_ARRAY_BUFFER, posVbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	glGenBuffers(1, &uvVbo);
	glBindBuffer(GL_ARRAY_BUFFER, uvVbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);

	glGenBuffers(1, &geometry->mEbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geometry->mEbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &geometry->mVao);
	glBindVertexArray(geometry->mVao);

	glBindBuffer(GL_ARRAY_BUFFER, posVbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, uvVbo);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geometry->mEbo);

	glBindVertexArray(0);
	return geometry;

	return nullptr;
}
