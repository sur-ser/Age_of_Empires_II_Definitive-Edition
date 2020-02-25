#pragma once
#include <string>

#include "imgui\imgui.h"

class Unit;
class Renderer
{
private:
	static Renderer* _instance;
	ImFont* m_pFont;

	Renderer();
	~Renderer();

public:
	static Renderer* Get();

	bool inFrame;

	void BeginScene();
	void EndScene();

	void RenderText(const std::string& text, const ImVec2& position, float size, uint32_t color, bool center = false);
	void RenderLine(const ImVec2& from, const ImVec2& to, uint32_t color, float thickness = 1.0f);
	void RenderPolygon(const ImVec2* points, int pointCount, uint32_t color, float thickness = 1.0f);
	void RenderCircle(const ImVec2& position, float radius, uint32_t color, float thickness = 1.0f, uint32_t segments = 16);
	void RenderCircleFilled(const ImVec2& position, float radius, uint32_t color, uint32_t segments = 16);
	void RenderRect(const ImVec2& from, const ImVec2& to, uint32_t color, float rounding = 0.0f, uint32_t roundingCornersFlags = ImDrawCornerFlags_All, float thickness = 1.0f);
	void RenderRect(const ImVec2& one, const ImVec2& two, const ImVec2& three, const ImVec2& four, uint32_t color, float thickness = 1.0f);
	void RenderRectFilled(const ImVec2& from, const ImVec2& to, uint32_t color, float rounding = 0.0f, uint32_t roundingCornersFlags = ImDrawCornerFlags_All);

	void DrawUnitCollisionRectangle(ImVec2 screenPositionCenter, ImVec2 collision, uint32_t color);
};