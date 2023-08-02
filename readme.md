
# SSH Config File Modifier

I'm tired changing ssh config file line by line when transferring my work from vscode pc to vscode mac. This program is a utility written in C++ designed to modify SSH configuration files for compatibility between Windows and macOS systems. The primary function is to replace the absolute path of the IdentityFile in Windows with a relative path for macOS. You can use this utility if you have more than 20 ssh hosts.

# Why C++?
I'm working in a windows environment so c++ is a good choice since I can just run .exe file.

# How it works
The program works by reading the SSH configuration file line by line. If a line contains the absolute path `C:\Users\<username>`, it replaces it with the relative path `~`. The modified lines are then written to a new file and put in the Desktop by default.

The user is asked to input their username, which is used to construct the absolute path to the SSH configuration file.

Assuming the users directory is inside `C:\Users` otherwise, you can modify the code to your liking.

# Usage
- Before everything, this program assumes your .ssh/config file is located in `C:\Users\<username>` and in mac your .ssh/config is located in `~/.ssh/config`. This program also assumes that your primary workstation is windows and you have the same number of hosts in windows and in mac. If not, then modify the code to your custom needs.
- Copy all your key files (pem, ppk, rsa) from your `C:\Users\<username>\.ssh` to your mac in `~/.ssh/`. This is required so that there will be no missing key when you copy your newly modified config file to your `~/.ssh/`
- Run the .exe file and input your Username
- The file will be generated in your Desktop, copy it and send it to your mac.
- If you have `~/.ssh/config` already in your mac, just rename it to something like .tmp or bak and replace it with your new config file.
- Refresh vscode Remotes
![image](https://i.imgur.com/lBH1kGU.png)
