﻿#define STB_IMAGE_IMPLEMENTATION
#include"stb_image.h"
#pragma warning(disable : 4996)
#include "api/KeyAuth.hpp"
#include "xorstr.hpp"
#include"SimpleIni.h"
#include<D3DX11tex.h>
#define LOADER_BRAND "Loader base"
#include "Esp.h"
#include <iostream>
#include <fstream>
#include "api/KeyAuth.hpp"
#include "imguipp.h"

using namespace KeyAuth;

bool fight = true;
//char key[60] = "";
std::string str = "KHANI";
bool login = false;
bool loginn = true;
 bool SaveUsers = true;
bool savekey = true;
bool loader_active = true;
D3DMATRIX Esp::ViewMatrix;
static bool Bot = true;
static bool Player = true;
std::string tim;
 char str1[60] = "";
 float overlaycolor = 0.0f;
 int teamids;
 ImVec4 linescolors;// = { 1.0f,1.0f,1.0f,1.0f };
 ImVec4 bonescolors;// = { 1.0f,1.0f,1.0f,1.0f };
 ImVec4 fullboxcolor;// = { 1.0f,1.0f,1.0f,1.0f };
 ImVec4 cornerboxcolor;// = { 1.0f,1.0f,1.0f,1.0f };

 ImVec4 blinescolors;
 ImVec4 bbonescolors;
 ImVec4 bfullboxcolor;
 ImVec4 bcornerboxcolor;
 bool driving = true;
 ImColor col;
 bool unload = false;

 static auto Flags2 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
 static auto Flags21 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar;

namespace Settings
{
	static int Tab = 5;
}
bool watermark = true;
int currIndex;
float popcorn = 0.5f;
float popcorn2 = 0.450f;
ImVec4 colorr;
int Emu_Int = 0;
int item_current_Emu = 0;
int currentengine = 0;
int item_current_Aim = 0;
int skelesec = 0;
 //  (DX11::pDevice, &logo, sizeof(logo), 462, 462, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &logggo);
ImVec4 to_vec4(float r, float g, float b, float a)
{
	return ImVec4(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
	

}

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}
std::string GetCurrentDirectory()
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}
inline bool FileExist(const std::string& name) {
	if (FILE* file = fopen(name.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}
void Esp::LoadConfig(std::string Path) {
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(Path.c_str());
//	if (rc < 0) { std::cout << "File not found"; };
	if (FileExist(Path))
	{
		bool State = ini.GetBoolValue("Key", "UserKeyState");
		if (State == true)
		{
			std::string Key = ini.GetValue("Key", "UserKey");
			if (Key != "")
			{
				strcpy(str1, Key.c_str());
				SaveUsers = true;
			}

		}

	}
	/* if (ini.GetValue("Key", "UserKey")=="123")
	 {

	 }*/
}
void WriteConfig(std::string Path, std::string Key, bool State) {
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(Path.c_str());
	if (rc < 0) {
	//	std::cout << "File not found";
	};
	if (State == true)
	{
		ini.SetBoolValue("Key", "UserKeyState", true);
	}
	else
	{
		ini.SetBoolValue("Key", "UserKeyState", false);
	}
	ini.SetValue("Key", "UserKey", Key.c_str());

	ini.SaveFile(Path.c_str());
}

bool dirExists(const std::string& dirName_in)
{
	DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}


void WriteResToDisk(std::string PathFile, LPWSTR File_WITHARG)
{
	HRSRC myResource = ::FindResource(NULL, File_WITHARG, RT_RCDATA);
	unsigned int myResourceSize = ::SizeofResource(NULL, myResource);
	HGLOBAL myResourceData = ::LoadResource(NULL, myResource);
	void* pMyExecutable = ::LockResource(myResourceData);
	std::ofstream f(PathFile, std::ios::out | std::ios::binary);
	f.write((char*)pMyExecutable, myResourceSize);
	f.close();
}
void WriteConfigurate(std::string Path)
{
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(Path.c_str());
	if (rc < 0) { std::cout << "File not found"; };


	
	Setting::MagicBullet = ini.GetBoolValue("ESp", "key0");
	Setting::MAgicline = ini.GetDoubleValue("ESp", "Key1");
	Setting::playerBone = ini.GetBoolValue("ESp", "Key2");
	Setting::playerdeadbox = ini.GetBoolValue("ESp", "Key3");
	Setting::pcorner = ini.GetBoolValue("ESp", "Key4");
	Setting::allitemss = ini.GetBoolValue("ESp", "Key5");
	Setting::hp = ini.GetDoubleValue("ESp", "Key6");
//	Setting::style1 = ini.GetBoolValue("style1", "Key7");
	Setting::pfullbox = ini.GetBoolValue("ESp", "Key8");
	Setting::pline = ini.GetDoubleValue("ESp", "Key9");
	Setting::botfullbox = ini.GetBoolValue("ESp", "Key10");
	Setting::fightmode = ini.GetDoubleValue("ESp", "Key11");
	Setting::botcorner = ini.GetBoolValue("ESp", "Key12");
	Setting::botblood = ini.GetBoolValue("ESp", "Key14");
	Setting::botBone = ini.GetDoubleValue("ESp", "Key13");
	Setting::botline = ini.GetBoolValue("ESp", "Key15");
	Setting::curraim = ini.GetDoubleValue("ESp", "Key16");
	Setting::botBone = ini.GetBoolValue("ESp", "Key17");

	ini.SaveFile(Path.c_str());
}

void LoadConfiggg(std::string Path)
{
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(Path.c_str());
	if (rc < 0) { std::cout << "File not found"; };

	Setting::MagicBullet = ini.GetBoolValue("MagicBullet", "key0");
	Setting::MAgicline = ini.GetDoubleValue("MAgicline", "Key1");
	Setting::playerBone = ini.GetBoolValue("playerBone", "Key2");
	Setting::playerdeadbox = ini.GetBoolValue("playerdeadbox", "Key3");
	Setting::pcorner = ini.GetBoolValue("pcorner", "Key4");
	Setting::allitemss = ini.GetBoolValue("allitemss", "Key5");
	Setting::hp = ini.GetDoubleValue("HP", "Key6");
	//Setting::style1 = ini.GetBoolValue("style1", "Key7");
	Setting::pfullbox = ini.GetBoolValue("pfullbox", "Key8");
	Setting::pline = ini.GetDoubleValue("pline", "Key9");
	Setting::botfullbox = ini.GetBoolValue("botfullbox", "Key10");
	Setting::fightmode = ini.GetDoubleValue("fightmode", "Key11");
	Setting::botcorner = ini.GetBoolValue("botcorner", "Key12");
	Setting::botblood = ini.GetBoolValue("botblood", "Key14");
	Setting::botBone = ini.GetDoubleValue("botBone", "Key13");
	Setting::botline = ini.GetBoolValue("botline", "Key15");
	Setting::curraim = ini.GetDoubleValue("Aim", "Key16");
	Setting::botBone = ini.GetBoolValue("botBone", "Key17");

}

bool ProcessInlineHexColor(const char* start, const char* end, ImVec4& color)
{
	const int hexCount = (int)(end - start);
	if (hexCount == 6 || hexCount == 8)
	{
		char hex[9];
		strncpy(hex, start, hexCount);
		hex[hexCount] = 0;

		unsigned int hexColor = 0;
		if (sscanf(hex, "%x", &hexColor) > 0)
		{
			color.x = static_cast<float>((hexColor & 0x00FF0000) >> 16) / 255.0f;
			color.y = static_cast<float>((hexColor & 0x0000FF00) >> 8) / 255.0f;
			color.z = static_cast<float>((hexColor & 0x000000FF)) / 255.0f;
			color.w = 1.0f;

			if (hexCount == 8)
			{
				color.w = static_cast<float>((hexColor & 0xFF000000) >> 24) / 255.0f;
			}

			return true;
		}
	}

	return false;
}

const char ColorMarkerStart = '{';
const char ColorMarkerEnd = '}';

void TextWithColors(const char* fmt, ...)
{
	char tempStr[4096];

	va_list argPtr;
	va_start(argPtr, fmt);
	_vsnprintf(tempStr, sizeof(tempStr), fmt, argPtr);
	va_end(argPtr);
	tempStr[sizeof(tempStr) - 1] = '\0';

	bool pushedColorStyle = false;
	const char* textStart = tempStr;
	const char* textCur = tempStr;
	while (textCur < (tempStr + sizeof(tempStr)) && *textCur != '\0')
	{
		if (*textCur == ColorMarkerStart)
		{
			// Print accumulated text
			if (textCur != textStart)
			{
				ImGui::TextUnformatted(textStart, textCur);
				ImGui::SameLine(0.0f, 0.0f);
			}

			// Process color code
			const char* colorStart = textCur + 1;
			do
			{
				++textCur;
			} while (*textCur != '\0' && *textCur != ColorMarkerEnd);

			// Change color
			if (pushedColorStyle)
			{
				ImGui::PopStyleColor();
				pushedColorStyle = false;
			}

			ImVec4 textColor;
			if (ProcessInlineHexColor(colorStart, textCur, textColor))
			{
				ImGui::PushStyleColor(ImGuiCol_Text, textColor);
				pushedColorStyle = true;
			}

			textStart = textCur + 1;
		}
		else if (*textCur == '\n')
		{
			// Print accumulated text an go to next line
			ImGui::TextUnformatted(textStart, textCur);
			textStart = textCur + 1;
		}

		++textCur;
	}

	if (textCur != textStart)
	{
		ImGui::TextUnformatted(textStart, textCur);
	}
	else
	{
		ImGui::NewLine();
	}

	if (pushedColorStyle)
	{
		ImGui::PopStyleColor();
	}
}
void DrawMenu2() {
	/*------------------------*/

	ImGuiStyle& style = ImGui::GetStyle();

	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	ImGuiIO& Io = ImGui::GetIO();

	bool pOpen1 = true;
	ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.1f, Io.DisplaySize.y * 0.5f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));

	ImGui::SetNextWindowSize({ 150.f,200.f });
	ImGui::Begin("BOSS eXtreme", &pOpen1, ImGuiWindowFlags_NoResize); {
		ImGui::Spacing();
		ImGui::SetNextWindowBgAlpha(0.60f);


		
		std::string hack = "HOME | Hide Menu";
		std::string Insert = "INS  | Show Settings";
		//ImGui::Text("=======================");


		float dsheight = DX11Window::Height / 2;

		VECTOR3 screen;
		int distance;


		ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
		ImGui::Text("F2 ||");
		ImGui::PopStyleColor();
		ImGui::SameLine();

		if (Setting::MagicBullet)
		{
			ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
			ImGui::Text("  Magic Bullet");
			ImGui::PopStyleColor();


		}
		else
		{
			ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));
			ImGui::Text("  Magic Bullet");
			ImGui::PopStyleColor();
		}

		ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
		ImGui::Text("F3 ||");
		ImGui::PopStyleColor();
		ImGui::SameLine();

		if (Setting::Item)
		{
			ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));
			ImGui::Text("  Combat Mode");
			ImGui::PopStyleColor();


		}
		else
		{
			ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
			ImGui::Text("  Combat Mode");
			ImGui::PopStyleColor();
		}

		ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
		ImGui::Text("F4 ||");
		ImGui::PopStyleColor();
		ImGui::SameLine();

		if (Setting::instanthit)
		{
			ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
			ImGui::Text("  Instant Hit");
			ImGui::PopStyleColor();


		}
		else
		{
			ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));
			ImGui::Text("  Instant Hit");
			ImGui::PopStyleColor();
		}

		ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
		ImGui::Text("F5 ||");
		ImGui::PopStyleColor();
		ImGui::SameLine();

		if (Setting::recoil)
		{
			ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
			ImGui::Text("  No Recoil");
			ImGui::PopStyleColor();


		}
		else
		{
			ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));
			ImGui::Text("  No Recoil");
			ImGui::PopStyleColor();
		}

		ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
		ImGui::Text("F6 ||");
		ImGui::PopStyleColor();
		ImGui::SameLine();

		if (Setting::speedcar)
		{
			ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
			ImGui::Text("  Speed Car");
			ImGui::PopStyleColor();


		}
		else
		{
			ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 255));
			ImGui::Text("  Speed Car");
			ImGui::PopStyleColor();
		}


		ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
		ImGui::Text("-----------------------------");
		ImGui::PopStyleColor();
		//ImGui::SameLine();



		ImGui::Text(hack.c_str());
		ImGui::Text(Insert.c_str());
		ImGui::End();



	}
	//----------------------------
	if (GetAsyncKeyState(VK_F3) & 1)
	{
		Setting::Item = !Setting::Item;
	}


	//---------------------------
	if (GetAsyncKeyState(VK_F4) & 1)
	{
		Setting::instanthit = !Setting::instanthit;
	}


	/*---------------------------*/
	if (GetAsyncKeyState(VK_F5) & 1)
	{
		Setting::recoil = !Setting::recoil;
	}
	if (GetAsyncKeyState(VK_F6) & 1)
	{
		Setting::speedcar = !Setting::speedcar;
	}
	if (GetAsyncKeyState(VK_F2) & 1)
	{
		Setting::MagicBullet = !Setting::MagicBullet;
	}
}


///Settings
int nsize = 14;
static int skelee = 0;
static int linne = 0;
static int hpbt = 0;
static int boxe = 0;
static int aimbp = 0;
int dissize = 14;
int hp = 14;
int vehisize = 15;
bool marco1 = false;
bool nothingm = true;
bool nothinga = false;

//

VOID Esp::EspThread()
{


	VECTOR3 Screen;
	INT Distance;
	INT EnemyCount;

	VECTOR3 HeadPos;
	VECTOR2 Head;
	VECTOR2 Chest;
	VECTOR2 Pelvis;
	VECTOR2 lSholder;
	VECTOR2 rSholder;
	VECTOR2 lElbow;
	VECTOR2 rElbow;
	VECTOR2 lWrist;
	VECTOR2 rWrist;
	VECTOR2 lThigh;
	VECTOR2 rThigh;
	VECTOR2 lKnee;
	VECTOR2 rKnee;
	VECTOR2 lAnkle;
	VECTOR2 rAnkle;
	std::string temp = "";
	std::string dist = "";
	string Text = "";
	DWORD window_flags =  ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
	std::string name = XorStr("PABLO11");
	std::string ownerid = XorStr("trUH4Xyg7e");
	std::string secret = XorStr("6230e3883eb99813840b7e602918826302dee2f98b8aff0293b8fd859fb3f7a3");
	std::string version = XorStr("1.0");
		
	api KeyAuthApp(name, ownerid, secret, version);
	KeyAuthApp.init();
	RECT screen_rect;
	GetWindowRect(GetDesktopWindow(), &screen_rect);
//	auto x = float(screen_rect.right - 400) / 2.f;
//	auto y = float(screen_rect.bottom - 300) / 2.f;
	
	LoadConfig("‪C:BOSS_Key.ini"); //‪C:\khni_Key.ini
	while (true)
	{
		Sleep(5);
		
		DX11::BeginDraw();
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		if (GetAsyncKeyState(Setting::EnableKey) & 1)
		{
			Setting::Aimbot = !Setting::Aimbot;
		}
		if (GetAsyncKeyState(Setting::PositionKey) & 1)
		{
			if (Setting::curraim == 0)
			{

				Setting::curraim++;
			}
			else
			{

				Setting::curraim--;
			}


		}



		int my_image_width = 0;
		int my_image_height = 0;
	
		/*bool Result = LoadTextureFromFile("../new.png", &my_texture, &my_image_width, &my_image_height);
		IM_ASSERT(Result);*/
	
		/*time_t rawtime = mktime(&KeyAuthApp.user_data.expiry);
		struct tm* timeinfo;
		timeinfo = localtime(&rawtime);*/
		//ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 0.300f);
		//const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
		
		if (Setting::ShowMenu)
		{
			//DX11::pImmediateContext->ClearRenderTargetView(DX11::pRenderTargetView, clear_color_with_alpha);
			LoadConfig("C:\\BOSS_Key.ini");
			if (!login)
			{
				ImGuiIO& Io = ImGui::GetIO();
				
				ImGui::SetNextWindowSize(ImVec2(400.0f, 110.0f));
			

				ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.5f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
				if (ImGui::Begin("BOSS eXtreme", 0, Flags2))
				{  
					
					ImGui::Text(" Key:  (?)");
					ImGui::SameLine();
					ImGui::InputText("###Key", str1, IM_ARRAYSIZE(str1));
				
					ImGui::SetCursorPosX({ 6.f });
					if (ImGui::Button(" Login", { 190.0f,23.0f }))
					{
						//ShellExecute(NULL, L"open", L"https://bossofficial.site", NULL, NULL, SW_SHOWNORMAL);
						if (KeyAuthApp.license(str1))
						//if (str1 == "")
						{
							 
						     login = true;

						

						}
						else
						{
							exit(1);
							login = false;	
						}
					
					}
					ImGui::SameLine();
					ImGui::SetCursorPosX({ 205.f });
					if (ImGui::Button(" Get FREE key", { 190.0f,23.0f }))
					{

						ShellExecute(NULL, L"open", L"https://bossofficial.site", NULL, NULL, SW_SHOWNORMAL);
					  //ShellExecute(NULL, L"open", L"bossofficial.site", NULL, NULL, SW_SHOWNORMAL);
						
					}
					//ImGui::SetCursorPosX({ 205.f });
					if (ImGui::Button(" Buy VIP key", { 390.0f,23.0f }))
					{

						ShellExecute(NULL, L"open", L"https://bossofficial.site", NULL, NULL, SW_SHOWNORMAL);
						//ShellExecute(NULL, L"open", L"bossofficial.site", NULL, NULL, SW_SHOWNORMAL);

					}
					ImGui::SetCursorPosX({ 200.f });
						
						if (SaveUsers)
						{

						}
						else
						{
						}
					


					ImGui::End();
				}

			}

			

			if (login)
			{


				static auto Name = "Menu";
				static auto Flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
				static auto Flags1 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

				/*static ImVec4 active = to_vec4(64, 83, 39, 255);
				static ImVec4 inactive = to_vec4(34, 61, 34, 102);*/
				static ImVec4 active = to_vec4(149, 42, 77, 255);  //149,42,77
				static ImVec4 inactive = to_vec4(122, 41, 41, 255);

				ImGui::SetNextWindowSize({ 799, 605 });

				if (ImGui::Begin("BOSS eXtreme Cheats", 0, Flags1))
				{
					
					ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 1 ? active : inactive);
					if (ImGui::Button(ICON_FA_HOME" Mainpage", ImVec2(158 - 6, 23)))
						Settings::Tab = 1;

					ImGui::SameLine();
					ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 2 ? active : inactive);
					if (ImGui::Button(ICON_FA_EYE" ESP", ImVec2(158 - 6, 23)))
						Settings::Tab = 2;

					ImGui::SameLine();
					ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 3 ? active : inactive);
					if (ImGui::Button(ICON_FA_CROSSHAIRS" Aimbot", ImVec2(158 - 6, 23)))
						Settings::Tab = 3;
					ImGui::SameLine();
					ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 4 ? active : inactive);
					if (ImGui::Button(ICON_FA_EDIT" Memory", ImVec2(158 - 6, 23)))
						Settings::Tab = 4;

					ImGui::SameLine();
					ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 5 ? active : inactive);
					if (ImGui::Button(ICON_FA_COG" Settings", ImVec2(158 - 6, 23)))
						Settings::Tab = 5;

					ImGui::PopStyleColor(5);

					ImGui::Separator();

					{
						if (Settings::Tab == 1)
						{
							//ImGui::SetCursorPos(ImVec2(10, 10));
							ImGui::BeginChild("##1", ImVec2(793, 535), true, 0);
							{
								ImGui::Text("Welcome To BOSS eXtreme Cheats");
								//ImGui::Text("Shit I Don't Know How To Make Online Chat Here -_-");

							}
							ImGui::EndChild();
						}

						if (Settings::Tab == 2)
						{
							//ImGui::SetCursorPos(ImVec2(10, 10));
							ImGui::BeginChild("##2", ImVec2(793, 535), true, 0);
							{

								ImGui::SetCursorPos(ImVec2(5, 5));
								ImGui::BeginChild("###1", ImVec2(230, 520), true, 0);
								{
									ImGui::Checkbox(" Show enemy name", &Setting::pname);
									ImGui::Checkbox(" Draw enemy skeleton", &Setting::playerBone);
									ImGui::Checkbox(" Draw line to enemy", &Setting::pline);
									ImGui::Checkbox(" Show enemy distance", &Setting::Distancee);
									ImGui::Checkbox(" Show enemy health", &Setting::phealth);
									ImGui::Checkbox(" Show enemy weapon", &Setting::Name);
									ImGui::Checkbox(" Draw player box", &Setting::pcorner);
									ImGui::Checkbox(" Show items", &Setting::Item);
									ImGui::Checkbox(" Sort items by sequences", &Setting::sortitem);
									ImGui::Checkbox(" Show items inside Lootbox", &Setting::deadbox);
									ImGui::Checkbox(" Show vehicle", &Setting::Vehicle);
									ImGui::Checkbox(" Show number of enemy around", &Setting::TotalEnemy);
									ImGui::Checkbox(" Show grenade warning", &Setting::graned);
									ImGui::Checkbox(" Show enemy aiming warning", &Setting::aimwarning);
									ImGui::Checkbox(" Draw radar", &Setting::dots);
									ImGui::Checkbox(" Show RedZone denger location", &Setting::redzone);

								}
								ImGui::EndChild();

								ImGui::SetCursorPos(ImVec2(238, 5));
								ImGui::BeginChild("###2", ImVec2(548, 520), true, 0);
								{
									if (ImGui::BeginTabBar("BOSS")) {
										if (ImGui::BeginTabItem("Player settings")) {
											ImGui::BeginChild("###");
											//ImGui::SetCursorPos(ImVec2(0, 5));
											ImGui::BeginChild("###12", ImVec2(540, 468), true, 0);
											{
												if (ImGui::BeginTabBar("BOSS")) {
													if (Setting::pname)
													{
														if (ImGui::BeginTabItem("Name")) {
															ImGui::Spacing();
															ImGui::Text("Text color ");
															ImGui::SameLine();
															ImGui::ColorEdit4("Text color", (float*)&Colors::nam, ImGuiColorEditFlags_NoLabel);

															ImGui::Text("Text size ");
															ImGui::SameLine();
															ImGui::SliderInt("###4", &nsize, 0, 50);

															ImGui::EndTabItem();
														}
													}
													ImGui::SameLine();
													if (Setting::playerBone)
													{
														if (ImGui::BeginTabItem("Skeleton")) {

															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															
															ImGui::Text("Color mode");
															ImGui::SameLine();
															const char* Emu[] = { "Team ID", "Default" };
															
															const char* combo_label = Emu[skelee];
															if (ImGui::BeginCombo(" lol", combo_label, ImGuiComboFlags_HeightSmall))
															{
																for (int n = 0; n < IM_ARRAYSIZE(Emu); n++)
																{
																	const bool is_selected = (skelee == n);
																	if (ImGui::Selectable(Emu[n], is_selected))
																		skelee = n;
																	if (is_selected)
																		ImGui::SetItemDefaultFocus();
																}
																if (skelee == 0);
																//Setting::skele = true;
																else if (skelee == 1);
																	//Setting::skele = false;
																

																ImGui::EndCombo();
															}
															if (skelee == 1)
															{
																ImGui::Text("Color ");
																ImGui::SameLine();
																ImGui::ColorEdit4(" color", (float*)&Colors::skelec, ImGuiColorEditFlags_NoLabel);
															}
															ImGui::Text("Thickness ");
															ImGui::SameLine();
															ImGui::SliderFloat("Bone size", &Setting::pbonesize, 0.100f, 3.00f);

															//ImGui::EndChild();
															ImGui::EndTabItem();
															//ImGui::EndChild();
														}
													}
													ImGui::SameLine();
													if (Setting::pline)
													{
														if (ImGui::BeginTabItem("Line")) {

															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();

															ImGui::Text("Color mode");
															ImGui::SameLine();
															const char* Emu1[] = { "Team ID", "Default" };

															const char* combo_label = Emu1[linne];
															if (ImGui::BeginCombo(" loll", combo_label, ImGuiComboFlags_HeightSmall))
															{
																for (int n = 0; n < IM_ARRAYSIZE(Emu1); n++)
																{
																	const bool is_selected = (linne == n);
																	if (ImGui::Selectable(Emu1[n], is_selected))
																		linne = n;
																	if (is_selected)
																		ImGui::SetItemDefaultFocus();
																}
																if (linne == 0);
																//Setting::skele = true;
																else if (linne == 1);
																	//Setting::skele = false;


																ImGui::EndCombo();
															}
															if (linne == 1)
															{
																ImGui::Text("Line color ");
																ImGui::SameLine();
																ImGui::ColorEdit4(" color1", (float*)&Colors::playerline, ImGuiColorEditFlags_NoLabel);
															}
															ImGui::Text("Thickness ");
															ImGui::SameLine();
															ImGui::SliderFloat("Line size", &Setting::plinesize, 0.100f, 3.00f);

															
															//ImGui::EndTabItem();
															

															ImGui::EndTabItem();
														}
													}
													ImGui::SameLine();
													if (Setting::Distancee)
													{
														if (ImGui::BeginTabItem("Distance")) {
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
														    ImGui::Text("Distance color ");
														    ImGui::SameLine();
														    ImGui::ColorEdit4(" color11", (float*)&Colors::enemy, ImGuiColorEditFlags_NoLabel);
														
														    ImGui::Text("Thickness ");
														    ImGui::SameLine();
														    ImGui::SliderInt("Distance size", &dissize, 0, 25);

															ImGui::EndTabItem();
														}
													}
													ImGui::SameLine();
													if (Setting::phealth)
													{
														if (ImGui::BeginTabItem("Health")) {

															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();

															ImGui::Text("Display mode");
															ImGui::SameLine();
															const char* Emu2[] = { "Show as BAR", "Show as TEXT" }; 

															const char* combo_label = Emu2[hpbt];
															if (ImGui::BeginCombo(" loll1", combo_label, ImGuiComboFlags_HeightSmall))
															{
																for (int n = 0; n < IM_ARRAYSIZE(Emu2); n++)
																{
																	const bool is_selected = (hpbt == n);
																	if (ImGui::Selectable(Emu2[n], is_selected))
																		hpbt = n;
																	if (is_selected)
																		ImGui::SetItemDefaultFocus();
																}
																if (hpbt == 0);
																//Setting::skele = true;
																else if (hpbt == 1);
																//Setting::skele = false;


																ImGui::EndCombo();
															}

																if (hpbt == 1)
																{
																	ImGui::Text("Text color ");
																	ImGui::SameLine();
																	ImGui::ColorEdit4(" colorhp", (float*)&Colors::hpt, ImGuiColorEditFlags_NoLabel);

																	ImGui::Text("Text size ");
																	ImGui::SameLine();
																	ImGui::SliderInt("Health size", &hp, 0, 25);
																}
															

															ImGui::EndTabItem();
														}
													}
													ImGui::SameLine();
													if (Setting::pcorner)
													{
														if (ImGui::BeginTabItem("Box")) {

															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();
															ImGui::Spacing();

															ImGui::Text("Display mode");
															ImGui::SameLine();
															const char* Emu3[] = { "4 edges", "Rectangle" };

															const char* combo_label = Emu3[boxe];
															if (ImGui::BeginCombo(" loll11", combo_label, ImGuiComboFlags_HeightSmall))
															{
																for (int n = 0; n < IM_ARRAYSIZE(Emu3); n++)
																{
																	const bool is_selected = (boxe == n);
																	if (ImGui::Selectable(Emu3[n], is_selected))
																		boxe = n;
																	if (is_selected)
																		ImGui::SetItemDefaultFocus();
																}
																if (boxe == 0);
																//Setting::skele = true;
																else if (boxe == 1);
																//Setting::skele = false;


																ImGui::EndCombo();
															}
															if (boxe == 0)
															{
																ImGui::Text("Thickness ");
																ImGui::SameLine();
																ImGui::SliderFloat("###1", &Setting::pcornersize, 0.100f, 2.00f);
															}
															else if (boxe == 1)
															{
																ImGui::Text("Thickness ");
																ImGui::SameLine();
																ImGui::SliderFloat("###2", &Setting::pfullboxsize, 0.100f, 2.00f);
															}

															ImGui::EndTabItem();
														}
													}
													ImGui::SameLine();
													if (Setting::dots)
													{
														if (ImGui::BeginTabItem("Radar")) {


															ImGui::EndTabItem();
														}
													}

												}
												ImGui::EndTabBar();
												
												
											}
											ImGui::EndChild();

											ImGui::EndChild();
											ImGui::EndTabItem();
										}
										//ImGui::SameLine();
										if (Setting::graned)
										{
											if (ImGui::BeginTabItem("Grenade")) {

												/*ImGui::Spacing();
												ImGui::Spacing();
												ImGui::Spacing();
												ImGui::Spacing();
												ImGui::Spacing();
												ImGui::Spacing();
												ImGui::Spacing();*/
												ImGui::Checkbox("Grenade warning", &Setting::grw);
												ImGui::Checkbox("Molotow warning", &Setting::molow);

												ImGui::EndTabItem();
											}
										}
										//ImGui::SameLine();
										if (Setting::Vehicle)
										{
											if (ImGui::BeginTabItem("Vehicle")) {

												/*ImGui::Spacing();
												ImGui::Spacing();
												ImGui::Spacing();
												ImGui::Spacing();
												ImGui::Spacing();
												ImGui::Spacing();
												ImGui::Spacing();*/
												ImGui::Text("Text color ");
												ImGui::SameLine();
												ImGui::ColorEdit4(" vehiclec", (float*)&Colors::vehicle, ImGuiColorEditFlags_NoLabel);

												ImGui::Text("Text size ");
												ImGui::SameLine();
												ImGui::SliderInt("vehicle size", &vehisize, 0, 25);


												ImGui::EndTabItem();
											}
										}

										//ImGui::SameLine();
										if (Setting::Item)
										{
											if (ImGui::BeginTabItem("Items")) {
												ImGui::BeginChild("###1");
												//ImGui::SetCursorPos(ImVec2(0, 5));
												//ImGui::BeginChild("###121", ImVec2(540, 468), true, 0);
												{
													if (ImGui::BeginTabBar("BOSS INER1")) {

														if (ImGui::BeginTabItem("Weapon")) {
															ImGui::BeginChild("###1211", ImVec2(535, 450), true, 0);
															{

																ImGui::Checkbox("M416", &Setting::Esp_Item_M416);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("M416", (float*)&weapon::m16, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("AKM", &Setting::Esp_Item_AKM);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("AKM", (float*)&weapon::AKM, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("SCAR-L", &Setting::Esp_Item_SCARL);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("SCAR-L", (float*)&weapon::scarl, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("M762", &Setting::Esp_Item_M762);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("M762", Setting::Esp_Item_M762_Color, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("DP28", &Setting::Esp_Item_DP28);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("DP28", Setting::Esp_Item_DP28_Color, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("AWM", &Setting::Esp_Item_Awm);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("AMW", (float*)&weapon::AWM, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("M24", &Setting::Esp_Item_M24);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("M24", (float*)&weapon::M24, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("KAR98", &Setting::Esp_Item_Kar98k);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("kar98", (float*)&weapon::kar98, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("Flare Gun", &Setting::Esp_Item_FlareGun);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("Flare", (float*)&weapon::Flaregun, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("G36C", &Setting::Esp_Item_G36C);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("G36C", (float*)&Setting::Esp_Item_G36C_Color, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("QBZ", &Setting::Esp_Item_QBZ);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("QBZ", (float*)&Setting::Esp_Item_QBZ_Color, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("QBU", &Setting::Esp_Item_QBU);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("QBU", (float*)&Setting::Esp_Item_QBU_Color, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("SLR", &Setting::Esp_Item_SLR);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("SLR", (float*)&Setting::Esp_Item_SLR_Color, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("SKS", &Setting::Esp_Item_SKS);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("SKS", (float*)&Setting::Esp_Item_SKS_Color, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("Mini14", &Setting::Esp_Item_Mini14);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("Mini14", (float*)&Setting::Esp_Item_Mini14_Color, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("PP19", &Setting::Esp_Item_PP19);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("PP19", (float*)&Setting::Esp_Item_PP19_Color, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("Tommy Gun", &Setting::Esp_Item_TommyGun);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("Tommy", (float*)&Setting::Esp_Item_TommyGun_Color, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("MP5K", &Setting::Esp_Item_MP5K);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("MP5K", (float*)&Setting::Esp_Item_MP5K_Color, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("UMP9", &Setting::Esp_Item_UMP9);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("UMP9", (float*)&Setting::Esp_Item_UMP9_Color, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("Vector", &Setting::Esp_Item_Vector);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("Vector", (float*)&Setting::Esp_Item_Vector_Color, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("Uzi", &Setting::Esp_Item_Uzi);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("Uzi", (float*)&Setting::Esp_Item_Uzi_Color, ImGuiColorEditFlags_NoLabel);
																ImGui::Checkbox("Mk47-Mutant", &Setting::Esp_Item_Mk47Mutant);
																ImGui::SameLine();
																ImGui::SetCursorPosX({ 170 });
																ImGui::ColorEdit4("Mk47-Mutant", (float*)&Setting::Esp_Item_Mk47Mutant_Color, ImGuiColorEditFlags_NoLabel);



															}//, ImGuiColorEditFlags_NoLabel);
															ImGui::EndChild();

															ImGui::EndTabItem();
														}

														//ImGui::SameLine();

														
														if (ImGui::BeginTabItem("Grenade")) {
															ImGui::BeginChild("##2", ImVec2(125, 20), true, 0);
															ImGui::Checkbox("Frag", &Setting::Esp_Item_Frag);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Frag", Setting::Esp_Item_Frag_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("Smoke", &Setting::Esp_Item_Smoke);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Smoke", Setting::Esp_Item_Smoke_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("Molotof", &Setting::Esp_Item_Molotof);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Molotof", Setting::Esp_Item_Molotof_Color, ImGuiColorEditFlags_NoLabel);

															ImGui::EndChild();
															ImGui::EndTabItem();

														}

														//ImGui::SameLine();


														if (ImGui::BeginTabItem("Health")) {

															ImGui::Checkbox("Med Kit", &Setting::Esp_Item_MedKit);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Med Kit", Setting::Esp_Item_MedKit_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("First Aid Kit", &Setting::Esp_Item_FirstAidKit);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("First Aid Kit", Setting::Esp_Item_FirstAidKit_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("Painkiller", &Setting::Esp_Item_Painkiller);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Painkiller", Setting::Esp_Item_Painkiller_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("Energy Drink", &Setting::Esp_Item_EnergyDrink);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Energy Drink", Setting::Esp_Item_EnergyDrink_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("Adrenaline Syringe", &Setting::Esp_Item_AdrenalineSyringe);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Adrenaline Syringe", Setting::Esp_Item_AdrenalineSyringe_Color, ImGuiColorEditFlags_NoLabel);



															ImGui::EndTabItem();
														}

														//ImGui::SameLine();

														if (ImGui::BeginTabItem("Bagpack")) {

															ImGui::Checkbox("Bag 1", &Setting::Esp_Item_Bag1);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Bag 1", Setting::Esp_Item_Bag1_Color, ImGuiColorEditFlags_NoLabel);

															ImGui::Checkbox("Bag 2", &Setting::Esp_Item_Bag2);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Bag 2", Setting::Esp_Item_Bag2_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("Bag 3", &Setting::Esp_Item_Bag3);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Bag 3", Setting::Esp_Item_Bag3_Color, ImGuiColorEditFlags_NoLabel);

															ImGui::EndTabItem();
														}

														//ImGui::SameLine();


														if (ImGui::BeginTabItem("Helmate")) {


															ImGui::Checkbox("Helmet 1", &Setting::Esp_Item_Helmet1);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Helmet 1", Setting::Esp_Item_Helmet1_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("Helmet 2", &Setting::Esp_Item_Helmet2);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Helmet 2", Setting::Esp_Item_Helmet2_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("Helmet 3", &Setting::Esp_Item_Helmet3);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Helmet 3", Setting::Esp_Item_Helmet3_Color, ImGuiColorEditFlags_NoLabel);


															ImGui::EndTabItem();
														}

														//ImGui::SameLine();

														if (ImGui::BeginTabItem("Armor")) {

															ImGui::Checkbox("Armor 1", &Setting::Esp_Item_Armor1);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Armor 1", Setting::Esp_Item_Armor1_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("Armor 2", &Setting::Esp_Item_Armor2);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Armor 2", Setting::Esp_Item_Armor2_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("Armor 3", &Setting::Esp_Item_Armor3);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Armor 3", Setting::Esp_Item_Armor3_Color, ImGuiColorEditFlags_NoLabel);

															ImGui::EndTabItem();
														}

														//ImGui::SameLine();

														if (ImGui::BeginTabItem("Ammo")) {

															ImGui::Checkbox("7.62mm", &Setting::Esp_Item_762mm);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("762mm", (float*)&Setting::Esp_Item_762mm_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("5.56mm", &Setting::Esp_Item_556mm);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("556mm", (float*)&Setting::Esp_Item_556mm_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("9mm", &Setting::Esp_Item_9mm);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("9mm", (float*)&Setting::Esp_Item_9mm_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("45ACP", &Setting::Esp_Item_45ACP);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("45ACP", (float*)&Setting::Esp_Item_45ACP_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("AWM Ammo", &Setting::Esp_Item_Awmimo);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("awm ammo", (float*)&weapon::AWMimmo, ImGuiColorEditFlags_NoLabel);

															ImGui::EndTabItem();
														}

														//ImGui::SameLine();

														if (ImGui::BeginTabItem("Attachments")) {

															ImGui::Checkbox("Holo", &Setting::Esp_Item_Holo);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Holo", (float*)&Setting::Esp_Item_Holo_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("x2", &Setting::Esp_Item_x2);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("2X", Setting::Esp_Item_x2_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("x3", &Setting::Esp_Item_x3);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("3X", Setting::Esp_Item_x3_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("x4", &Setting::Esp_Item_x4);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("4X", Setting::Esp_Item_x4_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("x6", &Setting::Esp_Item_x6);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("6X", Setting::Esp_Item_x6_Color, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("x8", &Setting::Esp_Item_x8);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("8X", Setting::Esp_Item_x8_Color, ImGuiColorEditFlags_NoLabel);


															ImGui::EndTabItem();
														}

														//ImGui::SameLine();

														if (ImGui::BeginTabItem("Others")) {

															ImGui::Checkbox("Dead box", &Setting::deadbox);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Dead Box ", (float*)&Colors::deadbox, ImGuiColorEditFlags_NoLabel);
															ImGui::Checkbox("Box item list", &Setting::playerdeadbox);
															ImGui::SameLine();
															ImGui::SetCursorPosX({ 170 });
															ImGui::ColorEdit4("Dead Boxi ", (float*)&Colors::deadboxitem, ImGuiColorEditFlags_NoLabel);

															ImGui::EndTabItem();
														}



													}
													ImGui::EndTabBar();


												}
												//ImGui::EndChild();

												ImGui::EndChild();
												ImGui::EndTabItem();
											}
											ImGui::SameLine();
											
										}
										/*ImGui::SameLine();
										if (ImGui::BeginTabItem("Teammate")) {



											ImGui::EndTabItem();
										}*/
									}
									ImGui::EndTabBar();


								}
								ImGui::EndChild();

							}
							ImGui::EndChild();
						}


						if (Settings::Tab == 3)
						{
							
							//ImGui::SetCursorPos(ImVec2(10, 10));
							ImGui::BeginChild("##2", ImVec2(793, 535), true, 0);
							{

								ImGui::SetCursorPos(ImVec2(5, 5));
								ImGui::BeginChild("###1", ImVec2(230, 520), true, 0);
								{
									ImGui::Checkbox(" Aimbot", &Setting::Aimbot);
									ImGui::Checkbox(" Marco", &marco1);
									

								}
								ImGui::EndChild();
								
								ImGui::SetCursorPos(ImVec2(238, 5));
								ImGui::BeginChild("###2", ImVec2(548, 520), true, 0);
								{
									if (ImGui::BeginTabBar("Slient aim")) {
										if (Setting::engine == 1)
										{
											if (ImGui::BeginTabItem("Slient aim")) {
												ImGui::Text("Pickup a Gun to active Bullet Tracking, no need to fire, press P to fix if not work");
												ImGui::Checkbox("Auto repair Slient Aim when detect game change.", &nothingm);
												ImGui::Checkbox("Enable aimbot also", &nothinga);
												ImGui::SameLine();
												ImGui::Checkbox("Enable Bullet Tracking (UNSAFE)", &Setting::MagicBullet);

												ImGui::EndTabItem();
											}
										}
										//ImGui::SameLine();
										if (Setting::Aimbot)
										{
											if (ImGui::BeginTabItem("Aimbot")) {

												ImGui::Text("Aimbot bone");
												ImGui::SameLine();

												const char* aimb[] = { "Head", "Body", "Pelvis" };

												const char* combo_label = aimb[Setting::curraim];

												if (ImGui::BeginCombo(" AimcPositon", combo_label, ImGuiComboFlags_HeightSmall))
												{
													for (int n = 0; n < IM_ARRAYSIZE(aimb); n++)
													{
														const bool is_selected = (Setting::curraim == n);
														if (ImGui::Selectable(aimb[n], is_selected))
															Setting::curraim = n;
														if (is_selected)
															ImGui::SetItemDefaultFocus();
													}


													ImGui::EndCombo();
												}

												ImGui::Text("Aimbot key");
												ImGui::SameLine();
												ImGui::Hotkey("##AimbotKey ", &Setting::AimbotKey, ImVec2(180.0f, 24));


												const char* enginetype[] = { "Mouse Event","Silent Aimbot" };

												const char* enginelabel = enginetype[Setting::engine];

												ImGui::Text("Aim method");
												ImGui::SameLine();
												if (ImGui::BeginCombo(" AimcEngine", enginelabel, ImGuiComboFlags_HeightSmall))
												{
													for (int n = 0; n < IM_ARRAYSIZE(enginetype); n++)
													{
														const bool is_selectedd = (item_current_Aim == n);
														if (ImGui::Selectable(enginetype[n], is_selectedd))
															Setting::engine = n;
														if (is_selectedd)
															ImGui::SetItemDefaultFocus();
													}

													ImGui::EndCombo();
												}

												ImGui::Text("Aim FOV");
												ImGui::SameLine();
												ImGui::SliderFloat("###fovFOVsize", &Setting::fovcircleredus, 1.0f, 2000.0f);
												ImGui::Text("Aim speed");
												ImGui::SameLine();
												ImGui::SliderFloat("###fovFOVspeed", &Setting::Aimspeed, 0.0f, 15.0f);
												ImGui::Checkbox("Show FOV circle", &Setting::fovcircle);
												ImGui::Checkbox("Aim knocked Enemy", &Setting::knocked);

												ImGui::Text(" Aim Bot key:");
												ImGui::SameLine();
												ImGui::Hotkey("###Enable ", &Setting::EnableKey, ImVec2(180.0f, 24));

												ImGui::Separator();
												ImGui::Checkbox("Draw current aiming enemy's line", &Setting::MAgicline);

												ImGui::EndTabItem();
											}
										}
										//ImGui::SameLine();
										int marco = 0;
										if (marco1)
										{
											if (ImGui::BeginTabItem("Marco")) {

												ImGui::Text("Marco value");
												ImGui::SameLine();

												ImGui::SliderInt("###marco", &marco, 1, 15);

												ImGui::EndTabItem();
											}
										}

									}
									ImGui::EndTabBar();


								}
								ImGui::EndChild();

							}
							ImGui::EndChild();
						}


						if (Settings::Tab == 4)
						{
							//ImGui::SetCursorPos(ImVec2(10, 10));
							ImGui::BeginChild("##2", ImVec2(793, 535), true, 0);
							{

								ImGui::SetCursorPos(ImVec2(5, 5));
								ImGui::BeginChild("###1", ImVec2(230, 520), true, 0);
								{
									ImGui::Checkbox(" Magic", &Setting::MagicBullet);
									ImGui::Checkbox(" Fast Run", &Setting::fastrun);
									ImGui::Checkbox(" Fast Run v2", &Setting::fastrun2);
									ImGui::Checkbox(" Fast Run v3(*)", &Setting::fastrun3);
									ImGui::Checkbox(" Fast Run v4(*)", &Setting::fastrun3);
									ImGui::Checkbox(" Fast car", &Setting::speedcar);
									ImGui::Checkbox(" Fly car", &Setting::carfly);
									ImGui::Checkbox(" Fast parachute", &Setting::fastland);
									ImGui::Checkbox(" High jump", &Setting::fly);
									ImGui::Checkbox(" God view", &Setting::godview);
									ImGui::Checkbox(" Disable memory check", &Setting::disablemc);
									ImGui::Checkbox(" Vehicle teleport(*)", &Setting::vehicletele);
									ImGui::Checkbox(" No grass", &Setting::nograss);
									ImGui::Checkbox(" No recoil(*)", &Setting::recoil);
									ImGui::Checkbox(" Instant hit", &Setting::instanthit);
									ImGui::Checkbox(" Mod skin", &Setting::modskin);
									ImGui::Checkbox(" X Effect", &Setting::MagicX);
									

								}
								ImGui::EndChild();

								ImGui::SetCursorPos(ImVec2(238, 5));
								ImGui::BeginChild("###2", ImVec2(548, 520), true, 0);
								{
									if (Setting::MagicBullet)
									{
										if (ImGui::TreeNodeEx("Magic bullet"))
										{
											ImGui::Indent();

											ImGui::SliderInt("####1", &Setting::magicv, 0, 50);


											ImGui::Unindent();
											ImGui::TreePop();
										}
									}

									if (Setting::fastrun)
									{
										if (ImGui::TreeNodeEx("Fast run"))
										{
											ImGui::Indent();

											ImGui::SliderInt("####2", &Setting::fastrv, 1.0f, 20.0f);
											ImGui::Text("Fast run key");
											ImGui::SameLine();
											ImGui::Hotkey("##fastrunKey ", &Setting::fastrunkey, ImVec2(180.0f, 24));


											ImGui::Unindent();
											ImGui::TreePop();
										}
									}

									if (Setting::speedcar)
									{
										if (ImGui::TreeNodeEx("Fast car"))
										{
											ImGui::Indent();

											ImGui::SliderInt("####3", &Setting::carsv, 1.0f, 600.0f);


											ImGui::Unindent();
											ImGui::TreePop();
										}
									}

									if (Setting::carfly)
									{
										if (ImGui::TreeNodeEx("Fly car"))
										{
											ImGui::Indent();

											ImGui::SliderInt("####4", &Setting::flycarv, 1.0f, 50000.0f);


											ImGui::Unindent();
											ImGui::TreePop();
										}
									}

									if (Setting::instanthit)
									{
										if (ImGui::TreeNodeEx("Instant hit"))
										{
											ImGui::Indent();

											ImGui::SliderInt("####5", &Setting::instantv, 1.0f, 1000000.0f);


											ImGui::Unindent();
											ImGui::TreePop();
										}
									}



								}
								ImGui::EndChild();

							}
							ImGui::EndChild();
						}


						if (Settings::Tab == 5)
						{
							//ImGui::SetCursorPos(ImVec2(10, 10));
							ImGui::BeginChild("##5", ImVec2(793, 535), true, 0);
							{

								ImGui::BeginChild("##1", ImVec2(390, 125), true, 0);
								{
									ImGui::Checkbox("Text border  |  Update tick:", &Setting::borderlo);
									ImGui::Separator();

									if (ImGui::Button("Save Setting", { 185.f,25.f }))
									{

										LoadConfiggg("C:\\BOSSconfig.ini");
									}
									ImGui::SameLine();
									if (ImGui::Button("Load Setting", { 185.f,25.f }))
									{


									ImGui::LoadIniSettingsFromDisk("C:\\BOSSconfig.ini");
										WriteConfigurate("C:\\BOSSconfig.ini");

									}
									ImGui::Separator();

								}
								ImGui::EndChild();

								ImGui::SameLine();

								ImGui::BeginChild("##2", ImVec2(390, 125), true, 0);
								{
									if (ImGui::Button("Unload hack", ImVec2(370, 105)))
									{
										unload = true;
										
										
									}

								}
								ImGui::EndChild();

							}
							ImGui::EndChild();
						}
					}

					ImGui::End();
				}
			}
		}

		if (Setting::ShowMenu2)
		{
			DrawMenu2();
		}

		

			if (login)
			{
				if (unload)
				{
					ImGuiIO& Io = ImGui::GetIO();

					//ImGui::SetNextWindowSize(ImVec2(400.0f, 115.0f));
					ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.5f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
					ImGui::SetNextWindowSize(ImVec2(260.0f, 80.0f));
					if (ImGui::Begin("Unload hack", 0, Flags2))
					{
						imguipp::CenterText("Are you sure ?", 0, 0);
						if (ImGui::Button("OK", { 122.f,21.f }))
						{
							exit(0);
						}
						ImGui::SameLine();
						if (ImGui::Button("Cancel", { 122.f,21.f }))
						{
							unload = false;
						}

						ImGui::End();
					}
				}
			  
				time_t t; // t passed as argument in function time()
				struct tm* tt; // decalring variable for localtime()
				time(&t); //passing argument to time()
				tt = localtime(&t);
				//cout << "Current Day, Date and Time is = " << asctime(tt);
				tim = asctime(tt);
				
				
					

					ViewMatrix = Utility::ReadMemoryEx<D3DMATRIX>(Utility::ReadMemoryEx<DWORD>(Utility::ReadMemoryEx<DWORD>(Data::ViewMatrixBase) + 0x20) + 0x200);
					currIndex = Memory::AimFindBestTarget();
					for (AActor& AActor : Data::AActorList)
					{
						if (!Algorithm::WorldToScreenPlayer(AActor.Position, Screen, &Distance, ViewMatrix)) continue;
						if (Distance < 350)
						{
							temp = AActor.Name.c_str();// +"   " + to_string(Distance) + "M ";
							teamids = AActor.TeamId;
							col = ImColor(teamids, teamids, teamids, 255);
							// linescolors = { teamids  ,  teamids , teamids ,1.0f };
							switch (teamids)
							{

							case 1:
								linescolors = { 1.000f, 0.033f, 0.129f, 1.000f };
								break;
							case 2:
								linescolors = { 1.000f, 1.000f, 0.000f, 1.000f };
								break;
							case 3:
								linescolors = { 0.866f, 0.128f, 0.081f, 1.000f };
								break;
							case 4:
								linescolors = { 0.844f, 0.066f, 1.000f, 1.000f };
								break;
							case 5:
								linescolors = { 0.737f, 1.000f, 0.000f, 1.000f };
								break;
							case 6:
								linescolors = { 0.000f, 1.000f, 0.964f, 1.000f };
								break;
							case 7:
								linescolors = { 0.610f, 0.190f, 1.000f, 1.000f };
								break;
							case 8:
								linescolors = { 1.000f, 0.100f, 0.401f, 1.000f };
								break;
							case 9:
								linescolors = { 0.610f, 0.190f, 1.000f, 1.000f };
								break;
							case  10:
								linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };
								break;
							case 11:
								linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };
								break;
							case 12:
								linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };
								break;
							case 13:
								linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };
								break;
							case 14:
								linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };
								break;
							case 15:
								linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };
								break;
							case 16:
								linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };
								break;
							case 17:
								linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };
								break;
							case 18:
								linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };
								break;
							case 19:
								linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };
								break;
							case  20:
								linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };
								break;
							case 21:
								linescolors = { 0.126f, 0.430f, 1.000f, 1.000f };
								break;
							case 22:
								linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
								break;
							case 23:
								linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
								break;
							case 24:
								linescolors = { 1.000f, 0.859f, 0.251f, 1.000f };
								break;
							case 25:
								linescolors = { 0.053f, 0.355f, 1.000f, 1.000f };
								break;
							case 26:
								linescolors = { 1.000f, 0.70f, 0.000f, 1.000f };
								break;
							case 27:
								linescolors = { 1.000f, 1.000f, 0.000f, 1.000f };
								break;
							case 28:
								linescolors = { 0.866f, 0.128f, 0.081f, 1.000f };
								break;
							case 29:
								linescolors = { 0.844f, 0.066f, 1.000f, 1.000f };
								break;
							case 30:
								linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };
								break;
							case 31:
								linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };
								break;
							case 32:
								linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };
								break;
							case 33:
								linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };
								break;
							case 34:
								linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };
								break;
							case 35:
								linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };
								break;
							case 36:
								linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };
								break;
							case 37:
								linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };
								break;
							case 38:
								linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };
								break;
							case 39:
								linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };
								break;
							case  40:
								linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };
								break;
							case 41:
								linescolors = { 0.126f, 0.430f, 1.000f, 1.000f };
								break;
							case 42:
								linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
								break;
							case 43:
								linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
								break;
							case 44:
								linescolors = { 1.000f, 0.859f, 0.251f, 1.000f };
								break;
							case 45:
								linescolors = { 0.053f, 0.355f, 1.000f, 1.000f };
								break;
							case 46:
								linescolors = { 0.126f, 0.430f, 1.000f, 1.000f };
								break;
							case 47:
								linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
								break;
							case 48:
								linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
								break;
							case 49:
								linescolors = { 1.000f, 0.859f, 0.251f, 1.000f };
								break;
							case 50:
								linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };
								break;
							case 51:
								linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };
								break;
							case 52:
								linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };
								break;
							case 53:
								linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };
								break;
							case 54:
								linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };
								break;
							case 55:
								linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };

								break;
							case 56:
								linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };

								break;
							case 57:
								linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };

								break;
							case 58:
								linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };

								break;
							case 59:
								linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };
								break;
							case  60:
								linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };

								break;
							case 61:
								linescolors = { 0.399f, 0.720f, 0.122f, 1.000f };

								break;
							case 62:
								linescolors = { 1.000f, 0.960f, 0.560f, 1.000f };

								break;
							case 63:
								linescolors = { 0.874f, 0.301f, 0.068f, 1.000f };

								break;
							case 64:
								linescolors = { 0.110f, 0.845f, 0.174f, 1.000f };

								break;
							case 65:
								linescolors = { 0.802f, 0.267f, 0.077f, 1.000f };

								break;

							case 66:
								linescolors = { 0.129f, 0.774f, 0.986f, 1.000f };

								break;
							case 67:
								linescolors = { 0.168f, 0.792f, 0.792f, 1.000f };

								break;
							case 68:
								linescolors = { 1.000f, 0.237f, 0.945f, 1.000f };

								break;
							case 69:
								linescolors = { 1.000f, 0.126f, 0.430f, 1.000f };

								break;
							case  70:
								linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };

								break;
							case 71:
								linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };

								break;
							case 72:
								linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };

								break;
							case 73:
								linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };

								break;
							case 74:
								linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };

								break;
							case 75:
								linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };

								break;
							case 76:
								linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };

								break;
							case 77:
								linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };

								break;
							case 78:
								linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };

								break;
							case 79:
								linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };

								break;
							case 80:
								linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };

								break;
							case 81:
								linescolors = { 1.000f, 0.033f, 0.129f, 1.000f };

								break;
							case 82:
								linescolors = { 1.000f, 0.033f, 0.290f, 1.000f };

								break;
							case 83:
								linescolors = { 1.000f, 0.033f, 0.450f, 1.000f };

								break;
							case 84:
								linescolors = { 1.000f, 0.033f, 0.578f, 1.000f };

								break;
							case 85:
								linescolors = { 1.000f, 0.033f, 0.802f, 1.000f };

								break;

							case 86:
								linescolors = { 0.973f, 0.033f, 1.000f, 1.000f };

								break;
							case 87:
								linescolors = { 0.781f, 0.033f, 1.000f, 1.000f };

								break;
							case 88:
								linescolors = { 0.557f, 0.033f, 1.000f, 1.000f };

								break;
							case 89:
								linescolors = { 0.033f, 0.375f, 1.000f, 1.000f };

								break;
							case  90:
								linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };

								break;
							case 91:
								linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };

								break;
							case 92:
								linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };

								break;
							case 93:
								linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };

								break;
							case 94:
								linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };

								break;
							case 95:
								linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };

								break;

							case 96:
								linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };

								break;
							case 97:
								linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };

								break;
							case 98:
								linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };

								break;
							case 99:
								linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };

								break;
							case  100:
								linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };

								break;
							default:

								linescolors = Colors::playerline;
								bonescolors = Colors::playerbone;
								fullboxcolor = Colors::playerbox;
								cornerboxcolor = Colors::playercorner;
								break;
							}

							

							if (Setting::dots)
							{
								std::string lol1 = "Player";
								if (Screen.X > DX11Window::Width && Screen.Y > 0 && Screen.Y < DX11Window::Height)//Right
								{
									//DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - 20, Screen.Y + Screen.Z, 7, 10, ImColor(0.0f, 0.f, 0.f, 0.200f));
									//DX11::ImGui_DX11::DrawCircle(DX11Window::Width - 20, Screen.Y + Screen.Z, 7, Setting::dotss, 4.0f);
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, lol1, DX11Window::Width - 20, Screen.Y + Screen.Z, DX11::ImGui_DX11::Color::Green, false);
									//DX11::ImGui_DX11::DrawFilledRectangle(DX11Window::Width - 20, Screen.Y + Screen.Z, 50, 30, ImColor(0.0f, 0.f, 0.f, 0.200f));

								}
								if (Screen.X < 0 && Screen.Y  >0 && Screen.Y < DX11Window::Height)//Left
								{

									//DX11::ImGui_DX11::DrawCircle(20, Screen.Y + Screen.Z, 7, Setting::dotss, 4.0f);
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, lol1, 20, Screen.Y + Screen.Z, DX11::ImGui_DX11::Color::Green, false);

								}
								if (Screen.Y < 0 && Screen.X>0 && Screen.X < DX11Window::Width)//Top
								{
									//DX11::ImGui_DX11::DrawCircle(Screen.X, 20, 7, Setting::dotss, 4.0f);
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, lol1, Screen.X, 20, DX11::ImGui_DX11::Color::Green, false);

								}
								if (Screen.Y > DX11Window::Height && Screen.X > 0 && Screen.X < DX11Window::Width)//Bottom
								{
									//DX11::ImGui_DX11::DrawCircle(Screen.X, DX11Window::Height - 20, 7, Setting::dotss, 4.0f);
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, lol1, Screen.X, DX11Window::Height - 20, DX11::ImGui_DX11::Color::Green, false);

								}
								if (Screen.X < 0 && Screen.Y < 0)//top left
								{
									//DX11::ImGui_DX11::DrawCircle(20, 20, 7, Setting::dotss, 4.0f);
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, lol1, 20, 20, DX11::ImGui_DX11::Color::Green, false);

								}
								if (Screen.X > DX11Window::Width && Screen.Y > DX11Window::Height)//bottom right
								{
									//DX11::ImGui_DX11::DrawCircle(DX11Window::Width - 20, DX11Window::Height - 20, 7, Setting::dotss, 4.0f);
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, lol1, DX11Window::Width - 20, DX11Window::Height - 20, DX11::ImGui_DX11::Color::Green, false);

								}
								if (Screen.X > DX11Window::Width && Screen.Y < 0)//top right
								{
									//DX11::ImGui_DX11::DrawCircle(DX11Window::Width - 20, 20, 7, Setting::dotss, 4.0f);
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, lol1, DX11Window::Width - 20, 20, DX11::ImGui_DX11::Color::Green, false);

								}
								if (Screen.X<0 && Screen.Y >DX11Window::Width)//bottom left
								{
									//DX11::ImGui_DX11::DrawCircle(20, DX11Window::Height - 20, 7, Setting::dotss, 4.0f);
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, lol1, 20, DX11Window::Height - 20, DX11::ImGui_DX11::Color::Green, false);

								}
							}


							dist = std::to_string(Distance) + "M";


							if (!AActor.IsBot)
					{
						temp = "[" + AActor.Nation + "]   " + AActor.Name.c_str();
					}
					else
					{
						temp = AActor.Name.c_str();
					}
					teamids = AActor.TeamId;

                     col = ImColor(teamids, teamids, teamids,255 );
							//{

							//	if (Setting::pname)
							//	{
							//		if (Setting::style1)
							//		{


							//			DX11::ImGui_DX11::DrawFilledRectangle(Screen.X + 55, Screen.Y - 15, 120, 13, ImColor(0.0f, 0.f, 0.f, 0.200f));
							//			if (AActor.Health <= 0)
							//			{
							//				DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 12, temp, Screen.X - 60, Screen.Y - 28, DX11::ImGui_DX11::Color::Red, false);
							//			}
							//			else
							//			{
							//				DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 12, temp, Screen.X - 60, Screen.Y - 28, Colors::nam, false);
							//				//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 12, dist, Screen.X + 30, Screen.Y - 28, Colors::enemy, false);

							//			}
							//		}
							//		if (Setting::style2)
							//		{

							//			Text = AActor.Name + " " + to_string(Distance) + "M";


							//			if (AActor.Health <= 0)
							//			{
							//				DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 12, Text, Screen.X, (Screen.Y + Screen.Z), DX11::ImGui_DX11::Color::Red, true);
							//			}
							//			else
							//			{

							//				DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 12, Text, Screen.X, (Screen.Y + Screen.Z), Colors::nam, true);

							//			}



							//		}

							//	}
							//	if (Setting::Distancee)
							//	{
							//		if (Setting::style1)
							//		{
							//			DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 12, dist, Screen.X + 30, Screen.Y - 28, Colors::enemy, false);

							//		}
							//		
							//	}
							//	if (Setting::phealth)
							//	{
							//		if (Setting::style1)
							//		{
							//			DX11::ImGui_DX11::DrawBlood(Screen.X - 65, Screen.Y - 15, 120, 4.0, AActor.Health);

							//		}


							//		if (Setting::style2)
							//		{
							//			DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5), DX11::ImGui_DX11::Color::Black);

							//			if (AActor.Health > 70.0)
							//			{
							//				DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Green);
							//			}
							//			if (AActor.Health > 30.0 && AActor.Health <= 70.0)
							//			{
							//				DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Yellow);
							//			}
							//			if (AActor.Health > 0.0 && AActor.Health <= 30.0)
							//			{
							//				DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Red);
							//			}
							//		}
							//	}
							//	if (Setting::pline)
							//	{
							//		if (Setting::style1)
							//		{
							//			DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 30, Colors::botline, Setting::blinesize);
							//		}
							//		if (Setting::style2)
							//		{
							//			DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 28, Colors::botline, Setting::blinesize);

							//		}
							//	}
							//	if (Setting::pfullbox)
							//	{

							//		DX11::ImGui_DX11::DrawRectangle(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Colors::botbox, Setting::bfullboxsize);


							//	}
							//	if (Setting::pcorner)
							//	{
							//		DX11::ImGui_DX11::CornerBox(Screen.X - Screen.Z / 4 - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting::bcornersize, popcorn / 2, Colors::botcorner);



							//	}
							//	if (Setting::Bone)
							//	{


							//		if (Setting::playerBone)
							//		{
							//			HeadPos = AActor.HeadPos;
							//			HeadPos.Z += 7;
							//			if (!Algorithm::WorldToScreenBone(ViewMatrix, HeadPos, Head, &Distance)) continue;
							//			if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.ChestPos, Chest, &Distance)) continue;
							//			if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.PelvisPos, Pelvis, &Distance)) continue;
							//			if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lSholderPos, lSholder, &Distance)) continue;
							//			if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rSholderPos, rSholder, &Distance)) continue;
							//			if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lElbowPos, lElbow, &Distance)) continue;
							//			if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rElbowPos, rElbow, &Distance)) continue;
							//			if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lWristPos, lWrist, &Distance)) continue;
							//			if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rWristPos, rWrist, &Distance)) continue;
							//			if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lThighPos, lThigh, &Distance)) continue;
							//			if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rThighPos, rThigh, &Distance)) continue;
							//			if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lKneePos, lKnee, &Distance)) continue;
							//			if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rKneePos, rKnee, &Distance)) continue;
							//			if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lAnklePos, lAnkle, &Distance)) continue;
							//			if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rAnklePos, rAnkle, &Distance)) continue;

							//			DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, Colors::botbone, Setting::bbonesize);
							//			DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, Colors::botbone, Setting::bbonesize);
							//			DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, Colors::botbone, Setting::bbonesize);
							//			DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, Colors::botbone, Setting::bbonesize);
							//			DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, Colors::botbone, Setting::bbonesize);
							//			DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, Colors::botbone, Setting::bbonesize);
							//			DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, Colors::botbone, Setting::bbonesize);
							//			DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, Colors::botbone, Setting::bbonesize);
							//			DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, Colors::botbone, Setting::bbonesize);
							//			DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, Colors::botbone, Setting::bbonesize);
							//			DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, Colors::botbone, Setting::bbonesize);
							//			DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, Colors::botbone, Setting::bbonesize);
							//			DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, Colors::botbone, Setting::bbonesize);
							//			DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, Colors::botbone, Setting::bbonesize);


							//		}

							//	}
							//}
							//else {





							if (Setting::pname)
							{
								if (Setting::style1)
								{

									DX11::ImGui_DX11::DrawFilledRectangle(Screen.X + 55, Screen.Y - 15, 120, 13, ImColor(0.0f, 0.f, 0.f, 0.200f));
									if (AActor.Health <= 0)
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 12, temp, Screen.X - 60, Screen.Y - 28, DX11::ImGui_DX11::Color::Red, false);
										//	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 12, dist, Screen.X + 30, Screen.Y - 28, Colors::enemy, false);
									}
									else
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 12, temp, Screen.X - 60, Screen.Y - 28, Colors::nam, false);
										//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 12, dist, Screen.X + 30, Screen.Y - 28, Colors::enemy, false);

									}
								}
								if (Setting::style2)
								{

									//Text = AActor.Name + " " + to_string(Distance) + "M";


									if (AActor.Health <= 0)
									{
										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, nsize, temp, Screen.X, (Screen.Y + Screen.Z), DX11::ImGui_DX11::Color::Red, true);
									}
									else
									{

										DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, nsize, temp, Screen.X, (Screen.Y + Screen.Z), Colors::nam, true);

									}



								}


							}

							if (Setting::Distancee)
							{
								if (Setting::style1)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 12, dist, Screen.X + 30, Screen.Y - 28, Colors::enemy, false);

								}

								if (Setting::style2)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, dissize, dist, Screen.X, (Screen.Y + 15 + Screen.Z), Colors::enemy, false);

								}

							}

							if (Setting::phealth)
							{
								if (Setting::style1)
								{
									DX11::ImGui_DX11::DrawBlood(Screen.X - 65, Screen.Y - 15, 120, 4.0, AActor.Health);

								}

								if (Setting::style2)
								{
									if (hpbt == 0)
									{
										DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5), DX11::ImGui_DX11::Color::Black);

										if (AActor.Health > 70.0)
										{
											DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Green);
										}
										if (AActor.Health > 30.0 && AActor.Health <= 70.0)
										{
											DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Yellow);
										}
										if (AActor.Health > 0.0 && AActor.Health <= 30.0)
										{
											DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Red);

										}
									}
									else if (hpbt == 1)
									{
										std::string hp100 = "HP : 100";
										std::string hp90 = "HP : 90";
										std::string hp80 = "HP : 80";
										std::string hp60 = "HP : 60";
										std::string hp40 = "HP : 40";
										std::string hp20 = "HP : 20";
										std::string hp10 = "HP : 10";
										std::string hp0 = "HP : 0";

										if (AActor.Health > 99.0)
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, hp, hp100, Screen.X, (Screen.Y + 30 + Screen.Z), Colors::hpt, true);

										}
										if (AActor.Health > 90.0 && AActor.Health <= 99.0)
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, hp, hp90, Screen.X, (Screen.Y + 30 + Screen.Z), Colors::hpt, true);

										}
										if (AActor.Health > 80.0 && AActor.Health <= 90.0)
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, hp, hp80, Screen.X, (Screen.Y + 30 + Screen.Z), Colors::hpt, true);

										}
										if (AActor.Health > 60.0 && AActor.Health <= 80.0)
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, hp, hp60, Screen.X, (Screen.Y + 30 + Screen.Z), Colors::hpt, true);

										}
										if (AActor.Health > 40.0 && AActor.Health <= 60.0)
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, hp, hp40, Screen.X, (Screen.Y + 30 + Screen.Z), Colors::hpt, true);

										}
										if (AActor.Health > 20.0 && AActor.Health <= 40.0)
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, hp, hp20, Screen.X, (Screen.Y + 30 + Screen.Z), Colors::hpt, true);

										}
										if (AActor.Health > 10.0 && AActor.Health <= 20.0)
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, hp, hp10, Screen.X, (Screen.Y + 30 + Screen.Z), Colors::hpt, true);

										}

										if (AActor.Health > 0.0 && AActor.Health <= 10.0)
										{
											DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, hp, hp0, Screen.X, (Screen.Y + 30 + Screen.Z), Colors::hpt, true);

										}
										//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 14, temp, Screen.X, (Screen.Y + Screen.Z), Colors::nam, true);
									}
								}

							}
							if (Setting::pline)
							{

								if (Setting::style2)
								{

									if (linne == 0)
									{
										DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, Setting::plinesize);
									}
									else if (linne == 1)
									{
										DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, Colors::playerline, Setting::plinesize);
									}


								}
								if (Setting::style1)
								{
									DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 18, linescolors, Setting::plinesize);

								}
							}
							//if (Setting::pfullbox)
							//{
								//fullboxcolor = linescolors;

								//DX11::ImGui_DX11::DrawRectangle(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, fullboxcolor, Setting::pfullboxsize);


							//}

							if (Setting::pcorner)
							{
								fullboxcolor = linescolors;
								cornerboxcolor = linescolors;
								if (boxe == 0)
								{
									DX11::ImGui_DX11::CornerBox(Screen.X - Screen.Z / 4 - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, Setting::pcornersize, popcorn / 2, cornerboxcolor);
								}
								else if (boxe == 1)
								{
									DX11::ImGui_DX11::DrawRectangle(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, fullboxcolor, Setting::pfullboxsize);
								}

							}
							if (Setting::Bone)
							{
								bonescolors = linescolors;
								if (Setting::playerBone)
								{
									HeadPos = AActor.HeadPos;
									HeadPos.Z += 7;
									if (!Algorithm::WorldToScreenBone(ViewMatrix, HeadPos, Head, &Distance)) continue;
									if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.ChestPos, Chest, &Distance)) continue;
									if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.PelvisPos, Pelvis, &Distance)) continue;
									if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lSholderPos, lSholder, &Distance)) continue;
									if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rSholderPos, rSholder, &Distance)) continue;
									if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lElbowPos, lElbow, &Distance)) continue;
									if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rElbowPos, rElbow, &Distance)) continue;
									if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lWristPos, lWrist, &Distance)) continue;
									if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rWristPos, rWrist, &Distance)) continue;
									if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lThighPos, lThigh, &Distance)) continue;
									if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rThighPos, rThigh, &Distance)) continue;
									if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lKneePos, lKnee, &Distance)) continue;
									if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rKneePos, rKnee, &Distance)) continue;
									if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lAnklePos, lAnkle, &Distance)) continue;
									if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rAnklePos, rAnkle, &Distance)) continue;

									if (skelee == 0)
									{

										DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, bonescolors, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, bonescolors, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, bonescolors, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, bonescolors, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, bonescolors, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, bonescolors, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, bonescolors, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, bonescolors, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, bonescolors, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, bonescolors, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, bonescolors, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, bonescolors, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, bonescolors, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, bonescolors, Setting::pbonesize);
									}
									else if (skelee == 1)
									{
										DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, Colors::skelec, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, Colors::skelec, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, Colors::skelec, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, Colors::skelec, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, Colors::skelec, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, Colors::skelec, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, Colors::skelec, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, Colors::skelec, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, Colors::skelec, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, Colors::skelec, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, Colors::skelec, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, Colors::skelec, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, Colors::skelec, Setting::pbonesize);
										DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, Colors::skelec, Setting::pbonesize);
									}
								}

							}

							//}
						}


					}

				

				//if (Setting::MagicBullet)
				//{
					//if (Memory::IsMagicInitialized == false)
					//{
					//	Text = "initializing Meagic";
					//	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, DX11Window::Width / 2, DX11Window::Height / 2, DX11::ImGui_DX11::Color::enem, true);

				//	//}
                   //
				//}
				if (Distance < 350)
				{
					if (Setting::TotalEnemy)
					{
						if (watermark) {


							if (Emulator::IsGameLoop)
							{
							//	Text = "Emulator : Gameloop & Time:";
								//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, Text, 90, DX11Window::Height / 2 + 330, DX11::ImGui_DX11::Color::Green, true);
								//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, tim, 260, DX11Window::Height / 2 + 330, DX11::ImGui_DX11::Color::Green, true);

							}

							if (Emulator::IsSmartGaGa)
							{
								//Text = " Emulator : SmartGaGA & Time:";

								//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, Text, 90, DX11Window::Height / 2 + 308, DX11::ImGui_DX11::Color::Green, true);
								//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 15, tim, 260, DX11Window::Height / 2 + 308, DX11::ImGui_DX11::Color::Green, true);

							}
						}
						if (Data::AActorList.size() != 0)
						{
							ImGui::SetNextWindowSize(ImVec2(190.0f, 35.0f));
							//ImGui::SetCursorPos({ 50, 200 });
							//ImGui::SetWindowPos({ 50, 50 });
							//ImGuiIO& io = ImGui::GetIO();
							ImGuiStyle& sstyle = ImGui::GetStyle();
							ImVec4* colors = sstyle.Colors;

							//sstyle.Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 230);
							//sstyle.Colors[ImGuiCol_Border] = ImColor(73, 255, 0, 255);
							//sstyle.WindowBorderSize = 1.0f;
							ImGuiIO& Io = ImGui::GetIO();

							//ImGui::SetNextWindowSize(ImVec2(400.0f, 115.0f));
							ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
							if (ImGui::Begin("ene", 0, Flags21))
							{
								std::string Text = "  Total enemy around you: ";
								Text.append(std::to_string((Data::AActorList.size())));

								//Text = " Enemy Near : " + to_string(Data::AActorList.size());
								//DX11::ImGui_DX11::DrawFilledRectangle(DX11Window::Width / 2 + 66, DX11Window::Height / 100 * 18.0f, 140, 22, ImColor(1.0f, 0.f, 0.f, 0.600f));
								//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 17, Text, DX11Window::Width / 2, DX11Window::Height / 100 * 14.5f, DX11::ImGui_DX11::Color::enem, true);

								ImGui::Text(Text.c_str());
								ImGui::End();
							}
						}
					}

					if (Setting::MAgicline)
					{
						for (int i = 0; i < Data::AActorList.size(); i++)
						{


							if (!Algorithm::WorldToScreen(Data::AActorList[i].Position, Screen, &Distance, ViewMatrix)) continue;
							if (currIndex == i)
							{
								DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, DX11Window::Height / 2, Screen.X, Screen.Y - 10, Colors::magicline, 1.8f);
							}
						}


					}
				}
				
				/*if (Setting::aimbotposition)
				{
					if (Setting::curraim == 0)
					{
						Text = "Current Aim Position : Head";
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 19, Text, DX11Window::Width / 2, DX11Window::Height / 2 + 200, DX11::ImGui_DX11::Color::Green, true);

					}
					if (Setting::curraim == 1)
					{
						Text = "Current Aim Position : Cheast";
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 19, Text, DX11Window::Width / 2, DX11Window::Height / 2 + 200 , DX11::ImGui_DX11::Color::Green, true);

					}
				}*/
				if (Setting::fovcircle)
				{
					if (Data::AActorList.size() != 0)
					{
						//DrawCircle(OverlayWindowWidth / 2, OverlayScreenHeight / 2, 100.0f/*FovRadius*/
						DX11::ImGui_DX11::DrawCircle(DX11Window::Width / 2, DX11Window::Height / 2, Setting::fovcircleredus, Colors::fovcirclecolor);
					}
				}
				if (Setting::graned)
				{
					for (Item& Item : Data::ItemList)
					{
						if (!Algorithm::WorldToScreen(Item.Position, Screen, &Distance, ViewMatrix)) continue;

						std::string	Textt = Item.Name;// +" " + "(" + to_string(Distance) + "m)";
						//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Textt, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::White, true);
						if (Setting::grw)
						{
							if (Setting::Esp_Item_Frag && Item.Name == "Frag")
							{

								////DX11::ImGui_DX11::DrawFilledRect(Screen.X - 15, Screen.Y, 30, 15, ImColor(0.000f, 0.00f, 0.00f, 0.250f));
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Textt, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);
								//DX11::ImGui_DX11::CornerBox(Screen.X - 15, Screen.Y, 30, 15, 0.9f, popcorn2, DX11::ImGui_DX11::Color::Red);

							}
						}

						if (Setting::Esp_Item_Smoke && Item.Name == "Smoke")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Textt, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Smoke_Color[0], Setting::Esp_Item_Smoke_Color[1], Setting::Esp_Item_Smoke_Color[2], Setting::Esp_Item_Smoke_Color[3]), true);
						}

						if (Setting::Esp_Item_Molotof && Item.Name == "Molotof")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Textt, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Molotof_Color[0], Setting::Esp_Item_Molotof_Color[1], Setting::Esp_Item_Molotof_Color[2], Setting::Esp_Item_Molotof_Color[3]), true);
						}
						if (Setting::molow)
						{
							if (Setting::Esp_Item_Molotof && Item.Name == "Burn")
							{
								//DX11::ImGui_DX11::DrawFilledRect(Screen.X - 15, Screen.Y, 30, 15, ImColor(0.000f, 0.00f, 0.00f, 0.250f));
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Textt, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);
								//DX11::ImGui_DX11::CornerBox(Screen.X - 15, Screen.Y, 30, 15, 0.9f, popcorn2, DX11::ImGui_DX11::Color::Red);
							}
						}
						if (Setting::Esp_Item_Molotof && Item.Name == "frag")
						{

							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Textt, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::White, true);
						}

					}
				}
				if (!Setting::fightmode)
				{


					if (Setting::deadbox)
					{
						ImColor color;
						for (int i = 0; i < g_pEsp->lootboxr.size(); i++)
						{

							if (!Algorithm::WorldToScreen(g_pEsp->lootboxr[i].Position, Screen, &Distance, ViewMatrix)) continue;
							std::string dead = "Loot-Box   " + to_string(Distance) + "M";

							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, dead, Screen.X, Screen.Y + 13, Colors::deadbox, false);
							if (Setting::playerdeadbox)
							{


								for (int k = 0; k < g_pEsp->lootboxr[i].boxitem.size(); k++)
								{
									color = g_pEsp->lootboxr[i].boxitem[k].colorcod;
									std::string text = g_pEsp->lootboxr[i].boxitem[k].Displayname;


									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, text, Screen.X, Screen.Y - 15 * (k), g_pEsp->lootboxr[i].boxitem[k].colorcod, false);

									if (Setting::bg)
									{
										DX11::ImGui_DX11::DrawFilledRect(Screen.X - 10, Screen.Y - 15 * (k), 100, 15, ImColor(0.000f, 0.00f, 0.00f, 0.200f));


									}
									if (Setting::itemrect)
									{
										if (Setting::redioption == 1)
										{
											DX11::ImGui_DX11::CornerBox(Screen.X - 10, Screen.Y - 15 * (k), 110, 15, 0.6f, popcorn2, Colors::bgcorner);

										}

										if (Setting::redioption == 2)
										{
											DX11::ImGui_DX11::DrawRectangle(Screen.X - 10, Screen.Y - 15 * (k), 100, 15, Colors::bgcorner, 0.6f);

										}


									}

								}

							}

						}


					}
					if (Setting::impitems)
					{
						for (Item& Item : Data::ItemList)
						{
							if (!Algorithm::WorldToScreen(Item.Position, Screen, &Distance, ViewMatrix)) continue;

							Text = Item.Name;// +" " + "(" + to_string(Distance) + "m)";
							std::string air = Item.Name + " " + to_string(Distance) + "M";
							if (Setting::Esp_Item_AKM && Item.Name == "AKM")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::AKM, true);
							}
							if (Setting::Esp_Item_SCARL && Item.Name == "SCAR-L")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::scarl, true);
							}

							if (Setting::Esp_Item_M416 && Item.Name == "M416")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::m16, true);
							}
							if (Setting::Esp_Item_M24 && Item.Name == "M24")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::M24, true);
							}

							if (Setting::Esp_Item_Kar98k && Item.Name == "Kar98k")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, weapon::kar98, true);
							}
							if (Setting::plan && Item.Name == "Plan")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, Setting::plancolor, true);
							}

							if (Setting::Esp_Item_DP28 && Item.Name == "DP28")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_DP28_Color[0], Setting::Esp_Item_DP28_Color[1], Setting::Esp_Item_DP28_Color[2], Setting::Esp_Item_DP28_Color[3]), true);
							}
							if (Setting::Esp_Item_M762 && Item.Name == "M762")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_M762_Color[0], Setting::Esp_Item_M762_Color[1], Setting::Esp_Item_M762_Color[2], Setting::Esp_Item_M762_Color[3]), true);
							}
							if (Setting::Esp_Item_Awm && Item.Name == "AWM")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, air, Screen.X, Screen.Y, weapon::AWM, true);
							}

							if (Setting::Esp_Item_FlareGun && Item.Name == "Flare Gun")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, air, Screen.X, Screen.Y, weapon::Flaregun, true);
							}

							if (Setting::Esp_Item_Flare && Item.Name == "Flare")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, air, Screen.X, Screen.Y, weapon::Flare, true);
							}

							if (Setting::Esp_Item_AirDrop && Item.Name == "Air Drop")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, air, Screen.X, Screen.Y, weapon::Airdrop, true);
							}
							if (Setting::Esp_Item_Armor3 && Item.Name == "Armor L.3")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Armor3_Color[0], Setting::Esp_Item_Armor3_Color[1], Setting::Esp_Item_Armor3_Color[2], Setting::Esp_Item_Armor3_Color[3]), true);
							}
							if (Setting::Esp_Item_Bag3 && Item.Name == "Bag L.3")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Bag3_Color[0], Setting::Esp_Item_Bag3_Color[1], Setting::Esp_Item_Bag3_Color[2], Setting::Esp_Item_Bag3_Color[3]), true);
							}
							if (Setting::Esp_Item_Helmet3 && Item.Name == "Helmet L.3")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Helmet3_Color[0], Setting::Esp_Item_Helmet3_Color[1], Setting::Esp_Item_Helmet3_Color[2], Setting::Esp_Item_Helmet3_Color[3]), true);
							}
							if (Setting::Esp_Item_Helmet3 && Item.Name == "300Magnum")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, air, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Helmet3_Color[0], Setting::Esp_Item_Helmet3_Color[1], Setting::Esp_Item_Helmet3_Color[2], Setting::Esp_Item_Helmet3_Color[3]), true);
							}
							if (Setting::deadbox && Item.Name == "Dead-Box")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, air, Screen.X, Screen.Y, Colors::deadbox, true);
							}
						}
					}

					if (Setting::healthitem)
					{
						for (Item& Item : Data::ItemList)
						{
							if (!Algorithm::WorldToScreen(Item.Position, Screen, &Distance, ViewMatrix)) continue;

							Text = Item.Name;// +" " + "(" + to_string(Distance) + "m)";

							if (Setting::Esp_Item_MedKit && Item.Name == "Med Kit")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_MedKit_Color[0], Setting::Esp_Item_MedKit_Color[1], Setting::Esp_Item_MedKit_Color[2], Setting::Esp_Item_MedKit_Color[3]), true);
							}

							if (Setting::Esp_Item_FirstAidKit && Item.Name == "First Aid Kit")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_FirstAidKit_Color[0], Setting::Esp_Item_FirstAidKit_Color[1], Setting::Esp_Item_FirstAidKit_Color[2], Setting::Esp_Item_FirstAidKit_Color[3]), true);
							}

							if (Setting::Esp_Item_Painkiller && Item.Name == "Painkiller")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Painkiller_Color[0], Setting::Esp_Item_Painkiller_Color[1], Setting::Esp_Item_Painkiller_Color[2], Setting::Esp_Item_Painkiller_Color[3]), true);
							}

							if (Setting::Esp_Item_EnergyDrink && Item.Name == "Energy Drink")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_EnergyDrink_Color[0], Setting::Esp_Item_EnergyDrink_Color[1], Setting::Esp_Item_EnergyDrink_Color[2], Setting::Esp_Item_EnergyDrink_Color[3]), true);
							}

							if (Setting::Esp_Item_AdrenalineSyringe && Item.Name == "Adrenaline Syringe")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_AdrenalineSyringe_Color[0], Setting::Esp_Item_AdrenalineSyringe_Color[1], Setting::Esp_Item_AdrenalineSyringe_Color[2], Setting::Esp_Item_AdrenalineSyringe_Color[3]), true);
							}

						}
					}

					if (Setting::scope)
					{
						for (Item& Item : Data::ItemList)
						{
							if (!Algorithm::WorldToScreen(Item.Position, Screen, &Distance, ViewMatrix)) continue;

							Text = Item.Name;// +" " + to_string(Distance) + " M";
							if (Setting::Esp_Item_x2 && Item.Name == "2x")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x2_Color[0], Setting::Esp_Item_x2_Color[1], Setting::Esp_Item_x2_Color[2], Setting::Esp_Item_x2_Color[3]), true);
							}

							if (Setting::Esp_Item_x3 && Item.Name == "3x")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x3_Color[0], Setting::Esp_Item_x3_Color[1], Setting::Esp_Item_x3_Color[2], Setting::Esp_Item_x3_Color[3]), true);
							}

							if (Setting::Esp_Item_x4 && Item.Name == "4x")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x4_Color[0], Setting::Esp_Item_x4_Color[1], Setting::Esp_Item_x4_Color[2], Setting::Esp_Item_x4_Color[3]), true);
							}

							if (Setting::Esp_Item_x6 && Item.Name == "6x")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x6_Color[0], Setting::Esp_Item_x6_Color[1], Setting::Esp_Item_x6_Color[2], Setting::Esp_Item_x6_Color[3]), true);
							}

							if (Setting::Esp_Item_x8 && Item.Name == "8x")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x8_Color[0], Setting::Esp_Item_x8_Color[1], Setting::Esp_Item_x8_Color[2], Setting::Esp_Item_x8_Color[3]), true);
							}
						}

					}
					if (Setting::allitemss)
					{
						for (Item& Item : Data::ItemList)
						{
							if (!Algorithm::WorldToScreen(Item.Position, Screen, &Distance, ViewMatrix)) continue;

							Text = Item.Name;// +" " + "(" + to_string(Distance) + "m)";

							if (Setting::Esp_Item_Bag1 && Item.Name == "Bag L.1")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Bag1_Color[0], Setting::Esp_Item_Bag1_Color[1], Setting::Esp_Item_Bag1_Color[2], Setting::Esp_Item_Bag1_Color[3]), true);
							}

							if (Setting::Esp_Item_Bag2 && Item.Name == "Bag L.2")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Bag2_Color[0], Setting::Esp_Item_Bag2_Color[1], Setting::Esp_Item_Bag2_Color[2], Setting::Esp_Item_Bag2_Color[3]), true);
							}

							if (Setting::Esp_Item_Helmet1 && Item.Name == "Helmet L.1")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Helmet1_Color[0], Setting::Esp_Item_Helmet1_Color[1], Setting::Esp_Item_Helmet1_Color[2], Setting::Esp_Item_Helmet1_Color[3]), true);
							}

							if (Setting::Esp_Item_Helmet2 && Item.Name == "Helmet L.2")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Helmet2_Color[0], Setting::Esp_Item_Helmet2_Color[1], Setting::Esp_Item_Helmet2_Color[2], Setting::Esp_Item_Helmet2_Color[3]), true);
							}

							if (Setting::Esp_Item_Armor1 && Item.Name == "Armor L.1")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting::fontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Armor1_Color[0], Setting::Esp_Item_Armor1_Color[1], Setting::Esp_Item_Armor1_Color[2], Setting::Esp_Item_Armor1_Color[3]), true);
							}

							if (Setting::Esp_Item_Armor2 && Item.Name == "Armor L.2")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Armor2_Color[0], Setting::Esp_Item_Armor2_Color[1], Setting::Esp_Item_Armor2_Color[2], Setting::Esp_Item_Armor2_Color[3]), true);
							}


							if (Setting::Esp_Item_Mk47Mutant && Item.Name == "Mk47 Mutant")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Mk47Mutant_Color[0], Setting::Esp_Item_Mk47Mutant_Color[1], Setting::Esp_Item_Mk47Mutant_Color[2], Setting::Esp_Item_Mk47Mutant_Color[3]), true);
							}

							if (Setting::Esp_Item_M16A4 && Item.Name == "M16A4")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_M16A4_Color[0], Setting::Esp_Item_M16A4_Color[1], Setting::Esp_Item_M16A4_Color[2], Setting::Esp_Item_M16A4_Color[3]), true);
							}

							if (Setting::Esp_Item_G36C && Item.Name == "G36C")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_G36C_Color[0], Setting::Esp_Item_G36C_Color[1], Setting::Esp_Item_G36C_Color[2], Setting::Esp_Item_G36C_Color[3]), true);
							}

							if (Setting::Esp_Item_QBZ && Item.Name == "QBZ")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_QBZ_Color[0], Setting::Esp_Item_QBZ_Color[1], Setting::Esp_Item_QBZ_Color[2], Setting::Esp_Item_QBZ_Color[3]), true);
							}

							if (Setting::Esp_Item_QBU && Item.Name == "QBU")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_QBU_Color[0], Setting::Esp_Item_QBU_Color[1], Setting::Esp_Item_QBU_Color[2], Setting::Esp_Item_QBU_Color[3]), true);
							}

							if (Setting::Esp_Item_SLR && Item.Name == "SLR")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_SLR_Color[0], Setting::Esp_Item_SLR_Color[1], Setting::Esp_Item_SLR_Color[2], Setting::Esp_Item_SLR_Color[3]), true);
							}

							if (Setting::Esp_Item_Mini14 && Item.Name == "Mini-14")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Mini14_Color[0], Setting::Esp_Item_Mini14_Color[1], Setting::Esp_Item_Mini14_Color[2], Setting::Esp_Item_Mini14_Color[3]), true);
							}



							if (Setting::Esp_Item_PP19 && Item.Name == "PP19")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_PP19_Color[0], Setting::Esp_Item_PP19_Color[1], Setting::Esp_Item_PP19_Color[2], Setting::Esp_Item_PP19_Color[3]), true);
							}

							if (Setting::Esp_Item_TommyGun && Item.Name == "Tommy Gun")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_TommyGun_Color[0], Setting::Esp_Item_TommyGun_Color[1], Setting::Esp_Item_TommyGun_Color[2], Setting::Esp_Item_TommyGun_Color[3]), true);
							}

							if (Setting::Esp_Item_MP5K && Item.Name == "MP5K")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_MP5K_Color[0], Setting::Esp_Item_MP5K_Color[1], Setting::Esp_Item_MP5K_Color[2], Setting::Esp_Item_MP5K_Color[3]), true);
							}

							if (Setting::Esp_Item_UMP9 && Item.Name == "UMP9")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_UMP9_Color[0], Setting::Esp_Item_UMP9_Color[1], Setting::Esp_Item_UMP9_Color[2], Setting::Esp_Item_UMP9_Color[3]), true);
							}

							if (Setting::Esp_Item_Vector && Item.Name == "Vector")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Vector_Color[0], Setting::Esp_Item_Vector_Color[1], Setting::Esp_Item_Vector_Color[2], Setting::Esp_Item_Vector_Color[3]), true);
							}

							if (Setting::Esp_Item_Uzi && Item.Name == "Uzi")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Uzi_Color[0], Setting::Esp_Item_Uzi_Color[1], Setting::Esp_Item_Uzi_Color[2], Setting::Esp_Item_Uzi_Color[3]), true);
							}

							if (Setting::Esp_Item_762mm && Item.Name == "7.62mm")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_762mm_Color[0], Setting::Esp_Item_762mm_Color[1], Setting::Esp_Item_762mm_Color[2], Setting::Esp_Item_762mm_Color[3]), true);
							}

							if (Setting::Esp_Item_556mm && Item.Name == "5.56mm")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_556mm_Color[0], Setting::Esp_Item_556mm_Color[1], Setting::Esp_Item_556mm_Color[2], Setting::Esp_Item_556mm_Color[3]), true);
							}

							if (Setting::Esp_Item_9mm && Item.Name == "9mm")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_9mm_Color[0], Setting::Esp_Item_9mm_Color[1], Setting::Esp_Item_9mm_Color[2], Setting::Esp_Item_9mm_Color[3]), true);
							}

							if (Setting::Esp_Item_45ACP && Item.Name == "45ACP")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_45ACP_Color[0], Setting::Esp_Item_45ACP_Color[1], Setting::Esp_Item_45ACP_Color[2], Setting::Esp_Item_45ACP_Color[3]), true);
							}

							if (Setting::Esp_Item_Holo && Item.Name == "Holo")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Holo_Color[0], Setting::Esp_Item_Holo_Color[1], Setting::Esp_Item_Holo_Color[2], Setting::Esp_Item_Holo_Color[3]), true);
							}
							if (Setting::Esp_Item_M249 && Item.Name == "M249")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, Colors::M249, true);
							}

							if (Setting::Esp_Item_Mk12 && Item.Name == "MK12")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, Colors::MK12, true);
							}


						}
					}

					if (Setting::Vehicle)
					{
						for (Vehicle& Vehicle : Data::VehicleList)
						{
							if (!Algorithm::WorldToScreen(Vehicle.Position, Screen, &Distance, ViewMatrix)) continue;

							Text = Vehicle.Name + "  " + to_string(Distance) + "M";


							if (Setting::hp)
							{
								///DX11::ImGui_DX11::DrawRectangle(Screen.X - 40, Screen.Y + 17, 82.0f, 5.0f, Colors::vehicle);
								//DX11::ImGui_DX11::DrawBlood(Screen.X - 30, Screen.Y + 23, 80.0f, 4.0f, Vehicle.hp);
							}
							if (Setting::feul)
							{
								//DX11::ImGui_DX11::DrawBlood(Screen.X - 30, Screen.Y + 17, 80.00f, 4.0, Vehicle.oil);
							}
							if (Setting::vahicle_item && Vehicle.Name == "BRDM")
							{
								if (Vehicle.driving)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red,true);

								}
								else
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, Colors::vehicle, true);

								}
							}
							if (Setting::vahicle_item && Vehicle.Name == "Scooter")
							{
								if (Vehicle.driving)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

								}
								else
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, Colors::vehicle, true);

								}
							}
							if (Setting::vahicle_item && Vehicle.Name == "Motorcycle")
							{
								if (Vehicle.driving)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

								}
								else
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, Colors::vehicle, true);

								}
							}
							if (Setting::vahicle_item && Vehicle.Name == "Snowmobile")
							{
								if (Vehicle.driving)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

								}
								else
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, Colors::vehicle, true);

								}
							}
							if (Setting::vahicle_item && Vehicle.Name == "Tuk")
							{
								if (Vehicle.driving)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

								}
								else
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, Colors::vehicle, true);

								}
							}
							if (Setting::vahicle_item && Vehicle.Name == "Buggy")
							{
								if (Vehicle.driving)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

								}
								else
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, Colors::vehicle, true);

								}
							}
							if (Setting::vahicle_item && Vehicle.Name == "Sportsa")
							{
								if (Vehicle.driving)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

								}
								else
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, Colors::vehicle, true);

								}
							}
							if (Setting::vahicle_item && Vehicle.Name == "Sports")
							{
								if (Vehicle.driving)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

								}
								else
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, Colors::vehicle, true);

								}
							}
							if (Setting::vahicle_item && Vehicle.Name == "Dacia")
							{
								if (Vehicle.driving)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

								}
								else
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, Colors::vehicle, true);

								}
							}
							if (Setting::vahicle_item && Vehicle.Name == "Rony")
							{
								if (Vehicle.driving)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

								}
								else
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, Colors::vehicle, true);

								}
							}

							if (Setting::Esp_Item_AKM && Vehicle.Name == "UAZ")
							{
								if (Vehicle.driving)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

								}
								else
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, Colors::vehicle, true);

								}
							}
							if (Setting::Esp_Item_AKM && Vehicle.Name == "Minibus")
							{
								if (Vehicle.driving)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

								}
								else
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, Colors::vehicle, true);

								}
							}
							if (Setting::Esp_Item_AKM && Vehicle.Name == "PG117")
							{
								if (Vehicle.driving)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

								}
								else
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, Colors::vehicle, true);

								}
							}
							if (Setting::Esp_Item_AKM && Vehicle.Name == "Aquarail")
							{
								if (Vehicle.driving)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

								}
								else
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, Colors::vehicle, true);

								}
							}
							if (Setting::Esp_Item_AKM && Vehicle.Name == "Plane")
							{
								if (Vehicle.driving)
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::Normalfontsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

								}
								else
								{
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, vehisize, Text, Screen.X, Screen.Y, Colors::vehicle, true);

								}
							}
						}
					}
				}
			}

		ImGui::Render();
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		DX11::EndDraw();

		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}