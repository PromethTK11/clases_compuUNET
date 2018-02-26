//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", F1);
USEFORM("Unit2.cpp", F2);
USEFORM("Unit3.cpp", F3);
USEFORM("Unit4.cpp", F4);
USEFORM("bitsWindow.cpp", bitsF5);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TF1), &F1);
		Application->CreateForm(__classid(TF2), &F2);
		Application->CreateForm(__classid(TF3), &F3);
		Application->CreateForm(__classid(TF4), &F4);
		Application->CreateForm(__classid(TbitsF5), &bitsF5);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
