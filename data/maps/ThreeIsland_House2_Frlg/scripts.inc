ThreeIsland_House2_Frlg_MapScripts::
	.byte 0

ThreeIsland_House2_EventScript_Man::
	lock
	faceplayer
	famechecker FAMECHECKER_SABRINA, 1
	msgbox ThreeIsland_House2_Text_IAdmireSabrina
	release
	end

ThreeIsland_House2_EventScript_Rocker::
	msgbox ThreeIsland_House2_Text_CantMakeThisSpoonBend, MSGBOX_NPC
	end

ThreeIsland_House2_Text_CantMakeThisSpoonBend::
	.string "Uuuuuuuuughhhh…\n"
	.string "¡Kuaaaaah!\p"
	.string "…¡Es inútil! No puedo doblar esta\n"
	.string "cuchara con la mente.\p"
	.string "Quizá de verdad no tengo poderes\n"
	.string "psíquicos.$"

ThreeIsland_House2_Text_IAdmireSabrina::
	.string "No sabes cómo te agradecemos\n"
	.string "que hayas rescatado a PEDRITA.\p"
	.string "Gracias a ti, la gente de ISLA\n"
	.string "TERA, tiene otra actitud hacia\l"
	.string "los habitantes de KANTO.\p"
	.string "Y yo soy de KANTO, ¿sabes?\p"
	.string "Por los habitantes de ISLA TERA,\n"
	.string "he aumentado el número\l"
	.string "de artículos.$"

