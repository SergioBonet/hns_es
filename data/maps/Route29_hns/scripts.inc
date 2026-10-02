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
	.string "Press A or B to stop viewing.$"

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
	.string "I've seen you a couple times.\n"
	.string "How many POKéMON have you caught?\p"
	.string "Would you like me to tell you\n"
	.string "how to catch POKéMON?$"

Route29_Text_OldManExplanation:
	.string "If you weaken them first,\n"
	.string "POKéMON are easier to catch.\p"
	.string "Then, throw a ball at them from\n"
	.string "your bag! Any ball will do.\p"
	.string "If you want to learn more,\n"
	.string "go to the ACADEMY in VIOLET CITY!\p"
	.string "The students there know a lot\n"
	.string "about POKéMON.$"

Route29_Text_OldManDeclined:
	.string "Oh. Fine, then.\p"
	.string "Check every route to find\n"
	.string "different types of POKéMON.\p"
	.string "Your POKéDEX shows where you can\n"
	.string "find them too!\p"
	.string "If you want to learn more,\n"
	.string "go to the ACADEMY in VIOLET CITY!\p"
	.string "The students know a lot about\n"
	.string "POKéMON.$"

Route29_Text_Youngster:
	.string "¿Cómo están tus POKéMON?\p"
	.string "Si están débiles y no pueden luchar,\n"
	.string "no entres en la hierba.$"

Route29_Text_Lass:
	.string "See those ledges?\n"
	.string "It's scary to jump off them.\p"
	.string "But you can go to NEW BARK\n"
	.string "without walking through the grass.$"

Route29_Text_Girl:
	.string "Quería descansar un poco, así que\n"
	.string "guardé la partida.$"

Route29_Text_Boy_WaitingForDay:
	.string "I'm waiting for POKéMON that\n"
	.string "appear only later in the day.$"

Route29_Text_Boy_WaitingForNight:
	.string "Estoy esperando los POKéMON que\n"
	.string "aparecen solo por la noche.$"

Route29_Text_MeetTuscany:
	.string "TUSCANY: I do believe that this\n"
	.string "is the first time we've met?\p"
	.string "I'm TUSCANY of the WEEKDAY FAMILY.\p"
	.string "If you can guess my favorite day,\n"
	.string "I'll give you a reward.$"

Route29_Text_TuscanyNope:
	.string "Not quite!$"

Route29_Text_TuscanyGivesGift:
	.string "Yes! By way of introduction,\n"
	.string "please accept this gift, a SILK\l"
	.string "SCARF.$"

Route29_Text_TuscanyGaveGift:
	.string "TUSCANY: Wouldn't you agree\n"
	.string "that it is most adorable?\p"
	.string "It strengthens NORMAL-type\n"
	.string "moves.\p"
	.string "I am certain it will be of use.$"

Route29_Text_TuscanyTuesday:
	.string "TUSCANY: Have you met MONICA,\n"
	.string "my older sister?\p"
	.string "Or my younger brother, WESLEY?\p"
	.string "I am the third of seven\n"
	.string "children.$"

Route29_Text_Sign1:
	.string "RUTA 29\p"
	.string "CIUDAD CEREZO - PUEBLO PRIMAVERA$"

