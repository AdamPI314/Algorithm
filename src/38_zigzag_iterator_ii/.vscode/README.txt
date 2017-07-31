https://stackoverflow.com/questions/30046411/define-multiple-tasks-in-vscode

{ "command": "myCommand"
  "args": ["myCommandArguments"],
  "tasks" : [ 
    { "taskName": "myTask",
      "args": ["myTaskArguments"],
      "suppressTaskName": false,
    }
  ]
}

The above definition will result in the following command:

myCommand myCommandArguments myTaskArguments myTask

The task name myTask is always last. Since version 0.4 it can be omitted with "suppressTaskName": true.