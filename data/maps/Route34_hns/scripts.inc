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
	.string "¡Eh! ¡Estoy buscando MANKEY!$"

Route34_Text_YoungsterSamuel_Beaten:
	.string "¡Vencido por un desconocido que\n"
	.string "pasaba por aquí!$"

Route34_Text_YoungsterSamuel_After:
	.string "Voy a entrenar aún más.\p"
	.string "Al fin y al cabo, quiero ser LÍDER de\n"
	.string "GIMNASIO.$"

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
	.string "Quizá debería llevar uno a la\n"
	.string "GUARDERÍA, o usar algunos objetos…$"

Route34_Text_ToddRegister:
	.string "Quizá debería llevar uno a la\n"
	.string "GUARDERÍA, o usar algunos objetos…$"

Route34_Text_ToddRematchIntro:
	.string "Confío en mi capacidad para criar\n"
	.string "POKéMON.\p"
	.string "¿Quieres verlo?$"

Route34_Text_ToddRematchDefeat:
	.string "¿He fallado en mi entrenamiento?$"

Route34_Text_ToddPostRematch:
	.string "Quizá debería llevar uno a la\n"
	.string "GUARDERÍA, o usar algunos objetos…$"

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
	.string "¿Quién va? ¿Qué tramas?$"

Route34_Text_OfficerKeith_Win:
	.string "Eres un chaval muy duro.$"

Route34_Text_OfficerKeith_After:
	.string "Sí, hoy todo está en orden.\p"
	.string "Pórtate bien y no te metas en líos.$"

Route34_Text_OfficerKeith_Daytime:
	.string "Estoy buscando individuos\n"
	.string "sospechosos.$"

Route34_Text_PokefanBrandon_Seen:
	.string "Acaban de devolverme mi POKéMON de la\n"
	.string "GUARDERÍA.\p"
	.string "¡A ver cuánto más fuerte se ha hecho!$"

Route34_Text_PokefanBrandon_Beaten:
	.string "¿Por qué acaba así?$"

Route34_Text_PokefanBrandon_After:
	.string "Mi POKéMON ha vuelto con movimientos\n"
	.string "nuevos.\p"
	.string "¡Me ha dejado de lo más\n"
	.string "desconcertado!$"

Route34_Text_Sign_IlexForest:
	.string "ENCINAR\n"
	.string "AL OTRO LADO DE LA PUERTA$"

Route34_Text_Sign_Route34:
	.string "RUTA 34\n"
	.string "CIUDAD TRIGAL - PUEBLO AZALEA\p"
	.string "ENCINAR EN ALGÚN PUNTO INTERMEDIO$"

Route34_Text_TrainerTips:
	.string "PISTAS para ENTRENADORES\p"
	.string "Los árboles de BAYAS dan BAYAS\n"
	.string "nuevas varias veces al día.\p"
	.string "Apunta qué árboles dan qué BAYAS.$"

Route34_Text_CooltrainerIrene_Seen:
	.string "Mar: ¡Espera un momento! ¿Quién eres\n"
	.string "tú?\p"
	.string "$"

Route34_Text_CooltrainerIrene_Beaten:
	.string "IRENE: ¡Ooooh! ¡Eres demasiado\n"
	.string "fuerte!$"

Route34_Text_CooltrainerIrene_After1:
	.string "Mar: ¡Mi hermana LISA te lo hará pagar!$"

Route34_Text_CooltrainerIrene_After2:
	.string "IRENE: ¿A que esta playa es genial?\p"
	.string "¡Es nuestro pequeño escondite\n"
	.string "secreto!$"

Route34_Text_CooltrainerJenn_Seen:
	.string "Mar: ¡Eh, tú! ¿Qué se te ha perdido por\n"
	.string "aquí?\p"
	.string "$"

Route34_Text_CooltrainerJenn_Beaten:
	.string "JENN: ¡Lo siento mucho, IRENE!\n"
	.string "¡Hermanita!$"

Route34_Text_CooltrainerJenn_After1:
	.string "ILDA: ¡No bajes la guardia! ¡Mi hermana\n"
	.string "LISA es fuerte!$"

Route34_Text_CooltrainerJenn_After2:
	.string "JENN: La luz del sol hace más fuerte el\n"
	.string "cuerpo.$"

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
	.string "KATE: Siento que te hayamos asaltado.\p"
	.string "No esperábamos que nadie nos\n"
	.string "encontrara aquí. Menudo susto nos\l"
	.string "has dado.$"


Route34_Text_Sign_DayCare:
	.string "GUARDERÍA\p"
	.string "¡DEJA QUE CRIEMOS A TUS POKéMON!$"
