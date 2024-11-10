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

" Compilar o arquivo C++ atual (.cpp), salvando o executável em .build com o sufixo '_exec'
command! Compile execute '!mkdir -p .build/%:h && g++ -std=c++11 % -o .build/%:t:r_exec'

" Compilar e executar arquivos de teste para uma classe específica, colocando o executável em .build
command! -nargs=1 RunTests execute '!mkdir -p .build && g++ -std=c++11 -I Mock $(find Mock -name "*.cpp") ' . substitute(toupper(<f-args>), '\(.\)\(.*\)', '\1\L\2', '') . '/test_' . tolower(<f-args>) . '*.cpp -o .build/' . tolower(<f-args>) . '_tests_exec && ./.build/' . tolower(<f-args>) . '_tests_exec'
