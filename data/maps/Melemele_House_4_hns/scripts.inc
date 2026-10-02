Melemele_House_4_hns_MapScripts::
	.byte 0


Melemele_House4_Man::
	lock
	faceplayer
	msgbox Melemele_House4_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House4_Woman::
	lock
	faceplayer
	msgbox Melemele_House4_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House4_Man_Text_0:
	.string "¡Estamos de vacaciones en las ISLAS\n"
	.string "ALOLA!\p"
	.string "¡Es igual que la región de ALOLA, pero\n"
	.string "más cerca de KANTO!\p"
	.string "¡Me he ahorrado un montón en el viaje!$"

Melemele_House4_Woman_Text_0:
	.string "Mi novio me dijo que íbamos a ALOLA…\p"
	.string "Yo pensaba que sería la región de\n"
	.string "ALOLA, no unas islitas frente a la\l"
	.string "costa de KANTO.$"
