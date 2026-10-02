BlackthornCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BlackthornGym_OnLoad
	.byte 0

BlackthornGym_OnLoad::
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 1, BlackthornGym_MapScript_Var1
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 2, BlackthornGym_MapScript_Var2
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 3, BlackthornGym_MapScript_Var3
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 4, BlackthornGym_MapScript_Var4
	end

BlackthornGym_MapScript_Var1::
	call BlackthornGym_MapScript_BuildBridge1
	end

BlackthornGym_MapScript_Var2::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	end

BlackthornGym_MapScript_Var3::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	end

BlackthornGym_MapScript_Var4::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	call BlackthornGym_MapScript_BuildBridge4
	end

BlackthornGym_TriggerBridge1::
	call BlackthornGym_MapScript_BuildBridge1
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 1
	end

BlackthornGym_MapScript_BuildBridge1::
	setmetatile 19, 47, 0x35A, FALSE
	setmetatile 19, 48, 0x35A, FALSE
	setmetatile 19, 49, 0x35A, FALSE
	setmetatile 19, 50, 0x35A, FALSE
	setmetatile 19, 51, 0x35A, FALSE
	setmetatile 19, 52, 0x35A, FALSE
	setmetatile 19, 53, 0x35A, FALSE
	setmetatile 19, 54, 0x35A, FALSE
	setmetatile 20, 47, 0x35A, FALSE
	setmetatile 20, 48, 0x35A, FALSE
	setmetatile 20, 49, 0x35A, FALSE
	setmetatile 20, 50, 0x35A, FALSE
	setmetatile 20, 51, 0x35A, FALSE
	setmetatile 20, 52, 0x35A, FALSE
	setmetatile 20, 53, 0x35A, FALSE
	setmetatile 20, 54, 0x35A, FALSE
	setmetatile 21, 47, 0x35A, FALSE
	setmetatile 21, 48, 0x35A, FALSE
	setmetatile 21, 49, 0x35A, FALSE
	setmetatile 21, 50, 0x35A, FALSE
	setmetatile 21, 51, 0x35A, FALSE
	setmetatile 21, 52, 0x35A, FALSE
	setmetatile 21, 53, 0x35A, FALSE
	setmetatile 21, 54, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge2::
	call BlackthornGym_MapScript_BuildBridge2
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 2
	end

BlackthornGym_MapScript_BuildBridge2::
	setmetatile 17, 35, 0x35A, FALSE
	setmetatile 17, 36, 0x35A, FALSE
	setmetatile 17, 37, 0x35A, FALSE
	setmetatile 17, 38, 0x35A, FALSE
	setmetatile 17, 39, 0x35A, FALSE
	setmetatile 17, 40, 0x35A, FALSE
	setmetatile 18, 35, 0x35A, FALSE
	setmetatile 18, 36, 0x35A, FALSE
	setmetatile 18, 37, 0x35A, FALSE
	setmetatile 18, 38, 0x35A, FALSE
	setmetatile 18, 39, 0x35A, FALSE
	setmetatile 18, 40, 0x35A, FALSE
	setmetatile 19, 35, 0x35A, FALSE
	setmetatile 19, 36, 0x35A, FALSE
	setmetatile 19, 37, 0x35A, FALSE
	setmetatile 19, 38, 0x35A, FALSE
	setmetatile 19, 39, 0x35A, FALSE
	setmetatile 19, 40, 0x35A, FALSE
	setmetatile 20, 32, 0x359, FALSE
	setmetatile 21, 32, 0x359, FALSE
	setmetatile 22, 32, 0x359, FALSE
	setmetatile 20, 35, 0x361, TRUE
	setmetatile 21, 35, 0x361, TRUE
	setmetatile 22, 35, 0x361, TRUE
	setmetatile 20, 33, 0x35A, FALSE
	setmetatile 20, 34, 0x35A, FALSE
	setmetatile 21, 33, 0x35A, FALSE
	setmetatile 21, 34, 0x35A, FALSE
	setmetatile 22, 33, 0x35A, FALSE
	setmetatile 22, 34, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge3::
	call BlackthornGym_MapScript_BuildBridge3
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 3
	end

BlackthornGym_MapScript_BuildBridge3::
	setmetatile 17, 26, 0x359, FALSE
	setmetatile 18, 26, 0x359, FALSE
	setmetatile 19, 26, 0x359, FALSE
	setmetatile 20, 26, 0x359, FALSE
	setmetatile 21, 26, 0x359, FALSE
	setmetatile 22, 26, 0x359, FALSE
	setmetatile 23, 26, 0x359, FALSE

	setmetatile 17, 29, 0x361, TRUE
	setmetatile 18, 29, 0x361, TRUE
	setmetatile 19, 29, 0x361, TRUE
	setmetatile 20, 29, 0x361, TRUE
	setmetatile 21, 29, 0x361, TRUE
	setmetatile 22, 29, 0x361, TRUE
	setmetatile 23, 29, 0x361, TRUE

	setmetatile 17, 27, 0x35A, FALSE
	setmetatile 17, 28, 0x35A, FALSE
	setmetatile 18, 27, 0x35A, FALSE
	setmetatile 18, 28, 0x35A, FALSE
	setmetatile 19, 27, 0x35A, FALSE
	setmetatile 19, 28, 0x35A, FALSE
	setmetatile 20, 27, 0x35A, FALSE
	setmetatile 20, 28, 0x35A, FALSE
	setmetatile 21, 27, 0x35A, FALSE
	setmetatile 21, 28, 0x35A, FALSE
	setmetatile 22, 27, 0x35A, FALSE
	setmetatile 22, 28, 0x35A, FALSE
	setmetatile 23, 27, 0x35A, FALSE
	setmetatile 23, 28, 0x35A, FALSE
	return	

BlackthornGym_TriggerBridge4::
	call BlackthornGym_MapScript_BuildBridge4
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 4
	end

BlackthornGym_MapScript_BuildBridge4::
	setmetatile 19, 11, 0x35A, FALSE
	setmetatile 19, 12, 0x35A, FALSE
	setmetatile 19, 13, 0x35A, FALSE
	setmetatile 19, 14, 0x35A, FALSE
	setmetatile 19, 15, 0x35A, FALSE
	setmetatile 20, 11, 0x35A, FALSE
	setmetatile 20, 12, 0x35A, FALSE
	setmetatile 20, 13, 0x35A, FALSE
	setmetatile 20, 14, 0x35A, FALSE
	setmetatile 20, 15, 0x35A, FALSE
	setmetatile 21, 11, 0x35A, FALSE
	setmetatile 21, 12, 0x35A, FALSE
	setmetatile 21, 13, 0x35A, FALSE
	setmetatile 21, 14, 0x35A, FALSE
	setmetatile 21, 15, 0x35A, FALSE
	return


BlackthornGym_EventScript_Cody::
	trainerbattle_single TRAINER_CODY_HNS, BlackthornGym_Text_CooltrainermCodySeenText, BlackthornGym_Text_CooltrainermCodyBeatenText
	msgbox BlackthornGym_Text_CooltrainermCodyAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Fran::
	trainerbattle_single TRAINER_FRAN_HNS, BlackthornGym_Text_CooltrainerfFranSeenText, BlackthornGym_Text_CooltrainerfFranBeatenText
	msgbox BlackthornGym_Text_CooltrainerfFranAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Paul::
	trainerbattle_single TRAINER_PAUL_HNS, BlackthornGym_Text_CooltrainermPaulSeenText, BlackthornGym_Text_CooltrainermPaulBeatenText
	msgbox BlackthornGym_Text_CooltrainermPaulAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE_HNS, BlackthornGym_Text_CooltrainermMikeSeenText, BlackthornGym_Text_CooltrainermMikeBeatenText
	msgbox BlackthornGym_Text_CooltrainermMikeAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Lola::
	trainerbattle_single TRAINER_LOLA_HNS, BlackthornGym_Text_CooltrainerfLolaSeenText, BlackthornGym_Text_CooltrainerfLolaBeatenText
	msgbox BlackthornGym_Text_CooltrainerfLolaAfterBattleText, MSGBOX_AUTOCLOSE
	end


BlackthornGym_EventScript_Clair::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, BlackthornGym_EventScript_ClairAfterLeague
	goto_if_ge VAR_BLACKTHORN_CITY_STATE, 4, BlackthornGym_EventScript_Clair_Defeated
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 2, BlackthornGym_EventScript_ClairDuringChallenge
	msgbox BlackthornGym_Text_ClairIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CLAIR_1_HNS, BlackthornGym_Text_ClairWinText
	msgbox BlackthornGym_Text_ClairText_GoToDragonsDen, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_BLACKTHORN_GYM
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers_hns
	setvar VAR_BLACKTHORN_CITY_STATE, 2
	closemessage
	release
	end

BlackthornGym_EventScript_ClairDuringChallenge::
	msgbox BlackthornGym_Text_ClairText_TooMuchToExpect, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Clair_Defeated::
	msgbox BlackthornGym_Text_ClairText_League, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_ClairAfterLeague::
	msgbox BlackthornGym_Text_ClairAfterLeague, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_ClairIntroText:
	.string "Soy DÉBORA.\p"
	.string "Soy la mejor maestra dragón del mundo.\p"
	.string "Puedo enfrentarme incluso al ALTO\p"
	.string "MANDO de la LIGA POKéMON.\p"
	.string "¿Todavía quieres enfrentarte a mí?\p"
	.string "Bien… ¡Adelante!\p"
	.string "¡Como LÍDER de GIMNASIO, usaré toda\n"
	.string "mi fuerza contra mi oponente!$"

BlackthornGym_Text_ClairWinText:
	.string "¿He perdido?\p"
	.string "No puedo creerlo. Ha debido de haber\n"
	.string "algún error…$"

BlackthornGym_Text_ClairText_GoToDragonsDen:
    .string "I won't admit this.\p"
    .string "I may have lost, but you're still\n"
    .string "not ready for the POKéMON LEAGUE.\p"
    .string "I know. You should take the dragon-\n"
    .string "user challenge.\p"
    .string "Behind this GYM is a place called\n"
    .string "DRAGON'S DEN.\p"
    .string "There is a small shrine at its\n"
    .string "center. Go there.\p"
    .string "If you can prove that you've lost\n"
    .string "your lazy ideals, I will recognize\l"
    .string "you as a trainer worthy of a GYM\l"
    .string "BADGE!$"

BlackthornGym_Text_ClairText_TooMuchToExpect:
    .string "What's the matter?\p"
    .string "Is it too much to expect of you?$"

BlackthornGym_Text_ClairText_YouKeptMeWaiting:
	.string "¡Me has hecho esperar!\p"
	.string "¡Ven! ¡Coge esto!$"

BlackthornGym_Text_ClairText_DescribeTM:
    .string "That contains DRAGON CLAW.\p"
    .string "You can figure out what it does.$"

BlackthornGym_Text_ClairText_League:
    .string "What's the matter?\p"
    .string "Aren't you headed to the POKéMON\n"
    .string "LEAGUE?\p"
    .string "Don't you know where it is?\p"
    .string "From here, go to NEW BARK TOWN.\p"
    .string "Then SURF east. The route there is\n"
    .string "very tough.\p"
    .string "Don't you dare lose at the POKéMON\n"
    .string "LEAGUE!\p"
    .string "If you do, I'll feel even worse\n"
    .string "about having lost to you!\p"
    .string "Give it everything you've got.$"

BlackthornGym_Text_ClairAfterLeague:
    .string "You did it, huh?\p"
    .string "You are now the JOHTO CHAMP.$"

BlackthornGym_Text_ClairRematchText:
    .string "You did it, huh?\p"
    .string "You are now the JOHTO CHAMP.\p"
    .string "You've proven your strength but can\n"
    .string "you handle me again?\p"
    .string "As a Dragon Master, I won't hold\n"
    .string "back.\p"
    .string "Not this time.\p"
    .string "Want to have a rematch with me?$"

BlackthornGym_Text_ClairRematchDefeatText:
    .string "I lost?\p"
    .string "Again?\p"
    .string "I don't believe it. There must be\n"
    .string "some mistake…$"

BlackthornGym_Text_CooltrainermCodySeenText:
    .string "I just got access to use DRAGON-\n"
    .string "type POKéMON!$"

BlackthornGym_Text_CooltrainermCodyBeatenText:
    .string "Rats! If only I had a DRAGONITE!$"

BlackthornGym_Text_CooltrainermCodyAfterBattleText:
	.string "Los miembros del clan de los dragones\n"
	.string "sólo pueden usar POKéMON del tipo\l"
	.string "dragón si el MAESTRO se lo permite.$"

BlackthornGym_Text_CooltrainerfFranSeenText:
	.string "¡No puedo permitir que alguien como tú\n"
	.string "pase de aquí!\p"
	.string "¡DÉBORA se enfadará si te dejo!$"

BlackthornGym_Text_CooltrainerfFranBeatenText:
	.string "Auuuu… Perdí…$"

BlackthornGym_Text_CooltrainerfFranAfterBattleText:
	.string "Oh, oh… DÉBORA se va a enfadar…$"

BlackthornGym_Text_CooltrainermPaulSeenText:
	.string "¿Tu primer combate contra dragones?\p"
	.string "¡Te mostraré lo fuertes que son!$"

BlackthornGym_Text_CooltrainermPaulBeatenText:
	.string "¿Han perdido mis POKéMON dragón?$"

BlackthornGym_Text_CooltrainermPaulAfterBattleText:
	.string "¿LANCE te dijo que quería verte de\n"
	.string "nuevo? ¡Ni por asomo!$"

BlackthornGym_Text_CooltrainermMikeSeenText:
	.string "¿Mis posibilidades de perder? ¡Ni el\n"
	.string "uno por ciento!$"

BlackthornGym_Text_CooltrainermMikeBeatenText:
    .string "That's odd.$"

BlackthornGym_Text_CooltrainermMikeAfterBattleText:
    .string "I know my short-comings now.\p"
    .string "Thanks for showing me!$"

BlackthornGym_Text_CooltrainerfLolaSeenText:
	.string "Los dragones son POKéMON sagrados.\p"
	.string "Están llenos de energía vital.\p"
	.string "Si no mantienes la seriedad, no podrás\n"
	.string "acabar con ellos.$"

BlackthornGym_Text_CooltrainerfLolaBeatenText:
	.string "¡Adelante!$"

BlackthornGym_Text_CooltrainerfLolaAfterBattleText:
	.string "Los dragones son débiles contra los\n"
	.string "movimientos del tipo dragón.$"

BlackthornGym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, BlackthornGym_EventScript_GymGuy2
	msgbox BlackthornGym_Text_GuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
BlackthornGym_EventScript_GymGuy2::
	goto_if_set FLAG_BADGE08_GET, BlackthornGym_EventScript_GymGuy3
	msgbox BlackthornGym_Text_GuideGotoDragonsDen, MSGBOX_DEFAULT
	release
	end

BlackthornGym_EventScript_GymGuy3::
	msgbox BlackthornGym_Text_GuideWinText, MSGBOX_DEFAULT
	release
	end	

BlackthornGym_Text_GuideText:
    .string "Yo! CHAMP in making!\p"
    .string "It's been a long journey, but we\n"
    .string "are almost done! Count on me!\p"
    .string "While CLAIR looks up to the Dragon\n"
    .string "Master, LANCE, she's managed to\l"
    .string "create her own identity with a\l"
    .string "team consisting of dragons from\l"
    .string "the sea.\p"
    .string "Dragons are supposed to be\n"
    .string "weak against ICE-type moves,\l"
    .string "but you'll need some DRAGON-type\l"
	.string "or FAIRY-type moves of your own if\l"
    .string "you want to win.$"
    .string "You got this!$"

BlackthornGym_Text_GuideGotoDragonsDen:
	.string "You were great to beat CLAIR!\p"
    .string "She can be a bit of a sore loser,\n"
	.string "though\p"
    .string "Sounds like you need to head to the\n"
    .string "DRAGON'S DEN if you want that GYM BADGE!$"

BlackthornGym_Text_GuideWinText:
	.string "¡Genial! ¡Has vencido a DÉBORA!\p"
	.string "Sólo te queda el desafío de la LIGA\n"
	.string "POKéMON.\p"
	.string "¡Vas a ganar la LIGA POKéMON!$"


BlackthornGym_EventScript_Statue::
	lock
	goto_if_set FLAG_BADGE08_GET, BlackthornGym_EventScript_Statue2
	msgbox BlackthornGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Statue2::
	msgbox BlackthornGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_GymStatue:
	.string "Gimnasio POKéMON de CIUDAD ENDRINO$"

BlackthornGym_Text_GymStatueCertified:
	.string "BLACKTHORN CITY POKéMON GYM\p"
	.string "CLAIR'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
