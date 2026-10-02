AlolaWater_hns_MapScripts::
	.byte 0


Alola_MelemeleSea_TrainerBattleSwimmer::
	trainerbattle_single TRAINER_MELEMELE_SWIMMER_2_HNS, Alola_MelemeleSea_TrainerBattleSwimmer_Text_0, Alola_MelemeleSea_TrainerBattleSwimmer_Text_1
	msgbox Alola_MelemeleSea_TrainerBattleSwimmer_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_MelemeleSea_TrainerBattleSwimmer_Text_0:
	.string "¡Cuánto mar abierto!$"

Alola_MelemeleSea_TrainerBattleSwimmer_Text_1:
	.string "¡Ay! Me ha dado un tirón…$"

Alola_MelemeleSea_TrainerBattleSwimmer_Text_2:
	.string "Aquí hay corrientes muy fuertes.\n"
	.string "¡Creo que atraen a POKéMON fuertes!$"
