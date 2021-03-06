#pragma once

#include "pch.h"

#include "..\..\..\Engine\Third Party\DirectX Tool Kit\VertexTypes.h"

#include "..\..\..\Engine\Pipeline Stages\Shaders\Vertex Shader.h"
#include "..\..\..\Engine\Pipeline Stages\Shaders\Pixel Shader.h"
#include "..\..\..\Engine\Pipeline Stages\Shaders\Compute Shader.h"

#include "..\..\..\Engine\Models\Mesh Base.h"
#include "..\..\..\Engine\Models\Basic Shapes\Cubes.h"
#include "..\..\..\Engine\Models\MD5Model\Md5Model.h"
#include "..\..\..\Engine\Models\MD5Model\CubeObject.h"

#include "..\..\..\Engine\Scene\Transforms\World Transforms.h"
#include "..\..\..\Engine\Scene\Transforms\View Transform.h"
#include "..\..\..\Engine\Scene\Transforms\Projection Transform.h"

using namespace vxe;

enum PRESENTATION_EXAMPLE
{
	REFERENT_POSE_LOAD = 0,
	ANIMATION_SKELETON_LOAD = 1,
	CDE_EXAMPLE = 2
};

class Renderer3D :public RendererBase3D
{
public:
	std::shared_ptr<VertexShader<DirectX::VertexPositionColor>> _vertexshader;
	std::shared_ptr<PixelShader> _pixelshader;

	std::shared_ptr<MD5Model> _model;
	std::shared_ptr<CubeObject> _cube;

	std::shared_ptr<WorldTransforms> _world;
	std::shared_ptr<ViewTransform> _view;
	std::shared_ptr<ProjectionTransform> _projection;

	Renderer3D() :RendererBase3D()
		, isCollision(false)
		, exampleNumber(CDE_EXAMPLE)
	{
		DebugPrint(std::string("Renderer3D::Ctor called\n"));
		
	}
	void CreateDeviceDependentResources();
	void CreateWindowSizeDependentResources();
	void Update(DX::StepTimer const & timer);
	void ReleaseDeviceDependentResources();
	void Render();

	bool Renderer3D::BoundingBoxCollisionTest(shared_ptr<GameObject> object1, shared_ptr<GameObject> object2);

	void Rotate(float radians)
	{
		_world->RotateY(radians);
	}

private:
	void SetCamera()
	{
		auto context = m_deviceResources->GetD3DDeviceContext();
		_view->GetConstantBuffer()->Bind(context, ProgrammableStage::VertexShaderStage, 1);
		_projection->GetConstantBuffer()->Bind(context, ProgrammableStage::VertexShaderStage, 2);
	}

	bool isCollision;
	PRESENTATION_EXAMPLE exampleNumber;
};