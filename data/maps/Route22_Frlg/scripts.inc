Route22_Frlg_MapScripts::
	.byte 0

Route22_EventScript_EarlyRivalTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route22_EventScript_EarlyRival
	end

Route22_EventScript_EarlyRivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 25, 5
	goto Route22_EventScript_EarlyRival
	end

Route22_EventScript_EarlyRivalTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 25, 5
	goto Route22_EventScript_EarlyRival
	end

Route22_EventScript_EarlyRival::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	addobject LOCALID_ROUTE22_RIVAL
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_EarlyRivalApproach
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_EarlyRivalApproach
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_EarlyRivalApproachBottom
	delay 6
	msgbox Route22_Text_EarlyRivalIntro
	call_if_eq VAR_STARTER_MON, 2, Route22_EventScript_EarlyRivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, Route22_EventScript_EarlyRivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, Route22_EventScript_EarlyRivalCharmander
	msgbox Route22_Text_EarlyRivalPostBattle
	closemessage
	delay 10
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_EarlyRivalExit
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_EarlyRivalExit
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_EarlyRivalExitBottom
	fadedefaultbgm
	removeobject LOCALID_ROUTE22_RIVAL
	setvar VAR_MAP_SCENE_ROUTE22, 2
	releaseall
	end

Route22_EventScript_EarlyRivalApproach::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproach
	waitmovement 0
	return

Route22_EventScript_EarlyRivalApproachBottom::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproachBottom
	applymovement LOCALID_PLAYER, Route22_Movement_PlayerFaceRival
	waitmovement 0
	return

Route22_EventScript_EarlyRivalSquirtle::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_SQUIRTLE, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return

Route22_EventScript_EarlyRivalBulbasaur::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_BULBASAUR, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return

Route22_EventScript_EarlyRivalCharmander::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_CHARMANDER, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return

Route22_EventScript_EarlyRivalExit::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_EarlyRivalExit
	waitmovement 0
	return

Route22_EventScript_EarlyRivalExitBottom::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_EarlyRivalExitBottom
	waitmovement 0
	return

Route22_Movement_UnusedRivalExit:: @ 8
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route22_Movement_EarlyRivalExit::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route22_Movement_EarlyRivalExitBottom::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route22_Movement_RivalApproach::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route22_Movement_RivalApproachBottom::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

Route22_Movement_PlayerFaceRival::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_up
	step_end

Route22_EventScript_LateRivalTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route22_EventScript_LateRival
	end

Route22_EventScript_LateRivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 25, 5
	goto Route22_EventScript_LateRival
	end

Route22_EventScript_LateRivalTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 25, 5
	goto Route22_EventScript_LateRival
	end

Route22_EventScript_LateRival::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	addobject LOCALID_ROUTE22_RIVAL
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_LateRivalApproach
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_LateRivalApproach
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_LateRivalApproachBottom
	msgbox Route22_Text_LateRivalIntro
	setvar VAR_LAST_TALKED, LOCALID_ROUTE22_RIVAL
	call_if_eq VAR_STARTER_MON, 2, Route22_EventScript_LateRivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, Route22_EventScript_LateRivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, Route22_EventScript_LateRivalCharmander
	msgbox Route22_Text_LateRivalPostBattle
	closemessage
	delay 10
	playbgm MUS_RG_RIVAL_EXIT, 0
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_LateRivalExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_ROUTE22_RIVAL
	setvar VAR_MAP_SCENE_ROUTE22, 4
	releaseall
	end

Route22_EventScript_LateRivalApproach::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproach
	waitmovement 0
	return

Route22_EventScript_LateRivalApproachBottom::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproachBottom
	applymovement LOCALID_PLAYER, Route22_Movement_PlayerFaceRival
	waitmovement 0
	return

Route22_EventScript_LateRivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_SQUIRTLE, Route22_Text_LateRivalDefeat
	return

Route22_EventScript_LateRivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_BULBASAUR, Route22_Text_LateRivalDefeat
	return

Route22_EventScript_LateRivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_CHARMANDER, Route22_Text_LateRivalDefeat
	return

Route22_Movement_LateRivalExit::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route22_EventScript_LeagueGateSign::
	msgbox Route22_Text_LeagueGateSign, MSGBOX_SIGN
	end

Route22_Text_EarlyRivalIntro::
	.string "{RIVAL}: ¡Eh! ¡{PLAYER}!\p"
	.string "¿Vas a la LIGA POKéMON?\n"
	.string "¡Olvídalo!\p"
	.string "Seguro que no tienes ninguna\n"
	.string "MEDALLA, ¿verdad?\p"
	.string "El guardia no te dejará pasar\n"
	.string "sin ellas.\p"
	.string "Por cierto, ¿se han hecho más\n"
	.string "fuertes tus POKéMON?$"

Route22_Text_EarlyRivalDefeat::
	.string "¡Aaah!\n"
	.string "¡Has tenido suerte!$"

Route22_Text_EarlyRivalPostBattle::
	.string "¡Dicen que los ENTRENADORES de la\n"
	.string "LIGA POKéMON son muy fuertes!\p"
	.string "¡Tengo que buscar una forma de\n"
	.string "vencerles!\p"
	.string "¡Deja de perder el tiempo y\n"
	.string "muévete!$"

@ Translated in RB as "{RIVAL}: What? Why do I have 2 POKéMON? You should catch some more too!"
Route22_Text_RivalShouldCatchSomeMons::
	.string "{RIVAL}: ¿Qué?\n"
	.string "¿Que por qué llevo dos\l"
	.string "POKéMON?\p"
	.string "¡Pues captura tú también\n"
	.string "uno más!$"

Route22_Text_LateRivalIntro::
	.string "{RIVAL}: ¿Qué? ¡{PLAYER}!\n"
	.string "¡Qué sorpresa verte aquí!\p"
	.string "¿Vas a ir a la LIGA POKéMON?\p"
	.string "¿Y tienes todas las MEDALLAS?\n"
	.string "¡Genial!\p"
	.string "¡Lucharé contra ti, {PLAYER}, como\n"
	.string "preparación para la LIGA POKéMON!\p"
	.string "¡Vamos allá!$"

Route22_Text_LateRivalDefeat::
	.string "¿¡Qué!?\p"
	.string "¡Es que no he tenido cuidado!$"

Route22_Text_LateRivalPostBattle::
	.string "¡Qué buen calentamiento!\n"
	.string "¡Listo para la LIGA POKéMON!\p"
	.string "¡{PLAYER}, necesitas más práctica!\p"
	.string "¡Ya lo sabes! ¡Yo me largo!\n"
	.string "¡Hasta luego!$"

@ Translated in RB as "{RIVAL}: Hahaha! {PLAYER}! That's your best? You're nowhere near as good as me, pal! Go train some more! You loser!"
Route22_Text_LateRivalVictory::
	.string "{RIVAL}: ¡Ja, ja, {PLAYER}!\n"
	.string "¿Con eso te esfuerzas?\l"
	.string "Comparado con mi talento,\l"
	.string "{PLAYER} aún tiene que mejorar.\p"
	.string "¡Entrena más!\n"
	.string "¡Jajaja!$"

Route22_Text_LeagueGateSign::
	.string "LIGA POKéMON\n"
	.string "Puerta delantera$"

