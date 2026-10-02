AzaleaTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_Pokecenter_OnTransition
	.byte 0

AzaleaTown_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_AZALEA_TOWN_HNS
	end

AzaleaPokeCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_FishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_PokefanF::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokecenter_Text_Gentleman:
	.string "¿Tus POKéMON saben movimientos MO?\p"
	.string "Se pueden usar estos movimientos\n"
	.string "aunque el POKéMON esté debilitado.$"

AzaleaPokecenter_Text_UnusedPCExplanation:
	.string "Ese tal BILL creó el sistema para\n"
	.string "guardar POKéMON en el PC.\p"
	.string "El PC de BILL puede guardar hasta 30\n"
	.string "POKéMON por CAJA.$"

AzaleaPokecenter_Text_FishingGuru:
	.string "Gracias al Sistema de Almacenamiento\n"
	.string "de Bill se pueden depositar hasta 30\l"
	.string "POKéMON por Caja.$"

AzaleaPokecenter_Text_PokefanF:
	.string "¿Sabes cosas de las BAYAS?\p"
	.string "Se abre una, se vacía y se le pone un\n"
	.string "dispositivo especial.\p"
	.string "Y entonces se pueden atrapar POKéMON\n"
	.string "con ella.\p"
	.string "Antes de que se inventaran las POKé\n"
	.string "BALLS, todo el mundo usaba BAYAS.$"
