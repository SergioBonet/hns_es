.set PLAYER_STARTER_SPECIES,  VAR_TEMP_2

NewBarkTown_Lab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Lab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_Lab_OnFrame
	.byte 0

NewBarkTown_Lab_OnTransition::
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, NewBarkTown_Lab_EventScript_ElmAtComputer
	end
	
NewBarkTown_Lab_OnFrame::
	map_script_2 VAR_NEWBARKTOWN_LABSTATE, 4, NewBarkTown_Lab_EventScript_PoliceEpisode
	.2byte 0

NewBarkTown_Lab_EventScript_ElmAtComputer::
	setobjectxyperm LOCALID_ELM, 3, 2
	setobjectmovementtype LOCALID_ELM, MOVEMENT_TYPE_FACE_UP
	end

NewBarkTown_Lab_EventScript_TriggerStartLabLeft::	
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkRight
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLabRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkLeft
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLab::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_LabMovement_WalkToElm
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_ElmIntro
	end

NewBarkTown_EventScript_Aide1::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_AideAlwaysBusy, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_EventScript_Aide2Testimony
	msgbox NewBarkTown_Lab_Text_AideSave, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2Testimony::
	msgbox NewBarkTown_Lab_Text_AideTheftTestimony, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_NEWBARKTOWN_LAB_AIDE, NewBarkTown_Lab_EventScript_ElmAideIsWaiting
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 7, NewBarkTown_Lab_EventScript_ElmMasterBall
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 8, NewBarkTown_Lab_EventScript_ElmKimono
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 9, NewBarkTown_Lab_EventScript_ElmLeague
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 10, NewBarkTown_Lab_EventScript_ElmSSTicket

	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, NewBarkTown_Lab_EventScript_Elm_AfterEggCheck
	goto_if_set FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_CallMe
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_Check_Togepi
NewBarkTown_Lab_EventScript_Elm_AfterEggCheck:
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 1, NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_Lab_EventScript_ElmState5

	goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmState5
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_MrPokemon
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmAideIsWaiting::
	msgbox NewBarkTown_Lab_Text_ElmAideIsWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Text_ElmAideIsWaiting:
	.string "¡{PLAYER}!\p"
	.string "¿Qué haces aquí?\p"
	.string "¡Mi ayudante aún te está esperando en\n"
	.string "CIUDAD MALVA!$"

NewBarkTown_Lab_EventScript_ElmIntro::
	msgbox NewBarkTown_Lab_Text_ElmIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmRefused::
	msgbox NewBarkTown_Lab_Text_ElmRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmAccepted::
	msgbox NewBarkTown_Lab_Text_ElmAccepted, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmResearchAmbitions, MSGBOX_DEFAULT
	delay 30
	playse SE_PC_LOGIN
	waitse
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ELM
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmail
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Left
	waitmovement 0
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmGotAnEmail, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ReturnFromEmail
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
	waitmovement 0
	delay 30
	msgbox NewBarkTown_Lab_Text_ElmMissionFromMrPokemon, MSGBOX_DEFAULT
	goto NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmChoosePokemon::
	msgbox NewBarkTown_Lab_Text_ElmChooseAPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 1
	release
	end

NewBarkTown_Lab_EventScript_TriggerReturnPlayer::
	lock
	msgbox NewBarkTown_Lab_Text_ElmWhereGoing, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_ReturnPlayer
	waitmovement 0
	release
	end

NewBarkTown_Lab_EventScript_ShouldntTouch::
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end


NewBarkTown_Lab_EventScript_ChikoritaBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ChikoritaBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_ChikoritaBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 0
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHIKORITA
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_CyndaquilBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_CyndaquilBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_CyndaquilBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 1
	setvar PLAYER_STARTER_SPECIES, SPECIES_CYNDAQUIL
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseCyndaquil, MSGBOX_YESNO	
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_TotodileBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_TotodileBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_TotodileBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 2
	setvar PLAYER_STARTER_SPECIES, SPECIES_TOTODILE
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_DeclinedStarter::
	hidemonpic
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
	closemessage
	@callnative EnableStaticRandomizer
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter::
	@callnative EnableStaticRandomizer
	hidemonpic
	removeobject VAR_LAST_TALKED
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, NewBarkTown_Lab_EventScript_GiveStarter_Chikorita
	call_if_eq VAR_STARTER_MON, 1, NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil
	call_if_eq VAR_STARTER_MON, 2, NewBarkTown_Lab_EventScript_GiveStarter_Totodile
	setflag FLAG_SYS_POKEMON_GET
	playfanfare MUS_OBTAIN_ITEM
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	message NewBarkTown_Lab_Text_ReceivedStarter
	waitfanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke
	msgbox NewBarkTown_Lab_Text_Nickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_NicknameStarter
	callnative UpdateFollowingPokemon
	release
	end

NewBarkTown_Lab_EventScript_GiveStarter_Chikorita::
	call_if_unset FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil::
	call_if_unset FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Totodile::
	call_if_unset FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_NotShiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_NEVER
	return

NewBarkTown_Lab_EventScript_GiveStarter_Shiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS	
	return

NewBarkTown_Lab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke::
	message NewBarkTown_Lab_Text_Nickname
	waitmessage
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_MrPokemon::
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
	setvar VAR_NEWBARK_TOWN_STATE, 3
	msgbox NewBarkTown_Lab_Text_ElmDirections1_Register, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_RegisteredElm, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	setflag FLAG_ENABLE_CONDITION
	release
	end

NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	release
	end

CopNewBarkTown_Lab_EventScript_ElmState2::
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine1::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine2::
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end



NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_HideCyndaquil::
	setflag FLAG_HIDE_CYNDAQUILBALL
	return
NewBarkTown_Lab_EventScript_HideTotodile::
	setflag FLAG_HIDE_TOTODILEBALL
	return
NewBarkTown_Lab_EventScript_HideChikorita::
	setflag FLAG_HIDE_CHIKORITABALL
	return

NewBarkTown_Lab_EventScript_PoliceEpisode::
	lock
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
	call_if_eq VAR_STARTER_MON, 0 NewBarkTown_Lab_EventScript_HideCyndaquil
	call_if_eq VAR_STARTER_MON, 1 NewBarkTown_Lab_EventScript_HideTotodile
	call_if_eq VAR_STARTER_MON, 2 NewBarkTown_Lab_EventScript_HideChikorita
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
	waitmovement 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	turnobject LOCALID_COP DIR_WEST
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceNo::
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceYes::
	closemessage
	special NameRival
	waitstate
	msgbox NewBarkTown_Lab_Text_Officer2_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_Lab_EventScript_PoliceYes
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
	waitmovement 0
	removeobject LOCALID_COP

	@ setobjectxyperm LOCALID_COP, 25, 4
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
	delay 20
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
	setvar VAR_NEWBARK_TOWN_STATE, 4
	setflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_HIDE_MOMS_FRIEND2
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_START_NUZLOCKE
	setflag FLAG_EXP_SHARE_ENABLED
	removeitem ITEM_MYSTERY_EGG
	release
	end

NewBarkTown_Lab_EventScript_ElmState5::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
	release
	end
	
NewBarkTown_Lab_EventScript_ElmMasterBall::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ELM
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	release
	end

NewBarkTown_Lab_EventScript_ElmKimono::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmLeague::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmSSTicket::
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
	release
	end

NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_BALLS
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
	checkspecies SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGETIC
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGEKISS
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	return

NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SHOWN_ELM_TOGEPI
	release
	end

NewBarkTown_Lab_EventScript_Elm_CallMe::
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Movement_WalkRight:
	walk_right
	step_end

NewBarkTown_Lab_Movement_WalkLeft:
	walk_left
	step_end

NewBarkTown_LabMovement_WalkToElm:
	walk_up
	walk_up
	walk_up
	step_end

NewBarkTown_Lab_Movement_ReturnPlayer:
	walk_up
	step_end

NewBarkTown_Lab_Movement_CheckEmail:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

NewBarkTown_Lab_Movement_CheckEmailSlow:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_Lab_Movement_GotoComputerSafe:
	walk_up
	walk_left
	walk_left
	walk_left
	face_up
	step_end

NewBarkTown_Lab_Movement_ReturnFromEmail:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end

NewBarkTown_Lab_Movement_Look_Left:
	face_left
	step_end

NewBarkTown_Lab_Movement_Look_Up:
	face_up
	step_end


NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

NewBarkTown_Lab_Movement_Aide1LeavePlayer:
	walk_left
	walk_left
	walk_up
	walk_up
	face_down
	step_end

NeBarkTownLab_Movement_PlayerWalkToCop:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	face_right
	step_end

NewBarkTown_Lab_Movement_CopLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_Lab_Movement_PlayerStepsToElm:
	walk_right
	face_up
	step_end

NewBarkTown_Lab_Movement_ElmStepBack:
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

NewBarkTown_Lab_Movement_ElmStepForward:
	walk_fast_down
	step_end

NewBarkTown_Lab_Text_ShouldntTouch:
	.string "¡Mejor no tocarlo!$"

NewBarkTown_Lab_Text_ElmIntro:
	.string "ELM: ¡{PLAYER}! ¡Aquí estás!\p"
	.string "Tenía que pedirte un favor.\p"
	.string "Ahora mismo estoy haciendo una nueva\n"
	.string "investigación sobre POKéMON. Me\l"
	.string "preguntaba si podrías ayudarme,\l"
	.string "{PLAYER}.\p"
	.string "Verás…\p"
	.string "Estoy escribiendo un artículo que\n"
	.string "quiero presentar en un congreso.\p"
	.string "Pero hay cosas que todavía no acabo\n"
	.string "de entender.\p"
	.string "¡Así que!\p"
	.string "Me gustaría que criaras a un POKéMON\n"
	.string "que he atrapado hace poco.$"

NewBarkTown_Lab_Text_ElmAccepted:
	.string "¡Gracias, {PLAYER}! ¡Eres de gran\n"
	.string "ayuda!$"

NewBarkTown_Lab_Text_ElmRefused:
	.string "Pero… ¡por favor, ayúdame!$"

NewBarkTown_Lab_Text_ElmResearchAmbitions:
	.string "Cuando anuncie mis descubrimientos,\n"
	.string "estoy seguro de que profundizaremos\p"
	.string "en los muchos misterios de los\n"
	.string "POKéMON.\p"
	.string "¡Puedes contar con ello!$"

NewBarkTown_Lab_Text_ElmGotAnEmail:
	.string "¡Anda! ¡Me ha llegado un correo!\p"
	.string "… … … … … … … …\n"
	.string "Mmm… Ajá…\p"
	.string "Vale…$"

NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
	.string "Oye, escucha.\p"
	.string "Tengo un conocido llamado SR.\n"
	.string "POKéMON.\p"
	.string "No para de encontrar cosas raras y de\n"
	.string "presumir de sus descubrimientos.\p"
	.string "El caso es que me acaba de mandar un\n"
	.string "correo diciendo que esta vez va en\l"
	.string "serio.\p"
	.string "Es intrigante, pero estamos muy\n"
	.string "ocupados con nuestra investigación\l"
	.string "sobre POKéMON…\p"
	.string "¡Espera! ¡Ya lo sé!\p"
	.string "{PLAYER}, ¿puedes ir tú en nuestro\n"
	.string "lugar?$"

NewBarkTown_Lab_Text_ElmChooseAPokemon:
	.string "Quiero que críes a uno de los POKéMON\n"
	.string "de estas BALLS.\p"
	.string "¡Serás el primer compañero de ese\n"
	.string "POKéMON, {PLAYER}!\p"
	.string "Vamos. ¡Elige uno!$"

NewBarkTown_Lab_Text_ElmWhereGoing:
	.string "ELM: ¡Espera! ¿Adónde vas?$"

NewBarkTown_Lab_Text_ChooseCyndaquil:
	.string "ELM: ¿Te quedas con {STR_VAR_1}, el\n"
	.string "POKéMON {STR_VAR_2}?$"

NewBarkTown_Lab_Text_ChooseTotodile:
	.string "ELM: ¿Quieres a {STR_VAR_1}, el\n"
	.string "POKéMON {STR_VAR_2}?$"

NewBarkTown_Lab_Text_ChooseChikorita:
	.string "ELM: Así que te gusta {STR_VAR_1}, el\n"
	.string "POKéMON {STR_VAR_2}, ¿eh?$"

NewBarkTown_Lab_Text_DidntChooseStarter:
	.string "ELM: Piénsalo bien.\p"
	.string "Tu compañero es importante.$"

NewBarkTown_Lab_Text_ChoseStarter:
	.string "ELM: ¡Yo también creo que es un\n"
	.string "POKéMON genial!$"

NewBarkTown_Lab_Text_ReceivedStarter:
	.string "¡{PLAYER} recibió a {STR_VAR_1}!$"

NewBarkTown_Lab_Text_Nickname:
	.string "¿Quieres ponerle un mote a tu\n"
	.string "{STR_VAR_1}?$"

NewBarkTown_Lab_Text_ElmDirections1:
	.string "El SR. POKéMON vive un poco más allá de\n"
	.string "CIUDAD CEREZO, la ciudad de al lado.\p"
	.string "El camino es casi recto, así que no\n"
	.string "tiene pérdida.\p"
	.string "Pero, por si acaso, tienes mi número de\n"
	.string "teléfono. ¡Llámame si pasa algo!$"

NewBarkTown_Lab_Text_ElmDirections1_Register:
	.string "El SR. POKéMON vive un poco más allá de\n"
	.string "CIUDAD CEREZO, la ciudad de al lado.\p"
	.string "El camino es casi recto, así que no\n"
	.string "tiene pérdida.\p"
	.string "Pero, por si acaso, aquí tienes mi\n"
	.string "número de teléfono. ¡Llámame si pasa\l"
	.string "algo!$"

NewBarkTown_Lab_Text_RegisteredElm:
	.string "Has registrado al PROF. ELM en el\n"
	.string "POKéGEAR.$"


NewBarkTown_Lab_Text_ElmLetYourMonBattle:
	.string "Si aparece un POKéMON salvaje, haz\n"
	.string "que tu POKéMON luche contra él.$"

NewBarkTown_Lab_Text_ElmDirections2:
	.string "¡Si aparece un POKéMON salvaje, deja\n"
	.string "que tu POKéMON luche contra él!\p"
	.string "Si tu POKéMON está herido, cúralo con\n"
	.string "la máquina que hay a mi derecha o en el\l"
	.string "CENTRO POKéMON.\p"
	.string "¡Cuento contigo!$"

NewBarkTown_Lab_Text_GotElmsNumber:
	.string "{PLAYER} anotó el número de ELM.$"

NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
	.string "El SR. POKéMON va a todas partes y\n"
	.string "encuentra rarezas.\p"
	.string "Lástima que solo sean raras y no muy\n"
	.string "útiles…$"

NewBarkTown_Lab_Text_ElmPokeBall:
	.string "Contiene un POKéMON atrapado por el\n"
	.string "PROF. ELM.$"

@THEFT================================================================================

NewBarkTown_Lab_Text_ElmAfterTheft1:
	.string "ELM: {PLAYER}, esto es terrible…\p"
	.string "Ah, sí, ¿cuál era el gran\n"
	.string "descubrimiento del SR. POKéMON?$"

NewBarkTown_Lab_Text_ElmAfterTheft2:
	.string "{PLAYER} le dio el HUEVO MISTERIOSO al\n"
	.string "PROF. ELM.$"

NewBarkTown_Lab_Text_ElmAfterTheft3:
	.string "ELM: ¿Esto?$"

NewBarkTown_Lab_Text_ElmAfterTheft4:
	.string "Pero… ¿Es un HUEVO POKéMON?\p"
	.string "Si lo es, ¡es un gran descubrimiento!\p"
	.string "ELM: ¿¡Qué!?\p"
	.string "¿El PROF. OAK te ha dado una POKéDEX?\p"
	.string "{PLAYER}, ¿es verdad? ¡E-es increíble!\p"
	.string "Tiene un don para ver el potencial de\n"
	.string "la gente como ENTRENADORES.\p"
	.string "Vaya, {PLAYER}. Puede que tengas lo\n"
	.string "necesario para ser CAMPEÓN.\p"
	.string "Y parece que también te llevas muy\n"
	.string "bien con los POKéMON.\p"
	.string "Deberías enfrentarte al desafío de\n"
	.string "los GIMNASIOS POKéMON.\p"
	.string "El GIMNASIO más cercano es el de\n"
	.string "CIUDAD MALVA.\p"
	.string "… {PLAYER}. El camino hacia el\n"
	.string "campeonato será largo.\p"
	.string "Antes de irte, no olvides hablar con tu\n"
	.string "madre.$"

NewBarkTown_Lab_Text_ElmStudyingEgg:
	.string "ELM: ¡No te rindas! Si sé algo sobre\n"
	.string "ese HUEVO, te llamaré.$"

NewBarkTown_Lab_Text_ElmAideHasEgg:
	.string "ELM: ¿{PLAYER}? ¿No te has encontrado\n"
	.string "con mi ayudante?\p"
	.string "Tendría que haberte dado el HUEVO en\n"
	.string "el\p"
	.string "CENTRO POKéMON de CIUDAD MALVA.\p"
	.string "Quizá os habéis cruzado sin veros.\n"
	.string "Intenta encontrarlo allí.$"

NewBarkTown_Lab_Text_ElmWaitingEggHatch:
	.string "ELM: ¿Alguna novedad?$"

NewBarkTown_Lab_Text_ElmThoughtEggHatched:
	.string "¿{PLAYER}? Creía que el HUEVO había\n"
	.string "eclosionado.\p"
	.string "¿Dónde está el POKéMON?$"

NewBarkTown_Lab_Text_ShowTogepi1:
	.string "ELM: ¡{PLAYER}, tienes muy buen\n"
	.string "aspecto!$"

NewBarkTown_Lab_Text_ShowTogepi2:
	.string "¿Qué? ¿¡Ese POKéMON!?$"

NewBarkTown_Lab_Text_ShowTogepi3:
	.string "¡El HUEVO se abrió! Los POKéMON deben\n"
	.string "nacer así.\p"
	.string "Quizá no todos los POKéMON.\p"
	.string "¡Uauu! Aún nos queda mucho por\n"
	.string "aprender.$"

NewBarkTown_Lab_Text_ElmGiveEverstone1:
	.string "¡Gracias, {PLAYER}! ¡Nos estás\n"
	.string "ayudando a desvelar los misterios de\l"
	.string "los POKéMON!\p"
	.string "Quiero que te quedes esto como\n"
	.string "muestra de nuestro agradecimiento.$"

NewBarkTown_Lab_Text_ElmGiveEverstone2:
	.string "Eso es una PIEDRAETERNA.\p"
	.string "Algunos POKéMON evolucionan al\n"
	.string "alcanzar ciertos niveles.\p"
	.string "Si un POKéMON va equipado con la\p"
	.string "PIEDRAETERNA, no evolucionará.\p"
	.string "Dásela al POKéMON que no quieras que\n"
	.string "evolucione.$"

NewBarkTown_Lab_Text_ElmCallYou:
	.string "ELM: {PLAYER}, te llamaré si pasa algo.$"

NewBarkTown_Lab_Text_AideAfterTheft:
	.string "(Suspiro…)\p"
	.string "El POKéMON robado…\p"
	.string "Me pregunto cómo estará.\p"
	.string "Dicen que los POKéMON educados por\n"
	.string "malas personas se vuelven malos.$"

NewBarkTown_Lab_Text_ElmGiveMasterBall1:
	.string "ELM: ¡Hola, {PLAYER}!\p"
	.string "¡Gracias a ti, mi investigación va de\n"
	.string "maravilla!\p"
	.string "Acepta esto como muestra de mi\n"
	.string "agradecimiento.$"

NewBarkTown_Lab_Text_ElmGiveMasterBall2:
	.string "¡La MASTER BALL es la mejor!\p"
	.string "¡Es la BALL definitiva! Atrapa\n"
	.string "cualquier POKéMON sin fallar.\p"
	.string "Solo se la dan a investigadores de\n"
	.string "POKéMON reconocidos.\p"
	.string "¡Creo que tú le sacarás mucho más\n"
	.string "partido que yo, {PLAYER}!$"

NewBarkTown_Lab_Text_KimonoGirls:
	.string "Por cierto… Un grupo de preciosas\n"
	.string "CHICAS KIMONO te estaba buscando.\p"
	.string "Me dijeron que te esperan en el TEATRO\n"
	.string "DE DANZA de CIUDAD IRIS.\p"
	.string "Sé que has pasado por muchas cosas\n"
	.string "desde que ese HUEVO te metió en todo\l"
	.string "esto…\p"
	.string "Espero que llegues hasta el final.$"

NewBarkTown_Lab_Text_KimonoWaiting:
	.string "PROF. ELM: Las CHICAS KIMONO te\n"
	.string "esperan en el TEATRO DE DANZA de\l"
	.string "CIUDAD IRIS.$"

NewBarkTown_Lab_Text_League:
	.string "PROF. ELM: Jajaja… ¡Buen trabajo!\p"
	.string "Ese HUEVO tan raro te ha dado muchos\n"
	.string "quebraderos de cabeza, ¿eh?\p"
	.string "¿Las CHICAS KIMONO dijeron algo de\n"
	.string "mí?\p"
	.string "Yo no tengo nada que ver.\p"
	.string "Tú tomaste tu decisión y la llevaste\n"
	.string "hasta el final.\p"
	.string "Después de todo lo que has hecho, ¡ya\n"
	.string "deberías poder enfrentarte a la LIGA!\p"
	.string "¡Deberías ir a la MESETA AÑIL!\p"
	.string "¿Sabes cómo llegar? Sigue la RUTA 27\n"
	.string "hasta la RUTA 26.\p"
	.string "Y, una vez allí, ¡todo recto hacia el\n"
	.string "norte!$"


NewBarkTown_Lab_Text_ElmGiveTicket1:
	.string "ELM: ¡{PLAYER}! ¡Aquí estás!\p"
	.string "Te he llamado porque tengo algo para\n"
	.string "ti.\p"
	.string "¿Lo ves? Es un TICKET BARCO.\p"
	.string "Ahora podrás atrapar POKéMON en\n"
	.string "KANTO.$"

NewBarkTown_Lab_Text_ElmGiveTicket2:
	.string "El barco sale de CIUDAD OLIVO.\p"
	.string "Pero eso ya lo sabías, {PLAYER}.\p"
	.string "Al fin y al cabo, has viajado por todas\n"
	.string "partes con tus POKéMON.\p"
	.string "¡Dale recuerdos al PROF. OAK en KANTO!$"

NewBarkTown_Lab_Text_LabMonEgg:
	.string "Es el HUEVO POKéMON que está\n"
	.string "estudiando el PROF. ELM.$"

NewBarkTown_Lab_Text_AideGivePotion:
	.string "{PLAYER}, quiero que te quedes esto\n"
	.string "para tu recado.$"

NewBarkTown_Lab_Text_AideAlwaysBusy:
	.string "Solo somos tres, así que siempre\n"
	.string "estamos ocupados.$"

NewBarkTown_Lab_Text_AideSave:
	.string "¡No te olvides de guardar la partida a\n"
	.string "menudo!\p"
	.string "¡Pulsa el botón START y luego GUARDAR!$"

NewBarkTown_Lab_Text_AideTheftTestimony:
	.string "Oímos un ruido muy fuerte…\p"
	.string "Y cuando salimos a mirar, alguien nos\n"
	.string "robó un POKéMON.\p"
	.string "¡Es horrible que alguien hiciera eso!\p"
	.string "(Suspiro…)\p"
	.string "El POKéMON robado…\p"
	.string "Me pregunto cómo estará.\p"
	.string "Dicen que los POKéMON educados por\n"
	.string "malas personas se vuelven malos.$"

NewBarkTown_Lab_Text_AideGiveBalls:
	.string "¡{PLAYER}!\p"
	.string "¡Usa esto en tu misión con la POKéDEX!$"

NewBarkTown_Lab_Text_AideExplainBalls:
	.string "Atrapa POKéMON para completar tu\n"
	.string "POKéDEX.\p"
	.string "Atrapa POKéMON salvajes usando las\n"
	.string "POKé BALL.$"

NewBarkTown_Lab_Text_Officer1:
	.string "Dicen que han robado un POKéMON.\p"
	.string "Y acabo de recibir cierta información\n"
	.string "del PROF. ELM.\p"
	.string "Parece que fue un joven pelirrojo, de\n"
	.string "pelo largo.\p"
	.string "¿Qué?\p"
	.string "¿Que tú te has enfrentado a un\n"
	.string "entrenador así?\p"
	.string "¿Y sabes cómo se llama?$"

NewBarkTown_Lab_Text_Officer2_1:
	.string "¡Vale! ¿Así que se llamaba {RIVAL}?$"

NewBarkTown_Lab_Text_Officer2:
	.string "¡Gracias por ayudar en la\n"
	.string "investigación!$"

NewBarkTown_Lab_Text_OfficerNo:
	.string "¿¡Seguro que te dijo su nombre!?$"

NewBarkTown_Lab_Text_Elm_CallMe:
	.string "¡Ah, {PLAYER}!\p"
	.string "¿Qué tal va tu POKéDEX? Ahora estoy\n"
	.string "ocupado, pero llámame algún día y\l"
	.string "miraré tus progresos.$"
