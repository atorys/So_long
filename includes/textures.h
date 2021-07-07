#ifndef TEXTURES_H
#define TEXTURES_H

# define T_PLAYER_R "textures/character_right.xpm"
# define T_PLAYER_L "textures/character_left.xpm"
# define T_PLAYER_U "textures/character_up.xpm"
# define T_PLAYER_D "textures/character_down.xpm"

# define T_SPRITE "textures/cherry3.xpm"
# define T_EXIT "textures/key.xpm"

# define T_WALL "textures/wall.xpm"
# define T_WALL_CUBE "textures/wall_cube.xpm"
# define T_WALL_DEST "textures/wall_destroed1.xpm"

# define T_BLOCK_L "textures/wooden_block.xpm"
# define T_BLOCK_R "textures/wooden_block1.xpm"
# define T_BLOCK_C "textures/wooden_block2.xpm"
# define T_BLOCK_E "textures/wooden_block3.xpm"
# define T_BLOCK_F "textures/wooden_block4.xpm"

# define T_FLOOR "textures/floor3.xpm"
# define T_FLOOR2 "textures/floor4.xpm"
# define T_FLOOR3 "textures/floor.xpm"
# define T_FLOOR4 "textures/floor2.xpm"

# define T_COL_T "textures/column_up.xpm"
# define T_COL_M "textures/column_middle.xpm"
# define T_COL_B "textures/column_down.xpm"
# define T_COL_H "textures/column_half.xpm"

# define T_TEETH_R "textures/tooth_right.xpm"
# define T_TEETH_L "textures/tooth_left.xpm"
# define T_TEETH_T "textures/tooth_up.xpm"
# define T_TEETH_B "textures/tooth_down.xpm"

# define T_CHAIN_T "textures/chain_up.xpm"
# define T_CHAIN "textures/chain.xpm"

# define T_GRASS1 "textures/grass.xpm"
# define T_GRASS2 "textures/grass2.xpm"
# define T_LAVA1 "textures/lavad.xpm"
# define T_LAVA2 "textures/lavad2.xpm"
# define T_ICE "textures/ice.xpm"



enum e_id {
	/** brick wall*/			ID_WALL,
	/** cube brick wall*/		ID_WALL_CUBE,
	/** destroyed brick wall*/	ID_WALL_DEST,

	/** wooden block: left*/	ID_BLOCK_L,
	/** wooden block: center*/	ID_BLOCK_C,
	/** wooden block: right*/	ID_BLOCK_R,
	/** wooden block: empty*/	ID_BLOCK_E,
	/** wooden block: full*/	ID_BLOCK_F,

	/** main floor color */		ID_FLOOR,
	/** floor with stones */	ID_FLOOR2,

	/** column top */			ID_COL_T,
	/** column middle */		ID_COL_M,
	/** column bottom */		ID_COL_B,
	/** column half */			ID_COL_H,

	/** enemy top */			ID_TEETH_T,
	/** enemy bottom */			ID_TEETH_B,
	/** enemy left */			ID_TEETH_L,
	/** enemy right */			ID_TEETH_R,

	/** chain top */			ID_CHAIN_T,
	/** chain middle */			ID_CHAIN,

	/** 20! grass one */		ID_GRASS1,
	/**  grass two */			ID_GRASS2,
	/** lava one */				ID_LAVA1,
	/** lava two */				ID_LAVA2,

	/** ice cube */				ID_ICE,
	/** exit key */				ID_EXIT,
	/** sprite */				ID_SPRITE,
	/** player */				ID_PLAYER,
};

#endif
