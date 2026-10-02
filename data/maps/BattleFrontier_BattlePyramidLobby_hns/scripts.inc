BattleFrontier_BattlePyramidLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth_hns:
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving_hns::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag_hns
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge_hns::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing_hns
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints_hns::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag_hns
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept_hns
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait_hns
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge_hns::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag_hns
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait_hns
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge_hns::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_Attendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge_hns::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge_hns
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge_hns
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge_hns::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid_hns, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag_hns
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR_HNS, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hns::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hnsLv50_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge_hns::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge_hns::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver_hns::
	lockall
	applymovement LOCALID_PYRAMID_LOBBY_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait_hns, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hns
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot_hns, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hns::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsLvOpen_hns
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint_hns
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint_hns::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsLv50_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah_hns, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsGetLv50Streak_hns
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsGetLv50Streak_hns::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsLvOpen_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah_hns, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsGetLvOpenStreak_hns
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint_hnsGetLvOpenStreak_hns::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment_hns::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis_hns
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison_hns
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn_hns
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste_hns
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate_hns
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility_hns
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce_hns
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion_hns
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic_hns
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock_hns
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting_hns
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather_hns
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug_hns
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark_hns
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater_hns
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost_hns
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel_hns
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon_hns
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve_hns
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag_hns::
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel_hns
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping_hns, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag_hns
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag_hns

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag_hns::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag_hns
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside_hns
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel_hns
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside_hns:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel_hns:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake_hns, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag_hns
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep_hns
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag_hns, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep_hns::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag_hns
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty_hns
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag_hns::
	special ChooseItemsToTossFromPyramidBag
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep_hns
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty_hns::
	special BattlePyramidChooseMonHeldItems
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep_hns
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems_hns::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems_hns
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem_hns, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep_hns
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon_hns
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers_hns
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze_hns
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag_hns
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag_hns::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid_hns:
	.string "¡Aquí ponemos a prueba la valentía\n"
	.string "de los ENTRENADORES!\p"
	.string "¡Te doy la bienvenida\n"
	.string "a la PIRÁMIDE BATALLA!\p"
	.string "Yo soy el guía de las\n"
	.string "EXPEDICIONES de COMBATES.$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge_hns:
	.string "¿Tienes valor para embarcarte\n"
	.string "en una EXPEDICIÓN de COMBATES?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge_hns:
	.string "Esperamos que vuelvas\n"
	.string "pronto por aquí.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid_hns:
	.string "La EXPEDICIÓN de COMBATES es una\n"
	.string "prueba en la que deberás explorar esta\l"
	.string "pirámide y tratar de llegar a la cima.\p"
	.string "En esta pirámide hay siete laberintos,\n"
	.string "uno en cada nivel, por los que merodean\l"
	.string "ENTRENADORES y POKéMON salvajes.\p"
	.string "Sólo podrás entrar con tres POKéMON,\n"
	.string "y ninguno de ellos podrá sostener\l"
	.string "ningún objeto.\p"
	.string "Antes de iniciar el ascenso, recibirás\n"
	.string "una MOCHILA PIRÁMIDE para guardar\l"
	.string "objetos.\p"
	.string "Si tu expedición fracasa, perderás\n"
	.string "los objetos que había en tu MOCHILA\l"
	.string "PIRÁMIDE.\p"
	.string "Si quieres tomarte un respiro y dejar\n"
	.string "de jugar, selecciona “DESCANSO”:\l"
	.string "guardarás la partida\l"
	.string "y saldrás del juego.\p"
	.string "Si salieras del juego sin guardar,\n"
	.string "cuando retomes la partida\l"
	.string "se te habrá descalificado.$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode_hns:
	.string "La PIRÁMIDE BATALLA tiene dos niveles:\n"
	.string "el nivel 50 y el nivel libre.\l"
	.string "¿En cuál quieres combatir?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons_hns:
	.string "Selecciona los tres POKéMON\n"
	.string "con los que quieres combatir.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen_hns:
	.string "¡Un pequeño problema, aventurero!\p"
	.string "Parece que no tienes los tres POKéMON\n"
	.string "que cumplen los requisitos del\l"
	.string "desafío.\p"
	.string "Recuerda también quitarles todos los\n"
	.string "objetos a tus POKéMON.\p"
	.string "Los HUEVOS{STR_VAR_1}.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50_hns:
	.string "¡Un pequeño problema, aventurero!\p"
	.string "Parece que no tienes los tres POKéMON\n"
	.string "que cumplen los requisitos del\l"
	.string "desafío.\p"
	.string "Los tres POKéMON deben ser distintos\n"
	.string "y no superar el nivel 50.\p"
	.string "Recuerda también quitarles todos los\n"
	.string "objetos a tus POKéMON.\p"
	.string "Los HUEVOS{STR_VAR_1}.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd_hns:
	.string "Cuando estés listo, ven a hablar\n"
	.string "conmigo.$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge_hns:
	.string "Antes de embarcarte en una EXPEDICIÓN\n"
	.string "de COMBATES, debes guardar la partida.\l"
	.string "¿Estás de acuerdo?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid_hns:
	.string "Adelante, pues. Permíteme conducirte\n"
	.string "al interior de la PIRÁMIDE BATALLA.$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping_hns:
	.string "{PLAYER}, permíteme tu MOCHILA,\n"
	.string "por favor. La pondremos a buen recaudo.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag_hns:
	.string "A cambio, toma la MOCHILA PIRÁMIDE,\n"
	.string "que ya has usado antes.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag_hns:
	.string "A cambio, toma esta MOCHILA PIRÁMIDE.$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag_hns:
	.string "{PLAYER} cambió su MOCHILA\n"
	.string "por la MOCHILA PIRÁMIDE.$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel_hns:
	.string "Cuando te pongas en esta baldosa,\n"
	.string "irás a parar a un piso superior\l"
	.string "de la pirámide.\p"
	.string "¡Espero y deseo por tu bien\n"
	.string "que tenga éxito la expedición!$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag_hns:
	.string "Cuánto lo siento…\p"
	.string "Se te olvidó guardar la partida antes\n"
	.string "de abandonar la expedición…\p"
	.string "Me temo que ello implica la\n"
	.string "descalificación automática.\p"
	.string "Toma tu MOCHILA. Suerte para el futuro.\p"
	.string "{PLAYER} recuperó su MOCHILA.$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid_hns:
	.string "¡Qué alegría verte de vuelta!\p"
	.string "¡Has coronado la PIRÁMIDE BATALLA!\n"
	.string "¡Excelente!$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake_hns:
	.string "Esto…, parece que hay un problema.\p"
	.string "Al menos uno de tus POKéMON\n"
	.string "está sosteniendo un objeto.\p"
	.string "Lo siento, pero los objetos obtenidos\n"
	.string "en esta pirámide, en ella se quedan.$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag_hns:
	.string "Los objetos que lleven tus POKéMON\n"
	.string "se colocarán automáticamente\l"
	.string "en la MOCHILA PIRÁMIDE, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep_hns:
	.string "La MOCHILA PIRÁMIDE no puede guardar\n"
	.string "todos los objetos que llevas, lo siento.\p"
	.string "Elige los objetos que quieres llevar\n"
	.string "en la MOCHILA PIRÁMIDE o que lleven\l"
	.string "tus POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem_hns:
	.string "Al menos un POKéMON sostiene\n"
	.string "todavía un objeto.$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep_hns:
	.string "Elige los objetos que quieres llevar\n"
	.string "en la MOCHILA PIRÁMIDE o que lleven\l"
	.string "tus POKéMON.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld_hns:
	.string "{PLAYER} ha devuelto todo lo que\n"
	.string "llevaban los POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept_hns:
	.string "Guardaremos la MOCHILA PIRÁMIDE que\n"
	.string "has usado para tu próxima expedición.\p"
	.string "{PLAYER} devolvió la MOCHILA PIRÁMIDE\n"
	.string "a cambio de su MOCHILA de siempre.$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait_hns:
	.string "Vamos a guardar tu récord.\n"
	.string "Espera unos instantes.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis_hns:
	.string "Como recuerdo por conquistar la\n"
	.string "PIRÁMIDE BATALLA, acepta esto, por\l"
	.string "favor.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem_hns:
	.string "{PLAYER} recibió el premio\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull_hns:
	.string "… Ah… Parece que tienes la MOCHILA\n"
	.string "llena.\p"
	.string "Vuelve cuando hayas ordenado el\n"
	.string "contenido de tu MOCHILA.$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag_hns:
	.string "Lo siento por ti…\p"
	.string "Toma tu MOCHILA.\p"
	.string "{PLAYER} recuperó su MOCHILA.$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge_hns:
	.string "Esperamos que vuelvas\n"
	.string "pronto por aquí.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize_hns:
	.string "¡Te estábamos esperando!\p"
	.string "Aquí tienes tu premio por conquistar\n"
	.string "la PIRÁMIDE.$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait_hns:
	.string "Hola…\p"
	.string "Si quieres, te contaré las calamidades\n"
	.string "que te aguardan en la PIRÁMIDE…$"

BattleFrontier_BattlePyramidLobby_Text_Aah_hns:
	.string "Mmm… \p"
	.string "Mmmmm…\p"
	.string "Mmmmmmm…\p"
	.string "¡Aah!$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis_hns:
	.string "Veo una lluvia de chispas…\p"
	.string "Y, bajo ella, veo a tus POKéMON\n"
	.string "luchando contra la parálisis…$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison_hns:
	.string "Veo veneno…\p"
	.string "Y veo también a tus POKéMON\n"
	.string "sufriendo su efecto…$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn_hns:
	.string "Veo llamas de un rojo vivo…\p"
	.string "Y veo a tus POKéMON sufriendo\n"
	.string "sus quemaduras…$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste_hns:
	.string "Siento la enorme presión\n"
	.string "de una rabia irracional…\p"
	.string "Es una especie de maldición…\p"
	.string "Veo a tus POKéMON quedarse poco a poco\n"
	.string "sin PUNTOS de PODER, sin otra opción\l"
	.string "que recurrir al COMBATE…$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate_hns:
	.string "Veo POKéMON elevándose sutilmente\n"
	.string "en el aire…\p"
	.string "Y veo a tus POKéMON frustrados por\n"
	.string "lo inútiles que les resultan todos sus\l"
	.string "movimientos de tipo TIERRA…$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility_hns:
	.string "Siento una energía terrorífica que\n"
	.string "surge de debajo de la tierra…\p"
	.string "Y veo a tus POKéMON incapaces de\n"
	.string "escapar al poder de sus garras…$"

BattleFrontier_BattlePyramidLobby_Text_HintIce_hns:
	.string "Veo POKéMON de tipo HIELO…\p"
	.string "Y veo a tus POKéMON luchando\n"
	.string "contra su poder congelante…$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion_hns:
	.string "Veo un frenesí de movimientos que\n"
	.string "ponen en peligro hasta a quien los usa…\p"
	.string "Y veo a tus POKéMON sucumbir\n"
	.string "a sus demoledores efectos…$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic_hns:
	.string "Veo POKéMON de tipo PSÍQUICO…\p"
	.string "Y veo a tus POKéMON atormentados\n"
	.string "bajo sus enormes poderes mentales…$"

BattleFrontier_BattlePyramidLobby_Text_HintRock_hns:
	.string "Veo POKéMON de tipo ROCA…\p"
	.string "Y los veo castigar con dureza\n"
	.string "a tus POKéMON…$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting_hns:
	.string "Veo POKéMON de tipo LUCHA…\p"
	.string "Luchando y castigando a tus POKéMON…$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather_hns:
	.string "DANZA LLUVIA… DÍA SOLEADO…\n"
	.string "TORMENTA ARENA… GRANIZO…\p"
	.string "Veo POKéMON que se hacen más fuertes\n"
	.string "con los cambios del tiempo…\p"
	.string "Y veo a tus POKéMON sufriendo\n"
	.string "el azote de sus movimientos…$"

BattleFrontier_BattlePyramidLobby_Text_HintBug_hns:
	.string "Veo POKéMON de tipo BICHO…\p"
	.string "Y veo a tus POKéMON acribillados\n"
	.string "por ataques de distintos tipos…$"

BattleFrontier_BattlePyramidLobby_Text_HintDark_hns:
	.string "Veo POKéMON de tipo SINIESTRO…\p"
	.string "Y los veo castigar a tus POKéMON con\n"
	.string "sus perversos movimientos…$"

BattleFrontier_BattlePyramidLobby_Text_HintWater_hns:
	.string "Veo POKéMON de tipo AGUA…\p"
	.string "Y veo a tus POKéMON tratando\n"
	.string "de no sucumbir bajo el agua…$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost_hns:
	.string "Veo POKéMON de tipo FANTASMA…\p"
	.string "Y veo a tus POKéMON atemorizados por\n"
	.string "sus terroríficos movimientos…$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel_hns:
	.string "Veo POKéMON de tipo ACERO…\p"
	.string "Y los veo caer sobre tus POKéMON\n"
	.string "con todo el peso de sus movimientos…$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon_hns:
	.string "Veo POKéMON voladores…\p"
	.string "Y veo a tus POKéMON tratando de\n"
	.string "escapar del poder de sus movimientos…$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve_hns:
	.string "Veo a los que han evolucionado a partir\n"
	.string "del poder de las piedras…\p"
	.string "Siento su fuego, su agua,\n"
	.string "y su electricidad…\p"
	.string "Y veo sufrir a tus POKéMON\n"
	.string "bajo esas tres fuerzas…$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal_hns:
	.string "Veo POKéMON de tipo NORMAL…\p"
	.string "Y veo a tus POKéMON sufriendo\n"
	.string "la dureza de sus ataques…$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot_hns:
	.string "Que creas en mis predicciones o no,\n"
	.string "depende solamente de ti…\p"
	.string "El futuro siempre se puede cambiar…\n"
	.string "Te deseo mucha suerte.$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning_hns:
	.string "¿Sabes una cosa?\p"
	.string "Resulta que, si corres y te ven\n"
	.string "los ENTRENADORES, irán a por ti.\p"
	.string "Si no quieres líos, no llames la atención\n"
	.string "e intenta pasar sin que se den cuenta.$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems_hns:
	.string "¡Aaaaargh! ¡Qué rabia!\p"
	.string "Tenía un montón de objetos, ¡y los\n"
	.string "perdí todos cuando perdí el combate!\p"
	.string "¡Aaaaargh!$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing_hns:
	.string "¡Es un honor tenerte otra vez aquí!\n"
	.string "¡Has conseguido lo impensable!\p"
	.string "¡Has derrotado al REY de la PIRÁMIDE\n"
	.string "y has coronado la PIRÁMIDE BATALLA!$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints_hns:
	.string "¡Has demostrado un gran valor!\n"
	.string "¡No hay mejor recompensa por ello\l"
	.string "que los PUNTOS de BATALLA!$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed_hns:
	.string "Son las reglas de la EXPEDICIÓN\n"
	.string "de COMBATES.$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading_hns:
	.string "¿Qué capítulo quieres leer?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules_hns:
	.string "Cuando llegues a la cima de la PIRÁMIDE,\n"
	.string "los POKéMON salvajes que había en ella\l"
	.string "serán sustituidos por otros distintos.\p"
	.string "Explora, observa y fíjate en los\n"
	.string "POKéMON salvajes con los que\l"
	.string "puedes encontrarte.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules_hns:
	.string "En la PIRÁMIDE acechan muchos\n"
	.string "ENTRENADORES.\p"
	.string "En cada nivel, puede haber\n"
	.string "hasta ocho ENTRENADORES.\p"
	.string "Cada vez que derrotes a uno, obtendrás\n"
	.string "una pista que te ayudará a continuar.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules_hns:
	.string "Los laberintos que hay en la PIRÁMIDE\n"
	.string "cambian cada vez que entras en ella.\p"
	.string "Los laberintos están en penumbra.\n"
	.string "Ve con mucho cuidado.\p"
	.string "Cada vez que derrotes a un POKéMON\n"
	.string "salvaje o a un ENTRENADOR, la luz que\l"
	.string "ilumina el laberinto será más intensa.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules_hns:
	.string "La MOCHILA PIRÁMIDE será la que lleves\n"
	.string "cuando estés dentro de la PIRÁMIDE.\p"
	.string "Hay dos tipos de MOCHILA PIRÁMIDE:\n"
	.string "uno para las expediciones de nivel 50\l"
	.string "y otro para las de nivel libre.\p"
	.string "Cada una tiene capacidad para\n"
	.string "99 objetos de diez clases distintas.\p"
	.string "Si fracasa tu expedición, perderás\n"
	.string "el contenido de la MOCHILA PIRÁMIDE.$"

