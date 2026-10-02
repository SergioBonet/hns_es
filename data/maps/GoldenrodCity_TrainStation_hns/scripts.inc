GoldenrodCity_TrainStation_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodCity_TrainStation_OnFrame
	.byte 0

GoldenrodCity_TrainStation_OnFrame::
	map_script_2 VAR_TRAIN, 1, GoldenrodCity_TrainStation_EventScript_ExitTrain
	.2byte 0

GoldenrodCity_TrainStation_EventScript_Attendant::
	lock
	faceplayer
	checkitem ITEM_PASS
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_TrainStation_EventScript_BoardTrain
	goto_if_set FLAG_RETURNED_MACHINE_PART, GoldenrodCity_TrainStation_EventScript_Attendant2
	msgbox GoldenrodMagnetTrainStation_Text_OfficerTrainHasntComeIn, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_TrainStation_EventScript_Attendant2::
	msgbox GoldenrodMagnetTrainStation_Text_OfficerNoRailPass, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_TrainStation_EventScript_BoardTrain::
	msgbox GoldenrodMagnetTrainStation_Text_OfficerRightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_CITY_TRAIN_STATION_ATTENDANT, GoldenrodCity_TrainStation_Movement_Attendant_Move_Up
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, GoldenrodCity_TrainStation_Movement_WalktoTrain
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	playse SE_EXIT
	waitse
	fadescreen FADE_TO_BLACK

	applymovement OBJ_EVENT_ID_CAMERA, GoldenrodCity_TrainStation_Movement_CameraPanUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, GoldenrodCity_TrainStation_Movement_CameraPanLeft
	waitmovement 0
	delay 60

	applymovement LOCALID_GOLDENROD_CITY_TRAIN_STATION_TRAIN GoldenrodCity_TrainStation_Movement_SlideRight
	applymovement OBJ_EVENT_ID_CAMERA, GoldenrodCity_TrainStation_Movement_SlideRight
	playbgm MUS_HG_MAGNET_TRAIN, FALSE
	fadescreen FADE_FROM_BLACK
	playse SE_TRUCK_MOVE
	delay 220
	playse SE_TRUCK_STOP
	applymovement LOCALID_GOLDENROD_CITY_TRAIN_STATION_TRAIN GoldenrodCity_TrainStation_Movement_SlideRight
	applymovement OBJ_EVENT_ID_CAMERA, GoldenrodCity_TrainStation_Movement_SlideRight
	fadescreen FADE_TO_BLACK
	waitse
	special RemoveCameraObject
	setvar VAR_TRAIN, 1
	delay 60
	warp MAP_SAFFRON_CITY_TRAIN_STATION_HNS, 1
	waitstate
	delay 60
	end

GoldenrodCity_TrainStation_EventScript_ExitTrain::
	lock
	applymovement LOCALID_GOLDENROD_CITY_TRAIN_STATION_ATTENDANT, GoldenrodCity_TrainStation_Movement_Attendant_Move_Up
	applymovement OBJ_EVENT_ID_PLAYER, GoldenrodCity_TrainStation_Movement_ExitTrain
	waitmovement 0
	waitmovement 0
	setvar VAR_TRAIN, 0
	applymovement LOCALID_GOLDENROD_CITY_TRAIN_STATION_ATTENDANT, GoldenrodCity_TrainStation_Movement_Attendant_Move_Down
	waitmovement 0
	release
	end

GoldenrodCity_TrainStation_EventScript_Gent::
	lock
	faceplayer
	msgbox GoldenrodMagnetTrainStation_Text_GentlemanPresident, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_TrainStation_EventScript_Boy::
	lock
	msgbox GoldenrodCity_TrainStation_Text_Boy, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_TrainStation_EventScript_Psychic::
	lock
	msgbox GoldenrodCity_TrainStation_Text_Psychic, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_TrainStation_Movement_ExitTrain:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

GoldenrodCity_TrainStation_Movement_Attendant_Move_Up:
	face_up
	walk_up
	walk_left
	face_right
	step_end

GoldenrodCity_TrainStation_Movement_Attendant_Move_Down:
	walk_right
	walk_down
	step_end

GoldenrodCity_TrainStation_Movement_WalktoTrain:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

GoldenrodCity_TrainStation_Movement_CameraPanUp:
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

GoldenrodCity_TrainStation_Movement_CameraPanLeft:
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	step_end

GoldenrodCity_TrainStation_Movement_SlideRight:
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	step_end

GoldenrodMagnetTrainStation_Text_OfficerTrainHasntComeIn:
	.string "El tren no ha llegado…\p"
	.string "¡Tengo una idea! ¡Llevaré a cuestas a\n"
	.string "los pasajeros!\p"
	.string "Aunque no creo que funcione.$"

GoldenrodMagnetTrainStation_Text_OfficerRightThisWay:
	.string "¿Por favor, puedo ver su\n"
	.string "MAGNETOPASE?\p"
	.string "Bien. Ya puede pasar, joven.$"

GoldenrodMagnetTrainStation_Text_OfficerNoRailPass:
	.string "Lo siento, pero no tiene MAGNETOPASE.$"

GoldenrodMagnetTrainStation_Text_GentlemanPresident:
	.string "Soy el PRESIDENTE.\p"
	.string "Mi sueño era crear un tren que fuera\n"
	.string "más rápido que cualquier POKéMON.\p"
	.string "Hace que JOHTO esté mucho más cerca\n"
	.string "de KANTO.$"

GoldenrodCity_TrainStation_Text_Boy:
	.string "You brought the MAGNET TRAIN PASS,\n"
	.string "right?$"

GoldenrodCity_TrainStation_Text_Psychic:
	.string "I thought you had it!$"
