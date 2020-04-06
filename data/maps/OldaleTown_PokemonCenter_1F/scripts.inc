OldaleTown_PokemonCenter_1F_MapScripts:: @ 81FC006
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition: @ 81FC011
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

@ VAR_0x800B is the Nurse's object event id
OldaleTown_PokemonCenter_1F_EventScript_Nurse:: @ 81FC01A
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman:: @ 81FC028
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy:: @ 81FC031
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl:: @ 81FC03A
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable:: @ 81FC04F
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC: @ 81FC059
	.string "Ese PC de la esquina es para el uso\n"
	.string "de cualquier ENTRENADOR POKéMON.\p"
	.string "Eso quiere decir que tú también lo\n"
	.string "puedes usar, claro.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat: @ 81FC0CD
	.string "¡Los CENTROS POKéMON son guays!\p"
	.string "Puedes usar sus servicios todas las\n"
	.string "veces que quieras y siempre es gratis.\l"
	.string "¡Es una pasada!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable: @ 81FC148
	.string "Acabaron de construir el CLUB del CABLE\n"
	.string "POKéMON del segundo piso hace poco.\p"
	.string "Pero dijeron que aún están en\n"
	.string "reformas.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub: @ 81FC1B9
	.string "Acabaron de construir el CLUB del CABLE\n"
	.string "POKéMON del segundo piso hace poco.\p"
	.string "¡Vengo de intercambiar un POKéMON!$"

