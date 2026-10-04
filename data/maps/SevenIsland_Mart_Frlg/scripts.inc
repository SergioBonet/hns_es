SevenIsland_Mart_Frlg_MapScripts::
	.byte 0

SevenIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SevenIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
SevenIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

SevenIsland_Mart_EventScript_Lass::
	msgbox SevenIsland_Mart_Text_MonHavePersonalitiesOfTheirOwn, MSGBOX_NPC
	end

SevenIsland_Mart_EventScript_Hiker::
	msgbox SevenIsland_Mart_Text_PreparationsCompleteForRuins, MSGBOX_NPC
	end

SevenIsland_Mart_EventScript_Fisher::
	msgbox SevenIsland_Mart_Text_NeedToFishOnSevenIsland, MSGBOX_NPC
	end

SevenIsland_Mart_Text_MonHavePersonalitiesOfTheirOwn::
	.string "Los POKéMON tienen su propia\n"
	.string "personalidad, como cualquiera.\p"
	.string "Mi PIKACHU, por ejemplo, tiene\n"
	.string "una naturaleza ACTIVA, y realmente\l"
	.string "no para.$"

SevenIsland_Mart_Text_PreparationsCompleteForRuins::
	.string "Bueno, ya lo tengo todo para\n"
	.string "explorar las RUINAS.$"

SevenIsland_Mart_Text_NeedToFishOnSevenIsland::
	.string "Tengo que pescar en ISLA SÉTIMA.\p"
	.string "Es la que me falta para completar\n"
	.string "mi ruta por ARCHI7.\p"
	.string "Pero antes, voy a hacerme con\n"
	.string "unas cuantas POKé BALLS.$"

