SSAqua_RoomSSE_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSAqua_RoomSSE_OnFrame
    map_script MAP_SCRIPT_ON_TRANSITION, SSAqua_RoomSSE_OnTransition
	.byte 0

SSAqua_RoomSSE_OnTransition::
    goto_if_ge VAR_SSAQUA_STATE, 5, SSAqua_RoomSSE_SetGirlPos
    end

SSAqua_RoomSSE_OnFrame::
	map_script_2 VAR_SSAQUA_STATE, 4, SSAqua_RoomSSE_EventScript_ReuinionScene
	.2byte 0

SSAqua_RoomSSE_SetGirlPos::
    setobjectxyperm LOCALID_SSAQUA_ROOM_SSE_GRANDDAUGTHER, 2, 4
    setobjectmovementtype LOCALID_SSAQUA_ROOM_SSE_GRANDDAUGTHER, MOVEMENT_TYPE_FACE_LEFT
    end

SSAqua_RoomSSE_EventScript_ReuinionScene::
	lock
    turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
    turnobject LOCALID_SSAQUA_ROOM_SSE_GRANDFATHER, DIR_SOUTH
    playse SE_PIN
    applymovement LOCALID_SSAQUA_ROOM_SSE_GRANDFATHER, Common_Movement_ExclamationMark
    delay 55
    waitmovement LOCALID_SSAQUA_ROOM_SSE_GRANDFATHER
	applymovement LOCALID_SSAQUA_ROOM_SSE_GRANDDAUGTHER, SSAqua_RoomSSE_Movement_GirlEnter
    waitmovement 0
    turnobject LOCALID_SSAQUA_ROOM_SSE_GRANDFATHER, DIR_EAST
    msgbox SSAqua_RoomSSE_Text_GranddaughterWasPlaying, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, SSAqua_RoomSSE_Movement_PlayerEnter
    waitmovement 0
    turnobject LOCALID_SSAQUA_ROOM_SSE_GRANDFATHER, DIR_SOUTH
    msgbox SSAqua_RoomSSE_Text_EntertainedGranddaughter, MSGBOX_DEFAULT
    msgbox SSAqua_RoomSSE_Text_GrandpaHaveThis, MSGBOX_DEFAULT
    giveitem ITEM_METAL_COAT
    closemessage
	setvar VAR_SSAQUA_STATE, 5
	release
	end

SSAqua_RoomSSE_EventScript_Grandpa::
	lock
	faceplayer
	goto_if_ge VAR_SSAQUA_STATE, 4, SSAqua_RoomSSE_EventScript_GrandpaAfter
	msgbox SSAqua_RoomSSE_Text_CantFindGranddaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_RoomSSE_EventScript_GrandpaAfter::
	msgbox SSAqua_RoomSSE_Text_GrandpaTravelling, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_RoomSSE_EventScript_GrandDaughter::
	msgbox SSAqua_RoomSSE_Text_GranddaughterHadFun, MSGBOX_NPC
	end

SSAqua_RoomSSE_Movement_GirlEnter:
    walk_up
    walk_up
    walk_left
    step_end

SSAqua_RoomSSE_Movement_PlayerEnter:
    walk_up
    walk_left
    walk_left
    walk_up
    step_end

SSAqua_RoomSSE_Text_CantFindGranddaughter:
	.string "Ah, hola…\p"
	.string "Todavía no encuentro a mi nieta.\p"
	.string "Si está en el barco, no pasa nada.\p"
	.string "Es una niña muy movida, así que quizá\n"
	.string "esté molestando a alguien. Estoy\l"
	.string "preocupado…$"

SSAqua_RoomSSE_Text_EntertainedGranddaughter:
	.string "¿{PLAYER}, era? He oído que has\n"
	.string "entretenido a mi nieta.\p"
	.string "Quiero darte las gracias por ello.$"

SSAqua_RoomSSE_Text_GrandpaHaveThis:
	.string "¡Me gustaría que tuvieras esto!$"

SSAqua_RoomSSE_Text_GrandpaTravelling:
	.string "Estamos viajando por todo el mundo.$"

SSAqua_RoomSSE_Text_GranddaughterWasPlaying:
	.string "¡Abuelo, estoy aquí! ¡Estaba jugando\n"
	.string "con el CAPITÁN y con esta persona!$"

SSAqua_RoomSSE_Text_GranddaughterHadFun:
	.string "¡Me he divertido mucho jugando!$"
