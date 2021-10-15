# Lovense SDK  2.0.1

The Windows SDK is a library provided for windows that allows you to have direct access to Lovense toys. You usually choose this option if you need to make your own application program.  
![avatar](https://github.com/caitain/test_SDK/blob/master/LovenseDongle.jpg#pic_center)



# Step 1: Get the Developer Token
Go to the [Dashboard](https://zh.lovense.com/user/developer/info), get your developer token.  
Note: You need to fill in the developer token when using the SDK, otherwise the SDK will not work.

# Step 2: Download demo examples and SDK
From the demo, you can find a quick way to get started.
## [Download Demo](https://test-front.lovense.com/lovense-developer/lovense-win-sdk-2.0.1-rc1.zip)
## [Download SDK](https://test-front.lovense.com/lovense-developer/lovense-win-sdk-2.0.1-rc1.zip)

# Step 3: Configure in Visual Studio 2019
1. Configuration header file   
![avatar](https://github.com/caitain/test_SDK/blob/master/configurehead.png)
2. Configure lib file   
![avatar](https://github.com/caitain/test_SDK/blob/master/configurelib.png)

# Step 4: Getting started

```c++
#include <Lovense.h>
...
class CEventCallBack: public ILovenseSDKNotify
{
	public:
		/*Call when toy search start*/
		virtual	void LovenseDidSearchStart();

		/*Call when toy searching toy*/
		virtual  void LovenseSearchingToys(lovense_toy_info_t *info) = 0;

		/*Call when Something went wrong*/
		virtual  void LovenseErrorOutPut(int errorCode,const char *errorMsg) = 0;


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
	//TODO:This is a simple process  
	CEventCallBack *callBack = new CEventCallBack();
	CLovenseToyManager *manager = GetLovenseToyManager();
	manager->SetDeveloperToken(...);
	manager->RegisterEventCallBack(callBack);
	manager->StartSearchToy();//Search for the toys via USB Dongle
```

# Step 5: How to send a command?

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
		.
		.
		.
	}
}
```

## Usage
1. Insert the usb Bluetooth adapter into the usb interface of the PC.
2. Then turn on the toy power and you will see the toy light flashing.
3. Open the app and start searching for toys.  
![avatar](https://github.com/caitain/test_SDK/blob/master/dongle-and-pc.png)

## Other instructions for using Dongle
1. When Dongle is searching for toys, it will not be able to send other commands for toys.
2. If you need to get the toy's power regularly, the best way is to start a thread loop to get it.
3. Don't send toy instructions frequently, because Dongle cannot process a large number of instructions in a short period of time.
4. If you use it for the first time, you can refer to the usage method in SDK Demo.

## View log output
Here is a simple way, is to use the editbin command.  
(You can see that there are logs output from the console.)  
Note:If there is an "editbin not found" error when compiling, there is a [solution](https://stackoverflow.com/questions/57207503/dumpbin-exe-editbin-exe-package-needed-in-visual-studio-2019).  
![avatar](https://github.com/caitain/test_SDK/blob/master/editbin.png)

