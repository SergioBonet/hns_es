Route28_House_hns_MapScripts::
	.byte 0

Route28House_EventScript_Celebrity::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_STEEL_WING, Route28House_EventScript_CelebrityAfter
	msgbox Route28House_Text_Celebrity1, MSGBOX_NPC
	giveitem ITEM_TM_STEEL_WING
	setflag FLAG_GOT_TM_STEEL_WING
Route28House_EventScript_CelebrityAfter::
	msgbox Route28House_Text_Celebrity2, MSGBOX_NPC
	release
	end

Route28House_Text_Celebrity1:
	.string "¡Pues vaya! Me encontraste.\p"
	.string "Por favor, no se lo digas a nadie.\p"
	.string "Te daré esto si me guardas el secreto.\n"
	.string "¿Vale?$"

Route28House_Text_Celebrity2:
	.string "Es muy duro ser famoso.\p"
	.string "Todo el mundo me persigue.\p"
	.string "Sólo quiero que me dejen en paz…$"

Route28House_Text_Fearow:
	.string "FEAROW: ¡Fearow!$"

