GoldenrodCity_House3_hns_MapScripts::
	.byte 0

GoldenrodCity_House3_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House3_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_Twin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodHappinessRater_Text_PokefanM:
	.string "No dejo de perder en los combates y\n"
	.string "mis POKéMON acaban desmayándose…\p"
	.string "Quizá sea ésa la razón por la que no\n"
	.string "les gusto…$"

GoldenrodHappinessRater_Text_Twin:
	.string "¡Si uso un objeto con mi POKéMON, se\n"
	.string "pone contento!$"
