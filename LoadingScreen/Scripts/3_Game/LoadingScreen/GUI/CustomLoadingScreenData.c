/**
 * ExpansionRespawnHandlerModule.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2022 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CustomLoadingScreenData
{
	bool ShowLogo = true;
	string LogoPath = "LoadingScreen/GUI/logo.edds";
	bool RandomizeBackgounds = true;
	int LoadingBarColor = ARGB(255, 199, 38, 81);
	bool UseCustomHints = true;
	string HintIconPath = "LoadingScreen/GUI/icons/circle_info.edds";

	ref array<ref CustomLoadingScreenBackground> m_ExBackgrounds;

	void CustomLoadingScreenData()
	{
		m_ExBackgrounds = new array<ref CustomLoadingScreenBackground>;
		JsonFileLoader<array<ref CustomLoadingScreenBackground>>.JsonLoadFile("LoadingScreen/Scripts/Data/LoadingImages.json", m_ExBackgrounds);
	}
};
