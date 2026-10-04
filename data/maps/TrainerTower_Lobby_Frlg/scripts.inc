TrainerTower_Lobby_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerTower_Lobby_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerTower_Lobby_OnReturnToField
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerTower_Lobby_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerTower_Lobby_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerTower_Lobby_OnFrame
	.byte 0

TrainerTower_Lobby_OnResume::
	setvar VAR_TEMP_2, 0
	ttower_resumetimer
	ttower_shouldexit
	goto_if_eq VAR_RESULT, FALSE, TrainerTower_Lobby_OnResumeEnd
	@ Never reached, above always FALSE
	setvar VAR_TEMP_0, 0
	setobjectxy LOCALID_PLAYER, 9, 7
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
TrainerTower_Lobby_OnResumeEnd::
	end

TrainerTower_Lobby_OnReturnToField::
	addobject LOCALID_TOWER_NURSE
	addobject LOCALID_TOWER_MART_CLERK
	addobject LOCALID_TOWER_RECEPTIONIST
	addobject LOCALID_TOWER_COOLTRAINER_F
	addobject LOCALID_TOWER_BALDING_MAN
	end

TrainerTower_Lobby_OnLoad::
	call_if_eq VAR_TEMP_D, 17, TrainerTower_Lobby_OpenCounterBarrier
	end

TrainerTower_Lobby_OpenCounterBarrier::
	setmetatile 17, 10, METATILE_TrainerTower_Floor_ShadeBottomLeft, 0
	return

TrainerTower_Lobby_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_TRAINER_TOWER_LOBBY
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

TrainerTower_Lobby_OnFrame::
	map_script_2 VAR_TEMP_0, 0, TrainerTower_Lobby_EventScript_Enter
	map_script_2 VAR_TEMP_D, 17, TrainerTower_Lobby_EventScript_ExitElevator
	.2byte 0

TrainerTower_Lobby_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_ExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerTower_CounterBarrier, 1
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerTower_Lobby_Movement_ExitElevator::
	walk_down
	walk_down
	step_end

TrainerTower_Lobby_EventScript_Enter::
	setvar VAR_TEMP_0, 1
	ttower_getchallengestatus
	switch VAR_RESULT
	case TT_CHALLENGE_STATUS_LOST, TrainerTower_Lobby_EventScript_LostChallenge
	case TT_CHALLENGE_STATUS_UNK, TrainerTower_Lobby_EventScript_ExitChallengeSpeakToReceptionist
	case TT_CHALLENGE_STATUS_NORMAL, TrainerTower_Lobby_EventScript_EnterEnd

TrainerTower_Lobby_EventScript_LostChallenge::
	lock
	faceplayer
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox TrainerTower_Lobby_Text_TooBadComeBackTryAgain
	goto TrainerTower_Lobby_EventScript_ExitChallenge

@ Presumably E-Reader related
TrainerTower_Lobby_EventScript_ExitChallengeSpeakToReceptionist::
	lock
	faceplayer
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox TrainerTower_Lobby_Text_MoveCounterHereWhenTrainersSwitch
TrainerTower_Lobby_EventScript_ExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_WalkDown
	waitmovement 0
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 0
	release
TrainerTower_Lobby_EventScript_EnterEnd::
	end

TrainerTower_Lobby_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

TrainerTower_Lobby_EventScript_Receptionist::
	lock
	faceplayer
	ttower_getbeatchallenge
	goto_if_eq VAR_RESULT, TRUE, TrainerTower_Lobby_EventScript_ThanksForCompeting
	msgbox TrainerTower_Lobby_Text_GiveItYourBest
	goto TrainerTower_Lobby_EventScript_ReceptionistEnd

TrainerTower_Lobby_EventScript_ThanksForCompeting::
	msgbox TrainerTower_Lobby_Text_ThanksForCompeting
TrainerTower_Lobby_EventScript_ReceptionistEnd::
	release
	end

TrainerTower_Lobby_EventScript_MartClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart TrainerTower_Lobby_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TrainerTower_Lobby_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

TrainerTower_Lobby_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox TrainerTower_Lobby_Text_WelcomeToTrainerTower
	ttower_getnumfloors
	goto_if_eq VAR_RESULT, FALSE, TrainerTower_Lobby_EventScript_AllFloorsUsed
	msgbox TrainerTower_Lobby_Text_TrainersUpToFloorNum
	goto TrainerTower_Lobby_EventScript_AskEnterChallenge

TrainerTower_Lobby_EventScript_AllFloorsUsed::
	msgbox TrainerTower_Lobby_Text_TrainersUpEighthFloor
TrainerTower_Lobby_EventScript_AskEnterChallenge::
	message TrainerTower_Lobby_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 18, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerTower_Lobby_EventScript_ChooseChallenge
	case 1, TrainerTower_Lobby_EventScript_DeclineChallenge
	case 2, TrainerTower_Lobby_EventScript_ChallengeInfo
	case MULTI_B_PRESSED, TrainerTower_Lobby_EventScript_DeclineChallenge
	end

TrainerTower_Lobby_EventScript_ChallengeInfo::
	msgbox TrainerTower_Lobby_Text_ExplainTrainerTower
	goto TrainerTower_Lobby_EventScript_AskEnterChallenge
	end

TrainerTower_Lobby_EventScript_ChooseChallenge::
	multichoice 13, 3, MULTI_TRAINER_TOWER_MODE, FALSE
	switch VAR_RESULT
	case 0, TrainerTower_Lobby_EventScript_BeginChallenge
	case 1, TrainerTower_Lobby_EventScript_BeginChallenge
	case 2, TrainerTower_Lobby_EventScript_BeginChallenge
	case 3, TrainerTower_Lobby_EventScript_BeginChallenge
	case 4, TrainerTower_Lobby_EventScript_DeclineChallenge
	case MULTI_B_PRESSED, TrainerTower_Lobby_EventScript_DeclineChallenge
	end

TrainerTower_Lobby_EventScript_BeginChallenge::
	copyvar VAR_0x8005, VAR_RESULT
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 1
	special HealPlayerParty
	msgbox TrainerTower_Lobby_Text_StartClockGetSetGo
	ttower_startchallenge
	releaseall
	end

TrainerTower_Lobby_EventScript_DeclineChallenge::
	msgbox TrainerTower_Lobby_Text_PleaseVisitUsAgain
	closemessage
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_WalkDown
	waitmovement 0
	releaseall
	end

TrainerTower_Lobby_Movement_FaceReceptionist::
	face_right
	step_end

TrainerTower_Lobby_Movement_WalkDown::
	walk_down
	step_end

TrainerTower_Lobby_EventScript_ShowRecords::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 1
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerTower_Lobby_EventScript_CooltrainerF::
	msgbox TrainerTower_Lobby_Text_WonderWhatKindsOfTrainers, MSGBOX_NPC
	end

TrainerTower_Lobby_EventScript_BaldingMan::
	msgbox TrainerTower_Lobby_Text_StairsTougherThanAnyBattle, MSGBOX_NPC
	end

@ All Trainer Tower text (Lobby and Roof) is interleaved here

TrainerTower_Lobby_Text_WelcomeToTrainerTower::
	.string "¡Hola!\p"
	.string "¡Ésta es la TORRE DESAFÍO, punto\n"
	.string "de encuentro de ENTRENADORES\l"
	.string "de todos sitios!$"

TrainerTower_Lobby_Text_TrainersUpToFloorNum::
	.string "Aquí vienen ENTRENADORES de todo\n"
	.string "el mundo para luchar.\p"
	.string "A ver, ahora mismo...\p"
	.string "Hay ENTRENADORES hasta\n"
	.string "el piso {STR_VAR_1}.$"

TrainerTower_Lobby_Text_TrainersUpEighthFloor::
	.string "Hay ENTRENADORES esperándote\n"
	.string "para luchar hasta el octavo piso.$"

TrainerTower_Lobby_Text_LikeToChallengeTrainers::
	.string "¿Quieres enfrentarte a ellos?$"

TrainerTower_Lobby_Text_StartClockGetSetGo::
	.string "Vale, pongo en marcha el reloj,\n"
	.string "así que dalo todo.\p"
	.string "En sus marcas…\p"
	.string "Listos…\n"
	.string "¡Ya!$"

TrainerTower_Lobby_Text_PleaseVisitUsAgain::
	.string "¡Vuelve cuando quieras!$"

TrainerTower_Lobby_Text_TooBadComeBackTryAgain::
	.string "Qué pena…\p"
	.string "La verdad es que te has esforzado\n"
	.string "mucho.\p"
	.string "¡Bueno, otra vez será!$"

TrainerTower_Lobby_Text_GiveItYourBest::
	.string "¡Demuestra lo que sabes!$"

TrainerTower_Lobby_Text_MoveCounterHereWhenTrainersSwitch::
	.string "Cuando los ENTRENADORES se\n"
	.string "cambian de sitio, organizan una…\l"
	.string "tremenda.\p"
	.string "Para evitar tanto follón pusimos\n"
	.string "la recepción aquí.\p"
	.string "Disculpa las molestias.$"

TrainerTower_Roof_Text_ImOwnerBattledPerfectly::
	.string "Hola.\p"
	.string "Soy el dueño de esta TORRE.\p"
	.string "La forma en que el cielo se\n"
	.string "extiende por encima de nosotros...\p"
	.string "La manera en que nos acaricia\n"
	.string "el viento...\p"
	.string "¡Es una maravilla!...\p"
	.string "Y la forma en que has luchado...\n"
	.string "es también espectacular...$"

TrainerTower_Roof_Text_ThisIsForYou::
	.string "Esto es para ti...$"

TrainerTower_Roof_Text_DoneItInRecordTime::
	.string "¡Estupendo!\n"
	.string "¡Maravilloso!\p"
	.string "¡Es extraordinario que hayas\n"
	.string "llegado tan rápido!\p"
	.string "La cosa es que lo has conseguido\n"
	.string "en tiempo récord...\p"
	.string "Voy a ponerlo junto a uno de los\n"
	.string "mostradores de la recepción.$"

TrainerTower_Roof_Text_TookSweetTimeGettingHere::
	.string "Parece que te has tomado tu tiempo\n"
	.string "para llegar aquí…$"

TrainerTower_Roof_Text_IdLikeToSeeBetterTime::
	.string "Me gustaría ver que consigues\n"
	.string "un tiempo mejor...\p"
	.string "Espero que no me defraudes.\p"
	.string "Nos vemos.$"

TrainerTower_Text_XMinYZSec::
	.string "{STR_VAR_1} min {STR_VAR_2},{STR_VAR_3} s$"

TrainerTower_Lobby_Text_HereAreTheResults::
	.string "Es la tabla de resultados.$"

TrainerTower_Lobby_Text_NeedTwoMonsForDouble::
	.string "Esto es un combate doble.\p"
	.string "Si no tienes dos POKéMON,\n"
	.string "no podrás participar.$"

TrainerTower_Lobby_Text_ExplainTrainerTower::
	.string "En la TORRE DESAFÍO, se lucha\n"
	.string "a CONTRARRELOJ.\p"
	.string "Cronometraremos lo que tardes\n"
	.string "en alcanzar al DUEÑO en el último\l"
	.string "piso, en cuanto dejes la recepción.\p"
	.string "Los mejores tiempos podrán verse\n"
	.string "en el marcador.\p"
	.string "Compite con tus amigos para ver\n"
	.string "quién tarda menos.\p"
	.string "¡Ah, piensa que aquí no se ganan\n"
	.string "puntos de EXP. ni dinero!$"

TrainerTower_Lobby_Text_ThanksForCompeting::
	.string "¡Gracias por participar!$"

TrainerTower_Lobby_Text_WonderWhatKindsOfTrainers::
	.string "Yo he venido para ver lo fuerte\n"
	.string "que soy.\p"
	.string "¿Cómo serán los ENTRENADORES con\n"
	.string "los que me tendré que enfrentar?\p"
	.string "¡Qué nervios!$"

TrainerTower_Lobby_Text_StairsTougherThanAnyBattle::
	.string "Uffffff...\n"
	.string "Estoy agotado...\p"
	.string "¡No por los combates, no!\n"
	.string "¡Es por las escaleras!...\l"
	.string "¡Son peores que las peleas!$"

