Route24_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route24_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route24_OnTransition:
	call_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_MapScript_SetRocketScene
	callnative SetTimeBasedEncounters
	end

Route24_MapScript_SetRocketScene:
	setobjectxyperm LOCALID_ROUTE24_GRUNT, 16, 8
	setobjectxyperm LOCALID_ROUTE24_WOMAN, 16, 9
	setobjectmovementtype LOCALID_ROUTE24_GRUNT, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_ROUTE24_WOMAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_ROUTE24_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

Route24_EventScript_Woman::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_WomanRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_WomanAfterRocket
	msgbox Route24_Text_Woman, MSGBOX_NPC
	end

Route24_EventScript_WomanRocket::
	msgbox Route24_Text_WomanRocket, MSGBOX_NPC
	end

Route24_EventScript_WomanAfterRocket::
	msgbox Route24_Text_WomanAfterRocket, MSGBOX_NPC
	end

Route24_EventScript_Man::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_ManRocket
		goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_ManAfterRocket
	msgbox Route24_Text_Man, MSGBOX_NPC
	end

Route24_EventScript_ManRocket::
	msgbox Route24_Text_ManRocket, MSGBOX_NPC
	end

Route24_EventScript_ManAfterRocket::
	msgbox Route24_Text_ManAfterRocket, MSGBOX_NPC
	end

Route24_Trigger_GruntScene::
	lock
	playse SE_PIN
	applymovement2 LOCALID_ROUTE24_GRUNT Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE24_GRUNT
	applymovement2 LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntHide
	delay 10
	applymovement2 LOCALID_ROUTE24_WOMAN, Route24_Movement_WomanMove
	waitmovement 0
	turnobject LOCALID_ROUTE24_MAN, DIR_SOUTH
	setvar VAR_KANTO_ROCKET_STORY_STATE, 4
	call Route24_MapScript_SetRocketScene
	release
	end

Route24_Movement_GruntHide:
	walk_fast_left
	walk_fast_left
	step_end

Route24_Movement_WomanMove:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	face_up
	step_end

Route24_EventScript_Grunt::
	lock
	faceplayer
	msgbox Route24_Text_RocketSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_31_HNS, Route24_Text_RocketBeaten
	msgbox Route24_Text_RocketAfter, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 LOCALID_ROUTE24_GRUNT, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ROUTE24_GRUNT
	msgbox Route24_Text_RocketDisappears, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route24_Movement_PlayerSlide
	delay 20
	applymovement LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntLeave
	waitmovement LOCALID_ROUTE24_GRUNT
	setflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	removeobject LOCALID_ROUTE24_GRUNT
	setvar VAR_KANTO_ROCKET_STORY_STATE, 5
	clearflag FLAG_HIDDEN_ITEM_MACHINE_PART
	release
	end

Route24_Movement_PlayerSlide:
	delay_16
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	face_down
	step_end

Route24_Movement_GruntLeave:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route24_Text_RocketSeen:
	.string "¡Eh, tú! ¡Un miembro del TEAM ROCKET\n"
	.string "ser yo!\p"
	.string "Ser de otro país. Entrenador número\n"
	.string "uno, ¡yo ése!\p"
	.string "Pensar hice. Si cortar energía, ¡mucho\n"
	.string "pánico aquí todos!\p"
	.string "Misión secreta es, ¡no contar a ti!\p"
	.string "Pero, si ganar a mí, un hombre soy y\n"
	.string "secreto mío a ti contar.\p"
	.string "¡Eh, tú! ¡Lucha empezar!$"

Route24_Text_RocketBeaten:
	.string "¡Ayyy! ¡No, no, no, creerlo no puedo!\p"
	.string "¡Fuerte muchísimo ser tú! ¡Rival para\n"
	.string "ti no soy yo!$"

Route24_Text_RocketAfter:
	.string "Vale. ¿Contarte mi secreto debo? La\n"
	.string "MAQUINARIA robé yo, en el GIMNASIO de\l"
	.string "CELESTE la escondí.\p"
	.string "Dentro del agua la puse. Buscar en el\n"
	.string "agua del centro del GIMNASIO tú\l"
	.string "debes.\p"
	.string "¡Pero olvidarme tú no!\p"
	.string "Vencerte seguro el TEAM ROCKET lo\n"
	.string "hará.\p"
	.string "De JOHTO vendrán ellos, mis amigos, sí.\n"
	.string "Vengarse ellos harán.$"

Route24_Text_RocketDisappears:
	.string "…\p"
	.string "¿Qué dices tú? ¿Adiós, adiós el TEAM\n"
	.string "ROCKET? ¿Disuelto dices tú que está?\p"
	.string "¡Oh, no! ¿Qué hacer ahora yo debo?$"



Route24_Text_Woman:
	.string "¿A que son preciosas las vistas?$"
Route24_Text_Man:
	.string "Podría quedarme aquí todo el día.$"

Route24_Text_WomanRocket:
	.string "¡A mí nadie me empuja!$"
Route24_Text_ManRocket:
	.string "¡A mi novia nadie la empuja!$"

Route24_Text_WomanAfterRocket:
	.string "¿Qué ha sido eso?$"
Route24_Text_ManAfterRocket:
	.string "¿Era un ROCKET?$"
