// Mainframe macro generated from application: C:\root\bin\root.exe
// By ROOT version 5.34/14 on 2014-07-01 10:47:17

#ifndef ROOT_TGFrame
#include "TGFrame.h"
#endif
#ifndef ROOT_TG3DLine
#include "TG3DLine.h"
#endif
#ifndef ROOT_TGListBox
#include "TGListBox.h"
#endif
#ifndef ROOT_TGScrollBar
#include "TGScrollBar.h"
#endif
#ifndef ROOT_TGComboBox
#include "TGComboBox.h"
#endif
#ifndef ROOT_TH2Editor
#include "TH2Editor.h"
#endif
#ifndef ROOT_TRootBrowser
#include "TRootBrowser.h"
#endif
#ifndef ROOT_TGMenu
#include "TGMenu.h"
#endif
#ifndef ROOT_TGFileDialog
#include "TGFileDialog.h"
#endif
#ifndef ROOT_TGButtonGroup
#include "TGButtonGroup.h"
#endif
#ifndef ROOT_TGCommandPlugin
#include "TGCommandPlugin.h"
#endif
#ifndef ROOT_TRootDialog
#include "TRootDialog.h"
#endif
#ifndef ROOT_TGCanvas
#include "TGCanvas.h"
#endif
#ifndef ROOT_TGFSContainer
#include "TGFSContainer.h"
#endif
#ifndef ROOT_TGButton
#include "TGButton.h"
#endif
#ifndef ROOT_TGTextEdit
#include "TGTextEdit.h"
#endif
#ifndef ROOT_TRootContextMenu
#include "TRootContextMenu.h"
#endif
#ifndef ROOT_TGFSComboBox
#include "TGFSComboBox.h"
#endif
#ifndef ROOT_TGLabel
#include "TGLabel.h"
#endif
#ifndef ROOT_TGView
#include "TGView.h"
#endif
#ifndef ROOT_TGMsgBox
#include "TGMsgBox.h"
#endif
#ifndef ROOT_TGFileBrowser
#include "TGFileBrowser.h"
#endif
#ifndef ROOT_TGraphEditor
#include "TGraphEditor.h"
#endif
#ifndef ROOT_TGTab
#include "TGTab.h"
#endif
#ifndef ROOT_TGListView
#include "TGListView.h"
#endif
#ifndef ROOT_TGSplitter
#include "TGSplitter.h"
#endif
#ifndef ROOT_TGTextEditor
#include "TGTextEditor.h"
#endif
#ifndef ROOT_TGTextEntry
#include "TGTextEntry.h"
#endif
#ifndef ROOT_TRootCanvas
#include "TRootCanvas.h"
#endif
#ifndef ROOT_TGDockableFrame
#include "TGDockableFrame.h"
#endif
#ifndef ROOT_TGStatusBar
#include "TGStatusBar.h"
#endif
#ifndef ROOT_TGListTree
#include "TGListTree.h"
#endif
#ifndef ROOT_TGToolTip
#include "TGToolTip.h"
#endif
#ifndef ROOT_TGIcon
#include "TGIcon.h"
#endif
#ifndef ROOT_TGToolBar
#include "TGToolBar.h"
#endif
#ifndef ROOT_TGHtmlBrowser
#include "TGHtmlBrowser.h"
#endif

#include "Riostream.h"

void john()
{

   // main frame
   TGMainFrame *fRootBrowser2 = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);

   // vertical frame
   TGVerticalFrame *fVerticalFrame3 = new TGVerticalFrame(fRootBrowser2,1366,687,kVerticalFrame);

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame4 = new TGHorizontalFrame(fVerticalFrame3,1366,26,kHorizontalFrame);

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame5 = new TGHorizontalFrame(fHorizontalFrame4,60,26,kHorizontalFrame | kRaisedFrame);

   // menu bar
   TGMenuBar *fMenuBar6 = new TGMenuBar(fHorizontalFrame5,58,22,kHorizontalFrame);

   // "Browser" menu
   TGPopupMenu *fPopupMenu8 = new TGPopupMenu(gClient->GetDefaultRoot(),169,228,kOwnBackground);
   fPopupMenu8->AddEntry("&Browse...\tCtrl+B",11011);
   fPopupMenu8->AddEntry("&Open...\tCtrl+O",11012);
   fPopupMenu8->AddSeparator();

   // cascaded menu "Browser Help..."
   TGPopupMenu *fPopupMenu9 = new TGPopupMenu(gClient->GetDefaultRoot(),179,154,kOwnBackground);
   fPopupMenu9->AddEntry("&About ROOT...",11014);
   fPopupMenu9->AddSeparator();
   fPopupMenu9->AddEntry("Help On Browser...",11015);
   fPopupMenu9->AddEntry("Help On Canvas...",11016);
   fPopupMenu9->AddEntry("Help On Menus...",11017);
   fPopupMenu9->AddEntry("Help On Graphics Editor...",11018);
   fPopupMenu9->AddEntry("Help On Objects...",11019);
   fPopupMenu9->AddEntry("Help On PostScript...",11020);
   fPopupMenu9->AddEntry("Help On Remote Session...",11021);
   fPopupMenu8->AddPopup("Browser Help...",fPopupMenu9);
   fPopupMenu8->AddSeparator();
   fPopupMenu8->AddEntry("&Clone\tCtrl+N",11013);
   fPopupMenu8->AddSeparator();
   fPopupMenu8->AddEntry("New &Editor\tCtrl+E",11022);
   fPopupMenu8->AddEntry("New &Canvas\tCtrl+C",11023);
   fPopupMenu8->AddEntry("New &HTML\tCtrl+H",11024);
   fPopupMenu8->AddSeparator();

   // cascaded menu "Execute Plugin..."
   TGPopupMenu *fPopupMenu10 = new TGPopupMenu(gClient->GetDefaultRoot(),97,42,kOwnBackground);
   fPopupMenu10->AddEntry("&Macro...",11025);
   fPopupMenu10->AddEntry("&Command...",11026);
   fPopupMenu8->AddPopup("Execute &Plugin...",fPopupMenu10);
   fPopupMenu8->AddSeparator();
   fPopupMenu8->AddEntry("Close &Tab\tCtrl+T",11027);
   fPopupMenu8->AddEntry("Close &Window\tCtrl+W",11028);
   fPopupMenu8->AddSeparator();
   fPopupMenu8->AddEntry("&Quit Root\tCtrl+Q",11029);
   fMenuBar6->AddPopup("&Browser",fPopupMenu8, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));
   fHorizontalFrame5->AddFrame(fMenuBar6, new TGLayoutHints(kLHintsTop | kLHintsExpandX,0,0,1,1));

   fHorizontalFrame4->AddFrame(fHorizontalFrame5, new TGLayoutHints(kLHintsNormal));

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame12 = new TGHorizontalFrame(fHorizontalFrame4,1306,26,kHorizontalFrame | kRaisedFrame);

   // menu bar
   TGMenuBar *fMenuBar113 = new TGMenuBar(fHorizontalFrame12,1304,22,kHorizontalFrame);

   // "File" menu
   TGPopupMenu *fPopupMenu105 = new TGPopupMenu(gClient->GetDefaultRoot(),100,108,kOwnBackground);
   fPopupMenu105->AddEntry("&New Canvas",0);
   fPopupMenu105->AddEntry("&Open...",1);
   fPopupMenu105->AddEntry("&Close Canvas",12);
   fPopupMenu105->DisableEntry(12);
   fPopupMenu105->HideEntry(12);
   fPopupMenu105->AddSeparator();

   // cascaded menu "Save"
   TGPopupMenu *fPopupMenu104 = new TGPopupMenu(gClient->GetDefaultRoot(),112,150,kOwnBackground);
   fPopupMenu104->AddEntry("Canvas_1.&ps",5);
   fPopupMenu104->AddEntry("Canvas_1.&eps",6);
   fPopupMenu104->AddEntry("Canvas_1.p&df",7);
   fPopupMenu104->AddEntry("Canvas_1.&gif",8);
   fPopupMenu104->AddEntry("Canvas_1.&jpg",9);
   fPopupMenu104->AddEntry("Canvas_1.&png",10);
   fPopupMenu104->AddEntry("Canvas_1.&C",4);
   fPopupMenu104->AddEntry("Canvas_1.&root",3);
   fPopupMenu105->AddPopup("&Save",fPopupMenu104);
   fPopupMenu105->AddEntry("Save &As...",2);
   fPopupMenu105->AddSeparator();
   fPopupMenu105->AddEntry("&Print...",11);
   fPopupMenu105->AddSeparator();
   fPopupMenu105->AddEntry("&Quit ROOT",13);
   fPopupMenu105->DisableEntry(13);
   fPopupMenu105->HideEntry(13);
   fMenuBar113->AddPopup("&File",fPopupMenu105, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Edit" menu
   TGPopupMenu *fPopupMenu107 = new TGPopupMenu(gClient->GetDefaultRoot(),68,144,kOwnBackground);
   fPopupMenu107->AddEntry("&Style...",14);
   fPopupMenu107->AddSeparator();
   fPopupMenu107->AddEntry("Cu&t",15);
   fPopupMenu107->DisableEntry(15);
   fPopupMenu107->AddEntry("&Copy",16);
   fPopupMenu107->DisableEntry(16);
   fPopupMenu107->AddEntry("&Paste",17);
   fPopupMenu107->DisableEntry(17);
   fPopupMenu107->AddSeparator();

   // cascaded menu "Clear"
   TGPopupMenu *fPopupMenu106 = new TGPopupMenu(gClient->GetDefaultRoot(),72,42,kOwnBackground);
   fPopupMenu106->AddEntry("&Pad",18);
   fPopupMenu106->AddEntry("&Canvas",19);
   fPopupMenu107->AddPopup("C&lear",fPopupMenu106);
   fPopupMenu107->AddSeparator();
   fPopupMenu107->AddEntry("&Undo",20);
   fPopupMenu107->DisableEntry(20);
   fPopupMenu107->AddEntry("&Redo",21);
   fPopupMenu107->DisableEntry(21);
   fMenuBar113->AddPopup("&Edit",fPopupMenu107, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "View" menu
   TGPopupMenu *fPopupMenu109 = new TGPopupMenu(gClient->GetDefaultRoot(),120,180,kOwnBackground);
   fPopupMenu109->AddEntry("&Editor",22);
   fPopupMenu109->AddEntry("&Toolbar",23);
   fPopupMenu109->AddEntry("Event &Statusbar",24);
   fPopupMenu109->AddEntry("T&oolTip Info",25);
   fPopupMenu109->AddSeparator();
   fPopupMenu109->AddEntry("&Colors",26);
   fPopupMenu109->AddEntry("&Fonts",27);
   fPopupMenu109->DisableEntry(27);
   fPopupMenu109->AddEntry("&Markers",28);
   fPopupMenu109->AddSeparator();
   fPopupMenu109->AddEntry("&Iconify",29);
   fPopupMenu109->AddSeparator();

   // cascaded menu "View With"
   TGPopupMenu *fPopupMenu108 = new TGPopupMenu(gClient->GetDefaultRoot(),75,42,kOwnBackground);
   fPopupMenu108->AddEntry("&X3D",30);
   fPopupMenu108->AddEntry("&OpenGL",31);
   fPopupMenu109->AddPopup("&View With",fPopupMenu108);
   fMenuBar113->AddPopup("&View",fPopupMenu109, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Options" menu
   TGPopupMenu *fPopupMenu110 = new TGPopupMenu(gClient->GetDefaultRoot(),145,216,kOwnBackground);
   fPopupMenu110->AddEntry("&Auto Resize Canvas",32);
   fPopupMenu110->CheckEntry(32);
   fPopupMenu110->AddEntry("&Resize Canvas",33);
   fPopupMenu110->AddEntry("&Move Opaque",34);
   fPopupMenu110->AddEntry("Resize &Opaque",35);
   fPopupMenu110->AddSeparator();
   fPopupMenu110->AddEntry("&Interrupt",36);
   fPopupMenu110->AddEntry("R&efresh",37);
   fPopupMenu110->AddSeparator();
   fPopupMenu110->AddEntry("&Pad Auto Exec",38);
   fPopupMenu110->AddSeparator();
   fPopupMenu110->AddEntry("&Statistics",39);
   fPopupMenu110->CheckEntry(39);
   fPopupMenu110->AddEntry("Histogram &Title",40);
   fPopupMenu110->CheckEntry(40);
   fPopupMenu110->AddEntry("&Fit Parameters",41);
   fPopupMenu110->AddEntry("Can Edit &Histograms",42);
   fMenuBar113->AddPopup("&Options",fPopupMenu110, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Tools" menu
   TGPopupMenu *fPopupMenu111 = new TGPopupMenu(gClient->GetDefaultRoot(),117,114,kOwnBackground);
   fPopupMenu111->AddEntry("&Inspect ROOT",43);
   fPopupMenu111->AddEntry("&Class Tree",44);
   fPopupMenu111->AddEntry("&Fit Panel",45);
   fPopupMenu111->AddEntry("&Start Browser",46);
   fPopupMenu111->AddEntry("&Gui Builder",47);
   fPopupMenu111->AddEntry("&Event Recorder",48);
   fMenuBar113->AddPopup("&Tools",fPopupMenu111, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Help" menu
   TGPopupMenu *fPopupMenu112 = new TGPopupMenu(gClient->GetDefaultRoot(),118,158,kOwnBackground);
   fPopupMenu112->AddLabel("Basic Help On...");
   fPopupMenu112->DefaultEntry(-1);
   fPopupMenu112->AddSeparator();
   fPopupMenu112->AddEntry("&Canvas",50);
   fPopupMenu112->AddEntry("&Menus",51);
   fPopupMenu112->AddEntry("&Graphics Editor",52);
   fPopupMenu112->AddEntry("&Browser",53);
   fPopupMenu112->AddEntry("&Objects",54);
   fPopupMenu112->AddEntry("&PostScript",55);
   fPopupMenu112->AddSeparator();
   fPopupMenu112->AddEntry("&About ROOT...",49);
   fMenuBar113->AddPopup("&Help",fPopupMenu112, new TGLayoutHints(kLHintsRight | kLHintsTop));
   fHorizontalFrame12->AddFrame(fMenuBar113, new TGLayoutHints(kLHintsTop | kLHintsExpandX,0,0,1,1));

   // menu bar
   TGMenuBar *fMenuBar158 = new TGMenuBar(fHorizontalFrame12,1304,22,kHorizontalFrame);

   // "File" menu
   TGPopupMenu *fPopupMenu153 = new TGPopupMenu(gClient->GetDefaultRoot(),85,126,kOwnBackground);
   fPopupMenu153->AddEntry("&New",0);
   fPopupMenu153->AddSeparator();
   fPopupMenu153->AddEntry("&Open...",1);
   fPopupMenu153->AddEntry("&Close",4);
   fPopupMenu153->AddEntry("&Save",2);
   fPopupMenu153->AddEntry("Save &As...",3);
   fPopupMenu153->AddSeparator();
   fPopupMenu153->AddEntry("&Print...",5);
   fPopupMenu153->AddSeparator();
   fPopupMenu153->AddEntry("E&xit",6);
   fPopupMenu153->DisableEntry(6);
   fPopupMenu153->HideEntry(6);
   fMenuBar158->AddPopup("&File",fPopupMenu153, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Edit" menu
   TGPopupMenu *fPopupMenu154 = new TGPopupMenu(gClient->GetDefaultRoot(),137,122,kOwnBackground);
   fPopupMenu154->AddEntry("Cu&t\tCtrl+X",7);
   fPopupMenu154->DisableEntry(7);
   fPopupMenu154->AddEntry("&Copy\tCtrl+C",8);
   fPopupMenu154->DisableEntry(8);
   fPopupMenu154->AddEntry("&Paste\tCtrl+V",9);
   fPopupMenu154->AddEntry("De&lete\tDel",10);
   fPopupMenu154->DisableEntry(10);
   fPopupMenu154->AddSeparator();
   fPopupMenu154->AddEntry("Select &All\tCtrl+A",11);
   fPopupMenu154->AddSeparator();
   fPopupMenu154->AddEntry("Set &Font",20);
   fMenuBar158->AddPopup("&Edit",fPopupMenu154, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Search" menu
   TGPopupMenu *fPopupMenu156 = new TGPopupMenu(gClient->GetDefaultRoot(),145,64,kOwnBackground);
   fPopupMenu156->AddEntry("&Find...\tCtrl+F",12);
   fPopupMenu156->AddEntry("Find &Next\tF3",13);
   fPopupMenu156->AddSeparator();
   fPopupMenu156->AddEntry("&Goto Line...\tCtrl+L",14);
   fMenuBar158->AddPopup("&Search",fPopupMenu156, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Tools" menu
   TGPopupMenu *fPopupMenu155 = new TGPopupMenu(gClient->GetDefaultRoot(),174,60,kOwnBackground);
   fPopupMenu155->AddEntry("&Compile Macro\tCtrl+F7",15);
   fPopupMenu155->AddEntry("&Execute Macro\tCtrl+F5",16);
   fPopupMenu155->AddEntry("&Interrupt\tShift+F5",17);
   fMenuBar158->AddPopup("&Tools",fPopupMenu155, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Help" menu
   TGPopupMenu *fPopupMenu157 = new TGPopupMenu(gClient->GetDefaultRoot(),128,46,kOwnBackground);
   fPopupMenu157->AddEntry("&Help Topics\tF1",18);
   fPopupMenu157->AddSeparator();
   fPopupMenu157->AddEntry("&About...",19);
   fMenuBar158->AddPopup("&Help",fPopupMenu157, new TGLayoutHints(kLHintsRight | kLHintsTop));
   fHorizontalFrame12->AddFrame(fMenuBar158, new TGLayoutHints(kLHintsTop | kLHintsExpandX,0,0,1,1));

   fHorizontalFrame4->AddFrame(fHorizontalFrame12, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY));

   fVerticalFrame3->AddFrame(fHorizontalFrame4, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX));

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame13 = new TGHorizontalFrame(fVerticalFrame3,400,2,kHorizontalFrame | kRaisedFrame);

   fVerticalFrame3->AddFrame(fHorizontalFrame13, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX));

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame14 = new TGHorizontalFrame(fVerticalFrame3,1366,661,kHorizontalFrame);

   // vertical frame
   TGVerticalFrame *fVerticalFrame15 = new TGVerticalFrame(fHorizontalFrame14,434,661,kVerticalFrame | kFixedWidth);

   // tab widget
   TGTab *fTab19 = new TGTab(fVerticalFrame15,430,657);

   // container of "Files"
   TGCompositeFrame *fCompositeFrame32;
   fCompositeFrame32 = fTab19->AddTab("Files");
   fCompositeFrame32->SetLayoutManager(new TGVerticalLayout(fCompositeFrame32));

   // composite frame
   TGCompositeFrame *fFileBrowser33 = new TGCompositeFrame(fCompositeFrame32,426,632,kVerticalFrame);

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame34 = new TGHorizontalFrame(fFileBrowser33,422,26,kHorizontalFrame);

   ULong_t ucolor;        // will reflect user color changes
   gClient->GetColorByName("#ffffff",ucolor);

   // combo box
   TGComboBox *fComboBox35 = new TGComboBox(fHorizontalFrame34,"same",-1,kHorizontalFrame | kSunkenFrame | kDoubleBorder | kOwnBackground);
   fComboBox35->AddEntry("",1);
   fComboBox35->AddEntry("box",2);
   fComboBox35->AddEntry("colz",3);
   fComboBox35->AddEntry("lego",4);
   fComboBox35->AddEntry("lego1",5);
   fComboBox35->AddEntry("lego2",6);
   fComboBox35->AddEntry("same",7);
   fComboBox35->AddEntry("surf",8);
   fComboBox35->AddEntry("surf1",9);
   fComboBox35->AddEntry("surf2",10);
   fComboBox35->AddEntry("surf3",11);
   fComboBox35->AddEntry("surf4",12);
   fComboBox35->AddEntry("surf5",13);
   fComboBox35->AddEntry("text",14);
   fComboBox35->Resize(80,20);
   fComboBox35->Select(7);
   fHorizontalFrame34->AddFrame(fComboBox35, new TGLayoutHints(kLHintsRight | kLHintsCenterY,2,2,2,2));
   TGLabel *fLabel62 = new TGLabel(fHorizontalFrame34,"Draw Option:");
   fLabel62->SetTextJustify(36);
   fLabel62->SetMargins(0,0,0,0);
   fLabel62->SetWrapLength(-1);
   fHorizontalFrame34->AddFrame(fLabel62, new TGLayoutHints(kLHintsRight | kLHintsCenterY,5,2,2,2));
   TGPictureButton *fPictureButton63 = new TGPictureButton(fHorizontalFrame34,gClient->GetPicture("bld_sortup.png"),-1,TGPictureButton::GetDefaultGC()(),kDoubleBorder);
   fPictureButton63->SetToolTipText("Sort Alphabetically\n(Current folder only)");
   fHorizontalFrame34->AddFrame(fPictureButton63, new TGLayoutHints(kLHintsLeft | kLHintsCenterY,2,2,2,2));
   fPictureButton63->Connect("Clicked()", 0, 0, "ToggleSort()");
   TGPictureButton *fPictureButton66 = new TGPictureButton(fHorizontalFrame34,gClient->GetPicture("filter.png"),-1,TGPictureButton::GetDefaultGC()(),kDoubleBorder);
   fPictureButton66->SetToolTipText("Filter Content");
   fHorizontalFrame34->AddFrame(fPictureButton66, new TGLayoutHints(kLHintsLeft | kLHintsCenterY,2,2,2,2));
   fPictureButton66->Connect("Clicked()", 0, 0, "RequestFilter()");
   TGPictureButton *fPictureButton69 = new TGPictureButton(fHorizontalFrame34,gClient->GetPicture("refresh.png"),-1,TGPictureButton::GetDefaultGC()(),kDoubleBorder);
   fPictureButton69->SetToolTipText("Refresh Current Folder");
   fHorizontalFrame34->AddFrame(fPictureButton69, new TGLayoutHints(kLHintsLeft | kLHintsCenterY,2,5,2,2));
   fPictureButton69->Connect("Clicked()", 0, 0, "Refresh()");

   fFileBrowser33->AddFrame(fHorizontalFrame34, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX,2,2,2,2));

   // canvas widget
   TGCanvas *fCanvas72 = new TGCanvas(fFileBrowser33,426,574);

   // canvas viewport
   TGViewPort *fViewPort73 = fCanvas72->GetViewPort();

   // list tree
   TGListTree *fListTree82 = new TGListTree(fCanvas72,kHorizontalFrame);

   const TGPicture *popen;       //used for list tree items
   const TGPicture *pclose;      //used for list tree items

   TGListTreeItem *item0 = fListTree82->AddItem(NULL,"root");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item0->SetPictures(popen, pclose);
   item0->SetTipText("root\nroot of all folders");
   fListTree82->CloseItem(item0);
   TGListTreeItem *item1 = fListTree82->AddItem(NULL,"PROOF Sessions");
   item1->SetPictures(popen, pclose);
   item1->SetTipText("Proofs\nDoubly linked list");
   fListTree82->CloseItem(item1);
   TGListTreeItem *item2 = fListTree82->AddItem(NULL,"ROOT Files");
   item2->SetPictures(popen, pclose);
   item2->SetTipText("Files\nDoubly linked list");
   fListTree82->OpenItem(item2);
   TGListTreeItem *item3 = fListTree82->AddItem(item2,"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root");
   popen = gClient->GetPicture("rootdb_t.xpm__16x16");
   pclose = gClient->GetPicture("rootdb_t.xpm__16x16");
   item3->SetPictures(popen, pclose);
   item3->SetTipText("C:/Users/Jesper/Dropbox/Unive...");
   TGListTreeItem *item4 = fListTree82->AddItem(item3,"allData;1");
   popen = gClient->GetPicture("h2_t.xpm__16x16");
   pclose = gClient->GetPicture("h2_t.xpm__16x16");
   item4->SetPictures(popen, pclose);
   item4->SetTipText("allData\nAl data: E1 vs. Egas ...");
   TGListTreeItem *item5 = fListTree82->AddItem(item3,"midBanan;1");
   item5->SetPictures(popen, pclose);
   item5->SetTipText("midBanan\nMid data: E1 vs. Ega...");
   TGListTreeItem *item6 = fListTree82->AddItem(item3,"bottomBanan;1");
   item6->SetPictures(popen, pclose);
   item6->SetTipText("bottomBanan\nBund data: E1 vs....");
   TGListTreeItem *item7 = fListTree82->AddItem(item3,"bottomBanan2;1");
   item7->SetPictures(popen, pclose);
   item7->SetTipText("bottomBanan2\nBund2 data: E1 v...");
   TGListTreeItem *item8 = fListTree82->AddItem(item3,"bottomLeftBanan;1");
   item8->SetPictures(popen, pclose);
   item8->SetTipText("bottomLeftBanan\nBundLeft data...");
   TGListTreeItem *item9 = fListTree82->AddItem(item3,"leftBanan;1");
   item9->SetPictures(popen, pclose);
   item9->SetTipText("leftBanan\nLeft data: E1 vs. E...");
   TGListTreeItem *item10 = fListTree82->AddItem(item3,"topRightBanan;1");
   item10->SetPictures(popen, pclose);
   item10->SetTipText("topRightBanan\nRight data: E1 ...");
   TGListTreeItem *item11 = fListTree82->AddItem(NULL,"C:\\");
   popen = gClient->GetPicture("hdisk_t.xpm");
   pclose = gClient->GetPicture("hdisk_t.xpm");
   item11->SetPictures(popen, pclose);
   item11->SetTipText("Local Disk (C:)");
   fListTree82->OpenItem(item11);
   TGListTreeItem *item12 = fListTree82->AddItem(item11,"$Recycle.Bin");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item12->SetPictures(popen, pclose);
   TGListTreeItem *item13 = fListTree82->AddItem(item11,"AMD");
   item13->SetPictures(popen, pclose);
   TGListTreeItem *item14 = fListTree82->AddItem(item11,"CM60S");
   item14->SetPictures(popen, pclose);
   TGListTreeItem *item15 = fListTree82->AddItem(item11,"Documents and Settings");
   item15->SetPictures(popen, pclose);
   TGListTreeItem *item16 = fListTree82->AddItem(item11,"Intel");
   item16->SetPictures(popen, pclose);
   TGListTreeItem *item17 = fListTree82->AddItem(item11,"My PDF");
   item17->SetPictures(popen, pclose);
   TGListTreeItem *item18 = fListTree82->AddItem(item11,"PerfLogs");
   item18->SetPictures(popen, pclose);
   TGListTreeItem *item19 = fListTree82->AddItem(item11,"Program Files");
   item19->SetPictures(popen, pclose);
   TGListTreeItem *item20 = fListTree82->AddItem(item11,"Program Files (x86)");
   item20->SetPictures(popen, pclose);
   TGListTreeItem *item21 = fListTree82->AddItem(item11,"ProgramData");
   item21->SetPictures(popen, pclose);
   TGListTreeItem *item22 = fListTree82->AddItem(item11,"Recovery");
   item22->SetPictures(popen, pclose);
   TGListTreeItem *item23 = fListTree82->AddItem(item11,"Riot Games");
   item23->SetPictures(popen, pclose);
   TGListTreeItem *item24 = fListTree82->AddItem(item11,"SWSetup");
   item24->SetPictures(popen, pclose);
   TGListTreeItem *item25 = fListTree82->AddItem(item11,"System Volume Information");
   item25->SetPictures(popen, pclose);
   TGListTreeItem *item26 = fListTree82->AddItem(item11,"TEMP");
   item26->SetPictures(popen, pclose);
   TGListTreeItem *item27 = fListTree82->AddItem(item11,"Users");
   item27->SetPictures(popen, pclose);
   TGListTreeItem *item28 = fListTree82->AddItem(item27,"Default");
   item28->SetPictures(popen, pclose);
   TGListTreeItem *item29 = fListTree82->AddItem(item27,"Default User");
   item29->SetPictures(popen, pclose);
   TGListTreeItem *item30 = fListTree82->AddItem(item27,"Guest");
   item30->SetPictures(popen, pclose);
   TGListTreeItem *item31 = fListTree82->AddItem(item27,"Guys!");
   item31->SetPictures(popen, pclose);
   TGListTreeItem *item32 = fListTree82->AddItem(item27,"Jesper");
   item32->SetPictures(popen, pclose);
   TGListTreeItem *item33 = fListTree82->AddItem(item32,"AppData");
   item33->SetPictures(popen, pclose);
   TGListTreeItem *item34 = fListTree82->AddItem(item32,"Application Data");
   item34->SetPictures(popen, pclose);
   TGListTreeItem *item35 = fListTree82->AddItem(item32,"Contacts");
   item35->SetPictures(popen, pclose);
   TGListTreeItem *item36 = fListTree82->AddItem(item32,"Cookies");
   item36->SetPictures(popen, pclose);
   TGListTreeItem *item37 = fListTree82->AddItem(item32,"Desktop");
   item37->SetPictures(popen, pclose);
   TGListTreeItem *item38 = fListTree82->AddItem(item32,"Documents");
   item38->SetPictures(popen, pclose);
   TGListTreeItem *item39 = fListTree82->AddItem(item32,"Downloads");
   item39->SetPictures(popen, pclose);
   TGListTreeItem *item40 = fListTree82->AddItem(item32,"Dropbox");
   item40->SetPictures(popen, pclose);
   TGListTreeItem *item41 = fListTree82->AddItem(item40,"-Musik");
   item41->SetPictures(popen, pclose);
   TGListTreeItem *item42 = fListTree82->AddItem(item40,"Arbejde");
   item42->SetPictures(popen, pclose);
   TGListTreeItem *item43 = fListTree82->AddItem(item40,"Arduino");
   item43->SetPictures(popen, pclose);
   TGListTreeItem *item44 = fListTree82->AddItem(item40,"Besøg_Jesper_01_11_13");
   item44->SetPictures(popen, pclose);
   TGListTreeItem *item45 = fListTree82->AddItem(item40,"Bolig");
   item45->SetPictures(popen, pclose);
   TGListTreeItem *item46 = fListTree82->AddItem(item40,"Camera Uploads");
   item46->SetPictures(popen, pclose);
   TGListTreeItem *item47 = fListTree82->AddItem(item40,"Eksp. Øvelser");
   item47->SetPictures(popen, pclose);
   TGListTreeItem *item48 = fListTree82->AddItem(item40,"Eksperimentelle-ovelser");
   item48->SetPictures(popen, pclose);
   TGListTreeItem *item49 = fListTree82->AddItem(item40,"Elektronik (1)");
   item49->SetPictures(popen, pclose);
   TGListTreeItem *item50 = fListTree82->AddItem(item40,"Gøgl");
   item50->SetPictures(popen, pclose);
   TGListTreeItem *item51 = fListTree82->AddItem(item40,"Gamle ting");
   item51->SetPictures(popen, pclose);
   TGListTreeItem *item52 = fListTree82->AddItem(item40,"Gode papirer");
   item52->SetPictures(popen, pclose);
   TGListTreeItem *item53 = fListTree82->AddItem(item40,"Højskolen");
   item53->SetPictures(popen, pclose);
   TGListTreeItem *item54 = fListTree82->AddItem(item40,"Holers drikkespil");
   item54->SetPictures(popen, pclose);
   TGListTreeItem *item55 = fListTree82->AddItem(item40,"KeePass Password Safe");
   item55->SetPictures(popen, pclose);
   TGListTreeItem *item56 = fListTree82->AddItem(item40,"Programmering");
   item56->SetPictures(popen, pclose);
   TGListTreeItem *item57 = fListTree82->AddItem(item40,"Project Euler");
   item57->SetPictures(popen, pclose);
   TGListTreeItem *item58 = fListTree82->AddItem(item40,"Rejsedokumenter");
   item58->SetPictures(popen, pclose);
   TGListTreeItem *item59 = fListTree82->AddItem(item40,"Styring og dataopsamling");
   item59->SetPictures(popen, pclose);
   TGListTreeItem *item60 = fListTree82->AddItem(item40,"TimeStamp");
   item60->SetPictures(popen, pclose);
   TGListTreeItem *item61 = fListTree82->AddItem(item40,"Udveksling");
   item61->SetPictures(popen, pclose);
   TGListTreeItem *item62 = fListTree82->AddItem(item40,"Universitetet");
   item62->SetPictures(popen, pclose);
   TGListTreeItem *item63 = fListTree82->AddItem(item62,"1 år");
   item63->SetPictures(popen, pclose);
   TGListTreeItem *item64 = fListTree82->AddItem(item62,"2 år");
   item64->SetPictures(popen, pclose);
   TGListTreeItem *item65 = fListTree82->AddItem(item62,"3 år");
   item65->SetPictures(popen, pclose);
   TGListTreeItem *item66 = fListTree82->AddItem(item65,"Bachelor");
   item66->SetPictures(popen, pclose);
   TGListTreeItem *item67 = fListTree82->AddItem(item66,"Artikler");
   item67->SetPictures(popen, pclose);
   TGListTreeItem *item68 = fListTree82->AddItem(item66,"BachelorLatex");
   item68->SetPictures(popen, pclose);
   TGListTreeItem *item69 = fListTree82->AddItem(item66,"ROOT");
   item69->SetPictures(popen, pclose);
   TGListTreeItem *item70 = fListTree82->AddItem(item69,"VS");
   item70->SetPictures(popen, pclose);
   TGListTreeItem *item71 = fListTree82->AddItem(item70,"ROOT");
   item71->SetPictures(popen, pclose);
   TGListTreeItem *item72 = fListTree82->AddItem(item71,"Debug");
   item72->SetPictures(popen, pclose);
   TGListTreeItem *item73 = fListTree82->AddItem(item71,"ROOT");
   item73->SetPictures(popen, pclose);
   TGListTreeItem *item74 = fListTree82->AddItem(item73,"Data");
   item74->SetPictures(popen, pclose);
   TGListTreeItem *item75 = fListTree82->AddItem(item73,"Debug");
   item75->SetPictures(popen, pclose);
   TGListTreeItem *item76 = fListTree82->AddItem(item73,"Histogrammer");
   item76->SetPictures(popen, pclose);
   TGListTreeItem *item77 = fListTree82->AddItem(item76,"New");
   item77->SetPictures(popen, pclose);
   TGListTreeItem *item78 = fListTree82->AddItem(item77,"beta.root");
   popen = gClient->GetPicture("rootdb_t.xpm__16x16");
   pclose = gClient->GetPicture("rootdb_t.xpm__16x16");
   item78->SetPictures(popen, pclose);
   item78->SetTipText("beta.root\nSize: 19.8K\n2014-05-12 19:38");
   TGListTreeItem *item79 = fListTree82->AddItem(item77,"dssd.root");
   item79->SetPictures(popen, pclose);
   item79->SetTipText("dssd.root\nSize: 16.5K\n2014-05-12 19:40");
   TGListTreeItem *item80 = fListTree82->AddItem(item77,"erik.root");
   item80->SetPictures(popen, pclose);
   item80->SetTipText("erik.root\nSize: 15.6K\n2014-05-11 17:44");
   TGListTreeItem *item81 = fListTree82->AddItem(item77,"laseroff.root");
   item81->SetPictures(popen, pclose);
   item81->SetTipText("laseroff.root\nSize: 35.4K\n2014-05-15 16:13");
   TGListTreeItem *item82 = fListTree82->AddItem(item77,"mg20_gas.root");
   item82->SetPictures(popen, pclose);
   item82->SetTipText("mg20_gas.root\nSize: 5.6K\n2014-05-05 22:08");
   TGListTreeItem *item83 = fListTree82->AddItem(item77,"mg20_silicium.root");
   item83->SetPictures(popen, pclose);
   item83->SetTipText("mg20_silicium.root\nSize: 5.5K\n2014-05-05 22:04");
   TGListTreeItem *item84 = fListTree82->AddItem(item77,"mg21_banana.root");
   item84->SetPictures(popen, pclose);
   item84->SetTipText("mg21_banana.root\nSize: 325.8K\n2014-05-05 22:14");
   TGListTreeItem *item85 = fListTree82->AddItem(item77,"mg21_gas.root");
   item85->SetPictures(popen, pclose);
   item85->SetTipText("mg21_gas.root\nSize: 10.4K\n2014-05-05 22:10");
   TGListTreeItem *item86 = fListTree82->AddItem(item77,"proton21_silicium.root");
   item86->SetPictures(popen, pclose);
   item86->SetTipText("proton21_silicium.root\nSize: 78.7K\n2014-05-18 18:02");
   TGListTreeItem *item87 = fListTree82->AddItem(item77,"si1si2.root");
   item87->SetPictures(popen, pclose);
   item87->SetTipText("si1si2.root\nSize: 86.0K\n2014-05-12 19:42");
   TGListTreeItem *item88 = fListTree82->AddItem(item77,"silicium21_large - No calibration.root");
   item88->SetPictures(popen, pclose);
   item88->SetTipText("silicium21_large - No calibration.root\nSize: 10.8K\n2014-06-30 15:25");
   TGListTreeItem *item89 = fListTree82->AddItem(item77,"silicium21_largeSilicium - No calibration.root");
   item89->SetPictures(popen, pclose);
   item89->SetTipText("silicium21_largeSilicium - No calibration.root\nSize: 9.8K\n2014-05-05 21:45");
   TGListTreeItem *item90 = fListTree82->AddItem(item77,"time.root");
   item90->SetPictures(popen, pclose);
   item90->SetTipText("time.root\nSize: 81.9K\n2014-05-12 18:39");
   TGListTreeItem *item91 = fListTree82->AddItem(item77,"timeSquare.root");
   item91->SetPictures(popen, pclose);
   item91->SetTipText("timeSquare.root\nSize: 253.2K\n2014-05-16 11:14");
   TGListTreeItem *item92 = fListTree82->AddItem(item76,"cuts");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item92->SetPictures(popen, pclose);
   TGListTreeItem *item93 = fListTree82->AddItem(item92,"Smart.txt");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item93->SetPictures(popen, pclose);
   TGListTreeItem *item94 = fListTree82->AddItem(item92,"alphacuts.root");
   popen = gClient->GetPicture("rootdb_t.xpm__16x16");
   pclose = gClient->GetPicture("rootdb_t.xpm__16x16");
   item94->SetPictures(popen, pclose);
   TGListTreeItem *item95 = fListTree82->AddItem(item92,"alphacuts1.root");
   item95->SetPictures(popen, pclose);
   TGListTreeItem *item96 = fListTree82->AddItem(item92,"betabeta.root");
   item96->SetPictures(popen, pclose);
   TGListTreeItem *item97 = fListTree82->AddItem(item92,"betacuts.root");
   item97->SetPictures(popen, pclose);
   TGListTreeItem *item98 = fListTree82->AddItem(item92,"bottomCut.root");
   item98->SetPictures(popen, pclose);
   TGListTreeItem *item99 = fListTree82->AddItem(item92,"bottomCut2.root");
   item99->SetPictures(popen, pclose);
   TGListTreeItem *item100 = fListTree82->AddItem(item99,"CUTG;1");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item100->SetPictures(popen, pclose);
   item100->SetTipText("CUTG\nGraph");
   TGListTreeItem *item101 = fListTree82->AddItem(item92,"bottomLeftCut.root");
   popen = gClient->GetPicture("rootdb_t.xpm__16x16");
   pclose = gClient->GetPicture("rootdb_t.xpm__16x16");
   item101->SetPictures(popen, pclose);
   TGListTreeItem *item102 = fListTree82->AddItem(item92,"extra_cuts.root");
   item102->SetPictures(popen, pclose);
   TGListTreeItem *item103 = fListTree82->AddItem(item92,"leftCut.root");
   item103->SetPictures(popen, pclose);
   TGListTreeItem *item104 = fListTree82->AddItem(item92,"lotofcuts.root");
   item104->SetPictures(popen, pclose);
   TGListTreeItem *item105 = fListTree82->AddItem(item104,"bottom1;1");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item105->SetPictures(popen, pclose);
   item105->SetTipText("bottom1\nGraph");
   TGListTreeItem *item106 = fListTree82->AddItem(item104,"overflow;1");
   item106->SetPictures(popen, pclose);
   item106->SetTipText("overflow\nGraph");
   TGListTreeItem *item107 = fListTree82->AddItem(item104,"left;1");
   item107->SetPictures(popen, pclose);
   item107->SetTipText("left\nGraph");
   TGListTreeItem *item108 = fListTree82->AddItem(item92,"midCut.root");
   popen = gClient->GetPicture("rootdb_t.xpm__16x16");
   pclose = gClient->GetPicture("rootdb_t.xpm__16x16");
   item108->SetPictures(popen, pclose);
   TGListTreeItem *item109 = fListTree82->AddItem(item92,"proton200.root");
   item109->SetPictures(popen, pclose);
   TGListTreeItem *item110 = fListTree82->AddItem(item92,"protoncuts.root");
   item110->SetPictures(popen, pclose);
   TGListTreeItem *item111 = fListTree82->AddItem(item110,"bigcut;1");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item111->SetPictures(popen, pclose);
   item111->SetTipText("bigcut\nGraph");
   TGListTreeItem *item112 = fListTree82->AddItem(item92,"tailcuts - Copy.root");
   popen = gClient->GetPicture("rootdb_t.xpm__16x16");
   pclose = gClient->GetPicture("rootdb_t.xpm__16x16");
   item112->SetPictures(popen, pclose);
   TGListTreeItem *item113 = fListTree82->AddItem(item92,"tailcuts.root");
   item113->SetPictures(popen, pclose);
   TGListTreeItem *item114 = fListTree82->AddItem(item92,"topRightCut.root");
   item114->SetPictures(popen, pclose);
   TGListTreeItem *item115 = fListTree82->AddItem(item76,"rapport");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item115->SetPictures(popen, pclose);
   TGListTreeItem *item116 = fListTree82->AddItem(item76,"bananamg20.root");
   popen = gClient->GetPicture("rootdb_t.xpm__16x16");
   pclose = gClient->GetPicture("rootdb_t.xpm__16x16");
   item116->SetPictures(popen, pclose);
   TGListTreeItem *item117 = fListTree82->AddItem(item76,"cumulated_alpha_cuts.root");
   item117->SetPictures(popen, pclose);
   TGListTreeItem *item118 = fListTree82->AddItem(item76,"proton.pdf");
   popen = gClient->GetPicture("pdf.xpm__16x16");
   pclose = gClient->GetPicture("pdf.xpm__16x16");
   item118->SetPictures(popen, pclose);
   TGListTreeItem *item119 = fListTree82->AddItem(item73,"Histogrammer - Shortcut.lnk");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item119->SetPictures(popen, pclose);
   TGListTreeItem *item120 = fListTree82->AddItem(item73,"Kalibrering");
   item120->SetPictures(popen, pclose);
   TGListTreeItem *item121 = fListTree82->AddItem(item73,"Logs");
   item121->SetPictures(popen, pclose);
   TGListTreeItem *item122 = fListTree82->AddItem(item73,"ROOT - Shortcut.lnk");
   item122->SetPictures(popen, pclose);
   TGListTreeItem *item123 = fListTree82->AddItem(item73,"Release");
   item123->SetPictures(popen, pclose);
   TGListTreeItem *item124 = fListTree82->AddItem(item73,"Results");
   item124->SetPictures(popen, pclose);
   TGListTreeItem *item125 = fListTree82->AddItem(item73,"montecarlo");
   item125->SetPictures(popen, pclose);
   TGListTreeItem *item126 = fListTree82->AddItem(item73,"AnalysisClass.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item126->SetPictures(popen, pclose);
   TGListTreeItem *item127 = fListTree82->AddItem(item73,"Analyzer.h");
   item127->SetPictures(popen, pclose);
   TGListTreeItem *item128 = fListTree82->AddItem(item73,"BananaAnalyzer.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item128->SetPictures(popen, pclose);
   TGListTreeItem *item129 = fListTree82->AddItem(item73,"BananaAnalyzer.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item129->SetPictures(popen, pclose);
   TGListTreeItem *item130 = fListTree82->AddItem(item73,"BetaAnalyzer.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item130->SetPictures(popen, pclose);
   TGListTreeItem *item131 = fListTree82->AddItem(item73,"BetaAnalyzer.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item131->SetPictures(popen, pclose);
   TGListTreeItem *item132 = fListTree82->AddItem(item73,"Calibration.h");
   item132->SetPictures(popen, pclose);
   TGListTreeItem *item133 = fListTree82->AddItem(item73,"CalibrationClass.h");
   item133->SetPictures(popen, pclose);
   TGListTreeItem *item134 = fListTree82->AddItem(item73,"CumuTime.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item134->SetPictures(popen, pclose);
   TGListTreeItem *item135 = fListTree82->AddItem(item73,"Cut.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item135->SetPictures(popen, pclose);
   TGListTreeItem *item136 = fListTree82->AddItem(item73,"Cut1D.h");
   item136->SetPictures(popen, pclose);
   TGListTreeItem *item137 = fListTree82->AddItem(item73,"Cut2D.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item137->SetPictures(popen, pclose);
   TGListTreeItem *item138 = fListTree82->AddItem(item73,"Cut2D.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item138->SetPictures(popen, pclose);
   TGListTreeItem *item139 = fListTree82->AddItem(item73,"Cuts.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item139->SetPictures(popen, pclose);
   TGListTreeItem *item140 = fListTree82->AddItem(item73,"Cuts.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item140->SetPictures(popen, pclose);
   TGListTreeItem *item141 = fListTree82->AddItem(item73,"DSSDAnalyzer.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item141->SetPictures(popen, pclose);
   TGListTreeItem *item142 = fListTree82->AddItem(item73,"DSSDAnalyzer.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item142->SetPictures(popen, pclose);
   TGListTreeItem *item143 = fListTree82->AddItem(item73,"DataLoader.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item143->SetPictures(popen, pclose);
   TGListTreeItem *item144 = fListTree82->AddItem(item73,"DataLoader.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item144->SetPictures(popen, pclose);
   TGListTreeItem *item145 = fListTree82->AddItem(item73,"FileName.dat");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item145->SetPictures(popen, pclose);
   TGListTreeItem *item146 = fListTree82->AddItem(item73,"GasAnalyzer.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item146->SetPictures(popen, pclose);
   TGListTreeItem *item147 = fListTree82->AddItem(item73,"GasAnalyzer.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item147->SetPictures(popen, pclose);
   TGListTreeItem *item148 = fListTree82->AddItem(item73,"IterateSRIM.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item148->SetPictures(popen, pclose);
   TGListTreeItem *item149 = fListTree82->AddItem(item73,"Kolmogorow.cpp");
   item149->SetPictures(popen, pclose);
   TGListTreeItem *item150 = fListTree82->AddItem(item73,"Kolmogorow.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item150->SetPictures(popen, pclose);
   TGListTreeItem *item151 = fListTree82->AddItem(item73,"LaseroffAnalyzer.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item151->SetPictures(popen, pclose);
   TGListTreeItem *item152 = fListTree82->AddItem(item73,"LaseroffAnalyzer.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item152->SetPictures(popen, pclose);
   TGListTreeItem *item153 = fListTree82->AddItem(item73,"Macros.h");
   item153->SetPictures(popen, pclose);
   TGListTreeItem *item154 = fListTree82->AddItem(item73,"Mg20GasAnalyzer.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item154->SetPictures(popen, pclose);
   TGListTreeItem *item155 = fListTree82->AddItem(item73,"Mg20GasAnalyzer.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item155->SetPictures(popen, pclose);
   TGListTreeItem *item156 = fListTree82->AddItem(item73,"Mg20SiliciumAnalyzer.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item156->SetPictures(popen, pclose);
   TGListTreeItem *item157 = fListTree82->AddItem(item73,"Mg20SiliciumAnalyzer.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item157->SetPictures(popen, pclose);
   TGListTreeItem *item158 = fListTree82->AddItem(item73,"MonteCarlo.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item158->SetPictures(popen, pclose);
   TGListTreeItem *item159 = fListTree82->AddItem(item73,"MonteCarlo.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item159->SetPictures(popen, pclose);
   TGListTreeItem *item160 = fListTree82->AddItem(item73,"MonteCarloSimulation.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item160->SetPictures(popen, pclose);
   TGListTreeItem *item161 = fListTree82->AddItem(item73,"ProtonMg21Analyzer.cpp");
   item161->SetPictures(popen, pclose);
   TGListTreeItem *item162 = fListTree82->AddItem(item73,"ProtonMg21Analyzer.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item162->SetPictures(popen, pclose);
   TGListTreeItem *item163 = fListTree82->AddItem(item73,"ROOT.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item163->SetPictures(popen, pclose);
   TGListTreeItem *item164 = fListTree82->AddItem(item73,"ROOT.vcxproj");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item164->SetPictures(popen, pclose);
   TGListTreeItem *item165 = fListTree82->AddItem(item73,"ROOT.vcxproj.filters");
   item165->SetPictures(popen, pclose);
   TGListTreeItem *item166 = fListTree82->AddItem(item73,"ReadMe.txt");
   item166->SetPictures(popen, pclose);
   TGListTreeItem *item167 = fListTree82->AddItem(item73,"RootTCut.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item167->SetPictures(popen, pclose);
   TGListTreeItem *item168 = fListTree82->AddItem(item73,"RootTCut.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item168->SetPictures(popen, pclose);
   TGListTreeItem *item169 = fListTree82->AddItem(item73,"SRIM");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item169->SetPictures(popen, pclose);
   TGListTreeItem *item170 = fListTree82->AddItem(item73,"SRIM.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item170->SetPictures(popen, pclose);
   TGListTreeItem *item171 = fListTree82->AddItem(item73,"SRIM.root");
   popen = gClient->GetPicture("rootdb_t.xpm__16x16");
   pclose = gClient->GetPicture("rootdb_t.xpm__16x16");
   item171->SetPictures(popen, pclose);
   TGListTreeItem *item172 = fListTree82->AddItem(item73,"SRIMLoader.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item172->SetPictures(popen, pclose);
   TGListTreeItem *item173 = fListTree82->AddItem(item73,"SRIMM.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item173->SetPictures(popen, pclose);
   TGListTreeItem *item174 = fListTree82->AddItem(item73,"SRIMM.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item174->SetPictures(popen, pclose);
   TGListTreeItem *item175 = fListTree82->AddItem(item73,"Selector.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item175->SetPictures(popen, pclose);
   TGListTreeItem *item176 = fListTree82->AddItem(item73,"Selector.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item176->SetPictures(popen, pclose);
   TGListTreeItem *item177 = fListTree82->AddItem(item73,"Si1Si2Analyzer.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item177->SetPictures(popen, pclose);
   TGListTreeItem *item178 = fListTree82->AddItem(item73,"Si1Si2Analyzer.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item178->SetPictures(popen, pclose);
   TGListTreeItem *item179 = fListTree82->AddItem(item73,"SiliciumAnalyzer.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item179->SetPictures(popen, pclose);
   TGListTreeItem *item180 = fListTree82->AddItem(item73,"SiliciumAnalyzer.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item180->SetPictures(popen, pclose);
   TGListTreeItem *item181 = fListTree82->AddItem(item73,"TimeAnalysis.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item181->SetPictures(popen, pclose);
   TGListTreeItem *item182 = fListTree82->AddItem(item73,"TimeAnalyzer.cpp");
   item182->SetPictures(popen, pclose);
   TGListTreeItem *item183 = fListTree82->AddItem(item73,"TimeAnalyzer.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item183->SetPictures(popen, pclose);
   TGListTreeItem *item184 = fListTree82->AddItem(item73,"TimeCalc.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item184->SetPictures(popen, pclose);
   TGListTreeItem *item185 = fListTree82->AddItem(item73,"TimeCalc.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item185->SetPictures(popen, pclose);
   TGListTreeItem *item186 = fListTree82->AddItem(item73,"Util.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item186->SetPictures(popen, pclose);
   TGListTreeItem *item187 = fListTree82->AddItem(item73,"Util.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item187->SetPictures(popen, pclose);
   TGListTreeItem *item188 = fListTree82->AddItem(item73,"binOptimize.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item188->SetPictures(popen, pclose);
   TGListTreeItem *item189 = fListTree82->AddItem(item73,"generateHistograms.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item189->SetPictures(popen, pclose);
   TGListTreeItem *item190 = fListTree82->AddItem(item73,"generateTimeHistograms.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item190->SetPictures(popen, pclose);
   TGListTreeItem *item191 = fListTree82->AddItem(item73,"is507.cpp");
   item191->SetPictures(popen, pclose);
   TGListTreeItem *item192 = fListTree82->AddItem(item73,"iteratePeakEnergy.cpp");
   item192->SetPictures(popen, pclose);
   TGListTreeItem *item193 = fListTree82->AddItem(item73,"mg20.dat");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item193->SetPictures(popen, pclose);
   TGListTreeItem *item194 = fListTree82->AddItem(item73,"mg21.dat");
   item194->SetPictures(popen, pclose);
   TGListTreeItem *item195 = fListTree82->AddItem(item73,"mg21_laseroff.dat");
   item195->SetPictures(popen, pclose);
   TGListTreeItem *item196 = fListTree82->AddItem(item73,"stdafx.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item196->SetPictures(popen, pclose);
   TGListTreeItem *item197 = fListTree82->AddItem(item73,"stdafx.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item197->SetPictures(popen, pclose);
   TGListTreeItem *item198 = fListTree82->AddItem(item73,"targetver.h");
   item198->SetPictures(popen, pclose);
   TGListTreeItem *item199 = fListTree82->AddItem(item73,"timeHistograms.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item199->SetPictures(popen, pclose);
   TGListTreeItem *item200 = fListTree82->AddItem(item71,"Release");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item200->SetPictures(popen, pclose);
   TGListTreeItem *item201 = fListTree82->AddItem(item71,"ipch");
   item201->SetPictures(popen, pclose);
   TGListTreeItem *item202 = fListTree82->AddItem(item71,"ROOT.opensdf");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item202->SetPictures(popen, pclose);
   TGListTreeItem *item203 = fListTree82->AddItem(item71,"ROOT.sdf");
   item203->SetPictures(popen, pclose);
   TGListTreeItem *item204 = fListTree82->AddItem(item71,"ROOT.sln");
   item204->SetPictures(popen, pclose);
   TGListTreeItem *item205 = fListTree82->AddItem(item71,"ROOT.v12.suo");
   item205->SetPictures(popen, pclose);
   TGListTreeItem *item206 = fListTree82->AddItem(item70,"desktop.ini");
   item206->SetPictures(popen, pclose);
   TGListTreeItem *item207 = fListTree82->AddItem(item69,"Jesper.zip");
   item207->SetPictures(popen, pclose);
   TGListTreeItem *item208 = fListTree82->AddItem(item69,"divingROOT.zip");
   item208->SetPictures(popen, pclose);
   TGListTreeItem *item209 = fListTree82->AddItem(item69,"diving_into_ROOT.pdf");
   popen = gClient->GetPicture("pdf.xpm__16x16");
   pclose = gClient->GetPicture("pdf.xpm__16x16");
   item209->SetPictures(popen, pclose);
   TGListTreeItem *item210 = fListTree82->AddItem(item69,"histo_21mg.root");
   popen = gClient->GetPicture("rootdb_t.xpm__16x16");
   pclose = gClient->GetPicture("rootdb_t.xpm__16x16");
   item210->SetPictures(popen, pclose);
   TGListTreeItem *item211 = fListTree82->AddItem(item69,"is5072.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item211->SetPictures(popen, pclose);
   TGListTreeItem *item212 = fListTree82->AddItem(item69,"is5072_cpp.d");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item212->SetPictures(popen, pclose);
   TGListTreeItem *item213 = fListTree82->AddItem(item69,"is5072_cpp_ACLiC_dict.def");
   item213->SetPictures(popen, pclose);
   TGListTreeItem *item214 = fListTree82->AddItem(item66,"Bachelor-master.pdf");
   popen = gClient->GetPicture("pdf.xpm__16x16");
   pclose = gClient->GetPicture("pdf.xpm__16x16");
   item214->SetPictures(popen, pclose);
   TGListTreeItem *item215 = fListTree82->AddItem(item66,"Lecture5-FK4002-2011.pdf");
   item215->SetPictures(popen, pclose);
   TGListTreeItem *item216 = fListTree82->AddItem(item66,"Opsætning.txt");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item216->SetPictures(popen, pclose);
   TGListTreeItem *item217 = fListTree82->AddItem(item66,"Rapport - husk.txt");
   item217->SetPictures(popen, pclose);
   TGListTreeItem *item218 = fListTree82->AddItem(item66,"SPSC05_C22014022410200.pdf");
   popen = gClient->GetPicture("pdf.xpm__16x16");
   pclose = gClient->GetPicture("pdf.xpm__16x16");
   item218->SetPictures(popen, pclose);
   TGListTreeItem *item219 = fListTree82->AddItem(item66,"TODO.txt");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item219->SetPictures(popen, pclose);
   TGListTreeItem *item220 = fListTree82->AddItem(item66,"The C++ Programming.Language.4th.Edition.Jun.2013[A4].pdf");
   popen = gClient->GetPicture("pdf.xpm__16x16");
   pclose = gClient->GetPicture("pdf.xpm__16x16");
   item220->SetPictures(popen, pclose);
   TGListTreeItem *item221 = fListTree82->AddItem(item66,"phy310-lecture-11-2007.pdf");
   item221->SetPictures(popen, pclose);
   TGListTreeItem *item222 = fListTree82->AddItem(item65,"EksØvelser");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item222->SetPictures(popen, pclose);
   TGListTreeItem *item223 = fListTree82->AddItem(item65,"Elektronik");
   item223->SetPictures(popen, pclose);
   TGListTreeItem *item224 = fListTree82->AddItem(item65,"Q1");
   item224->SetPictures(popen, pclose);
   TGListTreeItem *item225 = fListTree82->AddItem(item65,"Q2");
   item225->SetPictures(popen, pclose);
   TGListTreeItem *item226 = fListTree82->AddItem(item65,"Styring og dataopsamling");
   item226->SetPictures(popen, pclose);
   TGListTreeItem *item227 = fListTree82->AddItem(item65,"Nyttige links.pdf");
   popen = gClient->GetPicture("pdf.xpm__16x16");
   pclose = gClient->GetPicture("pdf.xpm__16x16");
   item227->SetPictures(popen, pclose);
   TGListTreeItem *item228 = fListTree82->AddItem(item65,"no_series_145.pdf");
   item228->SetPictures(popen, pclose);
   TGListTreeItem *item229 = fListTree82->AddItem(item62,"AulaClient");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item229->SetPictures(popen, pclose);
   TGListTreeItem *item230 = fListTree82->AddItem(item62,"Gøgl");
   item230->SetPictures(popen, pclose);
   TGListTreeItem *item231 = fListTree82->AddItem(item62,"0-10.pdf");
   popen = gClient->GetPicture("pdf.xpm__16x16");
   pclose = gClient->GetPicture("pdf.xpm__16x16");
   item231->SetPictures(popen, pclose);
   TGListTreeItem *item232 = fListTree82->AddItem(item62,"3");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item232->SetPictures(popen, pclose);
   TGListTreeItem *item233 = fListTree82->AddItem(item62,"622843.pdf");
   popen = gClient->GetPicture("pdf.xpm__16x16");
   pclose = gClient->GetPicture("pdf.xpm__16x16");
   item233->SetPictures(popen, pclose);
   TGListTreeItem *item234 = fListTree82->AddItem(item62,"myexpm.m");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item234->SetPictures(popen, pclose);
   TGListTreeItem *item235 = fListTree82->AddItem(item40,"amatoerssports-Hjemmeside");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item235->SetPictures(popen, pclose);
   TGListTreeItem *item236 = fListTree82->AddItem(item40,"johanne");
   item236->SetPictures(popen, pclose);
   TGListTreeItem *item237 = fListTree82->AddItem(item40,"ønskeseddel.docx");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item237->SetPictures(popen, pclose);
   TGListTreeItem *item238 = fListTree82->AddItem(item40,"Cut_through_turbomolecular_pump.jpg");
   popen = gClient->GetPicture("psp_t.xpm__16x16");
   pclose = gClient->GetPicture("psp_t.xpm__16x16");
   item238->SetPictures(popen, pclose);
   TGListTreeItem *item239 = fListTree82->AddItem(item40,"Faradays lov.pptx");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item239->SetPictures(popen, pclose);
   TGListTreeItem *item240 = fListTree82->AddItem(item40,"Itinerary-JY163260-20140310122840.pdf");
   popen = gClient->GetPicture("pdf.xpm__16x16");
   pclose = gClient->GetPicture("pdf.xpm__16x16");
   item240->SetPictures(popen, pclose);
   TGListTreeItem *item241 = fListTree82->AddItem(item40,"PDFClipper.jar");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item241->SetPictures(popen, pclose);
   TGListTreeItem *item242 = fListTree82->AddItem(item40,"Stepper.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item242->SetPictures(popen, pclose);
   TGListTreeItem *item243 = fListTree82->AddItem(item40,"TreeViewer.jar");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item243->SetPictures(popen, pclose);
   TGListTreeItem *item244 = fListTree82->AddItem(item40,"desktop.ini");
   item244->SetPictures(popen, pclose);
   TGListTreeItem *item245 = fListTree82->AddItem(item40,"jlatexmath-1.0.3.jar");
   item245->SetPictures(popen, pclose);
   TGListTreeItem *item246 = fListTree82->AddItem(item40,"uml.svg");
   item246->SetPictures(popen, pclose);
   TGListTreeItem *item247 = fListTree82->AddItem(item40,"uml.uxf");
   item247->SetPictures(popen, pclose);
   TGListTreeItem *item248 = fListTree82->AddItem(item32,"Favorites");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item248->SetPictures(popen, pclose);
   TGListTreeItem *item249 = fListTree82->AddItem(item32,"IdeaProjects");
   item249->SetPictures(popen, pclose);
   TGListTreeItem *item250 = fListTree82->AddItem(item32,"Links");
   item250->SetPictures(popen, pclose);
   TGListTreeItem *item251 = fListTree82->AddItem(item32,"Local Settings");
   item251->SetPictures(popen, pclose);
   TGListTreeItem *item252 = fListTree82->AddItem(item32,"Music");
   item252->SetPictures(popen, pclose);
   TGListTreeItem *item253 = fListTree82->AddItem(item32,"My Documents");
   item253->SetPictures(popen, pclose);
   TGListTreeItem *item254 = fListTree82->AddItem(item32,"NetHood");
   item254->SetPictures(popen, pclose);
   TGListTreeItem *item255 = fListTree82->AddItem(item32,"Pictures");
   item255->SetPictures(popen, pclose);
   TGListTreeItem *item256 = fListTree82->AddItem(item32,"PrintHood");
   item256->SetPictures(popen, pclose);
   TGListTreeItem *item257 = fListTree82->AddItem(item32,"Recent");
   item257->SetPictures(popen, pclose);
   TGListTreeItem *item258 = fListTree82->AddItem(item32,"Saved Games");
   item258->SetPictures(popen, pclose);
   TGListTreeItem *item259 = fListTree82->AddItem(item32,"Searches");
   item259->SetPictures(popen, pclose);
   TGListTreeItem *item260 = fListTree82->AddItem(item32,"SendTo");
   item260->SetPictures(popen, pclose);
   TGListTreeItem *item261 = fListTree82->AddItem(item32,"Start Menu");
   item261->SetPictures(popen, pclose);
   TGListTreeItem *item262 = fListTree82->AddItem(item32,"Templates");
   item262->SetPictures(popen, pclose);
   TGListTreeItem *item263 = fListTree82->AddItem(item32,"UMLet");
   item263->SetPictures(popen, pclose);
   TGListTreeItem *item264 = fListTree82->AddItem(item32,"Videos");
   item264->SetPictures(popen, pclose);
   TGListTreeItem *item265 = fListTree82->AddItem(item32,"git");
   item265->SetPictures(popen, pclose);
   TGListTreeItem *item266 = fListTree82->AddItem(item32,"pdfscissors");
   item266->SetPictures(popen, pclose);
   TGListTreeItem *item267 = fListTree82->AddItem(item32,"qugame");
   item267->SetPictures(popen, pclose);
   TGListTreeItem *item268 = fListTree82->AddItem(item32,"workspace");
   item268->SetPictures(popen, pclose);
   TGListTreeItem *item269 = fListTree82->AddItem(item32,"NTUSER.DAT");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item269->SetPictures(popen, pclose);
   TGListTreeItem *item270 = fListTree82->AddItem(item32,"NTUSER.DAT{97e1de87-d6fa-11e1-be62-94c0340a1222}.TM.blf");
   item270->SetPictures(popen, pclose);
   TGListTreeItem *item271 = fListTree82->AddItem(item32,"NTUSER.DAT{97e1de87-d6fa-11e1-be62-94c0340a1222}.TMContainer00000000000000000001.regtrans-ms");
   item271->SetPictures(popen, pclose);
   TGListTreeItem *item272 = fListTree82->AddItem(item32,"NTUSER.DAT{97e1de87-d6fa-11e1-be62-94c0340a1222}.TMContainer00000000000000000002.regtrans-ms");
   item272->SetPictures(popen, pclose);
   TGListTreeItem *item273 = fListTree82->AddItem(item32,"_viminfo");
   item273->SetPictures(popen, pclose);
   TGListTreeItem *item274 = fListTree82->AddItem(item32,"bashrc");
   item274->SetPictures(popen, pclose);
   TGListTreeItem *item275 = fListTree82->AddItem(item32,"danid.log");
   item275->SetPictures(popen, pclose);
   TGListTreeItem *item276 = fListTree82->AddItem(item32,"ntuser.dat.LOG1");
   item276->SetPictures(popen, pclose);
   TGListTreeItem *item277 = fListTree82->AddItem(item32,"ntuser.dat.LOG2");
   item277->SetPictures(popen, pclose);
   TGListTreeItem *item278 = fListTree82->AddItem(item32,"ntuser.ini");
   item278->SetPictures(popen, pclose);
   TGListTreeItem *item279 = fListTree82->AddItem(item32,"psv.ini");
   item279->SetPictures(popen, pclose);
   TGListTreeItem *item280 = fListTree82->AddItem(item27,"Public");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item280->SetPictures(popen, pclose);
   TGListTreeItem *item281 = fListTree82->AddItem(item27,"All Users");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item281->SetPictures(popen, pclose);
   TGListTreeItem *item282 = fListTree82->AddItem(item27,"desktop.ini");
   item282->SetPictures(popen, pclose);
   TGListTreeItem *item283 = fListTree82->AddItem(item11,"Windows");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item283->SetPictures(popen, pclose);
   TGListTreeItem *item284 = fListTree82->AddItem(item11,"glassfish3");
   item284->SetPictures(popen, pclose);
   TGListTreeItem *item285 = fListTree82->AddItem(item11,"root");
   item285->SetPictures(popen, pclose);
   TGListTreeItem *item286 = fListTree82->AddItem(item11,"texlive");
   item286->SetPictures(popen, pclose);
   TGListTreeItem *item287 = fListTree82->AddItem(item11,"ubuntu");
   item287->SetPictures(popen, pclose);
   TGListTreeItem *item288 = fListTree82->AddItem(item11,"BOOTNXT");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item288->SetPictures(popen, pclose);
   TGListTreeItem *item289 = fListTree82->AddItem(item11,"bootmgr");
   item289->SetPictures(popen, pclose);
   TGListTreeItem *item290 = fListTree82->AddItem(item11,"hiberfil.sys");
   item290->SetPictures(popen, pclose);
   TGListTreeItem *item291 = fListTree82->AddItem(item11,"pagefile.sys");
   item291->SetPictures(popen, pclose);
   TGListTreeItem *item292 = fListTree82->AddItem(item11,"swapfile.sys");
   item292->SetPictures(popen, pclose);
   TGListTreeItem *item293 = fListTree82->AddItem(item11,"wubildr");
   item293->SetPictures(popen, pclose);
   TGListTreeItem *item294 = fListTree82->AddItem(item11,"wubildr.mbr");
   item294->SetPictures(popen, pclose);
   TGListTreeItem *item295 = fListTree82->AddItem(NULL,"D:\\");
   popen = gClient->GetPicture("hdisk_t.xpm");
   pclose = gClient->GetPicture("hdisk_t.xpm");
   item295->SetPictures(popen, pclose);
   item295->SetTipText("Local Disk (D:)");
   fListTree82->CloseItem(item295);
   TGListTreeItem *item296 = fListTree82->AddItem(NULL,"E:\\");
   popen = gClient->GetPicture("cdrom_t.xpm");
   pclose = gClient->GetPicture("cdrom_t.xpm");
   item296->SetPictures(popen, pclose);
   item296->SetTipText("CD/DVD Drive (E:)");
   fListTree82->CloseItem(item296);

   fViewPort73->AddFrame(fListTree82);
   fListTree82->SetLayoutManager(new TGHorizontalLayout(fListTree82));
   fListTree82->MapSubwindows();
   fCanvas72->SetContainer(fListTree82);
   fCanvas72->MapSubwindows();
   fCanvas72->SetHsbPosition(0);
   fCanvas72->SetVsbPosition(1318);
   fFileBrowser33->AddFrame(fCanvas72, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY));

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame83 = new TGHorizontalFrame(fFileBrowser33,422,24,kHorizontalFrame);
   TGLabel *fLabel84 = new TGLabel(fHorizontalFrame83,"Filter: ");
   fLabel84->SetTextJustify(36);
   fLabel84->SetMargins(0,0,0,0);
   fLabel84->SetWrapLength(-1);
   fHorizontalFrame83->AddFrame(fLabel84, new TGLayoutHints(kLHintsLeft | kLHintsCenterY,2,2,2,2));

   gClient->GetColorByName("#ffffff",ucolor);

   // combo box
   TGComboBox *fComboBox85 = new TGComboBox(fHorizontalFrame83," All Files (*.*)",-1,kHorizontalFrame | kSunkenFrame | kDoubleBorder | kOwnBackground);
   fComboBox85->AddEntry(" All Files (*.*)",1);
   fComboBox85->AddEntry(" C/C++ Files (*.c;*.cxx;*.h;...)",2);
   fComboBox85->AddEntry(" ROOT Files (*.root)",3);
   fComboBox85->AddEntry(" Text Files (*.txt)",4);
   fComboBox85->Resize(381,20);
   fComboBox85->Select(-1);
   fHorizontalFrame83->AddFrame(fComboBox85, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX,2,2,2,2));
   fComboBox85->Connect("Selected(int)", 0, 0, "ApplyFilter(int)");

   fFileBrowser33->AddFrame(fHorizontalFrame83, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX,2,2,2,2));

   fCompositeFrame32->AddFrame(fFileBrowser33, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fFileBrowser33->Connect("ProcessedConfigure(Event_t*)", 0, 0, "Layout()");


   fTab19->SetTab(0);

   fTab19->Resize(fTab19->GetDefaultSize());
   fVerticalFrame15->AddFrame(fTab19, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY,2,2,2,2));

   fHorizontalFrame14->AddFrame(fVerticalFrame15, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandY));
   TGVSplitter *fVSplitter21 = new TGVSplitter(fHorizontalFrame14,4,661);
   fVSplitter21->SetFrame(fVerticalFrame15,kTRUE);
   fHorizontalFrame14->AddFrame(fVSplitter21, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandY));

   // vertical frame
   TGVerticalFrame *fVerticalFrame16 = new TGVerticalFrame(fHorizontalFrame14,928,661,kVerticalFrame);

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame17 = new TGHorizontalFrame(fVerticalFrame16,924,553,kHorizontalFrame);

   // tab widget
   TGTab *fTab22 = new TGTab(fHorizontalFrame17,924,553);

   // container of "Canvas_1"
   TGCompositeFrame *fCompositeFrame102;
   fCompositeFrame102 = fTab22->AddTab("Canvas_1");
   fCompositeFrame102->SetLayoutManager(new TGVerticalLayout(fCompositeFrame102));

   // composite frame
   TGCompositeFrame *fRootCanvas103 = new TGCompositeFrame(fCompositeFrame102,920,528,kVerticalFrame);
   TGHorizontal3DLine *fHorizontal3DLine121 = new TGHorizontal3DLine(fRootCanvas103,700,2);
   fRootCanvas103->AddFrame(fHorizontal3DLine121, new TGLayoutHints(kLHintsTop | kLHintsExpandX));

   // dockable frame
   TGDockableFrame *fDockableFrame122 = new TGDockableFrame(fRootCanvas103);

   // next lines belong to the dockable frame widget
   fDockableFrame122->EnableUndock(kTRUE);
   fDockableFrame122->EnableHide(kFALSE);
   fDockableFrame122->SetWindowName("ToolBar: Canvas_1");
   fDockableFrame122->DockContainer();

   fRootCanvas103->AddFrame(fDockableFrame122, new TGLayoutHints(kLHintsExpandX));
   TGHorizontal3DLine *fHorizontal3DLine127 = new TGHorizontal3DLine(fRootCanvas103,700,2);
   fRootCanvas103->AddFrame(fHorizontal3DLine127, new TGLayoutHints(kLHintsTop | kLHintsExpandX));

   // composite frame
   TGCompositeFrame *fCompositeFrame128 = new TGCompositeFrame(fRootCanvas103,920,528,kHorizontalFrame);

   // composite frame
   TGCompositeFrame *fCompositeFrame129 = new TGCompositeFrame(fCompositeFrame128,175,476,kFixedWidth);
   fCompositeFrame129->SetLayoutManager(new TGVerticalLayout(fCompositeFrame129));

   fCompositeFrame128->AddFrame(fCompositeFrame129, new TGLayoutHints(kLHintsLeft | kLHintsExpandY));

   // canvas widget
   TGCanvas *fCanvas130 = new TGCanvas(fCompositeFrame128,920,528);

   // canvas viewport
   TGViewPort *fViewPort131 = fCanvas130->GetViewPort();

   // canvas container
   Int_t canvasID = gVirtualX->InitWindow((ULong_t)fCanvas130->GetId());
   Window_t winC = gVirtualX->GetWindowID(canvasID);
   TGCompositeFrame *fCompositeFrame140 = new TGCompositeFrame(gClient,winC,fViewPort131);
   fViewPort131->AddFrame(fCompositeFrame140);
   fCompositeFrame140->SetLayoutManager(new TGVerticalLayout(fCompositeFrame140));
   fCompositeFrame140->MapSubwindows();
   fCanvas130->SetContainer(fCompositeFrame140);
   fCanvas130->MapSubwindows();
   fCompositeFrame128->AddFrame(fCanvas130, new TGLayoutHints(kLHintsRight | kLHintsExpandX | kLHintsExpandY));

   fRootCanvas103->AddFrame(fCompositeFrame128, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));

   // status bar
   TGStatusBar *fStatusBar143 = new TGStatusBar(fRootCanvas103,10,18);
   Int_t partsusBar143[] = {33,10,10,47};
   fStatusBar143->SetParts(partsusBar143,4);
   fRootCanvas103->AddFrame(fStatusBar143, new TGLayoutHints(kLHintsLeft | kLHintsBottom | kLHintsExpandX,2,2,1,1));

   fCompositeFrame102->AddFrame(fRootCanvas103, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fRootCanvas103->Connect("ProcessedConfigure(Event_t*)", 0, 0, "Layout()");

   TGTabElement *tab0 = fTab22->GetTabTab(0);
   tab0->ShowClose(kTRUE);

   // container of "Editor 1"
   TGCompositeFrame *fCompositeFrame151;
   fCompositeFrame151 = fTab22->AddTab("Editor 1");
   fCompositeFrame151->SetLayoutManager(new TGVerticalLayout(fCompositeFrame151));

   // composite frame
   TGCompositeFrame *fTextEditor152 = new TGCompositeFrame(fCompositeFrame151,920,528,kVerticalFrame);
   TGHorizontal3DLine *fHorizontal3DLine165 = new TGHorizontal3DLine(fTextEditor152,920,2);
   fTextEditor152->AddFrame(fHorizontal3DLine165, new TGLayoutHints(kLHintsTop | kLHintsExpandX,0,0,2,2));

   // tool bar
   TGToolBar *fToolBar166 = new TGToolBar(fTextEditor152,920,26,kHorizontalFrame);

   ToolBarData_t t;
   t.fPixmap = "ed_new.png";
   t.fTipText = "New File";
   t.fStayDown = kFALSE;
   t.fId = 1;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,8);
   t.fPixmap = "ed_open.png";
   t.fTipText = "Open File";
   t.fStayDown = kFALSE;
   t.fId = 2;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,0);
   t.fPixmap = "ed_save.png";
   t.fTipText = "Save File";
   t.fStayDown = kFALSE;
   t.fId = 3;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,0);
   t.fPixmap = "ed_saveas.png";
   t.fTipText = "Save File As...";
   t.fStayDown = kFALSE;
   t.fId = 4;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,0);
   t.fPixmap = "ed_print.png";
   t.fTipText = "Print";
   t.fStayDown = kFALSE;
   t.fId = 5;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,8);
   t.fPixmap = "ed_cut.png";
   t.fTipText = "Cut selection";
   t.fStayDown = kFALSE;
   t.fId = 6;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,8);
   TGButton *fPictureButton182 = t.fButton;
   fPictureButton182->SetState(kButtonDisabled);
   t.fPixmap = "ed_copy.png";
   t.fTipText = "Copy selection";
   t.fStayDown = kFALSE;
   t.fId = 7;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,0);
   TGButton *fPictureButton185 = t.fButton;
   fPictureButton185->SetState(kButtonDisabled);
   t.fPixmap = "ed_paste.png";
   t.fTipText = "Paste selection";
   t.fStayDown = kFALSE;
   t.fId = 8;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,0);
   t.fPixmap = "ed_delete.png";
   t.fTipText = "Delete selection";
   t.fStayDown = kFALSE;
   t.fId = 9;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,0);
   TGButton *fPictureButton191 = t.fButton;
   fPictureButton191->SetState(kButtonDisabled);
   t.fPixmap = "ed_find.png";
   t.fTipText = "Find...";
   t.fStayDown = kFALSE;
   t.fId = 10;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,8);
   t.fPixmap = "ed_findnext.png";
   t.fTipText = "Find next";
   t.fStayDown = kFALSE;
   t.fId = 11;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,0);
   t.fPixmap = "ed_goto.png";
   t.fTipText = "Goto...";
   t.fStayDown = kFALSE;
   t.fId = 12;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,0);
   t.fPixmap = "ed_compile.png";
   t.fTipText = "Compile Macro";
   t.fStayDown = kFALSE;
   t.fId = 13;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,8);
   t.fPixmap = "ed_execute.png";
   t.fTipText = "Execute Macro";
   t.fStayDown = kFALSE;
   t.fId = 14;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,0);
   t.fPixmap = "ed_interrupt.png";
   t.fTipText = "Interrupt";
   t.fStayDown = kFALSE;
   t.fId = 15;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,0);
   t.fPixmap = "ed_help.png";
   t.fTipText = "Help Contents";
   t.fStayDown = kFALSE;
   t.fId = 16;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,8);
   t.fPixmap = "ed_quit.png";
   t.fTipText = "Close Editor";
   t.fStayDown = kFALSE;
   t.fId = 17;
   t.fButton = 0;
   fToolBar166->AddButton(fTextEditor152,&t,8);
   TGButton *fPictureButton215 = t.fButton;
   fPictureButton215->SetState(kButtonDisabled);
   fTextEditor152->AddFrame(fToolBar166, new TGLayoutHints(kLHintsTop | kLHintsExpandX));
   TGHorizontal3DLine *fHorizontal3DLine230 = new TGHorizontal3DLine(fTextEditor152,920,2);
   fTextEditor152->AddFrame(fHorizontal3DLine230, new TGLayoutHints(kLHintsTop | kLHintsExpandX,0,0,2,2));
   TGTextEdit *fTextEdit231 = new TGTextEdit(fTextEditor152,920,469);
   fTextEdit231->LoadFile("setAxisTitles_exec");
   fTextEditor152->AddFrame(fTextEdit231, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fTextEdit231->Connect("DataDropped(char*)", 0, 0, "DataDropped(char*)");

   // status bar
   TGStatusBar *fStatusBar242 = new TGStatusBar(fTextEditor152,920,18);
   Int_t partsusBar242[] = {75,25};
   fStatusBar242->SetParts(partsusBar242,2);
   fStatusBar242->SetText("setAxisTitles: 3 lines written.",0);
   fStatusBar242->SetText("Ln 2, Ch 21",1);
   fTextEditor152->AddFrame(fStatusBar242, new TGLayoutHints(kLHintsBottom | kLHintsExpandX,0,0,3,0));

   fCompositeFrame151->AddFrame(fTextEditor152, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fTextEditor152->Connect("ProcessedConfigure(Event_t*)", 0, 0, "Layout()");

   TGTabElement *tab1 = fTab22->GetTabTab(1);
   tab1->ShowClose(kTRUE);

   fTab22->SetTab(1);

   fTab22->Resize(fTab22->GetDefaultSize());
   fHorizontalFrame17->AddFrame(fTab22, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY));
   fTab22->Connect("CloseTab(int)", 0, 0, "CloseTab(int)");

   fVerticalFrame16->AddFrame(fHorizontalFrame17, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY,2,2,2,2));
   TGHSplitter *fHSplitter24 = new TGHSplitter(fVerticalFrame16,928,4);
   fVerticalFrame16->AddFrame(fHSplitter24, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX));

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame18 = new TGHorizontalFrame(fVerticalFrame16,928,100,kHorizontalFrame | kFixedHeight);

   // tab widget
   TGTab *fTab25 = new TGTab(fHorizontalFrame18,924,96);

   // container of "Command"
   TGCompositeFrame *fCompositeFrame247;
   fCompositeFrame247 = fTab25->AddTab("Command");
   fCompositeFrame247->SetLayoutManager(new TGVerticalLayout(fCompositeFrame247));

   // composite frame
   TGCompositeFrame *fCommandPlugin248 = new TGCompositeFrame(fCompositeFrame247,920,71,kVerticalFrame);

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame249 = new TGHorizontalFrame(fCommandPlugin248,914,24,kHorizontalFrame);

   gClient->GetColorByName("#ffffff",ucolor);

   // combo box
   TGComboBox *fComboBox250 = new TGComboBox(fHorizontalFrame249,"",1,kHorizontalFrame | kSunkenFrame | kDoubleBorder | kOwnBackground);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry("gStyle->SetOptStyle(0);",0);
   fComboBox250->AddEntry("gStyle->SetOptStyle(0);",0);
   fComboBox250->AddEntry("gStyle->SetOptStyle(0);",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid_2.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid_2.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid.root\")",0);
   fComboBox250->AddEntry("log(2)/9.61941e-5",0);
   fComboBox250->AddEntry("log(2)/-9.61941e-5",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/laseroff.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/rapport/laseroff.root\")",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0);",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0);",0);
   fComboBox250->AddEntry("'",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0);",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0);",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/proton21_silicium.root\")",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0)",0);
   fComboBox250->AddEntry("gStyle-SetOptStat(0)",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/proton21_silicium.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_largeSilicium - No calibration.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0)",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid_sig.root\")",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0)",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid.root\")",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0)",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid_2.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid_2.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid_2.root\")",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0);",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0);",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_gas.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_gas.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry("12.0*2.79/5.0/1.19",0);
   fComboBox250->AddEntry("12/5",0);
   fComboBox250->AddEntry("12&5",0);
   fComboBox250->AddEntry("exp(log(2)/t_2 - log(2)/t_1)",0);
   fComboBox250->AddEntry("double t_2 = 1.219e-18",0);
   fComboBox250->AddEntry("double t_1 = 5.105e-19",0);
   fComboBox250->AddEntry("log(2)",0);
   fComboBox250->AddEntry("@",0);
   fComboBox250->AddEntry("log(2)",0);
   fComboBox250->AddEntry("log(29",0);
   fComboBox250->AddEntry("0.0279/0.0119*exp((log(2)/1.219e-18 - log(2)/5.105e-19)*1.2)",0);
   fComboBox250->AddEntry("log(2)",0);
   fComboBox250->AddEntry("0.0279/0.0119*exp((log(2)/1.219e-18 - log(2)/5.105e-19)*1.2)",0);
   fComboBox250->AddEntry("0.0279/0.0119*exp((1.219e-18 - 5.105e-19)*1.2)",0);
   fComboBox250->AddEntry("0.0279/0.0119*exp(1.219e-18 - 5.105e-19)*1.2)",0);
   fComboBox250->AddEntry("niv2 = -25.752-1.15055*TMath::Power(21,1/6)*TMath::Sqrt(11)+1.5913*11/TMath::Sqrt(8.816-6.560)",0);
   fComboBox250->AddEntry("TMath::Power(10, -17.914)",0);
   fComboBox250->AddEntry("-25.752-1.15055*TMath::Power(21,1/6)*TMath::Sqrt(11)+1.5913*11/TMath::Sqrt(2.256)",0);
   fComboBox250->AddEntry("TMath::Power(10, -18.292)",0);
   fComboBox250->AddEntry("TMath::Power(10, -18.29)",0);
   fComboBox250->AddEntry("-25.752-1.15055*TMath::Power(21,1/6)*TMath::Sqrt(11)+1.5913*11/TMath::Sqrt(2.410)",0);
   fComboBox250->AddEntry("TMath::Power(10, -29.211)",0);
   fComboBox250->AddEntry("-25.752-1.15055*TMath::Power(21,1/6)*TMath::Sqrt(11)+1.5913*11/TMath::Sqrt(2410)",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry("TMath::Power(10,niv2)",0);
   fComboBox250->AddEntry("TMath::Power(10,niv1)",0);
   fComboBox250->AddEntry("Math::Power(10,niv1)",0);
   fComboBox250->AddEntry("niv2 = -25.752-1.15055*TMath::Power(21,1/6)*TMath::Sqrt(11)+1.5913*11/TMath::Sqrt(8.816-6.560)",0);
   fComboBox250->AddEntry("niv1 = -25.752-1.15055*TMath::Power(21,1/6)*TMath::Sqrt(11)+1.5913*11/TMath::Sqrt(8.970-6.560)",0);
   fComboBox250->AddEntry("-25.752-1.15055*TMath::Power(21,1/6)*TMath::Sqrt(11)+1.5913*11/TMath::Sqrt(8.816-6.560)",0);
   fComboBox250->AddEntry("-25.752-1.15055*TMath::Power(21,1/6)*TMath::Sqrt(11)+1.5913*11/TMath::Sqrt(8.970-6.560)",0);
   fComboBox250->AddEntry("-25.752-1.15055*TMath::Power(21,1/6)*TMath::sqrt(11)+1.5913*11/TMath::sqrt(8.970-6.560)",0);
   fComboBox250->AddEntry("TMath::Power(2,3)",0);
   fComboBox250->AddEntry("TMath::Power(3,3)",0);
   fComboBox250->AddEntry("TMath::Power(3,2)",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_gas.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_gas.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_gas.root\")",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/proton21_silicium.root\")",0);
   fComboBox250->AddEntry("log(2)/(5.92189e-3+2.42683e-5)",0);
   fComboBox250->AddEntry("log(2)/(5.92189e-3)",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry("5.0/122.0",0);
   fComboBox250->AddEntry("5/122",0);
   fComboBox250->AddEntry("exp(log(2)/5*1200)",0);
   fComboBox250->AddEntry("log(exp(1))",0);
   fComboBox250->AddEntry("log(e)",0);
   fComboBox250->AddEntry("log(2)",0);
   fComboBox250->AddEntry("log(2)/(5.92e-3)",0);
   fComboBox250->AddEntry("log(2)/(5.93e-3)",0);
   fComboBox250->AddEntry("log(2)/(5.84010e-3)",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry("Slope",0);
   fComboBox250->AddEntry("log(2)/(5.853e+3+3.42e-5)",0);
   fComboBox250->AddEntry("log(2)/(5.853e-3+3.42e-5)",0);
   fComboBox250->AddEntry("log(2)/((5.853+3.42)*1e-5)",0);
   fComboBox250->AddEntry("log(2)/((5.853+3.4)2e-5)",0);
   fComboBox250->AddEntry("0.693/3.42e-5",0);
   fComboBox250->AddEntry("0.693/5.85344e-3",0);
   fComboBox250->AddEntry("1/5.85344",0);
   fComboBox250->AddEntry("log(2)/5.85344",0);
   fComboBox250->AddEntry("log(2)/5.91961",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_gas.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_gas.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_gas.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_gas.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_gas.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/cuts/tailcuts.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/cuts/extra_cuts.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/cuts/proton200.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/cuts/protoncuts.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_gas.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_gas.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_gas.root\")",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0);",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/proton21_silicium.root\")",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0);",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0);",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0);",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0);",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0);",0);
   fComboBox250->AddEntry("gStyle->SetOptStat(0);",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry("gDirectory->ls()",0);
   fComboBox250->AddEntry("gDirectory->ls()",0);
   fComboBox250->AddEntry("gDirectory->ls(\"-d\")",0);
   fComboBox250->AddEntry("gDirectory->ls(\"-m\")",0);
   fComboBox250->AddEntry("SRIMLoader *l = new SRIMLoader();",0);
   fComboBox250->AddEntry("lst",0);
   fComboBox250->AddEntry("dir",0);
   fComboBox250->AddEntry("cd",0);
   fComboBox250->AddEntry("ls",0);
   fComboBox250->AddEntry(".L SRIMLoader.cpp",0);
   fComboBox250->AddEntry(".l SRIMLoader.cpp",0);
   fComboBox250->AddEntry(".l SRIMLoader.cpp",0);
   fComboBox250->AddEntry(".l SRIMLoader",0);
   fComboBox250->AddEntry(".l SRIMLoader.h",0);
   fComboBox250->AddEntry(".L SRIMLoader.h",0);
   fComboBox250->AddEntry(".L SRIMLoader",0);
   fComboBox250->AddEntry(".L SRIMLoader.cpp",0);
   fComboBox250->AddEntry("(3820*1.3e-3+4122*2.79+4266*1.19+4698*0.18+4792*0.31+6583*1.07+6750*0.86+6930*0.14+7010*0.14+7116*0.47+7230*0.62+7330*0.34+7715*2.43+8075*2.53+8627*10.5+8801*5.4+9551*0.45+11379*10.9+12763*41+13095*16)/100",0);
   fComboBox250->AddEntry("3547.6*0.9493+3196.9*0.0507+753.5*4.e-4",0);
   fComboBox250->AddEntry("3547.6*0.9493+3196.9*0.0507+753.5*4.0e10-4",0);
   fComboBox250->AddEntry("3547.6*0.9493+3196.9*0.0507+753.5*4.0*10^-4",0);
   fComboBox250->AddEntry("3547.6*0.9493+3196.9*0.0507",0);
   fComboBox250->AddEntry("findEnergy(1158, 1940)",0);
   fComboBox250->AddEntry(".l iteratePeakEnergy.cpp",0);
   fComboBox250->AddEntry(".l iteratePeakEnergy.ccpp",0);
   fComboBox250->AddEntry("iteratePeakEnergy(1158, 1900)",0);
   fComboBox250->AddEntry("ls",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/laseroff.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/proton21_silicium.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/cuts/proton200.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Results/kol_grid.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/timeSquare.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/laseroff.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/laseroff.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/laseroff.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/laseroff.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/proton21_silicium.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/beta.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/beta.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/proton21_silicium.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/proton21_silicium.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/proton21_silicium.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/proton21_silicium.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/proton21_silicium.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/cumulated_alpha_cuts.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/cumulated_alpha_cuts.root\")",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/cumulated_alpha_cuts.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/proton21_silicium.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/dssd.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/si1si2.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/beta.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/beta.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/cuts/extra_cuts.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/erik.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/si1si2.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/si1si2.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/si1si2.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/time.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/si1si2.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/si1si2.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/si1si2.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/si1si2.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/proton21_silicium.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/si1si2.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/si1si2.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/si1si2.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/si1si2.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/proton21_silicium.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/silicium21_large - No calibration.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/mg21_banana.root\")",0);
   fComboBox250->AddEntry(".x C:\\root\\macros\\fileopen.C",0);
   fComboBox250->AddEntry("TFile *_file0 = TFile::Open(\"C:/Users/Jesper/Dropbox/Universitetet/3 år/Bachelor/ROOT/VS/ROOT/ROOT/Histogrammer/New/timeSquare.root\")",0);
   fComboBox250->Resize(795,22);
   fComboBox250->Select(-1);
   fHorizontalFrame249->AddFrame(fComboBox250, new TGLayoutHints(kLHintsRight | kLHintsCenterY | kLHintsExpandX,5,5,1,1));

   TGFont *ufont;         // will reflect user font changes
   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   TGGC   *uGC;           // will reflect user GC changes
   // graphics context changes
   GCValues_t vall261;
   vall261.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",vall261.fForeground);
   gClient->GetColorByName("#e0e0e0",vall261.fBackground);
   vall261.fFillStyle = kFillSolid;
   vall261.fFont = ufont->GetFontHandle();
   vall261.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&vall261, kTRUE);
   TGLabel *fLabel261 = new TGLabel(fHorizontalFrame249,"Command (local):",uGC->GetGC());
   fLabel261->SetTextJustify(36);
   fLabel261->SetMargins(0,0,0,0);
   fLabel261->SetWrapLength(-1);
   fHorizontalFrame249->AddFrame(fLabel261, new TGLayoutHints(kLHintsRight | kLHintsCenterY,5,5,1,1));

   fCommandPlugin248->AddFrame(fHorizontalFrame249, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX,3,3,3,3));
   TGTextView *fTextView262 = new TGTextView(fCommandPlugin248,914,35);
   fTextView262->LoadFile("TxtView262");
   fCommandPlugin248->AddFrame(fTextView262, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY,3,3,3,3));

   fCompositeFrame247->AddFrame(fCommandPlugin248, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fCommandPlugin248->Connect("ProcessedConfigure(Event_t*)", 0, 0, "Layout()");


   fTab25->SetTab(0);

   fTab25->Resize(fTab25->GetDefaultSize());
   fHorizontalFrame18->AddFrame(fTab25, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY,2,2,2,2));

   fVerticalFrame16->AddFrame(fHorizontalFrame18, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX));
   fHSplitter24->SetFrame(fHorizontalFrame18,kFALSE);

   fHorizontalFrame14->AddFrame(fVerticalFrame16, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY));

   fVerticalFrame3->AddFrame(fHorizontalFrame14, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY));

   fRootBrowser2->AddFrame(fVerticalFrame3, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY));

   // status bar
   TGStatusBar *fStatusBar27 = new TGStatusBar(fRootBrowser2,1366,18);
   Int_t partsusBar27[] = {26,74};
   fStatusBar27->SetParts(partsusBar27,2);
   fRootBrowser2->AddFrame(fStatusBar27, new TGLayoutHints(kLHintsBottom | kLHintsExpandX));

   fRootBrowser2->SetWindowName("ROOT Object Browser");
   fRootBrowser2->SetIconName("ROOT Object Browser");
   fRootBrowser2->SetIconPixmap("rootdb_s.xpm");
   fRootBrowser2->SetClassHints("ROOT","Browser");
   fRootBrowser2->SetMWMHints(kMWMDecorAll,
                        kMWMFuncAll,
                        kMWMInputModeless);
   fRootBrowser2->SetWMSizeHints(600,350,10000,10000,2,2);
   fRootBrowser2->MapSubwindows();
   fMenuBar113->UnmapWindow();
   fHorizontalFrame13->UnmapWindow();
   fHorizontal3DLine121->UnmapWindow();
   fDockableFrame122->UnmapWindow();
   fHorizontal3DLine127->UnmapWindow();
   fCompositeFrame129->UnmapWindow();
   fStatusBar143->UnmapWindow();

   fRootBrowser2->Resize(fRootBrowser2->GetDefaultSize());
   fRootBrowser2->MapWindow();
   fRootBrowser2->Resize(1366,705);
}  

void ToggleSort()
{
   cout << "Slot ToggleSort()" << endl; 
}

void RequestFilter()
{
   cout << "Slot RequestFilter()" << endl; 
}

void Refresh()
{
   cout << "Slot Refresh()" << endl; 
}

void ApplyFilter(int par1)
{
   cout << "Slot ApplyFilter(int " << par1 << ")" << endl; 
}

void Layout()
{
   cout << "Slot Layout()" << endl; 
}

void DataDropped(char* par2)
{
   cout << "Slot DataDropped(char* " << par2 << ")" << endl; 
}

void CloseTab(int par3)
{
   cout << "Slot CloseTab(int " << par3 << ")" << endl; 
}
