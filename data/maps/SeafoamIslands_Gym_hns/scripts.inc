SeafoamIslands_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_Gym_OnTransition
	.byte 0

SeafoamIslands_Gym_OnTransition: 
	setflag FLAG_TEMP_1
	end

SeafoamIslands_Gym_EventScript_Blaine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CINNABAR_ISLAND_GYM, SeafoamIslands_Gym_EventScript_Blaine_Defeated
	msgbox SeafoamIslands_Gym_Text_BlaineIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLAINE_HNS, SeafoamIslands_Gym_Text_BlaineWinLoss
	message SeafoamIslands_Gym_Text_ReceivedVolcanoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SeafoamIslands_Gym_Text_Blaine_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_OVERHEAT
	msgbox SeafoamIslands_Gym_Text_Blaine_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE15_GET
	setflag FLAG_DEFEATED_CINNABAR_ISLAND_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 15
	clearflag FLAG_HIDE_SEAFOAM_GYMGUY
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	release
	end

SeafoamIslands_Gym_EventScript_Blaine_Defeated::
	msgbox SeafoamIslands_Gym_Text_BlaineAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SeafomIslands2_EventScript_GymGuide::
	goto_if_set FLAG_TEMP_2, SeafomIslands2_EventScript_GymGuide2
	msgbox SeafoamIslands_Gym_Text_GymGuideWin, MSGBOX_NPC
	setflag FLAG_TEMP_2
	end
SeafomIslands2_EventScript_GymGuide2::
	msgbox SeafoamIslands_Gym_Text_GymGuideWin2, MSGBOX_NPC
	end

SeafoamIslands_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE15_GET, SeafoamIslands_Gym_EventScript_GymStatuePostVictory
	msgbox SeafoamIslands_Gym_Text_GymStatue
	releaseall
	end

SeafoamIslands_Gym_EventScript_GymStatuePostVictory::
	msgbox SeafoamIslands_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SeafoamIslands_Gym_Text_GymStatue::
	.string "GIMNASIO POKéMON DE ISLA CANELA\n"
	.string "LÍDER: BLAINE\p"
	.string "GANADORES:\n"
	.string "AZUL, ROJO$"

SeafoamIslands_Gym_Text_GymStatuePlayerWon::
	.string "GIMNASIO POKéMON DE ISLA CANELA\n"
	.string "LÍDER: BLAINE\p"
	.string "GANADORES:\n"
	.string "AZUL, ROJO, {PLAYER}$"

SeafoamIslands_Gym_Text_Blaine_GiveTM:
	.string "¡Toma, llévate esto también!$"

SeafoamIslands_Gym_Text_Blaine_ExplainTM:
	.string "¡Esta MT contiene el impresionante\n"
	.string "SOFOCO!\p"
	.string "Un calor abrumador que abrasa a los\n"
	.string "rivales, pero que luego reduce tu\l"
	.string "poder.\p"
	.string "¡Espero que tu próximo rival tenga un\n"
	.string "ANTIQUEMAR de sobra! ¡Uaaah!$"

SeafoamIslands_Gym_Text_BlaineIntro:
	.string "BLAINE: ¡Buaaa!\p"
	.string "Mi GIMNASIO de ISLA CANELA se ha\n"
	.string "quemado.\p"
	.string "El volcán nos ha dejado sin casa a mis\n"
	.string "POKéMON comefuego y a mí.\p"
	.string "¡Buaaaa!\p"
	.string "Pero sigo haciendo mi trabajo de\p"
	.string "LÍDER de GIMNASIO en esta cueva.\p"
	.string "Si me vences, te daré una MEDALLA.\p"
	.string "¡Ja! Espero que tengas ANTIQUEMAR.$"

SeafoamIslands_Gym_Text_BlaineWinLoss:
	.string "BLAINE: Increíble. Me consumí…\p"
	.string "¡Has ganado la MEDALLA VOLCÁN!$"

SeafoamIslands_Gym_Text_ReceivedVolcanoBadge:
	.string "{PLAYER} recibió la MED. VOLCÁN.$"

SeafoamIslands_Gym_Text_BlaineAfterBattle:
	.string "BLAINE: Esta vez he perdido, pero la\n"
	.string "próxima te ganaré.\p"
	.string "Cuando reconstruya mi GIMNASIO de I.\n"
	.string "CANELA, tendremos la revancha.$"

SeafoamIslands_Gym_Text_BlaineFightDone:
	.string "BLAINE: Mis POKéMON de fuego serán\n"
	.string "más fuertes. ¡Ya lo verás!$"

SeafoamIslands_Gym_Text_BlaineRematch:
	.string "BLAINE: ¡Caramba!\p"
	.string "¡Veo que te has convertido en el\n"
	.string "CAMPEÓN de KANTO!\p"
	.string "¡Eso es abrasador!\p"
	.string "Tus habilidades son de primera.\p"
	.string "Yo siempre estoy dispuesto a luchar.\p"
	.string "¿Quieres la revancha?$"

SeafoamIslands_Gym_Text_BlaineRematchDefeat:
	.string "BLAINE: ¡Tus habilidades son\n"
	.string "realmente ardientes!\p"
	.string "¡Has atravesado mis defensas a fuego!$"

SeafoamIslands_Gym_Text_GymGuideWin:
	.string "¡Vaya!\p"
	.string "¿Eh…? ¿Ya ha acabado?\p"
	.string "¡Lo siento!\p"
	.string "El GIMNASIO de ISLA CANELA ya no\n"
	.string "existe y no sabía dónde encontrarte.\p"
	.string "Pero eres fuerte hasta sin mis\n"
	.string "consejos. ¡Sabía que ganarías!$"

SeafoamIslands_Gym_Text_GymGuideWin2:
	.string "Los GIMNASIOS POKéMON están allí\n"
	.string "donde se encuentre su LÍDER.\p"
	.string "No es necesario un edificio.$"
