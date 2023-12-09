#include <iostream>
#include "CheatMenu.h"
#include "Image_Res.h"

ID3D11ShaderResourceView* CowNow_Memory = NULL;
int CowNow_Memory_w = 0;
int CowNow_Memory_h = 0;

void DrawCallBack()
{
	if (CowNow_Memory == NULL) {
		Gui.LoadTextureFromMemory(CowNowImagedata, sizeof CowNowImagedata, &CowNow_Memory, &CowNow_Memory_w, &CowNow_Memory_h);
	}
	
	ImGui::SetNextWindowSize(ImVec2(400, 0));
	ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
	{
		static ImColor FrameColor = ImColor(255, 70, 0, 255);
		static ImColor TextColor = ImColor(255, 255, 255, 255);
		Gui.NewText("This Text is centered", true);
		Gui.NewTextColored("And colored it", ImColor(255,60,0,255), true);
		Gui.StrokeText("Stroke Text", { 640,50 }, TextColor, FrameColor, 30.0f, true);
		Gui.OpenWebpageButton("Open Webpage", "https://github.com/CowNowK/ImGuiExpand");
		static bool a = false, b = false, c = false, d = false, e = false, f = false;
		static float Value1 = 25, Value2 = 75;
		static float Color = 0.f;
		static ImVec4 ColorVec4 = ImColor(255, 0, 0, 255);
		float min = 0, max = 100;
		
		Gui.MyCheckBox3("CheckBox3", &c);
		Gui.MyCheckBox4("CheckBox4", &d);
		ImGui::NewLine();
		Gui.SwitchButton("Switch Button", &e);
		Gui.SwitchButton2("Switch Button 2", &a);
		Gui.SwitchButton3("Switch Button 3", &b);
		Gui.SliderScalarEx1("[Slider1]", ImGuiDataType_Float, &Value1, &min, &max, "%.1f", ImGuiSliderFlags_None);
		Gui.SliderScalarEx2("[Slider2]", ImGuiDataType_Float, &Value2, &min, &max, "%.1f", ImGuiSliderFlags_None);
		ImGui::Text("Image");
		ImGui::Image((void*)CowNow_Memory, ImVec2(CowNow_Memory_w, CowNow_Memory_h));

		ImGui::SameLine();
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 50.f);
		if (ImGui::Button("Cheat Menu Example"))
			Menu::CheatMenu = true;

	}ImGui::End();

	if (Menu::CheatMenu)
	{
		ImGui::SetNextWindowSize(ImVec2(500, 0));
		ImGui::Begin("Example", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
		{
			ImGui::Columns(2, nullptr, false);
			ImGui::SeparatorText("Switch");
			Menu::SwitchWithColorEdit("Enable", 15.f, ImGui::GetFrameHeight() * 1.7, &Menu::Bool1);
			Menu::SwitchWithColorEdit("Wallhack Color", 15.f, ImGui::GetFrameHeight() * 1.7, &Menu::Bool2, true, "###ColorEdit", reinterpret_cast<float*>(&Menu::Color));
			
			ImGui::NextColumn();
			float Min = 0.f, Max = 500.f;
			ImGui::SeparatorText("Slider");
			Menu::PutSliderFloat("Delay:", 5.f, &Menu::Float, &Min, &Max, "%.2f ms");
			ImGui::Columns(1);
		}ImGui::End();
	}

	Gui.ShadowRectFilled({ 50,50 }, { 100,100 }, ImColor(220, 190, 99, 255), ImColor(50, 50, 50, 255), 9, { 0,0 }, 10);
	Gui.ShadowCircle({ 200,200 }, 30, ImColor(220, 190, 99, 255), ImColor(50, 50, 50, 255), 9, { 0,0 });

	//...
}

int main()
{
	try {
		Gui.NewWindow("WindowName", Vec2(1280, 720), DrawCallBack);

		//
		//Gui.AttachAnotherWindow("Title","", DrawCallBack);
	}
	catch (OSImGui::OSException& e)
	{
		std::cout << e.what() << std::endl;
	}

	system("pause");
	return 0;
}