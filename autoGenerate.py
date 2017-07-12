"""
update, generate a new problem entry
"""
import json
import os
import sys
import copy
import errno
import shutil
import stat
import re


def lowerOrUnderscore(c):
    if c is ' ':
        return '_'
    else:
        return c.lower()


def getDirectoryName(index, problem):
    name0 = str(index)
    name1 = ''.join([lowerOrUnderscore(c) for c in problem])
    return name0 + '_' + name1


def createDirectory(folderName):
    try:
        os.makedirs(folderName)
    except OSError as e:
        if e.errno != errno.EEXIST:
            raise


def deleteTemporaryFile(folderName):
    for f in os.listdir(folderName):
        # print(f)
        if re.search(r'[A-Z|a-z|0-9|_]+\.(obj|ilk|pdb|exe|in)+', f):
            # print(f)
            os.remove(os.path.join(folderName, f))


def copyTemplate(templateFolderName, destinationFolderName):
    try:
        shutil.copytree(templateFolderName, destinationFolderName)
    except OSError as exc:  # python >2.5
        if exc.errno == errno.ENOTDIR:
            shutil.copy(templateFolderName, destinationFolderName)
        else:
            raise


if __name__ == "__main__":
    fileDir = os.path.abspath(os.path.join(
        os.path.realpath(sys.argv[0]), os.pardir))
    fileName = os.path.join(fileDir, "demo.json")
    with open(fileName, 'r') as fhandler:
        data = json.load(fhandler)

    # clear previous project directory
    index = max([int(x) for x in data['problems'].keys()]) - 1
    newProblem = copy.deepcopy(data['problems'][str(index)])
    dirName = getDirectoryName(index, newProblem['problem'])
    deleteTemporaryFile(os.path.join(fileDir, "src", dirName))

    # update index
    index = max([int(x) for x in data['problems'].keys()])
    newProblem = copy.deepcopy(data['problems'][str(index)])
    dirName = getDirectoryName(index, newProblem['problem'])

    # clear directory in case
    if os.path.isdir(os.path.join(fileDir, "src", dirName)):
        # shutil.rmtree(os.path.join(fileDir, "src", dirName))
        print(str(os.path.join(fileDir, "src", dirName)) +
              " Directory exist alreay, please confirm and delete manually!")
    else:
        # copy template into new directory
        copyTemplate(os.path.join(fileDir, "src", "cppTemplate"),
                     os.path.join(fileDir, "src", dirName))

    print("Job Finished.")
