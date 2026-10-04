TwoIsland_JoyfulGameCorner_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwoIsland_JoyfulGameCorner_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TwoIsland_JoyfulGameCorner_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TwoIsland_JoyfulGameCorner_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad_Frlg
	.byte 0

TwoIsland_JoyfulGameCorner_OnTransition::
	call_if_set FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER, TwoIsland_JoyfulGameCorner_EventScript_SetLostelleReturnedPos
	end

TwoIsland_JoyfulGameCorner_EventScript_SetLostelleReturnedPos::
	setobjectxyperm LOCALID_JOYFUL_GAME_CORNER_DADDY, 6, 2
	setobjectmovementtype LOCALID_JOYFUL_GAME_CORNER_DADDY, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_JOYFUL_GAME_CORNER_LOSTELLE, MOVEMENT_TYPE_LOOK_AROUND
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 4
	return

TwoIsland_JoyfulGameCorner_OnWarp::
	map_script_2 VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2, TwoIsland_JoyfulGameCorner_EventScript_TurnPlayerNorth
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, EventScript_CheckTurnAttendant_Frlg
	.2byte 0

TwoIsland_JoyfulGameCorner_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

TwoIsland_JoyfulGameCorner_OnFrame::
	map_script_2 VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 0, TwoIsland_JoyfulGameCorner_EventScript_HelpFindLostelleScene
	map_script_2 VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2, TwoIsland_JoyfulGameCorner_EventScript_FoundLostelleScene
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

TwoIsland_JoyfulGameCorner_EventScript_FoundLostelleScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox TwoIsland_JoyfulGameCorner_Text_YouRescuedLostelle
	textcolor NPC_TEXT_COLOR_FEMALE
	special GetPlayerBigGuyGirlString
	msgbox TwoIsland_JoyfulGameCorner_Text_LostelleItsOkayDaddy
	closemessage
	applymovement LOCALID_JOYFUL_GAME_CORNER_LOSTELLE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 3
	releaseall
	end

TwoIsland_JoyfulGameCorner_EventScript_HelpFindLostelleScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, TwoIsland_JoyfulGameCorner_Movement_DaddyPacing
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_WhereHasLostelleGottenTo
	closemessage
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, TwoIsland_JoyfulGameCorner_Movement_DaddyApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_PleaseHelpFindLostelle
	closemessage
	playse SE_DOOR
	waitse
	applymovement LOCALID_PLAYER, TwoIsland_JoyfulGameCorner_Movement_PlayerFaceDaddy
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	addobject LOCALID_JOYFUL_GAME_CORNER_BIKER
	applymovement LOCALID_JOYFUL_GAME_CORNER_BIKER, TwoIsland_JoyfulGameCorner_Movement_BikerLookAround
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_IsThisOnlyThreeIsland
	applymovement LOCALID_JOYFUL_GAME_CORNER_BIKER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_ThisIsTwoIslandMoveIt
	msgbox TwoIsland_JoyfulGameCorner_Text_TheseIslandsAreConfusing
	closemessage
	applymovement LOCALID_JOYFUL_GAME_CORNER_BIKER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_JOYFUL_GAME_CORNER_BIKER
	fadedefaultbgm
	delay 60
	msgbox TwoIsland_JoyfulGameCorner_Text_PunkScuffedUpMyFloor
	clearflag FLAG_HIDE_THREE_ISLAND_LONE_BIKER
	setvar VAR_MAP_SCENE_THREE_ISLAND, 2
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 1
	releaseall
	end

TwoIsland_JoyfulGameCorner_Movement_DaddyPacing::
	walk_left
	walk_right
	walk_right
	delay_8
	walk_in_place_faster_up
	delay_16
	step_end

TwoIsland_JoyfulGameCorner_Movement_DaddyApproachPlayer::
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

TwoIsland_JoyfulGameCorner_Movement_PlayerFaceDaddy::
	walk_left
	walk_in_place_faster_right
	step_end

TwoIsland_JoyfulGameCorner_Movement_BikerLookAround::
	walk_in_place_faster_left
	delay_8
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_up
	step_end

TwoIsland_JoyfulGameCorner_EventScript_InfoMan::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 4, JoyfulGameCorner_EventScript_InfoMan2_Frlg
	goto_if_set FLAG_RESCUED_LOSTELLE, TwoIsland_JoyfulGameCorner_EventScript_GetGamesGoingSoon
	msgbox TwoIsland_JoyfulGameCorner_Text_NotRunningAnyGamesToday
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_GetGamesGoingSoon::
	msgbox TwoIsland_JoyfulGameCorner_Text_GetGamesGoingSoon
	release
	end

@ Only referred to as Lostelles Daddy in text
TwoIsland_JoyfulGameCorner_EventScript_LostellesDaddy::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 4, JoyfulGameCorner_EventScript_MinigameAttendant_Frlg
	goto_if_set FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER, TwoIsland_JoyfulGameCorner_EventScript_GetGameCornerRunning
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 3, TwoIsland_JoyfulGameCorner_EventScript_GiveDaddyMeteorite
	msgbox TwoIsland_JoyfulGameCorner_Text_PleaseGoToThreeIsland
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_GiveDaddyMeteorite::
	goto_if_set FLAG_NO_ROOM_FOR_JOYFUL_GAME_CORNER_MOON_STONE, TwoIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone
	msgbox TwoIsland_JoyfulGameCorner_Text_ThisIsForMe
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message TwoIsland_JoyfulGameCorner_Text_HandedMeteoriteToLostellesDaddy
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	removeitem ITEM_METEORITE
	msgbox TwoIsland_JoyfulGameCorner_Text_OhThisIsFromBill
	goto TwoIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone
	end

TwoIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone::
	checkitemspace ITEM_MOON_STONE
	goto_if_eq VAR_RESULT, FALSE, TwoIsland_JoyfulGameCorner_EventScript_NoRoomForMoonStone
	additem ITEM_MOON_STONE
	setflag FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER
	msgreceiveditem TwoIsland_JoyfulGameCorner_Text_ReceivedMoonStoneFromLostellesDaddy, ITEM_MOON_STONE
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_GetGameCornerRunning::
	msgbox TwoIsland_JoyfulGameCorner_Text_IllGetGameCornerRunning
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_NoRoomForMoonStone::
	setflag FLAG_NO_ROOM_FOR_JOYFUL_GAME_CORNER_MOON_STONE
	msgbox TwoIsland_JoyfulGameCorner_Text_NotGoingToFitInBag
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_Lostelle::
	lock
	faceplayer
	msgbox TwoIsland_JoyfulGameCorner_Text_PleaseShowMeYouBeingCool
	release
	end

TwoIsland_JoyfulGameCorner_Text_WhereHasLostelleGottenTo::
	.string "¿Dónde se habrá metido PEDRITA\n"
	.string "hoy?\p"
	.string "Siempre me trae la comida\n"
	.string "a tiempo, pero hoy...$"

TwoIsland_JoyfulGameCorner_Text_PleaseHelpFindLostelle::
	.string "¡Oye, sí, tú!\n"
	.string "¿Conoces a PEDRITA?\p"
	.string "¿La has visto por algún sitio?\n"
	.string "No tengo ni idea de dónde se habrá\l"
	.string "metido, pero tarda un montón.\p"
	.string "Es una monada de niña, espero\n"
	.string "que no le haya pasado nada...\p"
	.string "¡Como le haya pasado algo a mi\n"
	.string "PEDRITA!\p"
	.string "¡Por favor, ayúdame a buscarla!\n"
	.string "¿Irías a ISLA TERA a ver si está?$"

TwoIsland_JoyfulGameCorner_Text_IsThisOnlyThreeIsland::
	.string "¿Y éstos son los RECREATIVOS?\n"
	.string "¡POR FAVOR!\p"
	.string "Qué birria...\p"
	.string "¿No se supone que hemos quedado\n"
	.string "aquí? ¿Dónde está la gente?\p"
	.string "¡Eh, tú! ¿Hay otra ISLA TERA\n"
	.string "por ahí o es ésta la única?$"

TwoIsland_JoyfulGameCorner_Text_ThisIsTwoIslandMoveIt::
	.string "¡Vaya empanada mental que tienes,\n"
	.string "chaval!\p"
	.string "¡Esto es ISLA SECUNDA!\p"
	.string "¡Anda, pon en marcha la moto\n"
	.string "y tira!$"

TwoIsland_JoyfulGameCorner_Text_TheseIslandsAreConfusing::
	.string "Eh...\n"
	.string "Ah, vale.\p"
	.string "Eh...\n"
	.string "¡Me he liado con tanta isla!$"

TwoIsland_JoyfulGameCorner_Text_PunkScuffedUpMyFloor::
	.string "¿Has visto eso?\n"
	.string "Ese gamberro ha rayado mi suelo.$"

TwoIsland_JoyfulGameCorner_Text_PleaseGoToThreeIsland::
	.string "Por favor, tienes que ir a ISLA\n"
	.string "TERA.\p"
	.string "Si le pasara algo a mi PEDRITA...\p"
	.string "Mi casa está en ISLA TERA, es la\n"
	.string "del tejado rojo.\p"
	.string "Yo no quiero moverme de aquí,\n"
	.string "no vaya a ser que aparezca en\l"
	.string "algún momento.\p"
	.string "Por eso te pido que me ayudes.$"

TwoIsland_JoyfulGameCorner_Text_NotRunningAnyGamesToday::
	.string "Lo siento.\n"
	.string "En este momento no se puede jugar\l"
	.string "a nada.$"

TwoIsland_JoyfulGameCorner_Text_GetGamesGoingSoon::
	.string "¡Pronto pondremos los juegos\n"
	.string "en marcha para ti!$"

TwoIsland_JoyfulGameCorner_Text_YouRescuedLostelle::
	.string "¿Así que rescataste a PEDRITA?\n"
	.string "¿Cómo puedo agradecértelo?\p"
	.string "¡PEDRITA, cariño, perdóname!\p"
	.string "¡Papá no sabía que estabas\n"
	.string "asustada y en apuros!$"

TwoIsland_JoyfulGameCorner_Text_LostelleItsOkayDaddy::
	.string "PEDRITA: No asa nada, api.\n"
	.string "{PLAYER}, es amigui.$"

TwoIsland_JoyfulGameCorner_Text_ThisIsForMe::
	.string "¿Cómo?\n"
	.string "¿Que es para mí?\p"
	.string "¿Y cómo sabes que me gustan\n"
	.string "las rocas raras y las gemas?\p"
	.string "Desde luego, has dado en el clavo.$"

TwoIsland_JoyfulGameCorner_Text_HandedMeteoriteToLostellesDaddy::
	.string "{PLAYER} le entregó el METEORITO\n"
	.string "al papá de PEDRITA.$"

TwoIsland_JoyfulGameCorner_Text_OhThisIsFromBill::
	.string "¡Ah, que lo envía BILL!\n"
	.string "¡Dale las gracias de mi parte!\p"
	.string "No tengo palabras para agradecerte\n"
	.string "todo lo que has hecho.\l"
	.string "Me gustaría darte esto.$"

TwoIsland_JoyfulGameCorner_Text_ReceivedMoonStoneFromLostellesDaddy::
	.string "¡{PLAYER} obtuvo una PIEDRA LUNAR\n"
	.string "de manos del papá de PEDRITA!$"

TwoIsland_JoyfulGameCorner_Text_NotGoingToFitInBag::
	.string "En la MOCHILA no cabe nada\n"
	.string "más...$"

TwoIsland_JoyfulGameCorner_Text_IllGetGameCornerRunning::
	.string "Bueno, ya podemos poner en marcha\n"
	.string "los RECREATIVOS.\p"
	.string "Vente con algún amigo para jugar\n"
	.string "a algo.$"

TwoIsland_JoyfulGameCorner_Text_PleaseShowMeYouBeingCool::
	.string "¡Eh, eh!\p"
	.string "¡Ede guay, tú hace aggo guay!$"

