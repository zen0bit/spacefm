/*-
 * Copyright (c) 2004 os-cillation e.K.
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

/* 2006.01.23 modified by Hong Jen Yee (PCMan) to used in PCMan File Manager */

#ifndef __EXO_STRING_H__
#define __EXO_STRING_H__

#include <stdbool.h>

#include <glib.h>

G_BEGIN_DECLS

/**
 * exo_str_is_empty:
 * @string : a string
 *
 * Macro to check if a string is %NULL or empty. You should prefer
 * this function over strlen (str) == 0.
 *
 * Returns: %TRUE if the string is not %NULL and its length > 1,
 *          %FALSE otherwise.
 *
 * Since : 0.5.0
 **/
#define exo_str_is_empty(string) ((string) == NULL || *(string) == '\0')

G_END_DECLS

#endif /* !__EXO_STRING_H__ */
