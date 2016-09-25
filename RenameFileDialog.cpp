// RenameFileDialog.cpp : implementation file
//

#include "stdafx.h"
#include "RenameFileDialog.h"
#include "afxdialogex.h"


// RenameFileDialog dialog

IMPLEMENT_DYNAMIC(RenameFileDialog, CDialog)

RenameFileDialog::RenameFileDialog(CWnd* pParent /*=NULL*/)
	: CDialog(RenameFileDialog::IDD, pParent)
{

}

RenameFileDialog::~RenameFileDialog()
{
}

void RenameFileDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RenameFileDialog, CDialog)
	ON_BN_CLICKED(btnRename, &RenameFileDialog::OnBnClickedbtnrename)
	ON_BN_CLICKED(IDCANCEL, &RenameFileDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// RenameFileDialog message handlers


void RenameFileDialog::OnBnClickedbtnrename()
{
	int result;
	CString csOldNamePath, csNewNamePath;
	pceOldFilePath->GetWindowText(csOldNamePath);
	pceNewFileName->GetWindowText(csNewNamePath);

	size_t oldNameLength = csOldNamePath.GetLength();
	size_t newNameLength = csNewNamePath.GetLength();

	char* oldName = 0, *newName = 0;
	oldName = (char*)(LPCTSTR)csOldNamePath.GetBuffer(csOldNamePath.GetLength());
	csOldNamePath.ReleaseBuffer();
	//char* newName = new char[newNameLength];
	newName = (char*)(LPCTSTR)csNewNamePath.GetBuffer(csOldNamePath.GetLength());
	csNewNamePath.ReleaseBuffer();
	
	//strcpy_s(oldName, oldNameLength, (LPCSTR)csOldNamePath.GetString());
	//strcpy_s(newName, newNameLength, (LPCSTR)csNewNamePath.GetString());

	result = rename(oldName, newName);
	if (result == 0)
	{
		MessageBox(_T("File successfully renamed."), _T("Status"), MB_OK);
		pceNewFileName->SetWindowText(L"");
		pceOldFilePath->SetWindowText(L"");
	}
	else{
		MessageBox(_T("Error renaming file.\nMake sure you provided a valid path"), _T("Status"), MB_OK);
		pceNewFileName->SetWindowText(L"");
		pceOldFilePath->SetWindowText(L"");
	}
	pceOldFilePath->SetWindowText(CString(oldName));
}


void RenameFileDialog::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
	RenameFileDialog::OnOK();

}
