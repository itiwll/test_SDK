# Lovense SDK  1.0.0

Welcome to the [Lovense SDK](https://zh.lovense.com/user/developer/info) repository, built using C and C++. The SDK is a library provided for windows that allows you to have direct access to Lovense toys. You usually choose this option if you need to make your own application program.

----
## Features

| Feature | Supported |
|----------|------------ |
| Windows x86 x64  | ✔ |
| Standalone | ✔ |
| Free | ✔ |
| MIT license | ✔ |
| HID USB Dongle | ✔ |
| BLE USB Dongle | ✔ |

##Dynamic library compilation

| DLL | Supported |
|----------|------------ |
| Lovense.dll  | Unicode(MT/MTD) |

## Usage
1. Insert the usb Bluetooth adapter into the usb interface of the PC.
2. Then turn on the toy power and you will see the toy light flashing.
3. Open the app and start searching for toys.

### Getting started

```c++
#include <Lovense.h>
...
class CEventCallBack: public ILovenseSDKNotify
{
	public:
		/*Call when toy search start*/
		virtual	void LovenseDidSearchStart();

		/*Call when toy searching toy*/
		virtual  void LovenseSearchingToys( CToyInfo toyInfo);

		/*Call when Something went wrong*/
		virtual  void LovenseErrorOutPut(int errorCode,const char *errorMsg);

		/*Call when toy search end*/
		virtual  void LovenseDidSearchEnd();

		/*Call when send cmd start*/
		virtual	void LovenseDidSendCmdStart();

		/*Call when send cmd return*/
		virtual  void LovenseSendCmdResult(const char * szToyID, CLovenseToy::CmdType cmd,const char *result,CLovenseToy::Error errorCode);

		/*Call when send cmd end*/
		virtual	void LovenseDidSendCmdEnd();

		/*Call when toy connected, or disconnected*/
		virtual void LovenseToyConnectedStatus(const char *szToyID, bool isConnected) ;
};

...
	CEventCallBack *callBack = new CEventCallBack();
	CLovenseToyManager *manager = GetLovenseToyManager();
	manager->SetDeveloperToken(...);
	manager->RegisterEventCallBack(callBack);
	manager->StartSearchToy();//Search for the toys via USB Dongle
```

### How to send a command?

```c++
	CLovenseToyManager *manager = GetLovenseToyManager();
	//Send a vibration command
	manager->SendCommand(toyID,CLovenseToy::CmdType::COMMAND_VIBRATE,10);

```

### What commands are supported?
You can see the following definition in LovenseDef.h.
```c++
namespace CLovenseToy
{
	typedef enum {

		/**
		-Power off!
		- param Key = no parameter
		*/
		COMMAND_POWER_OFF = 100,

		/**
		- Vibrate the toy .The parameter must be between 0 and 20!
		- Supported toys = all
		*/
		COMMAND_VIBRATE = 101,

		/**
		- Rotate the toy .The parameter must be between 0 and 20!
		- Supported toys = Nora
		*/
		COMMAND_ROTATE = 102,
```
## Version
Release:1.0.0
