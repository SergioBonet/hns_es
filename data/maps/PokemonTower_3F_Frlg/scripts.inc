PokemonTower_3F_Frlg_MapScripts::
	.byte 0

PokemonTower_3F_EventScript_Patricia::
	trainerbattle_single TRAINER_CHANNELER_PATRICIA, PokemonTower_3F_Text_PatriciaIntro, PokemonTower_3F_Text_PatriciaDefeat
	msgbox PokemonTower_3F_Text_PatriciaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_EventScript_Carly::
	trainerbattle_single TRAINER_CHANNELER_CARLY, PokemonTower_3F_Text_CarlyIntro, PokemonTower_3F_Text_CarlyDefeat
	msgbox PokemonTower_3F_Text_CarlyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_EventScript_Hope::
	trainerbattle_single TRAINER_CHANNELER_HOPE, PokemonTower_3F_Text_HopeIntro, PokemonTower_3F_Text_HopeDefeat
	msgbox PokemonTower_3F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_Text_HopeIntro::
	.string "Urrg... aaa...\n"
	.string "Uuuu... graa...$"

PokemonTower_3F_Text_HopeDefeat::
	.string "¡Uau!\n"
	.string "¡Estoy salvado!$"

PokemonTower_3F_Text_HopePostBattle::
	.string "Los GHOST son identificados con\n"
	.string "el SCOPE SILPH.$"

PokemonTower_3F_Text_CarlyIntro::
	.string "Ji, ji, ji…\n"
	.string "¡Kuaaah!$"

PokemonTower_3F_Text_CarlyDefeat::
	.string "¿Mmm?\n"
	.string "¿Pero qué hago?$"

PokemonTower_3F_Text_CarlyPostBattle::
	.string "¡Perdona!\n"
	.string "¡Estaba fuera de mí!$"

PokemonTower_3F_Text_PatriciaIntro::
	.string "¡Fuera, espíritu malvado!$"

PokemonTower_3F_Text_PatriciaDefeat::
	.string "¡El espíritu se fue!$"

PokemonTower_3F_Text_PatriciaPostBattle::
	.string "Los de arriba…\n"
	.string "Deben de estar poseídos.$"

