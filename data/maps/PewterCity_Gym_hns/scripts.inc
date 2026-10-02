PewterCity_Gym_hns_MapScripts::
	.byte 0



PewterCity_Gym_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY_HNS, PewterCity_Gym_Text_CamperJerry_Seen, PewterCity_Gym_Text_CamperJerry_Beaten
	msgbox PewterCity_Gym_Text_CamperJerry_AfterBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_Brock_Defeated
	msgbox PewterCity_Gym_Text_Brock_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BROCK_HNS, PewterCity_Gym_Text_Brock_WinLoss
	message PewterCity_Gym_Text_ReceivedBoulderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PewterCity_Gym_Text_Brock_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROCK_SLIDE
	msgbox PewterCity_Gym_Text_Brock_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE09_GET
	setflag FLAG_DEFEATED_PEWTER_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 9
	call Common_EventScript_SetGymTrainers_hns
	clearflag FLAG_HIDE_DIGLETT_BROCK
	closemessage
	release
	end

PewterCity_Gym_EventScript_Brock_Defeated::
	goto_if_unset FLAG_HIDE_DOJO_BROCK, PewterCity_Gym_EventScript_Brock_Trade
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	closemessage
	release
	end


PewterCity_Gym_Text_Brock_Intro:
	.string "BROCK: ¡Uau! No todos los días nos\n"
	.string "desafía alguien de JOHTO.\p"
	.string "Soy BROCK, LÍDER del GIM. de C.\p"
	.string "PLATEADA y experto en POKéMON roca.\p"
	.string "Mis POKéMON son insensibles a la\n"
	.string "mayoría de ataques físicos. Te será\l"
	.string "muy difícil hacerles daño.\p"
	.string "¡Venga!$"

PewterCity_Gym_Text_Brock_WinLoss:
	.string "BROCK: Mi dura defensa no soportó los\n"
	.string "ataques de tus POKéMON…\p"
	.string "Eres más fuerte de lo que pensaba…\p"
	.string "Toma. Coge esta MEDALLA.$"

PewterCity_Gym_Text_ReceivedBoulderBadge:
	.string "{PLAYER} recibió la MEDALLA ROCA.$"

PewterCity_Gym_Text_Brock_GiveTM:
	.string "Toma, llévate esta MT.$"

PewterCity_Gym_Text_Brock_ExplainTM:
	.string "Contiene AVALANCHA.\p"
	.string "Lanza rocas sobre los rivales y puede\n"
	.string "hacerlos retroceder.\p"
	.string "Úsala para frenarlos en seco.$"

PewterCity_Gym_Text_Brock_BoulderBadge:
	.string "BROCK: {PLAYER}, gracias. Me ha\n"
	.string "gustado luchar contigo, aunque estoy\l"
	.string "un poco disgustado.\p"
	.string "Esa MEDALLA ROCA hará que tus\n"
	.string "POKéMON sean aún más poderosos.$"

PewterCity_Gym_Text_Brock_FightDone:
	.string "BROCK: El mundo es enorme. Hay muchos\n"
	.string "entrenadores tan fuertes como tú.\p"
	.string "Espera y verás. Yo también me voy a\n"
	.string "hacer más fuerte.$"

PewterCity_Gym_Text_CamperJerry_Seen:
	.string "Los ENTRENADORES de este GIMNASIO\n"
	.string "usan POKéMON de tipo ROCA.\p"
	.string "El tipo ROCA tiene mucha DEFENSA.\p"
	.string "Los combates podrían alargarse\n"
	.string "mucho. ¿Estás preparado?$"

PewterCity_Gym_Text_CamperJerry_Beaten:
	.string "Tengo que ganar estos combates…$"

PewterCity_Gym_Text_CamperJerry_AfterBattle:
	.string "¡Eh, tú! ¡JOVEN de Johto! Brock es un\n"
	.string "tipo muy duro.\p"
	.string "¡Te castigará si no le tomas en serio!$"

PewterCity_Gym_Text_Guide:
	.string "¡Eh! ¡Futuro CAMPEÓN! Lo estás\n"
	.string "haciendo genial.\p"
	.string "¿Estás luchando contra los LÍDERES\n"
	.string "de GIMNASIO de KANTO?\p"
	.string "Son gente fuerte y entregada, igual\n"
	.string "que los LÍDERES de GIMNASIO de JOHTO.$"

PewterCity_Gym_Text_Guide_Win:
	.string "¡Hola! Este GIMNASIO no te ha costado\n"
	.string "mucho.\p"
	.string "Tu forma de atacar ha sido realmente\n"
	.string "increíble. Lo digo en serio.$"

PewterCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_GymGuyAfter
	msgbox PewterCity_Gym_Text_Guide, MSGBOX_NPC
	end

PewterCity_Gym_EventScript_GymGuyAfter::
	msgbox PewterCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end


PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_GymStatue::
	.string "GIMNASIO POKéMON DE CIUDAD PLATEADA\n"
	.string "LÍDER: BROCK\p"
	.string "GANADORES:\n"
	.string "AZUL, ROJO$"

PewterCity_Gym_Text_GymStatuePlayerWon::
	.string "GIMNASIO POKéMON DE CIUDAD PLATEADA\n"
	.string "LÍDER: BROCK\p"
	.string "GANADORES:\n"
	.string "AZUL, ROJO, {PLAYER}$"

PewterCity_Gym_EventScript_Brock_Trade::
	goto_if_set FLAG_PEWTER_GYM_NPC_TRADE_COMPLETED, PewterCity_Gym_EventScript_BrockTradeCompleted
	ingame_trade INGAME_TRADE_BONSLY, PewterCity_Gym_Text_BrockWantToTrade, PewterCity_Gym_EventScript_BrockDeclineTrade, PewterCity_Gym_EventScript_BrockNotRequestedMon, PewterCity_Gym_Text_BrockTakeCare
	setflag FLAG_PEWTER_GYM_NPC_TRADE_COMPLETED
	release
	end

PewterCity_Gym_EventScript_BrockDeclineTrade::
	msgbox PewterCity_Gym_Text_BrockDeclineTrade, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_BrockNotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PewterCity_Gym_Text_BrockNotRequestedMon, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_BrockTradeCompleted::
	msgbox PewterCity_Gym_Text_BrockTradeCompleted, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_BrockWantToTrade:
	.string "BROCK: Eh, {PLAYER}. Encontré este\n"
	.string "pequeño BONSLY mientras entrenaba en\l"
	.string "las montañas.\p"
	.string "Es mono, pero creo que necesita otro\n"
	.string "tipo de ENTRENADOR.\p"
	.string "¿Me cambiarías un {STR_VAR_1} por mi\n"
	.string "{STR_VAR_2}?$"

PewterCity_Gym_Text_BrockTakeCare:
	.string "BROCK: ¡Gracias! ¡Cuida bien de WOODY\n"
	.string "por mí!$"

PewterCity_Gym_Text_BrockDeclineTrade:
	.string "BROCK: ¿No? No pasa nada. WOODY y yo\n"
	.string "seguiremos entrenando.$"

PewterCity_Gym_Text_BrockNotRequestedMon:
	.string "BROCK: Eso no es un {STR_VAR_1}. No es\n"
	.string "lo que busco.$"

PewterCity_Gym_Text_BrockTradeCompleted:
	.string "BROCK: ¿Qué tal está WOODY? ¡Los\n"
	.string "BONSLY son más duros de lo que\l"
	.string "parecen!$"
