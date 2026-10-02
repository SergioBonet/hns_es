EventScript_MomGiftCall_Item::
	lockall
	pokenavcall Mom_Text_GiftCall_Item
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

EventScript_MomGiftCall_Berry::
	lockall
	pokenavcall Mom_Text_GiftCall_Berry
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

EventScript_MomGiftCall_Decoration::
	lockall
	pokenavcall Mom_Text_GiftCall_Decoration
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

Mom_Text_GiftCall_Item:
	.string "MAMÁ: ¡Hola, cariño!\p"
	.string "¡Te he comprado algo bonito con tus\n"
	.string "ahorros!\p"
	.string "Te lo he enviado al PC. ¡Cuídate!$"

Mom_Text_GiftCall_Berry:
	.string "MAMÁ: ¡Hola, cariño!\p"
	.string "¡He encontrado unas BAYAS muy buenas\n"
	.string "para ti en la tienda!\p"
	.string "Te las he enviado al PC. ¡Cuídate!$"

Mom_Text_GiftCall_Decoration:
	.string "MAMÁ: ¡Hola, cariño!\p"
	.string "¡Te he comprado un POKé MUÑECO muy\n"
	.string "mono para tu habitación!\p"
	.string "Mira tu DECORACIÓN cuando vuelvas a\n"
	.string "casa. ¡Cuídate!$"
