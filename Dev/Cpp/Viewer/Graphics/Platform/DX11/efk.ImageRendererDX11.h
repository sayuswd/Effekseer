#pragma once

#include <Effekseer.h>
#include <EffekseerRenderer/EffekseerRendererDX11.Renderer.h>
#include <EffekseerRenderer/EffekseerRendererDX11.RendererImplemented.h>
#include <EffekseerRenderer/EffekseerRendererDX11.VertexBuffer.h>
#include <EffekseerRenderer/EffekseerRendererDX11.IndexBuffer.h>
#include <EffekseerRenderer/EffekseerRendererDX11.Shader.h>
#include <EffekseerRenderer/EffekseerRendererDX11.RenderState.h>
#include "../../efk.ImageRenderer.h"

namespace efk
{
	class ImageRendererDX11
		: public ImageRenderer
	{
	private:
		struct Sprite
		{
			std::array<EffekseerRendererDX11::Vertex, 4>	Verteies;
			void*	TexturePtr = nullptr;
		};

		EffekseerRendererDX11::RendererImplemented*	renderer = nullptr;
		EffekseerRenderer::ShaderBase*				shader = nullptr;
		EffekseerRenderer::ShaderBase*				shader_no_texture = nullptr;

		std::vector<Sprite>	sprites;

	public:
		ImageRendererDX11(EffekseerRenderer::Renderer* renderer);

		virtual ~ImageRendererDX11();

		void Draw(const Effekseer::Vector3D positions[], const Effekseer::Vector2D uvs[], const Effekseer::Color colors[], void* texturePtr) override;

		void Render() override;

		void ClearCache() override;

		void OnLostDevice() override;

		void OnResetDevice() override;
	};
}