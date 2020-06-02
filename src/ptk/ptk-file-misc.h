/*
 *  C Interface: ptk-file-misc
 *
 * Description: Miscellaneous GUI-realated functions for files
 *
 *
 * Author: Hong Jen Yee (PCMan) <pcman.tw (AT) gmail.com>, (C) 2006
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 */

#ifndef _PTK_FILE_MISC_H_
#define _PTK_FILE_MISC_H_

#include <stdbool.h>

#include <gtk/gtk.h>
#include "ptk-file-browser.h"

#include "../vfs/vfs-file-info.h"

G_BEGIN_DECLS

typedef struct _AutoOpenCreate
{
    char* path;
    PtkFileBrowser* file_browser;
    GFunc callback;
    bool open_file;
} AutoOpenCreate;

typedef enum
{
    PTK_RENAME,
    PTK_RENAME_NEW_FILE,
    PTK_RENAME_NEW_DIR,
    PTK_RENAME_NEW_LINK
} PtkRenameMode;

void ptk_delete_files(GtkWindow* parent_win, const char* cwd, GList* sel_files,
                      GtkTreeView* task_view);

int ptk_rename_file(PtkFileBrowser* file_browser, const char* file_dir, VFSFileInfo* file,
                    const char* dest_dir, bool clip_copy, PtkRenameMode create_new,
                    AutoOpenCreate* auto_open);

void ptk_show_file_properties(GtkWindow* parent_win, const char* cwd, GList* sel_files, int page);

/* sel_files is a list of VFSFileInfo
 * app_desktop is the application used to open the files.
 * If app_desktop == NULL, each file will be opened with its
 * default application. */
void ptk_open_files_with_app(const char* cwd, GList* sel_files, const char* app_desktop,
                             PtkFileBrowser* file_browser, bool xforce, bool xnever);

void ptk_file_misc_paste_as(PtkFileBrowser* file_browser, const char* cwd, GFunc callback); // sfm

void ptk_file_misc_rootcmd(PtkFileBrowser* file_browser, GList* sel_files, char* cwd,
                           char* setname); // sfm

char* get_real_link_target(const char* link_path);

G_END_DECLS

#endif
