#pragma once
#include "OS-ImGui.h"

namespace Menu
{
	inline bool CheatMenu = false;
	inline bool Bool1 = false, Bool2 = false;
	inline float Float = 50.0f;
	inline ImColor Color = ImColor(170, 255, 0, 255);

	void AlignRight(float ContentWidth)
	{
		float ColumnContentWidth = ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x;
		float checkboxPosX = ImGui::GetColumnOffset() + ColumnContentWidth - ContentWidth;
		ImGui::SetCursorPosX(checkboxPosX);
	}

	void SwitchWithColorEdit(const char* string, float CursorX, float ContentWidth, bool* v, bool ColorEditor = false, const char* lable = NULL, float col[4] = NULL)
	{
		ImGui::PushID(string);
		float CurrentCursorX = ImGui::GetCursorPosX();
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::TextDisabled(string);
		ImGui::SameLine();
		if (ColorEditor) {
			AlignRight(ContentWidth + ImGui::GetFrameHeight() + 8);
			ImGui::ColorEdit4(lable, col, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_AlphaPreview);
			ImGui::SameLine();
		}
		else {
			AlignRight(ContentWidth);
		}

		Gui.SwitchButton("", v);
		ImGui::PopID();
	}

	void PutSliderFloat(const char* string, float CursorX, float* v, const void* p_min, const void* p_max, const char* format)
	{
		ImGui::PushID(string);
		float CurrentCursorX = ImGui::GetCursorPosX();
		float SliderWidth = ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x - CursorX;
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::TextDisabled(string);
		ImGui::SameLine();
		ImGui::TextDisabled(format, *v);
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::SetNextItemWidth(SliderWidth);
		Gui.SliderScalarEx2("", ImGuiDataType_Float, v, p_min, p_max, "", ImGuiSliderFlags_None);
		ImGui::PopID();
	}
}
