#!/bin/bash

current_path=$(dirname $0)
bin_path=$current_path/bin
map_path=$current_path/maps

so_long=$bin_path/so_long

make -s

printf "$so_long $map_path/invalid_directory.ber\n"
$so_long $map_path/invalid_directory.ber
printf "\n$so_long $map_path/invalid_character.ber\n"
$so_long $map_path/invalid_character.ber
printf "\n$so_long $map_path/invalid_size.ber\n"
$so_long $map_path/invalid_size.ber
printf "\n$so_long $map_path/invalid_size_new_line_start.ber\n"
$so_long $map_path/invalid_size_new_line_start.ber
printf "\n$so_long $map_path/invalid_size_new_line_end.ber\n"
$so_long $map_path/invalid_size_new_line_end.ber
printf "\n$so_long $map_path/invalid_not_closed_up.ber\n"
$so_long $map_path/invalid_not_closed_up.ber
printf "\n$so_long $map_path/invalid_not_closed_down.ber\n"
$so_long $map_path/invalid_not_closed_down.ber
printf "\n$so_long $map_path/invalid_not_closed_left.ber\n"
$so_long $map_path/invalid_not_closed_left.ber
printf "\n$so_long $map_path/invalid_not_closed_right.ber\n"
$so_long $map_path/invalid_not_closed_right.ber
printf "\n$so_long $map_path/invalid_amount_collectible.ber\n"
$so_long $map_path/invalid_amount_collectible.ber
printf "\n$so_long $map_path/invalid_amount_player.ber\n"
$so_long $map_path/invalid_amount_player.ber
printf "\n$so_long $map_path/invalid_amount_player_2.ber\n"
$so_long $map_path/invalid_amount_player_2.ber
printf "\n$so_long $map_path/invalid_amount_exit.ber\n"
$so_long $map_path/invalid_amount_exit.ber
printf "\n$so_long $map_path/invalid_amount_exit_2.ber\n"
$so_long $map_path/invalid_amount_exit_2.ber
printf "\n$so_long $map_path/invalid_extension\n"
$so_long $map_path/invalid_extension
printf "\n$so_long $map_path/invalid_extension_2.be\n"
$so_long $map_path/invalid_extension_2.be
printf "\n$so_long $map_path/.ber\n"
$so_long $map_path/.ber


# Checking leaks
if [[ "$1" == "leaks" ]]; then
	printf "valgrind $so_long $map_path/invalid_directory.ber\n"
	valgrind $so_long $map_path/invalid_directory.ber
	printf "\nvalgrind $so_long $map_path/invalid_character.ber\n"
	valgrind $so_long $map_path/invalid_character.ber
	printf "\nvalgrind $so_long $map_path/invalid_size.ber\n"
	valgrind $so_long $map_path/invalid_size.ber
	printf "\nvalgrind $so_long $map_path/invalid_size_new_line_start.ber\n"
	valgrind $so_long $map_path/invalid_size_new_line_start.ber
	printf "\nvalgrind $so_long $map_path/invalid_size_new_line_end.ber\n"
	valgrind $so_long $map_path/invalid_size_new_line_end.ber
	printf "\nvalgrind $so_long $map_path/invalid_not_closed_up.ber\n"
	valgrind $so_long $map_path/invalid_not_closed_up.ber
	printf "\nvalgrind $so_long $map_path/invalid_not_closed_down.ber\n"
	valgrind $so_long $map_path/invalid_not_closed_down.ber
	printf "\nvalgrind $so_long $map_path/invalid_not_closed_left.ber\n"
	valgrind $so_long $map_path/invalid_not_closed_left.ber
	printf "\nvalgrind $so_long $map_path/invalid_not_closed_right.ber\n"
	valgrind $so_long $map_path/invalid_not_closed_right.ber
	printf "\nvalgrind $so_long $map_path/invalid_amount_collectible.ber\n"
	valgrind $so_long $map_path/invalid_amount_collectible.ber
	printf "\nvalgrind $so_long $map_path/invalid_amount_player.ber\n"
	valgrind $so_long $map_path/invalid_amount_player.ber
	printf "\nvalgrind $so_long $map_path/invalid_amount_player_2.ber\n"
	valgrind $so_long $map_path/invalid_amount_player_2.ber
	printf "\nvalgrind $so_long $map_path/invalid_amount_exit.ber\n"
	valgrind $so_long $map_path/invalid_amount_exit.ber
	printf "\nvalgrind $so_long $map_path/invalid_amount_exit_2.ber\n"
	valgrind $so_long $map_path/invalid_amount_exit_2.ber
	printf "\nvalgrind $so_long $map_path/invalid_extension\n"
	valgrind $so_long $map_path/invalid_extension
	printf "\nvalgrind $so_long $map_path/invalid_extension_2.be\n"
	valgrind $so_long $map_path/invalid_extension_2.be
	printf "\nvalgrind $so_long $map_path/.ber\n"
	valgrind $so_long $map_path/.ber
fi
