MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Gracias por usar el sistema de\n"
	.string "REGALO MISTERIOSO.\p"
	.string "Tu TARJETA de COMBATES lleva la cuenta\n"
	.string "de tu récord de combates contra\l"
	.string "ENTRENADORES con la misma TARJETA.\p"
	.string "Busca y combate contra ENTRENADORES\n"
	.string "que tengan la misma TARJETA que tú.\p"
	.string "Puedes consultar las clasificaciones\n"
	.string "generales leyendo las NOTICIAS.\p"
	.string "¡Anímate a probarlo!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Gracias por usar el sistema de\n"
	.string "REGALO MISTERIOSO.\p"
	.string "¡Enhorabuena!\p"
	.string "Has ganado un premio por ganar\n"
	.string "tres combates.\p"
	.string "Esperamos que esto te anime a\n"
	.string "combatir un poco más.$"
