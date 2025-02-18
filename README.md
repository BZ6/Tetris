# Tetris in console

## Размеры

```cpp
// Tetris.cpp
const int FIELD_WIDTH = 10;
const int FIELD_HEIGHT = 20;
```

## Описание

Консольная игра "Тетрис". Клетки, которые показывают движущуюся фигуру, отрисованы с помощью "@".
Клетки, которые показывают поставленные фигуры, отрисованы с помощью "#". Клетки, которые пустые,
отрисованы с помощью ".". Если есть горизонтальные линии полностью состоящие из "#", то они
удаляются и линии сверху сдвигуются ниже.

  Фигуры бывают 7 видов:

- Прямая линия (I):

    ```text
    ■■■■
    ```  

- Квадрат (O):

    ```text
    ■■
    ■■
    ```

- Т-образная (T):

    ```text
    ■■■
     ■
    ```

- Z-образная (S):

    ```text
     ■■
    ■■
    ```

- Обратная Z-образная (Z):

    ```text
    ■■
     ■■
    ```

- Г-образная (L):

    ```text
    ■
    ■
    ■■
    ```

- Обратная Г-образная (J):

    ```text
     ■
     ■
    ■■
    ```

Игрок может взаимодействовать с фигурами с помощью:

- "w" -- поворот
- "s" -- движение вниз
- "a" -- движение влево
- "d" -- движение вправо
