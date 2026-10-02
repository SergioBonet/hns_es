AzaleaTown_KurtsHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AzaleaTown_KurtsHouse_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_KurtsHouse_OnTransition
	.byte 0

AzaleaTown_KurtsHouse_OnTransition::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_ReturnFromWellSetup
	end

AzaleaTown_KurtsHouse_OnFrame::
	map_script_2 VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_ReturnFromWell
	.2byte 0

AzaleaTown_KurtsHouse_EventScript_KurtBefore::
	lock
	faceplayer
	msgbox KurtsHouse_Text_KurtMakingBallsMustWait, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, AzaleaTown_KurtsHouse_EventScript_PlayerMove
	applymovement LOCALID_AZALEA_TOWN_KURT_BEFORE, AzaleaTown_KurtsHouse_Movement_KurtWalkDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_AZALEA_TOWN_KURT_BEFORE
	setflag FLAG_HIDE_KURT_1
	setflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	setvar VAR_AZALEA_TOWN_STATE, 2
	release
	end

AzaleaTown_KurtsHouse_EventScript_PlayerMove::
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_KurtsHouse_Movement_Player
	waitmovement 0
	applymovement LOCALID_AZALEA_TOWN_KURT_BEFORE, AzaleaTown_KurtsHouse_Movement_KurtWalkDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_AZALEA_TOWN_KURT_BEFORE
	setflag FLAG_HIDE_KURT_1
	setflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_KURT_2, AzaleaTown_KurtsHouse_EventScript_Girl2
	goto_if_set FLAG_HIDE_KURT_1, AzaleaTown_KurtsHouse_EventScript_Girl3
	msgbox KurtsHouse_Text_GranddaughterSlowpokeGone, MSGBOX_DEFAULT
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl2::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 4, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_KurtsHouse_EventScript_Girl5
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, AzaleaTown_KurtsHouse_EventScript_Girl5

	msgbox KurtsHouse_Text_GranddaughterDad, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl3::
	msgbox KurtsHouse_Text_GranddaughterLonely, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl4::
	msgbox KurtsHouse_Text_GranddaughterSlowpokeBack, MSGBOX_DEFAULT
	closemessage
	release
	end	

AzaleaTown_KurtsHouse_EventScript_Girl5::
	msgbox KurtsHouse_Text_GranddaughterSound, MSGBOX_DEFAULT
	closemessage
	release
	end	

AzaleaTown_KurtsHouse_EventScript_ReturnFromWellSetup::
	setobjectmovementtype LOCALID_AZALEA_TOWN_KURT, MOVEMENT_TYPE_FACE_DOWN
	end

AzaleaTown_KurtsHouse_EventScript_ReturnFromWell::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox KurtsHouse_Text_KurtHonoredToMakeBalls, MSGBOX_DEFAULT
	giveitem ITEM_FAST_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtBallsFromApricorns, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	setvar VAR_AZALEA_TOWN_STATE, 4
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtCheckGSBall::
	checkitem ITEM_GS_BALL
	goto_if_eq VAR_RESULT, TRUE, AzaleaTown_KurtsHouse_EventScript_KurtGsBall
	return

AzaleaTown_KurtsHouse_EventScript_Kurt::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_KurtsHouse_EventScript_KurtGsBall2
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, AzaleaTown_KurtsHouse_EventScript_KurtGsBall3
	msgbox KurtsHouse_Text_KurtAskYouHaveAnApricorn, MSGBOX_DEFAULT
	closemessage
	call_if_unset FLAG_CAUGHT_CELEBI, AzaleaTown_KurtsHouse_EventScript_KurtCheckGSBall
AzaleaTown_KurtsHouse_EventScript_Kurt2::
	special CreateKurtBallShop
	waitstate
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_KurtCancel
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	call_if_eq VAR_FACING, DIR_EAST, AzaleaTown_KurtsHouse_EventScript_TurnWest
	call_if_eq VAR_FACING, DIR_WEST, AzaleaTown_KurtsHouse_EventScript_TurnEast
	call_if_eq VAR_FACING, DIR_NORTH, AzaleaTown_KurtsHouse_EventScript_TurnSouth
	goto_if_eq VAR_0x8005, 1, AzaleaTown_KurtsHouse_EventScript_SingularBall
	bufferitemname STR_VAR_1, VAR_0x8004
	buffernumberstring STR_VAR_2, VAR_0x8005
	msgbox KurtsHouse_Text_KurtFinishedPlural, MSGBOX_DEFAULT
	message KurtsHouse_Text_KurtObtainedPlural
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	additem VAR_0x8004, VAR_0x8005
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_TurnSouth::
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_SOUTH
	return
AzaleaTown_KurtsHouse_EventScript_TurnWest::
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_WEST
	return
AzaleaTown_KurtsHouse_EventScript_TurnEast::
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_EAST
	return


AzaleaTown_KurtsHouse_EventScript_SingularBall::
	bufferitemname STR_VAR_1, VAR_0x8004
	msgbox KurtsHouse_Text_KurtFinishedSingular, MSGBOX_DEFAULT
	message KurtsHouse_Text_KurtObtainedSingular
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	additem VAR_0x8004, VAR_0x8005
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtCancel::
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtGsBall::
	msgbox KurtsHouse_Text_KurtWhatIsThat, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_GS_BALL
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtThisBallStartedToShake, MSGBOX_DEFAULT
	closemessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_AZALEA_TOWN_KURT, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	waitse
	playse SE_M_PETAL_DANCE
	waitse
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Look_Around
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTownKurt_Movement_Look_Around
	waitmovement 0
	waitmovement 0
AzaleaTown_KurtsHouse_EventScript_KurtGsBall2::
	msgbox KurtsHouse_Text_Kurt_Whatwasthat, MSGBOX_DEFAULT
	setvar VAR_AZALEA_TOWN_STATE, 8
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtGsBall3::
	msgbox KurtsHouse_Text_Forest, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox KurtsHouse_Text_BallAnyway, MSGBOX_DEFAULT
	closemessage
	goto AzaleaTown_KurtsHouse_EventScript_Kurt2
	release
	end
KurtsHouse_Text_BallAnyway:
	.string "Bueno, ¿quieres que te haga unas\n"
	.string "BALLS?$"

AzaleaTown_KurtsHouse_EventScript_OakPhoto::
	msgbox KurtsHouse_Text_OakPhoto, MSGBOX_SIGN
	closemessage
	end

AzaleaTown_KurtsHouse_EventScript_CelebiStatue::
	msgbox KurtsHouse_Text_CelebiStatue, MSGBOX_SIGN
	closemessage
	end

AzaleaTownKurt_Movement_Look_Around:
	face_left
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_down
	delay_8
	face_left
	step_end

AzaleaTownKurt_Movement_Making_Ball:
	face_up
	walk_in_place_fast_up
	delay_8
	walk_in_place_fast_up
	delay_8
	walk_in_place_fast_up
	step_end

AzaleaTown_KurtsHouse_Movement_Player:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

AzaleaTown_KurtsHouse_Movement_KurtWalkDown:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

KurtsHouse_Text_KurtGetStarted:
	.string "CÉSAR: ¡Me pongo ahora mismo!$"

KurtsHouse_Text_KurtMakingBallsMustWait:
	.string "¿Mmm? ¿Quién eres?\p"
	.string "¿{PLAYER}, dices? ¿Quieres que te haga\n"
	.string "unas BALLS?\p"
	.string "Lo siento, pero tendrá que esperar.\p"
	.string "¿Conoces al TEAM ROCKET? Ah, no te\n"
	.string "preocupes.\p"
	.string "Te lo cuento de todos modos.\p"
	.string "El TEAM ROCKET es una banda malvada\n"
	.string "que usa a los POKéMON para sus\l"
	.string "fechorías.\p"
	.string "Se supone que se disolvió hace tres\n"
	.string "años.\p"
	.string "El caso es que están en el POZO,\n"
	.string "¡cortándoles la COLA a los SLOWPOKE\l"
	.string "para venderlas!\p"
	.string "¡Así que voy a darles una lección que\n"
	.string "no olvidarán!\p"
	.string "¡Aguantad, SLOWPOKE! ¡El viejo CÉSAR\n"
	.string "va de camino!$"

KurtsHouse_Text_KurtHonoredToMakeBalls:
	.string "CÉSAR: ¡{PLAYER}!\p"
	.string "Te has portado como nadie en el POZO.\p"
	.string "¡Tienes estilo!\p"
	.string "Sería un honor hacer alguna BALL\p"
	.string "para alguien como tú.\p"
	.string "Ahora sólo tengo ésta. Tuya es.$"

KurtsHouse_Text_KurtBallsFromApricorns:
	.string "CÉSAR: Yo hago BALLS con BAYAS.\p"
	.string "Recógelas de los árboles y tráemelas.\p"
	.string "Yo las convertiré en POKé BALLS.$"

KurtsHouse_Text_KurtAskYouHaveAnApricorn:
	.string "CÉSAR: ¿Tienes BAYAS para mí?\p"
	.string "¡Muy bien! Las convertiré en POKé\n"
	.string "BALLS.$"

KurtsHouse_Text_KurtThatsALetdown:
	.string "CÉSAR: ¡No veo ninguna {STR_VAR_1}!$"

KurtsHouse_Text_KurtFinishedPlural:
	.string "CÉSAR: ¡{PLAYER}! Tus {STR_VAR_1} ya\n"
	.string "están listas. ¡Toma!$"

KurtsHouse_Text_KurtObtainedPlural:
	.string "¡{PLAYER} ha obtenido {STR_VAR_2}\n"
	.string "{STR_VAR_1}!$"

KurtsHouse_Text_KurtFinishedSingular:
	.string "CÉSAR: ¡{PLAYER}! Tu {STR_VAR_1} ya\n"
	.string "está lista. ¡Toma!$"

KurtsHouse_Text_KurtObtainedSingular:
	.string "¡{PLAYER} ha obtenido {STR_VAR_1}!$"

KurtsHouse_Text_KurtTurnedOutGreat:
	.string "CÉSAR: Ha salido muy bien.\p"
	.string "Intenta capturar POKéMON con ella.$"

KurtsHouse_Text_KurtWhatIsThat:
	.string "¿Q-qué es eso?\p"
	.string "Nunca había visto nada igual.\p"
	.string "Parece una POKé BALL, pero no lo es.\p"
	.string "Déjame que le eche un vistazo.$"

KurtsHouse_Text_KurtImCheckingItNow:
	.string "Estoy viéndolo.$"

KurtsHouse_Text_KurtAhHaISee:
	.string "¡Ajá! ¡Ya veo! Entonces…$"

KurtsHouse_Text_KurtThisBallStartedToShake:
	.string "¡{PLAYER}!\p"
	.string "Esta BALL comenzó a agitarse cuando\n"
	.string "la examinaba.\p"
	.string "¡Tiene que haber algo!$"

KurtsHouse_Text_Kurt_Whatwasthat:
	.string "¿Qué ha sido ese ruido?\p"
	.string "¡Vamos fuera a ver qué pasa!$"

KurtsHouse_Text_GranddaughterSlowpokeGone:
	.string "Los SLOWPOKE se han ido…\p"
	.string "¿Se los ha llevado la gente mala?$"

KurtsHouse_Text_GranddaughterLonely:
	.string "El abuelo se fue. Estoy tan sola…$"

KurtsHouse_Text_GranddaughterSlowpokeBack:
	.string "¡El SLOWPOKE que me regaló mi padre ha\n"
	.string "vuelto!\p"
	.string "¡Y su COLA vuelve a crecer!$"

KurtsHouse_Text_GranddaughterDad:
	.string "Papá trabaja en SILPH y estudia las\n"
	.string "POKé BALL.\p"
	.string "Tengo que quedarme en casa con el\n"
	.string "abuelo y SLOWPOKE.$"

KurtsHouse_Text_GranddaughterHelp:
	.string "¡Estoy ayudando al abuelo!\p"
	.string "¡Haremos buenas BALL para ti, así que\n"
	.string "espera!$"

KurtsHouse_Text_GranddaughterFun:
	.string "¡Hacer BALL es divertido!$"

KurtsHouse_Text_GranddaughterSound:
	.string "¿Ese ruido venía del ENCINAR?$"

KurtsHouse_Text_Forest:
	.string "¿Ya has mirado en el ENCINAR? Se oye\n"
	.string "mucho jaleo.$"

KurtsHouse_Text_Slowpoke:
	.string "SLOWPOKE: ¡Mmm! (Bostezo).$"

KurtsHouse_Text_OakPhoto:
	.string "¿Un joven PROF. OAK?$"

KurtsHouse_Text_CelebiStatue:
	.string "Es una estatua del guardián del\n"
	.string "encinar.$"
