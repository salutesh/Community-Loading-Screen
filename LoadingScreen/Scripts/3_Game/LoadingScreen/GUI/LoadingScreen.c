

class ExpansionLoadingScreenBackground
{
	string ImagePath;
};

modded class LoginScreenBase
{
	const string m_ExLogoPath = "LoadingScreen/GUI/Logo.edds"; //! Set logo path here!
	ref array<ref ExpansionLoadingScreenBackground> m_ExBackgrounds;
	
	protected ImageWidget m_ExHintIcon;
	protected int m_ExBackgroundIndex = 0;
	
	protected const float LOADING_SCREEN_CHANGE_TIME = 3.0;
	protected float m_ExLoadingTime;
	
	protected ImageWidget m_ExBackground;
		
	void LoginScreenBase()
	{
		m_ExBackgrounds = new array<ref ExpansionLoadingScreenBackground>;
		JsonFileLoader<array<ref ExpansionLoadingScreenBackground>>.JsonLoadFile("LoadingScreen/Scripts/Data/LoadingImages.json", m_ExBackgrounds);
	}
	
	/*override Widget Init()
	{
		layoutRoot = super.Init();
		
		SetBackgroundImage(m_ExBackgroundIndex);
		m_ExBackgroundIndex++;
		
		return layoutRoot;
	}*/
	
	override void Update(float timeslice)
	{
		super.Update(timeslice);

		m_ExLoadingTime += timeslice;
		if (m_ExLoadingTime >= LOADING_SCREEN_CHANGE_TIME)
		{
			SetBackgroundImage(m_ExBackgroundIndex);
			m_ExBackgroundIndex++;
			if (m_ExBackgroundIndex > (m_ExBackgrounds.Count() - 1))
				m_ExBackgroundIndex = 0;
			
			m_ExLoadingTime = 0;
		}
	}
	
	protected void SetBackgroundImage(int index)
	{
		ExpansionLoadingScreenBackground background = m_ExBackgrounds.Get(index);
		if (background && background.ImagePath != string.Empty)
		{
			Print(ToString() + "::SetBackgroundImage - Background: " + background.ImagePath);
			m_ExBackground.LoadImageFile(0, background.ImagePath, true);
			m_ExBackground.SetImage(0);
		}
	}
};

modded class LoginQueueBase
{
	override Widget Init()
	{
		layoutRoot = super.Init();

		m_ExBackground = ImageWidget.Cast(layoutRoot.FindAnyWidget("Background"));

		SetBackgroundImage(m_ExBackgroundIndex);
		m_ExBackgroundIndex++;

		return layoutRoot;
	}
};

modded class LoginTimeBase
{
	override Widget Init()
	{
		layoutRoot = super.Init();

		m_ExBackground = ImageWidget.Cast(layoutRoot.FindAnyWidget("Background"));

		SetBackgroundImage(m_ExBackgroundIndex);
		m_ExBackgroundIndex++;

		return layoutRoot;
	}
};

modded class LoadingScreen
{
	const string m_ExLogoPath = "LoadingScreen/GUI/Logo.edds"; //! Set logo path here!
	ref array<ref ExpansionLoadingScreenBackground> m_ExBackgrounds;

	protected ImageWidget m_ExHintIcon;
	protected int m_ExBackgroundIndex = 0;

	protected const float LOADING_SCREEN_CHANGE_TIME = 3.0;
	protected float m_ExLoadingTime;
	protected float m_ExLoadingTimeStamp;

	void LoadingScreen(DayZGame game)
	{
		Print(ToString() + "::LoadingScreen - Start");

		m_ExBackgrounds = new array<ref ExpansionLoadingScreenBackground>;
		JsonFileLoader<array<ref ExpansionLoadingScreenBackground>>.JsonLoadFile("LoadingScreen/Scripts/Data/LoadingImages.json", m_ExBackgrounds);

		Print(ToString() + "::LoadingScreen - Backgrounds: " + m_ExBackgrounds.ToString());
		Print(ToString() + "::LoadingScreen - Backgrounds count: " + m_ExBackgrounds.Count());

		Class.CastTo(m_ExHintIcon, m_WidgetRoot.FindAnyWidget("hintIcon"));

		//! Remove vanilla mask texture
		m_ImageWidgetBackground.LoadMaskTexture("");

		//! Set logo
		m_ImageLogoCorner.LoadImageFile(0, m_ExLogoPath);

		Print(ToString() + "::LoadingScreen - End");
	}

	//! Method called when loading progress has finished.
	override void Dec()
	{
		Print(ToString() + "::Dec - Start");

		super.Dec();

		Print(ToString() + "::Dec - End");
	}

	override void EndLoading()
	{
		Print(ToString() + "::EndLoading - Start");

		super.EndLoading();

		Print(ToString() + "::EndLoading - End");
	}

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		m_ExLoadingTime += timeslice;
		if (m_ExLoadingTime >= LOADING_SCREEN_CHANGE_TIME)
		{
			SetBackgroundImage(m_ExBackgroundIndex);
			m_ExBackgroundIndex++;
			if (m_ExBackgroundIndex > (m_ExBackgrounds.Count() - 1))
				m_ExBackgroundIndex = 0;
			
			m_ExLoadingTime = 0;
		}
	}

	override void ShowEx(DayZGame game)
	{
		Print(ToString() + "::ShowEx - Start");

		super.ShowEx(game);

		float loadingTime = m_ExLoadingTime;
		float tickTime = game.GetTickTime();
		
		if (m_ExLoadingTimeStamp < 0)
		{
			m_ExLoadingTime = 0;
		}
		else
		{
			m_ExLoadingTime += tickTime - m_ExLoadingTimeStamp;
		}

		m_ExLoadingTimeStamp = tickTime;

		if (m_ExLoadingTime >= LOADING_SCREEN_CHANGE_TIME)
		{
			SetBackgroundImage(m_ExBackgroundIndex);
			m_ExBackgroundIndex++;
			if (m_ExBackgroundIndex > (m_ExBackgrounds.Count() - 1))
				m_ExBackgroundIndex = 0;
			
			m_ExLoadingTime = 0;
		}

		Print(ToString() + "::ShowEx - End");
	}

	override void Show()
	{
		Print(ToString() + "::Show - Start");

		super.Show();

		Print(ToString() + "::Show - End");
	}

	override void Hide(bool force)
	{
		Print(ToString() + "::Hide - Start");

		super.Hide(force);

		Print(ToString() + "::Hide - End");
	}
	
	protected void SetBackgroundImage(int index)
	{
		Print(ToString() + "::SetBackgroundImage - Start");

		ExpansionLoadingScreenBackground background = m_ExBackgrounds.Get(index);
		if (background && background.ImagePath != string.Empty)
		{
			Print(ToString() + "::SetBackgroundImage - Background: " + background.ImagePath);
			m_ImageWidgetBackground.LoadImageFile(0, background.ImagePath, true);
			m_ImageWidgetBackground.SetImage(0);
		}

		Print(ToString() + "::SetBackgroundImage - End");
	}
};