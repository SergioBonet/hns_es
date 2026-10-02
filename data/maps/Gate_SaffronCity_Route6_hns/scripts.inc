Gate_SaffronCity_Route6_hns_MapScripts::
	.byte 0

Gate_SaffronCity_Route6_EventScript_Guard::
	goto_if_eq VAR_TEMP_0, 1, Gate_SaffronCity_Route6_EventScript_Guard2
	msgbox Route6_Text_SaffronGuardWelcome, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
	end
Gate_SaffronCity_Route6_EventScript_Guard2::
	msgbox Route6_Text_SaffronGuardMagnetTrain, MSGBOX_NPC
	end

Route6_Text_SaffronGuardWelcome:
	.string "¡Bienvenidos a CIUDAD AZAFRÁN, hogar\n"
	.string "del MAGNETOTRÉN!\p"
	.string "Eso es lo que suelo decir, pero el\n"
	.string "MAGNETOTRÉN no funciona ahora.\p"
	.string "No recibe electricidad porque hay un\n"
	.string "problema en la CENTRAL ENERGÍA.$"

Route6_Text_SaffronGuardMagnetTrain:
	.string "El MAGNETOTRÉN es lo más famoso de\n"
	.string "CIUDAD AZAFRÁN.$"
