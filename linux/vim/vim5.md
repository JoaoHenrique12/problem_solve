# [tutorial_vim](https://learnvim.irian.to)

## Search And Substitute

```
:set ignorecase
:set noignorecase

:set ignorecase smartcase

/\Chello -> Search only lower case.

:history /
```

```
hello vim
hola vim
salve vim
bonjour vim

/hello\|holla
/\vhello|holla
```

### REGEX

\zsPATTERN\ze
/11\zsvim\ze22


/[^0-9] -> match not a digit.
:h /character-classes

```
"Vim is awesome!"
/"[^"]\+"
```

```
:s/pancake/donut/g
:h s_flags

&    Reuse the flags from the previous substitute command.
g    Replace all matches in the line.
c    Ask for substitution confirmation.
e    Prevent error message from displaying when substitution fails.
i    Perform case insensitive substitution.
I    Perform case sensitive substitution.
```

```
:h sub-replace-special

Vim Is The Greatest Text Editor In The Whole Galaxy
:s/\<./\U&/g
```

```
chocolate pancake
strawberry sweetcake
blueberry hotcake

:%s/hot\zscake/dog/g
```
#### Greedy and Non-Greedy

:h non-greedy
```
One Mississippi, two Mississippi, three Mississippi, four Mississippi, five Mississippi.

:s/\v(.{-}\zsMississippi){3}/Arkansas/g
```

#### Multiple files

```
:args *.txt
:argdo %s/dog/chicken/
:argdo update
```
