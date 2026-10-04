PokemonTower_4F_Frlg_MapScripts::
	.byte 0

PokemonTower_4F_EventScript_Paula::
	trainerbattle_single TRAINER_CHANNELER_PAULA, PokemonTower_4F_Text_PaulaIntro, PokemonTower_4F_Text_PaulaDefeat
	msgbox PokemonTower_4F_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_EventScript_Laurel::
	trainerbattle_single TRAINER_CHANNELER_LAUREL, PokemonTower_4F_Text_LaurelIntro, PokemonTower_4F_Text_LaurelDefeat
	msgbox PokemonTower_4F_Text_LaurelPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_EventScript_Jody::
	trainerbattle_single TRAINER_CHANNELER_JODY, PokemonTower_4F_Text_JodyIntro, PokemonTower_4F_Text_JodyDefeat
	msgbox PokemonTower_4F_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_Text_PaulaIntro::
	.string "¡Un GHOST!\n"
	.string "¡No! ¡Guaaah!$"

PokemonTower_4F_Text_PaulaDefeat::
	.string "¿Dónde está GHOST?$"

PokemonTower_4F_Text_PaulaPostBattle::
	.string "Debo de haber estado soñando…$"

PokemonTower_4F_Text_LaurelIntro::
	.string "¡Sé maldito conmigo!\n"
	.string "¡Kuaaah!$"

PokemonTower_4F_Text_LaurelDefeat::
	.string "¿Qué?$"

PokemonTower_4F_Text_LaurelPostBattle::
	.string "¡No podemos desvelar la identidad\n"
	.string "de los GHOST!$"

PokemonTower_4F_Text_JodyIntro::
	.string "Uuuuu…\n"
	.string "¡No me venzas!$"

PokemonTower_4F_Text_JodyDefeat::
	.string "¿Eh?\n"
	.string "¿Quién? ¿Qué?$"

PokemonTower_4F_Text_JodyPostBattle::
	.string "Que los POKéMON difuntos descansen\n"
	.string "en paz…$"

