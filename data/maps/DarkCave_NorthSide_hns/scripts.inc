DarkCave_NorthSide_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DarkCave_NorthSide_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

DarkCave_NorthSide_OnTransition: 
	callnative SetTimeBasedEncounters
	end

DarkCave2_EventScript_Item_BlackFlute::
	finditem ITEM_BLACK_FLUTE
	end

DarkCave2_EventScript_Item_StarPiece::
	finditem ITEM_STAR_PIECE
	end

DarkCave2_EventScript_BlackGlasses::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_GLASSES, DarkCave2_EventScript_BlackGlassesGot
	msgbox DarkCave2_Text_Nerd, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_GLASSES
	setflag FLAG_GOT_BLACK_GLASSES
	closemessage
	release
	end

DarkCave2_EventScript_BlackGlassesGot::
	msgbox DarkCave2_Text_Nerd2, MSGBOX_DEFAULT
	closemessage
	release
	end

DarkCave2_Text_Nerd:
	.string "¡Uau! ¡Qué susto me has dado!\p"
	.string "Llevaba puestas las GAFAS DE SOL, así\n"
	.string "que no te había visto.\p"
	.string "¿Que qué hago aquí?\p"
	.string "Eh, no te preocupes por eso.\p"
	.string "Te daré unas GAFAS DE SOL, así que\n"
	.string "olvida que me has visto, ¿vale?$"

DarkCave2_Text_Nerd2:
	.string "Las GAFAS DE SOL potencian los\n"
	.string "movimientos de tipo SINIESTRO.$"
