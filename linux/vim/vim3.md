# [tutorial_vim](https://learnvim.irian.to)

## Resize

Ctrl+W +/-: increase/decrease height (ex. 20<C-w>+)
Ctrl+W >/<: increase/decrease width (ex. 30<C-w><)
Ctrl+W _: set height (ex. 50<C-w>_)
Ctrl+W |: set width (ex. 50<C-w>|)
Ctrl+W =: equalize width and height of all windows

## Registers

### The Ten Register Types


```
1- The unnamed register (""). [ Last yank/delete ]
2- The numbered registers ("0-9). [ Lines deleted ]
3- The small delete register ("-). [ dw, cw ]
3- The named registers ("a-z).

4- The read-only registers (":, ".,and "%). 
  [ . -> last inserted text,
    : -> last executed comand line,
    % -> current file name
  ]

5- The alternate file register ("#).
6- The expression register ("=).
7- The selection registers ("* and "+).
8- The black hole register ("_).
9- The last search pattern register ("/).
```

```
:reg a 1 -
```

### Show off
```
10"ap


"kciw

"_dd -> Throw to /dev/null

insert mode: Ctrl-R a
insert mode: Ctrl-r =@a
```

Add to your existing named register. To do that, you can use the uppercase version of 
that register.

```
"ayiw + "Ayiw
```
