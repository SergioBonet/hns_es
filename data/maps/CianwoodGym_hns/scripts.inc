CianwoodGym_hns_MapScripts::
	.byte 0


CianwoodGym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Statue2
	msgbox CianwoodGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_Statue2::
	msgbox CianwoodGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_GymStatue:
	.string "Gimnasio POKéMON de CIUDAD ORQUÍDEA$"

CianwoodGym_Text_GymStatueCertified:
	.string "GIMNASIO POKéMON DE CIUDAD ORQUÍDEA\p"
	.string "CERTIFICADOS POR ANÍBAL:\n"
	.string "{PLAYER}$"

CianwoodGym_EventScript_Chuck::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_CHUCK, CianwoodGym_EventScript_ChuckAtDojo
	goto_if_set FLAG_VISITED_VERMILION_CITY, CianwoodGym_EventScript_ChuckGotoDojo
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Chuck_Defeated
	msgbox CianwoodGym_Text_ChuckIntro1, MSGBOX_DEFAULT
	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckLeft
	waitmovement 0
	message CianwoodGym_Text_ChuckIntro2
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_LEFT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0

	delay 20

	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckRight
	waitmovement 0
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_RIGHT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0
	waitmessage
	turnobject LOCALID_CIANWOOD_CHUCK, DIR_SOUTH
	msgbox CianwoodGym_Text_ChuckIntro3, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_OlivineCheckMahog
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_MahogCheckOlivine
	goto CianwoodGym_EventScript_Chuck_Battle1

CianwoodGym_EventScript_ChuckVictory::
	message CianwoodGym_Text_GetStormBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CianwoodGym_Text_ChuckBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setflag FLAG_DEFEATED_CIANWOOD_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_FOCUS_PUNCH
	msgbox CianwoodGym_Text_ChuckTMSpeech, MSGBOX_DEFAULT
	setvar VAR_GETFLY, 1
	setrespawn HEAL_LOCATION_CIANWOOD_CITY_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

CianwoodGym_EventScript_ChuckGotoDojo::
	msgbox CianwoodGym_Text_ChuckGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_CHUCK
	release
	end

CianwoodGym_Text_ChuckGotoDojo:
	.string "¡JAJAJAJÁ, {PLAYER}! ¡Estoy en pleno\n"
	.string "entrenamiento!\p"
	.string "Si quieres otro combate, ¡ven al DOJO\n"
	.string "KARATE de CIUDAD AZAFRÁN!$"

CianwoodGym_EventScript_ChuckAtDojo::
	msgbox CianwoodGym_Text_ChuckAtDojo, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_ChuckAtDojo:
	.string "¡Nos vemos en el DOJO! ¡JAJAJAJAJÁ!$"

CianwoodGym_EventScript_OlivineCheckMahog::
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2

CianwoodGym_EventScript_MahogCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2
	
CianwoodGym_EventScript_Chuck_Battle1::
	trainerbattle_no_intro TRAINER_CHUCK_1_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle2::
	trainerbattle_no_intro TRAINER_CHUCK_1_2_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle3::
	trainerbattle_no_intro TRAINER_CHUCK_1_3_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Defeated::
	msgbox CianwoodGym_Text_ChuckAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Movement_ChuckLeft:
	jump_in_place_left
	step_end

CianwoodGym_Movement_ChuckRight:
	jump_in_place_right
	step_end

CianwoodGym_Text_ChuckIntro1:
	.string "¡UAUUUU!\p"
	.string "¡Has llegado hasta aquí!\p"
	.string "¡Que sepas que soy muy fuerte!\p"
	.string "¡Mis POKéMON aplastarán piedras y\n"
	.string "romperán huesos!\p"
	.string "¡Atención!$"

CianwoodGym_Text_ChuckIntro2:
	.string "ANÍBAL: ¡Urgg! ¡Urgg…!\p"
	.string "¡Oooarrg!$"

CianwoodGym_Text_ChuckIntro3:
	.string "¿Qué? Ahora tienes miedo, ¿no?\p"
	.string "¿Qué? ¿No tiene nada que ver con los\n"
	.string "POKéMON? ¡Es cierto!\p"
	.string "Venga. ¡Luchemos!$"

CianwoodGym_Text_ChuckLoss:
	.string "¿Qué? ¿Cómo? ¿He perdido?\p"
	.string "¡Muy bien! ¡Te mereces la MEDALLA\n"
	.string "TORMENTA!$"

CianwoodGym_Text_GetStormBadge:
	.string "{PLAYER} recibió la MEDALLA TORMENTA.$"

CianwoodGym_Text_ChuckBadgeSpeech:
	.string "Con MED. TORMENTA, te obedecerán los\p"
	.string "POKéMON hasta el nivel 70.\p"
	.string "Y permitirá a tus POKéMON usar VUELO\p"
	.string "cuando no estén luchando.\p"
	.string "¡Toma esto también!$"

CianwoodGym_Text_ChuckTMSpeech:
	.string "Es PUÑO CERTERO.\p"
	.string "Es lento, pero causa muchísimo daño.\n"
	.string "¡Solo procura que no te golpeen\l"
	.string "primero!$"

CianwoodGym_Text_ChuckAfter:
	.string "¡UAJAJAA! ¡Ha sido muy divertido!\p"
	.string "¡Pero una derrota es una derrota!\p"
	.string "¡Desde ahora, voy a entrenarme 24\n"
	.string "horas al día!$"

CianwoodGym_Text_ChuckRematch:
	.string "¡JAJAJÁ! ¡CAMPEÓN de JOHTO!\p"
	.string "¡Has vuelto a por más!\p"
	.string "¡Veo que has mejorado!\p"
	.string "¿Listo para ver quién es más fuerte?$"

CianwoodGym_Text_ChuckRematchDefeat:
	.string "¿Qué? ¿Eh? ¿He perdido? ¿Otra vez?$"

CianwoodGym_EventScript_Yoshi::
	trainerbattle_single TRAINER_YOSHI_HNS, CianwoodGym_Text_BlackbeltYoshiSeen, CianwoodGym_Text_BlackbeltYoshiBeaten
	msgbox CianwoodGym_Text_BlackbeltYoshiAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltYoshiSeen:
	.string "A mis POKéMON y a mí nos une una gran\n"
	.string "amistad.\p"
	.string "¡Nuestro vínculo nunca se romperá!$"

CianwoodGym_Text_BlackbeltYoshiBeaten:
	.string "¡No puede ser!$"

CianwoodGym_Text_BlackbeltYoshiAfter:
	.string "¡Parece que tú también tienes un\n"
	.string "vínculo muy fuerte con tus POKéMON!$"

CianwoodGym_EventScript_Lao::
	trainerbattle_single TRAINER_LAO_HNS, CianwoodGym_Text_BlackbeltLaoSeen, CianwoodGym_Text_BlackbeltLaoBeaten
	msgbox CianwoodGym_Text_BlackbeltLaoAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLaoSeen:
	.string "¡Los expertos en artes marciales no\n"
	.string "tememos a nada!$"

CianwoodGym_Text_BlackbeltLaoBeaten:
	.string "¡Es increíble!$"

CianwoodGym_Text_BlackbeltLaoAfter:
	.string "Los POKéMON de tipo LUCHA les tienen\n"
	.string "miedo a los psíquicos…$"


CianwoodGym_EventScript_Nob::
	trainerbattle_single TRAINER_NOB_HNS, CianwoodGym_Text_BlackbeltNobSeen, CianwoodGym_Text_BlackbeltNobBeaten
	msgbox CianwoodGym_Text_BlackbeltNobAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltNobSeen:
	.string "Las palabras no sirven. ¡Deja que\n"
	.string "hablen tus puños!$"

CianwoodGym_Text_BlackbeltNobBeaten:
	.string "…$"

CianwoodGym_Text_BlackbeltNobAfter:
	.string "¡He perdido! ¡No sé qué decir!$"

CianwoodGym_EventScript_Lung::
	trainerbattle_single TRAINER_LUNG_HNS, CianwoodGym_Text_BlackbeltLungSeen, CianwoodGym_Text_BlackbeltLungBeaten
	msgbox CianwoodGym_Text_BlackbeltLungAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLungSeen:
	.string "¡Mis furiosos puños destrozarán a tus\n"
	.string "POKéMON!$"

CianwoodGym_Text_BlackbeltLungBeaten:
	.string "¡Me has aplastado!$"

CianwoodGym_Text_BlackbeltLungAfter:
	.string "Mis POKéMON han perdido… Mi… mi\n"
	.string "orgullo está hecho añicos…$"

