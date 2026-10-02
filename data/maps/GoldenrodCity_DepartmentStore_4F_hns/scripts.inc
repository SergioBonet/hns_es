GoldenrodCity_DepartmentStore_4F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore4_EventScript_Cooltrainer::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FCooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_GBAKid::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FGameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_4FCooltrainerM:
	.string "Me encantan los POKéMON fuertes.\p"
	.string "Les doy PROTEÍNA para mejorar su\n"
	.string "ATAQUE.$"

GoldenrodDeptStore_Text_4FBugCatcher:
	.string "El HIERRO mejora su DEFENSA.$"

GoldenrodDeptStore_Text_4FGameboyKid:
	.string "Corrían rumores de que algunos\n"
	.string "POKéMON solo evolucionan si se\l"
	.string "intercambian con un cable Game Link.\p"
	.string "Bah…\p"
	.string "¡Menuda desinformación!\p"
	.string "Conozco algunos de los POKéMON de los\n"
	.string "rumores: MACHOKE, KADABRA, HAUNTER y…\l"
	.string "GRAVELER, pero todos evolucionan\l"
	.string "subiendo de nivel.$"

GoldenrodDeptStore4_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore4_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore4_Pokemart:
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

GoldenrodDeptStore_Text_4FDirectory:
	.string "¡Fortalecemos a tus POKéMON!\p"
	.string "P3 BOTIQUÍN$"
