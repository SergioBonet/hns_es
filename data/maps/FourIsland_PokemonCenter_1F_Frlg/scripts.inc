FourIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FourIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FOUR_ISLAND
	end

FourIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

FourIsland_PokemonCenter_1F_EventScript_Man::
	msgbox FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave, MSGBOX_NPC
	end

FourIsland_PokemonCenter_1F_EventScript_Woman::
	msgbox FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore, MSGBOX_NPC
	end

FourIsland_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived, MSGBOX_NPC
	end

@ The 5 texts below are supposed to be in FourIsland_House1
Text_BodySlamTeach::
	.string "¿Ya?\n"
	.string "¡Toma!\p"
	.string "Estamos usando GOLPE CUERPO para\n"
	.string "ver quién machaca antes a quién.\p"
	.string "Si te metieras en la pelea, no\n"
	.string "tendrías nada que hacer...\p"
	.string "¿Quieres que le enseñe GOLPE\n"
	.string "CUERPO a alguno de tus POKéMON?$"

Text_BodySlamDeclined::
	.string "¡Venga, otra vez!\n"
	.string "¡Toma!$"

Text_BodySlamWhichMon::
	.string "¿A qué POKéMON quieres que\n"
	.string "le enseñe GOLPE CUERPO?$"

Text_BodySlamTaught::
	.string "¡Uauuu!$"

FourIsland_House1_Text_FatMan::
	.string "¡Boing!\n"
	.string "¡Pesas un montón!$"

FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave::
	.string "En la CUEVA GLACIADA hay un\n"
	.string "POKéMON raro del tipo HIELO.\p"
	.string "Aquí viene mucha gente para\n"
	.string "verlo.$"

FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore::
	.string "¿Cómo? ¿Un HUEVO POKéMON?\n"
	.string "Ni idea...\p"
	.string "Eh..., sí, espera, los ENCARGADOS\n"
	.string "de la GUARDERÍA comentaron algo\l"
	.string "sobre eso.\p"
	.string "Dijeron que habían encontrado\n"
	.string "HUEVOS en la propia GUARDERÍA.$"

FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived::
	.string "¡Pero bueno!\p"
	.string "¿Que aún no ha llegado el nuevo\n"
	.string "DIARIO POKéMON a esta isla?$"

