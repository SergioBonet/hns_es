LavenderTown_House1_Frlg_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_House1_EventScript_CooltrainerFGhostGone
	msgbox LavenderTown_House1_Text_RocketsKilledCubonesMother
	release
	end

LavenderTown_House1_EventScript_CooltrainerFGhostGone::
	msgbox LavenderTown_House1_Text_GhostOfPokemonTowerIsGone
	release
	end

LavenderTown_House1_EventScript_Cubone::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Cubone
	waitmoncry
	release
	end

LavenderTown_House1_Text_Cubone::
	.string "CUBONE: ¡Cubon!$"

LavenderTown_House1_Text_RocketsKilledCubonesMother::
	.string "¡Odio a esos horribles ROCKET!\p"
	.string "La pobre madre de CUBONE...\p"
	.string "¡Intentó escapar del TEAM ROCKET,\n"
	.string "pero no lo consiguió!...$"

LavenderTown_House1_Text_GhostOfPokemonTowerIsGone::
	.string "¡El GHOST de la TORRE POKéMON\n"
	.string "se ha ido!\p"
	.string "¡Alguien debe de haber calmado\n"
	.string "su atormentada alma!$"

