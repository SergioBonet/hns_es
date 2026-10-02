Melemele_House_3_hns_MapScripts::
	.byte 0


Melemele_House3_Woman::
	lock
	faceplayer
	msgbox Melemele_House3_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House3_Man::
	lock
	faceplayer
	msgbox Melemele_House3_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House3_Woman_Text_0:
	.string "¡Qué tranquila es la vida en la isla!\p"
	.string "¡Y qué bien que mis nietos estén a un\n"
	.string "ratito en barco, en KANTO!$"

Melemele_House3_Man_Text_0:
	.string "¡Malditos turistas!\p"
	.string "Mi agente inmobiliario me dijo que esto\n"
	.string "sería tranquilo… pero supongo que\l"
	.string "viajar aquí es más barato que ir hasta\l"
	.string "ALOLA.$"
