BattleFrontier_BattlePalaceLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp_hns
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving_hns::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge_hns, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge_hns::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven_hns
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded_hns
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge_hns
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge_hns::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded_hns
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge_hns
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge_hns::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge_hns
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge_hns
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch_hns::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge_hns::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge_hns::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting_hns, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge_hns
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant_hns::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge_hns
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle_hns
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge_hns
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge_hns2_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge_hns
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge_hns::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe_hns, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor_hns
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR_HNS, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge_hns::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge_hns
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hns::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hnsLv50_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge_hns::
	special LoadPlayerParty
	callnative LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge_hns::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge_hns::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge_hns
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge_hns::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge_hns
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant_hns
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor_hns
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor_hns
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor_hns
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor_hns
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant_hns::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant_hns::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor_hns::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor_hns::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor_hns::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor_hns::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor_hns:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor_hns:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics_hns
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature_hns
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves_hns
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered_hns
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger_hns
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle_hns:
	.string "¡Aquí ponemos a prueba el ánimo\n"
	.string "y el arrojo de los ENTRENADORES!\p"
	.string "¡Te doy la bienvenida\n"
	.string "al PALACIO BATALLA!\p"
	.string "Yo soy el guía del COMBATE\n"
	.string "sin TUTELA INDIVIDUAL.$"

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge_hns:
	.string "¿Aceptas el desafío del COMBATE\n"
	.string "sin TUTELA INDIVIDUAL?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge_hns:
	.string "En el PALACIO BATALLA, hay varias\n"
	.string "salas donde se celebran COMBATES\l"
	.string "sin TUTELA INDIVIDUALES.\p"
	.string "Los COMBATES sin TUTELA sólo se\n"
	.string "distinguen de los normales\l"
	.string "por una regla de obligado cumplimiento:\p"
	.string "Los ENTRENADORES sólo pueden\n"
	.string "cambiar de POKéMON.\p"
	.string "Es decir, los ENTRENADORES no pueden\n"
	.string "dar órdenes a sus POKéMON.\p"
	.string "De este modo, se deja que los POKéMON\n"
	.string "combatan solos, según su naturaleza.\p"
	.string "Debes confiar en tus POKéMON\n"
	.string "y vigilar para que nada les pase.\p"
	.string "Si logras derrotar consecutivamente\n"
	.string "a siete ENTRENADORES, obtendrás\l"
	.string "PUNTOS de BATALLA.\p"
	.string "Si quieres interrumpir el desafío,\n"
	.string "no olvides guardar antes la partida.\p"
	.string "Si no la guardas, se te descalificará.$"

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified_hns:
	.string "Vuelve cuando tu corazón y el de tus\n"
	.string "POKéMON latan como uno solo.$"

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge_hns:
	.string "Hay dos niveles de COMBATE sin TUTELA:\n"
	.string "el nivel 50 y el nivel libre. ¿Cuál eliges?$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50_hns:
	.string "Ay…\p"
	.string "No tienes los tres POKéMON necesarios\n"
	.string "para el desafío.\p"
	.string "Para participar, debes traer tres\n"
	.string "POKéMON distintos.\p"
	.string "Todos ellos deben ser de nivel 50 o\n"
	.string "inferior.\p"
	.string "Además, no pueden llevar objetos\n"
	.string "iguales.\p"
	.string "Los HUEVOS{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd_hns:
	.string "Vuelve cuando estés preparado.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen_hns:
	.string "Ay…\p"
	.string "No tienes los tres POKéMON necesarios\n"
	.string "para el desafío.\p"
	.string "Para participar, debes traer tres\n"
	.string "POKéMON distintos.\p"
	.string "Además, no pueden llevar objetos\n"
	.string "iguales.\p"
	.string "Los HUEVOS{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons_hns:
	.string "Selecciona los tres POKéMON\n"
	.string "con los que quieres combatir.$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge_hns2_hns:
	.string "Antes de participar en el COMBATE sin\n"
	.string "TUTELA, debes guardar la partida…$"

BattleFrontier_BattlePalaceLobby_Text_FollowMe_hns:
	.string "Bien.\n"
	.string "Ahora, sígueme.$"

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded_hns:
	.string "Me siento privilegiado por poder haber\n"
	.string "visto combatir a tus POKéMON.\p"
	.string "Voy a guardar tu resultado.\n"
	.string "Sólo será un segundo, por favor.$"

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak_hns:
	.string "Has logrado una racha de 7 victorias…\p"
	.string "Sin duda, existe un fuerte vínculo\n"
	.string "entre tus POKéMON y tú.$"

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded_hns:
	.string "Voy a guardar tu récord.\n"
	.string "Espera unos instantes.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak_hns:
	.string "Por la hazaña de tu racha de 7\n"
	.string "victorias, te entregamos estos\l"
	.string "Puntos de Batalla.$"

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize_hns:
	.string "Lástima, parece que no tienes sitio\n"
	.string "para guardar nuestro premio.\p"
	.string "No te olvides de volver cuando\n"
	.string "tengas sitio en la MOCHILA.$"

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting_hns:
	.string "Te estábamos esperando…$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge_hns:
	.string "Antes de participar en el COMBATE sin\n"
	.string "TUTELA, debes guardar la partida…$"

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge_hns:
	.string "Lo lamento…\p"
	.string "No debiste de guardar la partida antes\n"
	.string "de abandonar el desafío…\p"
	.string "Me temo que, por tanto, se te ha\n"
	.string "descalificado…$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize_hns:
	.string "{PLAYER} recibió el premio\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink_hns:
	.string "Para los tipos robustos como yo,\n"
	.string "los POKéMON robustos son los mejores.\p"
	.string "¡La mejor defensa es un buen ataque!\n"
	.string "¡Y un ataque incesante es aún mejor!\p"
	.string "Pero yo no quería hablarte de esto.\p"
	.string "De vez en cuando pasa por aquí\n"
	.string "una señorita realmente hermosa.\p"
	.string "Ella dice que puede adivinar lo\n"
	.string "que piensan los POKéMON.\p"
	.string "No sé si será verdad lo que dice,\n"
	.string "pero es que es guapa de verdad.\p"
	.string "¿Eh?\n"
	.string "¿Por qué me miras así?$"

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere_hns:
	.string "Mmm…\p"
	.string "Parece que la clave para ganar\n"
	.string "combates en este sitio está\l"
	.string "en la naturaleza de los POKéMON\l"
	.string "y en los movimientos que han aprendido.\p"
	.string "Concretamente, en lo bien que se\n"
	.string "corresponden los movimientos del\l"
	.string "POKéMON con su naturaleza.\p"
	.string "Si un POKéMON tiene problemas y no\n"
	.string "rinde como se espera de él, a lo mejor\l"
	.string "es que los movimientos que usa no\l"
	.string "tienen nada que ver con su naturaleza.$"

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms_hns:
	.string "Mi POKéMON suele ser muy dócil.\p"
	.string "Pero, oye, cuando participa en un\n"
	.string "COMBATE sin TUTELA, es como si se\l"
	.string "transformara en una bestia salvaje.\p"
	.string "Se vuelve muy agresivo.\n"
	.string "Da miedo verlo.$"

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway_hns:
	.string "Me preguntaba qué clase de naturaleza\n"
	.string "tendrá un POKéMON que hace más y más\l"
	.string "débiles a sus rivales hasta agotarlos.\p"
	.string "Me sorprendería que fuese\n"
	.string "de naturaleza FLOJA.\p"
	.string "Pero, bah, no puede ser.$"

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle_hns:
	.string "¡Aquí ponemos a prueba el ánimo\n"
	.string "y el arrojo de los ENTRENADORES!\p"
	.string "¡Te doy la bienvenida\n"
	.string "al PALACIO BATALLA!\p"
	.string "Yo soy el guía del COMBATE\n"
	.string "sin TUTELA DOBLE.$"

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge_hns:
	.string "¿Aceptas el desafío del COMBATE\n"
	.string "sin TUTELA DOBLE?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge_hns:
	.string "En el PALACIO BATALLA, hay varias\n"
	.string "salas donde se celebran COMBATES\l"
	.string "sin TUTELA DOBLES.\p"
	.string "Los COMBATES sin TUTELA sólo se\n"
	.string "distinguen de los normales\l"
	.string "por una regla de obligado cumplimiento:\p"
	.string "Los ENTRENADORES sólo pueden\n"
	.string "cambiar de POKéMON.\p"
	.string "Es decir, los ENTRENADORES no pueden\n"
	.string "dar órdenes a sus POKéMON.\p"
	.string "De este modo, se deja que los POKéMON\n"
	.string "combatan solos, según su naturaleza.\p"
	.string "Debes confiar en tus POKéMON\n"
	.string "y vigilar para que nada les pase.\p"
	.string "Si logras derrotar consecutivamente\n"
	.string "a siete ENTRENADORES, obtendrás\l"
	.string "PUNTOS de BATALLA.\p"
	.string "Si quieres interrumpir el desafío,\n"
	.string "no olvides guardar antes la partida.\p"
	.string "Si no la guardas, se te descalificará.$"

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers_hns:
	.string "Derrotado el AMO del PALACIO y, con él,\n"
	.string "siete ENTRENADORES consecutivos…$"

BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints_hns:
	.string "Debemos hacer honor al vínculo\n"
	.string "que has forjado entre tú y tus POKéMON,\l"
	.string "y premiarlo con PUNTOS de BATALLA.$"

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch_hns:
	.string "¿Quieres grabar tu último\n"
	.string "enfrentamiento del PALACIO BATALLA\l"
	.string "en tu PASE del FRENTE?$"

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed_hns:
	.string "Son las reglas del COMBATE sin TUTELA.$"

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading_hns:
	.string "¿Qué capítulo quieres leer?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics_hns:
	.string "Aquí, los POKéMON deberán pensar\n"
	.string "y combatir por sí mismos.\p"
	.string "A diferencia de los POKéMON salvajes,\n"
	.string "los que viven con gente se comportan\l"
	.string "de manera distinta según su naturaleza.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature_hns:
	.string "Según su naturaleza, un POKéMON puede\n"
	.string "atacar sin medir las consecuencias.\p"
	.string "Mientras que otro preferirá protegerse\n"
	.string "en lugar de atacar.\p"
	.string "Y otro puede que prefiera irritar\n"
	.string "o confundir a sus oponentes.\p"
	.string "Según su naturaleza, cada POKéMON\n"
	.string "tendrá unos movimientos preferidos,\l"
	.string "que sabrá usar muy bien.\p"
	.string "Igualmente, puede que deteste ciertos\n"
	.string "movimientos que le resultan difíciles.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves_hns:
	.string "Existen movimientos ofensivos que\n"
	.string "infligen un daño directo al enemigo.\p"
	.string "Hay movimientos defensivos que sirven\n"
	.string "para prepararse ante ataques enemigos,\l"
	.string "curar PS, etc.\p"
	.string "Existen también otros movimientos\n"
	.string "que pueden alterar el estado del rival\l"
	.string "con envenenamiento, parálisis, etc.\p"
	.string "Los POKéMON usarán movimientos\n"
	.string "de una de estas tres categorías.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered_hns:
	.string "Cuando no está bajo el control de su\n"
	.string "ENTRENADOR, un POKéMON puede ser\l"
	.string "incapaz de usar ciertos movimientos.\p"
	.string "A los POKéMON no les gusta usar\n"
	.string "movimientos impropios de su naturaleza.\p"
	.string "Si un POKéMON sólo conoce movimientos\n"
	.string "ajenos a su naturaleza, es probable que\l"
	.string "nunca llegue a demostrar su valía.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger_hns:
	.string "Cuando un POKéMON está en peligro,\n"
	.string "es posible que decida usar movimientos\l"
	.string "que sean ajenos a su naturaleza.\p"
	.string "Si un POKéMON comienza a comportarse\n"
	.string "de modo extraño en un momento de apuro,\l"
	.string "no lo pierdas de vista.$"

