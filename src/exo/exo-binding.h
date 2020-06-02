/*-
 * Copyright (c) 2004 os-cillation e.K.
 * Copyright (c) 2004 Victor Porton (http://ex-code.com/~porton/)
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
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301 USA
 */

#ifndef __EXO_BINDING_H__
#define __EXO_BINDING_H__

#include <stdbool.h>

#include <glib-object.h>

G_BEGIN_DECLS

typedef struct _ExoBinding ExoBinding;
typedef struct _ExoMutualBinding ExoMutualBinding;

/**
 * ExoBindingTransform:
 * @src_value : Value to transform.
 * @dst_value : Value to store the result of the transformation into.
 * @user_data : User data supplied at binding creation.
 *
 * Function type used for binding transformation functions.
 *
 * Accomplished transformation from @src_value to @dst_value.
 * @src_value and @dst_value are already initialized before
 * this function gets called.
 *
 * Returns: %FALSE if transformation failed, else %TRUE.
 **/
typedef bool (*ExoBindingTransform)(const GValue* src_value, GValue* dst_value, void* user_data);

ExoBinding* exo_binding_new(GObject* src_object, const char* src_property, GObject* dst_object,
                            const char* dst_property);

ExoBinding* exo_binding_new_full(GObject* src_object, const char* src_property, GObject* dst_object,
                                 const char* dst_property, ExoBindingTransform transform,
                                 GDestroyNotify destroy_notify, void* user_data);

ExoMutualBinding* exo_mutual_binding_new_full(GObject* object1, const char* property1,
                                              GObject* object2, const char* property2,
                                              ExoBindingTransform transform,
                                              ExoBindingTransform reverse_transform,
                                              GDestroyNotify destroy_notify, void* user_data);

G_END_DECLS

#endif /* !__EXO_BINDING_H__ */
