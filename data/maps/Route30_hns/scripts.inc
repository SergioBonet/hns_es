Route30_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route30_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route30_OnFrame
	.byte 0

Route30_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route30_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 2, Route30_EventScript_ElmCall_Trigger
	.2byte 0
	
Route30_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route30_EventScript_Boy2
	msgbox Route30_Text_YoungsterDirectionsToMrPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Boy2::
	lock
	faceplayer
	msgbox Route30_Text_YoungsterEveryoneIsBattling, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Girl::
	lock
	faceplayer
	msgbox Route30_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Youngster_Joey_Fighting::
	lock
	msgbox Route30_Text_UseTackle, 	MSGBOX_AUTOCLOSE
	waitmessage
	playse SE_PIN
	applymovement LOCALID_ROUTE_30_JOEY, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ROUTE_30_JOEY
	faceplayer
	msgbox Route30_Text_ThisIsABigBattle, MSGBOX_AUTOCLOSE
	waitmessage
	turnobject LOCALID_ROUTE_30_JOEY DIR_NORTH
	release
	end


Route30_EventScript_Youngster_Joey::
	trainerbattle_single TRAINER_JOEY_HNS, Route30_Text_YoungsterJoey1Seen, Route30_Text_YoungsterJoey1Beaten, Route30_EventScript_RegisterJoey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route30_EventScript_RematchJoey
	msgbox Route30_Text_YoungsterJoey1After, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_RegisterJoey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route30_Text_JoeyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOEY_HNS
	release
	end

Route30_EventScript_RematchJoey::
	trainerbattle_rematch TRAINER_JOEY_HNS, Route30_Text_JoeyRematchIntro, Route30_Text_JoeyRematchDefeat
	msgbox Route30_Text_JoeyPostRematch, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Youngster_Mikey::
	trainerbattle_single TRAINER_MIKEY_HNS, Route30_Text_YoungsterMikeySeen, Route30_Text_YoungsterMikeyBeaten
	msgbox Route30_Text_YoungsterMikeyAfter, MSGBOX_AUTOCLOSE
	end
	
Route30_EventScript_Bugcatcher_Don::
	trainerbattle_single TRAINER_DON_HNS, Route30_Text_BugCatcherDonSeen, Route30_Text_BugCatcherDonBeaten
	msgbox Route30_Text_BugCatcherDonAfter, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_ElmCall_Trigger::
	lock
	setspeaker Route30_Text_ElmName
	pokenavcall Route30_Text_Elm_Disaster
	waitmessage
	delay 30
	setvar VAR_CHERRYGROVE_CITY_STATE, 3
	release
	end

Route30_EventScript_Sign::
	lock
	msgbox Route30_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route30_EventScript_TrainerTips::
	lock
	msgbox Route30_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end	

Route30_EventScript_Poliwag::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWAG, CRY_MODE_NORMAL
	msgbox Route30_Text_Poliwag, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route30_EventScript_Mailbox::
	msgbox Route30_Text_Mailbox, MSGBOX_SIGN
	end

Route30_Text_Mailbox:
	.string "MR.POKéMON's House$"

Route30_Text_UseTackle:
	.string "¡Ve, RATTATA!\p"
	.string "¡PLACAJE!$"

Route30_Text_ThisIsABigBattle:
	.string "¿Qué? ¡Es un gran combate! ¡Déjame en\n"
	.string "paz!$"

Route30_Text_YoungsterJoey1Seen:
	.string "Perdí, así que estoy buscando más\n"
	.string "POKéMON.\p"
	.string "¡Espera! ¡Pareces débil! ¡Venga,\n"
	.string "luchemos!$"

Route30_Text_YoungsterJoey1Beaten:
	.string "¡Argh! ¡He perdido de nuevo!$"

Route30_Text_YoungsterJoey1After:
	.string "¿Debo tener más POKéMON para poder\n"
	.string "luchar mejor?\p"
	.string "¡No! ¡Continuaré sólo con éste, pase lo\n"
	.string "que pase!$"

Route30_Text_YoungsterMikeySeen:
	.string "Entrenas POKéMON, ¿verdad?\p"
	.string "¡Pues entonces luchemos!$"

Route30_Text_YoungsterMikeyBeaten:
	.string "¡Qué extraño! ¡Creí que ganaría!$"

Route30_Text_YoungsterMikeyAfter:
	.string "Becoming a good trainer is\n"
	.string "really tough.\p"
	.string "I'm going to battle other\n"
	.string "people to get better.$"

Route30_Text_BugCatcherDonSeen:
	.string "¡En lugar de un POKéMON bicho, he\n"
	.string "encontrado a alguien que los entrena!$"

Route30_Text_BugCatcherDonBeaten:
	.string "¡Arg! ¡Eres muy fuerte!$"

Route30_Text_BugCatcherDonAfter:
	.string "Me quedé sin POKé BALL mientras\n"
	.string "atrapaba POKéMON.\p"
	.string "Debería haber comprado más…$"

Route30_Text_YoungsterDirectionsToMrPokemon:
	.string "MR. POKéMON's house?\n"
	.string "It's a bit farther ahead.$"

Route30_Text_YoungsterEveryoneIsBattling:
	.string "¡Todo el mundo se divierte luchando!\p"
	.string "¡Tú también deberías hacerlo!$"

Route30_Text_CooltrainerF:
	.string "No soy una Entrenadora.\p"
	.string "Pero si miras a uno a los ojos,\n"
	.string "prepárate para luchar.$"

Route30_Text_Sign:
	.string "RUTA 30\p"
	.string "CIUDAD MALVA - CIUDAD CEREZO$"

Route30_Text_MrPokemonsHouseDirectionsSign:
	.string "Casa del Sr. POKéMON ¡Todo recto!$"

Route30_Text_MrPokemonsHouseSign:
	.string "Casa del Sr. POKéMON$"

Route30_Text_TrainerTips:
	.string "Pistas para Entrenadores:\p"
	.string "¡No robes POKéMON de otros!\p"
	.string "¡Las Poké Balls solo se lanzan a\n"
	.string "POKéMON salvajes!$"

Route30_Text_JoeyRegister:
	.string "You're pretty good!\p"
	.string "My RATTATA's raring to go,\n"
	.string "just like always.\p"
	.string "It's the only one I have.\n"
	.string "I'm going to become a great\l"
	.string "TRAINER with it!\p"
	.string "Let's battle again sometime!$"

Route30_Text_JoeyRematchIntro:
	.string "I promised things would be\n"
	.string "different! Let's battle!$"

Route30_Text_JoeyRematchDefeat:
	.string "¡Argh! ¡He perdido de nuevo!$"

Route30_Text_JoeyPostRematch:
	.string "I'm checking out my\n"
	.string "RATTATA's moves and devising\l"
	.string "some strategies.\p"
	.string "When I come up with a good\n"
	.string "one, let's battle!$"

Route30_Text_YoungsterJoeyGiveHPUp:
	.string "Perdí otra vez… ¡Eres fuerte!\p"
	.string "Oh. Casi olvido que tenía que darte\n"
	.string "esto.\p"
	.string "Úsalo para hacerte aún más fuerte,\n"
	.string "¿vale?\p"
	.string "Yo también seré más fuerte.$"

Route30_Text_ElmName:
	.string "PROF.ELM$"

Route30_Text_Elm_Disaster:
	.string "PROF.ELM: H-hello? {PLAYER}? It's\n"
	.string "a disaster!\p"
	.string "Uh, um, it's just terrible!\p"
	.string "What should I do? It…\n"
	.string "Oh, no…\p"
	.string "Please get back here now!$"


Route30_Text_Poliwag:
	.string "POLIWAG: Wag waag!$"
