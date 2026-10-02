BattleFrontier_BattleTowerMultiPartnerRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp_hns
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame_hns
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume_hns:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition_hns:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner_hns
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

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner_hns::
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

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp_hns:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth_hns::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom_hns
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom_hns
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom_hns::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom_hns::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom_hns
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit_hns
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner_hns, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom_hns:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit_hns:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant_hns::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge_hns
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner_hns2_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge_hns::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator_hns::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator_hns
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR_HNS, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator_hns::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator_hns
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator_hnsEast_hns:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator_hnsEast_hns
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator_hnsWest_hns:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest_hns
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator_hns:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator_hnsEast_hns:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest_hns:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner_hns
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
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner_hns
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit_hnsSouth_hns
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM_HNS, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner_hns::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit_hns::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit_hns
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit_hnsSouth_hns::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit_hnsSouth_hns
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit_hns:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit_hnsSouth_hns:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner_hns:
	.string "Búscate un compañero entre los\n"
	.string "ENTRENADORES que hay aquí.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner_hns:
	.string "¿{PLAYER}, aún no has encontrado\n"
	.string "un compañero para tu equipo?\p"
	.string "¿Qué pasa? ¿Quieres dejar de buscar\n"
	.string "y volver al mostrador de recepción?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner_hns2_hns:
	.string "Entonces, búscate un compañero entre\n"
	.string "los ENTRENADORES que hay aquí.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner_hns::
	.string "Bien, veo que ya tienes pareja.\p"
	.string "Te conduciré a la Sala de Combates\n"
	.string "Múltiples.\p"
	.string "$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro_hns::
	.string "Soy el aprendiz n.º {STR_VAR_2} de\n"
	.string "{STR_VAR_1}. ¡Puedes llamarme\l"
	.string "{STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1_hns::
	.string "Por consejo de {STR_VAR_1}, he traído\n"
	.string "un {STR_VAR_3} con {STR_VAR_2} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Por favor, déjame formar equipo\n"
	.string "contigo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept_hns::
	.string "¡Gracias! Voy a inscribirnos ahora\n"
	.string "mismo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject_hns::
	.string "Tenía muchas ganas de formar equipo\n"
	.string "contigo, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro_hns::
	.string "Soy el aprendiz n.º {STR_VAR_2} de\n"
	.string "{STR_VAR_1}. Me llamo {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1_hns::
	.string "{STR_VAR_1} me aconsejó y elegí un\n"
	.string "{STR_VAR_3} con {STR_VAR_2} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¡Por favor, formemos equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept_hns::
	.string "¡Muchísimas gracias! ¡Enseguida\n"
	.string "termino la inscripción!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject_hns::
	.string "{PLAYER}, esperaba poder formar\n"
	.string "pareja contigo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro_hns::
	.string "Eh… Me llamo {STR_VAR_3} y soy el\n"
	.string "aprendiz n.º {STR_VAR_2} de\l"
	.string "{STR_VAR_1}.\p"
	.string "Snif…\p"
	.string "¡Lo siento! Estoy tan nervioso que me\n"
	.string "echo a llorar…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1_hns::
	.string "{STR_VAR_3} me aconsejó que tuviese\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Snif…\n"
	.string "¡Por favor, déjame ser tu pareja!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept_hns::
	.string "¿De verdad? ¿Me eliges a mí?\n"
	.string "¡Genial! ¡Alucinante! ¡Superguay!\p"
	.string "Oh… Perdona…\n"
	.string "Son lágrimas de felicidad…\p"
	.string "Voy corriendo a registrarnos.\n"
	.string "¡No empieces sin mí!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject_hns::
	.string "Oh, pe-pero…\n"
	.string "Si… ¡Buaaaaaa!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro_hns::
	.string "¡Hola! ¡Soy {STR_VAR_3}, y {STR_VAR_1}\n"
	.string "me eligió como su aprendiz n.º {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1_hns::
	.string "Le pedí consejo a {STR_VAR_3}.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask_hns::
	.string "y un {STR_VAR_2} con {STR_VAR_1},\n"
	.string "ésa es mi pareja de POKéMON.\p"
	.string "¿Qué me dices? ¿Te interesa\n"
	.string "formar equipo conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept_hns::
	.string "¡Gracias! ¡No te arrepentirás!\n"
	.string "¡Voy a registrarnos ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject_hns::
	.string "Como quieras, {PLAYER}, pero pocos\n"
	.string "compañeros encontrarás como yo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro_hns::
	.string "¡Soy {STR_VAR_3}, el aprendiz n.º\n"
	.string "{STR_VAR_2} del famoso {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1_hns::
	.string "Pedí consejo a {STR_VAR_3}. Un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask_hns::
	.string "y un {STR_VAR_2} con {STR_VAR_1}: esa\n"
	.string "es mi pareja.\p"
	.string "Por favor, ¿formarías equipo conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept_hns::
	.string "¡Gracias! ¡Voy a inscribirnos ahora\n"
	.string "mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject_hns::
	.string "{PLAYER}, esperaba poder formar\n"
	.string "equipo contigo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro_hns::
	.string "Eh… Me alegra saber que aún hay gente\n"
	.string "capaz de confiar en desconocidos.\p"
	.string "Me llamo {STR_VAR_3}. No hace mucho,\n"
	.string "{STR_VAR_1} me nombró su aprendiz n.º {STR_VAR_2}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1_hns::
	.string "{STR_VAR_3} me dio un consejo que\n"
	.string "le agradeceré mientras viva.\p"
	.string "Mi equipo de POKéMON está formado\n"
	.string "por un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}. Sé que\n"
	.string "te pido mucho…\p"
	.string "No creo que quieras, pero ¿puedo ser\n"
	.string "tu compañero?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept_hns::
	.string "¿En serio? ¡Qué suerte!\n"
	.string "¡Es un honor que me quieras a tu lado!\l"
	.string "¡No pienso defraudarte!\p"
	.string "Esto…\n"
	.string "¡Voy volando a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject_hns::
	.string "Bueno… Quizás cambies de opinión\n"
	.string "cuando veas a los otros…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro_hns::
	.string "¡Hola, soy {STR_VAR_3}! ¡Soy el\n"
	.string "aprendiz n.º {STR_VAR_2} de\l"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1_hns::
	.string "{STR_VAR_3} me dijo que este equipo\n"
	.string "estaría bien: un {STR_VAR_2} que usa\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask_hns::
	.string "y un {STR_VAR_2} que sabe usar\n"
	.string "{STR_VAR_1}.\p"
	.string "No está mal, ¿eh? ¿Quieres formar\n"
	.string "equipo conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept_hns::
	.string "¡Vale, encantado de unirme a ti!\n"
	.string "¡Espero que no me lo estropees! Voy a\l"
	.string "inscribirme ahora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject_hns::
	.string "¿Eh? ¿Por qué me has rechazado? ¡No\n"
	.string "sabes juzgar a la gente!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro_hns::
	.string "Soy {STR_VAR_3} y soy TRIATLETA.\n"
	.string "Estoy muy ocupado todos los días\l"
	.string "entre correr, entrenar y rapear.\p"
	.string "Y además soy el aprendiz n.º\n"
	.string "{STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1_hns::
	.string "Esto es lo que me recomendó\n"
	.string "{STR_VAR_3}. Un {STR_VAR_2} que usa\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask_hns::
	.string "y un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Me he esforzado mucho en criarlos,\n"
	.string "aunque esté muy ocupado.\p"
	.string "¡Formemos equipo y a por ello!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept_hns::
	.string "¡Gracias, así me gusta! Espera aquí\n"
	.string "mientras voy a inscribirnos, ¿vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject_hns::
	.string "¡He sacado tiempo de mi apretada\n"
	.string "agenda para venir! ¡No me hagas esto!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro_hns::
	.string "¡Hola! ¿Qué tal?\p"
	.string "Soy {STR_VAR_3}, el aprendiz n.º\n"
	.string "{STR_VAR_2} de {STR_VAR_1}.\l"
	.string "¡Encantado de conocerte!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1_hns::
	.string "{STR_VAR_3} me dijo que lo mejor\n"
	.string "sería que formase este equipo:\l"
	.string "un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask_hns::
	.string "y un {STR_VAR_2} que supiese\n"
	.string "usar {STR_VAR_1}.\p"
	.string "No está mal, ¿eh?\n"
	.string "¿Quieres que luchemos en pareja?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept_hns::
	.string "¡Estupendo!\n"
	.string "¡Ahora sólo espero que no lo estropees!\l"
	.string "Voy a registrarnos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject_hns::
	.string "¿Cómo? ¿Por qué me rechazas?\n"
	.string "¡Quizás sea lo mejor!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro_hns::
	.string "Soy {STR_VAR_3}, renombrado TRIATLETA.\n"
	.string "Me paso todo el día corriendo,\l"
	.string "entrenando y practicando.\p"
	.string "También soy aprendiz de {STR_VAR_1},\n"
	.string "su n.º {STR_VAR_2}, para ser exactos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1_hns::
	.string "{STR_VAR_3} me recomendó este equipo:\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask_hns::
	.string "y un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¡Anda, hagamos equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept_hns::
	.string "Oh… ¡Eso es estupendo!\n"
	.string "¡Prometo que daré el máximo de mí!\p"
	.string "¡Voy a registrarnos ahora mismo!\n"
	.string "¡Prepárate!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject_hns::
	.string "Esperaba que dijeses que sí,\n"
	.string "{PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro_hns::
	.string "¡Eh! ¡Has venido a hablar tú conmigo!\n"
	.string "¡Menos mal, porque yo no me atrevía!\p"
	.string "¡Soy {STR_VAR_3}! ¡{STR_VAR_1} me eligió\n"
	.string "como su aprendiz n.º {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1_hns::
	.string "Por consejo de {STR_VAR_3}, he\n"
	.string "entrenado un {STR_VAR_2} que usa\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask_hns::
	.string "y un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Por favor, ¿me concedes un deseo?\n"
	.string "¡Quiero ser tu compañero de equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept_hns::
	.string "¡Sí! ¡Es… genial!\n"
	.string "¡Un millón de gracias!\l"
	.string "¡Voy pitando a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject_hns::
	.string "¡Buaaa! ¿No te doy ninguna pena? Pero\n"
	.string "así eres más genial…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro_hns::
	.string "¡Yija! ¡Soy el aprendiz n.º {STR_VAR_2}\n"
	.string "de {STR_VAR_1}!\p"
	.string "Me llamo {STR_VAR_3}. ¡Hola, hola!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1_hns::
	.string "Mi maestro {STR_VAR_3} me recomendó\n"
	.string "un {STR_VAR_2} experto en {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask_hns::
	.string "y un {STR_VAR_2} experto en\n"
	.string "{STR_VAR_1}.\p"
	.string "Está bien, ¿eh? Formarás equipo\n"
	.string "conmigo, ¿verdad?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept_hns::
	.string "¡Perfecto!\n"
	.string "¡Voy a registrarnos ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject_hns::
	.string "¡Vaya tela, {PLAYER}!\n"
	.string "No te andas con rodeos, ¿eh?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro_hns::
	.string "¡Eh! ¡Hay un problema gordo! ¡Hoy es el\n"
	.string "último día de la TORRE BATALLA!\p"
	.string "… … … … … …\p"
	.string "¡Es broma!\p"
	.string "La gente me llama {STR_VAR_3}, ¡y yo\n"
	.string "también! ¡Soy el aprendiz n.º 1000 de\l"
	.string "{STR_VAR_1}!\p"
	.string "En realidad, soy el n.º {STR_VAR_2}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1_hns::
	.string "{STR_VAR_3} me dio un buen consejo.\n"
	.string "Busca un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask_hns::
	.string "y un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "¡Tengo diez de cada!\l"
	.string "¡Bueno, uno de cada, quiero decir!\p"
	.string "¿Qué te parece?\n"
	.string "¿Nos ponemos a pelear juntos?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept_hns::
	.string "¡Estupendo!\n"
	.string "¡Voy a darte un POKéMON por enrollarte!\p"
	.string "¡Que es broma! Pero lo que sí es verdad\n"
	.string "es que voy a registrarnos, ¿vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject_hns::
	.string "¡Me dejas helado! ¡Sólo por eso\n"
	.string "voy a destruir esta TORRE BATALLA!\p"
	.string "¡Naa! ¡Claro que no!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro_hns::
	.string "¡Eh, aquí estoy, con mucho rock and\n"
	.string "roll! ¡A los POKéMON los controlo yo!\p"
	.string "Soy {STR_VAR_3}, el MARINERO que\n"
	.string "rapea. ¡No me confundas con uno que\l"
	.string "solo pelea!\p"
	.string "Soy el aprendiz n.º {STR_VAR_2} de\n"
	.string "{STR_VAR_1}. ¡A mí no me descartes,\l"
	.string "que te arrepentirás!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1_hns::
	.string "Siguiendo los consejos de {STR_VAR_3},\n"
	.string "¡formé mi equipo, que es la monda! Un\l"
	.string "{STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask_hns::
	.string "y un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "¡Nuestro encuentro hay que celebrar\n"
	.string "con un combate por parejas que ganar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept_hns::
	.string "¡Me alegra que luchemos juntos!\n"
	.string "¡Ahora mismo voy y nos apunto!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject_hns::
	.string "¡Vaya, {PLAYER}, me dejas de piedra!\n"
	.string "¡Por mí puedes irte a paseo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro_hns::
	.string "¡Yupi, yahú! ¡Eh, no huyas! ¡Solo me\n"
	.string "divertía!\p"
	.string "¡Hola! ¡Soy {STR_VAR_3}! ¡Soy el\n"
	.string "aprendiz n.º {STR_VAR_2} de\l"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1_hns::
	.string "{STR_VAR_3} me dijo lo que tenía que\n"
	.string "hacer. Así que un {STR_VAR_2} que usa\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask_hns::
	.string "y un {STR_VAR_2} que usa {STR_VAR_1}\n"
	.string "he elegido.\p"
	.string "Bueno, ¿qué me dices? ¡Venga, alégrame\n"
	.string "el día!\p"
	.string "¡Por favor, te lo suplico! ¡Déjame ir\n"
	.string "contigo, no me dejes tirado!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept_hns::
	.string "¡Ay! ¡Voy a ponerme a cantar!\n"
	.string "¡No quepo en mí de felicidad!\p"
	.string "¡Pero antes de luchar,\n"
	.string "nos debemos registrar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject_hns::
	.string "¿{PLAYER}, de verdad me vas a rechazar?\n"
	.string "¡Ahora sí que voy a tener que llorar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro_hns::
	.string "¡Cof!\p"
	.string "Ay, perdona, estoy resfriado. Pero mis\n"
	.string "POKéMON están bien.\p"
	.string "Me llamo {STR_VAR_3} y soy el aprendiz\n"
	.string "n.º {STR_VAR_2} de {STR_VAR_1}. ¡Cof!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1_hns::
	.string "Seguí el consejo de {STR_VAR_3} y junté\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Los entreno todos los días,\n"
	.string "aunque llueva o nieve.\p"
	.string "Por eso he pillado este catarro.\n"
	.string "¡Achís!\p"
	.string "Bueno, ésas son mis cartas.\n"
	.string "¿Te animas a combatir a mi lado?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept_hns::
	.string "¡Gracias, se agradece la confianza!\n"
	.string "¡Achís!\l"
	.string "¡Voy corriendo a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject_hns::
	.string "Lástima, {PLAYER}…\n"
	.string "Habríamos hecho una buena pareja.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro_hns::
	.string "¡Oh, hola!\n"
	.string "Todo esto me pone de los nervios.\p"
	.string "Soy {STR_VAR_3}, aprendiz\n"
	.string "n.º {STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1_hns::
	.string "{STR_VAR_3} me aconsejó este equipo:\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Me da un poco de reparo preguntar,\n"
	.string "pero ¿querrías combatir a mi lado?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept_hns::
	.string "¡Oh, guay, eso es genial!\n"
	.string "¡Espero poder estar a la altura!\p"
	.string "Yo me encargo del papeleo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject_hns::
	.string "¡No, por favor, no digas que no!\n"
	.string "Ya tenía suficientes dudas sobre mí…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro_hns::
	.string "Soy {STR_VAR_3}, y no es mentira. Soy\n"
	.string "el aprendiz n.º {STR_VAR_2} de\l"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1_hns::
	.string "Me llamo {STR_VAR_3},\n"
	.string "pero hay nombres peores.\p"
	.string "{STR_VAR_1} me hizo su aprendiz n.º {STR_VAR_2}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask_hns::
	.string "mi {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Si es posible, me gustaría que me\n"
	.string "aceptaras como compañero de equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept_hns::
	.string "¿Me aceptas de verdad?\n"
	.string "Menos mal, lo hubiese pasado fatal…\p"
	.string "¡Pero me has aceptado!\n"
	.string "¡Voy corriendo a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject_hns::
	.string "¿Mm? ¿Y se puede saber por qué no?\n"
	.string "¿Te piensas que tiene gracia?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro_hns::
	.string "¡Soy {STR_VAR_1}, una CHICA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1_hns::
	.string "Lo que tengo aquí es un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} y un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask_hns::
	.string "{STR_VAR_2} que usa {STR_VAR_1}.\n"
	.string "Es lo que me he traído.\p"
	.string "¿Quieres que seamos equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept_hns::
	.string "¡Muchas gracias!\n"
	.string "¡Voy a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject_hns::
	.string "¿Conque no soy buena para ti?\n"
	.string "¡Pues que sepas que lo vas a lamentar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro_hns::
	.string "¡Hola!\p"
	.string "¡Soy el JOVEN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1_hns::
	.string "¿Quieres saber lo que llevo conmigo?\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Quieres hacer un equipo conmigo,\n"
	.string "¿verdad?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept_hns::
	.string "¡Lo sabía!\n"
	.string "¡Voy a apuntarnos ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject_hns::
	.string "¡Qué palo! ¡Si formáramos un dúo\n"
	.string "tú y yo, no nos ganaría nadie!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro_hns::
	.string "¡Eco, eeeecooo!\n"
	.string "¡Soy el MONTAÑERO {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1_hns::
	.string "¿Sabes qué traigo conmigo? Mi\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask_hns::
	.string "mi {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Suena bien, ¿eh? ¿Formamos equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept_hns::
	.string "¡Jaroleri-leri-o!\n"
	.string "¡Voy a registrarnos antes \l"
	.string "de que cambies de opinión!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject_hns::
	.string "Qué pena, me habría gustado\n"
	.string "combatir a tu lado.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro_hns::
	.string "¡Hola!\n"
	.string "¡Soy la BELLA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1_hns::
	.string "¿Quieres ver lo que estoy entrenando?\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "¿Qué opinas?\n"
	.string "¿Los quieres en tu equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept_hns::
	.string "¡Qué estupendo!\n"
	.string "¡No te muevas, yo voy a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject_hns::
	.string "¡Qué decepción!\p"
	.string "¡Juntos habríamos sido los mejores!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro_hns::
	.string "¡Hola!\p"
	.string "¿Sabes quién soy?\n"
	.string "¡Soy {STR_VAR_1}, el PESCADOR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1_hns::
	.string "Traigo un equipo con un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask_hns::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Bueno, ¿qué te parece? ¿Lucharás a mi\n"
	.string "lado?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept_hns::
	.string "¡Bien, bien!\n"
	.string "¡Déjalo de mi cuenta!\p"
	.string "Voy a registrarnos ahora mismo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject_hns::
	.string "Lástima, éramos tal para cual…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro_hns::
	.string "Encantada de conocerte.\n"
	.string "Soy {STR_VAR_1}, una DAMISELA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1_hns::
	.string "En mi maravilloso equipo tengo\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Espero que te agraden, pues nada me\n"
	.string "haría más feliz que combatir a tu lado.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept_hns::
	.string "Te estoy agradecida.\n"
	.string "Voy a formalizar los trámites.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject_hns::
	.string "Humildemente, siento que terminarás\n"
	.string "por lamentar semejante decisión.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro_hns::
	.string "¡Soy {STR_VAR_1}, una TRIATLETA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1_hns::
	.string "A ver qué tengo aquí…\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}. ¡Esa\n"
	.string "es mi pareja!\p"
	.string "¿Por favor? ¿Formarás equipo\n"
	.string "conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept_hns::
	.string "¡Perfecto!\n"
	.string "¡Voy corriendo a apuntarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject_hns::
	.string "Oh. ¡Tú y yo podríamos\n"
	.string "haber hecho historia!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro_hns::
	.string "¿Qué tal?\n"
	.string "¡Soy el CAZABICHOS {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1_hns::
	.string "¡Mira lo que traigo en el morral!\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Así que escucha:\n"
	.string "¿Qué tal si unimos fuerzas?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept_hns::
	.string "¡Hecho!\p"
	.string "Voy al mostrador a hacer lo de la\n"
	.string "inscripción.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject_hns::
	.string "¿Cómo? ¿Con los POKéMON que tengo?\n"
	.string "¡Ya veremos si no te arrepientes!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro_hns::
	.string "¡Hola, hola! ¡Soy {STR_VAR_1},\n"
	.string "un ESCOLAR con mucha escuela!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1_hns::
	.string "Ahora estoy entrenando a un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask_hns::
	.string "y a un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1}.\p"
	.string "Envidia, ¿eh? Bueno, si quieres,\n"
	.string "nos unimos para luchar…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept_hns::
	.string "¡Bien dicho!\n"
	.string "¡Voy a rellenar la solicitud!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject_hns::
	.string "No esperaba oír eso…\p"
	.string "Me hubiese gustado aprender\n"
	.string "algo de ti…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro_hns::
	.string "Tú también sabes quién soy, ¿verdad?\n"
	.string "¡Soy {STR_VAR_1}, un NIÑO BIEN!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1_hns::
	.string "¡Yo siempre tengo lo mejor!\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Te voy a dar la oportunidad\n"
	.string "de luchar a mi lado.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept_hns::
	.string "¡Qué superguay!\p"
	.string "Espabila y prepárate mientras\n"
	.string "yo voy a registrarnos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject_hns::
	.string "¿Que vas tú y me rechazas?\n"
	.string "¡No! ¡Te rechazo yo antes a ti!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro_hns::
	.string "¡Kiaaaaaa!\n"
	.string "Soy el KARATEKA {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1_hns::
	.string "Yo estoy luchando con\n"
	.string "un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask_hns::
	.string "y un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Por favor, ¡concédeme este deseo!\n"
	.string "¡Déjame ser tu compañero!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept_hns::
	.string "¡Kiaaaaaaa!\n"
	.string "¡Voy corriendo a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject_hns::
	.string "Bien… Quizás cambies\n"
	.string "de opinión la próxima vez…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro_hns::
	.string "¡Hola, caracola!\n"
	.string "¡Soy {STR_VAR_1}, una PLAYERA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1_hns::
	.string "Te enseño lo que llevo.\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\n"
	.string "¿Me aceptas a tu lado?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept_hns::
	.string "¡Guay!\n"
	.string "¡Voy ahora mismo a apuntarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject_hns::
	.string "¡Si hubieses dicho que sí,\n"
	.string "tendríamos más futuro!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro_hns::
	.string "Je, je. Hola…\n"
	.string "Soy la BRUJITA {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1_hns::
	.string "Me acompañan un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask_hns::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}…\p"
	.string "Te lo ruego… Forma equipo conmigo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept_hns::
	.string "Te lo agradezco… Voy a inscribirnos…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject_hns::
	.string "Tenía tantas ganas de ir contigo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro_hns::
	.string "¿Qué tal? ¡Soy {STR_VAR_1} y soy\n"
	.string "CRIAPOKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1_hns::
	.string "Hoy llevo conmigo un {STR_VAR_2}\n"
	.string "con {STR_VAR_1} y también un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask_hns::
	.string "{STR_VAR_2} que usa {STR_VAR_1}…\p"
	.string "Te lo suplico…\n"
	.string "Formemos un equipo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept_hns::
	.string "¡Muchas gracias!\p"
	.string "Voy a encargarme de la inscripción,\n"
	.string "así que espera aquí.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject_hns::
	.string "Vaya, debe de haber\n"
	.string "un conjuro contra mi…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro_hns::
	.string "Encantado. ¡Me llamo {STR_VAR_1},\n"
	.string "y soy un CRIAPOKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1_hns::
	.string "¡Tengo dos POKéMON invencibles!\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "¿A que suena bien?\n"
	.string "No te cortes y lucha a mi lado.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept_hns::
	.string "¡Así me gusta!\p"
	.string "¡Termino la inscripción en un momento!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject_hns::
	.string "Tú y yo habríamos batido récords.\n"
	.string "Qué pena…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro_hns::
	.string "¡Hola! ¡Me llamo {STR_VAR_1}!\n"
	.string "¡Soy un TRIATLETA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1_hns::
	.string "Éstas son mis dos liebres:\n"
	.string "¡un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Si nos juntamos, podemos\n"
	.string "ganarlo todo. ¿Qué me dices?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept_hns::
	.string "¡La victoria es nuestra!\n"
	.string "¡Voy raudo y veloz a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject_hns::
	.string "Estaba dispuesto a darlo todo\n"
	.string "a tu lado…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro_hns::
	.string "¡Soy la LUCHADORA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1_hns::
	.string "He estado entrenando a un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask_hns::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "¿Te gusta la combinación? ¿Y si\n"
	.string "formamos equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept_hns::
	.string "¡Bien dicho!\p"
	.string "Ya que tú te has decidido,\n"
	.string "¡yo iré a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject_hns::
	.string "No pierdo la esperanza, quizás\n"
	.string "vuelvas en otra ocasión…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro_hns::
	.string "¡Soy {STR_VAR_1}, una TRIATLETA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1_hns::
	.string "Yo voy al gimnasio con un {STR_VAR_2}\n"
	.string "que sabe usar {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask_hns::
	.string "y con un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Creo que formaríamos un buen equipo.\n"
	.string "Tú decides…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept_hns::
	.string "¡Gracias!\p"
	.string "Voy a inscribirnos, ¡y ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject_hns::
	.string "Vaya, qué pena. ¡Habríamos sido el\n"
	.string "equipo más duro de todos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro_hns::
	.string "¿Yo?\n"
	.string "¡Soy {STR_VAR_1}, todo un PLAYERO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1_hns::
	.string "¿Que qué tengo aquí?\n"
	.string "Pues un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Ahora que lo sabes, supongo\n"
	.string "que querrás combatir a mi lado, ¿no?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept_hns::
	.string "¡Lo sabía!\p"
	.string "¡Voy a apuntarnos!\n"
	.string "¡Vamos a hacer algo grande!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject_hns::
	.string "Con lo fuertes que son mis POKéMON…\n"
	.string "Creo que te has precipitado.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro_hns::
	.string "¡A las muy buenas!\n"
	.string "¡Llámame GUITARRISTA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1_hns::
	.string "¡Mira qué banda he formado!\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "¿Suena bien, eh?\n"
	.string "¿Hacemos un dueto?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept_hns::
	.string "¡Música para mis oídos!\n"
	.string "¡Yo me encargo del papeleo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject_hns::
	.string "¡Vaya! ¡No reconocerías a un genio\n"
	.string "ni aunque lo tuvieses delante!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro_hns::
	.string "Es un honor.\n"
	.string "Soy el CABALLERO {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1_hns::
	.string "Me acompañan mi fiel {STR_VAR_2} que\n"
	.string "usa {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask_hns::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "¿Puedo pedirte que formes equipo\n"
	.string "conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept_hns::
	.string "Será un honor combatir a tu lado.\n"
	.string "Deja que yo me ocupe de la burocracia.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject_hns::
	.string "Qué desafortunada elección…\p"
	.string "Espero con impaciencia nuestro\n"
	.string "próximo encuentro…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro_hns::
	.string "Hola, soy {STR_VAR_1},\n"
	.string "y soy un POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1_hns::
	.string "Tengo un {STR_VAR_2} que sabe\n"
	.string "el movimiento {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Te gusta lo que ofrezco?\n"
	.string "¿Por qué no nos unimos?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept_hns::
	.string "¡Excelente!\n"
	.string "¡Voy a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject_hns::
	.string "Mis POKéMON son de lo mejor que hay…\n"
	.string "Es una pena que no sepas apreciarlos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro_hns::
	.string "¡Mm!\n"
	.string "Soy {STR_VAR_1}, un POKéABU.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1_hns::
	.string "Los POKéMON que entreno son\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Te alías con un experto como yo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept_hns::
	.string "¡Mm!\n"
	.string "¡Voy a registrarnos!\l"
	.string "¡Espero que tengamos suerte!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject_hns::
	.string "Espero que tu elección sea la\n"
	.string "más adecuada para ti…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro_hns::
	.string "Hola, hola.\n"
	.string "Soy {STR_VAR_1}, una POKéABU.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1_hns::
	.string "He entrenado mis POKéMON a conciencia.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}:\n"
	.string "eso es lo que tengo.\p"
	.string "¿Querrías aliarte conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept_hns::
	.string "Bien, bien, bien.\n"
	.string "Yo me encargo del papeleo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject_hns::
	.string "Quizás podamos formar\n"
	.string "un equipo la próxima vez.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro_hns::
	.string "¡Soy el DOMADRAGÓN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1_hns::
	.string "El equipo que he entrenado es\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¡Apuesto a que te gusta!\n"
	.string "¿Combatimos como equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept_hns::
	.string "¡Genial, voy a esforzarme de verdad!\n"
	.string "Prepárate, que voy a registrarnos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject_hns::
	.string "¡Te va a ser difícil encontrar a\n"
	.string "mejores ENTRENADORES que yo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro_hns::
	.string "¡Soy el ORNITÓLOGO {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1_hns::
	.string "¿Que cuáles son mis POKéMON?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿No te parece que haríamos\n"
	.string "un equipo fuera de serie?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept_hns::
	.string "¡Genial, a mí también!\n"
	.string "¡Yo me encargo de rellenar los papeles!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject_hns::
	.string "Mis POKéMON y yo somos muy buenos.\n"
	.string "¡Menuda decepción!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro_hns::
	.string "¡Soy {STR_VAR_1}, un CHICO NINJA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1_hns::
	.string "Mi equipo de POKéMON está formado por\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¡Vamos juntos a por todas!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept_hns::
	.string "¡Sí!\n"
	.string "¡Voy a registrarnos ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject_hns::
	.string "¡Creo que vas a echar de menos a mis\n"
	.string "POKéMON antes de lo que piensas!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro_hns::
	.string "¡Hola!\n"
	.string "¡Soy la DAMA PARASOL {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1_hns::
	.string "Haciéndome compañía están un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask_hns::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "¿A que son monos? ¿Te unes a nosotros\n"
	.string "en un equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept_hns::
	.string "¡Sabia decisión!\p"
	.string "Voy en volandas a registrarnos.\n"
	.string "¡Esperemos no fallarnos mutuamente!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject_hns::
	.string "Mis POKéMON no son sólo hermosos,\n"
	.string "también son fuertes. ¡Ignorante!…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro_hns::
	.string "Hola. Soy {STR_VAR_1},\n"
	.string "¡un auténtico BICHOMANÍACO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1_hns::
	.string "Ya tengo mis POKéMON, sí.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}:\n"
	.string "no hay nada mejor allá donde busques.\p"
	.string "¿Vas a aprovechar esta oportunidad\n"
	.string "única que te doy de combatir conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept_hns::
	.string "¡Genial!\n"
	.string "¡Comprendido!\p"
	.string "¡No tardaré en registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject_hns::
	.string "Con los POKéMON que he encontrado,\n"
	.string "no perderíamos nunca…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro_hns::
	.string "¡Echa el ancla!\n"
	.string "¡Soy el MARINERO {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1_hns::
	.string "¡Déjame mostrarte mi mercancía!\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask_hns::
	.string "¡un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Claro que no me vas a rechazar.\n"
	.string "Formaremos equipo, ¿verdad?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept_hns::
	.string "¡Bien dicho!\n"
	.string "¡Voy ahora mismo a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject_hns::
	.string "Has tirado por la borda una\n"
	.string "buena oportunidad, ¡no lo olvides!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro_hns::
	.string "Hola, me llamo {STR_VAR_1}.\n"
	.string "Soy un POKéCOLECTOR.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1_hns::
	.string "Las joyas de mi colección son\n"
	.string "mi {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask_hns::
	.string "mi {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Brillantes, eh?\n"
	.string "Deberíamos formar un equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept_hns::
	.string "¡Maravilloso!\p"
	.string "Venga, no perdamos tiempo.\n"
	.string "Voy a registrarnos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject_hns::
	.string "Pues que sepas que has perdido\n"
	.string "una ocasión de oro.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro_hns::
	.string "¡Choca ésa! ¡Me llamo {STR_VAR_1}!\n"
	.string "Soy un POKéGUARDA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1_hns::
	.string "Me hacen compañía un {STR_VAR_2} que\n"
	.string "usa {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask_hns::
	.string "¡un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "¿No crees que formaríamos un equipo\n"
	.string "impresionante?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept_hns::
	.string "¡Genial! Me encargo ahora de la\n"
	.string "inscripción.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject_hns::
	.string "La próxima vez, elige a mis POKéMON,\n"
	.string "¿vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro_hns::
	.string "Me llamo {STR_VAR_1}. ¡Soy POKéMON\n"
	.string "RANGER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1_hns::
	.string "Tengo a mi cargo un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Por poco que tengas tú, seguro\n"
	.string "que podemos hacer un buen equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept_hns::
	.string "¡Así se habla!\n"
	.string "¡Déjame encargarme del registro!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject_hns::
	.string "La próxima vez no te equivoques.\n"
	.string "Elige a mis POKéMON, ¿vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro_hns::
	.string "Me llamo {STR_VAR_1}.\n"
	.string "¡Soy una POKéGUARDA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1_hns::
	.string "Te resumo brevemente mi equipo:\n"
	.string "¡un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask_hns::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Espero que te gusten. ¿Quieres ser mi\n"
	.string "compañero?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept_hns::
	.string "Me halaga tu elección.\n"
	.string "Tardaré sólo un minuto en registrarnos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject_hns::
	.string "Sería estupendo que cambiases\n"
	.string "de opinión para la próxima vez.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro_hns::
	.string "¿Sabes quién soy yo?\n"
	.string "Soy {STR_VAR_1}, ¡un RUINAMANÍACO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1_hns::
	.string "Los POKéMON que tengo ahora son\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Intrigante, ¿verdad?\n"
	.string "¿Conquistamos juntos esta torre?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept_hns::
	.string "¡Bien! ¡Alea jacta est!\n"
	.string "Yo me ocupo de los papeles.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject_hns::
	.string "Habríamos hecho un equipo cuya fama\n"
	.string "perduraría por los siglos de los siglos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro_hns::
	.string "¡Soy {STR_VAR_1}, un ENTRENADOR GUAY!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1_hns::
	.string "Los POKéMON que tengo ahora a mi cargo\n"
	.string "son un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "¿Molan, eh?\p"
	.string "Creo que, si formamos un equipo,\n"
	.string "seremos la envidia de todos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept_hns::
	.string "¡Guay!\n"
	.string "¡Voy pitando a hacer el papeleo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject_hns::
	.string "Pensaba que formaríamos el mejor\n"
	.string "equipo de la historia.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro_hns::
	.string "¡Soy {STR_VAR_1}, un ENTRENADOR GUAY!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1_hns::
	.string "El equipo que he criado tiene un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Te parece bien? ¿Y si formamos\n"
	.string "pareja?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept_hns::
	.string "¡Perfecto! Será mejor que haga la\n"
	.string "inscripción.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject_hns::
	.string "Y yo que pensaba que seríamos un\n"
	.string "equipo durísimo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro_hns::
	.string "¡Eh! ¡Soy {STR_VAR_1}, el POKéMANÍACO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1_hns::
	.string "¿Que qué tiene alguien como yo? ¡Un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}, eso\n"
	.string "tengo!\p"
	.string "¡Vamos allá! ¡Arrasaremos como equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept_hns::
	.string "¡Buena elección! ¡Nos inscribo a los\n"
	.string "dos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject_hns::
	.string "¡Mis POKéMON son brutales! ¡No es\n"
	.string "culpa mía si te arrepientes!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro_hns::
	.string "¡Hola, me llamo {STR_VAR_1}!\n"
	.string "¡Soy una ENTRENADORA GUAY!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1_hns::
	.string "El equipo que estoy formando tiene\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "No te quejarás, ¿verdad?\n"
	.string "¿A que quieres combatir a mi lado?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept_hns::
	.string "¡Bien por ese espíritu ganador!\n"
	.string "Voy a apuntarnos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject_hns::
	.string "Prométeme que formarás equipo\n"
	.string "conmigo la próxima vez que nos veamos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro_hns::
	.string "¡Soy {STR_VAR_1} y soy CAMPISTA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1_hns::
	.string "He estado criando a un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask_hns::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "¿Crees que sería divertido formar\n"
	.string "equipo? ¡Seguro que sí!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept_hns::
	.string "¡Bien dicho!\n"
	.string "¡Voy volando a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject_hns::
	.string "¡Mis POKéMON son los mejores!\n"
	.string "¡No me digas que no te avisé!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro_hns::
	.string "¡Eh, hooola!\n"
	.string "¡Soy el FOGONERO {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1_hns::
	.string "Tengo una receta infalible para ganar:\n"
	.string "¡un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "¿Qué me dices?\n"
	.string "¿Formamos una piña?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept_hns::
	.string "¡Vamos a darnos una panzada de ganar!\n"
	.string "¡Yo me encargo de registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject_hns::
	.string "Espero que cambies de opinión\n"
	.string "la próxima vez que nos veamos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro_hns::
	.string "¡Soy {STR_VAR_1}, un CAMPISTA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1_hns::
	.string "He estado entrenando un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} y un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask_hns::
	.string "{STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "¿Te apetece que salgamos\n"
	.string "juntos al campo de batalla?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept_hns::
	.string "¡Bravo!\n"
	.string "¡Voy corriendo a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject_hns::
	.string "Bueno, quizás la próxima vez, ¿vale?\n"
	.string "Estoy deseando combatir junto a ti.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro_hns::
	.string "¡Hola! ¡Me llamo {STR_VAR_1}, y confieso\n"
	.string "que soy una auténtica DOMINGUERA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1_hns::
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask_hns::
	.string "y un {STR_VAR_2} que usa {STR_VAR_1}:\n"
	.string "ésos son mis dos POKéMON.\p"
	.string "¿Quieres combatir a mi lado\n"
	.string "a ver hasta dónde llegamos?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept_hns::
	.string "¡Ooh, muchas gracias!\n"
	.string "¡Voy a registrarnos ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject_hns::
	.string "¿Me dejarás combatir junto a ti\n"
	.string "la próxima vez? Anda, porfa…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro_hns::
	.string "¡Soy {STR_VAR_1}, ESCOLAR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1_hns::
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask_hns::
	.string "y un {STR_VAR_2} que usa {STR_VAR_1}\n"
	.string "son mi pareja de POKéMON.\p"
	.string "¿Puedo ser tu compañero de equipo,\n"
	.string "por favor?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept_hns::
	.string "¡Oh, gracias! ¡Me inscribo en el\n"
	.string "mostrador ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject_hns::
	.string "¿Por favor? ¿Puedo ir contigo la\n"
	.string "próxima vez?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro_hns::
	.string "¡Eh! ¡Me llamo {STR_VAR_1}!\n"
	.string "¡Soy una CRIAPOKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1_hns::
	.string "Los POKéMON que he criado son un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask_hns::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "¿Suena interesante? ¿Y si formamos\n"
	.string "equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept_hns::
	.string "¡Qué genial!\n"
	.string "¡Deja de mi cuenta lo de registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject_hns::
	.string "Pero, entonces, cuento contigo\n"
	.string "para la próxima vez, ¿de acuerdo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro_hns::
	.string "Soy {STR_VAR_1}, y puedo decir con\n"
	.string "orgullo que soy una POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1_hns::
	.string "Estoy enamorada de mis dos POKéMON:\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿A que son dos auténticas monadas?\n"
	.string "¡Tú y yo tenemos que hacer un equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept_hns::
	.string "¡Qué estupendísimo!\n"
	.string "¡Voy a registrarnos en un plis!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject_hns::
	.string "¿Cómo te atreves a hacerles ese feo\n"
	.string "a mis POKéMON? ¡No tienes perdón!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro_hns::
	.string "Hola, soy la NADADORA {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1_hns::
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask_hns::
	.string "y un {STR_VAR_2} que usa {STR_VAR_1}\n"
	.string "es lo que he entrenado.\p"
	.string "Tú y yo, formemos un equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept_hns::
	.string "¡De cabeza, eso es!\n"
	.string "¡Voy corriendo a hacer el papeleo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject_hns::
	.string "¡Menudo jarro de agua fría!\n"
	.string "¡Bueno, la próxima vez, entonces!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro_hns::
	.string "¿Qué tal?\n"
	.string "Soy {STR_VAR_1}, un TRIATLETA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1_hns::
	.string "Tengo un par de POKéMON decentes.\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "¡Me encantaría formar un equipo\n"
	.string "contigo! ¿Qué me dices?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept_hns::
	.string "¡Estupendo!\n"
	.string "Voy a registrarnos, ¿vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject_hns::
	.string "Espero que cambies de opinión\n"
	.string "la próxima vez que nos veamos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro_hns::
	.string "¡Soy la TRIATLETA {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1_hns::
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask_hns::
	.string "otro {STR_VAR_2} que sabe usar\n"
	.string "{STR_VAR_1}. Ésa es mi pareja.\p"
	.string "No está nada mal, ¿eh?\n"
	.string "Haríamos un buen equipo, ¿qué me dices?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept_hns::
	.string "¡Ésa es la respuesta que esperaba!\n"
	.string "¡Un segundo, que voy a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject_hns::
	.string "Bueno, espero que la próxima vez\n"
	.string "me des una oportunidad.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro_hns::
	.string "¡Hola! ¿Cómo te va?\n"
	.string "Soy {STR_VAR_1}, y soy un NADADOR.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1_hns::
	.string "¡Alucina con lo que tengo!\n"
	.string "¡Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask_hns::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "¿Una pareja guapa, eh?\n"
	.string "¡Estamos listos para formar equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept_hns::
	.string "¡Menuda oportunidad!\n"
	.string "¡Gracias, voy a registrarnos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject_hns::
	.string "Si nos volvemos a ver,\n"
	.string "vas a decir que sí, ¿verdad?$"

