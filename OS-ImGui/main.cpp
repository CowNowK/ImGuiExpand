#include <iostream>
#include "OS-ImGui.h"

void DrawCallBack()
{
	ImGui::SetNextWindowSize(ImVec2(400, 0));
	ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
	{
		Gui.NewText("This Text is centered", true);
		Gui.NewTextColored("And colored it", ImColor(255,60,0,255), true);
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
	}ImGui::End();

	Gui.ShadowRectFilled({ 50,50 }, { 100,100 }, ImColor(220, 190, 99, 255), ImColor(50, 50, 50, 255), 9, { 0,0 }, 10);
	Gui.ShadowCircle({ 200,200 }, 30, ImColor(220, 190, 99, 255), ImColor(50, 50, 50, 255), 9, { 0,0 });

	//...
}

int main()
{
	try {
		Gui.NewWindow("WindowName", Vec2(1280, 720), DrawCallBack);
		//Gui.AttachAnotherWindow("Title","", DrawCallBack);
	}
	catch (OSImGui::OSException& e)
	{
		std::cout << e.what() << std::endl;
	}

	system("pause");
	return 0;
}