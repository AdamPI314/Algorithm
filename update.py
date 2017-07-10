"""
update, generate a new entry
"""
import json
import os
import sys
import copy

import geolocation

if __name__ == "__main__":
    fileDir = os.path.abspath(os.path.join(
        os.path.realpath(sys.argv[0]), os.pardir))
    fileName = os.path.join(fileDir, "demo.json")
    with open(fileName, 'r') as fhandler:
        data = json.load(fhandler)

    # update index, prev+1
    index = max([int(x) for x in data['problems'].keys()]) + 1
    newProblem = copy.deepcopy(data['problems']['1'])

    newProblem['date'] = ''
    newProblem['Address'] = ''
    newProblem['Geolocation'] = geolocation.getGeolocation()
    newProblem['problem'] = ''
    newProblem['description'] = ''
    newProblem['notes'] = ''
    newProblem['link']['lintcode'] = ''
    newProblem['link']['jiuzhangsuanfa'] = ''

    data['problems'][str(index)] = newProblem

    with open(fileName, 'w') as fhandler:
        json.dump(data, fhandler, indent=2, sort_keys=True)
