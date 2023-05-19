" Minimal vimrc for competitive programming .

syntax on
set expandtab
set sw=2
set softtabstop=2
set tabstop=2
set number
set smarttab
filetype indent on
set smartindent

if $COLORTERM == 'gnome-terminal'
  set t_Co=256
endif

set hlsearch
set path+=**
set wildmenu

set incsearch

colorscheme torte
