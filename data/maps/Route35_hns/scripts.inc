Route35_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route35_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route35_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

Route35_EventScript_CamperIvan::
	trainerbattle_single TRAINER_IVAN_HNS, Route35_Text_CamperIvanSeen, Route35_Text_CamperIvanBeaten
	msgbox Route35_Text_CamperIvanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_CamperElliot::
	trainerbattle_single TRAINER_ELLIOT_HNS, Route35_Text_CamperElliotSeen, Route35_Text_CamperElliotBeaten
	msgbox Route35_Text_CamperElliotAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerBrooke::
	trainerbattle_single TRAINER_BROOKE_HNS, Route35_Text_PicnickerBrookeSeen, Route35_Text_PicnickerBrookeBeaten
	msgbox Route35_Text_PicnickerBrookeAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerKim::
	trainerbattle_single TRAINER_KIM_HNS, Route35_Text_PicnickerKimSeen, Route35_Text_PicnickerKimBeaten
	msgbox Route35_Text_PicnickerKimAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BirdKeeperBryan::
	trainerbattle_single TRAINER_BRYAN_HNS, Route35_Text_BirdKeeperBryanSeen, Route35_Text_BirdKeeperBryanBeaten
	msgbox Route35_Text_BirdKeeperBryanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_JugglerIrwin::
	trainerbattle_single TRAINER_IRWIN_HNS, Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten, Route35_EventScript_RegisterIrwin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchIrwin
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RegisterIrwin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_IrwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_IRWIN_HNS
	release
	end

Route35_EventScript_RematchIrwin::
	trainerbattle_rematch TRAINER_IRWIN_HNS, Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BugCatcherArnie::
	trainerbattle_single TRAINER_ARNIE_HNS, Route35_Text_BugCatcherArnieSeen, Route35_Text_BugCatcherArnieBeaten, Route35_EventScript_RegisterArnie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchArnie
	msgbox Route35_Text_BugCatcherArnieAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RegisterArnie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_ArnieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ARNIE_HNS
	release
	end

Route35_EventScript_RematchArnie::
	trainerbattle_rematch TRAINER_ARNIE_HNS, Route35_Text_ArnieRematchIntro, Route35_Text_ArnieRematchDefeat
	msgbox Route35_Text_ArniePostRematch, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_FirebreatherWalt::
	trainerbattle_single TRAINER_WALT_HNS, Route35_Text_FirebreatherWaltSeen, Route35_Text_FirebreatherWaltBeaten
	msgbox Route35_Text_FirebreatherWaltAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PolicemanDirk::
	trainerbattle_single TRAINER_DIRK_HNS, Route35_Text_OfficerDirkSeen, Route35_Text_OfficerDirkBeaten
	msgbox Route35_Text_OfficerDirkAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Sign1::
	lock
	msgbox Route35_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Sign2::
	lock
	msgbox Route35_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Item_Payback::
	finditem ITEM_TM_PAYBACK
	end

Route35_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route35_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

Route35_Text_CamperIvanSeen:
	.string "He estado cogiendo datos de POKéMON\p"
	.string "de mi radio. Creo que soy bueno.$"

Route35_Text_CamperIvanBeaten:
	.string "¡Me rindo!$"

Route35_Text_CamperIvanAfter:
	.string "La música de la radio cambia el ánimo\n"
	.string "de los POKéMON salvajes.$"

Route35_Text_CamperElliotSeen:
	.string "Le voy a demostrar a mi novia lo bueno\n"
	.string "que soy.$"

Route35_Text_CamperElliotBeaten:
	.string "Ojalá hubieras perdido tú…$"

Route35_Text_CamperElliotAfter:
	.string "Me humillaste delante de mi novia…$"

Route35_Text_PicnickerBrookeSeen:
	.string "Mi novio es débil. Así que no puedo\n"
	.string "confiar en él.$"

Route35_Text_PicnickerBrookeBeaten:
	.string "¡Cielos! ¡Eres tan fuerte!$"

Route35_Text_PicnickerBrookeAfter:
	.string "Confío más en mis POKéMON que en mi\n"
	.string "novio.$"

Route35_Text_PicnickerKimSeen:
	.string "¿Vas al GIMNASIO? ¡Yo también!$"

Route35_Text_PicnickerKimBeaten:
	.string "¡Vaya! No pude ganar…$"

Route35_Text_PicnickerKimAfter:
	.string "Me gustan las MEDALLAS de los\n"
	.string "GIMNASIOS.\p"
	.string "Las colecciono.$"

Route35_Text_BirdKeeperBryanSeen:
	.string "¿Qué tipo de POKé BALL usas?$"

Route35_Text_BirdKeeperBryanBeaten:
	.string "¡Vaya! ¡No lo bastante rápido!$"

Route35_Text_BirdKeeperBryanAfter:
	.string "Algunos POKéMON huyen enseguida.\p"
	.string "Intenta atraparlos con la RAPID BALL\n"
	.string "de CÉSAR.\p"
	.string "Cada vez que encuentro una BAYA\n"
	.string "PERASI, se la llevo a CÉSAR.\p"
	.string "Él la convierte en una BALL especial.$"

Route35_Text_JugglerIrwinSeen:
	.string "¡Observa cómo uso las POKé BALL!$"

Route35_Text_JugglerIrwinBeaten:
	.string "¡Uauuu! ¡Vaya sacudida!$"

Route35_Text_JugglerIrwinAfter:
	.string "Te iba a deslumbrar con mi preciado\n"
	.string "POKéMON.\p"
	.string "¡Pero tu habilidad me electrificó!$"

Route35_Text_BugCatcherArnieSeen:
	.string "Iré a cualquier lugar donde haya\n"
	.string "POKéMON bicho.$"

Route35_Text_BugCatcherArnieBeaten:
	.string "¿Eh? No debería haber perdido…$"

Route35_Text_BugCatcherArnieAfter:
	.string "Mi VENONAT ganó el Concurso de\n"
	.string "Captura de Bichos del PARQUE\l"
	.string "NACIONAL.$"

Route35_Text_IrwinRegister:
	.string "Te iba a deslumbrar con mi preciado\n"
	.string "POKéMON.\p"
	.string "¡Pero tu habilidad me electrificó!$"

Route35_Text_ArnieRegister:
	.string "Mi VENONAT ganó el Concurso de\n"
	.string "Captura de Bichos del PARQUE\l"
	.string "NACIONAL.$"

Route35_Text_ArnieRematchIntro:
	.string "Iré a cualquier lugar donde haya\n"
	.string "POKéMON bicho.$"

Route35_Text_ArnieRematchDefeat:
	.string "¿Eh? No debería haber perdido…$"

Route35_Text_ArniePostRematch:
	.string "Mi VENONAT ganó el Concurso de\n"
	.string "Captura de Bichos del PARQUE\l"
	.string "NACIONAL.$"

Route35_Text_BugCatcherArnieYanma:
	.string "Uau… Mira cuántos YANMA…\p"
	.string "Estoy tan impresionado que no puedo\n"
	.string "moverme.$"

Route35_Text_FirebreatherWaltSeen:
	.string "Practico mi aliento de fuego.$"

Route35_Text_FirebreatherWaltBeaten:
	.string "¡Me he quemado la punta de la nariz!$"

Route35_Text_FirebreatherWaltAfter:
	.string "La Marcha POKéMON de la radio atrae\n"
	.string "POKéMON salvajes.$"

Route35_Text_OfficerDirkSeen:
	.string "¡El peligro acecha por la noche!$"

Route35_Text_OfficerDirkBeaten:
	.string "¡Uy!$"

Route35_Text_OfficerDirkAfter:
	.string "¿Sabes? La noche tiene su gracia.\p"
	.string "Pero no te pases, ¿vale?$"

Route35_Text_OfficerDirkTough:
	.string "Tus POKéMON son bastante fuertes.\p"
	.string "Estarás a salvo en cualquier parte.$"

Route35_Text_Sign:
	.string "RUTA 35$"

Route35_Text_Sign2:
	.string "PUERTA DEL PARQUE NACIONAL$"
