OneIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OneIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_LOAD, OneIsland_PokemonCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OneIsland_PokemonCenter_1F_OnFrame
	.byte 0

OneIsland_PokemonCenter_1F_OnLoad::
	call_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile
	call_if_set FLAG_IS_CHAMPION, OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn
	end

OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile::
	setmetatile 13, 4, METATILE_PokemonCenterFrlg_NetworkMachine_Ruby, 1
	return

OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile::
	setmetatile 16, 4, METATILE_PokemonCenterFrlg_NetworkMachine_Sapphire, 1
	return

OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn::
	call OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile
	setmetatile 14, 4, METATILE_PokemonCenterFrlg_NetworkMachine_ScreenLeft_On, 1
	setmetatile 15, 4, METATILE_PokemonCenterFrlg_NetworkMachine_ScreenRight_On, 1
	return

OneIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_ONE_ISLAND
	call_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6, OneIsland_PokemonCenter_1F_EventScript_SetCelioQuestDone
	call_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 0, OneIsland_PokemonCenter_1F_EventScript_SetBillCelioFirstMeetingPos
	call_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 2, OneIsland_PokemonCenter_1F_EventScript_SetBillCelioReadyToLeavePos
	end

OneIsland_PokemonCenter_1F_EventScript_SetCelioQuestDone::
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 7
	return

OneIsland_PokemonCenter_1F_EventScript_SetBillCelioFirstMeetingPos::
	setobjectxyperm LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, 9, 8
	setobjectmovementtype LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_CELIO, 15, 6
	setobjectmovementtype LOCALID_CELIO, MOVEMENT_TYPE_FACE_UP
	return

OneIsland_PokemonCenter_1F_EventScript_SetBillCelioReadyToLeavePos::
	setobjectxyperm LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, 14, 7
	setobjectmovementtype LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_CELIO, 14, 8
	setobjectmovementtype LOCALID_CELIO, MOVEMENT_TYPE_FACE_LEFT
	return

OneIsland_PokemonCenter_1F_OnFrame::
	map_script_2 VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 0, OneIsland_PokemonCenter_1F_EventScript_MeetCelioScene
	.2byte 0

OneIsland_PokemonCenter_1F_EventScript_MeetCelioScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToCelio
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, OneIsland_PokemonCenter_1F_Movement_BillWalkToCelio
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillHeyThereCelio
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_CELIO, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_Delay48
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioCantBelieveYouCameOut
	msgbox OneIsland_PokemonCenter_1F_Text_BillHowsYourResearchComing
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_ThisIsMyBuddyCelio
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call_if_set FLAG_SYS_GAME_CLEAR, OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerChamp
	call_if_unset FLAG_SYS_GAME_CLEAR, OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerNotChamp
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioThatsReallyImpressive
	msgbox OneIsland_PokemonCenter_1F_Text_BillBringMeUpToSpeed
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioPCsCantLinkWithYours
	closemessage
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillLetMeHelpYou
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CanYouDeliverThisMeteoritePlayer
	msgreceiveditem OneIsland_PokemonCenter_1F_Text_AcceptedMeteoriteFromBill, ITEM_METEORITE, 1, MUS_RG_OBTAIN_KEY_ITEM
	additem ITEM_METEORITE
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioPleaseTakeThis
	giveitem_msg OneIsland_PokemonCenter_1F_Text_ObtainedTriPass, ITEM_TRI_PASS, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox OneIsland_PokemonCenter_1F_Text_PassLetsYouTravelBetweenIslands
	call_if_ge VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMapPage
	call_if_lt VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMap
	setflag FLAG_SYS_SEVII_MAP_123
	msgbox OneIsland_PokemonCenter_1F_Text_BillCatchYouLater
	closemessage
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setflag FLAG_SYS_PC_STORAGE_DISABLED
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerChamp::
	msgbox OneIsland_PokemonCenter_1F_Text_PlayerIsReigningPokemonChamp
	return

OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerNotChamp::
	msgbox OneIsland_PokemonCenter_1F_Text_PlayerIsRisingPokemonChamp
	return

OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMapPage::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message OneIsland_PokemonCenter_1F_Text_ReceivedExtraPageForTownMap
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	return

OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMap::
	setflag FLAG_HIDE_TOWN_MAP
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	giveitem_msg OneIsland_PokemonCenter_1F_Text_ReceivedTownMap, ITEM_TOWN_MAP, 1, MUS_RG_OBTAIN_KEY_ITEM
	return

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToCelio::
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

OneIsland_PokemonCenter_1F_Movement_BillWalkToCelio::
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_faster_right
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_WalkUp:
	walk_up
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_StepAsideLeft::
	walk_left
	walk_in_place_faster_right
	step_end

OneIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

OneIsland_PokemonCenter_1F_EventScript_Bill::
	lock
	goto_if_set FLAG_SEVII_DETOUR_FINISHED, OneIsland_PokemonCenter_1F_EventScript_BillGoTakeStroll
	msgbox OneIsland_PokemonCenter_1F_Text_HmmHowAboutLikeThis
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BillGoTakeStroll::
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_GotPCWorkingStrollAWhileMore
	release
	end

OneIsland_PokemonCenter_1F_EventScript_Celio::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 7, OneIsland_PokemonCenter_1F_EventScript_CelioGiveBillFact
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6, OneIsland_PokemonCenter_1F_EventScript_CelioJustGivenSapphire
	goto_if_set FLAG_RECOVERED_SAPPHIRE, OneIsland_PokemonCenter_1F_EventScript_GiveCelioSapphire
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass
	goto_if_set FLAG_GOT_RUBY, OneIsland_PokemonCenter_1F_EventScript_GiveCelioRuby
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, OneIsland_PokemonCenter_1F_EventScript_CelioWaitingForRuby
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	goto_if_eq VAR_RESULT, TRUE, OneIsland_PokemonCenter_1F_EventScript_CelioRequestRuby
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 3, OneIsland_PokemonCenter_1F_EventScript_CelioPlayerMissingNationalDex
	msgbox OneIsland_PokemonCenter_1F_Text_SorryForBeingPoorHost
	closemessage
	applymovement LOCALID_CELIO, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioGiveBillFact::
	msgbox OneIsland_PokemonCenter_1F_Text_CelioHearingRumorsAboutYou
	random 3
	goto_if_eq VAR_RESULT, 0, OneIsland_PokemonCenter_1F_EventScript_BillFact1
	goto_if_eq VAR_RESULT, 1, OneIsland_PokemonCenter_1F_EventScript_BillFact2
	famechecker FAMECHECKER_BILL, 5
	msgbox OneIsland_PokemonCenter_1F_Text_BillCantStomachMilk
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BillFact1::
	famechecker FAMECHECKER_BILL, 3
	msgbox OneIsland_PokemonCenter_1F_Text_BillsFirstMonWasAbra
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BillFact2::
	famechecker FAMECHECKER_BILL, 4
	msgbox OneIsland_PokemonCenter_1F_Text_BillsHometownInGoldenrod
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioJustGivenSapphire::
	msgbox OneIsland_PokemonCenter_1F_Text_WishYouBestOfLuck
	release
	end

OneIsland_PokemonCenter_1F_EventScript_GiveCelioSapphire::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message OneIsland_PokemonCenter_1F_Text_HandedSapphireToCelio
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	removeitem ITEM_SAPPHIRE
	msgbox OneIsland_PokemonCenter_1F_Text_ThankYouGiveMeTime
	closemessage
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine
	waitmovement 0
	playse SE_CLICK
	call OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile
	special DrawWholeMapView
	msgbox OneIsland_PokemonCenter_1F_Text_OkayThisIsGood
	closemessage
	delay 60
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine
	waitmovement 0
	delay 30
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine
	waitmovement 0
	delay 40
	playse SE_PC_ON
	call OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn
	special DrawWholeMapView
	msgbox OneIsland_PokemonCenter_1F_Text_LinkedUpWithLanette
	applymovement LOCALID_CELIO, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_ManagedToLinkWithHoennThankYou
	special SetPostgameFlags
	setflag FLAG_IS_CHAMPION
	setflag FLAG_HIDE_CERULEAN_CAVE_GUARD
	setflag FLAG_HIDE_LORELEI_IN_HER_HOUSE
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6
	special InitRoamer
	release
	end

OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass::
	msgbox OneIsland_PokemonCenter_1F_Text_PassLetYouGetToAllIslands
	release
	end

OneIsland_PokemonCenter_1F_EventScript_GiveCelioRuby::
	msgbox OneIsland_PokemonCenter_1F_Text_OhThats
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message OneIsland_PokemonCenter_1F_Text_HandedRubyToCelio
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	closemessage
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine
	waitmovement 0
	playse SE_CLICK
	call OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile
	special DrawWholeMapView
	delay 30
	applymovement LOCALID_CELIO, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_MayIAskOneMoreFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio
	goto OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass
	end

OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio::
	msgbox OneIsland_PokemonCenter_1F_Text_PleaseINeedYourHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio
	goto OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass
	end

OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass::
	msgbox OneIsland_PokemonCenter_1F_Text_AnotherGemstoneInSeviiIslands
	removeitem ITEM_RUBY
	removeitem ITEM_TRI_PASS
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5
	additem ITEM_RAINBOW_PASS
	setflag FLAG_SYS_SEVII_MAP_4567
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message OneIsland_PokemonCenter_1F_Text_ReturnedTriPassForRainbowPass
	waitmessage
	waitfanfare
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message OneIsland_PokemonCenter_1F_Text_ObtainedExtraMapPage
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	goto OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass
	end

OneIsland_PokemonCenter_1F_EventScript_CelioWaitingForRuby::
	msgbox OneIsland_PokemonCenter_1F_Text_TryingToFindGem
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioRequestRuby::
	msgbox OneIsland_PokemonCenter_1F_Text_CelioCaughtMoreMonMaybeICanBeUseful
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_YoullBeTradingFromTrainersFarAway
	applymovement LOCALID_CELIO, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_NeedsSpecialGemstone
	setvar VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 1
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioPlayerMissingNationalDex::
	msgbox OneIsland_PokemonCenter_1F_Text_CelioImModifyingMyNetworkMachine
	release
	end

OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine::
	walk_in_place_up
	delay_8
	walk_in_place_up
	step_end

OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine::
	walk_in_place_faster_up
	walk_in_place_up
	delay_16
	walk_in_place_up
	walk_in_place_up
	step_end

OneIsland_PokemonCenter_1F_EventScript_LittleBoy::
	msgbox OneIsland_PokemonCenter_1F_Text_CameFromPalletDontKnowIt, MSGBOX_NPC
	end

OneIsland_PokemonCenter_1F_EventScript_Hiker::
	msgbox OneIsland_PokemonCenter_1F_Text_EnormousVolcanoOnIsland, MSGBOX_NPC
	end

OneIsland_PokemonCenter_1F_EventScript_BattleGirl::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, OneIsland_PokemonCenter_1F_EventScript_BattleGirlHoennLinked
	msgbox OneIsland_PokemonCenter_1F_Text_WishICouldTradeWithBoyfriend
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BattleGirlHoennLinked::
	msgbox OneIsland_PokemonCenter_1F_Text_TradedWithFarAwayBoyfriend
	release
	end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachine::
	lockall
	goto_if_set FLAG_IS_CHAMPION, OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithHoenn
	goto_if_set FLAG_SEVII_DETOUR_FINISHED, OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithKanto
	msgbox OneIsland_PokemonCenter_1F_Text_MachineUnderAdjustment
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithKanto::
	msgbox OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKanto
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithHoenn::
	msgbox OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKantoAndHoenn
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerTop::
	lockall
	setvar VAR_TEMP_1, 1
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerMidTop::
	lockall
	setvar VAR_TEMP_1, 2
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerMidBottom::
	lockall
	setvar VAR_TEMP_1, 3
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 4
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene::
	textcolor NPC_TEXT_COLOR_MALE
	playse SE_PIN
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillOhHeyPlayer
	closemessage
	call_if_eq VAR_TEMP_1, 1, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillTop
	call_if_eq VAR_TEMP_1, 2, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidTop
	call_if_eq VAR_TEMP_1, 3, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidBottom
	call_if_eq VAR_TEMP_1, 4, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillBottom
	delay 10
	msgbox OneIsland_PokemonCenter_1F_Text_BillWeGotItDone
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioJobWentQuick
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillYouveLearnedALot
	msgbox OneIsland_PokemonCenter_1F_Text_CelioOhReallyEhehe
	closemessage
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 15
	msgbox OneIsland_PokemonCenter_1F_Text_BillWeShouldHeadBackToKanto
	closemessage
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 15
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioPromiseIllShowYouAroundSometime
	closemessage
	delay 25
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerExit
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, OneIsland_PokemonCenter_1F_Movement_BillExit
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_ONE_ISLAND_POKECENTER_BILL
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 3
	clearflag FLAG_HIDE_CINNABAR_BILL
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND, 3
	setvar VAR_0x8004, SEAGALLOP_ONE_ISLAND
	setvar VAR_0x8006, SEAGALLOP_CINNABAR_ISLAND
	goto EventScript_SetSail
	end

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillTop::
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillTop
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidTop::
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidTop
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidBottom::
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidBottom
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillBottom::
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillBottom
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillTop::
	walk_right
	walk_down
	walk_in_place_faster_right
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidTop::
	walk_right
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidBottom::
	walk_right
	walk_up
	walk_in_place_faster_right
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillBottom::
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_DelayWalkInPlaceLeft::
	delay_16
	delay_16
	delay_4
	walk_in_place_faster_left
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_WalkInPlaceDown::
	walk_in_place_fast_down
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerExit::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

OneIsland_PokemonCenter_1F_Movement_BillExit::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

OneIsland_PokemonCenter_1F_Text_BillHeyThereCelio::
	.string "BILL: ¡Eh, oye!\n"
	.string "¡CELIO!$"

OneIsland_PokemonCenter_1F_Text_CelioCantBelieveYouCameOut::
	.string "CELIO: ¡Hombre, BILL!\n"
	.string "¡No puedo creerme que estés aquí!$"

OneIsland_PokemonCenter_1F_Text_BillHowsYourResearchComing::
	.string "BILL: ¡Pues claro, hombre!\n"
	.string "¿Qué tal van tus investigaciones?\p"
	.string "Eh..., ay, perdona...$"

OneIsland_PokemonCenter_1F_Text_ThisIsMyBuddyCelio::
	.string "{PLAYER}, éste es mi amigo CELIO.\n"
	.string "Es un flipado de los ordenadores.$"

OneIsland_PokemonCenter_1F_Text_PlayerIsRisingPokemonChamp::
	.string "BILL: CELIO, te presento\n"
	.string "a {PLAYER}, aspirante a ganar\l"
	.string "la LIGA POKéMON.$"

OneIsland_PokemonCenter_1F_Text_PlayerIsReigningPokemonChamp::
	.string "BILL: CELIO, te presento\n"
	.string "a {PLAYER}, ¡ha ganado la LIGA\l"
	.string "POKéMON!$"

OneIsland_PokemonCenter_1F_Text_CelioThatsReallyImpressive::
	.string "CELIO: ¡Anda, fíjate tú!\p"
	.string "Yo la verdad es que soy un negado\n"
	.string "para los combates.\p"
	.string "Pero oye, me alegro de conocerte.$"

OneIsland_PokemonCenter_1F_Text_BillBringMeUpToSpeed::
	.string "BILL: Bueno, cuéntame, cuéntame,\n"
	.string "¿qué tal va la máquina esa en la\l"
	.string "que estabas trabajando?$"

OneIsland_PokemonCenter_1F_Text_CelioPCsCantLinkWithYours::
	.string "CELIO: Va bien, va bien, pero es\n"
	.string "que estamos en el quinto pino\p"
	.string "y no hay forma de conectar los PCs\n"
	.string "de aquí con tu PC, BILL.$"

OneIsland_PokemonCenter_1F_Text_BillLetMeHelpYou::
	.string "BILL: ¿Ah, no? Mmm, ¿me dejas\n"
	.string "que eche un vistazo?\p"
	.string "Un segundo... Oye, pues yo creo\n"
	.string "que podemos conseguir que\l"
	.string "funcione. ¿Me dejas que te ayude?$"

OneIsland_PokemonCenter_1F_Text_CanYouDeliverThisMeteoritePlayer::
	.string "{PLAYER}, ¿te importa esperarme\n"
	.string "un momento?\p"
	.string "O, mejor, ¿me haces un favor?\p"
	.string "Cerca de aquí está ISLA SECUNDA\n"
	.string "y hay un tipo que lleva los\l"
	.string "RECREATIVOS.\p"
	.string "La cosa es que le encantan\n"
	.string "las rocas raras y las gemas.\p"
	.string "Como ves, los dos tenemos\n"
	.string "nuestras manías, por eso estamos\l"
	.string "en contacto.\p"
	.string "¿Te importaría acercarle\n"
	.string "este METEORITO?$"

OneIsland_PokemonCenter_1F_Text_AcceptedMeteoriteFromBill::
	.string "{PLAYER} obtuvo el METEORITO\n"
	.string "de manos de BILL.$"

OneIsland_PokemonCenter_1F_Text_CelioPleaseTakeThis::
	.string "CELIO: {PLAYER}, toma, llévate esto\n"
	.string "si vas a ir a ISLA SECUNDA.$"

OneIsland_PokemonCenter_1F_Text_PassLetsYouTravelBetweenIslands::
	.string "CELIO: Es un TICKET para el ferry\n"
	.string "que conecta las islas.\p"
	.string "Con él podrás viajar entre las\n"
	.string "ISLAS PRIMA, SECUNDA y TERA.\p"
	.string "¡Ah, y llévate esto también!$"

OneIsland_PokemonCenter_1F_Text_ReceivedExtraPageForTownMap::
	.string "¡{PLAYER} obtuvo una página más\n"
	.string "del MAPA!$"

OneIsland_PokemonCenter_1F_Text_ReceivedTownMap::
	.string "¡{PLAYER} obtuvo el MAPA!$"

OneIsland_PokemonCenter_1F_Text_BillCatchYouLater::
	.string "BILL: ¡Bueno, después nos vemos!\n"
	.string "¡Dale recuerdos de mi parte!$"

OneIsland_PokemonCenter_1F_Text_HmmHowAboutLikeThis::
	.string "Mmm...\p"
	.string "¿Y si intentamos ponerlo de otra\n"
	.string "forma?...$"

OneIsland_PokemonCenter_1F_Text_GotPCWorkingStrollAWhileMore::
	.string "¡Eh, {PLAYER}!\p"
	.string "¿Has visto? ¡Hemos conseguido\n"
	.string "la conexión con el PC!\p"
	.string "Pero aún tengo que enseñarle\n"
	.string "un par de cosas a CELIO.\p"
	.string "¿Por qué no te das un paseo\n"
	.string "mientras?$"

OneIsland_PokemonCenter_1F_Text_SorryForBeingPoorHost::
	.string "CELIO: Siento haber entretenido\n"
	.string "tanto a BILL.\p"
	.string "Y siento también haber sido tan\n"
	.string "mal anfitrión.$"

OneIsland_PokemonCenter_1F_Text_UsualPCServicesUnavailable::
	.string "Los servicios habituales del PC\n"
	.string "no están disponibles...$"

OneIsland_PokemonCenter_1F_Text_BillOhHeyPlayer::
	.string "BILL: ¡Anda, {PLAYER}!\n"
	.string "¿Qué tal?$"

OneIsland_PokemonCenter_1F_Text_BillWeGotItDone::
	.string "BILL: ¿Qué has estado haciendo\n"
	.string "tanto tiempo? ¿Qué tal, bien?\p"
	.string "¡Nosotros ya lo tenemos! ¡Los PCs\n"
	.string "están a punto y van de maravilla!$"

OneIsland_PokemonCenter_1F_Text_CelioJobWentQuick::
	.string "CELIO: La verdad es que ha sido\n"
	.string "más rápido de lo que pensaba.\p"
	.string "BILL es un cerebrito.$"

OneIsland_PokemonCenter_1F_Text_BillYouveLearnedALot::
	.string "BILL: ¡Qué va, hombre! ¡Si todo\n"
	.string "estaba prácticamente hecho!\p"
	.string "CELIO, el mérito es tuyo.\n"
	.string "Sabes un montón.$"

OneIsland_PokemonCenter_1F_Text_CelioOhReallyEhehe::
	.string "CELIO: ¿Tú crees?\n"
	.string "Bueno, pues vale. Je.$"

OneIsland_PokemonCenter_1F_Text_BillWeShouldHeadBackToKanto::
	.string "BILL: Bueno, pues ya está.\n"
	.string "Por mi parte, yo he acabado.\l"
	.string "Vámonos ya de vuelta a KANTO.\p"
	.string "CELIO, nos vemos.$"

OneIsland_PokemonCenter_1F_Text_CelioPromiseIllShowYouAroundSometime::
	.string "CELIO: {PLAYER}, siento mucho que\n"
	.string "hayas tenido que marcharte sin\l"
	.string "nadie que te acompañara.\p"
	.string "Te prometo que te enseñaré\n"
	.string "la isla en otra ocasión.$"

OneIsland_PokemonCenter_1F_Text_CelioImModifyingMyNetworkMachine::
	.string "CELIO: ¡Hola!\n"
	.string "¡Siempre estás de aquí para allá!\p"
	.string "¿Que qué tal voy?\p"
	.string "Pues haciendo unos retoques\n"
	.string "a la MÁQUINA de REDES.\p"
	.string "¡Espero que la uses antes que\n"
	.string "nadie cuando esté lista, {PLAYER}!$"

OneIsland_PokemonCenter_1F_Text_CelioCaughtMoreMonMaybeICanBeUseful::
	.string "CELIO: {PLAYER}, ¿qué tal\n"
	.string "te ha ido?\p"
	.string "¿De verdad? ¿Has atrapado más\n"
	.string "POKéMON?\p"
	.string "Pues ¿sabes qué? A lo mejor puedo\n"
	.string "ayudarte.$"

OneIsland_PokemonCenter_1F_Text_YoullBeTradingFromTrainersFarAway::
	.string "En este momento estoy modificando\n"
	.string "la MÁQUINA de REDES.\p"
	.string "Estoy ajustándola para que puedan\n"
	.string "hacerse intercambios a grandes\l"
	.string "distancias.\p"
	.string "Cuando acabe, podrás recibir\n"
	.string "exóticos POKéMON de ENTRENADORES\l"
	.string "que están muy lejos de aquí.$"

OneIsland_PokemonCenter_1F_Text_NeedsSpecialGemstone::
	.string "Pero falta un pequeño detalle.\p"
	.string "Para que funcione la conexión,\n"
	.string "se necesita una gema especial.\p"
	.string "Parece ser que se encuentra\n"
	.string "en ISLA PRIMA, pero yo aún\l"
	.string "no he encontrado ninguna.\p"
	.string "Averigua dónde estará...$"

OneIsland_PokemonCenter_1F_Text_TryingToFindGem::
	.string "Durante mis investigaciones\n"
	.string "también he intentado encontrar\l"
	.string "la gema.\p"
	.string "Y al final, ni tengo gema ni\n"
	.string "he avanzado nada en mis estudios...\p"
	.string "Si acudiera a BILL, seguro que\n"
	.string "avanzaría en mis investigaciones.\p"
	.string "Pero en esta ocasión, quiero hacer\n"
	.string "las cosas por mí mismo.$"

OneIsland_PokemonCenter_1F_Text_OhThats::
	.string "¡Ahí va!\n"
	.string "¡Pero si es...!$"

OneIsland_PokemonCenter_1F_Text_HandedRubyToCelio::
	.string "{PLAYER} le entregó el RUBÍ\n"
	.string "a CELIO.$"

OneIsland_PokemonCenter_1F_Text_MayIAskOneMoreFavor::
	.string "¡Muchas gracias!\n"
	.string "¡{PLAYER}, eres increíble!\p"
	.string "... ... ... ... ... ...\p"
	.string "Eh...\n"
	.string "¿Puedo pedirte un favor enorme?$"

OneIsland_PokemonCenter_1F_Text_PleaseINeedYourHelp::
	.string "No es ninguna cosa rara...,\n"
	.string "no te preocupes.\l"
	.string "Es que necesito que me ayudes.$"

OneIsland_PokemonCenter_1F_Text_AnotherGemstoneInSeviiIslands::
	.string "Mientras estudiaba las gemas,\n"
	.string "descubrí algo importante.\p"
	.string "Hay otra que forma pareja\n"
	.string "con este RUBÍ.\p"
	.string "Y se supone que está en\n"
	.string "ARCHI7.\p"
	.string "{PLAYER}, necesito que vayas\n"
	.string "a buscarla, por favor.\p"
	.string "{PLAYER}, ¿me dejas un segundo\n"
	.string "el TICKET del ferry y el MAPA?$"

OneIsland_PokemonCenter_1F_Text_ReturnedTriPassForRainbowPass::
	.string "{PLAYER} devolvió el TRI-TICKET\n"
	.string "y recibió el IRIS-TICKET.$"

OneIsland_PokemonCenter_1F_Text_ObtainedExtraMapPage::
	.string "¡Y obtuviste una página más\n"
	.string "del MAPA!$"

OneIsland_PokemonCenter_1F_Text_PassLetYouGetToAllIslands::
	.string "Éste es mi TICKET para el ferry.\p"
	.string "Con él, podrás viajar entre las\n"
	.string "islas de ARCHI7.\p"
	.string "{PLAYER}, tienes que ayudarme,\n"
	.string "por favor.$"

OneIsland_PokemonCenter_1F_Text_HandedSapphireToCelio::
	.string "{PLAYER} le entregó el ZAFIRO\n"
	.string "a CELIO.$"

OneIsland_PokemonCenter_1F_Text_ThankYouGiveMeTime::
	.string "CELIO: Así que ésta es la\n"
	.string "compañera del RUBÍ...\p"
	.string "{PLAYER}, has debido de pasar por\n"
	.string "mil historias para conseguirla, ¿no?\p"
	.string "No hace falta que me digas nada,\n"
	.string "sé que no habrá sido nada fácil.\p"
	.string "¡Muchas gracias!\p"
	.string "Ahora me toca a mí hacer algo\n"
	.string "por ti. Dame algo de tiempo.$"

OneIsland_PokemonCenter_1F_Text_OkayThisIsGood::
	.string "Muy bien, a ver...$"

OneIsland_PokemonCenter_1F_Text_LinkedUpWithLanette::
	.string "¡Ya está!\n"
	.string "¡He conseguido establecer conexión\l"
	.string "con AREDIA!$"

OneIsland_PokemonCenter_1F_Text_ManagedToLinkWithHoennThankYou::
	.string "¡{PLAYER}!\n"
	.string "¡{PLAYER}, lo he conseguido!\p"
	.string "¡He conseguido establecer conexión\n"
	.string "con ENTRENADORES de la región\l"
	.string "de HOENN!\p"
	.string "¡Por fin funciona completamente\n"
	.string "la MÁQUINA de REDES!\p"
	.string "{PLAYER}, te lo debo todo a ti.\p"
	.string "Gracias a ti, mi sueño se ha hecho\n"
	.string "realidad...$"

OneIsland_PokemonCenter_1F_Text_WishYouBestOfLuck::
	.string "No...\n"
	.string "No estoy llorando, no...\p"
	.string "Ya está, ya se me pasa...\p"
	.string "{PLAYER}, ¿a que vas a intentar\n"
	.string "conseguir exóticos POKéMON, eh?\p"
	.string "¡Que tengas mucha suerte!$"

OneIsland_PokemonCenter_1F_Text_CelioHearingRumorsAboutYou::
	.string "CELIO: ¡Hola!\p"
	.string "{PLAYER}, últimamente se habla\n"
	.string "mucho sobre ti...$"

OneIsland_PokemonCenter_1F_Text_BillsFirstMonWasAbra::
	.string "{PLAYER}, ¿qué POKéMON te gusta\n"
	.string "más?\p"
	.string "BILL es un POKéMANÍACO,\n"
	.string "a él le gustan todos.\p"
	.string "Creo que el primero que atrapó\n"
	.string "fue un ABRA.$"

OneIsland_PokemonCenter_1F_Text_BillsHometownInGoldenrod::
	.string "A todo esto, {PLAYER}, tú eres\n"
	.string "de PUEBLO PALETA, ¿no?\p"
	.string "Me han comentado que es un sitio\n"
	.string "muy tranquilo y agradable.\p"
	.string "BILL es de CIUDAD TRIGAL,\n"
	.string "donde aún viven sus amigos.\p"
	.string "Dicen que es una ciudad muy\n"
	.string "alegre y animada.\p"
	.string "La verdad es que me gustaría\n"
	.string "ir algún día.$"

OneIsland_PokemonCenter_1F_Text_BillCantStomachMilk::
	.string "{PLAYER}, ¿hay algo que te siente\n"
	.string "mal?\p"
	.string "Creo que BILL no tolera muy bien\n"
	.string "la leche. Le da dolor de estómago.$"

OneIsland_PokemonCenter_1F_Text_CameFromPalletDontKnowIt::
	.string "¡Eh, tú no eres de aquí!\n"
	.string "¿De dónde vienes?\p"
	.string "¿PUEBLO PALETA?...\n"
	.string "¡No me suena de nada!$"

OneIsland_PokemonCenter_1F_Text_EnormousVolcanoOnIsland::
	.string "En esta isla hay un volcán enorme.\p"
	.string "Hace poco entró en erupción.\n"
	.string "Ahora sería buen momento\l"
	.string "para hacer escalada.$"

OneIsland_PokemonCenter_1F_Text_WishICouldTradeWithBoyfriend::
	.string "Ojalá pudiera intercambiar POKéMON\n"
	.string "con mi chico, que vive muy lejos\l"
	.string "de aquí...$"

OneIsland_PokemonCenter_1F_Text_TradedWithFarAwayBoyfriend::
	.string "¡He podido intercambiar POKéMON\n"
	.string "con mi chico!\l"
	.string "¡Con lo lejos que está!\p"
	.string "Todo el mundo dice que os\n"
	.string "lo debemos a CELIO y a ti.\p"
	.string "¡Así que gracias!$"

OneIsland_PokemonCenter_1F_Text_MachineUnderAdjustment::
	.string "MÁQUINA de REDES\n"
	.string "Nivel de conexión: 0\p"
	.string "Sistema de Almacenamiento\n"
	.string "de POKéMON, no disponible...$"

OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKanto::
	.string "MÁQUINA de REDES\n"
	.string "Nivel de conexión: 1\p"
	.string "Conexión establecida con la región\n"
	.string "de KANTO.$"

OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKantoAndHoenn::
	.string "MÁQUINA de REDES\n"
	.string "Nivel de conexión: 2\p"
	.string "Conexión establecida con las\n"
	.string "regiones de KANTO y HOENN.$"

OneIsland_PokemonCenter_1F_Text_ObtainedTriPass::
	.string "¡Obtuviste el TRI-TICKET!$"

