# SDC255 Team 3 Final Project

This repository contains the Team 3 final project for SDC255.

## Team Assignments

### Addison Smith

Main Integration Function

Jira setup

GitHub setup

Final integration

### Torren Moore

Menu

Option Selector

### Adam Smithhisler

Write to File Function

Calculation 1 Function

### James Strohm

Read File Function

Calculation 2 Function

## File Structure

### main.c

Main program entry point and integration logic.

### menu.c and menu.h

Displays the program menu and returns the user selection.

### option_selector.c and option_selector.h

Handles the user selection and calls the correct function.

### read_file.c and read_file.h

Reads saved information from the output file.

### write_file.c and write_file.h

Writes program information to the output file.

### calculations.c and calculations.h

Contains Calculation 1.

### calculations_2.c and calculations_2.h

Contains Calculation 2.

## Project Links

Jira Board:

https://addsmi1720.atlassian.net/jira/software/projects/T3FP/summary

## Workflow

Each team member should work on the file that matches their assigned Jira user story. Jira will be used to track task status. GitHub will be used to store and combine the final project code.

Once all assigned files are uploaded, the team will review the function names, connect the source files through the header files, compile the program, test each menu option, and fix any errors before final submission.

## Current Program Flow

The program starts in main.c.

The main function calls the menu function from menu.c.

The menu function displays the options and returns the user choice.

The selected option is sent to the option selector.

The option selector calls the correct function based on the user choice.

The program continues running until the user selects option 5 to exit.

## Menu Options

Option 1 reads from the output file.

Option 2 writes sample output to the output file.

Option 3 runs Calculation 1.

Option 4 runs Calculation 2.

Option 5 exits the program.

## Final Submission Notes

The final project should include all source files, header files, the GitHub repository link, and any required code compilation testing document.

Before submission, the team should confirm that the full program compiles and that each menu option works as expected.
