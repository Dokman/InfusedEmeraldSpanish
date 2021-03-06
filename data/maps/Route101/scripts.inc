Route101_MapScripts:: @ 81EBCBA
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnTransition: @ 81EBCC5
	call ProfBirch_EventScript_UpdateLocation
	end

Route101_OnFrame: @ 81EBCCB
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0

Route101_EventScript_HideMapNamePopup:: @ 81EBCD5
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE101_STATE, 1
	end

Route101_EventScript_StartBirchRescue:: @ 81EBCDE
	lockall
	playbgm MUS_EVENT0, 1
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
	closemessage
	setobjectxy 2, 0, 15
	setobjectxy 4, 0, 16
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_EnterScene
	applymovement 2, Route101_Movement_BirchRunAway1
	applymovement 4, Route101_Movement_PoochyenaChase1
	waitmovement 0
	applymovement 4, Route101_Movement_PoochyenaChaseInCircles
	applymovement 2, Route101_Movement_BirchRunInCircles
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement 4, Route101_Movement_PoochyenaFaceBirch
	applymovement 2, Route101_Movement_BirchFacePoochyena
	waitmovement 0
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE101_STATE, 2
	releaseall
	end

Route101_EventScript_PreventExitSouth:: @ 81EBD4E
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitSouth
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitWest:: @ 81EBD64
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitNorth:: @ 81EBD7A
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitNorth
	waitmovement 0
	releaseall
	end

Route101_Movement_PreventExitSouth: @ 81EBD90
	walk_up
	step_end

Route101_Movement_PreventExitWest: @ 81EBD92
	walk_right
	step_end

Route101_Movement_PreventExitNorth: @ 81EBD94
	walk_down
	step_end

Route101_Movement_PoochyenaChaseInCircles: @ 81EBD96
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_PoochyenaChase1: @ 81EBDB5
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_PoochyenaFaceBirch: @ 81EBDBD
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route101_Movement_EnterScene: @ 81EBDC2
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_fastest_left
	step_end

Route101_Movement_BirchRunInCircles: @ 81EBDC8
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_BirchRunAway1: @ 81EBDE7
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_BirchFacePoochyena: @ 81EBDEF
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Route101_Movement_Unused1: @ 81EBDF4
	walk_up
	walk_up
	step_end

Route101_Movement_Unused2: @ 81EBDF7
	walk_up
	walk_left
	walk_up
	step_end

Route101_EventScript_Youngster:: @ 81EBDFB
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end

Route101_EventScript_Boy:: @ 81EBE04
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route101_EventScript_RouteSign:: @ 81EBE0D
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_BirchsBag:: @ 81EBE16
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	removeobject 4
	setobjectxy OBJ_EVENT_ID_PLAYER, 6, 13
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	special ChooseStarter
	waitstate
	applymovement 2, Route101_Movement_BirchApproachPlayer
	waitmovement 0
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
	special HealPlayerParty
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Route101_EventScript_HideMayInBedroom
	compare VAR_RESULT, FEMALE
	call_if_eq Route101_EventScript_HideBrendanInBedroom
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 255, 6, 5
	waitstate
	release
	end

Route101_EventScript_HideMayInBedroom:: @ 81EBE85
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_HideBrendanInBedroom:: @ 81EBE89
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return

Route101_Movement_BirchApproachPlayer: @ 81EBE8D
	walk_right
	step_end

Route101_Text_HelpMe: @ 81EBE8F
	.string "¡Socorro! ¡Ayuda!$"

Route101_Text_PleaseHelp: @ 81EBE9A
	.string "¡Oye! ¡Sí, tu!\n"
	.string "¡Ayúdame, por favor!\p"
	.string "¡Coge la POKé BALL!\n"
	.string "¡En mi MOCHILA!$"

Route101_Text_DontLeaveMe: @ 81EBEDF
	.string "Pe-pero... ¡¿adónde vas?!\n"
	.string "¡¡¡No me dejes así!!!$"

Route101_Text_YouSavedMe: @ 81EBF12
	.string "PROF. ABEDUL: Uf...\p"
	.string "Estaba en la zona de hierba alta\n"
	.string "estudiando POKéMON salvajes.\l"
	.string "cuando me atacó uno...\p"
	.string "Me has salvado.\n"
	.string "¡Muchísimas gracias!\p"
	.string "¡Anda!\p"
	.string "¡Si eres {PLAYER}{KUN}!\p"
	.string "Éste no es el lugar para charlas, así que\n"
	.string "vente conmigo a mi LABORATORIO\l"
	.string "POKéMON, ¿vale?$"

Route101_Text_TakeTiredPokemonToPokeCenter: @ 81EBFDD
	.string "Si tus POKéMON están cansados,\n"
	.string "llévalos a un CENTRO POKéMON.\p"
	.string "Hay un CENTRO POKéMON en PUEBLO\n"
	.string "ESCASO, muy cerca de aquí.$"

Route101_Text_WildPokemonInTallGrass: @ 81EC04A
	.string "Los POKéMON salvajes te atacarán\n"
	.string "en las zonas de hierba alta.\p"
	.string "Si quieres atrapar POKéMON, ve donde\n"
	.string "haya hierba alta y busca.$"

Route101_Text_RouteSign: @ 81EC0C8
	.string "RUTA 101\n"
	.string "{UP_ARROW} PUEBLO ESCASO$"

