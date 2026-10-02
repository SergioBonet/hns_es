GoldenrodCity_BillsHouse_hns_MapScripts::
	.byte 0

GoldenrodCity_BillsHouse_EventScript_Sister::
	lock
	faceplayer
	msgbox BillHouse_Text_SisterStorageSystem, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_SYS_PC_BILL, GoldenrodCity_BillsHouse_EventScript_Mom2
	msgbox BillHouse_Text_MomBeforeEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom2::
	msgbox BillHouse_Text_MomAfterEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_EEVEE, GoldenrodCity_BillsHouse_EventScript_Bill_Eevee
	msgbox BillHouse_Text_PopWontWork, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill_Eevee::
	msgbox BillHouse_Text_TakeThisEevee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_BillsHouse_EventScript_Bill_Refused
	msgbox BillHouse_Text_CountingOnYou, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EEVEE
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	givenamedmon 3
	call Common_EventScript_GiftMonNamed

    

	setflag FLAG_GOT_EEVEE
	msgbox BillHouse_Text_EeveeMayEvolve, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_BillsHouse_EventScript_Bill_Refused::
	msgbox BillHouse_Text_NoEevee, MSGBOX_DEFAULT
	closemessage
	release
	end

BillHouse_Text_TakeThisEevee:
	.string "BILL: ¡Hola, {PLAYER}! Hazme un favor y\n"
	.string "llévate este EEVEE.\p"
	.string "Me lo dejaron a mi cargo mientras\n"
	.string "estaba fuera trabajando en mi\l"
	.string "sistema.\p"
	.string "Alguien tiene que cuidarlo, pero a mí\n"
	.string "no me gusta salir.\p"
	.string "¿Puedo contar contigo para que\n"
	.string "juegues con él, {PLAYER}?$"

BillHouse_Text_CountingOnYou:
	.string "BILL: ¡Sabía que aceptarías!\p"
	.string "¡Vamos! ¡Tú sí que vales!\p"
	.string "Bueno, cuento contigo.\p"
	.string "¡Cuídalo bien!$"

BillHouse_Text_ReceivedEevee:
	.string "¡{PLAYER} recibió a EEVEE!$"

BillHouse_Text_EeveeMayEvolve:
	.string "BILL: ELM dice que EEVEE evoluciona\n"
	.string "en formas nuevas y desconocidas.$"

BillHouse_Text_PartyFull:
	.string "No, espera. No puedes llevar más\n"
	.string "POKéMON.$"

BillHouse_Text_NoEevee:
	.string "¡Oh…! ¿Qué podemos hacer ahora?$"

BillHouse_Text_PopWontWork:
	.string "BILL: Mi padre no trabaja. Lo único que\n"
	.string "hace es holgazanear.\p"
	.string "Es que no da ni golpe…$"

BillHouse_Text_MomBeforeEcruteak:
	.string "Anda, ¿coleccionas POKéMON? Mi hijo\p"
	.string "BILL es todo un experto.\p"
	.string "Le han llamado del CENTRO POKéMON de\n"
	.string "CIUDAD IRIS.\p"
	.string "Mi marido fue al CASINO sin que le\n"
	.string "llamara nadie…$"

BillHouse_Text_MomAfterEcruteak:
	.string "Mi marido era conocido como un\p"
	.string "POKéMANÍACO. BILL ha debido de seguir\n"
	.string "los pasos de su padre.$"

BillHouse_Text_SisterUsefulNumber:
	.string "¿Entrenas POKéMON? Tengo un número\n"
	.string "de teléfono que te será útil.$"

BillHouse_Text_RecordedBillsNumber:
	.string "{PLAYER} grabó el n.º de BILL.$"

BillHouse_Text_SisterRefusedNumber:
	.string "Mi hermano creó el Sistema de\p"
	.string "Almacenamiento de POKéMON del PC.\p"
	.string "Te iba a dar el teléfono de BILL…$"

BillHouse_Text_SisterPhoneFull:
	.string "No puedes grabar ningún número más.$"

BillHouse_Text_SisterStorageSystem:
	.string "Mi hermano BILL creó el Sistema de\p"
	.string "Almacenamiento de los POKéMON.$"
