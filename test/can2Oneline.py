from sys import argv


if __name__ == '__main__':
    if len(argv) != 3:
        exit(0)

    mc = 0
    wf = ''
    mw = open(argv[2], "a")
    with open(argv[1], "r") as mf:
        for ml in mf:
            if ml[0] != '>':
                wf = wf+ml[:-1:]
                if (len(wf) > 10):
                    mw.write(wf)
                    wf = ''
    if(len(wf) > 0):
        mw.write(wf)

    mw.write("\n")


