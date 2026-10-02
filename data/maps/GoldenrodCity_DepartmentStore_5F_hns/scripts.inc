GoldenrodCity_DepartmentStore_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0


GoldenrodDeptStore5_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Girl::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_RETURN, GoldenrodDeptStore5_EventScript_Receptionist_Already
	msgbox GoldenrodDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn
	msgbox GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn::
	giveitem ITEM_TM_RETURN
	setflag FLAG_GOT_RETURN
	msgbox GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_Already::
	msgbox GoldenrodDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_5FReceptionistOhYourMon:
	.string "Te doy la bienvenida.\p"
	.string "¡Oh, tu POKéMON…!\p"
	.string "$"

GoldenrodDeptStore_Text_5FReceptionistWait:
	.string "¡Espera, si ya te he dado esa MT!$"

GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "Mmmm…\n"
	.string "No está mal, pero tampoco muy bien.\p"
	.string "Tendrías que esforzarte un\n"
	.string "poco más, ¿no te parece?$"

GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect:
	.string "Está muy unido a ti.\p"
	.string "Este movimiento sería perfecto para\n"
	.string "vosotros.$"

GoldenrodDeptStore_Text_5FLass:
	.string "Durante el día viene una señora a ver\n"
	.string "los POKéMON.\p"
	.string "¡Y hasta regala MT!$"

GoldenrodDeptStore_Text_5FPokefanM:
	.string "No puedes cambiar el nombre de un\p"
	.string "POKéMON que has intercambiado.\p"
	.string "El nombre refleja los sentimientos del\n"
	.string "entrenador original.$"

GoldenrodDeptStore_Text_Girl:
	.string "¡La señora me dio RETRIBUCIÓN! ¡Mis\n"
	.string "POKéMON deben de quererme mucho!$"

GoldenrodDeptStore5_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore5_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore5_Pokemart:
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_NATURAL_GIFT
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_TM_SOLAR_BEAM
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_FOCUS_BLAST
	pokemartlistend


GoldenrodDeptStore_Text_5FDirectory:
	.string "Personaliza a tus POKéMON\p"
	.string "P4 TIENDA DE MT$"
