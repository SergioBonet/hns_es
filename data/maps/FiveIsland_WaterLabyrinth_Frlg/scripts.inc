FiveIsland_WaterLabyrinth_Frlg_MapScripts::
	.byte 0

FiveIsland_WaterLabyrinth_EventScript_EggGentleman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TOGEPI_EGG, FiveIsland_WaterLabyrinth_EventScript_PostEggComment
	goto_if_set FLAG_NO_ROOM_FOR_TOGEPI_EGG, FiveIsland_WaterLabyrinth_EventScript_ReturnForEgg
	msgbox FiveIsland_WaterLabyrinth_Text_LetMeTakeLookAtMons
	specialvar VAR_RESULT, GetLeadMonFriendship
	goto_if_eq VAR_RESULT, 6, FiveIsland_WaterLabyrinth_EventScript_LeadMonMaxFriendship
	msgbox FiveIsland_WaterLabyrinth_Text_HmmISeeIsee
	release
	end

FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment::
	famechecker FAMECHECKER_DAISY, 2
	msgbox FiveIsland_WaterLabyrinth_Text_CuteMonRemindsMeOfDaisy
	release
	end

FiveIsland_WaterLabyrinth_EventScript_LeadMonMaxFriendship::
	msgbox FiveIsland_WaterLabyrinth_Text_TreatMonRightHaveThis
	goto FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg
	end

FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg::
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, FiveIsland_WaterLabyrinth_EventScript_NoRoomForEgg
	setflag FLAG_GOT_TOGEPI_EGG
	giveegg SPECIES_TOGEPI
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message FiveIsland_WaterLabyrinth_Text_ReceivedEggFromMan
	waitfanfare
	waitmessage
	call EventScript_RestorePrevTextColor
	goto FiveIsland_WaterLabyrinth_EventScript_PostEggComment
	end

@ If the player has a Togepi/Togetic from this game (assumed to be the one the man gave you) then comment on it
@ Otherwise make normal comment
FiveIsland_WaterLabyrinth_EventScript_PostEggComment::
	bufferspeciesname STR_VAR_2, SPECIES_TOGEPI
	setvar VAR_0x8004, SPECIES_TOGEPI
	specialvar VAR_RESULT, PlayerPartyContainsSpeciesWithPlayerID
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment
	bufferspeciesname STR_VAR_2, SPECIES_TOGETIC
	setvar VAR_0x8004, SPECIES_TOGETIC
	specialvar VAR_RESULT, PlayerPartyContainsSpeciesWithPlayerID
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment
	msgbox FiveIsland_WaterLabyrinth_Text_GladIMetSomeoneLikeYou
	release
	end

FiveIsland_WaterLabyrinth_EventScript_NoRoomForEgg::
	setflag FLAG_NO_ROOM_FOR_TOGEPI_EGG
	msgbox FiveIsland_WaterLabyrinth_Text_DontHaveSpaceInYourParty
	release
	end

FiveIsland_WaterLabyrinth_EventScript_ReturnForEgg::
	goto FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg
	end

FiveIsland_WaterLabyrinth_Text_LetMeTakeLookAtMons::
	.string "Viajas por todas partes, ¿verdad?\p"
	.string "¿No estarás tratando a tus POKéMON\n"
	.string "demasiado duro?\p"
	.string "Déjame echar un vistazo.\n"
	.string "… … …   … … …$"

FiveIsland_WaterLabyrinth_Text_HmmISeeIsee::
	.string "Mmm...\n"
	.string "Ya veo...$"

FiveIsland_WaterLabyrinth_Text_TreatMonRightHaveThis::
	.string "Impresionante.\n"
	.string "Tratas muy bien a los POKéMON.\p"
	.string "No hace falta que te diga nada.\p"
	.string "Toma, quiero darte esto.$"

FiveIsland_WaterLabyrinth_Text_ReceivedEggFromMan::
	.string "¡{PLAYER} recibió un HUEVO!$"

FiveIsland_WaterLabyrinth_Text_DontHaveSpaceInYourParty::
	.string "Vaya, qué lástima..., tu equipo\n"
	.string "está completo.\p"
	.string "Vuelve a recogerlo en otro\n"
	.string "momento.$"

@ Unused
FiveIsland_WaterLabyrinth_Text_YouveComeBackForTheEgg::
	.string "¡Hola!\n"
	.string "¿Has venido a recoger\l"
	.string "el HUEVO?$"

FiveIsland_WaterLabyrinth_Text_GladIMetSomeoneLikeYou::
	.string "A mí me dieron ese HUEVO cuando\n"
	.string "estuve fuera.\p"
	.string "Me alegro de haber encontrado\n"
	.string "a alguien como tú.$"

FiveIsland_WaterLabyrinth_Text_CuteMonRemindsMeOfDaisy::
	.string "Oh, hola.\n"
	.string "Qué {STR_VAR_2} más mono.\p"
	.string "Verlo me recuerda a una dulce\n"
	.string "niña que conocí durante mis viajes.\p"
	.string "Cepillaba a los POKéMON con\n"
	.string "delicadeza… Era un angelito.\p"
	.string "El nombre de esa niña…\n"
	.string "Creo que era DALIA.$"

FiveIsland_WaterLabyrinth_Text_AlizeIntro::
	.string "Este es un entorno excelente\n"
	.string "para criar POKéMON.$"

FiveIsland_WaterLabyrinth_Text_AlizeDefeat::
	.string "¡Tus POKéMON están creciendo\n"
	.string "admirablemente bien!$"

FiveIsland_WaterLabyrinth_Text_AlizePostBattle::
	.string "Sabes, creo que tienes talento\n"
	.string "para ser un buen CRIADOR.$"
