Route29_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route29_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route29_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1 
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	end

Route29_Text_PressAorB:
	.string "Pulsa A o B para dejar de mirar.$"

Route29_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route29_EventScript_OldMan2
	msgbox Route29_Text_OldMan1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan2::
	msgbox Route29_Text_OldMan2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route29_EventScript_OldMan_Tutorial
	waitmessage
	msgbox Route29_Text_OldManDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan_Tutorial::
	msgbox Route29_Text_OldManExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Lass::
	lock
	faceplayer
	msgbox Route29_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route29_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end


Route29_EventScript_Tuscany::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SILK_SCARF, Route29_EventScript_TuscanyCompleted
	msgbox Route29_Text_MeetTuscany, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route29_EventScript_TuscanyNope
	case 1, Route29_EventScript_TuscanyNope
	case 2, Route29_EventScript_TuscanyYes
	case 3, Route29_EventScript_TuscanyNope
	case 4, Route29_EventScript_TuscanyNope
	case 5, Route29_EventScript_TuscanyNope
	case 6, Route29_EventScript_TuscanyNope
	case 7 Route29_EventScript_TuscanyCancel
	case MULTI_B_PRESSED, Route29_EventScript_TuscanyCancel
	closemessage
	release
	end
Route29_EventScript_TuscanyYes::
	msgbox Route29_Text_TuscanyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SILK_SCARF
	msgbox Route29_Text_TuscanyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyCancel::
	closemessage
	release
	end
Route29_EventScript_TuscanyCompleted::
	msgbox Route29_Text_TuscanyTuesday, MSGBOX_DEFAULT
	closemessage
	release
	end



Route29_EventScript_Girl::
	lock
	faceplayer
	msgbox Route29_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_NIGHT_POKEMON, Route29_EventScript_Boy2
	msgbox Route29_Text_Boy_WaitingForDay, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy2::
	msgbox Route29_Text_Boy_WaitingForNight, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Sign::
	lock
	msgbox Route29_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route29_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

Route29_Text_OldMan1:
	.string "Los POKéMON se esconden en la hierba.\n"
	.string "Nadie sabe cuándo salen…$"

Route29_Text_OldMan2:
	.string "Ya te he visto un par de veces.\n"
	.string "¿Cuántos POKéMON has atrapado?\p"
	.string "¿Quieres que te explique cómo se\n"
	.string "atrapan los POKéMON?$"

Route29_Text_OldManExplanation:
	.string "Si primero los debilitas, es más fácil\n"
	.string "atrapar a los POKéMON.\p"
	.string "Luego, ¡lánzales una BALL de tu\n"
	.string "MOCHILA! Sirve cualquiera.\p"
	.string "Si quieres saber más, ¡ve a la ACADEMIA\n"
	.string "de CIUDAD MALVA!\p"
	.string "Los alumnos de allí saben mucho de\n"
	.string "POKéMON.$"

Route29_Text_OldManDeclined:
	.string "Ah. Bueno, pues nada.\p"
	.string "Recorre todas las rutas para\n"
	.string "encontrar distintos tipos de POKéMON.\p"
	.string "¡Tu POKéDEX también te muestra dónde\n"
	.string "encontrarlos!\p"
	.string "Si quieres saber más, ¡ve a la ACADEMIA\n"
	.string "de CIUDAD MALVA!\p"
	.string "Los alumnos saben mucho de POKéMON.$"

Route29_Text_Youngster:
	.string "¿Cómo están tus POKéMON?\p"
	.string "Si están débiles y no pueden luchar,\n"
	.string "no entres en la hierba.$"

Route29_Text_Lass:
	.string "¿Ves esos salientes? Da miedo saltar\n"
	.string "desde ellos.\p"
	.string "Pero así puedes ir a PUEBLO PRIMAVERA\n"
	.string "sin pasar por la hierba.$"

Route29_Text_Girl:
	.string "Quería descansar un poco, así que\n"
	.string "guardé la partida.$"

Route29_Text_Boy_WaitingForDay:
	.string "Estoy esperando a los POKéMON que\n"
	.string "solo aparecen más tarde.$"

Route29_Text_Boy_WaitingForNight:
	.string "Estoy esperando los POKéMON que\n"
	.string "aparecen solo por la noche.$"

Route29_Text_MeetTuscany:
	.string "MARTA: ¿Diría que es la primera vez\n"
	.string "que nos vemos?\p"
	.string "Soy MARTA, de la FAMILIA de los DÍAS\n"
	.string "de la SEMANA.\p"
	.string "Si adivinas cuál es mi día favorito, te\n"
	.string "daré una recompensa.$"

Route29_Text_TuscanyNope:
	.string "¡No exactamente!$"

Route29_Text_TuscanyGivesGift:
	.string "¡Sí! A modo de presentación, acepta\n"
	.string "este regalo, por favor: un PAÑUELO\l"
	.string "SEDA.$"

Route29_Text_TuscanyGaveGift:
	.string "MARTA: ¿No te parece de lo más\n"
	.string "adorable?\p"
	.string "Potencia los movimientos de tipo\n"
	.string "NORMAL.\p"
	.string "Estoy segura de que te será útil.$"

Route29_Text_TuscanyTuesday:
	.string "MARTA: ¿Conoces a LUNA, mi hermana\n"
	.string "mayor?\p"
	.string "¿O a mi hermano pequeño, MIGUEL?\p"
	.string "Soy la tercera de siete hermanos.$"

Route29_Text_Sign1:
	.string "RUTA 29\p"
	.string "CIUDAD CEREZO - PUEBLO PRIMAVERA$"

