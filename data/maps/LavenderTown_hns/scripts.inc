LavenderTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_EventScript_CityEnter
	.byte 0

LavenderTown_EventScript_CityEnter::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_EventScript_PokefanM::
	msgbox LavenderTown_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_EventScript_Teacher::
	msgbox LavenderTown_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_EventScript_Gramps::
	msgbox LavenderTown_Text_Gramps, MSGBOX_NPC
	end

LavenderTown_EventScript_Youngster::
	msgbox LavenderTown_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_Sign, MSGBOX_SIGN
	end

LavenderTown_EventScript_RadioTowerSign::
	msgbox LavenderTown_Text_KantoRadioStationSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouseSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SoulHouseSign::
	msgbox LavenderTown_Text_SoulHouseSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokefanM:
	.string "Menudo edificio, ¿eh?\p"
	.string "Es la TORRE RADIO de KANTO.$"

LavenderTown_Text_Teacher:
	.string "KANTO tiene muchos programas de radio\n"
	.string "buenos.$"

LavenderTown_Text_Gramps:
	.string "Viene gente de todas partes a rendir\n"
	.string "homenaje a las almas de los\p"
	.string "POKéMON que han partido.$"

LavenderTown_Text_Youngster:
	.string "Para despertar a los POKéMON,\n"
	.string "sintoniza FLAUTA POKéMON.\p"
	.string "¡Todo entrenador debería saberlo!$"

LavenderTown_Text_Sign:
	.string "PUEBLO LAVANDA\p"
	.string "El noble pueblo púrpura$"

LavenderTown_Text_KantoRadioStationSign:
	.string "EMISORA DE KANTO\p"
	.string "¡Tus programas favoritos a cualquier\n"
	.string "hora!$"

LavenderTown_Text_VolunteerPokemonHouseSign:
	.string "CASA POKéMON DE VOLUNTARIOS DE\n"
	.string "PUEBLO LAVANDA$"

LavenderTown_Text_SoulHouseSign:
	.string "CEMENTERIO\p"
	.string "Que las almas de los POKéMON\n"
	.string "descansen en paz$"
