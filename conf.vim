set number
set cursorline

syntax on

set nobackup
set nowritebackup
set noswapfile

set tabstop=4          " Define 4 espaços para cada tab
set shiftwidth=4       " Usado para indentação automática
set expandtab          " Converte tabs em espaços
set autoindent         " Mantém a indentação da linha anterior

set updatetime=300

set incsearch          " Pesquisa incremental enquanto você digita
set ignorecase         " Ignora maiúsculas e minúsculas
set smartcase          " Usa diferenciação de maiúsculas/minúsculas se houver letras maiúsculas

set laststatus=2
set showmode

" Variaveis de conf
let NERDTreeShowHidden=1

" Plugins
call plug#begin('~/.local/share/nvim/plugged')

Plug 'tpope/vim-sensible'       
Plug 'preservim/nerdtree'                               " Arvore de arquivos
Plug 'Xuyuanp/nerdtree-git-plugin'                      " Status git na arvore de arquivos
Plug 'tpope/vim-fugitive'                               " Habilita comandos git
Plug 'junegunn/fzf', { 'do': ':fzf#install()' }         " Pesquisa rápida
Plug 'junegunn/fzf.vim'
Plug 'neoclide/coc.nvim', {'branch': 'release'}         " Autocompletar inteligente


call plug#end()

" Abrir ou fechar a árvore de arquivos
command! Open :NERDTreeToggle

" Compilar atual cpp
command! Compile w | !g++ -std=c++11 % -o %:r

" Compilar e executar atual cpp
command! Run w | !g++ -std=c++11 % -o %:r && ./%:r
