# Packages

## Intro

[Sbuild](https://wiki.debian.org/sbuild#What_is_sbuild)

[Tutorial Eriberto](http://eriberto.pro.br/debian/guia_empacotamento_debian_3.5.pdf)
[Tracker](https://tracker.debian.org/)

## Criando ambiente isolado

```bash
$ sudo sbuild-createchroot --include=eatmydata,ccache unstable /srv/chroot/unstable-amd64-sbuild http://deb.debian.org/debian

$ sudo sbuild-adduser <seu_usuario>
$ newgrp sbuild
```

## sbuild.rc

```
# don't remove this, Perl needs it
1;

# sbuild config for personal use
$build_arch_all = 1;
$distribution = 'unstable';

# lintian
$run_lintian = 1;
$lintian_opts = ['-i', '-I', '--pedantic'];

# piuparts
$run_piuparts = 0;
$piuparts_opts = ['--schroot', '%r-%a-sbuild', '--no-eatmydata'];

# autopkgtest
$run_autopkgtest = 0;
$autopkgtest_root_args = '';
$autopkgtest_opts = [ '--', 'schroot', '%r-%a-sbuild'];

# clean
$clean_source = 0;

# source changes
$source_only_changes = 1;
```

## uscan
```bash
$ uscan --download-current-version
```


## Watch

[Link example](https://salsa.debian.org/python-team/packages/typer/-/blob/master/debian/watch)

## Testando Pacote

```bash
alias -> autopkgtest -BU -s ../*deb -- schroot chroot:unstable-amd64-sbuild
```
