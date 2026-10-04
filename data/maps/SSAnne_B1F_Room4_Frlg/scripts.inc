SSAnne_B1F_Room4_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room4_EventScript_Leonard::
	trainerbattle_single TRAINER_SAILOR_LEONARD, SSAnne_B1F_Room4_Text_LeonardIntro, SSAnne_B1F_Room4_Text_LeonardDefeat
	msgbox SSAnne_B1F_Room4_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_EventScript_Duncan::
	trainerbattle_single TRAINER_SAILOR_DUNCAN, SSAnne_B1F_Room4_Text_DuncanIntro, SSAnne_B1F_Room4_Text_DuncanDefeat
	msgbox SSAnne_B1F_Room4_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_Text_LeonardIntro::
	.string "¡Ya sabes lo que dicen sobre\n"
	.string "los marineros y las peleas!$"

SSAnne_B1F_Room4_Text_LeonardDefeat::
	.string "¡Has peleado muy bien, sí, sí!$"

SSAnne_B1F_Room4_Text_LeonardPostBattle::
	.string "¡Jajaja!\n"
	.string "¿Quieres ser marinero, grumete?$"

SSAnne_B1F_Room4_Text_DuncanIntro::
	.string "¡Está en juego mi fama de\n"
	.string "marinero!$"

SSAnne_B1F_Room4_Text_DuncanDefeat::
	.string "¡Tu espíritu me ha hundido!$"

SSAnne_B1F_Room4_Text_DuncanPostBattle::
	.string "¿Viste al GURÚ de los PESCADORES\n"
	.string "en CIUDAD CARMÍN?$"

