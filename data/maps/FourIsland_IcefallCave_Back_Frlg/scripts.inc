FourIsland_IcefallCave_Back_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_IcefallCave_Back_OnTransition
	.byte 0

FourIsland_IcefallCave_Back_OnTransition::
	call_if_eq VAR_MAP_SCENE_ICEFALL_CAVE_BACK, 1, FourIsland_IcefallCave_Back_EventScript_HideLorelei
	end

FourIsland_IcefallCave_Back_EventScript_HideLorelei::
	setflag FLAG_HIDE_ICEFALL_CAVE_LORELEI
	return

FourIsland_IcefallCave_Back_EventScript_LoreleiRocketsScene::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FourIsland_IcefallCave_Back_Text_LoreleiKeepHandsOffMons
	applymovement LOCALID_ICEFALL_ROCKET1, FourIsland_IcefallCave_Back_Movement_WalkInPlaceDown
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FourIsland_IcefallCave_Back_Text_ShutItLadyLeaveUsBe
	closemessage
	playse SE_PIN
	applymovement LOCALID_ICEFALL_LORELEI, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ICEFALL_LORELEI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_ICEFALL_LORELEI, Common_Movement_Delay48
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FourIsland_IcefallCave_Back_Text_LoreleiPlayerHelpMeKickPoachersOut
	closemessage
	applymovement LOCALID_ICEFALL_LORELEI, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 18
	applymovement LOCALID_ICEFALL_LORELEI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 35
	applymovement LOCALID_ICEFALL_ROCKET3, FourIsland_IcefallCave_Back_Movement_Rocket3FaceLorelei
	applymovement LOCALID_ICEFALL_LORELEI, FourIsland_IcefallCave_Back_Movement_LoreleiToRockets
	applymovement LOCALID_PLAYER, FourIsland_IcefallCave_Back_Movement_PlayerToRockets
	waitmovement 0
	applymovement LOCALID_ICEFALL_ROCKET2, FourIsland_IcefallCave_Back_Movement_WalkInPlaceDown
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FourIsland_IcefallCave_Back_Text_GruntIntro
	setvar VAR_LAST_TALKED, LOCALID_ICEFALL_ROCKET3
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_45, FourIsland_IcefallCave_Back_Text_GruntDefeat
	applymovement LOCALID_ICEFALL_LORELEI, FourIsland_IcefallCave_Back_Movement_WalkInPlaceUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FourIsland_IcefallCave_Back_Text_LoreleiWhereHaveYouTakenMons
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FourIsland_IcefallCave_Back_Text_NotTellingYouThat
	textcolor NPC_TEXT_COLOR_FEMALE
	message FourIsland_IcefallCave_Back_Text_LoreleiWellDeepFreezeYou
	waitmessage
	waitse
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	waitbuttonpress
	waitmoncry
	applymovement LOCALID_ICEFALL_ROCKET1, FourIsland_IcefallCave_Back_Movement_Rocket1ReactToThreat
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FourIsland_IcefallCave_Back_Text_OkayRocketWareHouseFiveIsland
	closemessage
	applymovement LOCALID_ICEFALL_LORELEI, FourIsland_IcefallCave_Back_Movement_LoreleiWatchRocketsExit
	applymovement LOCALID_PLAYER, FourIsland_IcefallCave_Back_Movement_PlayerWatchRocketsExit
	applymovement LOCALID_ICEFALL_ROCKET1, FourIsland_IcefallCave_Back_Movement_Rocket1Exit
	applymovement LOCALID_ICEFALL_ROCKET2, FourIsland_IcefallCave_Back_Movement_Rocket2Exit
	applymovement LOCALID_ICEFALL_ROCKET3, FourIsland_IcefallCave_Back_Movement_Rocket3Exit
	waitmovement 0
	removeobject LOCALID_ICEFALL_ROCKET1
	removeobject LOCALID_ICEFALL_ROCKET2
	removeobject LOCALID_ICEFALL_ROCKET3
	delay 50
	applymovement LOCALID_ICEFALL_LORELEI, FourIsland_IcefallCave_Back_Movement_LoreleiWalkToPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FourIsland_IcefallCave_Back_Text_ThankYouThisIsAwful
	setflag FLAG_HIDE_RUIN_VALLEY_SCIENTIST
	clearflag FLAG_HIDE_LORELEI_IN_HER_HOUSE
	setvar VAR_MAP_SCENE_ICEFALL_CAVE_BACK, 1
	releaseall
	end

FourIsland_IcefallCave_Back_Movement_PlayerToRockets::
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

FourIsland_IcefallCave_Back_Movement_PlayerWatchRocketsExit::
	delay_16
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

FourIsland_IcefallCave_Back_Movement_WalkInPlaceDown::
	walk_in_place_down
	step_end

FourIsland_IcefallCave_Back_Movement_UnusedPushRight::
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

FourIsland_IcefallCave_Back_Movement_Rocket1ReactToThreat::
	walk_in_place_fast_down
	step_end

FourIsland_IcefallCave_Back_Movement_Rocket1Exit::
	walk_right
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

FourIsland_IcefallCave_Back_Movement_Rocket2Exit::
	delay_16
	walk_left
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

FourIsland_IcefallCave_Back_Movement_Rocket3Exit::
	delay_16
	walk_down
	delay_16
	walk_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

FourIsland_IcefallCave_Back_Movement_Rocket3FaceLorelei::
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

FourIsland_IcefallCave_Back_Movement_UnusedWalkLeft::
	walk_left
	walk_left
	step_end

FourIsland_IcefallCave_Back_Movement_LoreleiToRockets::
	walk_left
	walk_up
	step_end

FourIsland_IcefallCave_Back_Movement_WalkInPlaceUp::
	walk_in_place_up
	step_end

FourIsland_IcefallCave_Back_Movement_LoreleiWatchRocketsExit::
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

FourIsland_IcefallCave_Back_Movement_LoreleiWalkToPlayer::
	walk_right
	step_end

FourIsland_IcefallCave_Back_EventScript_Lorelei::
	msgbox FourIsland_IcefallCave_Back_Text_ThankYouThisIsAwful, MSGBOX_NPC
	end

FourIsland_IcefallCave_Back_Text_LoreleiKeepHandsOffMons::
	.string "LORELEI: ¡Ni te acerques a los\n"
	.string "POKéMON que hay en la cueva!\p"
	.string "Si no, te las tendrás que ver\n"
	.string "conmigo.$"

FourIsland_IcefallCave_Back_Text_ShutItLadyLeaveUsBe::
	.string "Venga ya, señora, no incordie.\p"
	.string "¡Chicos, sigamos a lo nuestro!$"

FourIsland_IcefallCave_Back_Text_LoreleiPlayerHelpMeKickPoachersOut::
	.string "LORELEI: ¡¿{PLAYER}?!\n"
	.string "¿Qué haces aquí?\p"
	.string "Bueno, ya charlaremos después.\n"
	.string "Ayúdame con estos elementos.\p"
	.string "Necesito que me eches una mano\n"
	.string "para frenar a esta gentuza.\p"
	.string "Han estado atrapando POKéMON\n"
	.string "aquí, y vendiéndolos por ahí.\p"
	.string "¿Vas a ayudarme?\n"
	.string "¡Pues adelante!$"

FourIsland_IcefallCave_Back_Text_GruntIntro::
	.string "¿Perdón?\p"
	.string "¿Quién dice aquí lo que podemos\n"
	.string "o no podemos hacer con los\l"
	.string "POKéMON que atrapamos?$"

FourIsland_IcefallCave_Back_Text_GruntDefeat::
	.string "¡No lo habíamos planeado!$"

FourIsland_IcefallCave_Back_Text_LoreleiWhereHaveYouTakenMons::
	.string "LORELEI: Ja.\n"
	.string "Qué cosa más endeble...\p"
	.string "A ver, tú.\n"
	.string "Dime.\p"
	.string "¿Dónde tenéis a los POKéMON\n"
	.string "que habéis capturado?\p"
	.string "Dímelo ahora mismo si no quieres\n"
	.string "que te dé una zurra.$"

FourIsland_IcefallCave_Back_Text_NotTellingYouThat::
	.string "¡Ni en broma!\n"
	.string "¡No pienso decírtelo!$"

FourIsland_IcefallCave_Back_Text_LoreleiWellDeepFreezeYou::
	.string "LORELEI: Como no me lo digas,\n"
	.string "¡acabarás congelado!\p"
	.string "Mi LAPRAS está que trina por lo\n"
	.string "que les habéis hecho a sus amigos.\p"
	.string "¡Venga, LAPRAS!\n"
	.string "¡RAYO HIELO!...$"

FourIsland_IcefallCave_Back_Text_OkayRocketWareHouseFiveIsland::
	.string "¡Aaaaah!\n"
	.string "¡Para, para, que te lo digo!\p"
	.string "Los POKéMON están en el ALMACÉN\n"
	.string "ROCKET de ISLA INTA.\p"
	.string "¡Hala, ya lo he dicho!\n"
	.string "¡Vámonos ya de aquí!\p"
	.string "¡Pero que sepas que dudo mucho\n"
	.string "que puedas entrar en el ALMACÉN\l"
	.string "ROCKET!\p"
	.string "¡Ja, ja, ja!$"

FourIsland_IcefallCave_Back_Text_ThankYouThisIsAwful::
	.string "{PLAYER}, gracias.\n"
	.string "Ha sido horrible...\p"
	.string "Yo he nacido aquí y he pasado\n"
	.string "toda mi vida en estas islas.\p"
	.string "No sabía que esos golfos\n"
	.string "estuvieran por aquí sueltos...$"

