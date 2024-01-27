# [tutorial_vim](https://learnvim.irian.to)

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
v    Open in vertical split
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
`[    Jump to beginning of previously changed / yanked text
`]    Jump to the ending of previously changed / yanked text
`0    Jump back to the last edited file when exiting vim
```

## Ways To Go To Insert Mode

```
gi   Insert text in same position where the last insert mode was stopped
```

### Exit insert mode

```
<Esc>     Exits insert mode and go to normal mode
Ctrl-[    Exits insert mode and go to normal mode
Ctrl-C    Like Ctrl-[ and <Esc>, but does not check for abbreviation
```

```
inoremap jj <Esc>
inoremap jk <Esc>
10i

Ctrl-H    Delete one character
Ctrl-W    Delete one word
Ctrl-U    Delete the entire line
```

### Insert From Register

```
"ayiw
  "a tells Vim that the target of your next action will go to register a.

Ctrl-R + register symbol. Insert register value.
```

### Scrolling

```
Ctrl-X Ctrl-Y    Scroll up
Ctrl-X Ctrl-E    Scroll down
```

### Autocompletion

```
Ctrl-X Ctrl-L      Insert a whole line
Ctrl-X Ctrl-I      Insert a text from included files
Ctrl-X Ctrl-N      Insert a text from current file
Ctrl-X Ctrl-F      Insert a file name

 Ctrl-N and Ctrl-P -> cycle throught options.
```

### Normal mode command

```
Ctrl-O zz       Center window
Ctrl-O H/M/L    Jump to top/middle/bottom window
Ctrl-O 'a       Jump to mark a

Ctrl-O !! curl https://google.com    Run curl
Ctrl-O !! pwd                        Run pwd

Ctrl-O dtz    Delete from current location till the letter "z"
Ctrl-O D      Delete from current location to the end of the line
```

## Dot Command

```
let one = "1";
let two = "2";
let three = "3";

After you searched /let, run cgnconst<Esc> then . .
```
