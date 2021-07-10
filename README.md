
 
# So_long 
   
**[in progress]**  
Graphic project **so_long**: small 2D game with miniLibX library.  
42 School subject: [**subject.pdf**](https://cdn.intra.42.fr/pdf/pdf/24614/en.subject.pdf) 

<img src="frames/simple.gif" width="400px">


## Task

- [x] falling
- [ ] falling animation
- [x] climbing
- [ ] jumping
- [ ] animated coins
- [ ] ability to break some blocks
- [ ] background animation
- [ ] aka enemy
- [ ] status bar
- [ ] menu
- [ ] maps

## Install & run

```
git clone https://github.com/atorys/So_long.git
```
```
make 
```
```
./so_long [map_name].ber
```
  
  
  
## Make your own map: [name].ber:
 Use these characters to put blocks


<table>
 <tr><td> P </td><td><img src="frames/spr_character_down.png" align="center" width="20px" height="20px" ></td><td></td><td> 1 </td><td><img src="frames/wall.png" align="center" width="20px" height="20px" ></td><td></td><td> U </td><td><img src="frames/column_up.png" align="center" width="20px" height="20px" ></td><td></td><td> 2 </td><td><img src=frames/wooden_block.png align="center" width="20px" height="20px" ></td><td></td><td> ^ </td><td><img src="frames/tooth_down.png" align="center" width="20px" height="20px" ><td></td><td> T </td><td><img src="frames/chain_up.png" align="center" width="20px" height="20px" ></td></tr>
 
 <tr><td> C </td><td><img src="frames/cherry3.png" align="center" width="20px" height="20px"></td><td>  </td><td> # </td><td><img src="frames/wall_destroed1.png" align="center" width="20px" height="20px" ></td><td>  </td><td> M </td><td><img src="frames/column_middle.png" align="center" width="20px" height="20px" ><td></td><td> 3 </td><td><img src=frames/wooden_block2.png align="center" width="20px" height="20px" ></td></td><td></td><td> > </td><td><img src="frames/tooth_left.png" align="center" width="20px" height="20px" ></td><td></td><td> | </td><td><img src="frames/chain.png" align="center" width="20px" height="20px" ></td></tr>
 
 <tr><td> E </td><td><img src="frames/key.png" align="center" width="20px" height="20px"></td><td>  </td><td> 0 </td><td><img src="frames/floor3.png" align="center" width="20px" height="20px"> </td><td>  </td><td> H </td><td><img src="frames/column_half.png" align="center" width="20px" height="20px" ></td><td></td><td> 4 </td><td><img src=frames/wooden_block1.png align="center" width="20px" height="20px" ></td><td></td><td> < </td><td><img src="frames/tooth_right.png" align="center" width="20px" height="20px" ></td></tr>
 
 <tr><td> G </td><td><img src="frames/grass.png" align="center" width="20px" height="20px"> </td><td>  </td><td> 8 </td><td><img src="frames/floor4.png" align="center" width="20px" height="20px"> </td><td>  </td><td> D </td><td><img src="frames/column_down.png" align="center" width="20px" height="20px" ></td><td></td><td> 5 </td><td><img src=frames/wooden_block4.png align="center" width="20px" height="20px" ></td><td></td><td> V </td><td><img src="frames/tooth_up.png" align="center" width="20px" height="20px" ></td></tr>
 
 <tr><td> L </td><td><img src="frames/lavad.png" align="center" width="20px" height="20px"> </td><td>  </td><td>  *</td><td><img src="frames/ice.png" align="center" width="20px" height="20px"> </td><td></td><td></td><td></td><td></td><td> 6 </td><td><img src=frames/wooden_block3.png align="center" width="20px" height="20px" ></td></tr>
</table>



##  Sources
#### Code sources
  - **get_frame_and_set_size.c**  function for setting new xpm image size made by [**@lignigno**](https://github.com/lignigno)  
  - minilibx library from [**42.docs**](https://harm-smits.github.io/42docs/libs/minilibx.html)
#### Textures
  - background tileset [Dungeon Platformer Tileset](https://rottingpixels.itch.io/platformer-dungeon-tileset)
___

[![forthebadge ](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
