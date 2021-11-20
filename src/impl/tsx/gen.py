from __future__ import print_function

import sys


def _get_prologue(name):
    name = "_".join(name.upper().split())
    template = "#ifndef PATOMIC_IMPL_TSX_%s_H\n"
    template += "#define PATOMIC_IMPL_TSX_%s_H\n\n"
    return template % (name, name)


def _get_epilogue(name):
    name = "_".join(name.upper().split())
    template = "\n#endif  /* !PATOMIC_IMPL_TSX_%s_H */\n"
    return template % (name,)


def _get_warning():
    return "/* NOTE: this file is auto-generated by gen.py */\n\n"


def create_repeat(n):
    name = "repeat"

    content = _get_prologue(name)
    content += _get_warning()
    content += "#define PATOMIC_TSX_REPEAT_N %s\n" % n
    content += "#define PATOMIC_TSX_REPEAT_N_1 %s\n\n" % (n + 1,)
    content += "#define PATOMIC_TSX_REPEAT(def) \\\n"
    for i in range(n):
        content += "    def(%s) \\\n" % (i + 1,)
    content += "\n"
    content += _get_epilogue(name)

    with open(name + ".h", "w") as f:
        f.truncate()
        f.write(content)

    out = "Created %s.h with n=%s" % (name, n)
    print(out)


if __name__ == "__main__":
    """
    Call like: python gen.py n
    """
    error = "You must provide a single integer argument >= 2"

    if len(sys.argv) != 2:
        raise RuntimeError(error)

    repeats = None
    try:
        repeats = int(sys.argv[1])
    except ValueError:
        try:
            repeats = int(sys.argv[1], 16)
        except ValueError:
            pass
    if repeats is None:
        raise RuntimeError(error)

    if not repeats >= 2:
        raise RuntimeError(error)

    create_repeat(repeats)
