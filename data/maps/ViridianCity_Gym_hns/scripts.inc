ViridianCity_Gym_hns_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Blue::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_BLUE, ViridianCity_Gym_EventScript_BlueAtDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_BlueGotoDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_Blue_Defeated
	msgbox ViridianCity_Gym_Text_LeaderBlue_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLUE_HNS, ViridianCity_Gym_Text_LeaderBlue_Win
	message ViridianCity_Gym_Text_ReceivedEarthBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox ViridianCity_Gym_Text_LeaderBlue_After, MSGBOX_DEFAULT
	msgbox ViridianCity_Gym_Text_LeaderBlue_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_TRICK_ROOM
	msgbox ViridianCity_Gym_Text_LeaderBlue_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE16_GET
	setflag FLAG_DEFEATED_VIRIDIAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	setflag FLAG_HIDE_LEAGUE_BLACKBELT
	setflag FLAG_HIDE_SEAFOAM_BLAINE
	clearflag FLAG_HIDE_CINNABAR_BLAINE
	setvar VAR_OAK_MT_SILVER_CALL, 1
	release
	end

ViridianCity_Gym_EventScript_Blue_Defeated::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_EventScript_BlueGotoDojo::
	msgbox ViridianCity_Gym_Text_BlueGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_BLUE
	release
	end

ViridianCity_Gym_Text_BlueGotoDojo:
	.string "AZUL: ¿Ya vuelves a por más?\p"
	.string "Si quieres otra oportunidad contra mí,\n"
	.string "¡ven al DOJO KARATE!$"

ViridianCity_Gym_EventScript_BlueAtDojo::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_Text_LeaderBlue_Before:
	.string "AZUL: ¡Hola! Al fin llegaste, ¿eh?\p"
	.string "En ISLA CANELA no estaba a punto,\n"
	.string "pero ahora estoy listo para luchar.\p"
	.string "…\p"
	.string "¿Me estás contando que superaste los\p"
	.string "GIMNASIOS de JOHTO?\p"
	.string "¡Vaya! Pues los GIMNASIOS de JOHTO\p"
	.string "deben de ser patéticos.\p"
	.string "Pero bueno, no te preocupes.\p"
	.string "Sabremos si vales o no en un momento.\n"
	.string "Luchemos ahora.\p"
	.string "¿Vale?$"

ViridianCity_Gym_Text_LeaderBlue_Win:
	.string "AZUL: ¿Qué?\p"
	.string "¿Cómo demonios he perdido contra ti?\p"
	.string "…\p"
	.string "Bah, está bien… Toma, es la MEDALLA\n"
	.string "TIERRA.$"

ViridianCity_Gym_Text_ReceivedEarthBadge:
	.string "{PLAYER} recibió la MEDALLA TIERRA.$"

ViridianCity_Gym_Text_LeaderBlue_After:
	.string "AZUL: …\p"
	.string "De acuerdo, me he equivocado.\p"
	.string "Tenías razón. No me engañabas.\p"
	.string "Pero algún día te derrotaré.\p"
	.string "¡No lo olvides!$"

ViridianCity_Gym_Text_LeaderBlue_GiveTM:
	.string "Llévate esto.$"

ViridianCity_Gym_Text_LeaderBlue_ExplainTM:
	.string "Es ESPACIO RARO.\p"
	.string "Todos los POKéMON del combate\n"
	.string "cambiarán de velocidad. Los lentos\l"
	.string "atacan primero y los rápidos, los\l"
	.string "últimos.\p"
	.string "Úsalo para darle la vuelta a un\n"
	.string "combate.$"

ViridianCity_Gym_Text_LeaderBlue_Epilogue:
	.string "AZUL: Escucha.\p"
	.string "Será mejor que no pierdas hasta que\n"
	.string "yo te derrote. ¿Entendido?$"


ViridianCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_GymGuyAfter
	msgbox ViridianCity_Gym_Text_Guide, MSGBOX_NPC
	end

ViridianCity_Gym_EventScript_GymGuyAfter::
	msgbox ViridianCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end

ViridianCity_Gym_Text_Guide:
	.string "¡Hola! ¿Qué tal te va?\p"
	.string "Parece que estás de suerte.\p"
	.string "El LÍDER del GIMNASIO luchó contra el\n"
	.string "CAMPEÓN hace 3 años.\p"
	.string "¡Es un tipo duro!\p"
	.string "¡Debes esforzarte al máximo!$"

ViridianCity_Gym_Text_Guide_Win:
	.string "Vaya, eres realmente fuerte…\p"
	.string "¡Qué batalla más emocionante!\p"
	.string "Me ha hecho llorar.$"


ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE16_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GymStatue::
	.string "GIMNASIO POKéMON DE CIUDAD VERDE\n"
	.string "LÍDER: AZUL\p"
	.string "GANADORES:\n"
	.string "AZUL, ROJO$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
	.string "GIMNASIO POKéMON DE CIUDAD VERDE\n"
	.string "LÍDER: AZUL\p"
	.string "GANADORES:\n"
	.string "AZUL, ROJO, {PLAYER}$"

