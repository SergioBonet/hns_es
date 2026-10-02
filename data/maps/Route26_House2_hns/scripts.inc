Route26_House2_hns_MapScripts::
	.byte 0

Route26_House2_EventScript_Book::
	lock
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE,Route26_House2_EventScript_BookRead
	closemessage
	release
	end

Route26_House2_EventScript_BookRead::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route26_House2_EventScript_BookRead2
	closemessage
	release
	end
	
Route26_House2_EventScript_BookRead2::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex3, MSGBOX_DEFAULT
	closemessage
	release
	end

DayOfWeekSiblingsHouse_Text_Pokedex1:
	.string "Aquí hay algo escrito.\p"
	.string "¿Quieres leerlo?$"

DayOfWeekSiblingsHouse_Text_Pokedex2:
	.string "A mis hermanos y hermanas:\p"
	.string "Nos enorgullece ayudar a los\n"
	.string "entrenadores POKéMON.\p"
	.string "Cuando habléis con los entrenadores,\n"
	.string "dadles algo útil.\p"
	.string "Besos, LUNA\p"
	.string "¿Sigues leyendo?$"

DayOfWeekSiblingsHouse_Text_Pokedex3:
	.string "Lunes, LUNA RUTA 40\p"
	.string "Martes, MARTA RUTA 29\p"
	.string "Miércoles, MIGUEL LAGO DE LA FURIA\p"
	.string "Jueves, JOSUÉ RUTA 36\p"
	.string "Viernes, VICKI RUTA 32\p"
	.string "Sábado, SABINO CIUDAD ENDRINO\p"
	.string "Domingo, DOMINGO RUTA 37$"
