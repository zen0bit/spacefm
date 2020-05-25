/*
 *      vfs-utils.c
 *
 *      Copyright 2008 PCMan <pcman.tw@gmail.com>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 3 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#include <glib/gi18n.h>
#include <string.h>

#include "vfs-utils.h"
#include "settings.h"  //MOD

GdkPixbuf* vfs_load_icon( GtkIconTheme* theme, const char* icon_name, int size )
{
    GdkPixbuf* icon = NULL;
    const char* file;

    if ( !icon_name )
        return NULL;

    GtkIconInfo* inf = gtk_icon_theme_lookup_icon( theme, icon_name, size,
                                             GTK_ICON_LOOKUP_USE_BUILTIN |
                                             GTK_ICON_LOOKUP_FORCE_SIZE );

    if ( !inf && icon_name[0] == '/' )
        return gdk_pixbuf_new_from_file_at_size ( icon_name, size, size, NULL );
    
    if( G_UNLIKELY( ! inf ) )
        return NULL;

    file = gtk_icon_info_get_filename( inf );
    if( G_LIKELY( file ) )
        icon = gdk_pixbuf_new_from_file_at_size( file, size, size, NULL );
    else
    {
        icon = gtk_icon_info_get_builtin_pixbuf( inf );
        g_object_ref( icon );
    }
    gtk_icon_info_free( inf );

    return icon;
}

#ifdef HAVE_HAL
static char* find_su_program( GError** err )
{
    char* su = NULL;

#ifdef PREFERABLE_SUDO_PROG
    su = g_find_program_in_path( PREFERABLE_SUDO_PROG );
#endif
    // Use default search rules
    if ( ! su )
        su = get_valid_gsu();
    if ( ! su )
        su = g_find_program_in_path( "ktsuss" );
    if ( ! su )
        su = g_find_program_in_path( "gksudo" );
    if ( ! su )
        su = g_find_program_in_path( "gksu" );
    if ( ! su )
        su = g_find_program_in_path( "kdesu" );
        
    if ( ! su )
        g_set_error( err, G_SPAWN_ERROR, G_SPAWN_ERROR_FAILED, _( "su command not found" ) ); //MOD

    return su;
}

gboolean vfs_sudo_cmd_sync( const char* cwd, char* argv[],
                            int* exit_status,
                            char** pstdout, char** pstderr, GError** err )  //MOD
{
    char *su;  //MOD
    gboolean ret;

    if ( ! ( su = find_su_program( err ) ) )
        return FALSE;

    argv[0] = su;
    if ( ! strstr( su, "ktsuss" ) )  //MOD
    {
        // Combine arguments for gksu, kdesu, etc but not for ktsuss
        argv[1] = g_strdup_printf( "%s %s '%s'", argv[1], argv[2], argv[3] );
        argv[2] = NULL;
    }

    ret = g_spawn_sync( cwd, argv, NULL,
                   G_SPAWN_STDOUT_TO_DEV_NULL | G_SPAWN_STDERR_TO_DEV_NULL,
                   NULL, NULL,
                   pstdout, pstderr, exit_status, err );
    return ret;
}
#endif
