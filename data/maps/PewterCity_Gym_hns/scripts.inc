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
	.string "Here, take this TM with you.$"

PewterCity_Gym_Text_Brock_ExplainTM:
	.string "It contains ROCK SLIDE.\p"
	.string "It drops rocks on your opponents\n"
	.string "with a chance to cause flinching.\p"
	.string "Use it to stop them in their tracks.$"

PewterCity_Gym_Text_Brock_BoulderBadge:
	.string "BROCK: {PLAYER}, thanks. I enjoyed\n"
	.string "battling you, even though I am a bit\l"
	.string "upset.\p"
	.string "That BOULDERBADGE will make your\n"
	.string "POKéMON even more powerful.$"

PewterCity_Gym_Text_Brock_FightDone:
	.string "BROCK: El mundo es enorme. Hay muchos\n"
	.string "entrenadores tan fuertes como tú.\p"
	.string "Espera y verás. Yo también me voy a\n"
	.string "hacer más fuerte.$"

PewterCity_Gym_Text_CamperJerry_Seen:
	.string "The trainers of this GYM use ROCK-type\n"
	.string "POKéMON.\p"
	.string "The ROCK-type has high DEFENSE.\p"
	.string "Battles could end up going a long time.\n"
	.string "Are you ready for this?$"

PewterCity_Gym_Text_CamperJerry_Beaten:
	.string "Tengo que ganar estos combates…$"

PewterCity_Gym_Text_CamperJerry_AfterBattle:
	.string "¡Eh, tú! ¡JOVEN de Johto! Brock es un\n"
	.string "tipo muy duro.\p"
	.string "¡Te castigará si no le tomas en serio!$"

PewterCity_Gym_Text_Guide:
	.string "Yo! CHAMP in making! You're really\n"
	.string "rocking.\p"
	.string "Are you battling the GYM LEADERS of\n"
	.string "KANTO?\p"
	.string "They're strong and dedicated people,\n"
	.string "just like JOHTO's GYM LEADERS.$"

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
    .string "PEWTER POKéMON GYM\n"
    .string "LEADER: BROCK\p"
	.string "WINNING TRAINERS:\n"
	.string "BLUE, RED$"

PewterCity_Gym_Text_GymStatuePlayerWon::
    .string "PEWTER POKéMON GYM\n"
    .string "LEADER: BROCK\p"
    .string "WINNING TRAINERS:\n"
	.string "BLUE, RED, {PLAYER}$"

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
	.string "BROCK: Hey, {PLAYER}. I found this\n"
	.string "little BONSLY while training in the\l"
	.string "mountains.\p"
	.string "It's cute, but I think it needs\n"
	.string "a different kind of trainer.\p"
	.string "Would you trade a {STR_VAR_1}\n"
	.string "for my {STR_VAR_2}?$"

PewterCity_Gym_Text_BrockTakeCare:
	.string "BROCK: Thanks! Take good care of\n"
	.string "WOODY for me!$"

PewterCity_Gym_Text_BrockDeclineTrade:
	.string "BROCK: No? That's okay.\n"
	.string "WOODY and I will keep training.$"

PewterCity_Gym_Text_BrockNotRequestedMon:
	.string "BROCK: That's not a {STR_VAR_1}.\n"
	.string "That's not what I'm after.$"

PewterCity_Gym_Text_BrockTradeCompleted:
	.string "BROCK: How's WOODY doing?\n"
	.string "BONSLY are tougher than they look!$"
