
# New Feature - COM wrapper for uFCoder library

Implemented Component Object Model wrapper for uFCoder library.

```
COMuFCoder-x86.dll
```

## How to register COM library

```
regasm COMuFCoder-x86.dll /tlb /codebase
```
response:
```
Microsoft .NET Framework Assembly Registration Utility version 4.7.3056.0
for Microsoft .NET Framework version 4.7.3056.0
Copyright (C) Microsoft Corporation.  All rights reserved.

RegAsm : warning RA0000 : Registering an unsigned assembly with /codebase can cause your assembly to interfere with other applications that may be installed on the same computer. The /codebase switch is intended to be used only with signed assemblies. Please give your assembly a strong name and re-register it.
Types registered successfully
Assembly exported to 'W:\gitlab\nfc-rfid-reader-sdk\ufr-lib\windows\x86\COMuFCoder-x86.tlb', and the type library was registered successfully
```
