#include "resource.h"
#pragma once


// RenameFileDialog dialog

class RenameFileDialog : public CDialog
{
	DECLARE_DYNAMIC(RenameFileDialog)

public:
	CEdit* pceOldFilePath;
	CEdit* pceNewFileName;

	RenameFileDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~RenameFileDialog();

// Dialog Data
	enum { IDD = IDD_RENAME_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	
	virtual BOOL RenameFileDialog::OnInitDialog(){
		CDialog::OnInitDialog();
		pceOldFilePath = (CEdit*)GetDlgItem(ecOldFilePath);
		pceNewFileName = (CEdit*)GetDlgItem(ecNewFileName);

		return true;
	}
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedbtnrename();
	afx_msg void OnBnClickedCancel();
};
