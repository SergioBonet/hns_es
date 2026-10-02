SSAqua_RoomNNE_hns_MapScripts::
	.byte 0

SSAqua_RoomNNE_EventScript_Sean::
	trainerbattle_single TRAINER_SEAN_HNS, SSAqua_RoomNNE_Text_CooltrainermSeanSeen, SSAqua_RoomNNE_Text_CooltrainermSeanBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL_HNS, SSAqua_RoomNNE_Text_CooltrainerfCarolSeen, SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_Text_CooltrainermSeanSeen:
	.string "Voy a KANTO a ponerme a prueba.$"

SSAqua_RoomNNE_Text_CooltrainermSeanBeaten:
	.string "¡Quería ganar!$"

SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle:
	.string "Los Entrenadores de Johto pueden\n"
	.string "luchar contra los Líderes de Kanto.$"

SSAqua_RoomNNE_Text_CooltrainerfCarolSeen:
	.string "¡Me entreno para ser la CAMPEONA!$"

SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten:
	.string "¿En qué somos tan diferentes?$"

SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle:
	.string "¡Te ganaré un día de éstos!$"
