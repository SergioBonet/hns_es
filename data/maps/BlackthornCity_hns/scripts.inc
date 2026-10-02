BlackthornCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BlackthornCity_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, BlackthornCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BlackthornCity_OnLoad::
	goto_if_unset FLAG_BADGE05_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_unset FLAG_BADGE06_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_unset FLAG_BADGE07_GET, BlackThornCity_EventScript_MoveGymBoy
	end

BlackThornCity_EventScript_MoveGymBoy::
	setobjectxyperm LOCALID_BLACKTHORN_BOY, 24, 27
	end

BlackthornCity_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 4, BlackthornCity_EventScript_Call
	.2byte 0

BlackthornCity_EventScript_CityEnter:: 
	setflag FLAG_VISITED_BLACKTHORN_CITY
	callnative SetTimeBasedEncounters
	end

BlackthornCity_EventScript_Call::
	lock
	setspeaker BlackthornCity_Text_ElmName
	pokenavcall BlackthornCity_Text_ElmCall
	waitmessage
	delay 30
	setvar VAR_BLACKTHORN_CITY_STATE, 5
	setvar VAR_NEWBARKTOWN_LABSTATE, 7
	release
	end

BlackthornCity_Text_ElmName:
	.string "PROF. ELM$"

BlackthornCity_Text_BaobaCall:
	.string "GUARDA BAOBA: ¡{PLAYER}!\p"
	.string "Soy el GUARDA BAOBA.\p"
	.string "Te llamo para decirte que la ZONA\n"
	.string "SAFARI se ha ampliado.\p"
	.string "¡Ven a visitarla!$"

BlackthornCity_Text_ElmCall:
	.string "PROF. ELM: ¿Hola? ¿{PLAYER}?\p"
	.string "Tengo algo para ti. ¿Puedes pasarte\n"
	.string "por mi LABORATORIO?\p"
	.string "¡Hasta luego!$"

BlackThornCity_EventScript_Sage::
	lock
	faceplayer
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_SageRefuse
	msgbox BlackthornGrampsGrantsEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_SageRefuse::
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_Trigger_Sage::
	lock
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_EAST
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_WalkDown1
	waitmovement 0
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_SOUTH
	release
	end

BlackthornCity_EventScript_GymBoy::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE05_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_unset FLAG_BADGE06_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_unset FLAG_BADGE07_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_GymBoyBefore
	msgbox BlackthornCity_Text_ClairIsBeaten, MSGBOX_DEFAULT
	closemessage
	release
	end	

BlackThornCity_EventScript_GymBoyNotReady::
	msgbox BlackthornCity_Text_ClairNotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_GymBoyBefore::
	msgbox BlackthornCity_Text_ClairIsIn, MSGBOX_DEFAULT
	closemessage
	release
	end	

BlackthornCity_EventScript_BlackBelt::
	msgbox BlackBeltText_VoicesInMyHead, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF::
	msgbox BlackthornCooltrainerF1Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_Youngster::
	msgbox BlackthornYoungsterText, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF2::
	msgbox BlackthornCooltrainerF2Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_CitySign::
	msgbox BlackthornCitySignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_GymSign::
	msgbox BlackthornGymSignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_MoveHouseSign::
	msgbox BlackthornCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_DragonsDenSign::
	msgbox BlackthornCity_Text_DragonDenSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_Santos::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SPELL_TAG, BlackthornCity_EventScript_SantosCompleted
	msgbox BlackthornCity_MeetSantosText, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, BlackthornCity_EventScript_SantosNope
	case 1, BlackthornCity_EventScript_SantosNope
	case 2, BlackthornCity_EventScript_SantosNope
	case 3, BlackthornCity_EventScript_SantosNope
	case 4, BlackthornCity_EventScript_SantosNope
	case 5, BlackthornCity_EventScript_SantosNope
	case 6, BlackthornCity_EventScript_SantosYes
	case 7 BlackthornCity_EventScript_SantosCancel
	case MULTI_B_PRESSED, BlackthornCity_EventScript_SantosCancel
	closemessage
	release
	end
BlackthornCity_EventScript_SantosYes::
	msgbox BlackthornCity_SantosGivesGiftText, MSGBOX_DEFAULT
	giveitem ITEM_SPELL_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SPELL_TAG
	msgbox BlackthornCity_SantosGaveGiftText, MSGBOX_DEFAULT
	closemessage
	release
	end
BlackthornCity_EventScript_SantosNope::
	msgbox BlackthornCity_SantosNopeText, MSGBOX_DEFAULT
	closemessage
	release
	end
BlackthornCity_EventScript_SantosCancel::
	closemessage
	release
	end
BlackthornCity_EventScript_SantosCompleted::
	msgbox BlackthornCity_SantosSaturdayText, MSGBOX_DEFAULT
	closemessage
	release
	end


BlackthornCity_Text_ClairNotReady:
	.string "DÉBORA, nuestra LÍDER de GIMNASIO, ha\n"
	.string "seguido tus progresos.\p"
	.string "Pero solo lucha con ENTRENADORES que\n"
	.string "ya tengan 7 medallas.$"

BlackthornCity_Text_ClairIsIn:
	.string "DÉBORA, la LÍDER del GIMNASIO, te\n"
	.string "espera.\p"
	.string "Aunque, a alguien como tú le será\n"
	.string "imposible ganar.$"

BlackthornCity_Text_ClairIsBeaten:
	.string "¿Has vencido a DÉBORA?\n"
	.string "¡Impresionante!\p"
	.string "Nunca oí que perdiera contra nadie,\n"
	.string "excepto contra LANCE.$"

BlackthornGrampsRefusesEntryText:
	.string "No. Sólo los elegidos pueden\n"
	.string "entrenarse aquí. Por favor, vete.$"

BlackthornGrampsGrantsEntryText:
	.string "Si DÉBORA lo permite, su abuelo,\n"
	.string "nuestro MAESTRO, también lo permitirá.\p"
	.string "Puedes pasar.$"

BlackBeltText_VoicesInMyHead:
	.string "¡Auu! ¡Voces en mi cabeza! ¿Cómo?\p"
	.string "¡Estoy escuchando la radio!$"

BlackthornCooltrainerF1Text:
	.string "¿Vas a hacer que tus POKéMON\n"
	.string "recuerden algunos movimientos?$"

BlackthornYoungsterText:
	.string "Todos los expertos en dragones\n"
	.string "vienen de CIUDAD ENDRINO.$"

BlackthornCity_MeetSantosText:
	.string "SABINO: …\p"
	.string "Soy SABINO, de la familia de los días\n"
	.string "de la semana.\p"
	.string "Adivina.$"

BlackthornCity_SantosGivesGiftText:
	.string "Toma esto…$"

BlackthornCity_SantosGaveGiftText:
	.string "SABINO: …\p"
	.string "HECHIZO…\p"
	.string "Los movimientos de tipo FANTASMA se\n"
	.string "vuelven más fuertes…\p"
	.string "Te dará miedo…$"

BlackthornCity_SantosSaturdayText:
	.string "SABINO: …\p"
	.string "Nos vemos otro sábado…\p"
	.string "Pero ya no tendré más regalos…$"

BlackthornCity_SantosNopeText:
	.string "SABINO: No.$"

BlackthornCooltrainerF2Text:
	.string "¡Uau! ¿Has venido por la RUTA HELADA?\p"
	.string "¡Debes de ser genial!$"

BlackthornCitySignText:
	.string "CIUDAD ENDRINO\p"
	.string "Un tranquilo refugio de montaña$"

BlackthornGymSignText:
	.string "LÍDER DEL GIMNASIO POKéMON DE\n"
	.string "CIUDAD ENDRINO: DÉBORA\p"
	.string "La gran experta en POKéMON dragón$"

BlackthornCity_Text_MoveDeletersHouseSign:
	.string "CASA DE LOS HERMANOS DE LOS\n"
	.string "MOVIMIENTOS$"

BlackthornCity_Text_DragonDenSign:
	.string "HACIA LA GUARIDA DRAGÓN$"

