LavenderTown_VolunteerPokemonHouse_Frlg_MapScripts::
	.byte 0

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POKE_FLUTE, LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute
	msgbox LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis
	checkitemspace ITEM_POKE_FLUTE
	goto_if_eq VAR_RESULT, FALSE, LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute
	setflag FLAG_GOT_POKE_FLUTE
	giveitem_msg LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji, ITEM_POKE_FLUTE, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl::
	lock
	faceplayer
	famechecker FAMECHECKER_MRFUJI, 0
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack
	msgbox LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORINO, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Nidorino
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Psyduck
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine::
	lockall
	famechecker FAMECHECKER_MRFUJI, 2
	msgbox LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped
	releaseall
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf, MSGBOX_SIGN
	end

LavenderTown_PokemonCenter_1F_Text_HearMrFujiNotFromAroundHere::
	.string "Acabo de mudarme a este pueblo.\p"
	.string "He oído que el SR. FUJI tampoco\n"
	.string "es de por aquí.$"

LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo::
	.string "El SR. FUJI no está aquí.\n"
	.string "¡Qué raro! ¿Adónde ha ido?$"

LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother::
	.string "El SR. FUJI estaba rindiendo\n"
	.string "homenaje a la madre de CUBONE.$"

LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons::
	.string "Ésta es la casa del SR. FUJI.\p"
	.string "¡Es muy amable!\p"
	.string "¡Cuida de los POKéMON huérfanos\n"
	.string "y abandonados!$"

LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug::
	.string "¡Es tan bonito abrazar a los\n"
	.string "POKéMON!$"

LavenderTown_VolunteerPokemonHouse_Text_Nidorino::
	.string "NIDORINO: ¡Nidor!$"

LavenderTown_VolunteerPokemonHouse_Text_Psyduck::
	.string "PSYDUCK: ¡Psydu!$"

LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis::
	.string "SR. FUJI: {PLAYER}.\p"
	.string "Te va a costar mucho esfuerzo\n"
	.string "completar la POKéDEX.\p"
	.string "Si no adoras a tus POKéMON,\n"
	.string "te resultará difícil finalizarla.\p"
	.string "Creo que esto te ayudará.$"

LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji::
	.string "¡{PLAYER} obtuvo la POKé FLAUTA\n"
	.string "de manos del SR. FUJI!$"

LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute::
	.string "Cuando escuchen la POKé FLAUTA,\n"
	.string "los POKéMON dormidos se\l"
	.string "despertarán.\p"
	.string "Funciona con todos los POKéMON\n"
	.string "dormidos.$"

LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis::
	.string "¡No tienes sitio para esto!$"

LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou::
	.string "SR. FUJI: ¿Te ayudó mi POKé\n"
	.string "FLAUTA?$"

LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped::
	.string "REVISTA POKéMON\n"
	.string "¡Gran concurso mensual de dibujo\l"
	.string "POKéMON!\p"
	.string "El formulario de inscripción está\n"
	.string "en...\p"
	.string "¡Anda, se lo han llevado!\n"
	.string "¡Se ha debido de inscribir alguien!$"

LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf::
	.string "¡Revistas de los POKéMON!\p"
	.string "¡Cuadernos de los POKéMON!\p"
	.string "¡Dibujos de los POKéMON!$"

