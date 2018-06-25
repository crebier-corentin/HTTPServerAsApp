# HTTPServerAsApp

With this project you can launch HTTP server in the background and have a a menu in the system tray.

![Example Tray Icon](https://raw.githubusercontent.com/bibo5088/HTTPServerAsApp/master/example.png "Example Tray Icon")

# Config file
`HTTPServerAsAppConfig.json`
```JS
{
   "name":"example",
   "port":0,
   "command":"node server.js",
   "icon": "SP_FileIcon"
}
```
Name of the App  
`"name":"example"`  
0 to chose the port automatically  
`"port":0`  
Command to start the server  
`"command":"node server.js"`  
Path to icon or QStyle::Standartpixmap (http://doc.qt.io/qt-5/qstyle.html#StandardPixmap-enum)  
`"icon": "SP_FileIcon"`

# Port
The port is passed as an argument when the program is run.
Exemple (port = 1234):  
`"command" : node server.js arg1`  
`node server.js arg1 1234`  

# DEV or normal?

 Dev : console app with server output.  
 Normal : app in background.
 
 To build the dev version :
 `qmake CONFIG+=DEV`
 
 # Building
 Should work with qt 5.9/5.10/5.11  
 http://doc.qt.io/qt-5/deployment.html
