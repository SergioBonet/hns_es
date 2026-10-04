CeladonCity_Condominiums_RoofRoom_Frlg_MapScripts::
	.byte 0

CeladonCity_Condominiums_RoofRoom_EventScript_BlackBelt::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_TheresNothingIDontKnow, MSGBOX_NPC
	end

CeladonCity_Condominiums_RoofRoom_EventScript_EeveeBall::
	lock
	faceplayer
	setvar VAR_TEMP_1, SPECIES_EEVEE
	givemon SPECIES_EEVEE, 25
	goto_if_eq VAR_RESULT, 0, CeladonCity_Condominiums_RoofRoom_EventScript_GetEeveeParty
	goto_if_eq VAR_RESULT, 1, CeladonCity_Condominiums_RoofRoom_EventScript_GetEeveePC
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	release
	end

CeladonCity_Condominiums_RoofRoom_EventScript_GetEeveeParty::
	removeobject LOCALID_EEVEE_POKEBALL
	playfanfare MUS_LEVEL_UP
	message CeladonCity_Condominiums_RoofRoom_Text_ObtainedAnEevee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_Condominiums_RoofRoom_EventScript_SetGotEevee
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto CeladonCity_Condominiums_RoofRoom_EventScript_SetGotEevee
	end

CeladonCity_Condominiums_RoofRoom_EventScript_GetEeveePC::
	removeobject LOCALID_EEVEE_POKEBALL
	playfanfare MUS_LEVEL_UP
	message CeladonCity_Condominiums_RoofRoom_Text_ObtainedAnEevee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_Condominiums_RoofRoom_EventScript_TransferEeveeToPC
	call Common_EventScript_NameReceivedBoxMon
	goto CeladonCity_Condominiums_RoofRoom_EventScript_TransferEeveeToPC
	end

CeladonCity_Condominiums_RoofRoom_EventScript_TransferEeveeToPC::
	call Common_EventScript_TransferredToPC
	goto CeladonCity_Condominiums_RoofRoom_EventScript_SetGotEevee
	end

CeladonCity_Condominiums_RoofRoom_EventScript_SetGotEevee::
	setflag FLAG_GOT_EEVEE
	release
	end

CeladonCity_Condominiums_RoofRoom_EventScript_TMsPamphlet::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_PamphletOnTMs, MSGBOX_SIGN
	end

CeladonCity_Condominiums_RoofRoom_EventScript_Blackboard::
	lockall
	msgbox CeladonCity_Condominiums_RoofRoom_Text_WirelessAdapterLecture
	message CeladonCity_Condominiums_RoofRoom_Text_ReadWhichHeading
	waitmessage
	setvar VAR_0x8004, 4
	multichoice 0, 0, MULTI_LINKED_DIRECT_UNION, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_Condominiums_RoofRoom_EventScript_WirelessClub
	case 1, CeladonCity_Condominiums_RoofRoom_EventScript_DirectCorner
	case 2, CeladonCity_Condominiums_RoofRoom_EventScript_UnionRoom
	case 3, CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard
	case 127, CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard
	end

CeladonCity_Condominiums_RoofRoom_EventScript_ReadAnotherHeading::
	message CeladonCity_Condominiums_RoofRoom_Text_ReadWhichHeading
	waitmessage
	multichoice 0, 0, MULTI_LINKED_DIRECT_UNION, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_Condominiums_RoofRoom_EventScript_WirelessClub
	case 1, CeladonCity_Condominiums_RoofRoom_EventScript_DirectCorner
	case 2, CeladonCity_Condominiums_RoofRoom_EventScript_UnionRoom
	case 3, CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard
	case 127, CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard
	end

CeladonCity_Condominiums_RoofRoom_EventScript_WirelessClub::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_ExplainWirelessClub
	goto CeladonCity_Condominiums_RoofRoom_EventScript_ReadAnotherHeading
	end

CeladonCity_Condominiums_RoofRoom_EventScript_DirectCorner::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_ExplainDirectCorner
	goto CeladonCity_Condominiums_RoofRoom_EventScript_ReadAnotherHeading
	end

CeladonCity_Condominiums_RoofRoom_EventScript_UnionRoom::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_ExplainUnionRoom
	goto CeladonCity_Condominiums_RoofRoom_EventScript_ReadAnotherHeading
	end

CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard::
	releaseall
	end

CeladonCity_Condominiums_RoofRoom_Text_TheresNothingIDontKnow::
	.string "Ya lo dice la pizarra, no hay nada\n"
	.string "que no sepa.\p"
	.string "¡Yo lo sé todo sobre el mundo de\n"
	.string "los POKéMON de tu GAME BOY\l"
	.string "ADVANCE!\p"
	.string "¡Reúnete con tus amigos y cambia\n"
	.string "POKéMON!$"

CeladonCity_Condominiums_RoofRoom_Text_ObtainedAnEevee::
	.string "¡{PLAYER} obtuvo un EEVEE!$"

CeladonCity_Condominiums_RoofRoom_Text_BoxIsFull::
	.string "Tu equipo POKéMON está lleno.\n"
	.string "Ve a cambiar de CAJA.$"

CeladonCity_Condominiums_RoofRoom_Text_WirelessAdapterLecture::
	.string "Charla POKéMON\p"
	.string "Jugando con el Conector inalámbrico$"

CeladonCity_Condominiums_RoofRoom_Text_ReadWhichHeading::
	.string "¿Qué capítulo quieres leer?$"

CeladonCity_Condominiums_RoofRoom_Text_ExplainWirelessClub::
	.string "El CLUB INALÁMBRICO POKéMON\n"
	.string "está en el piso de arriba de los\l"
	.string "CENTROS POKéMON.\p"
	.string "Visita uno para conectarte con tus\n"
	.string "amigos usando el Conector\l"
	.string "inalámbrico de GBA.$"

CeladonCity_Condominiums_RoofRoom_Text_ExplainDirectCorner::
	.string "Para conectarte sólo con un amigo,\n"
	.string "ve a la ZONA DIRECTA.\p"
	.string "Es el mostrador de la derecha\n"
	.string "del CLUB INALÁMBRICO POKéMON.\p"
	.string "Entra con tu amigo en el CENTRO\n"
	.string "de CAMBIO o en el COLISEO.$"

CeladonCity_Condominiums_RoofRoom_Text_ExplainUnionRoom::
	.string "Para conectarte y comunicarte con\n"
	.string "cualquiera, ve a la SALA UNIÓN.\p"
	.string "Es el mostrador de la izquierda\n"
	.string "del CLUB INALÁMBRICO POKéMON.\p"
	.string "Entra en la SALA UNIÓN y disfruta\n"
	.string "del encuentro con otros\l"
	.string "ENTRENADORES.$"

CeladonCity_Condominiums_RoofRoom_Text_PamphletOnTMs::
	.string "Es un informe sobre las MT.\p"
	.string "...\p"
	.string "Hay un total de 50 MT.\p"
	.string "Y siete MO, que pueden usarse\n"
	.string "una y otra vez.\p"
	.string "SILPH S.A.$"

