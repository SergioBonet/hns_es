BattleFrontier_BattleFactoryLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp_hns
	.byte 0

BattleFrontier_BattleFactoryLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving_hns::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting_hns, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge_hns::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead_hns
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins_hns, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead_hns, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave_hns
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_save 0
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge_hns::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMons_hnsSaveResults_hns
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle_hns::
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle_hns
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle_hns
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle_hns

BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle_hns::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge_hns::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume_hns
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge_hns

BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant_hns::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_Attendant_hns::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle_hns
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge_hns
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge_hns

BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
	setvar VAR_0x8006, 0
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge_hns::
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay_hns, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant_hns
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor_hns
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM_HNS, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant_hns::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant_hns::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge_hns
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge_hns::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor_hns:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge_hns::
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge_hns
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge_hns::
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge_hns
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_Woman_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves_hns, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon_hns, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker_hns::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints_hns, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics_hns
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner_hns
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber_hns
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes_hns
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv_hns
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle_hns:
	.string "¡Aquí ponemos a prueba el saber\n"
	.string "de los ENTRENADORES!\p"
	.string "¡Te doy la más calurosa bienvenida\n"
	.string "a la FÁBRICA BATALLA!\p"
	.string "Yo soy el guía del TORNEO de COMBATES\n"
	.string "con TRUEQUE INDIVIDUALES.$"

BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge_hns:
	.string "¿Participas en el TORNEO de COMBATES\n"
	.string "con TRUEQUE INDIVIDUALES?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge_hns:
	.string "En el TORNEO de COMBATES con TRUEQUE\n"
	.string "INDIVIDUALES se disputan COMBATES\l"
	.string "con POKéMON prestados.\p"
	.string "Primero, debes elegir los tres POKéMON\n"
	.string "con los que vas a comenzar el torneo.\p"
	.string "Con esos POKéMON prestados, debes\n"
	.string "luchar en el primer COMBATE INDIVIDUAL.\p"
	.string "Si ganas a tu rival, tendrás derecho a\n"
	.string "un trueque: podrás elegir uno de sus\l"
	.string "POKéMON y cambiárselo por uno tuyo.\p"
	.string "Repite este ciclo de combate y trueque\n"
	.string "y, si logras ganar siete veces seguidas,\l"
	.string "conseguirás PUNTOS de BATALLA.\p"
	.string "Si quieres interrumpir el desafío,\n"
	.string "no olvides guardar antes la partida.\p"
	.string "Si no la guardas, se te descalificará.$"

BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit_hns:
	.string "Esperamos que vuelvas a visitarnos.\p"
	.string "$"

BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode_hns:
	.string "¿En qué nivel deseas participar?\n"
	.string "¿Nivel 50 o nivel libre?$"

BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge_hns:
	.string "Antes de comenzar,\n"
	.string "tengo que guardar la partida, ¿vale?$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping_hns:
	.string "Muy bien. Guardaré tus POKéMON\n"
	.string "mientras participas.$"

BattleFrontier_BattleFactoryLobby_Text_StepThisWay_hns:
	.string "Por aquí, por favor.$"

BattleFrontier_BattleFactoryLobby_Text_ReturnMons_hnsSaveResults_hns:
	.string "¡Gracias por participar!\p"
	.string "Voy a devolverte tus POKéMON\n"
	.string "a cambio de los que te prestamos.\p"
	.string "Y voy a guardar también tus resultados.\n"
	.string "Un momento, por favor.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReturnMons_hns:
	.string "Te devolveré tus POKéMON a cambio de\n"
	.string "nuestros POKéMON de alquiler.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins_hns:
	.string "¡Bravo! ¡Has ganado siete encuentros\n"
	.string "seguidos de COMBATE con TRUEQUE!$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints_hnsForStreak_hns:
	.string "Como reconocimiento a tu racha de 7\n"
	.string "victorias, te entregamos estos\l"
	.string "Puntos de Batalla.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints_hns:
	.string "¡Vaya, vaya, vaya!\p"
	.string "Ya tienes el máximo de Puntos de\n"
	.string "Batalla.\p"
	.string "Vuelve cuando hayas gastado algunos.$"

BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume_hns:
	.string "¡Te estábamos esperando!\p"
	.string "Antes de continuar el desafío,\n"
	.string "debo guardar la partida.$"

BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting_hns:
	.string "Siento decírtelo, pero no guardaste\n"
	.string "la partida la última vez que jugaste.\p"
	.string "Así que se te ha descalificado.\n"
	.string "Lo siento.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons_hns:
	.string "Te devolvemos tus POKéMON.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem_hns:
	.string "{PLAYER} recibió el premio\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle_hns:
	.string "¡Aquí ponemos a prueba el saber\n"
	.string "de los ENTRENADORES!\p"
	.string "¡Te doy la más calurosa bienvenida\n"
	.string "a la FÁBRICA BATALLA!\p"
	.string "Yo soy el guía del TORNEO de COMBATES\n"
	.string "con TRUEQUE DOBLES.$"

BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge_hns:
	.string "¿Participas en el TORNEO de COMBATES\n"
	.string "con TRUEQUE DOBLES?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge_hns:
	.string "En el TORNEO de COMBATES con TRUEQUE\n"
	.string "DOBLES se disputan COMBATES\l"
	.string "con POKéMON prestados.\p"
	.string "Primero, debes elegir los tres POKéMON\n"
	.string "con los que vas a comenzar el torneo.\p"
	.string "Con esos POKéMON prestados, debes\n"
	.string "luchar en el primer COMBATE DOBLE.\p"
	.string "Si ganas a tu rival, tendrás derecho a\n"
	.string "un trueque: podrás elegir uno de sus\l"
	.string "POKéMON y cambiárselo por uno tuyo.\p"
	.string "Repite este ciclo de combate y trueque\n"
	.string "y, si logras ganar siete veces seguidas,\l"
	.string "conseguirás PUNTOS de BATALLA.\p"
	.string "Si quieres interrumpir el desafío,\n"
	.string "no olvides guardar antes la partida.\p"
	.string "Si no la guardas, se te descalificará.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead_hns:
	.string "¡Enhorabuena por tu victoria sobre\n"
	.string "el JEFE de la FÁBRICA\l"
	.string "y por tus siete triunfos consecutivos!$"

BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints_hns:
	.string "Tu enorme saber y la agudeza\n"
	.string "de tu mente merecen ser reconocidos\l"
	.string "con PUNTOS de BATALLA.$"

BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave_hns:
	.string "Voy a cambiar tus POKéMON por\n"
	.string "los POKéMON que te prestamos.\p"
	.string "Y de paso guardaré los resultados.\n"
	.string "Un momento, por favor.$"

BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch_hns:
	.string "¿Quieres que tu último combate\n"
	.string "en la FÁBRICA BATALLA sea grabado\l"
	.string "en tu PASE del FRENTE?$"

BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves_hns:
	.string "¡Hola! \n"
	.string "¿Qué tal?\p"
	.string "Seguro que crees que aquí los combates\n"
	.string "están chupados porque no se necesita\l"
	.string "un equipo experto de POKéMON, ¿verdad?\p"
	.string "Pues yo no estaría tan segura.\p"
	.string "Si no tienes suficientes conocimientos\n"
	.string "sobre los POKéMON y sus movimientos,\l"
	.string "te va a ser difícil ganar.$"

BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon_hns:
	.string "Cambié un POKéMON malo por otro peor.\n"
	.string "¡Creí que era justo el que necesitaba!\p"
	.string "Me han dado una buena tunda…$"

BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons_hns:
	.string "Las cosas no me han ido muy bien,\n"
	.string "que digamos.\p"
	.string "Es importante ver cómo se portan\n"
	.string "los POKéMON de tu rival en combate\l"
	.string "para saber si merecen la pena o no.$"

BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints_hns:
	.string "¿Sabías que los guías que trabajan\n"
	.string "aquí te dan pistas sobre los rivales?\p"
	.string "Pues yo no sé si es cosa mía,\n"
	.string "pero no pillo ni una, oye…$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried_hns:
	.string "Yo soy muy fuerte, pero me aburro\n"
	.string "enseguida, así que no paraba de\l"
	.string "cambiar y luchar una y otra vez.\p"
	.string "Bueno, el caso es que, de tanto\n"
	.string "participar en el Intercambio de\l"
	.string "Combate, me di cuenta de que los\l"
	.string "POKéMON de alquiler iban cambiando.$"

BattleFrontier_BattleFactoryLobby_Text_RulesAreListed_hns:
	.string "Son las reglas del COMBATE con TRUEQUE.$"

BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading_hns:
	.string "¿Qué capítulo quieres leer?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules_hns:
	.string "En los enfrentamientos de COMBATE\n"
	.string "con TRUEQUE, sólo se usan tres POKéMON.\p"
	.string "Al tomar prestados o trocar POKéMON,\n"
	.string "hay que tener en cuenta que el equipo\l"
	.string "no debe tener dos POKéMON iguales.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules_hns:
	.string "Sólo puedes cambiarle un POKéMON\n"
	.string "al ENTRENADOR al que acabas de vencer.\p"
	.string "Y sólo puedes elegir entre los POKéMON\n"
	.string "que haya usado ese ENTRENADOR.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules_hns:
	.string "Después de cada victoria, podrás\n"
	.string "cambiar uno de tus POKéMON por\l"
	.string "uno de los del ENTRENADOR derrotado.\p"
	.string "Con el séptimo ENTRENADOR\n"
	.string "no podrás hacer trueque de POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules_hns:
	.string "A la hora de trocar POKéMON, debes\n"
	.string "tener en cuenta dos cosas.\p"
	.string "Primera: en el momento del trueque,\n"
	.string "no podrás ver las características\l"
	.string "del POKéMON que vas a recibir.\p"
	.string "Segunda: los POKéMON de tu equipo\n"
	.string "se mostrarán siguiendo el orden\l"
	.string "en el que los elegiste.\p"
	.string "Ese orden no se altera aunque\n"
	.string "luego realices trueques.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules_hns:
	.string "En el nivel libre, tanto los POKéMON\n"
	.string "que recibes prestados como los POKéMON\l"
	.string "del rival son todos del nivel 100.$"
