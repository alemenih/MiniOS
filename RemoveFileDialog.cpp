// RemoveFileDialog.cpp : implementation file
//

#include "stdafx.h"
#include "RemoveFileDialog.h"
#include "afxdialogex.h"
#include <direct.h>

// RemoveFileDialog dialog

IMPLEMENT_DYNAMIC(RemoveFileDialog, CDialog)

RemoveFileDialog::RemoveFileDialog(CWnd* pParent /*=NULL*/)
	: CDialog(RemoveFileDialog::IDD, pParent)
{

}

RemoveFileDialog::~RemoveFileDialog()
{
}

void RemoveFileDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RemoveFileDialog, CDialog)
	ON_BN_CLICKED(btnRemove, &RemoveFileDialog::OnBnClickedbtnremove)
END_MESSAGE_MAP()


// RemoveFileDialog message handlers


void RemoveFileDialog::OnBnClickedbtnremove()
{
	// TODO: Add your control notification handler code here
	CString csPath;
	pceRmvFilePath->GetWindowText(csPath);
	const size_t size = csPath.GetLength();
	char* chPath = new char[size];
	strcpy_s(chPath, size, (LPCSTR)csPath.GetString());

	int pathExists = PathFileExists((LPCWSTR)csPath);
	if (pathExists){
		int status = rmdir(chPath);
		MessageBox(_T("File successfully removed."), _T("Status"), MB_OK);
		pceRmvFilePath->SetWindowText(L"");
		//pceRmvFilePath->SetWindowText(csPath.GetString());
	}
	else
	{
		MessageBox(_T("Error removing file.\nPlease make sure you provided a correct path"), _T("Status"), MB_OK);
		pceRmvFilePath->SetWindowText(L"");
	}
}
