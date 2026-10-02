UnionCave_1F_hns_MapScripts::
	.byte 0


UnionCave_1F_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	end


UnionCave_1F_EventScript_HikerRussell::
	trainerbattle_single TRAINER_RUSSELL_HNS, UnionCave_1F_Text_HikerRussellSeen, UnionCave_1F_Text_HikerRussellBeaten
	msgbox UnionCave_1F_Text_HikerRussellAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_PokemaniacLarry::
	trainerbattle_single TRAINER_LARRY_HNS, UnionCave_1F_Text_PokemaniacLarrySeen, UnionCave_1F_Text_PokemaniacLarryBeaten
	msgbox UnionCave_1F_Text_PokemaniacLarryAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_HikerDaniel::
	trainerbattle_single TRAINER_DANIEL_HNS, UnionCave_1F_Text_HikerDanielSeen, UnionCave_1F_Text_HikerDanielBeaten
	msgbox UnionCave_1F_Text_HikerDanielAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherBill::
	trainerbattle_single TRAINER_BILL_HNS, UnionCave_1F_Text_FirebreatherBillSeen, UnionCave_1F_Text_FirebreatherBillBeaten
	msgbox UnionCave_1F_Text_FirebreatherBillAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherRay::
	trainerbattle_single TRAINER_RAY_HNS, UnionCave_1F_Text_FirebreatherRaySeen, UnionCave_1F_Text_FirebreatherRayBeaten
	msgbox UnionCave_1F_Text_FirebreatherRayAfter, MSGBOX_AUTOCLOSE
	end	

UnionCave_1F_EventScript_Item_Potion::
	finditem ITEM_POTION
	end

UnionCave_1F_EventScript_Item_GreatBall::
	finditem ITEM_GREAT_BALL
	end

UnionCave_1F_EventScript_Item_Xattack::
	finditem ITEM_X_ATTACK
	end

UnionCave_1F_EventScript_Item_Awakening::
	finditem ITEM_AWAKENING
	end

UnionCave_1F_Text_HikerRussellSeen:
	.string "¿Te diriges a PUEBLO AZALEA?\p"
	.string "Demuestra a mis POKéMON que vales\n"
	.string "para luchar.$"

UnionCave_1F_Text_HikerRussellBeaten:
	.string "¡Oh, oh, oh!$"

UnionCave_1F_Text_HikerRussellAfter:
	.string "¡Muy bien! Ya lo he decidido.\p"
	.string "¡No me iré hasta que mis POKéMON se\n"
	.string "fortalezcan!$"

UnionCave_1F_Text_PokemaniacLarrySeen:
	.string "Merodeo por todas partes en busca de\n"
	.string "POKéMON.\p"
	.string "¿También tú vas en busca de POKéMON?\p"
	.string "¡Pues entonces eres mi rival\n"
	.string "coleccionista!$"

UnionCave_1F_Text_PokemaniacLarryBeaten:
	.string "¡Ugh! Mis pobres POKéMON…$"

UnionCave_1F_Text_PokemaniacLarryAfter:
	.string "Sometimes, you can hear POKéMON\n"
	.string "roars from deep inside the cave.$"

UnionCave_1F_Text_HikerDanielSeen:
	.string "¡Uauu! ¡Qué sorpresa!\p"
	.string "¡No esperaba ver a nadie!$"

UnionCave_1F_Text_HikerDanielBeaten:
	.string "¡Uauu! ¡Me han machacado!$"

UnionCave_1F_Text_HikerDanielAfter:
	.string "I was conned into buying a\n"
	.string "SLOWPOKETAIL.\p"
	.string "I feel sorry for the poor POKéMON.$"

UnionCave_1F_Text_FirebreatherBillSeen:
	.string "El SUPERSÓNICO de ZUBAT confunde a\n"
	.string "mis POKéMON.\p"
	.string "¡Y eso me preocupa!$"

UnionCave_1F_Text_FirebreatherBillBeaten:
	.string "¡Fallé!$"

UnionCave_1F_Text_FirebreatherBillAfter:
	.string "Los fines de semana se oyen extraños\n"
	.string "rugidos en la cueva.$"

UnionCave_1F_Text_FirebreatherRaySeen:
	.string "Si hay luz, no me asusta la cueva.\p"
	.string "Si eres fuerte, los POKéMON no se\n"
	.string "asustarán.$"

UnionCave_1F_Text_FirebreatherRayBeaten:
	.string "¡Rayos y centellas!$"

UnionCave_1F_Text_FirebreatherRayAfter:
	.string "El fuego de mi POKéMON ilumina la\n"
	.string "cueva.$"
