OneIsland_KindleRoad_EmberSpa_Frlg_MapScripts::
	.byte 0

OneIsland_KindleRoad_EmberSpa_EventScript_OldMan::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_WaterWarmsMeToCore, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BaldingMan1::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_EnjoyBowlOfChowder, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BaldingMan2::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_HotSpringIsTherapeutic, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_OldWoman::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_SeeHowSmoothMySkinIs, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BlackBelt::
	lock
	faceplayer
	famechecker FAMECHECKER_BRUNO, 3
	msgbox OneIsland_KindleRoad_EmberSpa_Text_BrunoVisitsSpaOnOccasion
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_RockSmashMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM06, OneIsland_KindleRoad_EmberSpa_EventScript_AlreadyGotHM06
	msgbox OneIsland_KindleRoad_EmberSpa_Text_UsedThisToMakeEmberSpa
	giveitem ITEM_HM06
	setflag FLAG_GOT_HM06
	msgbox OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_AlreadyGotHM06::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_SpaHeal::
	lockall
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	msgbox OneIsland_KindleRoad_EmberSpa_Text_WaterExquisiteFullyRefreshed
	setvar VAR_TEMP_1, 1
	releaseall
	end

OneIsland_KindleRoad_EmberSpa_Text_WaterWarmsMeToCore::
	.string "¡Mm!\n"
	.string "¡Aaaaaaaaaah!\p"
	.string "¡Aaah! ¡Esto es el paraíso!\n"
	.string "¡El agua me calienta hasta el alma!\p"
	.string "Deberías meterte tú también.\p"
	.string "Ve al centro, relájate y\n"
	.string "¡caliéntate bien!$"

OneIsland_KindleRoad_EmberSpa_Text_EnjoyBowlOfChowder::
	.string "La mejor parte del baño viene\n"
	.string "cuando me salgo del agua.\p"
	.string "No hay nada como tomar un buen\n"
	.string "plato de sopa de pescado caliente\l"
	.string "para conservar el calorcito. Mmm...$"

OneIsland_KindleRoad_EmberSpa_Text_WaterExquisiteFullyRefreshed::
	.string "El agua está en su punto.\n"
	.string "Tiene la temperatura ideal...\p"
	.string "¡{PLAYER} y sus POKéMON están\n"
	.string "en forma de nuevo!$"

OneIsland_KindleRoad_EmberSpa_Text_HotSpringIsTherapeutic::
	.string "Dicen que los baños termales\n"
	.string "son terapéuticos.$"

OneIsland_KindleRoad_EmberSpa_Text_SeeHowSmoothMySkinIs::
	.string "¿Has visto cómo tengo la piel?\n"
	.string "Suave y tersa como la de un bebé.\p"
	.string "¡Las aguas termales me están\n"
	.string "dejando hecha una rosa!$"

OneIsland_KindleRoad_EmberSpa_Text_BrunoVisitsSpaOnOccasion::
	.string "Tras un duro día de entrenamiento,\n"
	.string "no hay nada como un buen baño\l"
	.string "termal.\p"
	.string "BRUNO, ejemplo al que sigo, viene\n"
	.string "al BALNEARIO cada vez que puede.\p"
	.string "No sólo para recuperarse él,\n"
	.string "también lo hace por sus POKéMON.$"

OneIsland_KindleRoad_EmberSpa_Text_UsedThisToMakeEmberSpa::
	.string "Las aguas termales tienen una\n"
	.string "relación estrecha con los volcanes.\p"
	.string "Yo fui quien montó el BALNEARIO\n"
	.string "ASCUAS hace unos años.\p"
	.string "En enormes cantos que había,\n"
	.string "hice las piscinas termales picando\l"
	.string "la piedra con mis propias manos.\p"
	.string "Entonces, usé esto. Creo que\n"
	.string "ya puedo desprenderme de ello.$"

OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06::
	.string "Podrás destrozar rocas como\n"
	.string "si fueran nueces.$"

