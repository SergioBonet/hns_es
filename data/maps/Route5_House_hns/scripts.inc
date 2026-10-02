Route5_House_hns_MapScripts::
	.byte 0

Route5_House_EventScript_Granny::
	goto_if_set FLAG_GOT_CLEANSE_TAG, Route5_House_EventScript_GrannyAfter
	msgbox Route5_House_Text_Granny1, MSGBOX_NPC
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_CLEANSE_TAG
	release
	end

Route5_House_EventScript_GrannyAfter::
	msgbox Route5_House_Text_Granny2, MSGBOX_NPC
	end

Route5_House_EventScript_Woman::
	msgbox Route5_House_Text_Woman, MSGBOX_NPC
	end

Route5_House_Text_Granny1:
	.string "¡Aaaayy!\p"
	.string "Siento que una siniestra sombra se\n"
	.string "cierne sobre ti.\p"
	.string "¡Toma esto para protegerte!$"

Route5_House_Text_Granny2:
	.string "Corrías un grave peligro, pero ahora\n"
	.string "estás a salvo.$"

Route5_House_Text_Woman:
	.string "A mi abuela le gusta protegerse\n"
	.string "contra supuestos malos espíritus.\p"
	.string "Perdona si te ha asustado.$"
