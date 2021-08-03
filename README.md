# @minishell:~$

>This project was done by:
> - [mde-rosa](https://github.com/mde-rosa)
> - [mpezzull](https://github.com/mpezzull)
 
 The objective is to create a simple shell, as beautiful as a shell
>With Minishell, you’ll be able to travel through time and come back to problems
people faced when Windows didn’t exist.
### How to use it

Using ``make`` will create the ``minishell`` executable.


Simply run it with :

```
./minishell
```

### Available options

Minishell runs executables from an absolute, relative or environment PATH (``/bin/ls`` or ``ls``), including arguments or options. ``'`` and ``"`` work the same as bash.

You can use redirections ``>`` ``>>`` ``<`` ``<<`` and pipes ``|``.

Environment variables are handled, including the return code ``$?``.

You can use ``Ctrl-C``,``Ctrl-\`` and ``Ctrl-D``, same as in bash.

A few of the functions are "built-in", meaning we don't call the executable, we re-coded them directly. It's the case for:
- ``echo with option -n``
- ``cd with only a relative or absolute path``
- ``pwd with no options``
- ``export with no options``
- ``unset with no options``
- ``env with no options or arguments``
- ``exit with no options``

### Some Instructions

- Your project must be written in accordance with the Norm.
- Your functions should not quit unexpectedly.
- No leaks.
- Your Makefile compile with the flags -Wall, -Wextra and -Werror, and not relink.
- ecc.

### Functions allowed:
readline, rl_on_new_line, rl_replace_line, rl_redisplay, add_history, printf, malloc,
free, write, open, read, close, fork, wait, waitpid, wait3, wait4, signal, kill,
exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir,
readdir, closedir, strerror, errno, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr,
tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs

for other information read en.subject.pdf

