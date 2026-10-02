SaffronCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_EventScript_CityEnter
	.byte 0

SaffronCity_EventScript_CityEnter::
	setflag FLAG_VISITED_SAFFRON_CITY
	end

SaffronCity_Text_BaobaName:
	.string "BAOBA$"

SaffronCity_Text_Baoba:
	.string "GUARDA BAOBA: ¡{PLAYER}!\p"
	.string "Soy el GUARDA BAOBA.\p"
	.string "Te llamo para decirte que la ZONA\n"
	.string "SAFARI se ha vuelto a ampliar.\p"
	.string "¡Por fin mi ZONA SAFARI está completa!\p"
	.string "Te acuerdas de dónde está, ¿verdad?\p"
	.string "¡Justo al oeste de CIUDAD ORQUÍDEA!\n"
	.string "¡Hasta pronto!$"

SaffronCity_EventScript_Lass1A::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Lass1B
	msgbox SaffronCity_Text_Lass1, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass1B::
	msgbox SaffronCity_Text_Lass1_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass2::
	msgbox SaffronCity_Text_Lass2, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_PokefanM2
	msgbox SaffronCity_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM2::
	msgbox SaffronCity_Text_PokefanM_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerM::
	msgbox SaffronCity_Text_CooltrainerM, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerF::
	msgbox SaffronCity_Text_CooltrainerF, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Fisher2
	msgbox SaffronCity_Text_Fisher, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher2::
	msgbox SaffronCity_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster1::
	msgbox SaffronCity_Text_Youngster1, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster2::
	msgbox SaffronCity_Text_Youngster2, MSGBOX_NPC
	end
SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_Sign, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	msgbox SaffronCity_Text_GymSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicSign::
	msgbox SaffronCity_Text_MrPsychicHouseSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MagnetTrainSign::
	msgbox SaffronCity_Text_MagnetTrainStationSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_Elli::
	msgbox SaffronCity_Text_Elli, MSGBOX_NPC
	end

SaffronCity_Text_Elli:
	.string "¡Me encanta VULPIX! :D$"

SaffronCity_Text_Lass1:
	.string "Aquí vive una niña que es experta en\n"
	.string "imitar a la gente.\p"
	.string "Imita incluso a la gente con la que\n"
	.string "habla, y te confunde.$"

SaffronCity_Text_Lass1_ReturnedPart:
	.string "La COPIONA parecía muy triste.\p"
	.string "Había perdido su POKé MUÑECO\n"
	.string "CLEFAIRY favorito.$"

SaffronCity_Text_PokefanM:
	.string "¿Eres de JOHTO?\p"
	.string "Si funcionara el MAGNETOTRÉN, no\n"
	.string "tardarías nada en volver a casa.$"

SaffronCity_Text_PokefanM_ReturnedPart:
	.string "¿Eres de JOHTO?\p"
	.string "Con el MAGNETOTRÉN enseguida estarás\n"
	.string "en casa.$"

SaffronCity_Text_CooltrainerM:
	.string "Iba al GIMNASIO a luchar contra\n"
	.string "entrenadores…\p"
	.string "Y acabé en el viejo GIMNASIO que hay\n"
	.string "al lado.\p"
	.string "¡Vaya, qué vergüenza pasé!$"

SaffronCity_Text_CooltrainerF:
	.string "Es SILPH S.A., famosa por sus\n"
	.string "artículos POKéMON.\p"
	.string "En el pasado, el TEAM ROCKET quiso\n"
	.string "hacerse con esta compañía por esa\l"
	.string "misma razón.$"

SaffronCity_Text_Fisher:
	.string "¡Ñam, ñam!\p"
	.string "Dicen que en la CENTRAL ENERGÍA\p"
	.string "tienen muchos problemas.\p"
	.string "¡Ñam, ñam!$"

SaffronCity_Text_Fisher_ReturnedPart:
	.string "Ñam… Ñam…\p"
	.string "He oído que hubo un gran problema en\n"
	.string "la CENTRAL ENERGÍA.\p"
	.string "Ñam… Ñam… ¡Aaah, estoy lleno!$"

SaffronCity_Text_Youngster1:
	.string "Entrar por primera vez en un callejón\n"
	.string "me pone un poco nervioso.$"

SaffronCity_Text_Youngster2:
	.string "En CIUDAD VERDE hay un sitio llamado\n"
	.string "SALA DE CONCURSOS, donde se reúnen\l"
	.string "ENTRENADORES de todas partes.$"

SaffronCity_Text_Lass2:
	.string "Nuestra ciudad salió en un programa\n"
	.string "de radio.\p"
	.string "Está bien que alaben tu ciudad, pero\n"
	.string "también da un poco de vergüenza.$"

SaffronCity_Text_Sign:
	.string "CIUDAD AZAFRÁN\p"
	.string "La brillante y dorada tierra del\n"
	.string "comercio$"

SaffronCity_Text_GymSign:
	.string "LÍDER DEL GIMNASIO POKéMON DE\n"
	.string "CIUDAD AZAFRÁN: SABRINA\p"
	.string "Maestra de los POKéMON psíquicos$"

SaffronCity_Text_FightingDojoSign:
	.string "¡Bienvenidos! DOJO-KARATE$"

SaffronCity_Text_SilphCoSign:
	.string "EDIFICIO-OFICINAS SILPH S.A.$"

SaffronCity_Text_MrPsychicHouseSign:
	.string "CASA DEL SR. PSÍQUICO$"

SaffronCity_Text_MagnetTrainStationSign:
	.string "ESTACIÓN DEL MAGNETOTRÉN DE CIUDAD\n"
	.string "AZAFRÁN$"
