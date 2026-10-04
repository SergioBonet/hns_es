ThreeIsland_DunsparceTunnel_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_DunsparceTunnel_OnTransition
	.byte 0

ThreeIsland_DunsparceTunnel_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_THREE_ISLAND_DUNSPARCE_TUNNEL
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, TRUE, ThreeIsland_DunsparceTunnel_EventScript_SetLayoutDugOut
	call_if_eq VAR_0x8008, FALSE, ThreeIsland_DunsparceTunnel_EventScript_MoveProspectorToWall
	end

ThreeIsland_DunsparceTunnel_EventScript_SetLayoutDugOut::
	setmaplayoutindex LAYOUT_THREE_ISLAND_DUNSPARCE_TUNNEL_DUG_OUT
	return

ThreeIsland_DunsparceTunnel_EventScript_MoveProspectorToWall::
	setobjectxyperm LOCALID_PROSPECTOR, 6, 3
	setobjectmovementtype LOCALID_PROSPECTOR, MOVEMENT_TYPE_FACE_RIGHT
	return

ThreeIsland_DunsparceTunnel_EventScript_Prospector::
	lock
	faceplayer
	goto_if_set FLAG_GOT_NUGGET_FROM_DUNSPARCE_TUNNEL, ThreeIsland_DunsparceTunnel_EventScript_ProspectorAlreadyGaveNugget
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	goto_if_eq VAR_RESULT, TRUE, ThreeIsland_DunsparceTunnel_EventScript_ProspectorStruckGold
	msgbox ThreeIsland_DunsparceTunnel_Text_ProspectingForGold
	closemessage
	applymovement LOCALID_PROSPECTOR, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ThreeIsland_DunsparceTunnel_EventScript_ProspectorStruckGold::
	msgbox ThreeIsland_DunsparceTunnel_Text_StruckGoldThisIsForYou
	giveitem ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, ThreeIsland_DunsparceTunnel_EventScript_NoRoomForNugget
	setflag FLAG_GOT_NUGGET_FROM_DUNSPARCE_TUNNEL
	goto ThreeIsland_DunsparceTunnel_EventScript_ProspectorAlreadyGaveNugget
	end

ThreeIsland_DunsparceTunnel_EventScript_NoRoomForNugget::
	msgbox ThreeIsland_DunsparceTunnel_Text_WhoopsBagCrammedFull
	release
	end

ThreeIsland_DunsparceTunnel_EventScript_ProspectorAlreadyGaveNugget::
	msgbox ThreeIsland_DunsparceTunnel_Text_ThatsANugget
	release
	end

ThreeIsland_DunsparceTunnel_Text_ProspectingForGold::
	.string "Eh, ¿qué tal?\p"
	.string "¿Que qué hago aquí?\n"
	.string "Pues estoy buscando oro.\p"
	.string "Cuando consiga una fortuna,\n"
	.string "me compraré una casita en KANTO.$"

ThreeIsland_DunsparceTunnel_Text_StruckGoldThisIsForYou::
	.string "Eh, ¿cómo lo llevas?\n"
	.string "¿Sabes qué? ¡He encontrado oro!\p"
	.string "¿Recuerdas que te dije que estaba\n"
	.string "buscando?\p"
	.string "¡No te puedes ni imaginar lo feliz\n"
	.string "que soy!\p"
	.string "Toma, anda.\n"
	.string "Compartiré un poco contigo.$"

ThreeIsland_DunsparceTunnel_Text_ThatsANugget::
	.string "Es una PEPITA.\p"
	.string "No puedo darte pepitas de la\n"
	.string "sabiduría, ¡sólo esto!$"

ThreeIsland_DunsparceTunnel_Text_WhoopsBagCrammedFull::
	.string "Vaya, tienes la MOCHILA hasta\n"
	.string "arriba... Bueno, otra vez será.$"

