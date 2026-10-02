GoldenrodCity_DepartmentStore_6F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore6_EventScript_Whitney::
	lock
	faceplayer
	msgbox GoldenrodDeptStore6_Text_Whitney, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_DEPTSTORE_WHITNEY
	removeobject LOCALID_STORE_WHITNEY
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_WHITNEY
	release
	end

GoldenrodDeptStore6_Text_Whitney:
	.string "¡{PLAYER}! ¡Qué casualidad verte por\n"
	.string "aquí!\p"
	.string "Estoy comprando algo para mi MILTANK.\p"
	.string "Si quieres otro combate, ¡ven al DOJO\n"
	.string "KARATE!$"

GoldenrodCity_DepartmentStore_6F_EventScript_Jose::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_NPC_TRADE_COMPLETED, GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MACHOP, GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou, GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade, GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon, GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare
	setflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_After, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou:
	.string "¡Colecciono POKéMON! ¿Tienes un\n"
	.string "{STR_VAR_1}?\p"
	.string "¿Quieres cambiármelo por mi\n"
	.string "{STR_VAR_2}?$"

GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare:
	.string "¡Bien! ¡He conseguido un {STR_VAR_1}!\p"
	.string "¡{STR_VAR_2}, cuídate!$"

GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon:
	.string "Vaya, pues va a ser que no.\n"
	.string "Eso no es un {STR_VAR_1}.$"

GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe:
	.string "¿No quieres cambiarlo? ¡Bah!$"

GoldenrodCity_DepartmentStore_6F_Text_After:
	.string "Hola, ¿cómo está mi MACHOP?$"


GoldenrodDeptStore6_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_6FLass:
	.string "¿Escuchas el CANAL SUERTE?\p"
	.string "Dicen que, si quieres ganar, deberías\n"
	.string "intercambiar POKéMON con toda la\l"
	.string "gente posible para conseguir números\l"
	.string "ID diferentes.\p"
	.string "Pero ahora no se intercambia tanto\n"
	.string "como antes.$"

GoldenrodDeptStore_Text_6FSuperNerd:
	.string "Si te cansas, prueba las bebidas de\n"
	.string "las máquinas.\p"
	.string "A tus POKéMON les gustarán.$"

GoldenrodDeptStore_Text_6FDirectory:
	.string "¡Descansa de las compras!\p"
	.string "P5 PLAZA TRANQUILA$"
