SafariZoneGate_hns_MapScripts::
	.byte 0

SafariZoneGate_EventScript_Trigger::
	setflag FLAG_VISITED_SAFARI_ZONE_GATE
	setvar VAR_SAFARI_ZONE_GATE_STATE, 3
	end

SafariZoneGate_EventScript_BackupTrigger::
	setflag FLAG_VISITED_SAFARI_ZONE_GATE
	setvar VAR_TEMP_0, 1
	end

SafariZoneGate_EventScript_WorkerM::
	lock
	faceplayer
	msgbox SafariZone_Text_ForeignFeeling, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_EventScript_Silent::
	lock
	faceplayer
	msgbox SafariZone_Text_SilentNPC, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_EventScript_Kangaskhan::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KANGASKHAN, CRY_MODE_NORMAL
	msgbox SafariZone_Text_Kangaskhan, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SafariZoneGate_EventScript_Engineer::
	lock
	faceplayer
	msgbox SafariZone_Text_JigglypuffTrainer, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_EventScript_Girl::
	lock
	faceplayer
	msgbox SafariZone_Text_FirstCatch, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_EventScript_SlowpokeLady::
	lock
	faceplayer
	msgbox SafariZone_Text_SlowpokeFan, MSGBOX_DEFAULT
	closemessage
	release
	end


SafariZone_Text_ForeignFeeling:
	.string "La ZONA SAFARI… Me hace sentir como\n"
	.string "si estuviera en un país extranjero.\p"
	.string "Me produce una sensación extraña.$"

SafariZone_Text_SilentNPC:
	.string "… (Yo no soy de muchas palabras.)$"

SafariZone_Text_Kangaskhan:
	.string "KANGASKHAN: ……$"

SafariZone_Text_JigglypuffTrainer:
	.string "¡La ZONA SAFARI es un lugar de lo más\n"
	.string "entretenido!\p"
	.string "He estado corriendo como un loco\n"
	.string "detrás de los POKéMON.\p"
	.string "Pero al JIGGLYPUFF que me acompaña\n"
	.string "no le hace mucha gracia eso y se ha\l"
	.string "enfurruñado.$"

SafariZone_Text_FirstCatch:
	.string "¡He decidido que mi primer POKéMON lo\n"
	.string "capturaré en la ZONA SAFARI!$"

SafariZone_Text_SlowpokeFan:
	.string "Hay muchos POKéMON entre los que\n"
	.string "elegir, pero nada supera lo mono que\l"
	.string "es SLOWPOKE.\p"
	.string "¡La gente suele decirme que me\n"
	.string "parezco a uno!$"

SafariZone_Text_CustomSystem:
	.string "Puede que tengas la impresión de que\n"
	.string "hay un sistema sofisticado para\l"
	.string "personalizar la ZONA SAFARI, ¿verdad?\p"
	.string "La verdad es que…$"

SafariZone_Text_Sign:
	.string "ZONA SAFARI\n"
	.string "Aquí todo es emocionante.\p"
	.string "¡Ven cuando quieras y vive lo salvaje!$"


SafariZoneGate_EventScript_IncenseClerk::
	goto_if_set FLAG_FINITE_TMS, SafariZoneGate_EventScript_IncenseClerkFinite
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SafariZoneGate_Pokemart_Incenses
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SafariZoneGate_Pokemart_Incenses:
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_NONE
	release
	end


SafariZoneGate_EventScript_IncenseClerkFinite::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SafariZoneGate_Pokemart_Incenses2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SafariZoneGate_Pokemart_Incenses2:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_NONE
	release
	end

SafariZoneGate_EventScript_VitaminGuru::
	lock
	faceplayer
	message SafariZoneGate_Text_VitaminGuruSellWhatYouNeed
	waitmessage
	pokemart SafariZoneGate_Pokemart_VitaminGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SafariZoneGate_Pokemart_VitaminGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end


SafariZoneGate_Text_VitaminGuruSellWhatYouNeed:
	.string "¡Soy CURRO!\n"
	.string "¡Se me va la olla y te vendo todo\l"
	.string "lo que necesitas barato, barato!$"

