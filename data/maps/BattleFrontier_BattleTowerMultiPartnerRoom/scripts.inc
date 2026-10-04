BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Búscate un compañero entre los\n"
	.string "ENTRENADORES que hay aquí.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "¿{PLAYER}, aún no has encontrado\n"
	.string "un compañero para tu equipo?\p"
	.string "¿Qué pasa? ¿Quieres dejar de buscar\n"
	.string "y volver al mostrador de recepción?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Entonces, búscate un compañero entre\n"
	.string "los ENTRENADORES que hay aquí.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Bien, veo que ya tienes pareja.\p"
	.string "Te conduciré a la SALA BATALLA\n"
	.string "de COMBATES MÚLTIPLES.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "Soy el aprendiz n.º {STR_VAR_2} de\n"
	.string "{STR_VAR_1}. ¡Llámame {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "Por consejo de {STR_VAR_1}, traje\n"
	.string "un {STR_VAR_3} con {STR_VAR_2} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Por favor, ¡déjame unirme a ti en\n"
	.string "un equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "¡Gracias!\n"
	.string "Voy a registrarme ahora mismo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "Tenía muchas ganas de formar\n"
	.string "equipo contigo, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "Soy el aprendiz n.º {STR_VAR_2} de\n"
	.string "{STR_VAR_1}. Me llamo {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "Seguí el consejo de {STR_VAR_1} y elegí\n"
	.string "un {STR_VAR_3} con {STR_VAR_2} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Por favor, ¡formemos un equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "¡Muchas gracias!\n"
	.string "¡Terminaré el registro enseguida!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, esperaba poder\n"
	.string "formar equipo contigo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Eh, me llamo {STR_VAR_3} y soy el\n"
	.string "aprendiz n.º {STR_VAR_2} de {STR_VAR_1}.\p"
	.string "Snif…\p"
	.string "¡Lo siento!\n"
	.string "La tensión me hace llorar…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} me aconsejó que tuviese\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Snif…\n"
	.string "¡Por favor, déjame ser tu pareja!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "¿De verdad? ¿Me eliges a mí?\n"
	.string "¡Genial! ¡Alucinante! ¡Superguay!\p"
	.string "Oh… Perdona…\n"
	.string "Son lágrimas de felicidad…\p"
	.string "Voy corriendo a registrarnos.\n"
	.string "¡No empieces sin mí!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Oh, pe-pero…\n"
	.string "Si… ¡Buaaaaaa!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "¡Hola! ¡Soy {STR_VAR_3}, y {STR_VAR_1}\n"
	.string "me eligió como su aprendiz n.º {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "Le pedí consejo a {STR_VAR_3}.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "y un {STR_VAR_2} con {STR_VAR_1},\n"
	.string "ésa es mi pareja de POKéMON.\p"
	.string "¿Qué me dices? ¿Te interesa\n"
	.string "formar equipo conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "¡Gracias! ¡No te arrepentirás!\n"
	.string "¡Voy a registrarnos ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Como quieras, {PLAYER}, pero pocos\n"
	.string "compañeros encontrarás como yo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "Soy {STR_VAR_3}, el aprendiz n.º\n"
	.string "{STR_VAR_2} ¡del famoso {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "Pedí consejo a {STR_VAR_3}.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "y un {STR_VAR_2} con {STR_VAR_1},\n"
	.string "esa es mi pareja.\p"
	.string "¿Quieres unirte a mí\n"
	.string "en un equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "¡Gracias!\n"
	.string "¡Me registro ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, esperaba unirme\n"
	.string "a ti en un equipo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Eh… Me alegra saber que aún hay gente\n"
	.string "capaz de confiar en desconocidos.\p"
	.string "Me llamo {STR_VAR_3}. No hace mucho,\n"
	.string "{STR_VAR_1} me nombró su aprendiz n.º {STR_VAR_2}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} me dio un consejo que\n"
	.string "le agradeceré mientras viva.\p"
	.string "Mi equipo de POKéMON está formado\n"
	.string "por un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "Sé que pido mucho…\p"
	.string "No creo que quieras, pero\n"
	.string "¿puedo unirme a ti como compañero?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "¿En serio? ¡Qué suerte!\n"
	.string "¡Es un honor que me quieras a tu lado!\l"
	.string "¡No pienso defraudarte!\p"
	.string "Esto…\n"
	.string "¡Voy volando a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Bueno… Quizás cambies de opinión\n"
	.string "cuando veas a los otros…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "¡Hola, soy {STR_VAR_3}! ¡Soy el\n"
	.string "aprendiz n.º {STR_VAR_2} de\l"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} me dijo que sería bueno\n"
	.string "formar este equipo:\l"
	.string "un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "y un {STR_VAR_2} que sabe usar\n"
	.string "{STR_VAR_1}.\p"
	.string "¿Nada mal, eh?\n"
	.string "¿Quieres que forme equipo contigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "¡Vale, encantado de unirme!\n"
	.string "¡Espero que no me la líes!\l"
	.string "Voy a registrarme ahora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "¿Eh? ¿Por qué me has rechazado?\n"
	.string "¡No sabes juzgar a las personas!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "Soy {STR_VAR_3} y soy TRIATLETA.\n"
	.string "Estoy ocupado cada día entre correr,\l"
	.string "entrenar y rapear.\p"
	.string "Además, soy el aprendiz n.º {STR_VAR_2}\n"
	.string "de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "Esto es lo que me recomendó\n"
	.string "{STR_VAR_3}. Un {STR_VAR_2} con\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "y un {STR_VAR_2} con\n"
	.string "{STR_VAR_1}.\p"
	.string "Me he esforzado mucho en criarlos,\n"
	.string "aunque estoy ocupado.\p"
	.string "¡Formemos un equipo\n"
	.string "y probemos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "¡Gracias, ese es el espíritu!\n"
	.string "Espera mientras me registro, ¿vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "¡Saqué tiempo de mi apretada\n"
	.string "agenda para venir! ¡Dame un respiro!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "¡Hola! ¿Qué tal?\p"
	.string "Soy {STR_VAR_3}, el aprendiz n.º\n"
	.string "{STR_VAR_2} de {STR_VAR_1}.\l"
	.string "¡Encantado!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "{STR_VAR_3} me dijo que lo mejor\n"
	.string "sería que formase este equipo:\l"
	.string "un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "y un {STR_VAR_2} que supiese\n"
	.string "usar {STR_VAR_1}.\p"
	.string "No está mal, ¿eh?\n"
	.string "¿Quieres que luchemos en pareja?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "¡Estupendo!\n"
	.string "¡Ahora sólo espero que no lo estropees!\l"
	.string "Voy a registrarnos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "¿Cómo? ¿Por qué me rechazas?\n"
	.string "¡Quizás sea lo mejor!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Soy {STR_VAR_3}, renombrado TRIATLETA.\n"
	.string "Me paso todo el día corriendo,\l"
	.string "entrenando y practicando.\p"
	.string "También soy aprendiz de {STR_VAR_1},\n"
	.string "su n.º {STR_VAR_2}, para ser exactos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "{STR_VAR_3} me recomendó este equipo:\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "y un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¡Anda, hagamos equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Oh… ¡Eso es estupendo!\n"
	.string "¡Prometo que daré el máximo de mí!\p"
	.string "¡Voy a registrarnos ahora mismo!\n"
	.string "¡Prepárate!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "Esperaba que dijeses que sí,\n"
	.string "{PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "¡Eh! ¡Has venido a hablar tú conmigo!\n"
	.string "¡Menos mal, porque yo no me atrevía!\p"
	.string "¡Soy {STR_VAR_3}! ¡{STR_VAR_1} me eligió\n"
	.string "como su aprendiz n.º {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "Por consejo de {STR_VAR_3}, entrené\n"
	.string "un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "y un {STR_VAR_2} con\n"
	.string "{STR_VAR_1}.\p"
	.string "¿Puedes concederme mi deseo?\n"
	.string "¡Quiero ser tu compañero de equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "¡Sí! ¡Es… genial!\n"
	.string "¡Un millón de gracias!\l"
	.string "¡Voy pitando a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "¡Buaaa! ¿No te doy pena?\n"
	.string "Pero eso te hace más genial…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "¡Yujuu! ¡Soy el aprendiz\n"
	.string "n.º {STR_VAR_2} de {STR_VAR_1}!\p"
	.string "¡Me llamo {STR_VAR_3}, hola, hola!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "Mi mentor {STR_VAR_3} me recomendó\n"
	.string "un {STR_VAR_2} maestro de {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "y un {STR_VAR_2} maestro de\n"
	.string "{STR_VAR_1}.\p"
	.string "¡Buena cosa, ¿eh?\n"
	.string "¿Formarás equipo conmigo, verdad?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "¡Perfecto!\n"
	.string "¡Voy a registrarnos ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "¡Vaya tela, {PLAYER}!\n"
	.string "No te andas con rodeos, ¿eh?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "¡Eh! ¡Hay un problemón! ¡Hoy es el\n"
	.string "último día de la TORRE BATALLA!\p"
	.string "… … … … … … ¡Es broma!\p"
	.string "Me llaman {STR_VAR_3} y yo también.\n"
	.string "¡Soy el aprendiz n.º 1000 de\l"
	.string "{STR_VAR_1}! ¡Bueno, en realidad soy el\l"
	.string "n.º {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} me dio un buen consejo.\n"
	.string "Busca un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "y un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "¡Tengo diez de cada!\l"
	.string "¡Bueno, uno de cada, quiero decir!\p"
	.string "¿Qué te parece?\n"
	.string "¿Nos ponemos a pelear juntos?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "¡Estupendo!\n"
	.string "¡Voy a darte un POKéMON por enrollarte!\p"
	.string "¡Que es broma! Pero lo que sí es verdad\n"
	.string "es que voy a registrarnos, ¿vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "¡Me dejas helado! ¡Sólo por eso\n"
	.string "voy a destruir esta TORRE BATALLA!\p"
	.string "¡Naa! ¡Claro que no!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "¡Hola, rockeo y rodeo! ¡A los POKéMON\n"
	.string "yo controlo!\p"
	.string "Soy {STR_VAR_3} el MARINERO rapero.\n"
	.string "¡No me confundas con un llorón!\p"
	.string "Soy el aprendiz n.º {STR_VAR_2} de\n"
	.string "{STR_VAR_1}. ¡No me descartes tan\l"
	.string "rápido!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "Con el consejo de {STR_VAR_3} acordé,\n"
	.string "y mi equipo de orgullo formé!\l"
	.string "Un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "y un {STR_VAR_2} con\n"
	.string "{STR_VAR_1}.\p"
	.string "¡Nuestro encuentro conmemoremos,\n"
	.string "con una victoria en equipo celebremos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "¡Me alegra que luchemos juntos!\n"
	.string "¡Ahora mismo voy y nos apunto!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "¡Vaya, {PLAYER}, me dejas de piedra!\n"
	.string "¡Por mí puedes irte a paseo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "¡Yupi-yujuu! ¡Oh, no huyas! ¡Solo\n"
	.string "bromeaba!\p"
	.string "¡Hola! ¡Soy {STR_VAR_3}! ¡Soy el\n"
	.string "aprendiz n.º {STR_VAR_2} de\l"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} me dijo qué hacer. Así que\n"
	.string "elegí un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "y un {STR_VAR_2} con\n"
	.string "{STR_VAR_1}.\p"
	.string "¿Qué dices?\n"
	.string "¡Venga, alégrame el día!\p"
	.string "¡Te lo ruego!\n"
	.string "¡Déjame unirme, no me dejes triste!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "¡Ay! ¡Voy a ponerme a cantar!\n"
	.string "¡No quepo en mí de felicidad!\p"
	.string "¡Pero antes de luchar,\n"
	.string "nos debemos registrar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "¿{PLAYER}, de verdad me vas a rechazar?\n"
	.string "¡Ahora sí que voy a tener que llorar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "¡Cof!\p"
	.string "¡Oh, perdón, estoy resfriado!\n"
	.string "Mis POKéMON están bien, eso sí.\p"
	.string "Me llamo {STR_VAR_3}, aprendiz\n"
	.string "n.º {STR_VAR_2} de {STR_VAR_1}. ¡Cof!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "Seguí el consejo de {STR_VAR_3} y junté\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Los entreno todos los días,\n"
	.string "aunque llueva o nieve.\p"
	.string "Por eso he pillado este catarro.\n"
	.string "¡Achís!\p"
	.string "Bueno, ésas son mis cartas.\n"
	.string "¿Te animas a combatir a mi lado?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "¡Gracias, se agradece la confianza!\n"
	.string "¡Achís!\l"
	.string "¡Voy corriendo a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Lástima, {PLAYER}…\n"
	.string "Habríamos hecho una buena pareja.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "¡Oh, hola!\n"
	.string "Todo esto me pone de los nervios.\p"
	.string "Soy {STR_VAR_3}, aprendiz\n"
	.string "n.º {STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} me aconsejó este equipo:\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Me da un poco de reparo preguntar,\n"
	.string "pero ¿querrías combatir a mi lado?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "¡Oh, guay, eso es genial!\n"
	.string "¡Espero poder estar a la altura!\p"
	.string "Yo me encargo del papeleo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "¡No, por favor, no digas que no!\n"
	.string "Ya tenía suficientes dudas sobre mí…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "Soy {STR_VAR_3}, y no miento. Soy el\n"
	.string "aprendiz n.º {STR_VAR_2} de\l"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "Me llamo {STR_VAR_3},\n"
	.string "pero hay nombres peores.\p"
	.string "{STR_VAR_1} me hizo su aprendiz n.º {STR_VAR_2}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "mi {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Si es posible, me gustaría que me\n"
	.string "aceptaras como compañero de equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "¿Me aceptas de verdad?\n"
	.string "Menos mal, lo hubiese pasado fatal…\p"
	.string "¡Pero me has aceptado!\n"
	.string "¡Voy corriendo a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "¿Mm? ¿Y se puede saber por qué no?\n"
	.string "¿Te piensas que tiene gracia?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "¡Soy {STR_VAR_1}, una CHICA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "Lo que tengo aquí es un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} y un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} que usa {STR_VAR_1}.\n"
	.string "Es lo que me he traído.\p"
	.string "¿Quieres que seamos equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "¡Muchas gracias!\n"
	.string "¡Voy a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "¿Conque no soy buena para ti?\n"
	.string "¡Pues que sepas que lo vas a lamentar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "¡Hola!\p"
	.string "¡Soy el JOVEN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "¿Quieres saber lo que llevo conmigo?\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Quieres hacer un equipo conmigo,\n"
	.string "¿verdad?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "¡Lo sabía!\n"
	.string "¡Voy a apuntarnos ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "¡Qué palo! ¡Si formáramos un dúo\n"
	.string "tú y yo, no nos ganaría nadie!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "¡Eco, eeeecooo!\n"
	.string "¡Soy el MONTAÑERO {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "¿Sabes qué llevo conmigo?\n"
	.string "¡Mi {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "mi {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "¿Suena bien, eh?\n"
	.string "¿Quieres formar equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "¡Jaroleri-leri-o!\n"
	.string "¡Voy a registrarnos antes \l"
	.string "de que cambies de opinión!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "Qué pena, me habría gustado\n"
	.string "combatir a tu lado.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "¡Hola!\n"
	.string "¡Soy la BELLA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "¿Quieres ver lo que estoy entrenando?\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "¿Qué opinas?\n"
	.string "¿Los quieres en tu equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "¡Qué estupendo!\n"
	.string "¡No te muevas, yo voy a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "¡Qué decepción!\p"
	.string "Los dos juntos… ¡habríamos sido\n"
	.string "los mejores!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "¡Hola!\p"
	.string "¿Sabes quién soy?\n"
	.string "¡Soy {STR_VAR_1}, el PESCADOR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "Llevo conmigo un equipo de un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Qué te parece?\n"
	.string "¿Combatirás a mi lado?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "¡Bien, bien!\n"
	.string "¡Déjalo de mi cuenta!\p"
	.string "Voy a registrarnos ahora mismo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "Lástima, éramos tal para cual…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Encantada de conocerte.\n"
	.string "Soy {STR_VAR_1}, una DAMISELA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "En mi maravilloso equipo tengo\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Espero que te agraden, pues nada me\n"
	.string "haría más feliz que combatir a tu lado.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "Te estoy agradecida.\n"
	.string "Voy a formalizar los trámites.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "Humildemente, siento que terminarás\n"
	.string "por lamentar semejante decisión.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "¡Soy {STR_VAR_1}, una TRIATLETA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "A ver qué tengo aquí…\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "¡un {STR_VAR_2} con {STR_VAR_1}!\n"
	.string "¡Esa es mi pareja!\p"
	.string "¿Por favor?\n"
	.string "¿Formarás equipo conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "¡Perfecto!\n"
	.string "¡Voy corriendo a apuntarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "Oh. ¡Tú y yo podríamos\n"
	.string "haber hecho historia!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "¿Qué tal?\n"
	.string "¡Soy el CAZABICHOS {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "¡Mira lo que traigo en el morral!\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Así que escucha:\n"
	.string "¿Qué tal si unimos fuerzas?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "¡Entendido!\p"
	.string "Voy a hacer el registro\n"
	.string "en el mostrador.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "¿Cómo? ¿Con los POKéMON que tengo?\n"
	.string "¡Ya veremos si no te arrepientes!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "¡Hola, hola! ¡Soy {STR_VAR_1},\n"
	.string "un ESCOLAR con mucha escuela!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "Ahora estoy entrenando a un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "y a un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1}.\p"
	.string "Envidia, ¿eh? Bueno, si quieres,\n"
	.string "nos unimos para luchar…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "¡Bien dicho!\n"
	.string "¡Voy a rellenar la solicitud!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "No esperaba oír eso…\p"
	.string "Me hubiese gustado aprender\n"
	.string "algo de ti…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Tú también sabes quién soy, ¿verdad?\n"
	.string "¡Soy {STR_VAR_1}, un NIÑO BIEN!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "¡Yo siempre tengo lo mejor!\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Te voy a dar la oportunidad\n"
	.string "de luchar a mi lado.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "¡Qué superguay!\p"
	.string "Espabila y prepárate mientras\n"
	.string "yo voy a registrarnos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "¿Que vas tú y me rechazas?\n"
	.string "¡No! ¡Te rechazo yo antes a ti!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "¡Kiaaaaaa!\n"
	.string "Soy el KARATEKA {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "Yo estoy luchando con\n"
	.string "un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "y un {STR_VAR_2} con\n"
	.string "{STR_VAR_1}.\p"
	.string "¡Por favor, concédeme mi deseo!\n"
	.string "¡Permíteme ser tu compañero de equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "¡Kiaaaaaaa!\n"
	.string "¡Voy corriendo a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "Bien… Quizás cambies\n"
	.string "de opinión la próxima vez…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "¡Hola, caracola!\n"
	.string "¡Soy {STR_VAR_1}, una PLAYERA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "Te enseño lo que llevo.\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\n"
	.string "¿Me aceptas a tu lado?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "¡Guay!\n"
	.string "¡Voy ahora mismo a apuntarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "¡Si hubieses dicho que sí,\n"
	.string "tendríamos más futuro!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Je, je. Hola…\n"
	.string "Soy la BRUJITA {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "Llevo conmigo un {STR_VAR_2} con\n"
	.string "{STR_VAR_1} junto con un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_2} con {STR_VAR_1}…\p"
	.string "Te lo suplico…\n"
	.string "Únete a mí en un equipo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "Te lo agradezco…\n"
	.string "Nos registraré…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "Tenía tantas ganas de unirme a ti…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "¿Cómo está usted? Soy {STR_VAR_1},\n"
	.string "¡y soy CRIADOR de POKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "Hoy llevo conmigo un {STR_VAR_2}\n"
	.string "con {STR_VAR_1} y también un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "{STR_VAR_2} que usa {STR_VAR_1}…\p"
	.string "Te lo suplico…\n"
	.string "Formemos un equipo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "¡Muchas gracias!\p"
	.string "Voy a ocuparme del registro,\n"
	.string "¡así que espera aquí!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "Vaya, debe de haber\n"
	.string "un conjuro contra mi…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Encantado. ¡Me llamo {STR_VAR_1},\n"
	.string "y soy un CRIAPOKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "¡Tengo dos POKéMON invencibles!\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "¿A que suena bien?\n"
	.string "No te cortes y lucha a mi lado.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "¡Bien hecho!\p"
	.string "¡Haré el registro enseguida!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "Tú y yo habríamos batido récords.\n"
	.string "Qué pena…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "¡Hola! ¡Me llamo {STR_VAR_1}!\n"
	.string "¡Soy un TRIATLETA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "Éstas son mis dos liebres:\n"
	.string "¡un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Si nos juntamos, podemos\n"
	.string "ganarlo todo. ¿Qué me dices?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "¡La victoria es nuestra!\n"
	.string "¡Voy raudo y veloz a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "Estaba dispuesto a darlo todo\n"
	.string "a tu lado…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "¡Soy la LUCHADORA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "He estado fortaleciendo un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Te gusta esa combinación?\n"
	.string "¿Qué tal si nos unimos tú y yo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "¡Bien dicho!\p"
	.string "Ya que tú te has decidido,\n"
	.string "¡yo iré a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "No pierdo la esperanza, quizás\n"
	.string "vuelvas en otra ocasión…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "¡Soy {STR_VAR_1}, una TRIATLETA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "Yo voy al gimnasio con un {STR_VAR_2}\n"
	.string "que sabe usar {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "y con un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Creo que formaríamos un buen equipo.\n"
	.string "Tú decides…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "¡Gracias!\p"
	.string "Voy a registrarnos, ¡y ahora\n"
	.string "mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Vaya, qué pena. ¡Habríamos sido\n"
	.string "el equipo más duro!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "¿Yo?\n"
	.string "¡Soy {STR_VAR_1}, todo un PLAYERO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "¿Que qué tengo aquí?\n"
	.string "Pues un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Ahora que lo sabes, supongo\n"
	.string "que querrás combatir a mi lado, ¿no?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "¡Lo sabía!\p"
	.string "¡Voy a apuntarnos!\n"
	.string "¡Vamos a hacer algo grande!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "Con lo fuertes que son mis POKéMON…\n"
	.string "Creo que te has precipitado.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "¡A las muy buenas!\n"
	.string "¡Llámame GUITARRISTA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "¡Mira qué banda he formado!\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "¿Suena bien, eh?\n"
	.string "¿Hacemos un dueto?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "¡Música para mis oídos!\n"
	.string "¡Yo me encargo del papeleo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "¡Vaya! ¡No reconocerías a un genio\n"
	.string "ni aunque lo tuvieses delante!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Es un honor.\n"
	.string "Soy el CABALLERO {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "Me acompañan mi fiel {STR_VAR_2} con\n"
	.string "{STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Puedo pedirte que te unas a mí en\n"
	.string "una asociación de equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Será un honor combatir a tu lado.\n"
	.string "Deja que yo me ocupe de la burocracia.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "Qué desafortunada elección…\p"
	.string "Espero con impaciencia nuestro\n"
	.string "próximo encuentro…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Hola, soy {STR_VAR_1},\n"
	.string "y soy un POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "Tengo un {STR_VAR_2} que sabe\n"
	.string "el movimiento {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Te gusta lo que ofrezco?\n"
	.string "¿Por qué no nos unimos?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "¡Excelente!\n"
	.string "¡Voy a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "Mis POKéMON son de lo mejor que hay…\n"
	.string "Es una pena que no sepas apreciarlos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "¡Mm!\n"
	.string "Soy {STR_VAR_1}, un POKéABU.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "Los POKéMON que entreno son\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Te alías con un experto como yo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "¡Mm!\n"
	.string "¡Voy a registrarnos!\l"
	.string "¡Espero que tengamos suerte!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "Espero que tu elección sea la\n"
	.string "más adecuada para ti…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Hola, hola.\n"
	.string "Soy {STR_VAR_1}, una POKéABU.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "He entrenado mis POKéMON a conciencia.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}:\n"
	.string "eso es lo que tengo.\p"
	.string "¿Querrías aliarte conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Bien, bien, bien.\n"
	.string "Yo me encargo del papeleo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Quizás podamos formar\n"
	.string "un equipo la próxima vez.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "¡Soy el DOMADRAGÓN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "El equipo que he entrenado es\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¡Apuesto a que te gusta!\n"
	.string "¿Combatimos como equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "¡Genial, voy a esforzarme de verdad!\n"
	.string "Prepárate, que voy a registrarnos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "¡Te va a ser difícil encontrar a\n"
	.string "mejores ENTRENADORES que yo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "¡Soy el ORNITÓLOGO {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "¿Que cuáles son mis POKéMON?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿No te parece que haríamos\n"
	.string "un equipo fuera de serie?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "¡Genial, a mí también!\n"
	.string "¡Yo me encargo de rellenar los papeles!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "Mis POKéMON y yo somos muy buenos.\n"
	.string "¡Menuda decepción!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "¡Soy {STR_VAR_1}, un CHICO NINJA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "Mi equipo de POKéMON está formado por\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¡Vamos juntos a por todas!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "¡Sí!\n"
	.string "¡Voy a registrarnos ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "¡Creo que vas a echar de menos a mis\n"
	.string "POKéMON antes de lo que piensas!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "¡Hola!\n"
	.string "¡Soy la DAMA PARASOL {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "Haciéndome compañía están un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "¿A que son geniales? ¿Quieres unirte a\n"
	.string "nosotros en un equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "¡Sabia decisión!\p"
	.string "Voy en volandas a registrarnos.\n"
	.string "¡Esperemos no fallarnos mutuamente!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "Mis POKéMON no son sólo hermosos,\n"
	.string "también son fuertes. ¡Ignorante!…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Hola. Soy {STR_VAR_1},\n"
	.string "¡un auténtico BICHOMANÍACO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "Ya tengo mis POKéMON, sí.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}:\n"
	.string "no hay nada mejor allá donde busques.\p"
	.string "¿Vas a aprovechar esta oportunidad\n"
	.string "única que te doy de combatir conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "¡Genial!\n"
	.string "¡Comprendido!\p"
	.string "¡No tardaré en registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "Con los POKéMON que he encontrado,\n"
	.string "no perderíamos nunca…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "¡Echa el ancla!\n"
	.string "¡Soy el MARINERO {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "¡Déjame mostrarte mi mercancía!\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Por supuesto que no me vas a\n"
	.string "rechazar. Haremos equipo, ¿verdad?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "¡Bien dicho!\n"
	.string "¡Voy ahora mismo a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "Has tirado por la borda una\n"
	.string "buena oportunidad, ¡no lo olvides!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Hola, me llamo {STR_VAR_1}.\n"
	.string "Soy un POKéCOLECTOR.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "Las joyas de mi colección son\n"
	.string "mi {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "mi {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Brillantes, eh?\n"
	.string "Deberíamos formar un equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "¡Maravilloso!\p"
	.string "Venga, no perdamos tiempo.\n"
	.string "Voy a registrarnos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Pues que sepas que has perdido\n"
	.string "una ocasión de oro.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "¡Choca ésa! ¡Me llamo {STR_VAR_1}!\n"
	.string "Soy un POKéGUARDA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "Me hacen compañía un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿No crees que formaríamos un\n"
	.string "equipo impresionante?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "¡Genial!\n"
	.string "Me ocupo del registro ahora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "La próxima vez, elige mis POKéMON,\n"
	.string "¿vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "Me llamo {STR_VAR_1}.\n"
	.string "¡Soy GUARDABOSQUES POKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Tengo a mi cargo un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Por poco que tengas tú, seguro\n"
	.string "que podemos hacer un buen equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "¡Así se habla!\n"
	.string "¡Déjame encargarme del registro!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "La próxima vez no te equivoques.\n"
	.string "Elige a mis POKéMON, ¿vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Me llamo {STR_VAR_1}.\n"
	.string "¡Soy una POKéGUARDA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "Te resumo brevemente mi equipo:\n"
	.string "¡un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Espero que te gusten.\n"
	.string "¿Querrías ser mi compañero?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "Me halaga tu elección.\n"
	.string "Tardaré sólo un minuto en registrarnos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "Sería estupendo que cambiases\n"
	.string "de opinión para la próxima vez.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "¿Sabes quién soy yo?\n"
	.string "Soy {STR_VAR_1}, ¡un RUINAMANÍACO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "Los POKéMON que tengo ahora son\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Intrigante, ¿verdad?\n"
	.string "¿Conquistamos juntos esta torre?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "¡Bien! ¡Alea jacta est!\n"
	.string "Yo me ocupo de los papeles.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Habríamos hecho un equipo cuya fama\n"
	.string "perduraría por los siglos de los siglos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "¡Soy {STR_VAR_1}, un ENTRENADOR GUAY!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "Los POKéMON que tengo ahora a mi cargo\n"
	.string "son un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "¿Molan, eh?\p"
	.string "Creo que, si formamos un equipo,\n"
	.string "seremos la envidia de todos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "¡Guay!\n"
	.string "¡Voy pitando a hacer el papeleo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "Pensaba que haríamos el mejor\n"
	.string "equipo de todos los tiempos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "¡Soy {STR_VAR_1}, un ENTRENADOR GUAY!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "El equipo que he criado tiene un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Te parece bien?\n"
	.string "¿Qué tal si formamos equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "¡Me parece perfecto!\n"
	.string "Mejor me ocupo del registro.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "Pensaba que seríamos un\n"
	.string "equipo muy duro…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "¡Eh, hola!\n"
	.string "¡Soy {STR_VAR_1}, el POKéMANÍACO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "¿Qué tiene un tipo como yo?\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1},\n"
	.string "¡eso!\p"
	.string "¡Hagámoslo!\n"
	.string "¡Arrasaremos como equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "¡Buena decisión!\n"
	.string "¡Nos registro a los dos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "¡Mis POKéMON son brutales!\n"
	.string "¡No es mi culpa si te arrepientes!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "¡Hola, me llamo {STR_VAR_1}!\n"
	.string "¡Soy una ENTRENADORA GUAY!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "El equipo que estoy formando tiene\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "No te quejarás, ¿verdad?\n"
	.string "¿A que quieres combatir a mi lado?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "¡Bien por ese espíritu ganador!\n"
	.string "Voy a apuntarnos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Prométeme que formarás equipo\n"
	.string "conmigo la próxima vez que nos veamos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "Soy {STR_VAR_1}, ¡y soy CAMPISTA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "He criado un {STR_VAR_2} con\n"
	.string "{STR_VAR_1} y un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Crees que sería divertido formar\n"
	.string "equipo? ¡Seguro que sí!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "¡Bien dicho!\n"
	.string "¡Voy volando a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "¡Mis POKéMON son los mejores!\n"
	.string "¡No me digas que no te avisé!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "¡Eh, hooola!\n"
	.string "¡Soy el FOGONERO {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "Tengo una receta infalible para ganar:\n"
	.string "¡un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "¿Qué me dices?\n"
	.string "¿Formamos una piña?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "¡Vamos a darnos una panzada de ganar!\n"
	.string "¡Yo me encargo de registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "Espero que cambies de opinión\n"
	.string "la próxima vez que nos veamos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "¡Soy {STR_VAR_1}, un CAMPISTA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "He estado entrenando un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} y un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "{STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "¿Te apetece que salgamos\n"
	.string "juntos al campo de batalla?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "¡Bravo!\n"
	.string "¡Voy corriendo a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "Bueno, quizás la próxima vez, ¿vale?\n"
	.string "Estoy deseando combatir junto a ti.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "¡Hola! ¡Me llamo {STR_VAR_1}, y confieso\n"
	.string "que soy una auténtica DOMINGUERA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "y un {STR_VAR_2} que usa {STR_VAR_1}:\n"
	.string "ésos son mis dos POKéMON.\p"
	.string "¿Quieres combatir a mi lado\n"
	.string "a ver hasta dónde llegamos?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "¡Ooh, muchas gracias!\n"
	.string "¡Voy a registrarnos ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "¿Me dejarás combatir junto a ti\n"
	.string "la próxima vez? Anda, porfa…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "¡Soy el ESCOLAR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "Un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "y un {STR_VAR_2} con\n"
	.string "{STR_VAR_1} son mi pareja de POKéMON.\p"
	.string "¿Puedo ser tu compañero en\n"
	.string "un equipo, por favor?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "¡Oh, gracias! ¡Me registro en el\n"
	.string "mostrador ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "¿Por favor?\n"
	.string "¿Puedo unirme la próxima vez?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "¡Eh! ¡Me llamo {STR_VAR_1}!\n"
	.string "¡Soy una CRIAPOKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "Los POKéMON que he criado son un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Te suena interesante?\n"
	.string "¿Qué tal si formamos equipo, entonces?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "¡Qué genial!\n"
	.string "¡Deja de mi cuenta lo de registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "Pero, entonces, cuento contigo\n"
	.string "para la próxima vez, ¿de acuerdo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "Soy {STR_VAR_1}, y puedo decir con\n"
	.string "orgullo que soy una POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "Estoy enamorada de mis dos POKéMON:\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿A que son dos auténticas monadas?\n"
	.string "¡Tú y yo tenemos que hacer un equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "¡Qué estupendísimo!\n"
	.string "¡Voy a registrarnos en un plis!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "¿Cómo te atreves a hacerles ese feo\n"
	.string "a mis POKéMON? ¡No tienes perdón!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Hola, soy la NADADORA {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "Un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "y un {STR_VAR_2} con\n"
	.string "{STR_VAR_1} es lo que he entrenado.\p"
	.string "Tú y yo, formemos un equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "¡De cabeza, eso es!\n"
	.string "¡Voy corriendo a hacer el papeleo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "¡Menudo jarro de agua fría!\n"
	.string "¡Bueno, la próxima vez, entonces!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "¿Qué tal?\n"
	.string "Soy {STR_VAR_1}, un TRIATLETA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "Tengo un par de POKéMON decentes.\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "¡Me encantaría formar un equipo\n"
	.string "contigo! ¿Qué me dices?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "¡Estupendo!\n"
	.string "Voy a registrarnos, ¿vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "Espero que cambies de opinión\n"
	.string "la próxima vez que nos veamos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "¡Soy la TRIATLETA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "otro {STR_VAR_2} que sabe usar\n"
	.string "{STR_VAR_1}. Ésa es mi pareja.\p"
	.string "No está nada mal, ¿eh?\n"
	.string "Haríamos un buen equipo, ¿qué me dices?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "¡Ésa es la respuesta que esperaba!\n"
	.string "¡Un segundo, que voy a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "Bueno, espero que la próxima vez\n"
	.string "me des una oportunidad.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "¡Hola! ¿Cómo te va?\n"
	.string "Soy {STR_VAR_1}, y soy un NADADOR.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "¡Alucina con lo que tengo!\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "¿Una pareja guapa, eh?\n"
	.string "¡Estamos listos para formar equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "¡Menuda oportunidad!\n"
	.string "¡Gracias, voy a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "Si nos volvemos a ver,\n"
	.string "vas a decir que sí, ¿verdad?$"

