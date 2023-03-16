# Маршрутное такси

Данный репозиторий представляет собой попытку моделирования движения маршрутного такси.

## Пояснения к классам
Для работы с классами используются  не только исходные (.cpp), но и заголовочные файлы (.h) .
Честно, я запуталась немного в указателях, где надо их применять, где не надо, поэтому в некоторых функциях в качестве аргументов передаются не указатели.

В проекте много классов, поэтому хотела бы немного пояснить, что есть что.
- [Util.cpp](task2/Util.cpp). Это класс, в который я вынесла вспомогательные функции, не относящиеся ни к такси, ни к пассажиру. А именно печать меню - `void  Util::Menu()` (заранее прошу прощения за английский язык в программе, просто почему-то у русского языка слетала кодировка именно при выкладывании на гит, в самом проекте все нормально, поэтому я решила изменить на английский всё); первоначальная инициализация мапы с ключом в виде остановки и значением в виде очереди пассажиров - `void  Util::fillStops(map<int, queue<Passenger>>* stopsMap)`; добавление пассажиров на остановку - `void Util::addPassengerToStop(int stop, map<int, queue<Passenger>>* stopsMap, Passenger* pass)`. Последняя функция - `void  Util::makeAnAction(map<int, queue<Passenger>>* map)` создана исходя из задания (при запуске программы маршрутка приезжает на остановку и пользователю предлагается выбрать действие, если он не хочет, то начинается высадка/посадка пассажиров, и такси едет на следующую остановку и так по кругу. 
-  [RouteTaxi.cpp](task2/RouteTaxi.cpp);
`vector<int> RouteTaxi::initStops()` - первоначальная инициализация остановок, по которым едет такси; `map<int, vector<Passenger>> RouteTaxi::initPassengers()` - первоначальная инициализация пассажиров, сидящих в такси;  `void  RouteTaxi::addPassengers(int currStop, Passenger pass)` - посадка в маршрутку, `void  RouteTaxi::dropOff(int currStop)` - высадка из маршрутки.
-   [StartMove.cpp](task2/StartMove.cpp) - класс, моделирующий движение маршрутки. Аргументы функции `void  StartMove::start(map<int, queue<Passenger>>* cursorMap, RouteTaxi* cursorTaxi)`: люди на остановках (мапа) и само такси. Начинаем двигаться по остановкам, на каждой остановке предлагаем пользователю выполнить какое-то действие, если он отказывается, то начинается высадка/посадка пассажиров. Едем, пока не проедем все остановки в одну сторону. Далее идет смена направления: `cursorTaxi->setDirection(false)`. При движении в обратную сторону происходит всё то же самое. Затем движение вновь меняет свое направление. Программа будет работать, пока `cout << "Do you want to see a menu? Print 1 - yes, smth else - no" << endl` в данном блоке кода не будет выбрана сначала 1, потом 2 -> при таких последовательных действиях программа завершится с кодом 2.
