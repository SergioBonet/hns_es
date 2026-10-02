SafariZoneGate_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZoneGate_PokemonCenter_OnTransition
	.byte 0

SafariZoneGate_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFARI_ZONE_GATE_HNS
	end

SafariZoneGate_PokemonCenter_EventScript_NPC1::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_EventScript_NPC2::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC2, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_Boy::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_SafariSong, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_NPC1:
	.string "Those who come to a POKéMON CENTER\n"
	.string "often take good care of their POKéMON.\p"
	.string "Wouldn't you agree?$"

SafariZoneGate_PokemonCenter_Text_NPC2:
	.string "After a long walk in the mountains to\n"
	.string "find a POKéMON CENTER, when you're\l"
	.string "just about to fall flat...\p"
	.string "Then it feels like you are in paradise!$"

SafariZoneGate_PokemonCenter_Text_SafariSong:
	.string "¡La ZONA SAFARI es algo genial!\p"
	.string "¡La ZONA SAFARI es sensacional!\p"
	.string "Con tantísimos POKéMON… un lugar sin\n"
	.string "igual…\p"
	.string "Es una canción que me he inventado.\p"
	.string "La canto mientras paseo por la ZONA\n"
	.string "SAFARI.$"
