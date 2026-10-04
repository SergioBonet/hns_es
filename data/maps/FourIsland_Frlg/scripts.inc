FourIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FourIsland_OnFrame
	.byte 0

FourIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FOUR_ISLAND
	call_if_eq VAR_MAP_SCENE_FOUR_ISLAND, 0, FourIsland_EventScript_ShowRival
	call FourIsland_EventScript_TrySetDayCareManPos
	end

FourIsland_EventScript_ShowRival::
	clearflag FLAG_HIDE_FOUR_ISLAND_RIVAL
	return

FourIsland_EventScript_TrySetDayCareManPos::
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, FourIsland_EventScript_EndSetDayCareManPos
	setobjectxyperm LOCALID_FOUR_ISLAND_DAYCARE_MAN, 16, 14
FourIsland_EventScript_EndSetDayCareManPos::
	return

FourIsland_OnFrame::
	map_script_2 VAR_MAP_SCENE_FOUR_ISLAND, 0, FourIsland_EventScript_RivalScene
	.2byte 0

FourIsland_EventScript_RivalScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_FOUR_ISLAND_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_FOUR_ISLAND_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOUR_ISLAND_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 25
	applymovement LOCALID_FOUR_ISLAND_RIVAL, FourIsland_Movement_RivalApproach
	waitmovement 0
	msgbox FourIsland_Text_RivalAlreadyGotEggBeSmellingYa
	closemessage
	applymovement LOCALID_PLAYER, FourIsland_Movement_PlayerWatchRivalExit
	applymovement LOCALID_FOUR_ISLAND_RIVAL, FourIsland_Movement_RivalExit
	waitmovement 0
	fadedefaultbgm
	playse SE_EXIT
	delay 35
	removeobject LOCALID_FOUR_ISLAND_RIVAL
	setvar VAR_MAP_SCENE_FOUR_ISLAND, 1
	releaseall
	end

FourIsland_Movement_RivalApproach::
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

FourIsland_Movement_RivalExit::
	delay_16
	delay_4
	walk_down
	step_end

FourIsland_Movement_PlayerWatchRivalExit::
	walk_left
	walk_in_place_faster_right
	step_end

FourIsland_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, FourIsland_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, FourIsland_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, FourIsland_EventScript_CheckOnTwoMons
	msgbox DayCare_Text_ImDaycareManSpeakToMyWife
	release
	end

FourIsland_EventScript_DaycareEggWaiting::
	msgbox DayCare_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FourIsland_EventScript_DaycareAcceptEgg
	msgbox DayCare_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FourIsland_EventScript_DaycareAcceptEgg
	msgbox DayCare_Text_IllKeepIt
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

FourIsland_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, FourIsland_EventScript_DaycareReceivedEgg
	msgbox DayCare_Text_YouHaveNoRoomForIt
	release
	end

FourIsland_EventScript_DaycareReceivedEgg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message DayCare_Text_ReceivedEgg
	call EventScript_RestorePrevTextColor
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox DayCare_Text_TakeGoodCareOfIt
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

FourIsland_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox DayCare_Text_YourMonIsDoingFine
	release
	end

FourIsland_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox DayCare_Text_YourMonsAreDoingFine
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	release
	end

FourIsland_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, FourIsland_EventScript_OldWomanLoreleiLeft
	msgbox FourIsland_Text_LoreleiHasReturned
	release
	end

FourIsland_EventScript_OldWomanLoreleiLeft::
	famechecker FAMECHECKER_LORELEI, 5
	msgbox FourIsland_Text_LoreleiMetLaprasAsChild
	release
	end

FourIsland_EventScript_LittleGirl::
	lock
	faceplayer
	famechecker FAMECHECKER_LORELEI, 4
	msgbox FourIsland_Text_LoreleiHasLotsOfStuffedDolls
	release
	end

FourIsland_EventScript_FatMan::
	msgbox FourIsland_Text_MadeSlushieUsingIcefallCaveIce, MSGBOX_NPC
	end

FourIsland_EventScript_IslandSign::
	msgbox FourIsland_Text_IslandSign, MSGBOX_SIGN
	end

FourIsland_EventScript_LoreleisHouseSign::
	msgbox FourIsland_Text_LoreleisHouse, MSGBOX_SIGN
	end

FourIsland_Text_IslandSign::
	.string "ISLA QUARTA\n"
	.string "La isla cálida, azul y rara.$"

FourIsland_Text_LoreleiHasReturned::
	.string "LORELEI ha vuelto.\p"
	.string "Creo que la vida de la ciudad le\n"
	.string "resultaba demasiado estresante...$"

FourIsland_Text_LoreleiMetLaprasAsChild::
	.string "LORELEI ha vuelto.\p"
	.string "Creo que el LAPRAS que tiene,\n"
	.string "es el mismo que atrapó de pequeña.\p"
	.string "Yo creo que se hizo con él\n"
	.string "en la CUEVA GLACIADA...\p"
	.string "Me parece que lo tiene desde\n"
	.string "entonces.$"

FourIsland_Text_RivalAlreadyGotEggBeSmellingYa::
	.string "{RIVAL}: ¡Eh, {PLAYER}!\p"
	.string "¿Qué estás haciendo en\n"
	.string "ARCHI7?\p"
	.string "Deberías dejar de copiarte de todo\n"
	.string "lo que hago.\p"
	.string "Bueno, yo ya tengo mi HUEVO\n"
	.string "POKéMON, así que no me queda\l"
	.string "nada más que hacer en esta isla.\p"
	.string "No sé ni para qué te cuento esto,\n"
	.string "seguro que no tienes ni idea de\l"
	.string "lo que es un HUEVO POKéMON.\p"
	.string "Así no vas a completar la POKéDEX\n"
	.string "NACIONAL en la vida.\p"
	.string "Por cierto, he visto a alguien a\n"
	.string "quien conocemos en la isla.\p"
	.string "¿No te das una vuelta a ver\n"
	.string "quién es?\l"
	.string "¿No te pica la curiosidad?\p"
	.string "Yo me largo, no tengo tiempo.\p"
	.string "¡Nos vemos!$"

FourIsland_Text_LoreleiHasLotsOfStuffedDolls::
	.string "¡Me has encontrado!\n"
	.string "¡No se lo digas a LORELEI!\p"
	.string "¿Sabías que LORELEI tiene un\n"
	.string "montón de muñecos de peluche?\p"
	.string "¡Cada vez que vuelve a ISLA\n"
	.string "QUARTA, aumenta la colección!$"

FourIsland_Text_MadeSlushieUsingIcefallCaveIce::
	.string "¡Uyyy, qué fresquito!\p"
	.string "Me he hecho un granizado con\n"
	.string "hielo de la CUEVA GLACIADA.\p"
	.string "¡Está fresquito y riquísimo!$"

FourIsland_Text_LoreleisHouse::
	.string "CASA DE LORELEI$"

