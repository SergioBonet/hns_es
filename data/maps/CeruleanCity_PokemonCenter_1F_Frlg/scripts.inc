CeruleanCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CeruleanCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

CeruleanCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_EventScript_Rocker::
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_EventScript_Youngster::
	lock
	faceplayer
	famechecker FAMECHECKER_BILL, 1
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons
	release
	end

CeruleanCity_PokemonCenter_1F_EventScript_Lass::
	msgbox CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons::
	.string "¡Ese BILL!\p"
	.string "He oído que hará lo que sea para\n"
	.string "conseguir POKéMON raros.\p"
	.string "Dicen que no tiene reparos en\n"
	.string "hacer todo tipo de cosas.$"

CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac::
	.string "¿Has oído hablar de BILL?\p"
	.string "¡Dicen que es un POKéMANÍACO!\p"
	.string "Pero yo creo que la gente le tiene\n"
	.string "mucha envidia.\p"
	.string "¿Quién no querría presumir de sus\n"
	.string "POKéMON?$"

CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons::
	.string "¡BILL tiene muchísimos POKéMON!\n"
	.string "¡Y algunos son muy raros!$"

CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs::
	.string "¿Por qué no subes e intercambias\n"
	.string "POKéMON con tus amigos?\p"
	.string "¡Así se pueden conseguir POKéMON\n"
	.string "muy distintos!\p"
	.string "Además, los que consigues por\n"
	.string "intercambio, crecen antes.$"

