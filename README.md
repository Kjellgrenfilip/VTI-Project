# Driver Machine Interface

A project in which a standalone Driver Machine Interface (DMI) is developed. The DMI is designed to be used togheter with a simulator made by VTI, The Swedish National Road and Transport Research Institute.

## Information about QT

The DMI is implemented in QT, version 6.4. Additionaly the offical QT multimedia module is required. The module can be added to the framework via the included **maintenanceTool**.

### How to start the application

To start the application, do the following steps:

- Build / run the *test_module* application.
- Wait until the test_module has started (indicated by the debug message **server started**). 
- Build / run the *train_dmi* application. 

## Known bugs

- The application behaves & looks different depending on which OS the application is running on. 
- The application window can be resized during runtime, and all graphics will scale after this. However the speedometer will not scale but instead remain the same size. 

## Licence

Resultatet som genererats av studenten inom ramen för projektet ska ägas av *VTI*, statens väg- och transportforskningsinstitut som kan ta det i drift och vidareutveckla det. Studenten bibehåller rätten att stå som upphovsman och visa upp de ursprungliga resultaten, t ex i CV och portfolio.

### Authors

Filip Kjellgren

Viktor Lindell

Linus Olsson

Pontus Kågström

Erik Delbom

Linus Bergman

Mikael Johnsson