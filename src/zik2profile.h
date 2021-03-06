/* Zik2ctl
 * Copyright (C) 2015 Aurélien Zanelli <aurelien.zanelli@darkosphere.fr>
 *
 * Zik2ctl is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Zik2ctl is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Zik2ctl. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ZIK2_PROFILE_H
#define ZIK2_PROFILE_H

#include <glib.h>
#include <gio/gio.h>

G_BEGIN_DECLS

#define ZIK2_PROFILE_TYPE (zik2_profile_get_type ())
#define ZIK2_PROFILE(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), ZIK2_PROFILE_TYPE, Zik2Profile))
#define ZIK2_PROFILE_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), ZIK2_PROFILE_TYPE, Zik2ProfileClass))


typedef struct _Zik2ProfileClass Zik2ProfileClass;
typedef struct _Zik2Profile Zik2Profile;

struct _Zik2Profile
{
  GObject parent;

  GDBusObjectManager *manager;
  GDBusConnection *conn;
  guint id;

  /* connected devices */
  GHashTable *devices;
};

struct _Zik2ProfileClass
{
  GObjectClass parent_class;

  GDBusNodeInfo *introspection_data;
  GDBusInterfaceVTable interface_vtable;
};

GType zik2_profile_get_type (void);
Zik2Profile *zik2_profile_new (void);

gboolean zik2_profile_install (Zik2Profile * profile,
    GDBusObjectManager * manager);

void zik2_profile_uninstall (Zik2Profile * profile);

G_END_DECLS

#endif
