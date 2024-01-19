# [tutorial_vim](https://learnvim.irian.to)

[Resizing windows](https://vi.stackexchange.com/questions/514/how-do-i-change-the-current-splits-width-and-height)

# Vim Basics

## Starting vim

Open files in split:

```bash
vim -O2 file1.txt file2.txt
vim -o2 file1.txt file2.txt
```

Suspending editing: **ctrl+z or :stop then fg**.

Execute a comand on open **vim +:%s/first/second/g +:10,20s/second/third/g filename.txt**

Get command from terminal and flush vim **ls -l | vim -**

## Buffers, Windows, and Tabs

### Buffers

*Buffers*: A buffer is an in-memory space where you can write and edit some text.

**set hidden** -> If it is disabled vim force you to save each buffer before
you switch.

```
:edit filename.txt -> Open as a buffer

:ls -> list buffers
:bn -> next buffer
:bN -> previous buffer
:b {number} -> go to buffer numbered as {number}

:bd {number} -> delete buffer numbered as {number}
```

```
CTRL + i
CTRL + o
CTRL + ^ -> Last buffer edited
```

### Windows

*Windows*: A window is a viewport on a buffer.

```
sp filename.txt -> Open horizontal split
vsp filename2.txt -> Open vertial split

new filename -> Open in horizontal/vertical split
```

### Tabs

**Tabs**: A tab is a collection of windows.

```
:tabnew file.txt    Open file.txt in a new tab
:tabclose           Close the current tab
:tabnext            Go to next tab
:tabprevious        Go to previous tab
:tablast            Go to last tab
:tabfirst           Go to first tab
```

## Searching Files

Search in path variable.
```
:find file_name.py
```

Search pattern in specified file.
```
VIM GREP
:vim /breakfast/ app/controllers/**/*.rb

TERMINAL GREP
:grep -R "lunch" app/controllers/ 
```

Quick Fix comands.
```
:copen        Open the quickfix window
:cclose       Close the quickfix window
:cnext        Go to the next error
:cprevious    Go to the previous error
:colder       Go to the older error list
:cnewer       Go to the newer error list
```

### Netrw

```
set nocp
filetype plugin on
```

```
%    Create a new file
d    Create a new directory
R    Rename a file or directory
D    Delete a file or directory
s    Open in vertical split
o    Open in horizontal split
```

## Moving in file

```
ge    Move backward to end of the previous word
gE    Move backward to end of the previous WORD

g_    Go to the last non-blank char in the current line
n|    Go the column n in the current line

%    Navigate to another match, usually works for (), [], {}

Ctrl-D    Scroll down half screen
Ctrl-U    Scroll up half screen

Ctrl-F    Scroll down whole screen
Ctrl-B    Scroll up whole screen

(/ and ?)
n    Repeat last search in same direction of previous search
N    Repeat last search in opposite direction of previous search

:marks
ma mark position with mark a
'a
```

```

''    Jump back to the last line in current buffer before jump
``    Jump back to the last position in current buffer before jump
`[    Jump to beginning of previously changed / yanked text
`]    Jump to the ending of previously changed / yanked text
`<    Jump to the beginning of last visual selection
`>    Jump to the ending of last visual selection
`0    Jump back to the last edited file when exiting vim
```

