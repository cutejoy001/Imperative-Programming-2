# pylint: disable=all


import os,sys
WARNING = "-Wall -Wextra"
COMMAND =""

def compileTask1():
    COMMAND = "gcc "+ WARNING + " LAB02-TASK01.c -o LAB02-TASK01.exe && LAB02-TASK01.exe"
    os.system(COMMAND)
    if os.path.exists("LAB02-TASK01.exe"):
        os.remove("LAB02-TASK01.exe")

def compileTask2():
    COMMAND = "gcc "+ WARNING + " LAB02-TASK02.c -o LAB02-TASK02.exe && LAB02-TASK02.exe"
    os.system(COMMAND)
    if os.path.exists("LAB02-TASK02.exe"):
        os.remove("LAB02-TASK02.exe")


## https://github.com/khushaalan/Imperative-Programming-2.git
def gitUpdate():
    os.system("git status")
    os.system("git add -A")
    os.system("git commit -m 'update'")
    os.system("git push origin main")
    os.system("git status")


def main(args=None):
    args = args or sys.argv[1:]
    if args:
        if args[0] == '--1':
            compileTask1()
        elif args[0] == '--2':
            compileTask2()
        elif args[0] == '--git':
            gitUpdate()
        else:
            print("Usage: python MAKEFILE.py [ --1 | --2 | --git ]")
            print("Example: python MAKEFILE.py --1")
            return
    else:
        print("Usage: python MAKEFILE.py [ --1 | --2 | --git ]")
        print("Example: python MAKEFILE.py --1")
        return


main()