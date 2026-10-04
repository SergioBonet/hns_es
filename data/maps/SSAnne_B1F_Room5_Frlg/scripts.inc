SSAnne_B1F_Room5_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room5_EventScript_Boy::
	msgbox SSAnne_B1F_Room5_Text_MachokeHasStrengthToMoveRocks, MSGBOX_NPC
	end

SSAnne_B1F_Room5_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
	msgbox SSAnne_B1F_Room5_Text_Machoke
	waitmoncry
	release
	end

SSAnne_B1F_Room5_Text_MachokeHasStrengthToMoveRocks::
	.string "¡Mi amigo, MACHOKE,\n"
	.string "es superfuerte!\p"
	.string "¡Tiene tanta FUERZA que puede\n"
	.string "mover hasta grandes rocas!$"

SSAnne_B1F_Room5_Text_Machoke::
	.string "MACHOKE: ¡Cho! ¡Chokecho!$"

