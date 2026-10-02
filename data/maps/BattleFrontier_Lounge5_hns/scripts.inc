BattleFrontier_Lounge5_hns_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsEgg_hns
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirl_hnsEgg_hns::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman_hns::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt_hns::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy_hns::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting_hns::
	.string "¡Je, je, je!\n"
	.string "¡Yo puedo decirte lo que piensan los\l"
	.string "POKéMON sobre esto de los combates!\p"
	.string "Porfa, ¿me dejas ver tus POKéMON?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown_hns::
	.string "¡Ay!\n"
	.string "¡Qué carácter, oye!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow_hns::
	.string "Mmm…\p"
	.string "¡Dice que le gusta combatir!\n"
	.string "¡Aunque le hagan pupa!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow_hns::
	.string "Mmm…\p"
	.string "¡Dice que le gusta combatir!\n"
	.string "¡Pero que se preocupa si le hacen pupa!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow_hns::
	.string "Mmm…\p"
	.string "¡Dice que le gusta combatir!\n"
	.string "¡Pero que, si le hacen mucha\l"
	.string "pupa, se lo pensará dos veces!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow_hns::
	.string "Mmm…\p"
	.string "¡Dice que se cuida mucho!\n"
	.string "¡Y que, si le hacen pupa, no se anda\l"
	.string "con pamplinas!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow_hns::
	.string "Mmm…\p"
	.string "¡Dice que se cuida mucho!\n"
	.string "Que se preocupa si le hacen pupa,\l"
	.string "¡y aunque no se la hagan!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow_hns::
	.string "Mmm…\p"
	.string "¡Dice que se cuida mucho!\n"
	.string "¡Pero que, si le hacen mucha\l"
	.string "pupa, se lo pensará dos veces!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow_hns::
	.string "Mmm…\p"
	.string "¡Dice que le gusta reservarse!\n"
	.string "¡Y que, si le hacen pupa, no se anda\l"
	.string "con pamplinas!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow_hns::
	.string "Mmm…\p"
	.string "¡Dice que le gusta reservarse!\n"
	.string "¡Pero que se preocupa si le hacen pupa!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow_hns::
	.string "Mmm…\p"
	.string "¡Dice que le gusta reservarse! ¡Le\n"
	.string "gusta reservarse aunque le hagan pupa!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg_hns::
	.string "¡Qué tontería! ¡Los HUEVOS duermen!\n"
	.string "¡No puedo hablar con los HUEVOS!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon_hns::
	.string "¡Qué ricura!\n"
	.string "¡Esa pequeña dice que puede leerles\l"
	.string "el pensamiento a los POKéMON!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound_hns::
	.string "Me parece a mí que esa niña\n"
	.string "dice cosas la mar de profundas.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot_hns::
	.string "¿Sabes una cosa? \p"
	.string "¡Esa niña juega mucho en la casa roja!$"

