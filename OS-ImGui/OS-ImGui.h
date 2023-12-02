#pragma once
#include "OS-ImGui_External.h"

namespace OSImGui
{
#ifdef _CONSOLE
	class OSImGui : public OSImGui_External, public Singleton<OSImGui>
#else
	class OSImGui : public OSImGui_Internal, public Singleton<OSImGui>
#endif
	{
	public:
		void ColorEditorEx1(const char* label, ImVec4* color, float width, float height, float Roundings = 0);		// SUCKED

		void Text(std::string Text, Vec2 Pos, ImColor Color, float FontSize = 15, bool KeepCenter = false);			// Draw a text
		void StrokeText(std::string Text, Vec2 Pos, ImColor Color, float FontSize = 15, bool KeepCenter = false);	// Draw a Stroke Text
		void NewText(std::string Text, bool isCenter);																// Draw a text, but applies to text rendered in a window
		void NewTextColored(std::string Text, ImColor Color, bool isCenter);										// Same as NewText(), but u can customize its color.

		void Rectangle(Vec2 Pos, Vec2 Size, ImColor Color, float Thickness, float Rounding = 0);
		void RectangleFilled(Vec2 Pos, Vec2 Size, ImColor Color, float Rounding = 0, int Nums = 15);

		void Line(Vec2 From, Vec2 To, ImColor Color, float Thickness);

		void Circle(Vec2 Center, float Radius, ImColor Color,float Thickness, int Num = 50);
		void CircleFilled(Vec2 Center, float Radius, ImColor Color, int Num = 50);

		void ConnectPoints(std::vector<Vec2> Points, ImColor Color, float Thickness);

		void Arc(ImVec2 Center, float Radius, ImColor Color, float Thickness, float Aangle_begin, float Angle_end, float Nums = 15);

		void MyCheckBox3(const char* str_id, bool* v);
		void MyCheckBox4(const char* str_id, bool* v);

		void ShadowRectFilled(Vec2 Pos, Vec2 Size, ImColor RectColor, ImColor ShadowColor, float ShadowThickness, Vec2 ShadowOffset, float Rounding = 0);

		void ShadowCircle(Vec2 Pos, float Radius, ImColor CircleColor, ImColor ShadowColor, float ShadowThickness, Vec2 ShadowOffset, int Num = 30);

		bool SliderScalarEx1(const char* label, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format, ImGuiSliderFlags flags);
		bool SliderScalarEx2(const char* label, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format, ImGuiSliderFlags flags);

		void SwitchButton(const char* str_id, bool* v);		// SwitchButton with grab color
		void SwitchButton2(const char* str_id, bool* v);	// SwitchButton with bg color
		void SwitchButton3(const char* str_id, bool* v);	// SwitchButton using ImGui theme color

		void OpenWebpage(const char* url);								// Open a URL
		void OpenWebpageButton(const char* label, const char* url);		// Open URL when button is clicked
	};
}

inline OSImGui::OSImGui& Gui = OSImGui::OSImGui::get();