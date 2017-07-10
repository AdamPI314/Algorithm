"""
update, generate a new problem entry
"""
import json
import os
import sys
import copy
import errno


def lowerOrUnderstore(c):
    if c is ' ':
        return '_'
    else:
        return c.lower()


def getDirectoryName(index, problem):
    name0 = str(index)
    name1 = ''.join([lowerOrUnderstore(c) for c in problem])
    return name0 + '_' + name1


def createDirectory(directory):
    try:
        os.makedirs(directory)
    except OSError as e:
        if e.errno != errno.EEXIST:
            raise


if __name__ == "__main__":
    fileDir = os.path.abspath(os.path.join(
        os.path.realpath(sys.argv[0]), os.pardir))
    fileName = os.path.join(fileDir, "demo.json")
    with open(fileName, 'r') as fhandler:
        data = json.load(fhandler)

    # update index, prev+1
    index = max([int(x) for x in data['problems'].keys()])
    newProblem = copy.deepcopy(data['problems'][str(index)])

    # # create Folder
    # dirName = getDirectoryName(index, newProblem['problem'])
    # createDirectory(os.path.join(fileDir, "src", dirName))
