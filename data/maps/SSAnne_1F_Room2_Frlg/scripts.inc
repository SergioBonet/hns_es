SSAnne_1F_Room2_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room2_EventScript_Woman::
	msgbox SSAnne_1F_Room2_Text_CruisingAroundWorld, MSGBOX_NPC
	end

SSAnne_1F_Room2_EventScript_Ann::
	trainerbattle_single TRAINER_LASS_ANN, SSAnne_1F_Room2_Text_AnnIntro, SSAnne_1F_Room2_Text_AnnDefeat
	msgbox SSAnne_1F_Room2_Text_AnnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_EventScript_Tyler::
	trainerbattle_single TRAINER_YOUNGSTER_TYLER, SSAnne_1F_Room2_Text_TylerIntro, SSAnne_1F_Room2_Text_TylerDefeat
	msgbox SSAnne_1F_Room2_Text_TylerPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_Text_TylerIntro::
	.string "¡Me gustan los POKéMON!\n"
	.string "¿Y a ti?$"

SSAnne_1F_Room2_Text_TylerDefeat::
	.string "¡Guauu!\n"
	.string "¡Eres genial!$"

SSAnne_1F_Room2_Text_TylerPostBattle::
	.string "Seamos amigos, ¿vale?\p"
	.string "¡Y así podremos intercambiar\n"
	.string "POKéMON!$"

SSAnne_1F_Room2_Text_AnnIntro::
	.string "¡He atrapado POKéMON por todo\n"
	.string "el mundo!$"

SSAnne_1F_Room2_Text_AnnDefeat::
	.string "¡Oh, no!\n"
	.string "¡Di la vuelta al mundo por esto!$"

SSAnne_1F_Room2_Text_AnnPostBattle::
	.string "¡Les has hecho daño a mis pobres\n"
	.string "POKéMON!\p"
	.string "¡¡¡Y exijo que los cures en un\n"
	.string "CENTRO POKéMON!!!$"

SSAnne_1F_Room2_Text_CruisingAroundWorld::
	.string "¡Viajamos en crucero por todo\n"
	.string "el mundo!$"

