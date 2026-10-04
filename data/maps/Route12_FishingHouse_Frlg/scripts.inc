Route12_FishingHouse_Frlg_MapScripts::
	.byte 0

Route12_FishingHouse_EventScript_FishingGuruBrother::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_FishingHouse_EventScript_CheckMagikarpRecord
	msgbox Route12_FishingHouse_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route12_FishingHouse_EventScript_GiveSuperRod
	msgbox Route12_FishingHouse_Text_OhThatsDisappointing
	release
	end

Route12_FishingHouse_EventScript_GiveSuperRod::
	checkitemspace ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForSuperRod
	additem ITEM_SUPER_ROD
	msgbox Route12_FishingHouse_Text_TakeThisAndFish
	msgreceiveditem Route12_FishingHouse_Text_ReceivedSuperRod, ITEM_SUPER_ROD
	setflag FLAG_GOT_SUPER_ROD
	msgbox Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe
	release
	end

Route12_FishingHouse_EventScript_NoRoomForSuperRod::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_EventScript_CheckMagikarpRecord::
	setvar VAR_0x8004, SPECIES_MAGIKARP
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoMagikarpInParty
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_OhMagikarpAllowMeToSee
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_ge VAR_RESULT, PARTY_SIZE, Route12_FishingHouse_EventScript_CancelShowMon
	special CompareMagikarpSize
	goto_if_eq VAR_RESULT, 1, Route12_FishingHouse_EventScript_NotMagikarp
	goto_if_eq VAR_RESULT, 2, Route12_FishingHouse_EventScript_NotRecordMagikarp
	goto_if_eq VAR_RESULT, 3, Route12_FishingHouse_EventScript_NewRecordMagikarp
	goto_if_eq VAR_RESULT, 4, Route12_FishingHouse_EventScript_TieRecordMagikarp
	release
	end

Route12_FishingHouse_EventScript_NoMagikarpInParty::
	msgbox Route12_FishingHouse_Text_TryFishingBringMeMagikarp
	release
	end

Route12_FishingHouse_EventScript_CancelShowMon::
	release
	end

Route12_FishingHouse_EventScript_NotMagikarp::
	msgbox Route12_FishingHouse_Text_DoesntLookLikeMagikarp
	release
	end

Route12_FishingHouse_EventScript_NotRecordMagikarp::
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HmmXInchesDoesntMeasureUp
	release
	end

Route12_FishingHouse_EventScript_TieRecordMagikarp::
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HuhXInchesSameSizeAsLast
	release
	end

Route12_FishingHouse_EventScript_NewRecordMagikarp::
	setflag FLAG_GOT_RECORD_SETTING_MAGIKARP
	msgbox Route12_FishingHouse_Text_WhoaXInchesTakeThis
	giveitem ITEM_NET_BALL
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForNetBall
	msgbox Route12_FishingHouse_Text_LookForwardToGreaterRecords
	release
	end

Route12_FishingHouse_EventScript_NoRoomForNetBall::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_EventScript_MagikarpRecordSign::
	lockall
	goto_if_set FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet
	msgbox Route12_FishingHouse_Text_BlankChartOfSomeSort
	releaseall
	end

Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet::
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_MostGiganticMagikarpXInches
	releaseall
	end

Route12_FishingHouse_Text_DoYouLikeToFish::
	.string "¡Soy hermano del GURÚ PESCADOR!\p"
	.string "¡Simplemente me encanta pescar!\p"
	.string "¿Te gusta pescar?$"

Route12_FishingHouse_Text_TakeThisAndFish::
	.string "¡Fenomenal!\n"
	.string "¡Me gusta tu estilo!\p"
	.string "¡Toma esto y pesca, anda!$"

Route12_FishingHouse_Text_ReceivedSuperRod::
	.string "¡{PLAYER} obtuvo una SUPERCAÑA\n"
	.string "del hermano del GURÚ PESCADOR!$"

Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe::
	.string "¡La pesca es una forma de vida!\n"
	.string "¡Es un arte!\p"
	.string "¡En el mar, en los ríos, da igual,\n"
	.string "hay que pescar el más grande!\p"
	.string "A ver, tengo que pedirte algo.\p"
	.string "Si consigues un MAGIKARP con\n"
	.string "esa CAÑA, me gustaría que me\l"
	.string "lo enseñaras.\p"
	.string "Pescar me gusta tanto como ver\n"
	.string "MAGIKARP enormes.$"

Route12_FishingHouse_Text_OhThatsDisappointing::
	.string "Oh... Estoy tan decepcionado...$"

Route12_FishingHouse_Text_TryFishingBringMeMagikarp::
	.string "¡Hola, {PLAYER}!\n"
	.string "¿Has estado pescando?\p"
	.string "Prueba a pescar con la SUPERCAÑA\n"
	.string "en cualquier masa de agua.\p"
	.string "Encontrarás POKéMON distintos\n"
	.string "en lugares distintos.\p"
	.string "Ah, y no olvides traerme\n"
	.string "unos MAGIKARP gigantes.$"

Route12_FishingHouse_Text_OhMagikarpAllowMeToSee::
	.string "¡Hola, {PLAYER}!\n"
	.string "¡Anda, un MAGIKARP!\p"
	.string "¡Deja, deja que lo vea!$"

Route12_FishingHouse_Text_WhoaXInchesTakeThis::
	.string "¡Guaaaau, {STR_VAR_2} cm!\p"
	.string "¡Tienes una forma muy peculiar\n"
	.string "de entender el arte de la pesca!\p"
	.string "Toma esto, por favor.$"

Route12_FishingHouse_Text_LookForwardToGreaterRecords::
	.string "¡Espero ver de ti récords aún\n"
	.string "mayores!$"

Route12_FishingHouse_Text_HuhXInchesSameSizeAsLast::
	.string "¿Mmm?\n"
	.string "¿{STR_VAR_2} cm?\p"
	.string "¡Pero si tiene el mismo tamaño\n"
	.string "que el anterior!$"

Route12_FishingHouse_Text_HmmXInchesDoesntMeasureUp::
	.string "Mmm...\n"
	.string "Este mide {STR_VAR_2} cm de largo...\p"
	.string "¡Pero si el de antes medía {STR_VAR_3} cm!$"

Route12_FishingHouse_Text_DoesntLookLikeMagikarp::
	.string "Eh... me parece a mí que eso\n"
	.string "no es un MAGIKARP.$"

Route12_FishingHouse_Text_NoRoomForGift::
	.string "¡Oh, no!\p"
	.string "¡Tenía un regalo para ti, pero no\n"
	.string "tienes sitio!$"

Route12_FishingHouse_Text_MostGiganticMagikarpXInches::
	.string "¡Madre mía, es el MAGIKARP más\n"
	.string "grande que he visto en mi vida!\p"
	.string "¡{STR_VAR_3} cm!$"

Route12_FishingHouse_Text_BlankChartOfSomeSort::
	.string "Es una especie de cuadro y\n"
	.string "está en blanco.\p"
	.string "Tiene casillas para anotar cosas.$"

