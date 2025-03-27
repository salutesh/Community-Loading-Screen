class CfgPatches
{
	class DayZExpansion_LoadingScreen_Scripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Scripts"
		};
	};
};
class CfgMods
{
	class DZ_Expansion_LoadingScreen
	{
		dir = "LoadingScreen";
		credits = "Steve aka Salutesh";
		extra = 0;
		type = "mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] =
				{
					"LoadingScreen/Scripts/3_Game"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = 
				{
					"LoadingScreen/Scripts/5_Mission"
				};
			};
		};
	};
};
class CfgSoundSets
{
	class Main_Music_Menu_SoundSet
	{
		soundShaders[] = {"Main_Music_Menu_SoundShader"};
		volumeFactor = 1;
		frequencyFactor = 1;
		spatial = 0;
	};
};	
class CfgSoundShaders
{
	class Main_Music_Menu_SoundShader
	{
		samples[] = {{"LoadingScreen\Music\mainmenu3.ogg",1}};
		volume = 1.00000000;
	};
};