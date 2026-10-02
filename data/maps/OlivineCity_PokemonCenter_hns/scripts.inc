OlivineCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_PokemonCenter_OnTransition
	.byte 0

OlivineCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_OLIVINE_CITY_HNS
	end

OlivineCity_EventScript_Fisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterFisher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Teacher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PokecenterFisher:
	.string "El MARINERO de la CAFETERÍA de CIUDAD\n"
	.string "OLIVO, aquí al lado, es muy generoso.\p"
	.string "Le enseñó FUERZA a mi POKéMON.\p"
	.string "Ahora puede mover grandes rocas sin\n"
	.string "despeinarse.$"

OlivineCity_Text_PokecenterTeacher:
	.string "En CIUDAD ORQUÍDEA, al otro lado del\n"
	.string "mar, hay una persona.\p"
	.string "Le oí presumir todo el rato de su\n"
	.string "POKéMON raro.$"
