// HomeDialog.cpp : implementation file
//

#include "stdafx.h"
#include "HomeDialog.h"
#include "afxdialogex.h"
#include "FileDialog.h"
#include "RemoveFileDialog.h"
#include "RenameFileDialog.h"
#include <direct.h> 
#include <stdlib.h>

// HomeDialog dialog

IMPLEMENT_DYNAMIC(HomeDialog, CDialog)

HomeDialog::HomeDialog(CWnd* pParent /*=NULL*/)
	: CDialog(HomeDialog::IDD, pParent)
{

}

HomeDialog::~HomeDialog()
{
}

void HomeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HomeDialog, CDialog)
	ON_COMMAND(ID_TEXTEDITORMENU, &HomeDialog::OnTexteditormenu)
	ON_COMMAND(ID_GAME_HENWAY, &HomeDialog::OnGameHenway)
	ON_COMMAND(ID_GAME_BATTLEOFFICE, &HomeDialog::OnGameBattleoffice)
	ON_COMMAND(ID_DIRECTORY_MAKEDIRECTORY, &HomeDialog::OnDirectoryMakedirectory)
	ON_COMMAND(ID_DIRECTORY_REMOVEDIRECTORY, &HomeDialog::OnDirectoryRemovedirectory)
	ON_COMMAND(ID_DIRECTORY_SHOWCONTENT, &HomeDialog::OnDirectoryShowcontent)
	ON_COMMAND(ID_DIRECTORY_RENAME, &HomeDialog::OnDirectoryRename)
END_MESSAGE_MAP()


// HomeDialog message handlers

/*
void HomeDialog::OnTexteditormenu()
{
	// TODO: Add your command handler code here

}
*/

void HomeDialog::OnGameHenway()
{
	// TODO: Add your command handler code here
	STARTUPINFO sui;
	PROCESS_INFORMATION pi;

	sui.cb = sizeof(STARTUPINFO);
	sui.lpReserved = 0;
	sui.lpDesktop = NULL;
	sui.lpTitle = NULL;
	sui.dwX = 0;
	sui.dwY = 0;
	sui.dwXSize = 0;
	sui.dwXCountChars = 0;
	sui.dwYCountChars = 0;
	sui.dwFillAttribute = 0;
	sui.dwFlags = 0;
	sui.wShowWindow = 0;
	sui.cbReserved2 = 0;
	sui.lpReserved2 = 0;

	wchar_t LszCommandLine[512] = _T("Henway.exe");
	wchar_t* pCommandLine = LszCommandLine;
	::CreateProcessW(NULL, (LPTSTR)pCommandLine, NULL, NULL, FALSE, DETACHED_PROCESS,
		NULL, NULL, &sui, &pi);
}


void HomeDialog::OnGameBattleoffice()
{
	STARTUPINFO sui;
	PROCESS_INFORMATION pi;

	sui.cb = sizeof(STARTUPINFO);
	sui.lpReserved = 0;
	sui.lpDesktop = NULL;
	sui.lpTitle = NULL;
	sui.dwX = 0;
	sui.dwY = 0;
	sui.dwXSize = 0;
	sui.dwXCountChars = 0;
	sui.dwYCountChars = 0;
	sui.dwFillAttribute = 0;
	sui.dwFlags = 0;
	sui.wShowWindow = 0;
	sui.cbReserved2 = 0;
	sui.lpReserved2 = 0;

	wchar_t LszCommandLine[512] = _T("BattleOffice.exe");
	wchar_t* pCommandLine = LszCommandLine;
	::CreateProcessW(NULL, (LPTSTR)pCommandLine, NULL, NULL, FALSE, DETACHED_PROCESS,
		NULL, NULL, &sui, &pi);
}


void HomeDialog::OnDirectoryMakedirectory()
{
	// TODO: Add your command handler code here
	FileDialog fDlg;
	fDlg.DoModal();
}


void HomeDialog::OnDirectoryRemovedirectory()
{
	// TODO: Add your command handler code here
	RemoveFileDialog rmvDlg;
	rmvDlg.DoModal();
}


void HomeDialog::OnDirectoryShowcontent()
{
	// TODO: Add your command handler code here
	STARTUPINFO sui;
	PROCESS_INFORMATION pi;

	sui.cb = sizeof(STARTUPINFO);
	sui.lpReserved = 0;
	sui.lpDesktop = NULL;
	sui.lpTitle = NULL;
	sui.dwX = 0;
	sui.dwY = 0;
	sui.dwXSize = 0;
	sui.dwXCountChars = 0;
	sui.dwYCountChars = 0;
	sui.dwFillAttribute = 0;
	sui.dwFlags = 0;
	sui.wShowWindow = 0;
	sui.cbReserved2 = 0;
	sui.lpReserved2 = 0;

	wchar_t LszCommandLine[512] = _T("windir.exe");
	wchar_t* pCommandLine = LszCommandLine;
	::CreateProcessW(NULL, (LPTSTR)pCommandLine, NULL, NULL, FALSE, DETACHED_PROCESS,
		NULL, NULL, &sui, &pi);
}


void HomeDialog::OnDirectoryRename()
{
	RenameFileDialog renameDlg;
	renameDlg.DoModal();
	
	
}
