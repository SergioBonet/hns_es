Route30_MrPokemonsHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MrPokemonHouse_OnFrame
	.byte 0

MrPokemonHouse_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 1, MrPokemonHouse_EventScript_GiveEgg
	.2byte 0

MrPokemonHouse_EventScript_GiveEgg::
	lock
	playse SE_PIN
	applymovement LOCALID_MRPOKEMON, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_MRPOKEMON
	turnobject LOCALID_MRPOKEMON, DIR_SOUTH
	msgbox MrPokemonHouse_Text_Intro1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MrPokemonHouse_Movement_MeetMrPokemon
	waitmovement 0
	msgbox MrPokemonHouse_Text_Intro2, MSGBOX_DEFAULT

	giveitem ITEM_MYSTERY_EGG

	msgbox MrPokemonHouse_Text_Intro3, MSGBOX_DEFAULT
	msgbox MrPokemonHouse_Text_Intro4, MSGBOX_DEFAULT
	turnobject LOCALID_ROUTE30_OAK, DIR_WEST
	msgbox MrPokemonHouse_Text_Intro5, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_HG_OAK, FALSE
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakToPlayer
	waitmovement 0 
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox MrPokemonHouse_Text_OakIntro, MSGBOX_DEFAULT
	

	playfanfare MUS_OBTAIN_ITEM
	message MrPokemonHouse_Text_GetDex
	waitfanfare

	
	msgbox MrPokemonHouse_Text_OakParting, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_ROUTE30_OAK
	setflag FLAG_DELIVERED_EGG
	turnobject OBJ_EVENT_ID_PLAYER DIR_NORTH
	fadedefaultbgm
	msgbox MrPokemonHouse_Text_Heal, MSGBOX_DEFAULT
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox MrPokemonHouse_Text_DependingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MRPOKEMON, MrPokemonHouse_Movement_MrPokemon_Leave
	waitmovement 0
	removeobject LOCALID_MRPOKEMON
	clearflag FLAG_HIDE_MRPOKEMON
	addobject LOCALID_MRPOKEMON2
	
	setvar VAR_NEWBARKTOWN_LABSTATE, 4
	setflag FLAG_HIDE_SILVER_NEWBARKTOWN
	setflag FLAG_SYS_POKEDEX_GET
	checkrandomizer
	call_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_GiveNatDexRandomizer
	clearflag FLAG_HIDE_LAB_POLICEMAN
	setvar VAR_CHERRYGROVE_CITY_STATE, 2
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY_HNS
	clearflag FLAG_HIDE_SILVER_CHERRYGROVE
	setflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
	clearflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	release
	end

MrPokemonHouse_EventScript_GiveNatDexRandomizer::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

MrPokemonHouse_EventScript_MrPokemon::
	lock
	faceplayer
	checkitem ITEM_RED_SCALE
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale
	msgbox MrPokemonHouse_Text_AlwaysNewDiscoveries, MSGBOX_DEFAULT
	closemessage
	release
	end

MrPokemonHouse_EventScript_MrPokemon_RedScale::
	msgbox MrPokemonHouse_Text_GimmeTheScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted
	msgbox MrPokemonHouse_Text_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end	

MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted::
	removeitem ITEM_RED_SCALE
	giveitem ITEM_EXP_SHARE_SMALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end


MrPokemonHouse_EventScript_Computer::
	lock
	msgbox MrPokemonHouse_Text_BrokenComputer, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Magazine::
	lock
	msgbox MrPokemonHouse_Text_ForeignMagazines, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Coins::
	lock
	msgbox MrPokemonHouse_Text_StrangeCoins, MSGBOX_SIGN
	release
	end

MrPokemonHouse_Movement_MeetMrPokemon:
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

MrPokemonHouse_Movement_OakToPlayer:
	walk_down
	face_left
	step_end

MrPokemonHouse_Movement_OakLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_down
	step_end

MrPokemonHouse_Movement_MrPokemon_Leave:
	walk_up
	walk_left
	walk_left
	step_end

MrPokemonHouse_Text_Intro1:
	.string "¡Hola, hola! Tú debes de ser {PLAYER}.\p"
	.string "El PROF. ELM me dijo que vendrías.$"

MrPokemonHouse_Text_Intro2:
	.string "Esto es lo que quiero que examine el\n"
	.string "PROF. ELM.$"

MrPokemonHouse_Text_GotEgg:
	.string "{PLAYER} recibió un HUEVO MISTERIOSO.$"

MrPokemonHouse_Text_Intro3:
	.string "Conozco a una pareja que tiene una\n"
	.string "GUARDERÍA POKéMON.\p"
	.string "Ellos me dieron ese HUEVO.\p"
	.string "Como me intrigaba, le mandé una carta\n"
	.string "al PROF. ELM.\p"
	.string "El PROF. ELM es la máxima autoridad en\n"
	.string "evolución de los POKéMON.$"


MrPokemonHouse_Text_Intro4:
	.string "Hasta el PROF. OAK lo reconoce.$"

MrPokemonHouse_Text_Intro5:
	.string "Si mi suposición es correcta, el PROF.\n"
	.string "ELM lo sabrá.$"

MrPokemonHouse_Text_Heal:
	.string "¿Vas a ir a ver al PROF. ELM?\p"
	.string "Toma. Tus POKéMON deberían descansar\n"
	.string "un poco.$"

MrPokemonHouse_Text_DependingOnYou:
	.string "¡Confío en ti!$"

MrPokemonHouse_Text_AlwaysNewDiscoveries:
	.string "¡La vida es maravillosa! Siempre hay\n"
	.string "cosas nuevas que descubrir.$"

MrPokemonHouse_Text_OakIntro:
	.string "OAK: ¡Ajá! ¡Así que tú eres {PLAYER}!\p"
	.string "¡Soy OAK! Un investigador de POKéMON.\p"
	.string "He venido a visitar a mi viejo amigo, el\n"
	.string "SR. POKéMON.\p"
	.string "Me enteré de que estabas haciendo un\n"
	.string "recado para el PROF. ELM, así que te he\l"
	.string "esperado aquí.\p"
	.string "¡Oh! ¿Qué es esto? ¡Un POKéMON raro!\p"
	.string "A ver… Mmm, ¡ya veo!\p"
	.string "Entiendo por qué el PROF. ELM te dio un\n"
	.string "POKéMON para este recado.\p"
	.string "Para los investigadores como el PROF.\n"
	.string "ELM y yo, los POKéMON son nuestros\l"
	.string "amigos.\p"
	.string "Él vio que tratarías a tu POKéMON con\n"
	.string "cariño y cuidado.\p"
	.string "… ¡Ah!\p"
	.string "Pareces de fiar. ¿Te gustaría\n"
	.string "ayudarme?\p"
	.string "¿Ves? Esta es la última versión de la\n"
	.string "POKéDEX.\p"
	.string "Registra automáticamente los datos\n"
	.string "de los POKéMON que has visto o\l"
	.string "atrapado.\p"
	.string "¡Es una enciclopedia de alta\n"
	.string "tecnología!\p"
	.string "Muestra su hábitat, cómo evolucionan\n"
	.string "y sus movimientos.$"

MrPokemonHouse_Text_GetDex:
	.string "¡{PLAYER} recibió la POKéDEX!$"

MrPokemonHouse_Text_OakParting:
	.string "¡Ve a conocer muchas clases de\n"
	.string "POKéMON y completa esa POKéDEX!\p"
	.string "Pero ya me he entretenido demasiado.\p"
	.string "Tengo que ir a CIUDAD TRIGAL para mi\n"
	.string "programa de radio de siempre.\p"
	.string "{PLAYER}, ¡cuento contigo!$"

MrPokemonHouse_Text_GimmeTheScale:
	.string "¿Mmm? ¡Esa ESCAMA! ¿Qué es eso? ¿Un\n"
	.string "GYARADOS rojo?\p"
	.string "¡Qué raro! Yo… yo la quiero…\p"
	.string "{PLAYER}, ¿te importaría cambiármela?\p"
	.string "Puedo ofrecerte este REPARTIR EXP\n"
	.string "que me dio el PROF. OAK.$"

MrPokemonHouse_Text_Disappointed:
	.string "Es una pena. Es realmente raro.$"

MrPokemonHouse_Text_ExpShare:
	.string "También tengo un objeto especial para\n"
	.string "ti.$"

MrPokemonHouse_Text_ForeignMagazines:
	.string "Lleno de revistas extranjeras.\p"
	.string "Ni siquiera puedo leer los títulos.$"

MrPokemonHouse_Text_BrokenComputer:
	.string "Es un ordenador enorme. ¡Mmm! Está\n"
	.string "estropeado.$"

MrPokemonHouse_Text_StrangeCoins:
	.string "¡Un montón de monedas extrañas!\p"
	.string "Quizá sean de otro país…$"

MrPokemonHouse_Text_GotExpShare:
	.string "¡{PLAYER} ha recibido el REPARTIR EXP!$"
