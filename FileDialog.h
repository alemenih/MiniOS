#include "resource.h"
#pragma once


// FileDialog dialog

class FileDialog : public CDialog
{
	DECLARE_DYNAMIC(FileDialog)

public:
	CEdit* pceFilePath;
	CEdit* pceFileName;
	FileDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~FileDialog();

// Dialog Data
	enum { IDD = IDD_FILEINFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();

		pceFilePath = (CEdit *)GetDlgItem(ecFilePath);
		pceFileName = (CEdit *)GetDlgItem(ecFileName);

		return true;
	}
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedbtngofiledlg();
	afx_msg void OnBnClickedbtncancelfiledlg();
};
