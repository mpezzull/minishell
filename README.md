# ([mde-rosa](https://github.com/mde-rosa)&[mpezzull](https://github.com/mpezzull))@minishell:~$ _
 
 The objective is to create a simple shell: as beautiful as a shell.
>"...with Minishell, you’ll be able to travel through time and come back to problems
people faced when Windows didn’t exist..."
### How to use it

Using ``make`` will create the ``minishell`` executable.


Simply run it with :

```
./minishell
```

### Available options

Minishell runs executables from an absolute, relative or environment PATH (``/bin/ls`` or ``ls``), including arguments or options. ``'`` and ``"`` work the same as bash (but unclosed quotes are not allowed).

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

### Some other Instructions

- The project must be written in accordance with the Norm.
- The functions should not quit unexpectedly.
- No Memory-leaks.
- Makefile compile with the flags -Wall, -Wextra and -Werror, and not relink.
- Only a small group of functions are allowed.
- ecc.

## for other information please read en.subject.pdf

