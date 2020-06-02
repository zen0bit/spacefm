/*
 * SpaceFM settings.h
 *
 * Copyright (C) 2015 IgnorantGuru <ignorantguru@gmx.com>
 * Copyright (C) 2006 Hong Jen Yee (PCMan) <pcman.tw (AT) gmail.com>
 *
 * License: See COPYING file
 *
 */

#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include <stdbool.h>
#include <stdint.h>

#include <glib.h>
#include <gdk/gdk.h>
#include <gtk/gtk.h>

#include "ptk/ptk-file-browser.h"

// this determines time before item is selected by hover in single-click mode
#define SINGLE_CLICK_TIMEOUT 150

// This limits the small icon size for side panes and task list
#define PANE_MAX_ICON_SIZE 48

typedef struct AppSettings
{
    /* General Settings */
    bool show_thumbnail;
    int max_thumb_size;

    int big_icon_size;
    int small_icon_size;
    int tool_icon_size;

    bool single_click;
    bool no_single_hover;

    bool no_execute;      // MOD
    bool no_confirm;      // MOD
    bool sdebug;          // sfm
    bool load_saved_tabs; // sfm
    char* date_format;    // MOD for speed dupe of xset

    int sort_order; /* Sort by name, size, time */
    int sort_type;  /* ascending, descending */

    /* Window State */
    int width;
    int height;
    bool maximized;

    /* Interface */
    bool always_show_tabs;
    bool hide_close_tab_buttons;

    /* Units */
    bool use_si_prefix;
} AppSettings;

extern AppSettings app_settings;

void load_conf();
void load_settings(char* config_dir);
void save_settings(void* main_window_ptr);
void free_settings();
const char* xset_get_config_dir();
const char* xset_get_user_tmp_dir();

///////////////////////////////////////////////////////////////////////////////
// MOD extra settings below

extern GList* xsets;

enum
{
    XSET_B_UNSET,
    XSET_B_TRUE,
    XSET_B_FALSE
};

enum
{
    XSET_CMD_LINE,
    XSET_CMD_SCRIPT,
    XSET_CMD_APP,
    XSET_CMD_BOOKMARK
};

enum
{ // do not renumber - these values are saved in session files
    XSET_MENU_NORMAL,
    XSET_MENU_CHECK,
    XSET_MENU_STRING,
    XSET_MENU_RADIO,
    XSET_MENU_FILEDLG,
    XSET_MENU_FONTDLG,
    XSET_MENU_ICON,
    XSET_MENU_COLORDLG,
    XSET_MENU_CONFIRM,
    XSET_MENU_DUMMY3,
    XSET_MENU_DUMMY4,
    XSET_MENU_DUMMY5,
    XSET_MENU_DUMMY6,
    XSET_MENU_DUMMY7,
    XSET_MENU_DUMMY8,
    XSET_MENU_DUMMY9,
    XSET_MENU_DUMMY10,
    XSET_MENU_SUBMENU, // add new before submenu
    XSET_MENU_SEP
};

enum
{ // do not reorder - these values are saved in session files
  // also update builtin_tool_name builtin_tool_icon in settings.c
    XSET_TOOL_NOT,
    XSET_TOOL_CUSTOM,
    XSET_TOOL_DEVICES,
    XSET_TOOL_BOOKMARKS,
    XSET_TOOL_TREE,
    XSET_TOOL_HOME,
    XSET_TOOL_DEFAULT,
    XSET_TOOL_UP,
    XSET_TOOL_BACK,
    XSET_TOOL_BACK_MENU,
    XSET_TOOL_FWD,
    XSET_TOOL_FWD_MENU,
    XSET_TOOL_REFRESH,
    XSET_TOOL_NEW_TAB,
    XSET_TOOL_NEW_TAB_HERE,
    XSET_TOOL_SHOW_HIDDEN,
    XSET_TOOL_SHOW_THUMB,
    XSET_TOOL_LARGE_ICONS,
    XSET_TOOL_INVALID // keep this always last
};

enum
{
    XSET_JOB_KEY,
    XSET_JOB_ICON,
    XSET_JOB_LABEL,
    XSET_JOB_EDIT,
    XSET_JOB_EDIT_ROOT,
    XSET_JOB_LINE,
    XSET_JOB_SCRIPT,
    XSET_JOB_CUSTOM,
    XSET_JOB_TERM,
    XSET_JOB_KEEP,
    XSET_JOB_USER,
    XSET_JOB_TASK,
    XSET_JOB_POP,
    XSET_JOB_ERR,
    XSET_JOB_OUT,
    XSET_JOB_BOOKMARK,
    XSET_JOB_APP,
    XSET_JOB_COMMAND,
    XSET_JOB_SUBMENU,
    XSET_JOB_SUBMENU_BOOK,
    XSET_JOB_SEP,
    XSET_JOB_ADD_TOOL,
    XSET_JOB_IMPORT_FILE,
    XSET_JOB_IMPORT_URL,
    XSET_JOB_IMPORT_GTK,
    XSET_JOB_CUT,
    XSET_JOB_COPY,
    XSET_JOB_PASTE,
    XSET_JOB_REMOVE,
    XSET_JOB_REMOVE_BOOK,
    XSET_JOB_NORMAL,
    XSET_JOB_CHECK,
    XSET_JOB_CONFIRM,
    XSET_JOB_DIALOG,
    XSET_JOB_MESSAGE,
    XSET_JOB_COPYNAME,
    XSET_JOB_PROP,
    XSET_JOB_PROP_CMD,
    XSET_JOB_IGNORE_CONTEXT,
    XSET_JOB_SCROLL,
    XSET_JOB_EXPORT,
    XSET_JOB_BROWSE_FILES,
    XSET_JOB_BROWSE_DATA,
    XSET_JOB_BROWSE_PLUGIN,
    XSET_JOB_HELP,
    XSET_JOB_HELP_NEW,
    XSET_JOB_HELP_ADD,
    XSET_JOB_HELP_BROWSE,
    XSET_JOB_HELP_STYLE,
    XSET_JOB_HELP_BOOK,
    XSET_JOB_TOOLTIPS
};

enum
{
    PLUGIN_JOB_INSTALL,
    PLUGIN_JOB_COPY,
    PLUGIN_JOB_REMOVE
};

enum
{
    PLUGIN_USE_HAND_ARC,
    PLUGIN_USE_HAND_FS,
    PLUGIN_USE_HAND_NET,
    PLUGIN_USE_HAND_FILE,
    PLUGIN_USE_BOOKMARKS,
    PLUGIN_USE_NORMAL
};

typedef struct
{
    char* name;
    char b; // tri-state 0=unset(false) 1=true 2=false
    char* s;
    char* x;
    char* y;
    char* z;      // for menu_string locked, stores default
    bool disable; // not saved, default false
    char* menu_label;
    int menu_style; // not saved or read if locked
    char* icon;
    void (*cb_func)();       // not saved
    void* cb_data;           // not saved
    char* ob1;               // not saved
    void* ob1_data;          // not saved
    char* ob2;               // not saved
    void* ob2_data;          // not saved
    PtkFileBrowser* browser; // not saved - set automatically
    int key;
    int keymod;
    char* shared_key; // not saved
    char* desc;       // not saved or read if locked
    char* title;      // not saved or read if locked
    char* next;
    char* context;
    unsigned char tool; // 0=not 1=true 2=false
    bool lock;          // not saved, default true

    // Custom Command ( !lock )
    char* prev;
    char* parent;
    char* child;
    char* line; // or help if lock
    // x = XSET_CMD_LINE..XSET_CMD_BOOKMARK
    // y = user
    // z = custom executable
    char task;
    char task_pop;
    char task_err;
    char task_out;
    char in_terminal;   // or save menu_label if lock
    char keep_terminal; // or save icon if lock
    char scroll_lock;
    char opener;

    // Plugin (not saved at all)
    bool plugin;
    bool plugin_top;
    char* plug_name;
    char* plug_dir;

} XSet;

// cache these for speed in event handlers
extern XSet* evt_win_focus;
extern XSet* evt_win_move;
extern XSet* evt_win_click;
extern XSet* evt_win_key;
extern XSet* evt_win_close;
extern XSet* evt_pnl_show;
extern XSet* evt_pnl_focus;
extern XSet* evt_pnl_sel;
extern XSet* evt_tab_new;
extern XSet* evt_tab_chdir;
extern XSet* evt_tab_focus;
extern XSet* evt_tab_close;
extern XSet* evt_device;

// instance-wide command history
extern GList* xset_cmd_history;

// These will contain the su settings from /etc/spacefm/spacefm.conf
extern char* settings_terminal_su;

typedef struct
{
    bool valid;
    char* var[40];
} XSetContext;

void xset_autosave(bool force, bool delay);
void xset_autosave_cancel();

void xset_set_window_icon(GtkWindow* win);
XSet* xset_get(const char* name);
char* xset_get_s(const char* name);
bool xset_get_b(const char* name);
XSet* xset_get_panel(int panel, const char* name);
char* xset_get_s_panel(int panel, const char* name);
bool xset_get_b_panel(int panel, const char* name);
XSet* xset_set_b(const char* name, bool bval);
XSet* xset_set_b_panel(int panel, const char* name, bool bval);
int xset_get_int(const char* name, const char* var);
int xset_get_int_panel(int panel, const char* name, const char* var);
XSet* xset_set_panel(int panel, const char* name, const char* var, const char* value);
XSet* xset_set_cb_panel(int panel, const char* name, void (*cb_func)(), void* cb_data);
bool xset_get_b_set(XSet* set);
XSet* xset_get_panel_mode(int panel, const char* name, char mode);
bool xset_get_b_panel_mode(int panel, const char* name, char mode);
XSet* xset_set_b_panel_mode(int panel, const char* name, char mode, bool bval);

XSetContext* xset_context_new();
XSet* xset_get_plugin_mirror(XSet* set);
char* xset_custom_get_script(XSet* set, bool create);
char* xset_get_keyname(XSet* set, int key_val, int key_mod);
void xset_set_key(GtkWidget* parent, XSet* set);

XSet* xset_set(const char* name, const char* var, const char* value);
XSet* xset_set_set(XSet* set, const char* var, const char* value);
void xset_custom_delete(XSet* set, bool delete_next);
void xset_custom_activate(GtkWidget* item, XSet* set);
XSet* xset_custom_remove(XSet* set);
char* xset_custom_get_app_name_icon(XSet* set, GdkPixbuf** icon, int icon_size);
GdkPixbuf* xset_custom_get_bookmark_icon(XSet* set, int icon_size);
void xset_custom_export(GtkWidget* parent, PtkFileBrowser* file_browser, XSet* set);
GtkWidget* xset_design_show_menu(GtkWidget* menu, XSet* set, XSet* book_insert, unsigned int button,
                                 uint32_t time);
void xset_add_menu(PtkFileBrowser* file_browser, GtkWidget* menu, GtkAccelGroup* accel_group,
                   char* elements);
GtkWidget* xset_add_menuitem(PtkFileBrowser* file_browser, GtkWidget* menu,
                             GtkAccelGroup* accel_group, XSet* set);
GtkWidget* xset_get_image(const char* icon, int icon_size);
XSet* xset_set_cb(const char* name, void (*cb_func)(), void* cb_data);
XSet* xset_set_ob1_int(XSet* set, const char* ob1, int ob1_int);
XSet* xset_set_ob1(XSet* set, const char* ob1, void* ob1_data);
XSet* xset_set_ob2(XSet* set, const char* ob2, void* ob2_data);
XSet* xset_is(const char* name);
XSet* xset_find_custom(const char* search);

void xset_menu_cb(GtkWidget* item, XSet* set);
bool xset_menu_keypress(GtkWidget* widget, GdkEventKey* event, void* user_data);
bool xset_text_dialog(GtkWidget* parent, const char* title, GtkWidget* image, bool large,
                      const char* msg1, const char* msg2, const char* defstring, char** answer,
                      const char* defreset, bool edit_care, const char* help);
char* xset_file_dialog(GtkWidget* parent, GtkFileChooserAction action, const char* title,
                       const char* deffolder, const char* deffile);
char* xset_font_dialog(GtkWidget* parent, const char* title, const char* preview,
                       const char* deffont);
void xset_edit(GtkWidget* parent, const char* path, bool force_root, bool no_root);
void xset_open_url(GtkWidget* parent, const char* url);
void xset_fill_toolbar(GtkWidget* parent, PtkFileBrowser* file_browser, GtkWidget* toolbar,
                       XSet* set_parent, bool show_tooltips);
int xset_msg_dialog(GtkWidget* parent, int action, const char* title, GtkWidget* image, int buttons,
                    const char* msg1, const char* msg2, const char* help);
GtkTextView* multi_input_new(GtkScrolledWindow* scrolled, const char* text, bool def_font);
void multi_input_select_region(GtkWidget* input, int start, int end);
char* multi_input_get_text(GtkWidget* input);
XSet* xset_custom_new();
bool write_root_settings(GString* buf, const char* path);
GList* xset_get_plugins(bool included);
void install_plugin_file(void* main_win, GtkWidget* handler_dlg, const char* path,
                         const char* plug_dir, int type, int job, XSet* insert_set);
XSet* xset_import_plugin(const char* plug_dir, int* use);
void clean_plugin_mirrors();
void xset_show_help(GtkWidget* parent, XSet* set, const char* anchor);
bool xset_opener(PtkFileBrowser* file_browser, char job);
const char* xset_get_builtin_toolitem_label(unsigned char tool_type);
char* xset_icon_chooser_dialog(GtkWindow* parent, const char* def_icon);

#endif
