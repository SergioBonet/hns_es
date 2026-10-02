ViridianCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianCity_OnFrame
	.byte 0

ViridianCity_EventScript_CityEnter::
	setflag FLAG_VISITED_VIRIDIAN_CITY
	end

ViridianCity_OnFrame::
	map_script_2 VAR_OAK_MT_SILVER_CALL, 1, ViridianCity_EventScript_OakCall
	.2byte 0

ViridianCity_EventScript_OakCall::
	lock
	setspeaker ViridianCity_Text_OakName
	pokenavcall ViridianCity_Text_OakCall
	waitmessage
	delay 30
	setvar VAR_OAK_MT_SILVER_CALL, 2
	release
	end

ViridianCity_Text_OakName:
	.string "OAK$"

ViridianCity_Text_OakCall:
	.string "OAK: ¡Ah, {PLAYER}!\p"
	.string "Ven a verme a mi LABORATORIO de\n"
	.string "PUEBLO PALETA cuando tengas ocasión.$"

ViridianCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox ViridianCity_Text_CoffeeGramps_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_EventScript_GrampsDoubted
	msgbox ViridianCity_Text_CoffeeGramps_Believed, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_EventScript_GrampsDoubted::
	msgbox ViridianCity_Text_CoffeeGramps_Doubted, MSGBOX_DEFAULT
	closemessage
	release
	end

VirianCity_EventScript_GymGramps::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_Text_GrampsNearGym, MSGBOX_NPC
	end

VirianCity_EventScript_GymGrampsBlue::
	msgbox ViridianCity_Text_GrampsNearGym_BlueReturned, MSGBOX_NPC
	end

ViridianCity_EventScript_Fisher::
	goto_if_set FLAG_GOT_VIRIDIAN_TM_DREAM_EATER, ViridianCity_EventScript_FisherAfter
	msgbox ViridianCity_Text_DreamEaterFisher, MSGBOX_NPC
	giveitem ITEM_TM_DREAM_EATER
	setflag FLAG_GOT_VIRIDIAN_TM_DREAM_EATER
	end

ViridianCity_EventScript_FisherAfter::
	msgbox ViridianCity_Text_DreamEaterFisher_GotTM, MSGBOX_NPC
	end

ViridianCity_EventScript_Youngster::
	msgbox ViridianCity_Text_Youngster, MSGBOX_NPC
	end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_WelcomeSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_CitySign2::
	msgbox ViridianCity_Text_Sign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_Text_CoffeeGramps_Question:
	.string "¡Hola! ¡Me acabo de tomar un café\n"
	.string "doble y estoy como una moto!\p"
	.string "¡Tengo que hablar con alguien, así que\n"
	.string "te toca a ti!\p"
	.string "Puede que ahora no lo parezca, pero yo\n"
	.string "era un experto atrapando POKéMON.\p"
	.string "¿Me crees?$"

ViridianCity_Text_CoffeeGramps_Believed:
	.string "Muy bien. Sí, yo era algo fuera de lo\n"
	.string "normal. ¡Déjame contártelo!$"

ViridianCity_Text_CoffeeGramps_Doubted:
	.string "¿Qué? ¡Serás insolente!\p"
	.string "Si fuera un poco más joven, te\n"
	.string "enseñaría un par de cosas. ¡Vaya!$"

ViridianCity_Text_GrampsNearGym:
	.string "Este GIMNASIO no ha tenido LÍDER\n"
	.string "hasta hace poco.\p"
	.string "Un joven de PUEBLO PALETA se\n"
	.string "convirtió en LÍDER pero viaja mucho.$"

ViridianCity_Text_GrampsNearGym_BlueReturned:
	.string "¿Vas a enfrentarte al LÍDER?\p"
	.string "¡Buena suerte! ¡La vas a necesitar!$"

ViridianCity_Text_DreamEaterFisherNew:
	.string "… Zzzzz…\p"
	.string "¡Aaah!\p"
	.string "Me habré quedado dormido al sol.\p"
	.string "¿Qué? ¿Que te recuerdo a alguien?\p"
	.string "No sé, toma, quédate esto.$"


ViridianCity_Text_DreamEaterFisher_GotTM::
	.string "… Zzzzz…$"

ViridianCity_Text_DreamEaterFisher:
	.string "¡Qué sueño!\p"
	.string "Me habré quedado dormido al sol.\p"
	.string "He soñado que un DROWZEE se comía mi\n"
	.string "sueño.\p"
	.string "Es raro, ¿verdad?\p"
	.string "¿Eh? ¿Qué es esto?\p"
	.string "¿De dónde ha salido esta MT?\p"
	.string "¡Esto es muy misterioso! Aquí tienes\n"
	.string "esta MT.$"

ViridianCity_Text_DreamEaterFisher_GotDreamEater:
	.string "MT42 contiene COME SUEÑOS…\p"
	.string "¡Zzzzz…!$"

ViridianCity_Text_Youngster:
	.string "Dicen que en el suelo del BOSQUE\p"
	.string "VERDE hay muchos objetos.$"

ViridianCity_Text_Sign:
	.string "CIUDAD VERDE\p"
	.string "El paraíso eternamente verde$"

ViridianCity_Text_GymSign:
	.string "LÍDER DEL GIMNASIO POKéMON DE\n"
	.string "CIUDAD VERDE:…\p"
	.string "El resto del texto es ilegible…$"

ViridianCity_Text_WelcomeSign:
	.string "Ésta es la CIUDAD VERDE, la entrada a\n"
	.string "la MESETA AÑIL$"

ViridianCity_Text_TrainerHouseSign:
	.string "CASA DEL ENTRENADOR\p"
	.string "Club de Mejores Entrenadores$"
