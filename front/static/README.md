# HTML

## Sites

- Emojipedia
- Unsplash
- Pexels
- IconArchive
- Favicon
- iana.org, mediatypes.


### Iframe

sandbox="sandbox" -> não permite 'cadastro'
referrerpolicy="no-referrer"

### Add icon

link:favicon

<link rel="shortcut icon" href="favicon.ico" type="image/x-icon">


### Add Emoji in your code

&#xEMOJICODE;


## Images

### Principais formatos
- jpg -> extremamente compactado.
- png -> Permite transparência.

### Sobre o tamanho das imagens

Resolução: 72 ta ok.
Qualidade 75%

- FUll -> 1500
- Medio -> 1200
- Baixo -> 650

## Tags

- b -> strong
- i -> em
- q -> quote, citação.
- blockquote -> citação em bloco.
    - atributo: cite="pagina"
- mark
- del -> riscado, texto deletado.
- ins -> sublinhado, texto inserido.
- code -> tag para código.
- pre -> pre-formatado.
- abbr -> abreviation
    - atributo: title="significado"
  
- header
  - nav
- main
  - section
  - article
- footer
- aside

### Listas

- ol, ul type disc, square.
    - type=
    - start="2" 

#### Lista de definição
- dl
  - dt termo
  - dd definição

### Links

- a
  - target="_blank", "_self".
  - rel="external", "next", "prev", "nofollow".

#### Download

<a href="#" download="lorem.pdf" type="application/pdf"> </a>

# CSS

## Symbs

- '>' filho direto
- ' ' descendente
- '+' seleciona o elemento que vem depois do primeiro:
```
div + p {
  color: gray;
}

<div>
</div>

<p> selecionado </p>

```

- '~' subsequent sibling combinator.

## Variáveis

```
* {
  margin: 0px;
  padding: 0px;
}
:root {
  --cor1: #id_cor1;
}


body {
  background-color: var(--cor1);
}
```

## Anatomia de caixas

- Margin
- Outline
- Border
- Padding

## Tipos de caixas

Box level
- div

Inline level
- span

display: block;
display: inline;
display: inline-block;

## Short hands

### background

```
color image position repeat [size] attachment

background: black url('image.png') no-repeat cover fixed;
```

### Border and Outline
```
border: width style color;

border: 10px solid darkslategray;

outline: width style color;

outline: 10px solid darkslategray;

```

### Padding
```
padding top right bottom left;

padding: 5px 5px 5px 5px;

padding for all sides.

padding 5px;
```
## Border

```
border-radius: 20px 0px;
border-radius: 50%;

border-image-source: url('imagem.png');
border-image-slice: 20;
border-image-repeate: repeate/stretch;
```

## Responsividade

```
main {
  min-width: 320px;
  max-width: 1200px;
  width: 800px;
}

main img {
  width: 100%;
}
```

## Background

```
body {
  height: 98vh;
  width: 98vw;

  background-image: url('image.jpg');

  background-size: 100px 100px;
  background-size: cover;
  background-attachment: fixed;

  background-repeat: no-repeat;

  background-position: left top;

}
```

## Centralização vertical

```
.conteudo {
  overflow: hidden; // :)
  cursor: pointer; // Muda o mouse quando ele passar em cima.

  position: absolute;
  top: 50%;
  left: 50%;
  transform: translate(-50%,-50%);
}
```

## Escondendo barra de rolagem

::-webkit-scrollbar {
  width: 0px;
  height: 0px;
}

## Forms

### Input

type = file
type = date
type = time
type = email
type = tel
type = color
type = range

type = reset value="limpar" -> Vai perto do submit.
#### REGEX

<input pattern="^[0-9]{4}-[0-9]{4}$">

</input>

### select

<select name=estado>
  <optgroup label="Valores">
    <option value=VA> Valor</option>
  </optgroup>
</select >

### FIELDSET
### LEGEND

### TAG OUTPUT

### FORM

<form autocomplete="off" action="cadastro.php">
<p>
<label for="idnome">Nome:</label> <input type="text" name="nome" id="idnome" required minlength="8" size="8">

<label for="idpeso">Peso:</label> <input type="number" name="peso" id="idpeso"  min="20" max="200" step="0.1" required>
</p>
</form>

### Datalist

<input type= text id="iprof" list="lstprof">

<datalist id="lstprof">
  <option value="PROF"> Professor</option>
</datalist>