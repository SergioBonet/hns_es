SlowpokeWell_B1F_hns_MapScripts::
	.byte 0

SlowpokeWell_B1F_EventScript_Item_Super_Potion_1::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Super_Potion_2::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Great_Ball::
	finditem ITEM_GREAT_BALL
	end

SlowpokeWell_B1F_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

SlowpokeWell_B1F_EventScript_Kurt::
	lock
	msgbox SlowpokeWell_B1F_Text_KurtIntro, MSGBOX_DEFAULT
	closemessage
	end

SlowpokeWell_B1F_EventScript_Grunt21::
	trainerbattle_single TRAINER_GRUNT_21_HNS, SlowpokeWell_B1F_Text_GruntM29Seen, SlowpokeWell_B1F_Text_GruntM29Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM29After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Grunt22F::
	trainerbattle_single TRAINER_GRUNT_22_HNS, SlowpokeWell_B1F_Text_GruntF1Seen, SlowpokeWell_B1F_Text_GruntF1Beaten
	msgbox SlowpokeWell_B1F_Text_GruntF1After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO_HNS, SlowpokeWell_B1F_Text_GruntM2Seen, SlowpokeWell_B1F_Text_GruntM2Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM2After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Proton::
	lock
	faceplayer
	msgbox SlowpokeWell_B1F_Text_ProtonSeen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_PROTON_1_HNS, SlowpokeWell_B1F_Text_ProtonBeaten
	msgbox SlowpokeWell_B1F_Text_ProtonAfter, MSGBOX_AUTOCLOSE
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_KURT_1
	addobject LOCALID_WELL_KURT
	removeobject 11
	removeobject 12
	removeobject 13
	delay 120
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_WELL_KURT, SlowpokeWell_B1F_Movement_Kurt
	waitmovement 0
	msgbox SlowpokeWell_B1F_Text_KurtAfter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SLOWPOKE_WELL_KURT
	setflag FLAG_HIDE_KURT_1
	clearflag FLAG_HIDE_KURT_2
	clearflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setvar VAR_AZALEA_TOWN_STATE, 3
	warp MAP_AZALEA_TOWN_KURTS_HOUSE_HNS, 15, 4
	waitstate
	end

SlowpokeWell_B1F_Movement_Kurt:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

SlowpokeWell_B1F_Text_KurtIntro:
	.string "CÉSAR: ¡Hola, {PLAYER}!\p"
	.string "Los guardias de arriba huyeron en\n"
	.string "cuanto les grité.\p"
	.string "Pero entonces me caí por el POZO.\p"
	.string "Me golpeé en la espalda y ahora no\n"
	.string "puedo moverme.\p"
	.string "Si estuviera bien, mis POKéMON\p"
	.string "los habrían machacado…\p"
	.string "¡Bah! Pero no puedo hacer nada.\p"
	.string "¡{PLAYER}, demuéstrales lo que vales!$"

SlowpokeWell_B1F_Text_KurtAfter:
	.string "KURT: Way to go, {PLAYER}!\p"
	.string "TEAM ROCKET has taken off.\p"
	.string "My back's better too.\n"
	.string "Let's get out of here.$"

SlowpokeWell_B1F_Text_GruntM29Seen:
	.string "¡Maldición! Estaba de guardia arriba\n"
	.string "cuando un viejo memo me gritó.\p"
	.string "Me asusté tanto que me caí aquí\n"
	.string "abajo.\p"
	.string "¡Creo que voy a desahogar mi ira\n"
	.string "luchando contra ti!$"

SlowpokeWell_B1F_Text_GruntM29Beaten:
	.string "¡Arrg! ¡Hoy no es mi día!$"

SlowpokeWell_B1F_Text_GruntM29After:
	.string "Sí, hemos estado cortando las colas\n"
	.string "de los SLOWPOKE y vendiéndolas.\p"
	.string "Lo hacemos sólo por dinero.\p"
	.string "¡Así es! Somos el TEAM ROCKET, ¡y\n"
	.string "haríamos lo que fuera por dinero!$"

SlowpokeWell_B1F_Text_ProtonSeen:
	.string "¿Qué quieres?\p"
	.string "¡Si nos molestas, no esperes\n"
	.string "misericordia!$"

SlowpokeWell_B1F_Text_ProtonBeaten:
	.string "Lo hiciste bien hoy, pero… ¡espera a la\n"
	.string "próxima vez!$"

SlowpokeWell_B1F_Text_ProtonAfter:
	.string "Yeah, TEAM ROCKET was broken up\n"
	.string "three years ago.\p"
	.string "The boss went into hiding.\p"
	.string "But we continued our activities\n"
	.string "underground!\p"
	.string "A small obstacle like you won't be\n"
	.string "much of a problem for our mission.\p"
	.string "I advise you to be very afraid of\n"
	.string "what is to come!$"

SlowpokeWell_B1F_Text_GruntM2Seen:
	.string "Hyuck-hyuck-hyuck!\n"
	.string "Quit taking SLOWPOKETAILS?\p"
	.string "You're nuts!\n"
	.string "If we obeyed you, TEAM ROCKET's\l"
	.string "rep would be ruined!$"

SlowpokeWell_B1F_Text_GruntM2Beaten:
	.string "Hyuck…\n"
	.string "Too strong…$"

SlowpokeWell_B1F_Text_GruntM2After:
	.string "We need the money,\n"
	.string "but selling SLOWPOKETAILS?\p"
	.string "It's tough being a ROCKET GRUNT!$"

SlowpokeWell_B1F_Text_GruntF1Seen:
	.string "¿No más COLAS?\p"
	.string "¡Claro! ¡Intenta vencernos a todos!$"

SlowpokeWell_B1F_Text_GruntF1Beaten:
	.string "¡Maldición!$"

SlowpokeWell_B1F_Text_GruntF1After:
	.string "SLOWPOKETAILS grow back fast!\p"
	.string "What's wrong with selling them?$"

SlowpokeWell_B1F_Text_SlowpokeWithMail:
	.string "Un SLOWPOKE sin COLA…\p"
	.string "¿Qué? Tiene una CARTA. ¿La lees?$"

SlowpokeWell_B1F_Text_SlowpokeMail:
	.string "{PLAYER} lee la CARTA.\p"
	.string "Sé buena y cuida de la casa donde\n"
	.string "están el abuelo y SLOWPOKE.\p"
	.string "Te quiere, papá.$"

SlowpokeWell_B1F_Text_TaillessSlowpoke:
	.string "Un SLOWPOKE sin COLA…$"
