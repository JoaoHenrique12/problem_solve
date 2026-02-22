# Linux helper

## When you break your apt with libmlt
sudo apt list libmlt\*
sudo dpkg -r libmlt7-data
sudo apt --fix-broken install

## Alternatives over apt
apt-file
aptitude

## Hard link & Symbolic link

- Every time you create a folder, it creates two hard link '.' for itself, and '..' for it's parent
directory;
- Hard links points for inodes, sym links points to names of files;
- You can't create a hard link for a directory, and it is not possible to avoid:
  - problems with recursions (commands like find or backups would get insane with it)
  - the three direcotry would be broke


```bash
ln -s [who is the link] [place for link]
```

### Symbolic link

The easiest way to understand what a symbolic link is in Linux is to compare it to the
“direct link” or “shortcut” in Windows. The file or directory is located at a single 
point on the disk and the links are a pointer against it. Each symbolic link has its own
inode number which allows symbolic links to be made between different file systems.

To create links (both symbolic and hard links) we use the command ln. In this case, 
we will create a symbolic link (parameter -s) from the test file:

```bash
$ ln -s test link-to-test
$ ln -s files/soft.txt soft.txt
```

### Hard link

The hard links are to associate two or more files sharing the same inode. This makes each
hard link an exact copy of the rest of the associated files, both data and permissions, 
owner, etc. This also implies that when changes are made to one of the links or to the 
file, these changes will also be made to the rest of the links.

Hard links cannot be made against directories or outside the file system itself.


```bash
ln test link-hard-test
```

[Stack Overflow](https://stackoverflow.com/questions/185899/what-is-the-difference-between-a-symbolic-link-and-a-hard-link)

[Reference](https://blog.devgenius.io/hard-link-and-a-symbolic-link-any-difference-ef8b9bd61734#:~:text=Symbolic%20links%20can%20be%20made,number%2C%20symbolic%20links%20do%20not.)

## Screen

Split terminal without tmux.

[Reference](https://linuxize.com/post/how-to-use-linux-screen/)
