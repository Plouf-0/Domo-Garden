/***************************************************************************//**
 * @file sl_cli_command_table.c
 * @brief Declarations of relevant command structs for cli framework.
 * @version x.y.z
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#include <stdlib.h>

#include "sl_cli_config.h"
#include "sl_cli_command.h"
#include "sl_cli_arguments.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 *****************************   TEMPLATED FILE   ******************************
 ******************************************************************************/

/*******************************************************************************
 * Example syntax (.slcc or .slcp) for populating this file:
 *
 *   template_contribution:
 *     - name: cli_command          # Register a command
 *       value:
 *         name: status             # Name of command
 *         handler: status_command  # Function to be called. Must be defined
 *         help: "Prints status"    # Optional help description
 *         shortcuts:               # Optional shorcut list
 *           - name: st
 *         argument:                # Argument list, if apliccable
 *           - type: uint8          # Variable type
 *             help: "Channel"      # Optional description
 *           - type: string
 *             help: "Text"
 *     - name: cli_group            # Register a group
 *       value:
 *         name: shell              # Group name
 *         help: "Shell commands"   # Optional help description
 *         shortcuts:               # Optional shorcuts
 *           - name: sh
 *     - name: cli_command
 *       value:
 *         name: repeat
 *         handler: repeat_cmd
 *         help: "Repeat commands"
 *         shortcuts:
 *           - name: r
 *           - name: rep
 *         group: shell            # Associate command with group
 *         argument:
 *           - type: string
 *             help: "Text"
 *           - type: additional
 *             help: "More text"
 *
 * For subgroups, an optional unique id can be used to allow a particular name to
 * be used more than once. In the following case, from the command line the
 * following commands are available:
 *
 * >  root_1 shell status
 * >  root_2 shell status
 *
 *     - name: cli_group            # Register a group
 *       value:
 *         name: root_1             # Group name
 *
 *     - name: cli_group            # Register a group
 *       value:
 *         name: root_2             # Group name
 *
 *    - name: cli_group             # Register a group
 *       value:
 *         name: shell              # Group name
 *         id: shell_root_1         # Optional unique id for group
 *         group: root_1            # Add group to root_1 group
 *
 *    - name: cli_group             # Register a group
 *       value:
 *         name: shell              # Group name
 *         id: shell_root_2         # Optional unique id for group
 *         group: root_2            # Add group to root_1 group
 *
 *    - name: cli_command           # Register a command
 *       value:
 *         name: status
 *         handler: status_1
 *         group: shell_root_1      # id of subgroup
 *
 *    - name: cli_command           # Register a command
 *       value:
 *         name: status
 *         handler: status_2
 *         group: shell_root_2      # id of subgroup
 *
 ******************************************************************************/

// Provide function declarations
void sli_zigbee_debug_print_enable_stack_type_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_debug_print_enable_core_type_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_debug_print_enable_app_type_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_debug_print_enable_zcl_type_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_debug_print_enable_legacy_af_debug_type_command(sl_cli_command_arg_t *arguments);
void sl_zigbee_gpd_af_cli_reset_command(sl_cli_command_arg_t *arguments);
void sl_zigbee_gpd_af_cli_node_info(sl_cli_command_arg_t *arguments);
void sl_zigbee_gpd_af_cli_channel_req(sl_cli_command_arg_t *arguments);
void sl_zigbee_gpd_af_cli_comm_req(sl_cli_command_arg_t *arguments);
void sl_zigbee_gpd_af_cli_node_set_addr(sl_cli_command_arg_t *arguments);
void sl_zigbee_gpd_af_cli_node_set_auto_comm(sl_cli_command_arg_t *arguments);
void sl_zigbee_gpd_af_cli_node_set_bi_dir_param(sl_cli_command_arg_t *arguments);
void sl_zigbee_gpd_af_cli_node_set_channel(sl_cli_command_arg_t *arguments);
void sl_zigbee_gpd_af_cli_node_set_sec_key_type(sl_cli_command_arg_t *arguments);
void sl_zigbee_gpd_af_cli_node_set_sec_key(sl_cli_command_arg_t *arguments);
void sl_zigbee_gpd_af_cli_node_set_sec_fc(sl_cli_command_arg_t *arguments);
void sl_zigbee_gpd_af_cli_node_set_sec_level(sl_cli_command_arg_t *arguments);
void sl_zigbee_gpd_af_cli_send_gpdf(sl_cli_command_arg_t *arguments);
void sl_zigbee_gpd_af_cli_switch_toggle(sl_cli_command_arg_t *arguments);
void sl_zigbee_gpd_af_cli_switch_sleep(sl_cli_command_arg_t *arguments);

// Command structs. Names are in the format : cli_cmd_{command group name}_{command name}
// In order to support hyphen in command and group name, every occurence of it while
// building struct names will be replaced by "_hyphen_"
static const sl_cli_command_info_t cli_cmd_enable_type_stack = \
  SL_CLI_COMMAND(sli_zigbee_debug_print_enable_stack_type_command,
                 "Enable/disable debug `stack` print type.",
                  "Enable/disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_enable_type_core = \
  SL_CLI_COMMAND(sli_zigbee_debug_print_enable_core_type_command,
                 "Enable/disable debug `core` print type.",
                  "Enable/disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_enable_type_app = \
  SL_CLI_COMMAND(sli_zigbee_debug_print_enable_app_type_command,
                 "Enable/disable debug `app` print type.",
                  "Enable/disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_enable_type_zcl = \
  SL_CLI_COMMAND(sli_zigbee_debug_print_enable_zcl_type_command,
                 "Enable/disable debug `zcl` print type.",
                  "Enable/disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_enable_type_legacy_af_debug = \
  SL_CLI_COMMAND(sli_zigbee_debug_print_enable_legacy_af_debug_type_command,
                 "Enable/disable debug `legacy app framework debug` print type.",
                  "Enable/disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__reset = \
  SL_CLI_COMMAND(sl_zigbee_gpd_af_cli_reset_command,
                 "Resets the node.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_node_info = \
  SL_CLI_COMMAND(sl_zigbee_gpd_af_cli_node_info,
                 "Prints the GPD node information.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_node_channel_hyphen_req = \
  SL_CLI_COMMAND(sl_zigbee_gpd_af_cli_channel_req,
                 "Sends out a channel request command from the GPD.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_node_comm = \
  SL_CLI_COMMAND(sl_zigbee_gpd_af_cli_comm_req,
                 "Sends out a commissioning request and moves the commissioning state machine based on the parameter provided.",
                  "0x00 - Decommission, 0x01 = A single commissioning GPDF, 0xFF = Start automatic commissioning process" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_node_set_hyphen_addr = \
  SL_CLI_COMMAND(sl_zigbee_gpd_af_cli_node_set_addr,
                 "Sets the address of the GPD node.",
                  "array of 8 bit data, where AppId = arg[0], if AppId = 0 then SrcId = arg[1-4] but if AppId = 2 then Endpoint = arg[1] and EUI = arg[2-9]" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_node_set_hyphen_ac = \
  SL_CLI_COMMAND(sl_zigbee_gpd_af_cli_node_set_auto_comm,
                 "Sets the auto-commission parameter of the GPD node.",
                  "Auto-commissioning parameter of the GPD node" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_node_set_hyphen_bidir_hyphen_param = \
  SL_CLI_COMMAND(sl_zigbee_gpd_af_cli_node_set_bi_dir_param,
                 "Sets bidirectional parameter of the GPD node.",
                  "rx-after-tx flag." SL_CLI_UNIT_SEPARATOR "rx-offset in milliseconds." SL_CLI_UNIT_SEPARATOR "rxwindow in milliseconds." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_node_set_hyphen_channel = \
  SL_CLI_COMMAND(sl_zigbee_gpd_af_cli_node_set_channel,
                 "Sets the channel of operation for unidirectional GPD or channel for bidirectional commissioning.",
                  "GPD channel from 11 to 26" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_node_set_hyphen_sec_hyphen_key_hyphen_type = \
  SL_CLI_COMMAND(sl_zigbee_gpd_af_cli_node_set_sec_key_type,
                 "Sets the bidirectional commissioning key type.",
                  "Key type between 0 and 7" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_node_set_hyphen_sec_hyphen_key = \
  SL_CLI_COMMAND(sl_zigbee_gpd_af_cli_node_set_sec_key,
                 "Sets the bidirectional key.",
                  "128 bit key" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_node_set_hyphen_sec_hyphen_fc = \
  SL_CLI_COMMAND(sl_zigbee_gpd_af_cli_node_set_sec_fc,
                 "Sets security frame counter.",
                  "Sec frame counter" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_node_set_hyphen_sec_hyphen_level = \
  SL_CLI_COMMAND(sl_zigbee_gpd_af_cli_node_set_sec_level,
                 "Sets security level. 0 = No security, 1 = RESERVED, 2 = Authentication only, 3 = Encrypted and Authenticated",
                  "Sec level between 0 to 3." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__send_hyphen_gpdf = \
  SL_CLI_COMMAND(sl_zigbee_gpd_af_cli_send_gpdf,
                 "Sends out a GPD command based on the set GPD parameters.",
                  "Frame type 0 = Data frame, 1 = Maintenance frame." SL_CLI_UNIT_SEPARATOR "Command payload" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_switch_toggle = \
  SL_CLI_COMMAND(sl_zigbee_gpd_af_cli_switch_toggle,
                 "Sends a toggle command.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_switch_sleep = \
  SL_CLI_COMMAND(sl_zigbee_gpd_af_cli_switch_sleep,
                 "sets gpd as a sleepy device.",
                  "",
                 {SL_CLI_ARG_END, });


// Create group command tables and structs if cli_groups given
// in template. Group name is suffixed with _group_table for tables
// and group commands are cli_cmd_grp_( group name )
static const sl_cli_command_entry_t enable_type_group_table[] = {
  { "stack", &cli_cmd_enable_type_stack, false },
  { "core", &cli_cmd_enable_type_core, false },
  { "app", &cli_cmd_enable_type_app, false },
  { "zcl", &cli_cmd_enable_type_zcl, false },
  { "legacy_af_debug", &cli_cmd_enable_type_legacy_af_debug, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_enable_type = \
  SL_CLI_COMMAND_GROUP(enable_type_group_table, "");

static const sl_cli_command_entry_t zigbee_print_group_table[] = {
  { "enable_type", &cli_cmd_grp_enable_type, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_zigbee_print = \
  SL_CLI_COMMAND_GROUP(zigbee_print_group_table, "");

static const sl_cli_command_entry_t node_group_table[] = {
  { "info", &cli_cmd_node_info, false },
  { "channel-req", &cli_cmd_node_channel_hyphen_req, false },
  { "comm", &cli_cmd_node_comm, false },
  { "set-addr", &cli_cmd_node_set_hyphen_addr, false },
  { "set-ac", &cli_cmd_node_set_hyphen_ac, false },
  { "set-bidir-param", &cli_cmd_node_set_hyphen_bidir_hyphen_param, false },
  { "set-channel", &cli_cmd_node_set_hyphen_channel, false },
  { "set-sec-key-type", &cli_cmd_node_set_hyphen_sec_hyphen_key_hyphen_type, false },
  { "set-sec-key", &cli_cmd_node_set_hyphen_sec_hyphen_key, false },
  { "set-sec-fc", &cli_cmd_node_set_hyphen_sec_hyphen_fc, false },
  { "set-sec-level", &cli_cmd_node_set_hyphen_sec_hyphen_level, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_node = \
  SL_CLI_COMMAND_GROUP(node_group_table, "gpd node related commands");

static const sl_cli_command_entry_t switch_group_table[] = {
  { "toggle", &cli_cmd_switch_toggle, false },
  { "sleep", &cli_cmd_switch_sleep, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_switch = \
  SL_CLI_COMMAND_GROUP(switch_group_table, "switch related commands");

// Create root command table
const sl_cli_command_entry_t sl_cli_default_command_table[] = {
  { "reset", &cli_cmd__reset, false },
  { "send-gpdf", &cli_cmd__send_hyphen_gpdf, false },
  { "zigbee_print", &cli_cmd_grp_zigbee_print, false },
  { "node", &cli_cmd_grp_node, false },
  { "switch", &cli_cmd_grp_switch, false },
  { NULL, NULL, false },
};


#ifdef __cplusplus
}
#endif
