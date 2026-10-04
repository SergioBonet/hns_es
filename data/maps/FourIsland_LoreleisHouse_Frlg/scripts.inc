FourIsland_LoreleisHouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_LoreleisHouse_OnTransition
	.byte 0

FourIsland_LoreleisHouse_OnTransition::
	special UpdateLoreleiDollCollection
	end

FourIsland_LoreleisHouse_EventScript_Lorelei::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_LORELEI_AFTER_WAREHOUSE, FourIsland_LoreleisHouse_EventScript_Lorelei3
	goto_if_set FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE, FourIsland_LoreleisHouse_EventScript_Lorelei2
	msgbox FourIsland_LoreleisHouse_Text_IfAnythingWereToHappenToIsland
	release
	end

FourIsland_LoreleisHouse_EventScript_Lorelei2::
	setflag FLAG_TALKED_TO_LORELEI_AFTER_WAREHOUSE
	msgbox FourIsland_LoreleisHouse_Text_IllReturnToLeagueInShortWhile
	release
	end

FourIsland_LoreleisHouse_EventScript_Lorelei3::
	msgbox FourIsland_LoreleisHouse_Text_WillDoWhatICanHereAndNow
	release
	end

FourIsland_LoreleisHouse_EventScript_Doll::
	lock
	msgbox FourIsland_LoreleisHouse_Text_StuffedMonDollsGalore
	release
	end

FourIsland_LoreleisHouse_Text_IfAnythingWereToHappenToIsland::
	.string "LORELEI: No me puedo quitar una\n"
	.string "cosa de la cabeza...\p"
	.string "Si ocurriera algo a la isla en la\n"
	.string "que nací...\p"
	.string "No me enteraría si estuviera\n"
	.string "en la LIGA POKéMON.\p"
	.string "Entonces, sería responsable\n"
	.string "de lo ocurrido, ¿no?$"

FourIsland_LoreleisHouse_Text_IllReturnToLeagueInShortWhile::
	.string "LORELEI: ¿Que tú has solucionado\n"
	.string "todos los problemas?\p"
	.string "Qué maravilla...\p"
	.string "Entonces, no tengo que quedarme\n"
	.string "aquí todo el tiempo...\p"
	.string "¡Gracias!\p"
	.string "¡En ese caso, me volveré a la\n"
	.string "LIGA POKéMON!$"

FourIsland_LoreleisHouse_Text_WillDoWhatICanHereAndNow::
	.string "No sé qué pasará en el futuro,\n"
	.string "pero…\p"
	.string "Haré lo que pueda aquí y ahora.\n"
	.string "Es lo único que puedo hacer.$"

FourIsland_LoreleisHouse_Text_StuffedMonDollsGalore::
	.string "¡Qué cantidad de MUÑECOS POKéMON\n"
	.string "de peluche!$"

