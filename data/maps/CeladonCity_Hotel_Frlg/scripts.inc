CeladonCity_Hotel_Frlg_MapScripts::
	.byte 0

CeladonCity_Hotel_EventScript_Receptionist::
	msgbox CeladonCity_Hotel_Text_ThisHotelIsForPeople, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_Beauty::
	msgbox CeladonCity_Hotel_Text_OnVacationWithBrotherAndBoyfriend, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_BeautyBoyfriend::
	msgbox CeladonCity_Hotel_Text_WhyDidSheBringBrother, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_BeautyBrother::
	msgbox CeladonCity_Hotel_Text_SisBroughtMeOnVacation, MSGBOX_NPC
	end

CeladonCity_Hotel_Text_ThisHotelIsForPeople::
	.string "¿POKéMON?\n"
	.string "No, éste es un hotel para gente.\p"
	.string "¡Está completo!$"

CeladonCity_Hotel_Text_OnVacationWithBrotherAndBoyfriend::
	.string "Estoy de vacaciones con mi\n"
	.string "hermano y con mi novio.\p"
	.string "¡AZULONA es una bonita ciudad!$"

CeladonCity_Hotel_Text_WhyDidSheBringBrother::
	.string "¿Por qué trajo a su hermano?$"

CeladonCity_Hotel_Text_SisBroughtMeOnVacation::
	.string "¡Mi hermana me trajo de\n"
	.string "vacaciones!$"

