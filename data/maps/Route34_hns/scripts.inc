Route34_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route34_OnTransition: 
	specialvar VAR_RESULT, GetDaycareState
	call_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_MapScript_EggReady
	callnative SetTimeBasedEncounters
	end	

Route34_MapScript_EggReady::
	setobjectxyperm LOCALID_ROUTE34_DAYCAREMAN, 30, 34
	return

Route34_EventScript_YoungsterSamuel::
	trainerbattle_single TRAINER_SAMUEL_HNS, Route34_Text_YoungsterSamuel_Seen, Route34_Text_YoungsterSamuel_Beaten
	msgbox Route34_Text_YoungsterSamuel_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_YoungsterIan::
	trainerbattle_single TRAINER_IAN_HNS, Route34_Text_YoungsterIan_Seen, Route34_Text_YoungsterIan_Beaten
	msgbox Route34_Text_YoungsterIan_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_CamperTodd::
	trainerbattle_single TRAINER_TODD_HNS, Route34_Text_CamperTodd_Seen, Route34_Text_CamperTodd_Beaten, Route34_EventScript_RegisterTodd
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route34_EventScript_RematchTodd
	msgbox Route34_Text_CamperTodd_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_RegisterTodd::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_ToddRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TODD_HNS
	release
	end

Route34_EventScript_RematchTodd::
	trainerbattle_rematch TRAINER_TODD_HNS, Route34_Text_ToddRematchIntro, Route34_Text_ToddRematchDefeat
	msgbox Route34_Text_ToddPostRematch, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_PicnickerGina::
	trainerbattle_single TRAINER_GINA_HNS, Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten, Route34_EventScript_RegisterGina
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route34_EventScript_RematchGina
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_RegisterGina::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_GinaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GINA_HNS
	release
	end

Route34_EventScript_RematchGina::
	trainerbattle_rematch TRAINER_GINA_HNS, Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_OfficerKeith::
	trainerbattle_single TRAINER_KEITH_HNS, Route34_Text_OfficerKeith_Seen, Route34_Text_OfficerKeith_Win
	msgbox Route34_Text_OfficerKeith_After, MSGBOX_AUTOCLOSE
	end


Route34_EventScript_PokefanMBrandon::
	trainerbattle_single TRAINER_BRANDON_HNS, Route34_Text_PokefanBrandon_Seen, Route34_Text_PokefanBrandon_Beaten
	msgbox Route34_Text_PokefanBrandon_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE_HNS, Route34_Text_CooltrainerIrene_Seen, Route34_Text_CooltrainerIrene_Beaten
	msgbox Route34_Text_CooltrainerIrene_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Jenn::
	trainerbattle_single TRAINER_JENN_HNS, Route34_Text_CooltrainerJenn_Seen, Route34_Text_CooltrainerJenn_Beaten
	msgbox Route34_Text_CooltrainerJenn_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Kate::
	trainerbattle_single TRAINER_KATE_HNS, Route34_Text_CooltrainerKate_Seen, Route34_Text_CooltrainerKate_Beaten
	msgbox Route34_Text_CooltrainerKate_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Sign1::
	lock
	msgbox Route34_Text_Sign_Route34, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign2::
	lock
	msgbox Route34_Text_Sign_DayCare, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign3::
	lock
	msgbox Route34_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Item_SoftSand::
	finditem ITEM_SOFT_SAND
	end

Route34_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end
	
Route34_EventScript_Item_Embargo::
    finditem ITEM_TM_EMBARGO
    end


Route34_Text_YoungsterSamuel_Seen:
	.string "Hey! I'm looking for MANKEY!$"

Route34_Text_YoungsterSamuel_Beaten:
	.string "Beaten by a passing stranger!$"

Route34_Text_YoungsterSamuel_After:
	.string "I'm going to train even harder.\p"
	.string "After all, I'm trying to become\n"
	.string "a GYM LEADER.$"

Route34_Text_YoungsterIan_Seen:
	.string "Soy el mejor de mi clase en lo\n"
	.string "referente a POKéMON.\p"
	.string "$"

Route34_Text_YoungsterIan_Beaten:
	.string "¡No! Hay mejores Entrenadores…$"

Route34_Text_YoungsterIan_After:
	.string "Estoy esforzándome para ser el mejor\n"
	.string "de mi clase.$"

Route34_Text_CamperTodd_Seen:
	.string "Confío en mi capacidad para criar\n"
	.string "POKéMON.\p"
	.string "¿Quieres verlo?$"

Route34_Text_CamperTodd_Beaten:
	.string "¿He fallado en mi entrenamiento?$"

Route34_Text_CamperTodd_After:
	.string "Maybe I should take one to DAY-CARE,\n"
	.string "or maybe use some items…$"

Route34_Text_ToddRegister:
	.string "Maybe I should take one to DAY-CARE,\n"
	.string "or maybe use some items…$"

Route34_Text_ToddRematchIntro:
	.string "Confío en mi capacidad para criar\n"
	.string "POKéMON.\p"
	.string "¿Quieres verlo?$"

Route34_Text_ToddRematchDefeat:
	.string "¿He fallado en mi entrenamiento?$"

Route34_Text_ToddPostRematch:
	.string "Maybe I should take one to DAY-CARE,\n"
	.string "or maybe use some items…$"

Route34_Text_GinaRegister:
	.string "Eres demasiado fuerte para practicar\n"
	.string "conmigo.$"

Route34_Text_PicnickerGina_Seen:
	.string "¿Entrenas POKéMON? Libremos un\n"
	.string "combate de prueba.\p"
	.string "$"

Route34_Text_PicnickerGina_Beaten:
	.string "¡Oh, no! No puedo ganar…$"

Route34_Text_PicnickerGina_After:
	.string "Eres demasiado fuerte para practicar\n"
	.string "conmigo.$"

Route34_Text_OfficerKeith_Seen:
	.string "Who goes there?\n"
	.string "What are you up to?$"

Route34_Text_OfficerKeith_Win:
	.string "You're a tough little kid.$"

Route34_Text_OfficerKeith_After:
	.string "Yep, nothing wrong today.\p"
	.string "Be good and stay out of trouble.$"

Route34_Text_OfficerKeith_Daytime:
	.string "Estoy buscando individuos\n"
	.string "sospechosos.$"

Route34_Text_PokefanBrandon_Seen:
	.string "I just got my POKéMON back from\n"
	.string "DAY-CARE.\p"
	.string "Let's see how much stronger it got!$"

Route34_Text_PokefanBrandon_Beaten:
	.string "¿Por qué acaba así?$"

Route34_Text_PokefanBrandon_After:
	.string "My POKéMON came back with new moves.\p"
	.string "That confounded me to no end!$"

Route34_Text_Sign_IlexForest:
	.string "ILEX FOREST\n"
	.string "THROUGH THE GATE$"

Route34_Text_Sign_Route34:
	.string "ROUTE 34\n"
	.string "GOLDENROD CITY - AZALEA TOWN\p"
	.string "ILEX FOREST SOMEWHERE BETWEEN$"

Route34_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "BERRY trees grow new BERRIES\n"
	.string "several times a day.\p"
	.string "Note which trees bear which\n"
	.string "BERRIES.$"

Route34_Text_CooltrainerIrene_Seen:
	.string "Mar: ¡Espera un momento! ¿Quién eres\n"
	.string "tú?\p"
	.string "$"

Route34_Text_CooltrainerIrene_Beaten:
	.string "IRENE: Ohhh! You're too strong!$"

Route34_Text_CooltrainerIrene_After1:
	.string "Mar: ¡Mi hermana LISA te lo hará pagar!$"

Route34_Text_CooltrainerIrene_After2:
	.string "IRENE: Isn't this beach great?\p"
	.string "It's our secret little getaway!$"

Route34_Text_CooltrainerJenn_Seen:
	.string "Mar: ¡Eh, tú! ¿Qué se te ha perdido por\n"
	.string "aquí?\p"
	.string "$"

Route34_Text_CooltrainerJenn_Beaten:
	.string "JENN: So sorry, IRENE! Dear Sis!$"

Route34_Text_CooltrainerJenn_After1:
	.string "ILDA: ¡No bajes la guardia! ¡Mi hermana\n"
	.string "LISA es fuerte!$"

Route34_Text_CooltrainerJenn_After2:
	.string "JENN: Sunlight makes your body\n"
	.string "stronger.$"

Route34_Text_CooltrainerKate_Seen:
	.string "LISA: Seguro que te has portado muy\n"
	.string "bien con mis hermanas, ¿no?\p"
	.string "$"

Route34_Text_CooltrainerKate_Beaten:
	.string "LISA: ¡He perdido! ¡Increíble!$"

Route34_Text_CooltrainerKate_GiveSoftSand:
	.string "LISA: Eres muy fuerte. No pude hacer\n"
	.string "nada.\p"
	.string "Toma. Te lo mereces.\p"
	.string "$"

Route34_Text_CooltrainerKate_After:
	.string "KATE: I'm sorry we jumped you.\p"
	.string "We never expected anyone to find\n"
	.string "us here. You sure startled us.$"


Route34_Text_Sign_DayCare:
	.string "DAY-CARE\p"
	.string "LET US RAISE YOUR POKéMON FOR YOU!$"
