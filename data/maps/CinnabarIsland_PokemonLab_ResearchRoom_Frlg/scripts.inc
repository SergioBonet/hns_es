CinnabarIsland_PokemonLab_ResearchRoom_Frlg_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_MetronomeTutor::
	goto EventScript_MetronomeTutor
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Computer::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_AmberPipe::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons::
	.string "EEVEE puede evolucionar\n"
	.string "y convertirse en tres tipos\l"
	.string "de POKéMON.$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail::
	.string "¡Hay un correo electrónico!\p"
	.string "...\p"
	.string "Los 3 legendarios pájaros POKéMON\n"
	.string "son ARTICUNO, ZAPDOS y MOLTRES.\p"
	.string "Desconocemos sus guaridas.\p"
	.string "Pensamos explorar la cueva\n"
	.string "que hay cerca de la CELESTE.\p"
	.string "De: EQUIPO de INVESTIGACIÓN\n"
	.string "POKéMON...$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe::
	.string "¡Un bote de ámbar!$"

