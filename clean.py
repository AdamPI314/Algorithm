"""
update, generate a new problem entry
"""
import json
import os
import sys
import copy
from autoGenerate import getDirectoryName, deleteTemporaryFile


if __name__ == "__main__":
    fileDir = os.path.abspath(os.path.join(
        os.path.realpath(sys.argv[0]), os.pardir))
    fileName = os.path.join(fileDir, "demo.json")
    with open(fileName, 'r') as fhandler:
        data = json.load(fhandler)

    # clear current project directory
    index = max([int(x) for x in data['problems'].keys()])
    newProblem = copy.deepcopy(data['problems'][str(index)])
    dirName = getDirectoryName(index, newProblem['problem'])
    deleteTemporaryFile(os.path.join(fileDir, "src", dirName))

    print("Job Finished.")
