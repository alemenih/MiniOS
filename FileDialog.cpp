// FileDialog.cpp : implementation file
//

#include "stdafx.h"
#include "FileDialog.h"
#include "afxdialogex.h"
#include <direct.h>

// FileDialog dialog

IMPLEMENT_DYNAMIC(FileDialog, CDialog)

FileDialog::FileDialog(CWnd* pParent /*=NULL*/)
	: CDialog(FileDialog::IDD, pParent)
{

}

FileDialog::~FileDialog()
{
}

void FileDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FileDialog, CDialog)
	ON_BN_CLICKED(btnGoFileDlg, &FileDialog::OnBnClickedbtngofiledlg)
	ON_BN_CLICKED(btnCancelFileDlg, &FileDialog::OnBnClickedbtncancelfiledlg)
END_MESSAGE_MAP()


// FileDialog message handlers


void FileDialog::OnBnClickedbtngofiledlg()
{
	CString csFileName, csFilePath;
	pceFileName->GetWindowText(csFileName);
	pceFilePath->GetWindowText(csFilePath);

	const size_t nMaxPath = 512;
	TCHAR szPath[nMaxPath];
	SetCurrentDirectory((LPCWSTR)csFilePath);
	GetCurrentDirectory(nMaxPath, szPath);
	int pathExists = PathFileExists((LPCWSTR)csFilePath);

	if (pathExists){
		wcsncpy_s(szPath, csFileName, nMaxPath);
		CreateDirectory(szPath, NULL);
		MessageBox(_T("File successfully created."), _T("Status"), MB_OK);
		pceFileName->SetWindowText(L"");
		pceFilePath->SetWindowText(L"");
	}
	else{
		MessageBox(_T("Error creating file.\nMake sure you have a correct path!"), _T("Status"), MB_OK);
		pceFileName->SetWindowText(L"");
		pceFilePath->SetWindowText(L"");
	}
}


void FileDialog::OnBnClickedbtncancelfiledlg()
{
	// TODO: Add your control notification handler code here
	FileDialog::OnOK();
}
