# Driver Machine Interface

A project in which a standalone Driver Machine Interface (DMI) is developed. The DMI is designed to be used togheter with a simulator made by VTI.

## Information about QT

The DMI is implemented in the QT version 6.4 with the addition of the multimedia module. The module can be added to the framework via the included **maintenanceTool**.

### How to start the application

To start the application, do the following steps:

- Build / run the *test_module* application.
- Wait until the test_module has started (indicated by the debug message **server started**). 
- Build / run the *train_dmi* application. 

## Known bugs

- The application behaves & looks different depending on which OS the application is running on. 