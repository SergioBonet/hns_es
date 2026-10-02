FuchsiaCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	.byte 0

FuchsiaCity_EventScript_CityEnter::
	setflag FLAG_VISITED_FUCHSIA_CITY
	end

FuchsiaCity_EventScript_BaobaCall::
	lock
	setspeaker FuchsiaCity_Text_BaobaName
	pokenavcall FuchsiaCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_BAOBA_QUEST_STATE, 1
	setvar VAR_FUCHSIA_CITY_STATE, 1
	release
	end

FuchsiaCity_Text_BaobaName:
	.string "BAOBA$"

FuchsiaCity_Text_Baoba:
	.string "WARDEN BAOBA: {PLAYER}!\p"
	.string "This is WARDEN BAOBA.\p"
	.string "Something awful has happened!\n"
	.string "My old SAFARI ZONE in FUCHSIA CITY\l"
	.string "was bought out and reopened!\p"
	.string "And apparently it has exotic new\n"
	.string "POKéMON!\p"
	.string "It's hurting my business!\p"
	.string "{PLAYER}, you must venture into the\n"
	.string "new SAFARI ZONE and catch a POKéMON\l"
	.string "to show me. I must know about these\l"
	.string "'exotic' POKéMON.\p"
	.string "Please {PLAYER}, my business depends\n"
	.string "on you!$"

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	msgbox FuchsiaCity_Text_PokefanM, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Teacher::
	msgbox FuchsiaCity_Text_Teacher, MSGBOX_NPC
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	end

FuchsiaCity_Text_Youngster:
	.string "Un miembro del ALTO MANDO era el\p"
	.string "LÍDER del GIMNASIO de CIUDAD FUCSIA.$"

FuchsiaCity_Text_PokefanM:
	.string "La hija de KOGA le ha sucedido como\p"
	.string "LÍDER del GIMNASIO cuando él se unió\n"
	.string "al ALTO MANDO.$"

FuchsiaCity_Text_Teacher:
	.string "The SAFARI ZONE is under new\n"
	.string "management.\p"
	.string "And it has tons of new POKéMON!$"

FuchsiaCity_Text_Sign:
	.string "CIUDAD FUCSIA\p"
	.string "¡Mirad la CIUDAD FUCSIA! ¡La pasión\n"
	.string "rosa!$"

FuchsiaCity_Text_GymSign:
	.string "LÍDER DEL GIMNASIO POKéMON DE\n"
	.string "CIUDAD FUCSIA: SACHIKO\p"
	.string "La venenosa maestra ninja$"

FuchsiaCity_Text_SafariZoneOfficeSign:
	.string "Aquí hay una nota…\p"
	.string "El PUESTO GUARDA DE LA ZONA SAFARI\p"
	.string "está cerrado hasta nuevo aviso$"

FuchsiaCity_Text_SafariZone:
	.string "SAFARI ZONE\n"
	.string "NOW OWNED BY\l"
	.string "DEVON CORP.$"

FuchsiaCity_Text_SafariZoneClosedSign:
	.string "El GUARDA está de viaje. Ésa es la\n"
	.string "razón por la que la ZONA SAFARI está\l"
	.string "cerrada$"

FuchsiaCity_Text_NoLitteringSign:
	.string "No ensuciar.\p"
	.string "Por favor, no tirar basura$"

