MysteryGiftScript_AlteringCave::
	setvaddress MysteryGiftScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, (NUM_ALTERING_CAVE_TABLES + 1), MysteryGiftScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryGiftScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "Gracias por usar el sistema de\n"
	.string "REGALO MISTERIOSO.\p"
	.string "Parece que corre el rumor de\n"
	.string "avistamientos de POKéMON raros.\p"
	.string "Según se dice, los avistamientos\n"
	.string "vienen de la CUEVA CAMBIANTE, en la\l"
	.string "RUTA 103.\p"
	.string "Quizá te merezca la pena\n"
	.string "investigar este rumor.$"
