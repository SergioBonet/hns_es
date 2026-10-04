SSAnne_Kitchen_Frlg_MapScripts::
	.byte 0

SSAnne_Kitchen_EventScript_Chef1::
	msgbox SSAnne_Kitchen_Text_BusyOutOfTheWay, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef2::
	msgbox SSAnne_Kitchen_Text_SawOddBerryInTrash, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef3::
	msgbox SSAnne_Kitchen_Text_SoBusyImDizzy, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef4::
	lock
	faceplayer
	msgbox SSAnne_Kitchen_Text_IAmLeChefMainCourseIs
	random 3
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, SSAnne_Kitchen_EventScript_SalmonDuSalad
	call_if_eq VAR_0x8008, 1, SSAnne_Kitchen_EventScript_EelsAuBarbecue
	call_if_eq VAR_0x8008, 2, SSAnne_Kitchen_EventScript_PrimeBeefsteak
	release
	end

SSAnne_Kitchen_EventScript_SalmonDuSalad::
	msgbox SSAnne_Kitchen_Text_SalmonDuSalad
	return

SSAnne_Kitchen_EventScript_EelsAuBarbecue::
	msgbox SSAnne_Kitchen_Text_EelsAuBarbecue
	return

SSAnne_Kitchen_EventScript_PrimeBeefsteak::
	msgbox SSAnne_Kitchen_Text_PrimeBeefsteak
	return

SSAnne_Kitchen_EventScript_Chef5::
	msgbox SSAnne_Kitchen_Text_PeelSpudsEveryDay, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef6::
	msgbox SSAnne_Kitchen_Text_HearAboutSnorlaxItsAGlutton, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef7::
	msgbox SSAnne_Kitchen_Text_OnlyGetToPeelOnions, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_BusyOutOfTheWay::
	.string "¡Hola, peque!\n"
	.string "¡Ahora estamos ocupados!\l"
	.string "¡Fuera de aquí!$"

SSAnne_Kitchen_Text_SawOddBerryInTrash::
	.string "He visto una BAYA muy rara en la\n"
	.string "basura. No sé de qué tipo será...$"

SSAnne_Kitchen_Text_SoBusyImDizzy::
	.string "¡Estoy tan ocupado que me estoy\n"
	.string "mareando!$"

SSAnne_Kitchen_Text_PeelSpudsEveryDay::
	.string "¿Por qué? ¿Por qué yo?\p"
	.string "¡Me paso todo el día pelando\n"
	.string "patatas!$"

SSAnne_Kitchen_Text_HearAboutSnorlaxItsAGlutton::
	.string "¿Has oído hablar de SNORLAX?\p"
	.string "¡Se pasa todo el día comiendo\n"
	.string "y durmiendo!$"

SSAnne_Kitchen_Text_OnlyGetToPeelOnions::
	.string "Sniff...sniff...\p"
	.string "Yo sólo pelo cebollas...\n"
	.string "Sniff...$"

SSAnne_Kitchen_Text_IAmLeChefMainCourseIs::
	.string "¡Ejem!\n"
	.string "¡Por algo soy el CHEF!\p"
	.string "El menú es:$"

SSAnne_Kitchen_Text_SalmonDuSalad::
	.string "¡Ensalada de salmón!\p"
	.string "¡Pero puede que los clientes se\n"
	.string "quejen de tanto repetir pescado!$"

SSAnne_Kitchen_Text_EelsAuBarbecue::
	.string "¡Anguilas a la barbacoa!\p"
	.string "¡Me temo que los clientes se van\n"
	.string "a amotinar!$"

SSAnne_Kitchen_Text_PrimeBeefsteak::
	.string "¡Filetes de ternera de primera!\n"
	.string "Pero ¿tengo bastantes filetes\l"
	.string "para todos?$"

