/////////////////////////////////////////////////////////////////////////////////
// Author:      Steven Lamerton
// Copyright:   Copyright (C) 2009 - 2011 Steven Lamerton
// License:     GNU GPL 2 http://www.gnu.org/licenses/gpl-2.0.html
/////////////////////////////////////////////////////////////////////////////////

#include "log.h"
#include <wx/app.h> 
#include <wx/msgdlg.h>
#include <wx/textfile.h>
#include <boost/interprocess/ipc/message_queue.hpp>

using namespace boost::interprocess;

void LogMessageQueue::DoLogRecord(wxLogLevel level, const wxString& msg, const wxLogRecordInfo& info){
    //Discard verbose output, they should only be output to a file
    if(level >= wxLOG_Info)
        return;

    std::string out =  msg.ToStdString();
    try{
        message_queue eq(open_only, "error");
        eq.send(out.data(), out.size(), 5);
    }
    catch(std::exception &ex){
        wxLogError("%s", ex.what());
    }
}

LogFile::LogFile(wxTextFile* file) : file(file)
{
    count = 0;
}

void LogFile::DoLogRecord(wxLogLevel level, const wxString& msg, const wxLogRecordInfo& info){
    file->AddLine(msg);
    count++;
    //Don't write output every line but do it fairly frequently
    if(count % 10 == 0)
        file->Write();
}
