# [tutorial_vim](https://learnvim.irian.to)

## Global

:h ex-cmd-index

:g/pattern/command

```
const one = 1;
console.log("one: ", one);

const two = 2;
console.log("two: ", two);

const three = 3;
console.log("three: ", three);

:g/console/d
:g!/console/d -> negation.

:g/\v\w+/normal @a -> Executing a macro.
```

### Recursive global comand

```
const one = 1;
console.log("one: ", one);

const two = 2;
console.log("two: ", two);

const three = 3;
console.log("three: ", three);

:g/console/g/two/d

:g/console/d _ -> black hole
```

### Joining lines

```
const one = 1;
console.log("one: ", one);

const two = 2;
console.log("two: ", two);

const three = 3;
console.log("three: ", three);

:g/^$/ ,/ ./-1j
  pattern1/ ,/pattern2/command
```


```
const arrayB = [
  "i",
  "g",
  "h",
  "b",
  "f",
  "d",
  "e",
  "c",
  "a",
]

const arrayA = [
  "h",
  "b",
  "f",
  "d",
  "e",
  "a",
  "c",
]

:g/\[/+1,/\]/-1sort
```
