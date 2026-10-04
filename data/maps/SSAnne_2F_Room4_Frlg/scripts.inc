SSAnne_2F_Room4_Frlg_MapScripts::
	.byte 0

SSAnne_2F_Room4_EventScript_Lamar::
	trainerbattle_single TRAINER_GENTLEMAN_LAMAR, SSAnne_2F_Room4_Text_LamarIntro, SSAnne_2F_Room4_Text_LamarDefeat
	msgbox SSAnne_2F_Room4_Text_LamarPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_EventScript_Dawn::
	trainerbattle_single TRAINER_LASS_DAWN, SSAnne_2F_Room4_Text_DawnIntro, SSAnne_2F_Room4_Text_DawnDefeat
	msgbox SSAnne_2F_Room4_Text_DawnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_Text_LamarIntro::
	.string "¿Qué?\n"
	.string "Estoy esperando aquí a mis amigos.$"

SSAnne_2F_Room4_Text_LamarDefeat::
	.string "¡Te saludo con respeto!$"

SSAnne_2F_Room4_Text_LamarPostBattle::
	.string "Dicen que aquí hay unos fósiles\n"
	.string "muy raros.$"

SSAnne_2F_Room4_Text_DawnIntro::
	.string "No creo haberte visto en la fiesta.$"

SSAnne_2F_Room4_Text_DawnDefeat::
	.string "¡Tranquilo!$"

SSAnne_2F_Room4_Text_DawnPostBattle::
	.string "¡Oh, adoro a tus POKéMON fuertes!\n"
	.string "¡Oh, cómo te los envidio!$"

