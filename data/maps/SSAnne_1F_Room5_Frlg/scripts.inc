SSAnne_1F_Room5_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room5_EventScript_Arthur::
	trainerbattle_single TRAINER_GENTLEMAN_ARTHUR, SSAnne_1F_Room5_Text_ArthurIntro, SSAnne_1F_Room5_Text_ArthurDefeat
	msgbox SSAnne_1F_Room5_Text_ArthurPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room5_Text_ArthurIntro::
	.string "¡Descarado!\n"
	.string "¡¿Cómo te atreves a entrar así?!$"

SSAnne_1F_Room5_Text_ArthurDefeat::
	.string "¡Bah! ¡Qué niño más maleducado!\n"
	.string "¡No tienes ni un poco de cortesía!$"

SSAnne_1F_Room5_Text_ArthurPostBattle::
	.string "¡Quiero que me dejen en paz!\n"
	.string "¡Fuera de aquí!$"

