CianwoodHouse2_hns_MapScripts::
	.byte 0

CianwoodHouse2_EventScript_Teacher::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Twin::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTwin, MSGBOX_DEFAULT
	closemessage
	release
	end
	
CianwoodCity_Text_LugiaHouseTeacher:
	.string "¿Vienes de CIUDAD OLIVO?\p"
	.string "¿Te acuerdas de las cuatro islas del\n"
	.string "camino?\p"
	.string "Dicen que en ellas se esconde una\n"
	.string "mítica criatura marina.$"

CianwoodCity_Text_LugiaHouseLass:
	.string "Dicen que sólo puedes verla si tienes\n"
	.string "un ALA PLATEADA.\p"
	.string "Debe de tener la misma esencia que la\n"
	.string "criatura.$"

CianwoodCity_Text_LugiaHouseTwin:
	.string "He oído que los remolinos que hay\n"
	.string "alrededor de las islas son causados\l"
	.string "por una criatura marina.\p"
	.string "Necesitarás una habilidad especial\n"
	.string "para sortearlos.$"
