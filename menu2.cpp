
#include <afxwin.h>
#include <afxdlgs.h>
#include "resource.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <io.h>
#include <stdlib.h>
#include <time.h>
#include "SplashDlg.h"
#include "HomeDialog.h"

#define IDC_EDIT 500
using namespace std;

#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

//Define filters for use with File Dialog
const char fileDialogFilter[] =
"C++ Files (*.cpp) | *.cpp|Header Files\
(*.h)|*.h|Resource Files (*.rc) | *.rc |Text Files (*.txt)|*.txt| All Files (*.*)| *.*||";
const char fileDialogExt[] = "cpp";

CSplashDlg* CSplashDlg::c_pSplashDlg; 

CString csFileDgExt = CString(fileDialogExt);
CString csFilDlgFilter = CString(fileDialogFilter);
	
	CString findString;
	

//Define the application object class


class CApp: public CWinApp
{
public:
	virtual BOOL InitInstance();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};


//Define the edit window class


class CWindow : public CDialog
{
	DECLARE_DYNAMIC(HomeDialog)

 private:
	 static UINT findMessage;
	 CMenu *menu;
	CEdit m_edit;
public:
	//CWindow(CWnd* pParent = NULL);   // standard constructor
	// Dialog Data
	enum { IDD = IDD_HOME_DIALOG };
protected:
	void CWindow::DoDataExchange(CDataExchange* pDX)
	{
		CDialog::DoDataExchange(pDX);
	}
	virtual BOOL CWindow::OnInitDialog(){
		CDialog::OnInitDialog();
		//CSplashDlg::ShowSplashScreen(NULL);
		return true;
	}

public:	
	
	//virtual ~CWindow();
	//CWindow();
	afx_msg void HandleOpen();
	afx_msg void HandlePrint();
	afx_msg void HandleQuit();
	afx_msg void HandleFind();
	afx_msg void HandleDelete();
	afx_msg void HandleUndo();
	afx_msg void HandleDate();
	afx_msg void HandleCut();
	afx_msg void HandleCopy();
	afx_msg void HandlePaste();
	afx_msg void HandleSave();
	afx_msg void HandleClear();
	afx_msg void HandleAbout();
	afx_msg LONG FindHelper(UINT wParam, LONG lParam);
	afx_msg void OnMouseMove(UINT,CPoint);
	DECLARE_MESSAGE_MAP()

};

// Create an instance of the application object

CApp App;

// The message map

BEGIN_MESSAGE_MAP(CWindow,CDialog)
 ON_COMMAND (IDM_FILE_OPEN, HandleOpen)
 ON_COMMAND (IDM_FILE_PRINT, HandlePrint)
 ON_COMMAND (IDM_FILE_QUIT, HandleQuit)
 ON_COMMAND (IDM_FILE_FIND, HandleFind)
 ON_COMMAND (IDM_FILE_DELETE,HandleDelete)
 ON_COMMAND (IDM_FILE_UNDO,HandleUndo)
 ON_COMMAND (IDM_FILE_DATE,HandleDate)
 ON_COMMAND (IDM_FILE_CUT,HandleCut)
 ON_COMMAND (IDM_FILE_COPY,HandleCopy)
 ON_COMMAND (IDM_FILE_PASTE,HandlePaste)
 ON_COMMAND (IDM_FILE_SAVE,HandleSave)
 ON_COMMAND(IDM_FILE_CLEAR,HandleClear)
 ON_REGISTERED_MESSAGE(findMessage, FindHelper)
 ON_COMMAND(IDM_FILE_ABOUT,HandleAbout)
  ON_WM_MOUSEMOVE()
  END_MESSAGE_MAP()

  UINT CWindow::findMessage =::RegisterWindowMessage(FINDMSGSTRING);
CFindReplaceDialog *findReplaceDialog = NULL;	  	 





void CWindow::OnMouseMove(UINT flag, CPoint mousePos)
{
	
	unsigned long seed =time(0); 
		srand(seed);

	CClientDC dc (this);
	if (flag ==MK_LBUTTON )
	{
		CPoint a[10];
		

		
		
		for (int x=0; x< 500; x++)
		{
		
		a[0] = CPoint(rand()%40,rand()%100);
		a[1]=CPoint(rand()%200,rand()%40);
		a[2] = CPoint(rand()%200,rand()%300);
		a[3]=CPoint(rand()%20,rand()%20);
		a[4]=CPoint(rand()%400,rand()%150);
		a[5]=CPoint(rand()%100,rand()%100);

		dc.SetPolyFillMode(ALTERNATE);
		dc.Polygon(a,rand()%6);
		dc.MoveTo(rand()%300,rand()%300);
		dc.LineTo(rand()%300, rand()%300);
		CBrush brush(RGB(rand()%255,rand()%255,rand()%255)), *oldBrush;
		oldBrush=dc.SelectObject(&brush);
		dc.ExtFloodFill(100,100, RGB(rand()%255,rand()%255,rand()%255),
			FLOODFILLBORDER);
		dc.SelectObject(oldBrush);
		
		}
	
		int res=MessageBox(L"Quit",L"Exiting!",MB_ICONQUESTION|MB_YESNO);
	  if (res==IDYES)
	  
		DestroyWindow();

	}
   else if (flag ==MK_RBUTTON)
   {
	



	for (int x=0; x<500; x++)
     {
	   
	CRect rect;   
	GetClientRect(&rect);
	
	CClientDC dc2(this);
	CPen pen(PS_SOLID,rand()%100,RGB(rand()%255,rand()%255,rand()%255)), *oldPen;
	oldPen=dc2.SelectObject(&pen);
	CBrush br (RGB(rand()%255,rand()%255,rand()%255));
	CBrush* pbrOld;
	pbrOld=dc2.SelectObject(&br);
	dc2.Ellipse(rect);
	dc2.SelectObject(pbrOld);
	dc2.SelectObject(oldPen);
	
	CClientDC dc(this);
	CPen penRed;
	penRed.CreatePen(PS_SOLID,rand()%175,RGB(rand()%255,rand()%255,rand()%255));
	CPen* ppenOld;
	ppenOld=dc.SelectObject(&penRed);
	dc.MoveTo(0,(rect.bottom+rect.top)/2);
	dc.LineTo ((rect.right+rect.left)/2,0);
	dc.LineTo (rect.right,(rect.bottom+rect.top)/2);
	dc.LineTo ((rect.right+rect.left)/2,rect.bottom);
	dc.LineTo (0,(rect.bottom+rect.top)/2);
	dc.SelectObject(ppenOld);

	Sleep(500); 
	}
   int resp=MessageBox(L"Quit",L"Exiting!",MB_ICONQUESTION|MB_YESNO);
	  if (resp==IDYES)
	  	  DestroyWindow();

   
   }

 


}


void  CWindow::HandleOpen()
{
	char s[200];
		
	CFileDialog fileDialog (TRUE, 
		csFileDgExt, NULL,
		OFN_FILEMUSTEXIST, csFilDlgFilter);
	if(  fileDialog.DoModal()== IDOK)
	{
	cout << "Pathname: "
	     << fileDialog.GetPathName()
		 << endl
		 <<"Filename: "
		 <<fileDialog.GetFileName()
		 << endl
		 <<"Extension: "
		 << fileDialog.GetFileExt()
		 << endl
		 << "File Title: "
		 << fileDialog.GetFileTitle()
		 << endl
		 << endl;

	
	CStdioFile f;
	CFileException exception;
	BOOL status;
	char name[40];
	char b[65535];
	
    for (int a=0; a<10000; a++)
		b[a]= ' ';
	
	
	int x=0;
	CString csFileDlg = CString(fileDialog.GetPathName());
	
	// Does this even make sense?

	strcpy_s(name,(LPCSTR)csFileDlg.GetString());
	
	if (_access(name,04)==0)
	
		MessageBox(L"File is there",L"Status",MB_OK);
	try{
	
	ifstream file(name,ios::binary);
	 while (!file.eof())
	 {
	
		 file.read((char*)&b[x++], sizeof(char));
	 
	 }
	 int len = m_edit.GetWindowTextLength();
	 m_edit.SetSel(len, len);
	 m_edit.ReplaceSel(CString(b));
	// CString text = CString(b);
	// m_edit.SetWindowText(text);

	 file.close();

	}

	catch(...)
	{
		MessageBox(L"File is too big to be loaded\n64K Maximum size\n--Returning!",L"Status",MB_OK);
		m_edit.SetFocus();
		return;
	}
		status = f.Open(fileDialog.GetPathName(), CFile::
	
		 modeRead,&exception);
	if (!status)
	{
		char s[100];
		sprintf(s,"Error opening file for reading. Code:  %d",
			exception.m_cause);
		CString css = CString(s);
		MessageBox(css,L"Error",MB_OK);
		return;
	}
	
 		
		m_edit.SetWindowText((LPTSTR)b);
			
		  
	}
		 	
	
	/**MessageBox (s,
		"Dialog Information",
		MB_ICONINFORMATION);
         m_edit.SetFocus();*/
	
	}

 void CWindow::HandleSave()
{
	CFile file;
	static CString filePathName;
	CFileDialog fileDialog (FALSE, csFileDgExt,
		filePathName,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
	csFilDlgFilter);
	if (fileDialog.DoModal()==IDOK)
	{
		CString oldPathName (filePathName);
	   filePathName=fileDialog.GetPathName();
	
	}
	
	
	char buffer[65535];
   UINT length=	m_edit.GetWindowTextLength();
   if (length ==0)
   {
	   MessageBox(L"Nothing to Save", L"Warning!",MB_OK);
	   m_edit.SetFocus();
	   return;
   }


		if (!file.Open(filePathName, 
		CFile::modeCreate | CFile::modeWrite))
	{
		CString msg ("Can't open " +
			filePathName +
			"\nCheck the name.");
		MessageBox(msg, L"File Save Error",
			MB_ICONEXCLAMATION);
	 return;
	
	} 
		char info[100];
		sprintf( info,"Saving %d  Lines",m_edit.GetLineCount());
		CString csInfo = CString(info);
		MessageBox(csInfo, L"File Save", MB_ICONINFORMATION|
			MB_OK);
   m_edit.FmtLines(TRUE);
   m_edit.GetWindowText((LPTSTR)buffer,length+1);

   
   file.Write (buffer,length+1);
	
   file.Close();
 m_edit.SetFocus();
 
	



}

 void CWindow::HandleClear()
{
  	 
	 UINT length=	m_edit.GetWindowTextLength(); 
	 if (length > 0 )
	 {
	 int result = MessageBox(L"Warning:  Data Loss! \n Proceed",L"Caution",
		  MB_ICONQUESTION|MB_YESNO);
	 if (result == IDYES)
	 m_edit.SetWindowText(L"");
	 }
 	 m_edit.SetFocus();
 }

	
	
	
 
 
 
 void CWindow::HandlePrint()
{

	 char b[10000];
	unsigned int x=0;
	ofstream printer ("PRN");
	int result =MessageBox(L"Screen File?", L"Print what?",
		MB_ICONINFORMATION|MB_YESNO);
	if (result == IDYES)
	{
	  UINT length=	m_edit.GetWindowTextLength(); 
	  m_edit.GetWindowText((LPTSTR)b,length+1);
	  for ( x=0; x< length+1; x++)
		   printer << b[x];
		   printer << "\f";
	}
	else
	{
	 char s[30];
		
	CPrintDialog printDialog (FALSE,
	PD_ALLPAGES| PD_PAGENUMS | PD_SELECTION);
	if (printDialog.DoModal() == IDOK)
	{
		cout << "Number of Copies:  "
		    <<  printDialog.GetCopies()
		    << endl
		    << endl;
		CString css = CString(s);
		MessageBox(css, L"Dialog Information",
			MB_ICONINFORMATION);
	  int result = MessageBox(L"Ready to send file to printer",
		  L"File Printing", MB_ICONQUESTION|MB_YESNO);
	  if (result == IDYES)
	  {
	
		  char s[200];
	//ostrstream ostr (s,200);
	
	CFileDialog fileDialog (TRUE, 
		csFileDgExt, NULL,
	  OFN_FILEMUSTEXIST, csFilDlgFilter);
	if(  fileDialog.DoModal()== IDOK)
	{
	cout << "Pathname: "
	     << fileDialog.GetPathName()
		 << endl
		 <<"Filename: "
		 <<fileDialog.GetFileName()
		 << endl
		 <<"Extension: "
		 << fileDialog.GetFileExt()
		 << endl
		 << "File Title: "
		 << fileDialog.GetFileTitle()
		 << endl
		 << endl;
		CStdioFile f;
	CFileException exception;
	BOOL status;
	char name[20];
	//Same fix here
	CString csPathName = CString(fileDialog.GetPathName());
	strcpy(name,(LPCSTR)csPathName.GetString());
	
	if (access(name,04)==0)
	
		MessageBox(L"File is there",L"Status",MB_OK);
		
	ifstream file(name,ios::binary);
	 while (!file.eof())
	 {
	
		 file.read((char*)&b[x++], sizeof(char));
	 
	 }
	
	 

	 file.close();




	 status = f.Open(fileDialog.GetPathName(), CFile::
		modeRead,&exception);
	if (!status)
	{
		char s[100];
		sprintf(s,"Error opening file for reading. Code:  %d",
			exception.m_cause);
		CString css = CString(s);
		MessageBox(css,L"Error",MB_OK);
		return;
	}
	
 		
	}		
		  
	}
		 	
	  css = CString(s);
     MessageBox (css,
		L"Dialog Information",
		MB_ICONINFORMATION);
         m_edit.SetFocus();

		 for (unsigned int z=0; z<x;z++)
		  
		printer << b[z]; 
		printer << "\f";
		printer.close();
	  }
	
	}	
 m_edit.SetFocus();
}

 void CWindow:: HandleQuit()
{
	 int answer=MessageBox(L"Do you want to save your file?",L"File Save",
		 MB_ICONQUESTION|MB_YESNO);
	    if (answer==IDYES)
	       HandleSave();
	 int result = MessageBox(L"Are you sure?", L"Exiting!",
		MB_ICONQUESTION|MB_YESNO);
	if (result == IDYES)
		DestroyWindow();
	else
	m_edit.SetFocus();
 }




void  CWindow::HandleFind()
 {


	findReplaceDialog = new CFindReplaceDialog;
	findReplaceDialog->Create(TRUE,L"default", L"Arland");
    
 }
	 
	 LONG CWindow::FindHelper(UINT WParam, LONG lParam)
	 {

		 findString.Empty();
	   if (findReplaceDialog->IsTerminating())
		 findReplaceDialog = NULL;
	 else if (findReplaceDialog->FindNext())
 	 	
		
  {
	  
		 findString=findReplaceDialog->GetFindString();	
		 CString line , rightLine;
	  int cursorPos, startChar, foundChar,
		  lineIndex,charIndex, lineLength;
		 findString.MakeLower();
		 lineIndex = m_edit.LineFromChar();
		 m_edit.GetSel(startChar, charIndex);
		 do
		 {
			 lineLength=m_edit.LineLength(charIndex);
			 cursorPos=charIndex -
				 m_edit.LineIndex(lineIndex);
			 m_edit.GetLine(lineIndex,
				 line.GetBuffer(lineLength),
				 lineLength);
			 line.ReleaseBuffer(lineLength);
			 rightLine=line.Right(lineLength -
				 cursorPos);
			 rightLine.MakeLower();
			 foundChar = rightLine.Find (findString);
			 if (foundChar == -1)
				 charIndex =m_edit.LineIndex(++lineIndex);
		 } while ((foundChar == -1) &&  
			 (lineIndex < m_edit.GetLineCount()));
		  if (foundChar != -1)
		  {	  
			  
			  startChar =charIndex + foundChar;
				  m_edit.SetSel (startChar, 
				  startChar + findString.GetLength());
			  m_edit.LineScroll (m_edit.LineFromChar(
				  startChar) - m_edit.GetFirstVisibleLine());
			  m_edit.SetFocus();
		  }
		  else
		  {
			  
			  
			  if (findReplaceDialog)
				  findReplaceDialog->EnableWindow(FALSE);
			  MessageBox(L"String not found.",
				  L"Find String",
				  MB_ICONINFORMATION);
			  if (findReplaceDialog)
				  findReplaceDialog->EnableWindow(TRUE);
		  }

	 
	 
	 }
	  return 0L;
	 }

	 



  void CWindow::HandleDelete()
 {
	 m_edit.ReplaceSel(L"");
	 m_edit.SetFocus();
 }
	 
  void CWindow::HandleUndo()
	 
 {
	 m_edit.Undo();
 	 m_edit.SetFocus();
 }

 void CWindow::HandleCut()
 {
	 m_edit.Cut();
 }

 
 void CWindow::HandleCopy()
 {
	 m_edit.Copy();
 }

 void CWindow::HandlePaste()
 {
	 m_edit.Paste();
 }

  void CWindow :: HandleDate()
 {
		
	 CTime t;
	 t= CTime::GetCurrentTime();
	 CString s = t.Format ("Current date and time: %c");
	 MessageBox(s, L"Date/Time", MB_OK);
	 m_edit.SetFocus();
 }

  void CWindow::HandleAbout()
  {

	 
	  CRect rect;
	
	
	
	CModalDialog aboutDialog(IDM_FILE_ABOUT,this);
	aboutDialog.DoModal();
	m_edit.SetFocus();
  }


  
  //CWindow constructor

 //CWindow::CWindow()
//	{
      
	/* CRect rect;
	 int ans=MessageBox(L"Want to Draw?", L"Do What?",MB_ICONINFORMATION|MB_YESNO);

	  if (ans==IDYES)
	  	    Create (NULL,L"Drawing",WS_OVERLAPPEDWINDOW,
				CRect(150,100,450,400));
	    */
	 //HomeDialog homeDialog;
	 //homeDialog.DoModal();

	 /* else
	  {
	LoadAccelTable(L"MainAccelTable");
	
	Create (NULL, L"Arland's MiniEdit", WS_OVERLAPPED|WS_SYSMENU,
	
		rectDefault);
	   menu = new CMenu();
	   menu->LoadMenu(L"MainMenu");
		   SetMenu(menu);
	   DrawMenuBar();
	   GetClientRect(&rect);
	   m_edit.Create(WS_VISIBLE|WS_VSCROLL|WS_HSCROLL|ES_AUTOVSCROLL|
		   ES_MULTILINE |ES_NOHIDESEL,rect,this,IDC_EDIT); 
	  m_edit.SetFocus();
	
	  }
 */
 //}

	//Initialize the CApp m_pMainWnd data member


		   BOOL CApp :: InitInstance()
		   {
			   //CApp::InitInstance();
			   
			   HomeDialog dlg;
			   m_pMainWnd = &dlg;
			   dlg.DoModal();
			   /*CSplashDlg::ShowSplashScreen(NULL);
			   m_pMainWnd= new CWindow();
			   m_pMainWnd->ShowWindow(m_nCmdShow);
			   //m_pMainWnd->UpdateWindow();
			   */
			   
			   return FALSE;
			}
		  
		    

			   BOOL CApp::PreTranslateMessage(MSG* pMsg)
		   {
				   // TODO: Add your specialized code here and call the base class, or both.
				   if (CSplashDlg::PreTranslateAppMessage(pMsg))
					   return TRUE;

				   return CWinApp::PreTranslateMessage(pMsg);
			   }

		   void HomeDialog::OnTexteditormenu(){
			   CWindow cwnd;
			   cwnd.DoModal();
		   }