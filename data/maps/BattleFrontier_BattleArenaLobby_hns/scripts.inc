BattleFrontier_BattleArenaLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp_hns
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving_hns::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown_hns, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge_hns::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon_hns
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon_hns, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement_hns
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge_hns
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns2_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge_hns::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave_hns
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge_hns
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns2_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge_hns::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge_hns
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge_hns
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch_hns::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge_hns::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge_hns::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame_hns
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_Attendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena_hns, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge_hns::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge_hns
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge_hns
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge_hns::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena_hns, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50_hns
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen_hns
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR_HNS, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hns::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hnsLv50_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge_hns::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge_hns::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50_hns::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor_hns
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor_hns
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor_hns:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen_hns::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor_hns
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor_hns
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack_hns, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked_hns, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw_hns, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant_hns, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules_hns
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules_hns
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules_hns
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules_hns
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena_hns:
	.string "¡Aquí ponemos a prueba el coraje\n"
	.string "de los ENTRENADORES!\p"
	.string "¡Te doy la bienvenida al DOJO BATALLA!\p"
	.string "¡Soy el guía del TORNEO con JUEZ!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge_hns:
	.string "¿Aceptas el desafío del DOJO BATALLA?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns:
	.string "Esperamos que vuelvas\n"
	.string "pronto por aquí.$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge_hns:
	.string "En el DOJO BATALLA, se disputan\n"
	.string "TORNEOS con JUEZ.\p"
	.string "Cada ENTRENADOR participa\n"
	.string "con un equipo de tres POKéMON.\p"
	.string "Primero, debes elegir los tres POKéMON\n"
	.string "en el orden en que deseas que combatan.\p"
	.string "Durante el combate, los POKéMON\n"
	.string "aparecerán uno a uno en ese orden.\p"
	.string "Una vez entre un POKéMON en combate,\n"
	.string "deberá seguir hasta que concluya.\p"
	.string "Pero si no hay ganador al cabo\n"
	.string "de tres rondas, el juez decidirá.\p"
	.string "Si quieres interrumpir el torneo,\n"
	.string "no olvides guardar antes la partida.\p"
	.string "Si no la guardas, se te descalificará.\p"
	.string "Si logras vencer a siete ENTRENADORES\n"
	.string "seguidos, ganarás PUNTOS de BATALLA.$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave_hns:
	.string "Antes de entrar en el DOJO BATALLA,\n"
	.string "debes guardar la partida. ¿De acuerdo?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode_hns:
	.string "En DOJO BATALLA hay dos categorías:\n"
	.string "nivel 50 y nivel libre. ¿Cuál prefieres?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons_hns:
	.string "Selecciona los tres POKéMON\n"
	.string "con los que quieres combatir.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen_hns:
	.string "¡Estimado aspirante!\p"
	.string "No tienes los tres POKéMON necesarios\n"
	.string "para participar.\p"
	.string "Para poder participar, debes traer\n"
	.string "tres POKéMON distintos.\p"
	.string "Además, no pueden llevar objetos\n"
	.string "iguales.\p"
	.string "Los HUEVOS{STR_VAR_1}.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd_hns:
	.string "Cuando estés preparado, vuelve, por\n"
	.string "favor.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50_hns:
	.string "¡Estimado aspirante!\p"
	.string "No tienes los tres POKéMON necesarios\n"
	.string "para participar.\p"
	.string "Para poder participar, debes traer\n"
	.string "tres POKéMON distintos.\p"
	.string "Los tres POKéMON deben ser de nivel\n"
	.string "50 o inferior.\p"
	.string "Además, no pueden llevar objetos\n"
	.string "iguales.\p"
	.string "Los HUEVOS{STR_VAR_1}.$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena_hns:
	.string "Ahora te guiaré hasta el DOJO BATALLA.$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown_hns:
	.string "Lástima…\p"
	.string "No guardaste la partida antes\n"
	.string "de abandonar el desafío, ¿verdad?…\p"
	.string "Eso implica la descalificación…\p"
	.string "No obstante, puedes volver\n"
	.string "a participar cuando quieras.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins_hns:
	.string "¡Enhorabuena por tu extraordinaria\n"
	.string "serie de siete victorias consecutivas!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement_hns:
	.string "Vamos a guardar tu récord.\n"
	.string "Espera unos instantes.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize_hns:
	.string "Para conmemorar tu racha de 7\n"
	.string "victorias, te entregamos este premio.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize_hns:
	.string "{PLAYER} recibió el premio\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize_hns:
	.string "¡Pero bueno!\n"
	.string "Tienes la MOCHILA repleta.\p"
	.string "Será mejor que la vacíes un poco\n"
	.string "si quieres llevarte el premio.$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave_hns:
	.string "¡Muchas gracias por participar!\p"
	.string "Espera un segundo mientras\n"
	.string "guardo la partida.$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns2_hns:
	.string "Esperamos que vuelvas\n"
	.string "pronto por aquí.$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame_hns:
	.string "Es un placer tenerte de nuevo por aquí.\p"
	.string "Antes de conducirte al DOJO BATALLA,\n"
	.string "debo guardar tu partida. Un segundo.$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch_hns:
	.string "¿Quieres que tu último combate\n"
	.string "en el DOJO BATALLA sea grabado\l"
	.string "en tu PASE del FRENTE?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack_hns:
	.string "He perdido por decisión del JUEZ…\p"
	.string "Creo que hice mal en usar tantos\n"
	.string "movimientos defensivos y no atacar…$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked_hns:
	.string "¡El JUEZ me ha dado la victoria!\p"
	.string "¡Mi táctica de atacar sin cesar\n"
	.string "al POKéMON del rival ha funcionado!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw_hns:
	.string "Hemos empatado.\p"
	.string "Cuando se acabó el tiempo, tanto mi\n"
	.string "POKéMON como el de mi rival tenían\l"
	.string "el mismo número de PS.$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant_hns:
	.string "En el DOJO BATALLA, el orden\n"
	.string "de los POKéMON es algo clave.\p"
	.string "Por ejemplo, si tu primer POKéMON\n"
	.string "tiene ciertas deficiencias, trata de\l"
	.string "compensarlo poniendo de segundo\l"
	.string "POKéMON a uno cuyos movimientos\l"
	.string "sean muy eficaces contra el primero.\p"
	.string "Creo que ésa es la estrategia adecuada\n"
	.string "para formar un buen equipo.$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed_hns:
	.string "Son las reglas del TORNEO con JUEZ.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading_hns:
	.string "¿Qué capítulo quieres leer?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules_hns:
	.string "Las reglas del TORNEO con JUEZ difieren\n"
	.string "de las que rigen los combates normales.\p"
	.string "Primero, los combates\n"
	.string "sólo duran tres turnos.\p"
	.string "Si al cabo de los tres turnos no hay\n"
	.string "un ganador, lo decidirá el JUEZ.\p"
	.string "El JUEZ elegirá al ganador basándose\n"
	.string "en cómo han luchado los POKéMON.\p"
	.string "Además, no podrá cambiarse de POKéMON\n"
	.string "hasta que el combate esté decidido.$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules_hns:
	.string "El primer factor que se juzga\n"
	.string "es la MENTE.\p"
	.string "Con este factor, el JUEZ evalúa\n"
	.string "la capacidad agresiva de los rivales.\p"
	.string "Para ello, el JUEZ se basa en el número\n"
	.string "de veces que los ENTRENADORES\l"
	.string "han ordenado movimientos ofensivos.$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules_hns:
	.string "El segundo factor que se juzga\n"
	.string "es la HABILIDAD.\p"
	.string "Se trata de evaluar la eficacia de los\n"
	.string "movimientos usados por los POKéMON.\p"
	.string "Si un movimiento funcionó,\n"
	.string "sube la nota en habilidad.\p"
	.string "Si un movimiento no funcionó,\n"
	.string "baja la nota en habilidad.\p"
	.string "En movimientos ofensivos, la nota sube\n"
	.string "si resulta “muy eficaz” y baja cuando\l"
	.string "“no es muy eficaz”.\p"
	.string "La nota en habilidad no sube cuando\n"
	.string "se usan movimientos como PROTECCIÓN\l"
	.string "y DETECCIÓN.\p"
	.string "Si el rival usa PROTECCIÓN o DETECCIÓN\n"
	.string "y el movimiento de tu POKéMON falla,\l"
	.string "la nota en habilidad no baja.$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules_hns:
	.string "El tercer factor que se juzga\n"
	.string "es el CUERPO.\p"
	.string "La nota se basa en el número de PS\n"
	.string "que se conservan al final del combate.\p"
	.string "La nota tiene también en cuenta\n"
	.string "cuántos PS tenía cada POKéMON\l"
	.string "al comienzo del combate.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon_hns:
	.string "¡7 victorias sobre 7 ENTRENADORES\n"
	.string "venciendo a la MAESTRA del DOJO!\p"
	.string "¡Debemos felicitarte todos\n"
	.string "por semejante proeza!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints_hns:
	.string "En reconocimiento a ese infatigable\n"
	.string "espíritu tuyo, por favor, acepta un\l"
	.string "modesto premio en PUNTOS de BATALLA.$"
