GoldenrodCity_DepartmentStore_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore1_EventScript_Receptionist::
	lock
	faceplayer
	msgbox GoldenrodDeptStor1_Text_Receptionist, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_Gentleman::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore1_EventScript_Directory::
	lock
	msgbox GoldenrodDeptStore1_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodDeptStor1_Text_Receptionist:
	.string "Éste es el CENTRO COMERCIAL de\n"
	.string "CIUDAD TRIGAL.$"

GoldenrodDeptStore1_Text_Gentleman:
	.string "El CENTRO COMERCIAL tiene buenos\n"
	.string "artículos.\p"
	.string "Pero algunos objetos sólo se\n"
	.string "consiguen en el CASINO.$"

GoldenrodDeptStore1_Text_PokefanF:
	.string "¡Me encanta ir de compras!$"

GoldenrodDeptStore1_Text_BugCatcher:
	.string "Mamá es experta en conseguir gangas.\p"
	.string "Siempre compra cosas a precios más\n"
	.string "bajos.$"

GoldenrodDeptStore1_Text_Directory:
    .string "1F SERVICE COUNTER\n"
	.string "YOU ARE HERE.\p"
    .string "2F TRAINER'S MARKET\p"
    .string "3F BATTLE COLLECTION\p"
    .string "4F MEDICINE BOX\p"
    .string "5F TM CORNER\p"
    .string "6F TRANQUIL SQUARE\p"
    .string "ROOFTOP LOOKOUT$"
