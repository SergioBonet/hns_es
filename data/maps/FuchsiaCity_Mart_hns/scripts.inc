FuchsiaCity_Mart_hns_MapScripts::
	.byte 0

FuchsiaCity_Mart_EventScript_Fisher::
	msgbox FuchsiaMart_Text_Fisher, MSGBOX_NPC
	end

FuchsiaCity_Mart_EventScript_Woman::
	msgbox FuchsiaMart_Text_CooltrainerF, MSGBOX_NPC
	end

FuchsiaMart_Text_Fisher:
	.string "La antigua ZONA SAFARI tenía\n"
	.string "recuerdos mucho mejores…$"

FuchsiaMart_Text_CooltrainerF:
	.string "La nieta del antiguo GUARDA de la ZONA\n"
	.string "SAFARI vive en la ciudad.$"
