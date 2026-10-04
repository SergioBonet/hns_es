PokemonTower_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonTower_1F_OnTransition
	.byte 0

PokemonTower_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POKEMON_TOWER_1F
	end

PokemonTower_1F_EventScript_Channeler::
	msgbox PokemonTower_1F_Text_SenseSpiritsUpToMischief, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_Woman1::
	msgbox PokemonTower_1F_Text_GrowlitheWhyDidYouDie, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_BaldingMan::
	msgbox PokemonTower_1F_Text_CameToPrayForDepartedClefairy, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_Woman2::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, PokemonTower_1F_EventScript_Woman2MalePlayer
	msgbox PokemonTower_1F_Text_ComeToPayRespectsGirl
	release
	end

PokemonTower_1F_EventScript_Woman2MalePlayer::
	msgbox PokemonTower_1F_Text_ComeToPayRespectsSon
	release
	end

PokemonTower_1F_EventScript_WorkerF::
	msgbox PokemonTower_1F_Text_ErectedInMemoryOfDeadMons, MSGBOX_NPC
	end

PokemonTower_1F_Text_ErectedInMemoryOfDeadMons::
	.string "La TORRE POKéMON fue erigida\n"
	.string "en memoria de los POKéMON\l"
	.string "que se han debilitado.$"

PokemonTower_1F_Text_ComeToPayRespectsSon::
	.string "¿Has venido a rendirles homenaje?\p"
	.string "¡Qué majo!$"

PokemonTower_1F_Text_ComeToPayRespectsGirl::
	.string "¿Has venido a rendirles homenaje?\p"
	.string "¡Qué maja!$"

PokemonTower_1F_Text_CameToPrayForDepartedClefairy::
	.string "Vine a rendir homenaje\n"
	.string "a mi CLEFAIRY.\p"
	.string "¡Sniff!\n"
	.string "No puedo dejar de llorar...$"

PokemonTower_1F_Text_GrowlitheWhyDidYouDie::
	.string "Mi GROWLITHE... ¿Por qué\n"
	.string "has tenido que debilitarte?$"

PokemonTower_1F_Text_SenseSpiritsUpToMischief::
	.string "¡Soy EXORCISTA!\p"
	.string "¡Hay espíritus muy revoltosos\n"
	.string "en esta TORRE!$"

