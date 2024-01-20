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

:bd {number} -> deconste buffer numbered as {number}
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
