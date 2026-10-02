EcruteakCity_Gym_hns_MapScripts::
	.byte 0

EcruteakCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_GymGuy2
	msgbox EcruteakCity_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_Gym_EventScript_GymGuy2::
	msgbox EcruteakCity_GymGuideWinText, MSGBOX_DEFAULT
	release
	end	

EcruteakCity_Gym_EventScript_Jeffrey::
	trainerbattle_single TRAINER_JEFFREY_HNS, SageJeffreySeenText, SageJeffreyBeatenText
	msgbox SageJeffreyAfterBattleText, MSGBOX_AUTOCLOSE
	end
EcruteakCity_Gym_EventScript_Ping::
	trainerbattle_single TRAINER_PING_HNS, SagePingSeenText, SagePingBeatenText
	msgbox SagePingAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Martha::
	trainerbattle_single TRAINER_MARTHA_HNS, MediumMarthaSeenText, MediumMarthaBeatenText
	msgbox MediumMarthaAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE_HNS, MediumGraceSeenText, MediumGraceBeatenText
	msgbox MediumGraceAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Morty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Morty_Defeated
	msgbox MortyIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MORTY_1_HNS, MortyWinLossText
	message Text_ReceivedFogBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MortyText_FogBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_SHADOW_BALL
	msgbox MortyText_ShadowBallSpeech, MSGBOX_DEFAULT
	setvar VAR_ECRUTEAK_CITY_STATE, 4
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Morty_Defeated::
	msgbox MortyFightDoneText, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Statue2
	msgbox EcruteakCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue2::
	msgbox EcruteakCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_Text_GymStatue:
	.string "Gimnasio POKéMON de CIUDAD IRIS$"

EcruteakCity_Gym_Text_GymStatueCertified:
	.string "GIMNASIO POKéMON DE CIUDAD IRIS\p"
	.string "CERTIFICADOS POR MORTI:\n"
	.string "{PLAYER}$"

MortyIntroText:
	.string "Me alegra que hayas venido.\p"
	.string "Aquí, en CIUDAD IRIS, siempre se ha\n"
	.string "venerado a los POKéMON.\p"
	.string "Dicen que un POKéMON de color\n"
	.string "arcoíris bajará para aparecerse ante\l"
	.string "un verdadero ENTRENADOR.\p"
	.string "Yo creí en esa leyenda, así que he\n"
	.string "entrenado aquí en secreto.\p"
	.string "Gracias a ello, ahora puedo ver lo que\n"
	.string "otros no ven.\p"
	.string "Solo un poco más…\p"
	.string "Con un poco más, podría ver un futuro\n"
	.string "en el que conozco al POKéMON de color\l"
	.string "arcoíris.\p"
	.string "¡Tú vas a ayudarme a alcanzar ese\n"
	.string "nivel!$"

MortyWinLossText:
	.string "Aún no soy lo bastante bueno…\p"
	.string "De acuerdo. Esta MEDALLA es tuya.$"

Text_ReceivedFogBadge:
	.string "¡{PLAYER} ha recibido la MEDALLA\n"
	.string "NIEBLA!$"

MortyText_FogBadgeSpeech:
	.string "Con la MEDALLA NIEBLA, los POKéMON de\n"
	.string "hasta nivel 50 te obedecerán.\p"
	.string "Además, cualquier POKéMON que sepa\n"
	.string "SURF podrá usarlo en cualquier\l"
	.string "momento.\p"
	.string "Quiero que también te quedes con\n"
	.string "esto.$"

MortyText_ShadowBallSpeech:
	.string "Es BOLA SOMBRA. Causa daño y puede\n"
	.string "bajar la DEF. ESP.\p"
	.string "Úsala si te conviene.$"

MortyFightDoneText:
	.string "Ya veo…\p"
	.string "Tu viaje te ha llevado a lugares\n"
	.string "lejanos.\p"
	.string "Has visto mucho más que yo.\p"
	.string "Te envidio por ello…$"

MortyRematchText:
	.string "¡Ah, el CAMPEÓN de JOHTO! Me alegra\n"
	.string "que hayas venido.\p"
	.string "Has demostrado fuerza y habilidad,\n"
	.string "pero ¿has crecido desde nuestro\l"
	.string "último combate?\p"
	.string "Desde entonces he entrenado con mis\n"
	.string "POKéMON de tipo FANTASMA.\p"
	.string "Veamos si puedes volver a superar las\n"
	.string "sombras.\p"
	.string "¿Quieres la revancha?$"

Morty_RematchDefeatText:
	.string "Aún no soy lo bastante bueno…\p"
	.string "Has visto mucho más que yo.\p"
	.string "Te envidio por ello…$"

SageJeffreySeenText:
	.string "Pasé la primavera con mis POKéMON.\p"
	.string "Y luego el verano, el otoño y el\n"
	.string "invierno…\p"
	.string "Y la primavera volvió otra vez.\n"
	.string "Llevamos mucho tiempo juntos.$"

SageJeffreyBeatenText:
	.string "Victorias y derrotas… He conocido las\n"
	.string "dos.$"

SageJeffreyAfterBattleText:
	.string "¿De dónde vienen los POKéMON?$"

SagePingSeenText:
	.string "¿Puedes causar algún daño a nuestros\n"
	.string "POKéMON?$"

SagePingBeatenText:
	.string "¡Ah! ¡Bien hecho!$"

SagePingAfterBattleText:
	.string "Usamos POKéMON de tipo FANTASMA.\p"
	.string "¡Los ataques de tipo NORMAL no les\n"
	.string "hacen nada!$"

MediumMarthaSeenText:
	.string "¡Ganaré!$"

MediumMarthaBeatenText:
	.string "¡He… he perdido!$"

MediumMarthaAfterBattleText:
	.string "¡Gana quien más quiere ganar!$"

MediumGraceSeenText:
	.string "¿Te pierdes en nuestros pasillos\n"
	.string "oscuros? ¡Vénceme si quieres una\l"
	.string "pista!$"

MediumGraceBeatenText:
	.string "¿Có… cómo?$"

MediumGraceAfterBattleText:
	.string "Está bien. Te contaré el secreto de\n"
	.string "las sombras.\p"
	.string "¡El camino está justo delante de tus\n"
	.string "ojos!$"

EcruteakCity_GymGuideText:
	.string "¡Eh, CAMPEÓN! ¡Ya vas casi por la\n"
	.string "mitad!\p"
	.string "Los ENTRENADORES de aquí usan\n"
	.string "POKéMON de tipo FANTASMA y\l"
	.string "SINIESTRO.\p"
	.string "Aunque MORTI es experto en el tipo\n"
	.string "FANTASMA, ten cuidado con su ciervo\l"
	.string "místico.\p"
	.string "Dicen que provoca pesadillas\n"
	.string "extrañas…$"

EcruteakCity_GymGuideWinText:
	.string "¡Uauu, {PLAYER}! ¡Genial!\p"
	.string "¡Me escondí en el rincón muerto de\n"
	.string "miedo!$"

EcruteakCity_GymClosedText:
	.string "MORTI, el LÍDER de GIMNASIO, no está.\p"
	.string "Lo siento, pero tendrás que irte.\p"
	.string "Jo, jo, jo, jo.$"
