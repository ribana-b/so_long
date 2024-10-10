# so_long

## Preview

> [!WARNING]
> **Photosensitive Warning**:
This illuminated dance floor may feature flashing or strobing lights. People who are sensitive to flashing lights or have a history of photosensitive epilepsy may be at risk of seizures or other symptoms. Viewer discretion is advised.
>
> If you experience dizziness, disorientation, or any other symptoms, **stop the preview**.

[preview.webm](https://github.com/user-attachments/assets/c9bc09a3-baa5-453b-be50-bde0ce03cdae)

## Description

So_long is a 2D game where the goal is to gather every collectible to open the exit and escape. It is made from _scratch_ with the
help of [MLX42](https://github.com/codam-coding-college/MLX42/tree/da6e42050b299e61aa2d96e5f08ac178c000514c).

It must have:

- A player.
- An exit.
- At least one collectible.
- Walls.

### Bonus

In the bonus part, it is required to have the following features:
- Add enemies, and the player loses when it touches any of them.
- Add sprite animations.
- Display the movement count on the screen.

## Usage

Clone the repository and build the program

```bash
git clone https://github.com/ribana-b/so_long
cd so_long
make
```

Run the program

```bash
./bin/so_long ./maps/map.ber
```

> [!NOTE]
> There are a bunch of maps in the maps folder, you can also create them.
> Just make sure that:
> - The map is rectangular and surrounded by walls
> - The player is able to win
> - The map name ends with `.ber` extension. For example `example.ber`

## Controls

|Key|Description|
|-|-|
|<kbd>W</kbd>, <kbd>Up Arrow</kbd>, <kbd>K</kbd>|Move up|
|<kbd>A</kbd>, <kbd>Left Arrow</kbd>, <kbd>H</kbd>|Move left|
|<kbd>S</kbd>, <kbd>Down Arrow</kbd>, <kbd>J</kbd>|Move down|
|<kbd>D</kbd>, <kbd>Right Arrow</kbd>, <kbd>L</kbd>|Move right|
|<kbd>ESC</kbd>, <kbd>Q</kbd>|Close the window|

_If you wonder why I added <kbd>h</kbd>, <kbd>j</kbd>, <kbd>k</kbd>, <kbd>l</kbd> as controls, I'm just going to say **vim enjoyer**._

## Sprites

I made every sprite using [LibreSprite](https://libresprite.github.io/#!/). But I used these images as reference.

- Chopper: https://gifer.com/es/2g8o
- Blackhole: https://www.pinterest.co.kr/pin/black-hole-space-pixel-art-by-sezalilly--1056797868785814756/
- Cotton candy: https://www.shutterstock.com/image-vector/pink-cotton-candy-pixel-art-icon-1549034876
- Speaker: https://es.vecteezy.com/arte-vectorial/5146426-altavoz-en-pixel-art-estilo
- Kairoseki: https://www.pngwing.com/en/free-png-zrzud

## Progress

If you are interested in checking my progress in 42 Common Core, I suggest you to take a look at [My Common Core Projects](https://github.com/ribana-b/#common-core)
