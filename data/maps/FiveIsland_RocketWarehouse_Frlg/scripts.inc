.equ PLAYER_X_POS, VAR_0x8004
.equ PLAYER_Y_POS, VAR_0x8005

FiveIsland_RocketWarehouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FiveIsland_RocketWarehouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_RocketWarehouse_OnTransition
	.byte 0

FiveIsland_RocketWarehouse_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FIVE_ISLAND_ROCKET_WAREHOUSE
	end

FiveIsland_RocketWarehouse_OnLoad::
	call_if_defeated TRAINER_TEAM_ROCKET_ADMIN, FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry
	end

FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry::
	setmetatile 26, 20, METATILE_SilphCo_Arrow_Up, 0
	setmetatile 27, 20, METATILE_SilphCo_Arrow_Up, 0
	return

FiveIsland_RocketWarehouse_EventScript_Cage::
	lockall
	goto_if_set FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE, FiveIsland_RocketWarehouse_EventScript_CageUnlocked
	msgbox FiveIsland_RocketWarehouse_Text_ManyMonsLockedInPen
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_CageUnlocked::
	msgbox FiveIsland_RocketWarehouse_Text_PenUnlockedMonsFled
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_Computer::
	msgbox FiveIsland_RocketWarehouse_Text_ReportWithGraphsAndText, MSGBOX_SIGN
	end

FiveIsland_RocketWarehouse_EventScript_Admin2Trigger::
	lockall
	applymovement LOCALID_WAREHOUSE_ADMIN2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_Gideon::
	trainerbattle_single TRAINER_SCIENTIST_GIDEON, FiveIsland_RocketWarehouse_Text_GideonIntro, FiveIsland_RocketWarehouse_Text_GideonDefeat, FiveIsland_RocketWarehouse_EventScript_DefeatedGideon
	goto_if_set FLAG_IS_CHAMPION, FiveIsland_RocketWarehouse_EventScript_MentionGiovannisKid
	msgbox FiveIsland_RocketWarehouse_Text_GetLostLeaveMeBe, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_MentionGiovannisKid::
	famechecker FAMECHECKER_GIOVANNI, 5
	msgbox FiveIsland_RocketWarehouse_Text_GiovannisKidHasRedHair, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedGideon::
	msgbox FiveIsland_RocketWarehouse_Text_GideonPostBattle
	setflag FLAG_RECOVERED_SAPPHIRE
	giveitem ITEM_SAPPHIRE
	release
	end

FiveIsland_RocketWarehouse_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_47, FiveIsland_RocketWarehouse_Text_Grunt2Intro, FiveIsland_RocketWarehouse_Text_Grunt2Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_48, FiveIsland_RocketWarehouse_Text_Grunt3Intro, FiveIsland_RocketWarehouse_Text_Grunt3Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Admin2::
	trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN_2, FiveIsland_RocketWarehouse_Text_Admin2Intro, FiveIsland_RocketWarehouse_Text_Admin2Defeat, FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin2
	msgbox FiveIsland_RocketWarehouse_Text_Admin2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin2::
	getplayerxy PLAYER_X_POS, PLAYER_Y_POS
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin2
	msgbox FiveIsland_RocketWarehouse_Text_Admin2PostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_WAREHOUSE_GRUNT2
	removeobject LOCALID_WAREHOUSE_GRUNT3
	removeobject LOCALID_WAREHOUSE_ADMIN2
	removeobject LOCALID_WAREHOUSE_ADMIN1
	setflag FLAG_HIDE_FIVE_ISLAND_ROCKETS
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
	setflag FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE
	release
	end

FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin2::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_42, FiveIsland_RocketWarehouse_Text_Grunt1Intro, FiveIsland_RocketWarehouse_Text_Grunt1Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Admin1::
	trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN, FiveIsland_RocketWarehouse_Text_Admin1Intro, FiveIsland_RocketWarehouse_Text_Admin1Defeat, FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin1
	msgbox FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin1::
	getplayerxy PLAYER_X_POS, PLAYER_Y_POS
	specialvar VAR_RESULT, GetPlayerFacingDirection
	call_if_eq VAR_RESULT, DIR_NORTH, FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin1
	msgbox FiveIsland_RocketWarehouse_Text_Admin1PostBattle
	closemessage
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitchFar
	call_if_eq PLAYER_X_POS, 25, FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitch
	call_if_eq PLAYER_X_POS, 26, FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch
	call_if_eq PLAYER_X_POS, 27, FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch
	playse SE_PIN
	call FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry
	special DrawWholeMapView
	waitse
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 25, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 26, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 27, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerDown
	msgbox FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough
	release
	end

FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin1::
	goto_if_eq PLAYER_X_POS, 27, Common_EventScript_NopReturn
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitchFar::
	applymovement LOCALID_WAREHOUSE_ADMIN1, FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitchFar
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitch::
	applymovement LOCALID_WAREHOUSE_ADMIN1, FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitch
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerDown::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitchFar::
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitch::
	walk_right
	walk_in_place_faster_up
	step_end

FiveIsland_RocketWarehouse_Text_ManyMonsLockedInPen::
	.string "Hay muchos POKéMON encerrados\n"
	.string "en el corral…$"

FiveIsland_RocketWarehouse_Text_PenUnlockedMonsFled::
	.string "La puerta está abierta.\n"
	.string "Se ve que los POKéMON han huido.$"

FiveIsland_RocketWarehouse_Text_Grunt2Intro::
	.string "¿Has venido hasta aquí sabiendo\n"
	.string "que era el ALMACÉN ROCKET?$"

FiveIsland_RocketWarehouse_Text_Grunt2Defeat::
	.string "Pero bueno, ¿tú qué te crees?$"

FiveIsland_RocketWarehouse_Text_Grunt2PostBattle::
	.string "¿Que si el TEAM ROCKET se ha\n"
	.string "separado?\l"
	.string "Pero ¿tú de qué planeta vienes?$"

FiveIsland_RocketWarehouse_Text_Grunt1Intro::
	.string "Tus POKéMON parecen muy fuertes.\n"
	.string "¿No te gustaría venderlos?\p"
	.string "¡Ah, que quieres luchar!$"

FiveIsland_RocketWarehouse_Text_Grunt1Defeat::
	.string "Oh, pero…\n"
	.string "¡Es demasiado!$"

FiveIsland_RocketWarehouse_Text_Grunt1PostBattle::
	.string "Te daremos un gran precio.\n"
	.string "¡Véndenos tus POKéMON!$"

FiveIsland_RocketWarehouse_Text_Grunt3Intro::
	.string "Me han hablado mucho de ti.\p"
	.string "¡Ante nuestro JEFE GIOVANNI\n"
	.string "no vas a poder hacer nada!$"

FiveIsland_RocketWarehouse_Text_Grunt3Defeat::
	.string "No…te…atrevas…a reírte…$"

FiveIsland_RocketWarehouse_Text_Grunt3PostBattle::
	.string "¡No te metas en los asuntos de\n"
	.string "los mayores, renacuajo engreído!$"

FiveIsland_RocketWarehouse_Text_Admin1Intro::
	.string "Ni sé ni me importa si lo que hago\n"
	.string "está bien o no...\p"
	.string "Yo confío en GIOVANNI y cumplo\n"
	.string "con lo que se me dice.$"

FiveIsland_RocketWarehouse_Text_Admin1Defeat::
	.string "Es-estoy... sin aliento...$"

FiveIsland_RocketWarehouse_Text_Admin1PostBattle::
	.string "Entiendo que lo que haces responde\n"
	.string "a tus principios.\p"
	.string "Ahora lo entiendo.$"

FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough::
	.string "He dejado esto así para que\n"
	.string "puedas volver a entrar.\p"
	.string "¿No quieres descansar antes de\n"
	.string "continuar con lo que te queda?\p"
	.string "El ADMINISTRADOR que me sigue\n"
	.string "es mejor ENTRENADOR que yo.\p"
	.string "Más vale que te prepares para\n"
	.string "un difícil encuentro.$"

FiveIsland_RocketWarehouse_Text_Admin2Intro::
	.string "Ya está bien de ir de guay.\p"
	.string "Lo de contar que el TEAM ROCKET\n"
	.string "se ha separado es...\p"
	.string "un intento descarado de causar\n"
	.string "el desconcierto entre nosotros.\p"
	.string "Pero afortunadamente no somos\n"
	.string "lelos y no nos tragamos semejantes\l"
	.string "chorradas.\p"
	.string "¡Te vas a enterar de lo que llegan\n"
	.string "a molestar estas cosas!$"

FiveIsland_RocketWarehouse_Text_Admin2Defeat::
	.string "Urgh…\n"
	.string "Eras demasiado fuerte…\p"
	.string "…\n"
	.string "¡E-esa es la MEDALLA de GIOVANNI!\p"
	.string "¿Es verdad entonces?\n"
	.string "¿El TEAM ROCKET se ha disuelto?$"

FiveIsland_RocketWarehouse_Text_Admin2PostBattle::
	.string "¡Nos iremos del ALMACÉN!...\p"
	.string "Pero no te pienses que la cosa\n"
	.string "se queda ahí. ¡Ya me ocuparé yo!\p"
	.string "Iré a buscar a GIOVANNI y reuniré\n"
	.string "al TEAM ROCKET. ¡Ya lo verás!\p"
	.string "¡Hasta entonces, ya nos veremos!$"

FiveIsland_RocketWarehouse_Text_ReportWithGraphsAndText::
	.string "Hay un informe con gráficos\n"
	.string "y anotaciones en el monitor del PC.\p"
	.string "“La influencia de las ondas\n"
	.string "magnéticas en la evolución de los\l"
	.string "POKéMON”...\p"
	.string "... ... ... ... ... ...\p"
	.string "Cualquiera entiende esto...$"

FiveIsland_RocketWarehouse_Text_GideonIntro::
	.string "He estado a punto de vender\n"
	.string "el ZAFIRO por un buen pellizco...\p"
	.string "¡Y vas tú y apareces justo cuando\n"
	.string "iba a cerrar el trato!\p"
	.string "¡Grrrrrrrrrrrrrrrrr...!\n"
	.string "¡No tienes perdón!$"

FiveIsland_RocketWarehouse_Text_GideonDefeat::
	.string "¡Grr! ¡Maldición!\n"
	.string "¡Maldición! ¡Maldición!$"

FiveIsland_RocketWarehouse_Text_GideonPostBattle::
	.string "¡Si no puedo venderlo, no vale\n"
	.string "nada! ¡Adelante, llévatelo!$"

FiveIsland_RocketWarehouse_Text_GetLostLeaveMeBe::
	.string "¿Y ahora qué?\n"
	.string "¿Quieres dejarme ya en paz?$"

FiveIsland_RocketWarehouse_Text_GiovannisKidHasRedHair::
	.string "Pero ¿otra vez tú?\p"
	.string "Tú... tú no eres el retoño\n"
	.string "de GIOVANNI, ¿verdad?\p"
	.string "No, no puede ser, el retoño\n"
	.string "de GIOVANNI es pelirrojo.\p"
	.string "Bueno, ¿y por qué me incordias?\n"
	.string "Déjame, anda.$"

