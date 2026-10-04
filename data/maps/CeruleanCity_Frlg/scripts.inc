CeruleanCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
	.byte 0

CeruleanCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CERULEAN_CITY
	call_if_unset FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_BlockExits
	end

CeruleanCity_EventScript_BlockExits::
	setobjectxyperm LOCALID_CERULEAN_POLICEMAN, 30, 12
	setobjectxyperm LOCALID_CERULEAN_SLOWBRO, 26, 31
	setobjectxyperm LOCALID_CERULEAN_LASS, 27, 31
	return

CeruleanCity_EventScript_RivalTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_CERULEAN_RIVAL, 23, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm LOCALID_CERULEAN_RIVAL, 24, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_Rival::
	textcolor NPC_TEXT_COLOR_MALE
	setvar VAR_MAP_SCENE_ROUTE22, 2
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	addobject LOCALID_CERULEAN_RIVAL
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalEnter
	waitmovement 0
	msgbox CeruleanCity_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_CERULEAN_RIVAL
	call_if_eq VAR_STARTER_MON, 2, CeruleanCity_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, CeruleanCity_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, CeruleanCity_EventScript_RivalCharmander
	famechecker FAMECHECKER_BILL, 0
	msgbox CeruleanCity_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 1, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 2, CeruleanCity_EventScript_RivalStartExitRight
	msgbox CeruleanCity_Text_OhRightLittlePresentAsFavor
	setvar VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1
	setflag FLAG_GOT_FAME_CHECKER
	giveitem ITEM_FAME_CHECKER
	msgbox CeruleanCity_Text_ExplainFameCheckerSmellYa
	closemessage
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_CERULEAN_RIVAL
	releaseall
	end

CeruleanCity_EventScript_RivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_SQUIRTLE, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_BULBASAUR, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_CHARMANDER, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalStartExit::
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExit
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalStartExit
	waitmovement 0
	return

CeruleanCity_EventScript_RivalStartExitRight::
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExitRight
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalStartExitRight
	waitmovement 0
	return

CeruleanCity_Movement_PlayerWatchRivalExit::
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

CeruleanCity_Movement_PlayerWatchRivalExitRight::
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

CeruleanCity_Movement_RivalEnter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Movement_RivalStartExit::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalStartExitRight::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalExit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_EventScript_Grunt::
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_EventScript_GruntDefeated
	message CeruleanCity_Text_GruntIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	goto CeruleanCity_EventScript_GruntDefeated
	end

CeruleanCity_EventScript_GruntDefeated::
	msgbox CeruleanCity_Text_OkayIllReturnStolenTM
	checkitemspace ITEM_TM28
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_EventScript_NoRoomForTM28
	giveitem_msg CeruleanCity_Text_RecoveredTM28FromGrunt, ITEM_TM28
	msgbox CeruleanCity_Text_BetterGetMovingBye
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_CERULEAN_GRUNT
	fadescreenswapbuffers FADE_FROM_BLACK
	setflag FLAG_GOT_TM28_FROM_ROCKET
	release
	end

CeruleanCity_EventScript_NoRoomForTM28::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox CeruleanCity_Text_MakeRoomForThisCantRun
	release
	end

CeruleanCity_EventScript_GruntTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_CERULEAN_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	goto CeruleanCity_EventScript_GruntTrigger
	end

CeruleanCity_EventScript_GruntTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_CERULEAN_GRUNT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto CeruleanCity_EventScript_GruntTrigger
	end

CeruleanCity_EventScript_GruntTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox CeruleanCity_Text_GruntIntro
	setvar VAR_LAST_TALKED, LOCALID_CERULEAN_GRUNT
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	goto CeruleanCity_EventScript_GruntDefeated
	end

CeruleanCity_EventScript_Policeman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_PeopleHereWereRobbed
	closemessage
	applymovement LOCALID_CERULEAN_POLICEMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeruleanCity_EventScript_LittleBoy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_LittleBoySlowbroMoved
	msgbox CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree
	release
	end

CeruleanCity_EventScript_LittleBoySlowbroMoved::
	msgbox CeruleanCity_Text_YouCanCutDownSmallTrees
	release
	end

CeruleanCity_EventScript_BaldingMan::
	msgbox CeruleanCity_Text_PokemonEncyclopediaAmusing, MSGBOX_NPC
	end

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_TrainerLifeIsToughIsntIt, MSGBOX_NPC
	end

CeruleanCity_EventScript_CeruleanCaveGuard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_EventScript_Woman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_WantBrightRedBicycle
	closemessage
	applymovement LOCALID_CERULEAN_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeruleanCity_EventScript_Lass::
	lock
	random 3
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroCommand1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroCommand2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroCommand3
	waitmessage
	delay 40
	playse SE_PIN
	applymovement LOCALID_CERULEAN_SLOWBRO, Common_Movement_QuestionMark
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroFailed1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroFailed2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroFailed3
	release
	end

CeruleanCity_EventScript_SlowbroCommand1::
	message CeruleanCity_Text_SlowbroUseSonicboom
	return

CeruleanCity_EventScript_SlowbroCommand2::
	message CeruleanCity_Text_SlowbroPunch
	return

CeruleanCity_EventScript_SlowbroCommand3::
	message CeruleanCity_Text_SlowbroWithdraw
	return

CeruleanCity_EventScript_SlowbroFailed1::
	msgbox CeruleanCity_Text_SlowbroPayAttention
	return

CeruleanCity_EventScript_SlowbroFailed2::
	msgbox CeruleanCity_Text_NoYouBlewItAgain
	return

CeruleanCity_EventScript_SlowbroFailed3::
	msgbox CeruleanCity_Text_HardToControlMonsObedience
	return

CeruleanCity_EventScript_Slowbro::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroText1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroText2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroText3
	call_if_eq VAR_0x8008, 3, CeruleanCity_EventScript_SlowbroText4
	release
	end

CeruleanCity_EventScript_SlowbroText1::
	msgbox CeruleanCity_Text_SlowbroTookSnooze
	return

CeruleanCity_EventScript_SlowbroText2::
	msgbox CeruleanCity_Text_SlowbroLoafingAround
	return

CeruleanCity_EventScript_SlowbroText3::
	msgbox CeruleanCity_Text_SlowbroTurnedAway
	return

CeruleanCity_EventScript_SlowbroText4::
	msgbox CeruleanCity_Text_SlowbroIgnoredOrders
	return

CeruleanCity_EventScript_CitySign::
	msgbox CeruleanCity_Text_CitySign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_TrainerTips::
	msgbox CeruleanCity_Text_TrainerTipsHeldItems, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_MISTY, 0
	msgbox CeruleanCity_Text_GymSign
	releaseall
	end

CeruleanCity_Text_RivalIntro::
	.string "{RIVAL}: ¡Eh! ¡{PLAYER}!\p"
	.string "¿Sigues pasándolas canutas por aquí\n"
	.string "atrás?\p"
	.string "¡A mí me va genial! ¡He atrapado un\n"
	.string "montón de POKéMON fuertes e\l"
	.string "inteligentes!\p"
	.string "¡Venga, a ver qué has atrapado,\n"
	.string "{PLAYER}!$"

CeruleanCity_Text_RivalDefeat::
	.string "¡Eh!\n"
	.string "¡Tranquilo!\l"
	.string "¡Ya has ganado!$"

CeruleanCity_Text_RivalPostBattle::
	.string "{RIVAL}: ¡Eh, a que no sabes qué?\p"
	.string "He ido a casa de BILL y le he hecho\n"
	.string "enseñarme sus POKéMON raros.\p"
	.string "¡Eso ha rellenado muchas páginas\n"
	.string "de mi POKéDEX!\p"
	.string "Al fin y al cabo, BILL es famoso en\n"
	.string "todo el mundo como POKéMANÍACO.\p"
	.string "También inventó el Sistema de\n"
	.string "Almacenamiento POKéMON del PC.\p"
	.string "Como usas su sistema, deberías\n"
	.string "ir a darle las gracias.\p"
	.string "¡Bueno, mejor me pongo en marcha!\n"
	.string "¡Hasta la vista!$"

CeruleanCity_Text_OhRightLittlePresentAsFavor::
	.string "Ah, sí, claro.\p"
	.string "Me das pena. De verdad. Siempre vas\n"
	.string "arrastrándote detrás de mí.\p"
	.string "Así que toma, te daré un regalito como\n"
	.string "favor.$"

CeruleanCity_Text_ExplainFameCheckerSmellYa::
	.string "Un cotilla parlanchín como tú…\n"
	.string "Esto es perfecto para ti.\p"
	.string "Yo no lo necesito porque me importan\n"
	.string "un bledo los demás.\p"
	.string "Bien, esta vez sí que me voy.\n"
	.string "¡Hasta la vista!$"

CeruleanCity_Text_GruntIntro::
	.string "¡Eh! ¡Fuera!\n"
	.string "¡No es tu jardín!\p"
	.string "…¿Eh?\n"
	.string "¿Yo?\p"
	.string "¡Soy un simple transeúnte!\n"
	.string "¿No me crees?{PLAY_BGM}{MUS_RG_ENCOUNTER_ROCKET}$"

CeruleanCity_Text_GruntDefeat::
	.string "GRUNT: ¡Para! ¡Me rindo!\n"
	.string "¡Me iré tranquilamente!$"

CeruleanCity_Text_OkayIllReturnStolenTM::
	.string "…Vale.\n"
	.string "Devolveré la MT que robé.$"

CeruleanCity_Text_RecoveredTM28FromGrunt::
	.string "{PLAYER} recuperó la MT28 del\n"
	.string "GRUNT del TEAM ROCKET.$"

CeruleanCity_Text_BetterGetMovingBye::
	.string "¡Mejor me pongo en marcha!\n"
	.string "¡Adiós!$"

CeruleanCity_Text_MakeRoomForThisCantRun::
	.string "¡Haz hueco para esto!\n"
	.string "¡No puedo irme hasta dártelo!$"

CeruleanCity_Text_TrainerLifeIsToughIsntIt::
	.string "¿Tú también eres ENTRENADOR?\p"
	.string "Coleccionar, combatir…\n"
	.string "Es una vida dura, ¿verdad?$"

CeruleanCity_Text_YouCanCutDownSmallTrees::
	.string "¿Sabías que se pueden talar con\n"
	.string "CORTE los árboles pequeños?\p"
	.string "Hasta el arbolito de delante de la\n"
	.string "tienda se puede talar.\p"
	.string "Aunque creo que hay un camino\n"
	.string "que lo rodea.$"

CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree::
	.string "Si ese SLOWBRO no estuviera ahí,\n"
	.string "podrías talar el arbolito con CORTE.\p"
	.string "Así podrías llegar al otro lado.\p"
	.string "Aunque creo que hay un camino\n"
	.string "que lo rodea.$"

CeruleanCity_Text_PokemonEncyclopediaAmusing::
	.string "¿Estás haciendo una enciclopedia de\n"
	.string "POKéMON? Qué divertido.$"

CeruleanCity_Text_PeopleHereWereRobbed::
	.string "Han robado a la gente de aquí.\p"
	.string "¡Está claro que el TEAM ROCKET\n"
	.string "está detrás de este vil crimen!\p"
	.string "¡Hasta nuestra POLICÍA tiene\n"
	.string "problemas con los ROCKET!$"

CeruleanCity_Text_SlowbroUseSonicboom::
	.string "¡Vale! ¡SLOWBRO!\n"
	.string "¡Usa SONICBOOM!$"

CeruleanCity_Text_SlowbroPayAttention::
	.string "¡Vamos, SLOWBRO, presta atención!$"

CeruleanCity_Text_SlowbroPunch::
	.string "¡SLOWBRO, puñetazo!$"

CeruleanCity_Text_NoYouBlewItAgain::
	.string "¡No!\n"
	.string "¡Lo has vuelto a fastidiar!$"

CeruleanCity_Text_SlowbroWithdraw::
	.string "¡SLOWBRO, REFUGIO!$"

CeruleanCity_Text_HardToControlMonsObedience::
	.string "¡No! ¡Eso está mal!\n"
	.string "¡Es muy difícil controlar a los POKéMON!\p"
	.string "La obediencia de tus POKéMON depende\n"
	.string "de tus habilidades como ENTRENADOR.$"

CeruleanCity_Text_SlowbroTookSnooze::
	.string "SLOWBRO se echó una siesta…$"

CeruleanCity_Text_SlowbroLoafingAround::
	.string "SLOWBRO está holgazaneando…$"

CeruleanCity_Text_SlowbroTurnedAway::
	.string "SLOWBRO miró hacia otro lado…$"

CeruleanCity_Text_SlowbroIgnoredOrders::
	.string "SLOWBRO ignoró las órdenes…$"

CeruleanCity_Text_WantBrightRedBicycle::
	.string "Quiero una bicicleta rojo brillante.\p"
	.string "La guardaré en casa para que\n"
	.string "no se ensucie.$"

CeruleanCity_Text_ThisIsCeruleanCave::
	.string "Esta es la CUEVA CELESTE.\p"
	.string "Dentro viven POKéMON terriblemente\n"
	.string "fuertes.\p"
	.string "Solo se permite la entrada a un\n"
	.string "ENTRENADOR muy especial.\p"
	.string "Para empezar, tendrías que ser lo\n"
	.string "bastante fuerte como para ser\l"
	.string "CAMPEÓN de la LIGA POKéMON.\p"
	.string "Y además, tendrías que haber\n"
	.string "conseguido una gran hazaña.$"

CeruleanCity_Text_CitySign::
	.string "CIUDAD CELESTE\n"
	.string "Un aura azul misteriosa la rodea$"

CeruleanCity_Text_TrainerTipsHeldItems::
	.string "PISTAS ENTRENADOR\p"
	.string "Se puede hacer que un POKéMON\n"
	.string "sostenga un objeto.\p"
	.string "Algunos objetos pueden incluso ser\n"
	.string "usados en combate por el POKéMON.$"

CeruleanCity_Text_BikeShopSign::
	.string "¡Hierba y cuevas sin problemas!\n"
	.string "TIENDA DE BICIS$"

CeruleanCity_Text_GymSign::
	.string "GIMNASIO POKéMON de CIUDAD CELESTE\n"
	.string "LÍDER: MISTY\l"
	.string "¡La Sirena Marimacho!$"

