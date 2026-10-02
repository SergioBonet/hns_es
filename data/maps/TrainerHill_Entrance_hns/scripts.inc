TrainerHill_Entrance_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_hns_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_hns_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_hns_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_hns_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_hns_OnFrame
	.byte 0

TrainerHill_Entrance_hns_OnTransition:
	clearflag FLAG_LIMIT_TO_50
	calculatemonstats
	setflag FLAG_TEMP_HIDE_FOLLOWER
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

TrainerHill_Entrance_hns_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_hns_EventScript_TryFaceAttendant
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 6
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_hns_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_hns_EventScript_PlayerDontFaceAttendant
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_hns_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_hns_OnReturn:
	addobject LOCALID_TRAINER_HILL_HNS_NURSE
	addobject LOCALID_TRAINER_HILL_HNS_ATTENDANT
	addobject LOCALID_TRAINER_HILL_HNS_MAN
	addobject LOCALID_TRAINER_HILL_HNS_GIRL
	end

TrainerHill_Entrance_hns_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_hns_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_hns_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_hns_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_hns_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_hns_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_hns_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_Entrance_hns_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_hns_EventScript_WarpToEntranceCounter::
	setvar VAR_TEMP_1, 0
	warp MAP_TRAINER_HILL_ENTRANCE_HNS, 9, 6
	waitstate
	end

TrainerHill_Entrance_hns_EventScript_ExitElevator::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_hns_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_hns_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_hns_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_hns_EventScript_EndExitChallenge

TrainerHill_Entrance_hns_EventScript_ExitChallengeLost::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_hns_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_hns_EventScript_PlayerExitChallenge

TrainerHill_Entrance_hns_EventScript_ExitChallengeECard::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_hns_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_hns_EventScript_PlayerExitChallenge::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	releaseall
TrainerHill_Entrance_hns_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_hns_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_HNS_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_hns_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_hns_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_hns_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_hns_EventScript_AttendantEnd

TrainerHill_Entrance_hns_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_hns_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_hns_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_hns_EventScript_EntryTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_hns_EventScript_Closed
	msgbox TrainerHill_Entrance_hns_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_hns_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_hns_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_hns_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_hns_EventScript_AskChallengeTrainers

TrainerHill_Entrance_hns_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_hns_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_hns_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_hns_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_hns_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_hns_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_hns_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_hns_EventScript_CancelEntry
	end

TrainerHill_Entrance_hns_EventScript_Info::
	msgbox TrainerHill_Entrance_hns_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_hns_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_hns_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_hns_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_hns_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox TrainerHill_Entrance_hns_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_hns_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_hns_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_hns_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_hns_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_hns_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_hns_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_hns_EventScript_CancelEntry
	end

TrainerHill_Entrance_hns_EventScript_Closed::
	msgbox TrainerHill_Entrance_hns_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_hns_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

TrainerHill_Entrance_hns_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_hns_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_hns_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_hns_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_hns_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_hns_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_Man2::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_hns_EventScript_ManTrainerHillClosed2
	msgbox TrainerHill_Entrance_hns_Text_Money, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_ManTrainerHillClosed2::
	msgbox TrainerHill_Entrance_hns_Text_HereToGetMoney, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_hns_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_hns_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_hns_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart TrainerHill_Entrance_hns_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

TrainerHill_Entrance_hns_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_hns_Pokemart_Basic:
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

TrainerHill_Entrance_hns_Text_HereToGetMoney:
	.string "¡He venido a ganar dinero! ¿Por qué?\n"
	.string "¡Porque cada vez que llegas a la cima\l"
	.string "te dan una recompensa en dinero!\p"
	.string "¿Cuándo abrirán por fin? ¡Estoy\n"
	.string "deseándolo!$"

TrainerHill_Entrance_hns_Text_Money:
	.string "Cada vez que llegas a la cima, ganas\n"
	.string "algo de dinero.\p"
	.string "¡He oído que puedes ganar hasta\n"
	.string "¥1.000.000 si terminas en menos de\l"
	.string "diez minutos!\p"
	.string "Pero si tardas más, la recompensa se\n"
	.string "reduce…$"

TrainerHill_Entrance_hns_Text_StillGettingReady:
	.string "Ésta es la COLINA DESAFÍO.\n"
	.string "Aquí podrás enfrentarte a otros\l"
	.string "ENTRENADORES en una carrera\l"
	.string "por llegar arriba lo antes posible.\p"
	.string "Por desgracia, aún no está preparado\n"
	.string "todo. Pásate por aquí en otro momento.$"

TrainerHill_Entrance_hns_Text_WelcomeToTrainerHill:
	.string "¡Te damos la bienvenida!\p"
	.string "Ésta es la COLINA DESAFÍO.\n"
	.string "Aquí podrás enfrentarte a otros\l"
	.string "ENTRENADORES en una carrera\l"
	.string "por llegar arriba lo antes posible.$"

TrainerHill_Entrance_hns_Text_SaveGameBeforeEnter:
	.string "¿Es la primera vez que vienes?\p"
	.string "Antes de entrar, debes\n"
	.string "guardar la partida.$"

TrainerHill_Entrance_hns_Text_TrainersUpToFloorX:
	.string "Veamos…\n"
	.string "Los ENTRENADORES están ahora…\p"
	.string "Hasta el nivel {STR_VAR_1}.$"

TrainerHill_Entrance_hns_Text_TrainersInEveryRoom:
	.string "Veamos…\n"
	.string "Los ENTRENADORES están ahora…\p"
	.string "¡Vaya, parece que hay ENTRENADORES\n"
	.string "en todos los niveles!$"

TrainerHill_Entrance_hns_Text_LikeToChallengeTrainers:
	.string "¿Quieres enfrentarte a ellos?$"

TrainerHill_Entrance_hns_Text_TimeProgessGetSetGo:
	.string "Cronometraré tu tiempo.\n"
	.string "¡Suerte!\p"
	.string "A la una…\p"
	.string "A las dos…\p"
	.string "¡Y a las tres!$"

TrainerHill_Entrance_hns_Text_PleaseVisitUsAgain:
	.string "¡Vuelve cuando quieras!$"

TrainerHill_Entrance_hns_Text_TooBadTremendousEffort:
	.string "Qué pena…\p"
	.string "La verdad es que te has esforzado\n"
	.string "mucho.\p"
	.string "¡Bueno, otra vez será!$"

TrainerHill_Entrance_hns_Text_HopeYouGiveItYourBest:
	.string "¡Demuestra lo que sabes!$"

TrainerHill_Entrance_hns_Text_MovedReceptionHereForSwitch:
	.string "Cuando los ENTRENADORES se\n"
	.string "cambian de sitio, organizan una…\l"
	.string "tremenda.\p"
	.string "Para evitar tanto follón pusimos\n"
	.string "la recepción aquí.\p"
	.string "Disculpa las molestias.$"

TrainerHill_Entrance_hns_Text_ThankYouForPlaying:
	.string "¡Gracias por participar!\p"
	.string "$"

TrainerHill_Entrance_hns_Text_ExplainTrainerHill:
	.string "En la COLINA DESAFÍO, los participantes\n"
	.string "compiten en la llamada “contrarreloj”.\p"
	.string "Es una carrera donde se cuenta\n"
	.string "el tiempo que tardas en llegar\l"
	.string "desde aquí hasta la azotea,\l"
	.string "donde te espera el dueño del local.\p"
	.string "Los récords de cada categoría están\n"
	.string "expuestos en el PANEL de TIEMPOS.\l"
	.string "¡Demuestra que no hay nadie\l"
	.string "más veloz que tú!\p"
	.string "En los combates que libres contra\n"
	.string "los ENTRENADORES que te encuentres\l"
	.string "en el ascenso, no ganarás ni dinero\l"
	.string "ni puntos de EXPERIENCIA.$"

TrainerHill_Entrance_hns_Text_WhatSortOfTrainersAreAhead:
	.string "No sé qué clase de ENTRENADORES\n"
	.string "y de POKéMON esperan ahí arriba.\p"
	.string "¡Lo que sí sé es que no dejaré que\n"
	.string "nadie se interponga en mi camino!$"

TrainerHill_Entrance_hns_Text_CantWaitToTestTheWaters:
	.string "He oído que a esta COLINA DESAFÍO\n"
	.string "vienen ENTRENADORES de todas partes.\p"
	.string "¡Estoy deseando probar!\p"
	.string "¡Voy a quitar de en medio a todos\n"
	.string "los que se me pongan por delante!$"

TrainerHill_Entrance_hns_Text_FriendsTryingToReachTimeBoardTop:
	.string "¿Has visto el PANEL de TIEMPOS de ahí?\p"
	.string "Mis amigos y yo estamos a ver quién\n"
	.string "consigue llegar arriba en menos tiempo.$"

TrainerHill_Entrance_hns_Text_DoYouKnowWhenTheyOpen:
	.string "¿Tienes idea de cuándo\n"
	.string "van a abrir este sitio?\p"
	.string "¡Quiero ser la primera de todos\n"
	.string "en competir aquí!$"
