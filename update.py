"""
update, generate a new entry
"""
import json
import os
import sys
import copy

import geolocation
import getDate


class MyStr(str):

    def __lt__(self, other):
        """Override the default Equals behavior"""
        if isinstance(other, self.__class__):
            return int(self) < int(other)
        return NotImplemented

    def __gt__(self, other):
        """Override the default Equals behavior"""
        if isinstance(other, self.__class__):
            return int(self) > int(other)
        return NotImplemented

if __name__ == "__main__":
    fileDir = os.path.abspath(os.path.join(
        os.path.realpath(sys.argv[0]), os.pardir))
    fileName = os.path.join(fileDir, "demo.json")
    with open(fileName, 'r') as fhandler:
        data = json.load(fhandler)

    # update index, prev+1
    index = max([int(x) for x in data['problems'].keys()]) + 1
    newProblem = copy.deepcopy(data['problems']['1'])

    newProblem['date'] = getDate.get_date() 
    newProblem['Address'] = ''
    newProblem['Geolocation'] = geolocation.getGeolocation()
    newProblem['problem'] = ''
    newProblem['description'] = ''
    newProblem['notes'] = ''
    newProblem['link']['lintcode'] = ''
    newProblem['link']['jiuzhangsuanfa'] = ''

    data['problems'][str(index)] = newProblem

    newData = dict()
    newData['problems'] = dict()
    for key, val in data['problems'].items():
        newData['problems'][MyStr(key)] = val

    with open(fileName, 'w') as fhandler:
        json.dump(newData, fhandler, indent=4, sort_keys=True)

    print("Job Finished.")
