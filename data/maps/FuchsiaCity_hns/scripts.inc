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
	.string "GUARDA BAOBA: ¡{PLAYER}!\p"
	.string "Soy el GUARDA BAOBA.\p"
	.string "¡Ha pasado algo terrible! ¡Han\n"
	.string "comprado mi antigua ZONA SAFARI de\l"
	.string "CIUDAD FUCSIA y la han vuelto a abrir!\p"
	.string "¡Y por lo visto tiene POKéMON nuevos y\n"
	.string "exóticos!\p"
	.string "¡Me está arruinando el negocio!\p"
	.string "{PLAYER}, tienes que adentrarte en la\n"
	.string "nueva ZONA SAFARI y atrapar un\l"
	.string "POKéMON para enseñármelo. Necesito\l"
	.string "saber cómo son esos POKéMON\l"
	.string "“exóticos”.\p"
	.string "Por favor, {PLAYER}, ¡mi negocio\n"
	.string "depende de ti!$"

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
	.string "La ZONA SAFARI tiene una nueva\n"
	.string "dirección.\p"
	.string "¡Y tiene montones de POKéMON nuevos!$"

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
	.string "ZONA SAFARI\n"
	.string "AHORA PROPIEDAD\l"
	.string "DE DEVON S.A.$"

FuchsiaCity_Text_SafariZoneClosedSign:
	.string "El GUARDA está de viaje. Ésa es la\n"
	.string "razón por la que la ZONA SAFARI está\l"
	.string "cerrada$"

FuchsiaCity_Text_NoLitteringSign:
	.string "No ensuciar.\p"
	.string "Por favor, no tirar basura$"

