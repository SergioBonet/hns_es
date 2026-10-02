VioletCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_Pokecenter_OnTransition
	.byte 0

VioletCity_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	end

VioletCity_PokemonCenter_EventScript_Aide::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TOGEPI_EGG, VioletCity_PokemonCenter_EventScript_Aide_Received
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	goto_if_eq VAR_0x8004, 1, VioletCity_PokemonCenter_EventScript_Aide_Offer @ party limit of 1: the Egg goes to the PC
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, VioletCity_PokemonCenter_EventScript_AideNoRoom
VioletCity_PokemonCenter_EventScript_Aide_Offer::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end


VioletCity_PokemonCenter_EventScript_Aide_FullParty::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFullParty, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_AideNoRoom::
	msgbox VioletCity_PokeCenter_Text_ElmsAideNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Refuse::
	msgbox VioletCity_PokeCenter_Text_ElmsAideRefuse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Accepted::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	goto_if_eq VAR_0x8004, 1, VioletCity_PokemonCenter_EventScript_Aide_GiveEgg @ party limit of 1: the Egg goes to the PC
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, VioletCity_PokemonCenter_EventScript_Aide_FullParty
VioletCity_PokemonCenter_EventScript_Aide_GiveEgg::
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	giveegg SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Common_EventScript_NoMoreRoomForPokemon @ party limit of 1 and every BOX full
	call_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VioletCity_PokemonCenter_EventScript_Aide_EggSentToPC
	setflag FLAG_RECEIVED_TOGEPI_EGG
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveItem, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE_SMALL
	setflag FLAG_HIDE_VIOLET_CITY_AIDE
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 1
	clearflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	clearflag FLAG_HIDE_NEWBARKTOWN_LAB_AIDE
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_EggSentToPC::
	msgbox VioletCity_PokeCenter_Text_ElmsAideEggToPC, MSGBOX_DEFAULT
	closemessage
	return

VioletCity_PokemonCenter_EventScript_Aide_Received::
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EVentScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_GameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Man::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_Text_BookshelfWoman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_BooksAreGreat, MSGBOX_DEFAULT
	closemessage
	release
	end


VioletCity_PokeCenter_Text_ElmsAideFavor:
	.string "{PLAYER}, cuánto tiempo.\p"
	.string "El PROF. ELM me pidió que te buscara.\p"
	.string "Tiene otro favor que pedirte.\p"
	.string "¿Te llevarías el HUEVO POKéMON?$"

VioletCity_PokeCenter_Text_ElmsAideNoRoom:
	.string "{PLAYER}, cuánto tiempo.\p"
	.string "El PROF. ELM me pidió que te buscara.\p"
	.string "Tiene otro favor que pedirte.\p"
	.string "¿Te llevarías el HUEVO POKéMON?\p"
	.string "Ah, espera… Primero tienes que hacer\n"
	.string "sitio en tu equipo.$"

VioletCity_PokeCenter_Text_ElmsAideGiveEgg:
	.string "Hemos descubierto que un POKéMON no\n"
	.string "eclosiona hasta que no crece dentro\l"
	.string "del HUEVO.\p"
	.string "Además, para eclosionar, tiene que\n"
	.string "estar con otros POKéMON activos.\p"
	.string "{PLAYER}, eres la única persona en la\n"
	.string "que podemos confiar.$"

VioletCity_PokeCenter_Text_ElmsAideGiveItem:
	.string "Ah, y esto quizás te ayude cuando\n"
	.string "eclosione.$"

VioletCity_PokeCenter_Text_ElmsAideFullParty:
	.string "¡Oh, no! No puedes llevar más POKéMON.\p"
	.string "Esperaré aquí a que le hagas sitio al\n"
	.string "HUEVO.$"

VioletCity_PokeCenter_Text_ElmsAideEggToPC:
	.string "Ah, pero no puedes llevar más POKéMON\n"
	.string "contigo.\p"
	.string "No te preocupes, te he enviado el\n"
	.string "HUEVO al PC de BILL.$"

VioletCity_PokeCenter_Text_ElmsAideRefuse:
	.string "Pero… El PROF. ELM preguntó por ti.$"

VioletCity_PokeCenter_Text_BooksAreGreat:
	.string "Mientras mis POKéMON se recuperan, me\n"
	.string "encanta leer un buen libro.$"

VioletCity_PokeCenter_Text_MobileAdapter:
	.string "Acabo de luchar contra un amigo de\n"
	.string "CIUDAD ORQUÍDEA por conexión.\p"
	.string "Si conectas un ADAPTADOR MÓVIL,\n"
	.string "puedes conectarte con un amigo que\l"
	.string "esté lejos.$"

VioletCity_PokeCenter_Text_GameboyKid:
	.string "Un tal BILL creó el Sistema de\p"
	.string "Almacenamiento de POKéMON.$"

VioletCity_PokeCenter_Text_Gentleman:
	.string "Fue hace unos tres años.\p"
	.string "El TEAM ROCKET quería hacer daño a\n"
	.string "los POKéMON.\p"
	.string "Pero prevaleció la justicia y un niño\n"
	.string "acabó con ellos.$"

VioletCity_PokeCenter_Text_Youngster:
	.string "Los POKéMON son listos y no obedecen\n"
	.string "a quien no respetan.\p"
	.string "Sin las MEDALLAS necesarias, harán lo\n"
	.string "que ellos quieran.$"
