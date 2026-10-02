EcruteakCity_Theater_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_Theater_OnTransition
	.byte 0

EcruteakCity_Theater_OnTransition::
	call_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_MapScript_SetRocketSceneActive
	call_if_eq VAR_ECRUTEAK_CITY_THEATER, 8, EcruteakCity_Theater_MapScript_SetKimonoMovement
	end

EcruteakCity_Theater_MapScript_SetRocketSceneActive::
	setobjectxyperm LOCALID_ECRUTEAK_ZUKI, 10, 2
	setobjectmovementtype LOCALID_ECRUTEAK_ROCKET, MOVEMENT_TYPE_TOWER_BEAM
	return

EcruteakCity_Theater_MapScript_SetKimonoMovement::
	setobjectmovementtype LOCALID_ECRUTEAK_ZUKI, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_NAOKO, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_MIKI, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_SAYO, MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_KUNI, MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_SISTER, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	return

EcruteakCity_Theater_EventScript_RocketEventTrigger::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 60
	turnobject LOCALID_ECRUTEAK_ROCKET, DIR_NORTH
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, EcruteakCity_Theater_Movement_CameraPanUp
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	msgbox EcruteakCity_Theater_Text_KimonoRocket1, MSGBOX_DEFAULT
	closemessage
	msgbox EcruteakCity_Theater_Text_Rocket2, MSGBOX_DEFAULT
	applymovement LOCALID_ECRUTEAK_ZUKI, EcruteakCity_Theater_Movement_KimonoGirlMoveBack
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_Rocket3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ECRUTEAK_ROCKET, EcruteakCity_Theater_Movement_RocketDance
	delay 50
	applymovement OBJ_EVENT_ID_CAMERA, EcruteakCity_Theater_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setobjectmovementtype LOCALID_ECRUTEAK_ROCKET, MOVEMENT_TYPE_TOWER_BEAM
	setobjectxyperm LOCALID_ECRUTEAK_ZUKI, 10, 2
	setvar VAR_ECRUTEAK_CITY_THEATER, 1
	releaseall
	end

EcruteakCity_Theater_Movement_RocketDance:
	walk_in_place_down
	delay_2
	walk_in_place_right
	delay_2
	face_up
	delay_2
	face_left
	delay_8
	walk_in_place_down
	delay_2
	walk_in_place_left
	delay_2
	face_up
	delay_8
	face_right
	step_end

EcruteakCity_Theater_Movement_CameraPanUp:
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

EcruteakCity_Theater_Movement_CameraPanDown:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

EcruteakCity_Theater_Movement_KimonoGirlMoveBack:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

EcruteakCity_Theater_Text_Rocket1:
	.string "ROCKET: ¡Deja de bailar un baile tan\n"
	.string "serio! ¡Enséñame algo como un hula!$"

EcruteakCity_Theater_Text_KimonoRocket1:
	.string "CHICA KIMONO: … No deberías insistir\n"
	.string "en una petición así.$"

EcruteakCity_Theater_Text_Rocket2:
	.string "ROCKET: ¿Eh?\p"
	.string "¿Me estás diciendo que no respetas lo\n"
	.string "que quiere el cliente?$"

EcruteakCity_Theater_Text_Rocket3:
	.string "¿Hace falta que haga una\n"
	.string "demostración? ¡Fíjate bien en cómo\l"
	.string "hay que mover las caderas! ¡Ja, ja, ja,\l"
	.string "ja!\p"
	.string "$"

EcruteakCity_Theater_EventScript_Rocket::
	lock
	faceplayer
	msgbox EcruteakCity_Theater_Text_RocketSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_33_HNS, EcruteakCity_Theater_Text_RocketBeaten
	msgbox EcruteakCity_Theater_Text_RocketAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ECRUTEAK_ROCKET, EcruteakCity_Theater_Movement_RocketLeave
	waitmovement 0
	setflag FLAG_HIDE_ECRUTEAK_ROCKET
	removeobject LOCALID_ECRUTEAK_ROCKET
	call_if_eq VAR_FACING, DIR_EAST, EcruteakCity_Theater_EventScript_PostRocketLeft
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_Theater_EventScript_PostRocketRight
	call_if_eq VAR_FACING, DIR_SOUTH, EcruteakCity_Theater_EventScript_PostRocketTop
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox EcruteakCity_Theater_Text_KimonoRocket3, MSGBOX_DEFAULT
	closemessage	
	setvar VAR_ECRUTEAK_CITY_THEATER, 2
	release
	end
	
EcruteakCity_Theater_EventScript_PostRocketLeft::
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkDown1
	waitmovement 0
	return

EcruteakCity_Theater_EventScript_PostRocketRight::
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkRight1
	waitmovement 0
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkDown1
	waitmovement 0
	return

EcruteakCity_Theater_EventScript_PostRocketTop::
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

EcruteakCity_Theater_Movement_RocketLeave:
	jump_2_down
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

EcruteakCity_Theater_Text_RocketSeen:
	.string "¿Eh? ¿Y tú qué quieres?\p"
	.string "¡Estoy en plena coreografía!\p"
	.string "$"

EcruteakCity_Theater_Text_RocketBeaten:
	.string "¡Pero yo no soy un esbirro cualquiera!\p"
	.string "$"

EcruteakCity_Theater_Text_RocketAfter:
	.string "¡Uy! ¡Tengo una misión importante! ¡Si\n"
	.string "se enteran de que estaba perdiendo el\l"
	.string "tiempo aquí, me harán empezar de\l"
	.string "nuevo como el SOLDADO ROCKET más\l"
	.string "bajo!\p"
	.string "¡Será mejor que me vaya!$"

EcruteakCity_Theater_Text_KimonoRocket3:
	.string "Tú debes de ser {PLAYER}, ¿verdad? Ha\n"
	.string "sido excelente, sin duda.\p"
	.string "Amable y fuerte… Y además sabes criar\n"
	.string "POKéMON…\p"
	.string "Esa persona sí que sabe qué buscar en\n"
	.string "la gente…\p"
	.string "¡Ojojó! Solo hablaba conmigo misma. No\n"
	.string "me hagas caso.$"


EcruteakCity_Theater_EventScript_KimonoGirl::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 6, EcruteakCity_Theater_EventScript_KimonoGirlDuringEvent
	msgbox EcruteakCity_Theater_Text_KimonoDone, MSGBOX_DEFAULT
	closemessage
	release
	end
EcruteakCity_Theater_EventScript_KimonoGirlDuringEvent::
	msgbox EcruteakCity_Theater_Text_KimonoGirlsBeforeBattle, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_Theater_EventScript_Zuki::
	lock
	faceplayer
	goto_if_ge VAR_ECRUTEAK_CITY_THEATER, 8, EcruteakCity_Theater_EventScript_ZukiAfterLegendary
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 6, EcruteakCity_Theater_EventScript_ZukiBattle
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_ZukiDuringRocket
	msgbox EcruteakCity_Theater_Text_Kimono, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_ZukiAfterLegendary::
	msgbox EcruteakCity_Theater_Text_ZukiAfterAll, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_ZukiDuringRocket::
	msgbox EcruteakCity_Theater_Text_KimonoGirlBeaten, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_Text_Kimono:
	.string "Cada día sin excepción practicamos\n"
	.string "nuestra danza en este escenario de la\l"
	.string "vida.\p"
	.string "Y, de igual modo, ni un solo día\n"
	.string "eludimos el cuidado de nuestros\l"
	.string "POKéMON para que, poco a poco, vayan\l"
	.string "progresando.$"

EcruteakCity_Theater_EventScript_SurfGuy::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_SurfGuyDuringRocket
	goto_if_unset FLAG_RECEIVED_HM_SURF, EcruteakCity_Theater_EventScript_SurfGuy_GiveSurf
	msgbox EcruteakCity_Theater_Text_SurfGuyAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_SurfGuy_GiveSurf::
	msgbox EcruteakCity_Theater_Text_SurfGuyGiveSurf, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox EcruteakCity_Theater_Text_SurfGuyGaveSurf
	closemessage
	setflag FLAG_RECEIVED_HM_SURF
	setvar VAR_ECRUTEAK_CITY_THEATER, 3
	release
	end

EcruteakCity_Theater_EventScript_SurfGuyDuringRocket::
	msgbox EcruteakCity_Theater_Text_SurfGuyRocket, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_TriggerSurfGuy::
	lock
	applymovement LOCALID_SURF_GUY, EcruteakCity_Theater_Movement_SurfGuy1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox EcruteakCity_Theater_Text_SurfGuyGiveSurf, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox EcruteakCity_Theater_Text_SurfGuyGaveSurf
	closemessage
	setflag FLAG_RECEIVED_HM_SURF
	setvar VAR_ECRUTEAK_CITY_THEATER, 3
	applymovement LOCALID_SURF_GUY, EcruteakCity_Theater_Movement_SurfGuy2
	waitmovement 0 
	release
	end

EcruteakCity_Theater_EventScript_Psyduck::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	msgbox EcruteakCity_Theater_Text_Psyduck, MSGBOX_DEFAULT
	waitmoncry
	release
	end


EcruteakCity_Theater_EventScript_Boy::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_BoyDuringRocket
	msgbox EcruteakCity_Theater_Text_Boy, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_BoyDuringRocket::
	msgbox EcruteakCity_Theater_Text_BoyBefore, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_Theater_EventScript_Granny::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_GrannyDuringRocket
	msgbox EcruteakCity_Theater_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_GrannyDuringRocket::
	msgbox EcruteakCity_Theater_Text_GrannyBefore, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_Theater_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_GrampsDuringRocket
	msgbox EcruteakCity_Theater_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_GrampsDuringRocket::
	msgbox EcruteakCity_Theater_Text_GrampsBefore, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_Girl::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_GirlDuringRocket
	msgbox EcruteakCity_Theater_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_GirlDuringRocket::
	msgbox EcruteakCity_Theater_Text_GirlBefore, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_FancyPanel::
	lock
	msgbox EcruteakCity_Theater_Text_FancyPanel, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_Movement_SurfGuy1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

EcruteakCity_Theater_Movement_SurfGuy2:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EcruteakCity_Theater_Text_SurfGuyRocket:
	.string "¿Qué pretende ese SOLDADO del TEAM\n"
	.string "ROCKET metiéndose con esa CHICA\l"
	.string "KIMONO?\p"
	.string "Eres ENTRENADOR, ¿verdad? ¡Ayúdala,\n"
	.string "por favor!$"

EcruteakCity_Theater_Text_SurfGuyGiveSurf:
	.string "¡Maravilloso! ¡Has sido muy valiente\n"
	.string "para tu edad!\p"
	.string "¡No se ve algo así todos los días!\n"
	.string "Quiero que te quedes esto.\p"
	.string "No te cortes, ¡cógelo!$"

EcruteakCity_Theater_Text_SurfGuyGaveSurf:
	.string "Es SURF. Es un movimiento que permite\n"
	.string "a los POKéMON nadar por el agua con\l"
	.string "facilidad.$"

EcruteakCity_Theater_Text_SurfGuyAfter:
	.string "Las CHICAS KIMONO no solo bailan de\n"
	.string "maravilla, también son muy hábiles con\l"
	.string "los POKéMON.\p"
	.string "Pero solo luchan por buenos motivos.\p"
	.string "No sé si podrías vencerlas si\n"
	.string "mostraran su habilidad…$"

EcruteakCity_Theater_Text_Psyduck:
	.string "PSYDUCK: ¡Psy psy!$"

EcruteakCity_Theater_Text_BoyBefore:
	.string "¡Iiiiiih!$"

EcruteakCity_Theater_Text_Boy:
	.string "¡Es… es mi oportunidad!\p"
	.string "¡Ahora podría conocer a la CHICA\n"
	.string "KIMONO!$"

EcruteakCity_Theater_Text_Granny:
	.string "Ese hombre siempre está con su\n"
	.string "PSYDUCK.\p"
	.string "Dice que quiere un POKéMON que sepa\n"
	.string "hacer SURF y bailar.\p"
	.string "¿Estará intentando crear un POKéMON\n"
	.string "estrella de la natación sincronizada?$"

EcruteakCity_Theater_Text_GrannyBefore:
	.string "¡Ay… Ay…! ¡Qué dolor de tripa!\p"
	.string "¡Si no fuera por este dolor, no dejaría\n"
	.string "que este tipo se comportara así…!$"

EcruteakCity_Theater_Text_Gramps:
	.string "Las CHICAS KIMONO son tan guapas…\p"
	.string "Pero tienen que entrenarse mucho.\p"
	.string "Y deben aprender los distintos bailes\n"
	.string "antes de actuar.\p"
	.string "Pero si te gusta algo, todo es posible.$"

EcruteakCity_Theater_Text_GrampsBefore:
	.string "¡Ay… Ay…! ¡Qué dolor de espalda!\p"
	.string "¡Si no fuera por este dolor, no dejaría\n"
	.string "que este tipo se comportara así…!$"

EcruteakCity_Theater_Text_Girl:
	.string "¡Las CHICAS KIMONO son mis hermanas\n"
	.string "mayores! ¡Algún día seré como ellas!$"

EcruteakCity_Theater_Text_GirlBefore:
	.string "¡Me gusta ese baile tan gracioso!$"

EcruteakCity_Theater_Text_FancyPanel:
	.string "Es un elegante panel decorado con\n"
	.string "flores.$"

EcruteakCity_Theater_Trigger_PreBattleCutsceneLeft::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, EcruteakCity_Theater_Movement_PlayerWalkToZukiLeft
	applymovement2 OBJ_EVENT_ID_FOLLOWER, EcruteakCity_Theater_Movement_MonWalkToZukiLeft
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto EcruteakCity_Theater_EventScript_LegendaryCutscene

EcruteakCity_Theater_Trigger_PreBattleCutsceneTop::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, EcruteakCity_Theater_Movement_PlayerWalkToZukiTop
	applymovement2 OBJ_EVENT_ID_FOLLOWER, EcruteakCity_Theater_Movement_MonWalkToZukiTop
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto EcruteakCity_Theater_EventScript_LegendaryCutscene

EcruteakCity_Theater_Trigger_PreBattleCutsceneRight::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, EcruteakCity_Theater_Movement_PlayerWalkToZukiRight
	applymovement2 OBJ_EVENT_ID_FOLLOWER, EcruteakCity_Theater_Movement_MonWalkToZukiRight
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto EcruteakCity_Theater_EventScript_LegendaryCutscene


EcruteakCity_Theater_Movement_PlayerWalkToZukiLeft:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end
EcruteakCity_Theater_Movement_MonWalkToZukiLeft:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

EcruteakCity_Theater_Movement_PlayerWalkToZukiTop:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end
EcruteakCity_Theater_Movement_MonWalkToZukiTop:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

EcruteakCity_Theater_Movement_PlayerWalkToZukiRight:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end
EcruteakCity_Theater_Movement_MonWalkToZukiRight::
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end


EcruteakCity_Theater_Movement_KimonoSpin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	step_end

EcruteakCity_Theater_EventScript_LugiaBuffer::
	bufferspeciesname STR_VAR_1, SPECIES_LUGIA
	return
EcruteakCity_Theater_EventScript_HoohBuffer::
	bufferspeciesname STR_VAR_1, SPECIES_HO_OH
	return
EcruteakCity_Theater_EventScript_LegendaryCutscene::
	call_if_eq VAR_LUGIA_OR_HOOH, 1, EcruteakCity_Theater_EventScript_LugiaBuffer
	call_if_eq VAR_LUGIA_OR_HOOH, 2, EcruteakCity_Theater_EventScript_HoohBuffer 
	msgbox EcruteakCity_Theater_Text_ZukiSeen, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ECRUTEAK_ZUKI, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	setvar VAR_ECRUTEAK_CITY_THEATER, 6
EcruteakCity_Theater_EventScript_ZukiBattle::
	msgbox EcruteakCity_Theater_Text_ZukiSeenAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, EcruteakCity_Theater_EventScript_LegendaryDenied
	call_if_eq VAR_FACING, DIR_SOUTH, EcruteakCity_Theater_Movement_SouthCorrection
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_Theater_Movement_WestCorrection
	call_if_eq VAR_FACING, DIR_EAST, EcruteakCity_Theater_Movement_EastCorrection
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 1, 2, 0, 0
	trainerbattle_no_intro TRAINER_ZUKI_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement2 LOCALID_ECRUTEAK_ZUKI, EcruteakCity_Theater_Movement_ZukiWalkUp
	waitmovement 0
EcruteakCity_Theater_EventScript_NaokoBattle::
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ECRUTEAK_NAOKO, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	applymovement2 LOCALID_ECRUTEAK_NAOKO, EcruteakCity_Theater_Movement_NaokoWalkToPlayer
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_NaokoSeen, MSGBOX_DEFAULT
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 1, 0, 1, 1, 0
	trainerbattle_no_intro TRAINER_NAOKO_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement2 LOCALID_ECRUTEAK_NAOKO, EcruteakCity_Theater_Movement_NaokoWalkBack
	waitmovement 0
EcruteakCity_Theater_EventScript_MikiBattle::
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ECRUTEAK_MIKI, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	applymovement2 LOCALID_ECRUTEAK_MIKI, EcruteakCity_Theater_Movement_MikiWalkToPlayer
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_MikiSeen, MSGBOX_DEFAULT
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 1, 2, 0
	trainerbattle_no_intro TRAINER_MIKI_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement2 LOCALID_ECRUTEAK_MIKI, EcruteakCity_Theater_Movement_MikiWalkBack
	waitmovement 0
EcruteakCity_Theater_EventScript_SayoBattle::
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ECRUTEAK_SAYO, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	applymovement2 LOCALID_ECRUTEAK_SAYO, EcruteakCity_Theater_Movement_SayoWalkToPlayer
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_SayoSeen, MSGBOX_DEFAULT
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 2, 1, 0, 0
	trainerbattle_no_intro TRAINER_SAYO_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement2 LOCALID_ECRUTEAK_SAYO, EcruteakCity_Theater_Movement_SayoWalkBack
	waitmovement 0
EcruteakCity_Theater_EventScript_KuniBattle::
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ECRUTEAK_KUNI, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	applymovement2 LOCALID_ECRUTEAK_KUNI, EcruteakCity_Theater_Movement_KuniWalkToPlayer
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_KuniSeen, MSGBOX_DEFAULT
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 2, 0, 0, 1, 0
	trainerbattle_no_intro TRAINER_KUNI_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement2 LOCALID_ECRUTEAK_KUNI, EcruteakCity_Theater_Movement_KuniWalkBack
	waitmovement 0
EcruteakCity_Theater_EventScript_BeatGauntlet::
	applymovement2 LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkDown1
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_ZukiDone, MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 1, EcruteakCity_Theater_EventScript_Lugia
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, EcruteakCity_Theater_EventScript_Hooh

	EcruteakCity_Theater_Movement_SouthCorrection::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

	EcruteakCity_Theater_Movement_WestCorrection::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

	EcruteakCity_Theater_Movement_EastCorrection::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

EcruteakCity_Theater_EventScript_Lugia::
	giveitem ITEM_TIDAL_BELL
	closemessage
	playse SE_M_RAZOR_WIND
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	addobject LOCALID_ECRUTEAK_SISTER
	applymovement2 LOCALID_ECRUTEAK_SISTER, EcruteakCity_Theater_Movement_Sister
	waitmovement 0
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_WEST
	msgbox EcruteakCity_Theater_Text_GirlLugia, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ECRUTEAK_ZUKI
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	msgbox EcruteakCity_Theater_Text_ZukiLugia, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK

	removeobject LOCALID_ECRUTEAK_ZUKI
	removeobject LOCALID_ECRUTEAK_MIKI
	removeobject LOCALID_ECRUTEAK_NAOKO
	removeobject LOCALID_ECRUTEAK_KUNI
	removeobject LOCALID_ECRUTEAK_SAYO
	removeobject LOCALID_ECRUTEAK_MIKI

	removeobject LOCALID_ECRUTEAK_SISTER
	playse SE_EXIT
	delay 120
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setvar VAR_COMPLETED_LUGIA, 2
	setvar VAR_COMPLETED_HO_OH, 3
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setvar VAR_NEWBARKTOWN_LABSTATE, 9
	setvar VAR_ECRUTEAK_CITY_THEATER, 7
	release
	end
EcruteakCity_Theater_EventScript_Hooh::
	giveitem ITEM_CLEAR_BELL
	closemessage
	playse SE_M_RAZOR_WIND
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	addobject LOCALID_ECRUTEAK_SISTER
	applymovement2 LOCALID_ECRUTEAK_SISTER, EcruteakCity_Theater_Movement_Sister
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_GirlHooh, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ECRUTEAK_ZUKI
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	msgbox EcruteakCity_Theater_Text_ZukiHooh, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK

	removeobject LOCALID_ECRUTEAK_ZUKI
	removeobject LOCALID_ECRUTEAK_MIKI
	removeobject LOCALID_ECRUTEAK_NAOKO
	removeobject LOCALID_ECRUTEAK_KUNI
	removeobject LOCALID_ECRUTEAK_SAYO
	removeobject LOCALID_ECRUTEAK_MIKI

	removeobject LOCALID_ECRUTEAK_SISTER
	playse SE_EXIT
	delay 120
	fadescreenswapbuffers FADE_FROM_BLACK

	clearflag FLAG_HIDE_TINTOWER_GUARD
	clearflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setvar VAR_COMPLETED_HO_OH, 2
	setvar VAR_COMPLETED_LUGIA, 3
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setvar VAR_NEWBARKTOWN_LABSTATE, 9
	setvar VAR_ECRUTEAK_CITY_THEATER, 7
	release
	end

EcruteakCity_Theater_Movement_Sister:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_right
	step_end

EcruteakCity_Theater_EventScript_LegendaryDenied::
	msgbox EcruteakCity_Theater_Text_ZukiNo, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_Movement_ZukiWalkUp:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end
EcruteakCity_Theater_Movement_NaokoWalkToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end
EcruteakCity_Theater_Movement_NaokoWalkBack:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end
EcruteakCity_Theater_Movement_MikiWalkToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end
EcruteakCity_Theater_Movement_MikiWalkBack:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

EcruteakCity_Theater_Movement_SayoWalkToPlayer:
	walk_down
	walk_right
	walk_right
	walk_right
	face_down
	step_end
EcruteakCity_Theater_Movement_SayoWalkBack:
	walk_left
	walk_left
	walk_left
	walk_up
	face_down
	step_end

EcruteakCity_Theater_Movement_KuniWalkToPlayer:
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end
EcruteakCity_Theater_Movement_KuniWalkBack:
	walk_right
	walk_right
	walk_right
	walk_up
	face_down
	step_end

EcruteakCity_Theater_Text_KimonoGirlBeaten:
	.string "…$"

EcruteakCity_Theater_Text_ZukiSeen:
	.string "Bienvenido. Me llamo ZUKI. Ya nos vimos\n"
	.string "en CIUDAD MALVA.\p"
	.string "Para traer de vuelta a {STR_VAR_1},\n"
	.string "necesitábamos a alguien con el\l"
	.string "vínculo adecuado con los POKéMON.\p"
	.string "Le pedimos al SR. POKéMON que diera\n"
	.string "este HUEVO MISTERIOSO a quien\l"
	.string "mostrara potencial.\p"
	.string "El HUEVO pasó del SR. POKéMON al PROF.\n"
	.string "ELM, y de él a ti.\p"
	.string "Pero ser puro no basta para\n"
	.string "enfrentarse al poder de este POKéMON.$"

EcruteakCity_Theater_Text_ZukiSeenAgain:
	.string "Voy a ponerte a prueba para ver si\n"
	.string "eres un buen ENTRENADOR.\p"
	.string "¿Estás listo, {PLAYER}?$"

EcruteakCity_Theater_Text_ZukiNo:
	.string "De acuerdo… Esperaremos hasta que lo\n"
	.string "creáis oportuno.$"

EcruteakCity_Theater_Text_NaokoSeen:
	.string "Eres bastante fuerte. Me ayudaste en\n"
	.string "el ENCINAR.\p"
	.string "Soy NAOKO, la que no tiene sentido de\n"
	.string "la orientación.\p"
	.string "Te vi vencer al TEAM ROCKET cuando\n"
	.string "CÉSAR estaba en apuros en el POZO\l"
	.string "SLOWPOKE.\p"
	.string "¡Déjame desafiarte a ti y a tus\n"
	.string "POKéMON!$"

EcruteakCity_Theater_Text_MikiSeen:
	.string "Eres todo un ENTRENADOR. Recuerdo\n"
	.string "que echaste a aquel SOLDADO ROCKET\l"
	.string "de aquí mismo.\p"
	.string "Gracias por ello.\p"
	.string "Pero yo también soy ENTRENADORA.\n"
	.string "¡Quien más sabe, menos habla!\p"
	.string "¡Soy MIKI, la CHICA KIMONO!\p"
	.string "¡Déjame desafiarte a ti y a tus\n"
	.string "POKéMON!$"

EcruteakCity_Theater_Text_SayoSeen:
	.string "¡Qué espíritu tan excelente! Me\n"
	.string "sacaste del hielo empujándome.\p"
	.string "Yo patino en sandalias. ¡Soy SAYO, la\n"
	.string "CHICA KIMONO!\p"
	.string "Te escuché en la GUARIDA DRAGÓN\n"
	.string "cuando superaste la prueba del\l"
	.string "anciano.\p"
	.string "¡Déjame desafiarte a ti y a tus\n"
	.string "POKéMON!$"

EcruteakCity_Theater_Text_KuniSeen:
	.string "Soy la última.\p"
	.string "Fuiste de gran ayuda en el TÚNEL de\n"
	.string "CIUDAD TRIGAL.\p"
	.string "¡Soy la que baila incluso bajo tierra,\n"
	.string "KUNI!\p"
	.string "Te vi frustrar el plan del TEAM ROCKET\n"
	.string "para hacerse con la ESTACIÓN DE\l"
	.string "RADIO.\p"
	.string "¡Ahora enséñame tu fuerza! ¡Déjame\n"
	.string "desafiarte a ti y a tus POKéMON!$"

EcruteakCity_Theater_Text_ZukiDone:
	.string "No me cabe la menor duda. Ahora sé que\n"
	.string "sois la persona indicada para poseer\l"
	.string "esto.\p"
	.string "Aquí tenéis.\p"
	.string "$"

EcruteakCity_Theater_Text_GirlHooh:
	.string "¡Hermanas! ¡Acabo de ver la gran\n"
	.string "sombra de un POKéMON sobre la TORRE\l"
	.string "CAMPANA!\p"
	.string "Podría ser…$"

EcruteakCity_Theater_Text_GirlLugia:
	.string "¡Hermana!\p"
	.string "¡La sombra de un enorme POKéMON\n"
	.string "planea sobre las ISLAS REMOLINO!\p"
	.string "¿Podría ser…?\p"
	.string "$"

EcruteakCity_Theater_Text_ZukiHooh:
	.string "ZUKI: ¡{PLAYER}! Estaremos en la TORRE\n"
	.string "CAMPANA. ¡Nos vemos allí!$"

EcruteakCity_Theater_Text_ZukiLugia:
	.string "ZUKI: ¡{PLAYER}! Estaremos en las\n"
	.string "ISLAS REMOLINO. ¡Nos vemos allí!$"

EcruteakCity_Theater_Text_KimonoDone:
	.string "Estamos ensayando nuestra danza.$"

EcruteakCity_Theater_Text_ZukiAfterAll:
	.string "Gracias por tu ayuda el otro día.\p"
	.string "Has demostrado que el vínculo entre\n"
	.string "las personas puede crecer gracias a\l"
	.string "los POKéMON…\p"
	.string "¡Te agradecemos que hayas estado a la\n"
	.string "altura de nuestras esperanzas,\l"
	.string "{PLAYER}!\p"
	.string "Si has aprendido algo de todo esto,\n"
	.string "dale las gracias al SR. POKéMON y al\l"
	.string "PROF. ELM…$"

EcruteakCity_Theater_Text_KimonoGirlsBeforeBattle:
	.string "Cuando os hayáis preparado, hablad\n"
	.string "con nuestra hermana TAMAO, en el\l"
	.string "centro.$"

