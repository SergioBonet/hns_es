BattleFrontier_BattleDomeLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeLobby_OnResume_hns
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp_hns
	.byte 0

BattleFrontier_BattleDomeLobby_OnResume_hns:
	dome_initresultstree
	end

BattleFrontier_BattleDomeLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleDomeLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleDomeLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleDomeLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving_hns::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting_hns, MSGBOX_DEFAULT
	closemessage
	dome_set DOME_DATA_WIN_STREAK, 0
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_WonChallenge_hns::
	call BattleFrontier_EventScript_IncrementWinStreak
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce_hns
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker_hns, MSGBOX_DEFAULT
BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved_hns
	waitmessage
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	frontier_checkairshow
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	dome_set DOME_DATA_HAS_WON_CHALLENGE, TRUE
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, TRUE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	goto BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle_hns

BattleFrontier_BattleDomeLobby_EventScript_LostChallenge_hns::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying_hns, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved_hns
	waitmessage
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	frontier_checkairshow
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle_hns::
	dome_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge_hns
	message BattleFrontier_BattleDomeLobby_Text_RecordLastMatch_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge_hns
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RecordBattle_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_RecordBattle_hns::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleDomeLobby_EventScript_EndChallenge_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge_hns::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou_hns, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge_hns2_hns
	waitmessage
	dome_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome_hns::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles_hns
BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattleDomeLobby_Text_WhichLevelMode_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleDomeLobby_Text_SelectThreeMons_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge_hns
	msgbox BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge_hns
	case YES, BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	dome_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
	dome_inittrainers
BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge_hns::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	dome_settrainers
	msgbox BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome_hns, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor_hns
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_CORRIDOR_HNS, 23, 6
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge_hns
	goto BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hns::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hnsLv50_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge_hns::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain_hns, MSGBOX_DEFAULT
BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge_hns::
	release
	end

BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant_hnsWalkToDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant_hnsWalkToDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor_hns
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor_hns
	waitdooranim
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant_hnsEnterDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant_hnsEnterDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor_hns
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor_hns
	waitdooranim
	return

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant_hnsWalkToDoor_hns::
	applymovement LOCALID_DOME_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant_hnsWalkToDoor_hns::
	applymovement LOCALID_DOME_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant_hnsEnterDoor_hns::
	applymovement LOCALID_DOME_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant_hnsEnterDoor_hns::
	applymovement LOCALID_DOME_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge_hns::
	message BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge_hns::
	message BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor_hns::
	opendoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor_hns::
	opendoor 17, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor_hns::
	closedoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor_hns::
	closedoor 17, 4
	return

BattleFrontier_BattleDomeLobby_Movement_WalkToDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor_hns:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_EventScript_ShowSinglesResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ShowDoublesResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ShowPrevTourneyTree_hns::
	dome_get DOME_DATA_PREV_TOURNEY_TYPE
	call_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50_hns
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50_hns
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen_hns
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen_hns
	fadescreen FADE_TO_BLACK
	dome_showprevtourneytree
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50_hns, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50_hns, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen_hns, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen_hns, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_Man_hnsiac_hns::
	dome_getwinnersname
	msgbox BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough_hns, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_Lass_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation_hns, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_FatMan_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound_hns, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_Man_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully_hns, MSGBOX_NPC
	end

@ A few OutsideWest event scripts are inserted here instead, two of which are unused
BattleFrontier_OutsideWest_EventScript_Man3_hns::
	msgbox BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_BattleDomeSign2_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign2_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnderConstructionSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction_hns, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 17, 4, MULTI_BATTLE_DOME_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup_hns
	case 1, BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree_hns
	case 2, BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO_hns
	case 3, BattleFrontier_BattleDomeLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle_hns:
	.string "¡Aquí ponemos a prueba la táctica\n"
	.string "de los ENTRENADORES!\p"
	.string "¡Te doy la más calurosa bienvenida\n"
	.string "a la CÚPULA BATALLA!\p"
	.string "Yo soy la guía del TORNEO \n"
	.string "de COMBATES INDIVIDUALES.$"

BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge_hns:
	.string "¿Deseas enfrentarte al desafío de\n"
	.string "un TORNEO de COMBATES INDIVIDUALES?$"

BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain_hns:
	.string "Siempre a su servicio.$"

BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge_hns:
	.string "El TORNEO de COMBATES INDIVIDUALES\n"
	.string "es exactamente lo que indica su nombre:\l"
	.string "un torneo de COMBATES INDIVIDUALES.\p"
	.string "Todos los ENTRENADORES participan\n"
	.string "con tres POKéMON cada uno.\p"
	.string "En cada enfrentamiento, uno de los tres\n"
	.string "POKéMON queda de reserva.\p"
	.string "Los otros dos POKéMON lucharán\n"
	.string "uno después del otro.\p"
	.string "Elige los dos POKéMON que combatirán\n"
	.string "después de examinar el trío del rival.\p"
	.string "Ganarás el torneo si logras derrotar\n"
	.string "a cuatro ENTRENADORES.\p"
	.string "Quien gane el torneo, obtendrá\n"
	.string "PUNTOS de BATALLA.\p"
	.string "Si quieres interrumpir el desafío,\n"
	.string "no olvides guardar antes la partida.\p"
	.string "Si no la guardas, se te descalificará.$"

BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge_hns:
	.string "Antes de llevarte a la CÚPULA BATALLA,\n"
	.string "debo guardar tu partida. ¿De acuerdo?$"

BattleFrontier_BattleDomeLobby_Text_WhichLevelMode_hns:
	.string "El torneo se disputa en dos niveles:\n"
	.string "el nivel 50 y el nivel libre. ¿Cuál eliges?$"

BattleFrontier_BattleDomeLobby_Text_SelectThreeMons_hns:
	.string "Selecciona los tres POKéMON\n"
	.string "con los que quieres combatir.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen_hns:
	.string "¡Disculpa!\p"
	.string "No tienes tres POKéMON que cumplan\n"
	.string "los requisitos.\p"
	.string "Además, los POKéMON deben llevar\n"
	.string "objetos distintos.\p"
	.string "Los HUEVOS{STR_VAR_1}.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsEnd_hns:
	.string "Vuelve cuando tengas todo lo\n"
	.string "necesario.\p"
	.string "$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50_hns:
	.string "¡Disculpa!\p"
	.string "No tienes tres POKéMON que cumplan\n"
	.string "los requisitos.\p"
	.string "Para participar, debes tener tres\n"
	.string "POKéMON distintos de nivel 50 o\l"
	.string "inferior.\p"
	.string "Además, deben llevar objetos\n"
	.string "distintos.\p"
	.string "Los HUEVOS{STR_VAR_1}.$"

BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome_hns:
	.string "Venga, pasemos a la CÚPULA BATALLA.$"

BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting_hns:
	.string "Huy, qué pena…\p"
	.string "Se te olvidó guardar la partida antes\n"
	.string "de abandonar el desafío…\p"
	.string "Eso quiere decir que, ejem, se te ha\n"
	.string "descalificado por el momento…$"

BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney_hns:
	.string "¡Enhorabuena por conquistar\n"
	.string "un torneo tan difícil!$"

@ Unused
BattleFrontier_BattleDomeLobby_Text_HereIsYourPrize_hns:
	.string "Aquí tienes tu premio por ganar el\n"
	.string "Torneo de Combate.$"

@ Used by Verdanturf Tent
BattleFrontier_BattleDomeLobby_Text_ReceivedPrize_hns:
	.string "{PLAYER} recibió el premio\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleDomeLobby_Text_BagFullMakeRoom_hns:
	.string "Vaya, parece que tienes la MOCHILA\n"
	.string "llena.\p"
	.string "Haz sitio en la MOCHILA y vuelve a\n"
	.string "verme.$"

BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying_hns:
	.string "¡Gracias por participar!\p"
	.string "$"

BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved_hns:
	.string "Se va a guardar tu récord. Espera…$"

BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou_hns:
	.string "¡Te estábamos esperando!$"

BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge_hns2_hns:
	.string "Antes de llevarte a la CÚPULA BATALLA,\n"
	.string "debo guardar tu partida. ¿De acuerdo?$"

BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle_hns:
	.string "¡Aquí ponemos a prueba la táctica\n"
	.string "de los ENTRENADORES!\p"
	.string "¡Te doy la más calurosa bienvenida\n"
	.string "a la CÚPULA BATALLA!\p"
	.string "Yo soy la guía del TORNEO \n"
	.string "de COMBATES DOBLES.$"

BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge_hns:
	.string "¿Deseas enfrentarte al desafío de\n"
	.string "un TORNEO de COMBATES DOBLES?$"

BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge_hns:
	.string "El TORNEO de COMBATES DOBLES\n"
	.string "es exactamente lo que indica su nombre:\l"
	.string "un torneo de COMBATES DOBLES.\p"
	.string "Todos los ENTRENADORES participan\n"
	.string "con tres POKéMON cada uno.\p"
	.string "En cada enfrentamiento, uno de los tres\n"
	.string "POKéMON queda de reserva.\p"
	.string "Los otros dos POKéMON se enfrentarán\n"
	.string "en un COMBATE DOBLE.\p"
	.string "Elige los dos POKéMON que combatirán\n"
	.string "después de examinar el trío del rival.\p"
	.string "Ganarás el torneo si logras derrotar\n"
	.string "a cuatro ENTRENADORES.\p"
	.string "Quien gane el torneo, obtendrá\n"
	.string "PUNTOS de BATALLA.\p"
	.string "Si quieres interrumpir el desafío,\n"
	.string "no olvides guardar antes la partida.\p"
	.string "Si no la guardas, se te descalificará.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50_hns:
	.string "Son los resultados del último TORNEO\n"
	.string "de COMBATES INDIVIDUALES de nivel 50.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50_hns:
	.string "Son los resultados del último TORNEO\n"
	.string "de COMBATES DOBLES de nivel 50.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen_hns:
	.string "Son los resultados del último TORNEO de\n"
	.string "COMBATES INDIVIDUALES de nivel libre.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen_hns:
	.string "Son los resultados del último TORNEO de\n"
	.string "COMBATES DOBLES de nivel libre.$"

BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough_hns:
	.string "¿Lo has visto? ¿Has visto el último\n"
	.string "TORNEO de COMBATES?\p"
	.string "{STR_VAR_1} ganó y demostró que hoy\n"
	.string "por hoy no tiene rival.\p"
	.string "Echa un vistazo a los resultados, están\n"
	.string "en el monitor que hay al lado del PC.$"

BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier_hns:
	.string "El FRENTE de BATALLA…\n"
	.string "¡Cuánto he soñado con este lugar!$"

@ Functionally unused
BattleFrontier_OutsideWest_Text_BattleDomeSign2_hns:
	.string "CÚPULA BATALLA\n"
	.string "¡Conviértete en el rival a batir!$"

@ Functionally unused
BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction_hns:
	.string "(?)\n"
	.string "¡En construcción!$"

BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation_hns:
	.string "Cuando un ENTRENADOR logra varias\n"
	.string "victorias seguidas en los torneos\l"
	.string "de la CÚPULA BATALLA, pronto se corre\l"
	.string "la voz y se convierte en una estrella.\p"
	.string "La reputación de la CÚPULA BATALLA\n"
	.string "atrae a los mejores ENTRENADORES.\p"
	.string "Las auténticas superestrellas son las\n"
	.string "que consiguen seguir ganando torneos.$"

BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound_hns:
	.string "Me tocó enfrentarme a uno de los\n"
	.string "favoritos justo en la primera ronda.\p"
	.string "Ni que decir tiene que me machacó…$"

BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully_hns:
	.string "Habría ganado si hubiese dejado\n"
	.string "este POKéMON de reserva.\p"
	.string "Conviene estudiar cuidadosamente\n"
	.string "los POKéMON del rival antes de elegir\l"
	.string "los que vas a sacar tú.$"

BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker_hns:
	.string "¡Enhorabuena!\p"
	.string "¡Has derrotado al ASTRO de la CÚPULA y \n"
	.string "has ganado el TORNEO de COMBATES!$"

BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints_hns:
	.string "Déjanos premiar tu estrategia,\n"
	.string "todo un prodigio de ingenio táctico,\l"
	.string "con PUNTOS de BATALLA.$"

BattleFrontier_BattleDomeLobby_Text_RecordLastMatch_hns:
	.string "¿Quieres que tu último combate\n"
	.string "en la CÚPULA BATALLA sea grabado\l"
	.string "en tu PASE del FRENTE?$"

BattleFrontier_BattleDomeLobby_Text_RulesAreListed_hns:
	.string "Son las reglas del TORNEO de COMBATES.$"

BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading_hns:
	.string "¿Qué capítulo quieres leer?$"

BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules_hns:
	.string "Los emparejamientos se realizan\n"
	.string "teniendo en cuenta la dureza de los\l"
	.string "POKéMON de cada ENTRENADOR.\p"
	.string "Así se evita que los ENTRENADORES\n"
	.string "más fuertes se enfrenten\l"
	.string "en las primeras rondas.$"

BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree_hns:
	.string "El cuadro de enfrentamientos, que aquí\n"
	.string "llamamos TABLA, puede consultarse en\l"
	.string "la sala de espera preguntando a la guía.\p"
	.string "La tabla del torneo ofrece una serie\n"
	.string "de datos que pueden ser muy útiles.\p"
	.string "Entre ellos: los resultados de todos los\n"
	.string "combates disputados, los POKéMON que\l"
	.string "posee cada ENTRENADOR y los estilos\l"
	.string "de combate de cada ENTRENADOR.$"

BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules_hns:
	.string "En caso de que todos los POKéMON\n"
	.string "de un combate se debiliten a la vez,\l"
	.string "es decir, que haya K.O. doble,\l"
	.string "los JUECES decidirán el vencedor.$"
