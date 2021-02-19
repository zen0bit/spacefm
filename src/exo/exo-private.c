/*-
 * Copyright (c) 2004-2006 os-cillation e.K.
 *
 * Written by Benedikt Meurer <benny@xfce.org>.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <stdbool.h>

#include "exo-private.h"

void _exo_gtk_widget_send_focus_change(GtkWidget* widget, bool in)
{
    GdkEvent* fevent;

    g_object_ref(G_OBJECT(widget));

    fevent = gdk_event_new(GDK_FOCUS_CHANGE);
    fevent->focus_change.type = GDK_FOCUS_CHANGE;
    fevent->focus_change.window = g_object_ref(gtk_widget_get_window(widget));
    fevent->focus_change.in = in;

    gtk_widget_send_focus_change(widget, fevent);

    g_object_unref(G_OBJECT(widget));
    gdk_event_free(fevent);
}
