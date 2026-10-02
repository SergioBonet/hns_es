BurnedTower_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BurnedTower_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BurnedTower_1F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BurnedTower_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BurnedTower_1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

BurnedTower_1F_OnLoad::
	goto_if_ge VAR_ECRUTEAK_CITY_STATE, 4, BurnedTower_1F_MapScript_CreateHole
	end

BurnedTower_1F_MapScript_CreateHole::
	setmetatile 16, 12, 0x37E, FALSE
	end

BurnedTower_1F_OnFrame::
	map_script_2 VAR_ECRUTEAK_CITY_STATE, 1, BurnedTower_1F_EventScript_MeetEusine
	.2byte 0

BurnedTower_1F_EventScript_MeetEusine::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_EUSINE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_BURNED_TOWER_EUSINE
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine1
	waitmovement 0
	msgbox BurnedTower_1FEusineIntroText, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine2
	waitmovement 0
	setvar VAR_ECRUTEAK_CITY_STATE, 2
	release
	end

BurnedTower_Movement_Eusine1:
	walk_down
	walk_down
	step_end

BurnedTower_Movement_Eusine2:
	walk_up
	walk_up
	step_end


BurnedTower_1FEusineIntroText:
	.string "EUSINE: Me llamo EUSINE.\p"
	.string "Sigo la pista de un POKéMON llamado\n"
	.string "SUICUNE.\p"
	.string "¿Y tú eres…?\p"
	.string "¿{PLAYER}? ¡Encantado de conocerte!\p"
	.string "He oído que SUICUNE podría estar en\n"
	.string "esta TORRE QUEMADA, así que he venido\l"
	.string "a comprobarlo.\p"
	.string "Pero ¿dónde estará exactamente?$"

BurnedTower_1F_EventScript_Item_HpUp::
	finditem ITEM_HP_UP
	end

BurnedTower_1F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

BurnedTower_1F_EventScript_Eusine::
	lock
	faceplayer
	msgbox BurnedTower_1FEusineText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1F_EventScript_Morty::
	lock
	faceplayer
	msgbox BurnedTower_1FMortyText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1FEusineText:
	.string "EUSINE: He oído que SUICUNE podría\n"
	.string "estar en esta TORRE QUEMADA, así que\l"
	.string "he venido a comprobarlo.\p"
	.string "Pero ¿dónde estará exactamente?$"

BurnedTower_1FMortyText:
	.string "MORTI: El LÍDER del GIMNASIO de\n"
	.string "CIUDAD IRIS debe estudiar a los que\l"
	.string "se consideran POKéMON legendarios:\l"
	.string "SUICUNE, ENTEI y RAIKOU.\p"
	.string "Como EUSINE está aquí, he decidido\n"
	.string "investigar la TORRE con él.$"

BurnedTower_1F_EventScript_Silver::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_BURNED_TOWER_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_WalkLeft1
	waitmovement 0
	waitmovement 0
	msgbox BurnedTowerSilver_BeforeText, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, BurnedTower_1F_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, BurnedTower_1F_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, BurnedTower_1F_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox BurnedTowerSilver_AfterText1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_CLICK
	setmetatile 16, 12, 0x37E, FALSE
	special DrawWholeMapView
	waitse
	delay 60
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	msgbox BurnedTowerSilver_AfterText2, MSGBOX_AUTOCLOSE
	waitmessage
	warphole MAP_BURNED_TOWER_B1F_HNS
	setvar VAR_ECRUTEAK_CITY_STATE, 3
	waitstate
	release
	end

BurnedTower_1F_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTowerSilver_BeforeText:
	.string "……\p"
	.string "… Ah, eres tú.\p"
	.string "He venido a buscar unos POKéMON\n"
	.string "legendarios que dicen que se refugian\l"
	.string "aquí.\p"
	.string "¡Pero aquí no hay nada!\p"
	.string "¿Nada, después de tanto esfuerzo\n"
	.string "para venir a este vertedero? ¡No\l"
	.string "puede ser!\p"
	.string "¡Todo es culpa tuya!$"

BurnedTowerSilver_WinText:
	.string "… ¡Bah!\p"
	.string "Solo he perdido porque mis POKéMON\n"
	.string "son debilísimos.\p"
	.string "Qué patético.$"

BurnedTowerSilver_AfterText1:
	.string "… Bah, me da igual.\p"
	.string "De todas formas, tú nunca podrías\n"
	.string "atrapar a un POKéMON legendario.$"

BurnedTowerSilver_LossText:
	.string "… ¡Bah!\p"
	.string "Por eso odio luchar con debiluchos. Es\n"
	.string "una pérdida de tiempo.$"

BurnedTowerSilver_AfterText2:
	.string "¡Bah!\p"
	.string "¿Qué haces cayéndote por un agujero?\n"
	.string "¡Menudo genio!\p"
	.string "¡Te lo tienes merecido!$"

BurnedTower_1F_EventScript_Nard::
	trainerbattle_single TRAINER_NARD_HNS, BurnedTower_Text_NardSeen, BurnedTower_Text_NardBeaten
	msgbox BurnedTower_Text_NardAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_1F_EventScript_Richardo::
	trainerbattle_single TRAINER_RICHARDO_HNS, BurnedTower_Text_RichardoSeen, BurnedTower_Text_RichardoBeaten
	msgbox BurnedTower_Text_RichardoAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_Text_NardSeen:
	.string "¡No te preocupes!\p"
	.string "¡Los que escupimos fuego conocemos\n"
	.string "el verdadero poder del fuego mejor\l"
	.string "que nadie!$"
BurnedTower_Text_NardBeaten:
	.string "Gracias por este combate tan\n"
	.string "ardiente.$"
BurnedTower_Text_NardAfter:
	.string "La TORRE QUEMADA está así por un\n"
	.string "rayo.\p"
	.string "¿O pensabas que con estas llamitas de\n"
	.string "nada podría haberlo hecho yo?$"

BurnedTower_Text_RichardoSeen:
	.string "¡Estoy practicando mis robos en la\n"
	.string "TORRE QUEMADA! ¡No lo intentes en\l"
	.string "casa!$"
BurnedTower_Text_RichardoBeaten:
	.string "Pfffffffffffffff.$"
BurnedTower_Text_RichardoAfter:
	.string "Quizás la vida de delincuente no es\n"
	.string "para mí…$"
