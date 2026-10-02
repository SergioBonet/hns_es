Route32_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_PokemonCenter_OnTransition	
	.byte 0

Route32_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ROUTE_32_HNS
	end

Route32_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox Route32_Pokecenter_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_PokemonCenter_EventScript_FishingGuru::
	lock
	faceplayer
	checkitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru3
	msgbox Route32_Pokecenter_Text_FishingGuruQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru2
	msgbox Route32_Pokecenter_Text_FishingGuruNo, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru2::
	msgbox Route32_Pokecenter_Text_FishingGuruYes, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route32_Pokecenter_Text_FishingGuruGiveRod, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru3::
	msgbox Route32_Pokecenter_Text_FishingGuruAfter, MSGBOX_DEFAULT
	release
	end



Route32_Pokecenter_Text_FishingGuruQuestion:
	.string "Éste es un buen sitio para pescar.\p"
	.string "¿Has visto a gente pescando? ¿Y tú?\p"
	.string "¿Quieres una de mis CAÑAS?$"

Route32_Pokecenter_Text_FishingGuruYes:
	.string "Eso está bien.\p"
	.string "¡Ahora ya puedes pescar!$"

Route32_Pokecenter_Text_FishingGuruGiveRod:
	.string "¡Pescar es genial!\p"
	.string "Si ves agua, ya sea el mar o un río,\n"
	.string "utiliza tu CAÑA.$"

Route32_Pokecenter_Text_FishingGuruNo:
	.string "¡Vaya! Me has decepcionado…$"

Route32_Pokecenter_Text_FishingGuruAfter:
	.string "Hola. ¿Están picando?$"

Route32_Pokecenter_Text_CooltrainerF:
	.string "¿Cómo equipar a mi POKéMON?\p"
	.string "Quizá con un objeto que aumente su\n"
	.string "ATAQUE…$"

