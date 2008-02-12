/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  nickname.h nickname related header file
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *  $Id: msg.h 957 2007-05-07 16:52:26Z stu $
 */

#ifndef INCLUDED_nickname_h
#define INCLUDED_nickname_h

struct AccessEntry
{
  unsigned int id;
  char *value;
};


struct Nick *nickname_find(const char *);
int nickname_register(struct Nick *);
int nickname_delete(struct Nick *);

int nickname_forbid(const char *);
int nickname_delete_forbid(const char *);
int nickname_is_forbid(const char *);


int nickname_link(struct Nick *, struct Nick *);
int nickname_unlink(struct Nick *);

char *nickname_nick_from_id(int, int);
int nickname_id_from_nick(const char *, int);
int nickname_set_master(struct Nick *, const char *);

int nickname_save(struct Nick *);

int nickname_accesslist_add(struct AccessEntry *);
int nickname_accesslist_list(struct Nick *, dlink_list *);
int nickname_accesslist_check(struct Nick *, const char *);
int nickname_accesslist_delete(struct Nick *, const char *, int);
void nickname_accesslist_free(dlink_list *);

int nickname_cert_add(struct AccessEntry *);
int nickname_cert_list(struct Nick *, dlink_list *);
int nickname_cert_check(struct Nick *, const char *);
int nickname_cert_delete(struct Nick *, const char *, int);
void nickname_certlist_free(dlink_list *);

#endif