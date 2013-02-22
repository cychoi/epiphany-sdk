/*
  File: e_coreid_address_from_coreid.c

  This file is part of the Epiphany Software Development Kit.

  Copyright (C) 2013 Adapteva, Inc.
  Contributed by Oleg Raikhman, Jim Thomas, Yaniv Sapir <support@adapteva.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License (LGPL)
  as published by the Free Software Foundation, either version 3 of the
  License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  and the GNU Lesser General Public License along with this program,
  see the files COPYING and COPYING.LESSER.  If not, see
  <http://www.gnu.org/licenses/>.
*/

#include <machine/epiphany_config.h>
#include "e_coreid.h"

void *e_address_from_coreid(e_coreid_t coreid, void *ptr)
{
	unsigned uptr;

	/* If not a local address or global on caller core, return ptr unchanged. */
	if (!e_is_oncore(ptr))
	{
		return ptr;
	}

	/* Get the 20 ls bits of the pointer and add coreid. */
	uptr = ((unsigned) ptr) & 0x000fffff;
	uptr = (coreid << 20) | uptr;

	return (void *) uptr;
}