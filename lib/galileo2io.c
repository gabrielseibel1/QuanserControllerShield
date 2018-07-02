/*
  pgets.c: Gets a string from a file, given its path.

  Copyright (c) 2016 Walter Fetter Lages <w.fetter@ieee.org>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    You can also obtain a copy of the GNU General Public License
    at <http://www.gnu.org/licenses>.

*/

/* USED BY ARTHUR ADOLFO E GABRIEL DE SOUZA SEIBEL */

#include <fcntl.h>
#include <unistd.h>

#include "../include/galileo2io.h"
#include <string.h>

char *pgets(char *s, int size, const char path[]) {
    int fd;

    if ((fd = open(path, O_RDONLY)) == -1) return NULL;
    read(fd, s, (size_t) size);
    close(fd);
    return s;
}

int pputs(const char path[], const char s[]) {
    int fd;
    int n;

    if ((fd = open(path, O_WRONLY)) == -1) return -1;
    n = (int) write(fd, s, strlen(s));
    close(fd);
    return n;
}