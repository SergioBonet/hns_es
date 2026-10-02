SSAqua_RoomSE_hns_MapScripts::
	.byte 0

SSAqua_RoomSE_EventScript_Colin::
	trainerbattle_single TRAINER_COLIN_HNS, SSAqua_RoomSE_Text_PokefanmColinSeen, SSAqua_RoomSE_Text_PokefanmColinBeaten
	msgbox SSAqua_RoomSE_Text_PokefanmColinAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Meg::
	trainerbattle_double TRAINER_MEG_AND_PEG_HNS, SSAqua_RoomSE_Text_TwinsMegandpeg1Seen, SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg1After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Peg::
	trainerbattle_double TRAINER_MEG_AND_PEG_HNS, SSAqua_RoomSE_Text_TwinsMegandpeg2Seen, SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg2After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_Text_PokefanmColinSeen:
	.string "¡Hola, peque! ¿Quieres luchar?$"

SSAqua_RoomSE_Text_PokefanmColinBeaten:
	.string "¡Eres fuerte!$"

SSAqua_RoomSE_Text_PokefanmColinAfter:
	.string "¿Viajas sin compañía? ¿Tu madre no\n"
	.string "está preocupada?$"

SSAqua_RoomSE_Text_TwinsMegandpeg1Seen:
	.string "¿Crees que soy una nena? ¡No es\n"
	.string "justo!$"

SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten:
	.string "¡Oh! ¡Perdimos!$"

SSAqua_RoomSE_Text_TwinsMegandpeg1After:
	.string "¡No deberías llamar nenas a las\n"
	.string "chicas!$"

SSAqua_RoomSE_Text_TwinsMegandpeg2Seen:
	.string "¡No soy una nena!\p"
	.string "¡Y no deberías llamar así a una dama!$"

SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten:
	.string "¡Oh! ¡Perdimos!$"

SSAqua_RoomSE_Text_TwinsMegandpeg2After:
	.string "A veces, los niños son más listos que\n"
	.string "los adultos.$"
