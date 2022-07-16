#pragma once

#include "Core.h"

namespace Moon
{
	enum class MaterialType
	{
		Texture,
		Color
	};

	class MOON_API Texture
	{
	public:
		Texture(Uint textureID);
		Texture(const String& texturePath);
		~Texture();
		void Bind(Uint slot = 0) const;
		void Unbind() const;
	private:
		Uint m_TextureID;
	};

	class Color
	{
	public:
		MOON_API Color(Vec4 color);
		MOON_API Color(Float r, Float g, Float b, Float a = 1.0);

		MOON_API inline Vec4 GetColor() const { return m_Color; }
	private:
		Vec4 m_Color;
	};

	class MOON_API Material
	{
	public:
		Material(MaterialType, Texture* texture);
		Material(MaterialType, Color* color);

		inline Texture* GetTexture() const { return m_Texture; }
		inline Color* GetColor() const { return m_Color; }
		inline MaterialType GetMaterialType() const { return m_MaterialType; }
	private:
		MaterialType m_MaterialType;
		Texture* m_Texture;
		Color* m_Color;
	};
}