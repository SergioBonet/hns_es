ThreeIsland_House5_Frlg_MapScripts::
	.byte 0

ThreeIsland_House5_EventScript_LittleGirl::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_LOSTELLE, ThreeIsland_House5_EventScript_LittleGirlLostelleFound
	msgbox ThreeIsland_House5_Text_ImNotLostelle
	release
	end

ThreeIsland_House5_EventScript_LittleGirlLostelleFound::
	msgbox ThreeIsland_House5_Text_IllGoPlayWithLostelle
	release
	end

ThreeIsland_House5_Text_ImNotLostelle::
	.string "¿Yo?\n"
	.string "No, yo no soy PEDRITA.\p"
	.string "Yo creo que se ha ido al BOSQUE\n"
	.string "BAYA.\p"
	.string "Se dedica a recoger BAYAS para\n"
	.string "hacer la comida.$"

ThreeIsland_House5_Text_IllGoPlayWithLostelle::
	.string "Creo que voy a irme a jugar\n"
	.string "con PEDRITA.$"

