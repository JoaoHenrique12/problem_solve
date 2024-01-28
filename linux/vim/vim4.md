# [tutorial_vim](https://learnvim.irian.to)

## Macros

```
qa<comands>q

@a
@@
```
Safety Guard: Macros stops when find an error.

###Command Line Macro

```
:normal @a
:2,3 normal@a
```
### Series VS Parallel macros

```
qa0f{gui{jq

99@a
:1,$ normal @a
```

```
import { FUNC1 } from "library1";
import { FUNC2 } from "library2";
import { FUNC3 } from "library3";
import foo from "bar";
import { FUNC4 } from "library4";
import { FUNC5 } from "library5";
```

## Undo

```
u, U (fortissimo), ctrl + r
:undo
:redo

:echo &undolevels
: set undolevels=1000

Ctrl-G u creates an undo breakpoint
ione <Ctrl-G u>two <Ctrl-G u>three<Esc>

// Commands accept time as argument.
:earlier
:later
```

one two three

## Visual Mode

Letra: o O

Letra: r

Letra: A I

Letra: g + Ctrl + x/a

```
one
two
three

Chapter One
===========

<div id="app-1"></div>
<div id="app-2"></div>
<div id="app-3"></div>
<div id="app-4"></div>
<div id="app-5"></div>

set nrformats+=alpha // Increment letters.

<div id="app-a"></div>
<div id="app-b"></div>
<div id="app-c"></div>
<div id="app-d"></div>
<div id="app-e"></div>
```
