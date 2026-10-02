OlivineCity_Mart_hns_MapScripts::
	.byte 0

OlivineCity_EventScript_Trainer1::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Lass::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartLass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_MartCooltrainerF:
	.string "Do your POKéMON already know\n"
	.string "the move for carrying people\l"
	.string "across water?$"

OlivineCity_Text_MartLass:
	.string "Mi BUTTERFREE ha estado con mi novio.\p"
	.string "Y me ha traído una CARTA suya.\p"
	.string "¿Quieres saber lo que dice?\p"
	.string "Veamos… ¡No! ¡Es un secreto!$"
