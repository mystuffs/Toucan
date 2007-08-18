/////////////////////////////////////////////////////////////////////////////////
// Author:      Steven Lamerton
// Copyright:   Copyright (C) 2006-2007 Steven Lamerton
// Licence:     GNU GPL 2 (See readme for more info
/////////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "frmopen.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "frmopen.h"
#include "toucan.h"

#include <wx/stdpaths.h>
#include <wx/fileconf.h>

////@begin XPM images
////@end XPM images

/*!
 * frmOpen type definition
 */

IMPLEMENT_DYNAMIC_CLASS( frmOpen, wxDialog )

/*!
 * frmOpen event table definition
 */

BEGIN_EVENT_TABLE( frmOpen, wxDialog )

////@begin frmOpen event table entries
    EVT_BUTTON( wxID_OPEN, frmOpen::OnOPENClick )

    EVT_BUTTON( wxID_CANCEL, frmOpen::OnCANCELClick )

////@end frmOpen event table entries

END_EVENT_TABLE()

/*!
 * frmOpen constructors
 */

frmOpen::frmOpen()
{
    Init();
}

frmOpen::frmOpen( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}

/*!
 * frmOpen creator
 */

bool frmOpen::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin frmOpen creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end frmOpen creation
SetIcon(GetIconResource(wxT("Toucan.ico")));
    return true;
}

/*!
 * frmOpen destructor
 */

frmOpen::~frmOpen()
{
////@begin frmOpen destruction
////@end frmOpen destruction
}

/*!
 * Member initialisation 
 */

void frmOpen::Init()
{
////@begin frmOpen member initialisation
    m_List = NULL;
////@end frmOpen member initialisation
}

/*!
 * Control creation for frmOpen
 */

void frmOpen::CreateControls()
{    
	//Load language if one exists from toucan.h
	wxGetApp().SelectLanguage();
	////@begin frmOpen content construction
    	// Generated by DialogBlocks, 18/07/2007 10:10:22 (Personal Edition)

    frmOpen* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxStaticText* itemStaticText3 = new wxStaticText( itemDialog1, wxID_STATIC, _("Please Select One"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemStaticText3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxADJUST_MINSIZE, 5);

    wxArrayString m_ListStrings;
    m_List = new wxListBox( itemDialog1, ID_LISTBOX, wxDefaultPosition, wxSize(250, 200), m_ListStrings, wxLB_SINGLE|wxLB_ALWAYS_SB );
    itemBoxSizer2->Add(m_List, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton6 = new wxButton( itemDialog1, wxID_OPEN, _("&Open"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(itemButton6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton7 = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(itemButton7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end frmOpen content construction
    
    wxFileConfig *config = new wxFileConfig( wxT(""), wxT(""), wxPathOnly(wxStandardPaths::Get().GetExecutablePath()) + wxT("\\Data\\Jobs.ini") );
    wxFileConfig::Set( config );
    
    wxString str;
    long dummy;
    bool bCont = config->GetFirstGroup(str, dummy);
    
    while ( bCont ) 
    {
        //wxMessageBox(config->Read(str +wxT("/Type"), wxEmptyString));
        //wxMessageBox(wxGetApp().GetStrTemp());
        if(config->Read(str +wxT("/Type"), wxEmptyString) == wxGetApp().GetStrTemp())
        {
            m_List->Append(str);
        }
    bCont = config->GetNextGroup(str, dummy);
    }
}

/*!
 * Should we show tooltips?
 */

bool frmOpen::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap frmOpen::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin frmOpen bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end frmOpen bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon frmOpen::GetIconResource( const wxString& name )
{
    wxUnusedVar(name);
	if (name == _T("Toucan.ico"))
	{
		wxIcon icon(_T("App\\toucan\\bitmaps\\Toucan.ico"), wxBITMAP_TYPE_ICO);
		return icon;
	}
	return wxNullIcon;
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OPEN
 */

void frmOpen::OnOPENClick( wxCommandEvent& event )
{
    if(m_List->GetStringSelection() != wxEmptyString)
    {
        wxGetApp().SetStrTemp(m_List->GetStringSelection());
        EndModal(wxID_OK);
    }
    else
    {
        wxLogError(_("Please select one."));
    }
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void frmOpen::OnCANCELClick( wxCommandEvent& event )
{
    EndModal(wxID_CANCEL);
}

