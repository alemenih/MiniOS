#include "resource.h"
#pragma once


// RemoveFileDialog dialog

class RemoveFileDialog : public CDialog
{
	DECLARE_DYNAMIC(RemoveFileDialog)

public:
	CEdit* pceRmvFilePath;
	RemoveFileDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~RemoveFileDialog();

// Dialog Data
	enum { IDD = IDD_REMOVEFILE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	
	virtual BOOL RemoveFileDialog::OnInitDialog(){
		CDialog::OnInitDialog();
		pceRmvFilePath = (CEdit*)GetDlgItem(tfRemoveFilePath);

		return true;
	}
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedbtnremove();
};
