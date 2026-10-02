Gate_EcruteakCity_Route38_hns_MapScripts::
	.byte 0

Route38_EventScript_Officer::
	lock
	faceplayer
	msgbox Route38_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route38_Text_EcruteakGateOfficer:
	.string "¿De dónde has dicho que eras?\p"
	.string "¿De PUEBLO PRIMAVERA?\p"
	.string "El PROF. ELM vive por allí, ¿no?\p"
	.string "Has recorrido un largo camino.$"
