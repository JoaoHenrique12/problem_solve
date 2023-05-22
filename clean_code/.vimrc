set nocompatible
call plug#begin('~/.vim/autoload/')

Plug'dracula/vim',{'as':'dracula'}
Plug 'jnurmine/Zenburn'
Plug 'altercation/vim-colors-solarized'
Plug 'preservim/nerdtree'
Plug 'joshdick/onedark.vim'
Plug 'liuchengxu/space-vim-dark'
Plug 'itchyny/lightline.vim'
Plug 'mhartington/oceanic-next'
Plug 'henrynewcomer/vim-theme-papaya'
Plug 'morhetz/gruvbox'

call plug#end()

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

"onedark
" Tutorial do cara la
" Higlight
set hlsearch
set path+=**
set wildmenu

"colorscheme space-vim-dark
colorscheme onedark
let g:onedark_termcolors=256
set termguicolors
"autocmd vimenter * NERDTree
map <C-n> :NERDTreeToggle<CR>
" --- linha bonitinha
set noshowmode
set noshowmode
set laststatus=2

" Ligando regex highlights
set incsearch

" Mudando reconhecimento do .pl de perl para prolog.

let g:filetype_pl="prolog"
let g:filetype_pro="prolog"
