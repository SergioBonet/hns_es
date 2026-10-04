MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "Gracias por usar el sistema de\n"
	.string "REGALO MISTERIOSO.\p"
	.string "Si tienes esta TARJETA MISTERIOSA,\n"
	.string "puedes participar en una encuesta en\l"
	.string "una TIENDA POKéMON.\p"
	.string "Usa estas encuestas para invitar\n"
	.string "a ENTRENADORES a CIUDAD ALGARIA.\p"
	.string "…Te daré una contraseña secreta\n"
	.string "para una encuesta:\p"
	.string "“DAME UN\n"
	.string "ENTRENADOR GENIAL”\p"
	.string "Escríbela en una encuesta y envíala\n"
	.string "al SISTEMA de COMUNICACIÓN\l"
	.string "INALÁMBRICA.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Gracias por usar el sistema de\n"
	.string "REGALO MISTERIOSO.\p"
	.string "Ha llegado un ENTRENADOR a\n"
	.string "CIUDAD ALGARIA buscándote.\p"
	.string "Esperamos que disfrutes\n"
	.string "combatiendo contra el visitante.\p"
	.string "Puedes invitar a otros ENTRENADORES\n"
	.string "introduciendo otras contraseñas.\p"
	.string "Prueba a buscar otras contraseñas\n"
	.string "que puedan funcionar.$"
