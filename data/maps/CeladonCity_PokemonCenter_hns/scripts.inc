CeladonCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_OnTransition
	.byte 0

CeladonCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY_HNS
	end

CeladonCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Pharmacist::
	msgbox CeladonCity_PokemonCenter1F_Text_Pharmacist, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Eusine::
	msgbox Celadon_Text_Eusine1, MSGBOX_NPC
	end

CeladonCity_PokemonCenter1F_Text_CooltrainerF:
	.string "ERIKA es una experta en POKéMON de\n"
	.string "tipo PLANTA.\p"
	.string "Si no tienes cuidado, te lo hará pagar.$"

CeladonCity_PokemonCenter1F_Text_Pharmacist:
	.string "El TEAM ROCKET está escondido en el\n"
	.string "sótano del CASINO.\p"
	.string "Espera. Eso fue hace tres años.$"

Celadon_Text_Eusine1:
	.string "EUSINE: ¡Hola!\p"
	.string "Vuelvo de visitar mi ciudad.\p"
	.string "Llevaba tiempo sin ir.$"

Celadon_Text_EusineLeaves:
	.string "{PLAYER}, ¿te has enterado?\p"
	.string "Hay rumores nuevos de que un POKéMON\n"
	.string "de color arcoíris ha aparecido en la\l"
	.string "TORRE CAMPANA.\p"
	.string "Acaban de curar a mi equipo, así que\n"
	.string "me voy a CIUDAD IRIS.\p"
	.string "¡Nos vemos, {PLAYER}!$"

Celadon_Text_NoBeasts:
	.string "Ah, por cierto, {PLAYER}.\p"
	.string "¿Has atrapado a los POKéMON\n"
	.string "legendarios RAIKOU y ENTEI?\p"
	.string "……\p"
	.string "Vale…\p"
	.string "Si atrapas aunque sea uno, espero que\n"
	.string "me avises.\p"
	.string "¡Cuento contigo, {PLAYER}!$"
