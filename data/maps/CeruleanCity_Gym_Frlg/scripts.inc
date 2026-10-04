CeruleanCity_Gym_Frlg_MapScripts::
	.byte 0

CeruleanCity_Gym_EventScript_Misty::
	famechecker FAMECHECKER_MISTY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_MISTY, CeruleanCity_Gym_Text_MistyIntro, CeruleanCity_Gym_Text_MistyDefeat, CeruleanCity_Gym_EventScript_MistyDefeated, NO_MUSIC
	goto_if_unset FLAG_GOT_TM03_FROM_MISTY, CeruleanCity_Gym_EventScript_GiveTM03
	msgbox CeruleanCity_Gym_Text_ExplainTM03
	release
	end

CeruleanCity_Gym_EventScript_MistyDefeated::
	famechecker FAMECHECKER_MISTY, 1
	setflag FLAG_DEFEATED_MISTY
	setflag FLAG_BADGE02_GET
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	set_gym_trainers_frlg 2
	goto CeruleanCity_Gym_EventScript_GiveTM03
	end

CeruleanCity_Gym_EventScript_GiveTM03::
	msgbox CeruleanCity_Gym_Text_ExplainCascadeBadge
	checkitemspace ITEM_TM03
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_Gym_EventScript_NoRoomForTM03
	giveitem_msg CeruleanCity_Gym_Text_ReceivedTM03FromMisty, ITEM_TM03
	setflag FLAG_GOT_TM03_FROM_MISTY
	msgbox CeruleanCity_Gym_Text_ExplainTM03
	release
	end

CeruleanCity_Gym_EventScript_NoRoomForTM03::
	msgbox CeruleanCity_Gym_Text_BetterMakeRoomForThis
	release
	end

CeruleanCity_Gym_EventScript_Diana::
	trainerbattle_single TRAINER_PICNICKER_DIANA, CeruleanCity_Gym_Text_DianaIntro, CeruleanCity_Gym_Text_DianaDefeat
	msgbox CeruleanCity_Gym_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_Luis::
	trainerbattle_single TRAINER_SWIMMER_MALE_LUIS, CeruleanCity_Gym_Text_LuisIntro, CeruleanCity_Gym_Text_LuisDefeat
	famechecker FAMECHECKER_MISTY, 2
	msgbox CeruleanCity_Gym_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MISTY, CeruleanCity_Gym_EventScript_GymGuyPostVictory
	msgbox CeruleanCity_Gym_Text_GymGuyAdvice
	release
	end

CeruleanCity_Gym_EventScript_GymGuyPostVictory::
	msgbox CeruleanCity_Gym_Text_WeMakePrettyGoodTeam
	release
	end

CeruleanCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanCity_Gym_Text_MistyIntro::
	.string "¡Hola, eres un recién llegado!\p"
	.string "Solo los ENTRENADORES con una\n"
	.string "filosofía sobre los POKéMON pueden\l"
	.string "hacerse profesionales.\p"
	.string "¿Cuál es tu enfoque cuando capturas\n"
	.string "y entrenas POKéMON?\p"
	.string "¡Mi filosofía es la ofensiva total\n"
	.string "con POKéMON de tipo AGUA!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

CeruleanCity_Gym_Text_ExplainTM03::
	.string "¡La MT03 enseña HIDROPULSO!\p"
	.string "¡Úsala con los POKéMON del tipo\n"
	.string "AGUA!$"

CeruleanCity_Gym_Text_ExplainCascadeBadge::
	.string "¡La MEDALLA CASCADA obligará a\n"
	.string "todos los POKéMON por debajo del\l"
	.string "nivel 30 a obedecer!\p"
	.string "¡Incluidos los forasteros!\p"
	.string "¡Y podrás usar CORTAR siempre que\n"
	.string "quieras!\p"
	.string "¡Puedes CORTAR pequeños arbustos\n"
	.string "para abrir nuevos caminos!\p"
	.string "¡Voy a darte mi MT favorita!$"

CeruleanCity_Gym_Text_ReceivedTM03FromMisty::
	.string "¡{PLAYER} obtuvo la MT03\n"
	.string "de manos de MISTY!$"

CeruleanCity_Gym_Text_BetterMakeRoomForThis::
	.string "¡Más vale que le hagas sitio!$"

CeruleanCity_Gym_Text_MistyDefeat::
	.string "¡Uauuu!\n"
	.string "¡Eres demasiado!\p"
	.string "¡Muy bien!\p"
	.string "¡Toma la MEDALLA CASCADA para que\n"
	.string "todos sepan que me has ganado!$"

CeruleanCity_Gym_Text_DianaIntro::
	.string "¡Soy demasiado buena para ti!\p"
	.string "¡MISTY puede esperar!$"

CeruleanCity_Gym_Text_DianaDefeat::
	.string "¡Me has machacado!$"

CeruleanCity_Gym_Text_DianaPostBattle::
	.string "Tienes que luchar contra otros\n"
	.string "ENTRENADORES para saber lo fuerte\l"
	.string "que eres.$"

CeruleanCity_Gym_Text_LuisIntro::
	.string "¡Splash!\p"
	.string "¡Soy el primero!\n"
	.string "¡Al ataque!$"

CeruleanCity_Gym_Text_LuisDefeat::
	.string "¡No puede ser!$"

CeruleanCity_Gym_Text_LuisPostBattle::
	.string "¡MISTY es cada vez más fuerte!\p"
	.string "¡No perderá con alguien como tú!$"

CeruleanCity_Gym_Text_GymGuyAdvice::
	.string "¡Hola, aspirante al título!\p"
	.string "¡Un consejo!\p"
	.string "¡La LÍDER, MISTY, es profesional\n"
	.string "y usa POKéMON acuáticos!\p"
	.string "¡Puedes absorber toda su agua con\n"
	.string "los POKéMON del tipo PLANTA!\p"
	.string "¡O dejarlos hechos polvo usando\n"
	.string "POKéMON del tipo ELÉCTRICO!$"

CeruleanCity_Gym_Text_WeMakePrettyGoodTeam::
	.string "¡Has ganado a MISTY!\n"
	.string "¡No sé qué decirte!\p"
	.string "¡Tú y yo formaríamos un equipo\n"
	.string "invencible!$"

CeruleanCity_Gym_Text_GymStatue::
	.string "LÍDER del GIMNASIO POKéMON\n"
	.string "de CELESTE: MISTY\p"
	.string "ENTRENADOR GANADOR:\n"
	.string "{RIVAL}$"

CeruleanCity_Gym_Text_GymStatuePlayerWon::
	.string "LÍDER del GIMNASIO POKéMON\n"
	.string "de CELESTE: MISTY\p"
	.string "ENTRENADORES GANADORES:\n"
	.string "{RIVAL} y {PLAYER}$"

