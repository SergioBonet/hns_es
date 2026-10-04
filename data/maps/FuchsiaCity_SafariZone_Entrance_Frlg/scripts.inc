FuchsiaCity_SafariZone_Entrance_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_SafariZone_Entrance_OnFrame
	.byte 0

FuchsiaCity_SafariZone_Entrance_OnFrame::
	map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 1, FuchsiaCity_SafariZone_Entrance_EventScript_ExitWarpIn
	map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 2, FuchsiaCity_SafariZone_Entrance_EventScript_ExitEarly
	map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 3, FuchsiaCity_SafariZone_Entrance_EventScript_ExitWalkIn
	.2byte 0

@ When player runs out of balls mid-battle
FuchsiaCity_SafariZone_Entrance_EventScript_ExitWalkIn::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ApproachCounter
	waitmovement 0
	msgbox FuchsiaCity_SafariZone_Entrance_Text_CatchFairShareComeAgain
	closemessage
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_Exit2
	waitmovement 0
	special ExitSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
	releaseall
	end

@ When player runs of out balls after catching a pokemon, or runs out of steps
FuchsiaCity_SafariZone_Entrance_EventScript_ExitWarpIn::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FuchsiaCity_SafariZone_Entrance_Text_CatchFairShareComeAgain
	closemessage
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_Exit
	waitmovement 0
	special ExitSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
	releaseall
	end

@ When player re-enters the entrance building with balls/steps remaining
FuchsiaCity_SafariZone_Entrance_EventScript_ExitEarly::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FuchsiaCity_SafariZone_Entrance_Text_GoingToLeaveSafariZoneEarly, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FuchsiaCity_SafariZone_Entrance_EventScript_ReturnToSafariZone
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PleaseReturnSafariBalls
	closemessage
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_Exit
	waitmovement 0
	special ExitSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
	releaseall
	end

FuchsiaCity_SafariZone_Entrance_EventScript_ReturnToSafariZone::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_GoodLuck
	closemessage
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ReEnter
	waitmovement 0
	warp MAP_SAFARI_ZONE_CENTER, 26, 30
	waitstate
	end

FuchsiaCity_SafariZone_Entrance_Movement_Exit::
	walk_down
	walk_down
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_ReEnter::
	walk_up
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_Exit2::
	walk_down
	walk_down
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_ApproachCounter::
	walk_down
	delay_8
	step_end

FuchsiaCity_SafariZone_Entrance_EventScript_EntryTriggerMid::
	lockall
	setvar VAR_TEMP_2, 0
	goto FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone
	end

FuchsiaCity_SafariZone_Entrance_EventScript_EntryTriggerRight::
	lockall
	setvar VAR_TEMP_2, 1
	goto FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone
	end

FuchsiaCity_SafariZone_Entrance_EventScript_EntryTriggerLeft::
	lockall
	setvar VAR_TEMP_2, 2
	goto FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone
	end

FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FuchsiaCity_SafariZone_Entrance_Text_WelcomeToSafariZone
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PlaySafariGameFor500, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZone_Entrance_EventScript_TryEnterSafariZone
	msgbox FuchsiaCity_SafariZone_Entrance_Text_OkayPleaseComeAgain
	goto FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack
	end

FuchsiaCity_SafariZone_Entrance_EventScript_TryEnterSafariZone::
	call FuchsiaCity_SafariZone_Entrance_EventScript_CheckSpaceForMons
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZone_Entrance_EventScript_NotEnoughMoney
	removemoney 500
	updatemoneybox
	msgbox FuchsiaCity_SafariZone_Entrance_Text_ThatllBe500WeOnlyUseSpecialBalls
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message FuchsiaCity_SafariZone_Entrance_Text_PlayerReceived30SafariBalls
	waitfanfare
	call EventScript_RestorePrevTextColor
	msgbox FuchsiaCity_SafariZone_Entrance_Text_CallYouOnPAWhenYouRunOut
	closemessage
	hidemoneybox
	call_if_eq VAR_TEMP_2, 0, FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneMid
	call_if_eq VAR_TEMP_2, 1, FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneRight
	call_if_eq VAR_TEMP_2, 2, FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneLeft
	special EnterSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 2
	warp MAP_SAFARI_ZONE_CENTER, 255, 26, 30
	waitstate
	end

FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneRight::
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneRight
	waitmovement 0
	return

FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneMid::
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneMid
	waitmovement 0
	return

FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneLeft::
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneLeft
	waitmovement 0
	return

FuchsiaCity_SafariZone_Entrance_EventScript_CheckSpaceForMons::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, Common_EventScript_NopReturn
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NopReturn
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull
	goto FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack
	end

FuchsiaCity_SafariZone_Entrance_EventScript_NotEnoughMoney::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_OopsNotEnoughMoney
	goto FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack
	end

FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack::
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ForceBack
	waitmovement 0
	releaseall
	end

FuchsiaCity_SafariZone_Entrance_Movement_ForceBack::
	walk_down
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneMid::
	walk_up
	walk_up
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneRight::
	walk_up
	walk_left
	walk_up
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneLeft::
	walk_up
	walk_right
	walk_up
	step_end

FuchsiaCity_SafariZone_Entrance_EventScript_InfoAttendant::
	lock
	faceplayer
	msgbox FuchsiaCity_SafariZone_Entrance_Text_FirstTimeAtSafariZone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZone_Entrance_EventScript_ExplainSafariZone
	msgbox FuchsiaCity_SafariZone_Entrance_Text_SorryYoureARegularHere
	release
	end

FuchsiaCity_SafariZone_Entrance_EventScript_ExplainSafariZone::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_ExplainSafariZone
	release
	end

FuchsiaCity_SafariZone_Entrance_Text_WelcomeToSafariZone::
	.string "¡Ésta es la ZONA del SAFARI!$"

FuchsiaCity_SafariZone_Entrance_Text_PlaySafariGameFor500::
	.string "¡Por sólo 500¥, podrás atrapar a\n"
	.string "todos los POKéMON que quieras\l"
	.string "en el parque!\p"
	.string "¿Te gustaría probar?$"

FuchsiaCity_SafariZone_Entrance_Text_ThatllBe500WeOnlyUseSpecialBalls::
	.string "¡Son 500¥, por favor!\p"
	.string "Aquí sólo usamos un tipo\n"
	.string "concreto de POKé BALL.$"

FuchsiaCity_SafariZone_Entrance_Text_PlayerReceived30SafariBalls::
	.string "¡{PLAYER} obtuvo 30 SAFARI BALLS\n"
	.string "del recepcionista!$"

FuchsiaCity_SafariZone_Entrance_Text_CallYouOnPAWhenYouRunOut::
	.string "¡Te avisaremos cuando se agoten\n"
	.string "tus SAFARI BALLS o tu tiempo!\p"
	.string "¡Que te vaya muy bien!$"

FuchsiaCity_SafariZone_Entrance_Text_OkayPleaseComeAgain::
	.string "¡Bien!\n"
	.string "¡Vuelve cuando quieras!$"

FuchsiaCity_SafariZone_Entrance_Text_OopsNotEnoughMoney::
	.string "¡Vaya!\n"
	.string "¡No tienes suficiente dinero!$"

FuchsiaCity_SafariZone_Entrance_Text_GoingToLeaveSafariZoneEarly::
	.string "¿Ya te vas de la ZONA del\n"
	.string "SAFARI?$"

FuchsiaCity_SafariZone_Entrance_Text_PleaseReturnSafariBalls::
	.string "Devuelve las SAFARI BALLS\n"
	.string "que te sobren.$"

FuchsiaCity_SafariZone_Entrance_Text_GoodLuck::
	.string "¡Buena suerte!$"

FuchsiaCity_SafariZone_Entrance_Text_CatchFairShareComeAgain::
	.string "¿Has capturado tu parte?\n"
	.string "¡Vuelve cuando quieras!$"

FuchsiaCity_SafariZone_Entrance_Text_FirstTimeAtSafariZone::
	.string "¡Hola!\n"
	.string "¿Es tu primera vez aquí?$"

FuchsiaCity_SafariZone_Entrance_Text_ExplainSafariZone::
	.string "La ZONA del SAFARI tiene 4 ZONAS.\p"
	.string "Cada zona tiene diferentes tipos de\n"
	.string "POKéMON, y algunos son raros.\p"
	.string "¡Usa las SAFARI BALLS para\n"
	.string "atraparlos!\p"
	.string "¡También podrás usar CEBO\n"
	.string "y ROCAS para atraerlos!\p"
	.string "¡Si tiras CEBO, será difícil que\n"
	.string "escapen, pero te costará más\l"
	.string "atraparlos!\p"
	.string "¡Si tiras ROCAS, será fácil que\n"
	.string "escapen, pero te costará menos\l"
	.string "atraparlos!\p"
	.string "¡Cuando se te acabe el tiempo\n"
	.string "o las SAFARI BALLS, el juego\l"
	.string "se dará por terminado!$"

FuchsiaCity_SafariZone_Entrance_Text_SorryYoureARegularHere::
	.string "¡Lo siento, eres un habitual!$"

