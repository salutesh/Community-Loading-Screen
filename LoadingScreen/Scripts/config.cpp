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
		};
	};
};