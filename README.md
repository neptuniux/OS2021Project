# The Müller's closet

This project is a part of the UniFR's Operating System course. The goal is to develop a C or C++ program to apply the notions seen in class.

## Support
The project is currently only supported by Linux because of the Pthread and the QT GUI that doesn't support the Pthreads. A possible solution could be found here: [Qthreads in QT](https://doc.qt.io/qt-5/qthread.html#details)

## Installation 
To install this software follow these steps:
Clone the is repository and open a terminal in the extracted directory.
```bash
mkdir build
cd build
cmake ..
cmake --build .
```
To execute he program simply type and pray.
```bash
./OS2021Project
```

## Usage
To test the software one can use the all in one method containing all the units test made.
```c++
fullTest();
```
This method contains the test of scenario1 and scenario23.

To run the software's GUI (made with QT) one can run:
```c++
QApplication a(argc, argv);
mainWindows w;
w.show();
return a.exec();
```

If we want to implement a behavior directly in the main one can use these functions to create the necessary objects:
```c++
//objects creation
WardRobe* objWardrobe = new WardRobe();
Family testFamily();
```
The wardrobe object is described as follow:
```c++
void *putBagIntoWardrobe(void *threadarg);

//properties
int id;
std::vector<Cloth> wardrobe;

//constructor
WardRobe();

//methods
int addFamBagsToWardrobe(Family family);
void cleanWardrobe(int toClean);
void cleanWardrobe();
int getId() const;
std::vector<Cloth> &getWardrobe();
int addClothToWardrobe(const Cloth &cloth);
Cloth popCloth(int clothid);
Cloth popClothName(std::string clothname);
int getAmount(std::string name);

//methods for testing purpose
int useRandomCloth(const Member &member);
int useRandomCloth();
```

The family object is described as follow:
```c++
//properties
int id;
std::vector<Member> family;

//constructors
Family();
explicit Family(int amount);

//methods
void goShopping(int numberItems);
void goShopping();

//methods for testing purpose
Member &getRandMember();
std::vector<Member> generateTestFamily(int amount);
```

The cloth object is described as follow:
```c++
//properties
std::string name;
int id;
int ownerID;
time_t created;
time_t lastUsed;

//constructors
Cloth(std::string name, int ownerId);
explicit Cloth(int ownerId);

//method
void updateUseDate();
```

The member object is described as follow:
objects:
```c++
//properties
int id;
std::string firstname;
std::string lastname;
std::vector<Cloth> bag;

//constructors
Member(std::string firstname, std::string lastname);
Member();

//methods
int addClohToBag(const Cloth &cloth);
[[nodiscard]] int getId() const;
[[nodiscard]] const std::string &getFirstname() const;
[[nodiscard]] const std::string &getLastname() const;
[[nodiscard]] const std::vector<Cloth> &getBag() const;
void cleanbag();
```

## Final words
The software is conceived using the paradigm KISS (keep it simple and stupid) to ensure the readability and an easier manipulation/expansion capability.

## License
[MIT](https://choosealicense.com/licenses/mit/)
