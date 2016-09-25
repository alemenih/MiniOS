#include "resource.h"
#include "SplashDlg.h"
#pragma once


// HomeDialog dialog

class HomeDialog : public CDialog
{
	DECLARE_DYNAMIC(HomeDialog)

public:
	HomeDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~HomeDialog();

// Dialog Data
	enum { IDD = IDD_HOME_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL HomeDialog::OnInitDialog(){
		CDialog::OnInitDialog();
		CSplashDlg::ShowSplashScreen(NULL);
		return true;
	}
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTexteditormenu();
	afx_msg void OnGameHenway();
	afx_msg void OnGameBattleoffice();
	afx_msg void OnDirectoryMakedirectory();
	afx_msg void OnDirectoryRemovedirectory();
	afx_msg void OnDirectoryShowcontent();
	afx_msg void OnDirectoryRename();
};
