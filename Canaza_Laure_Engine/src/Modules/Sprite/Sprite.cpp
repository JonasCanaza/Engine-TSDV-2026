#include "Sprite.h"

namespace Sprite
{
	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec4 aColor;\n"
		"layout (location = 2) in vec2 aTexCoord;\n"

		"uniform mat4 model;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"out vec4 myColor;\n"
		"out vec2 texCoord;\n"
		"void main()\n"
		"{\n"
		"    gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
		"    myColor = aColor;\n"
		"    texCoord = aTexCoord;\n"
		"}\n";

	const char* fragmentShaderSource = "#version 330 core\n"
		"in vec4 myColor;\n"
		"in vec2 texCoord;\n"
		"out vec4 FragColor;\n"
		"uniform sampler2D ourTexture;\n"
		"void main()\n"
		"{\n"
		"    FragColor = texture(ourTexture, texCoord);\n"
		"}\n";

	static const std::vector<float> rectangleVerticesObj =
	{
	-0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,  0.0f, 0.0f,
	 0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 1.0f,  1.0f, 0.0f,
	 0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f, 1.0f,  1.0f, 1.0f,
	-0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f, 1.0f,  0.0f, 1.0f
	};

	static const std::vector<unsigned int> rectangleIndexesObj =
	{
0,1,2,
2,3,0
	};

	Sprite::Sprite(glm::mat4 globalTRS, glm::vec4 color, Renderer::Renderer* renderer, TextureImporter::TextureImporter* textImporter, const char path[], int width, int height, ColorFormat::ColorFormat format) : Entity2D(globalTRS, color, renderer, rectangleVerticesObj, rectangleIndexesObj, vertexShaderSource, fragmentShaderSource)
	{
		texture = textImporter->ImportTexture(path, width, height, format);
	}

	void Sprite::AddFrame(float framePosX, float framePosY, float frameWidth, float frameHeight, float textWidth, float textHeight, float durationInSeconds)
	{
		if (animation == nullptr)
		{
			animation = new Animation::Animation();
		}

		animation->AddFrame(framePosX, framePosY, frameWidth, frameHeight, textWidth, textHeight, durationInSeconds);
	}

	void Sprite::ChangeSprite(AnimationFrame::AnimationFrame* animationFrame)
	{
		for (int i = 0; i < 4; i++)
		{
			vertices[9 * i + 7] = animationFrame->uvCoords[i].u;
			vertices[9 * i + 8] = animationFrame->uvCoords[i].v;
		}

		renderer->UpdateVBO(model.VBO, vertices);
	}

	void Sprite::Update(float deltaTime)
	{
		if (animation != nullptr)
		{
			animation->Update(deltaTime);

			AnimationFrame::AnimationFrame* animationCurrentFrame = animation->GetCurrentFrame();

			if (animationCurrentFrame != currentFrame)
			{
				currentFrame = animationCurrentFrame;
				ChangeSprite(currentFrame);
			}
		}

		Draw();
	}

	void Sprite::Draw()
	{
		renderer->DrawSprite(globalTRS, model.VAO, model.indexCount, material->GetShader()->GetId(), material->GetModelLocation(), material->GetViewLocation(), material->GetProjectionLocation(), texture);
	}

	Sprite::~Sprite()
	{
		if (animation != nullptr)
		{
			delete animation;
		}
	}
}