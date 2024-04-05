This is the folder for PA5, the session logger.
This folder technically includes two files to be run: prog4 and prog5.
prog4 lies within the src/implem/ folder, while prog5 lies only within the src/ folder. 
prog4 is an updated and modified version of the previous prog4 in the corresponding folder.
It has been updated to store appropriate session chat logs in a .txt file that it will create, with the layout of sessionData[Year]_[Month]_[Day][Hour].
Hour is mainly put in so that it does not attempt to overwrite the session file with the same name due to being recorded on the same day.
At the end of the .txt files, it gives an overall user report at the end of the user responses, valid program responses, and the elapsed time of the program until termination.
These reports are also stored in chat_statistics.csv in the following format: txtname, userResponses,programResponses, elapsedTime

Most code was written by me, with appropriate credit given to Geeks4Geeks for the readFromCSV method. CoPilot was used to check the code for possible errors.