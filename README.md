# snake-game
Модификация классической игры "Змейка", реализованная на фреймворке Qt для языка C++.

В этой версии "Змейки" на игровом поле расположены препятствия, случайным образом генерируемые в начале каждой игры, а еда с 50% вероятности появляется ядовитой (обозначено красным цветом). Чтобы сделать отравленную еду безопасной, змейка должна обернуть вокруг неё три круга против часовой стрелки.

Запуск программы осуществляется в среде разработки Qt Creator версии не ниже 5 посредством открытия в ней файла проекта (.pro), его сборки и запуска.

Единственный объект класса GameField регулирует течение игры и контролирует игровое поле, разбитое на клетки. Каждой клетке соответствует объект либо фундаментального класса Block, либо одного из его дочерних классов, в виде экземпляров которых существуют все игровые сущности: препятствие, тело змейки, etc. Обороты змейки вокруг отравленной еды подсчитываются объектом класса WindingManager.

Скриншоты игрового процесса:

Безопасная еда:  
![image](https://user-images.githubusercontent.com/42893256/154997573-d5ea0fd8-a9ef-483e-a308-e0e817f5f1ab.png)

Отравленная еда:  
![image](https://user-images.githubusercontent.com/42893256/154997382-f7d13d7d-725c-44f6-86de-3d1293060cce.png)

Змейка наворачивает круги вокруг отравленной еды, делая её безопасной:  
![image](https://user-images.githubusercontent.com/42893256/154997263-3fe253c9-ca76-465c-8c83-3d26aa44a3cd.png)
