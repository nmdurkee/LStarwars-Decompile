/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50b4e0; label: FUN_0050b4e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050b4e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_004f30f0(2);
  FUN_004f30d0(0);
  FUN_004fda90(param_1,param_3,param_4,"LABEL",param_2);
  PTR_DAT_00800980 = (undefined *)FUN_004f8e90("GAMENAME");
  PTR_DAT_00800984 = (undefined *)FUN_004f8e90("GAMETITLE");
  PTR_DAT_00800988 = (undefined *)FUN_004f8e90("GAMESUBTITLE");
  PTR_PTR_008009cc = (undefined *)FUN_004f8e90("GEN_YES");
  PTR_DAT_008009d0 = (undefined *)FUN_004f8e90("GEN_NO");
  PTR_DAT_008009d4 = (undefined *)FUN_004f8e90("GEN_OK");
  PTR_s_Cancel_008009d8 = (undefined *)FUN_004f8e90("GEN_CANCEL");
  PTR_s_Retry_008009dc = (undefined *)FUN_004f8e90("GEN_RETRY");
  PTR_s_Profile_008009e0 = (undefined *)FUN_004f8e90("GEN_SLOT");
  PTR_s_Present_008009e4 = (undefined *)FUN_004f8e90("GEN_PRESENT");
  PTR_s_Empty_008009e8 = (undefined *)FUN_004f8e90("GEN_EMPTY");
  PTR_s_No_Space_008009ec = (undefined *)FUN_004f8e90("GEN_NOSPACE");
  PTR_s_Continue_008009f0 = (undefined *)FUN_004f8e90("GEN_CONTINUE");
  PTR_s_Save_Game_008009f4 = (undefined *)FUN_004f8e90("GEN_SAVEGAME");
  PTR_s_Load_Game_008009f8 = (undefined *)FUN_004f8e90("GEN_LOADGAME");
  PTR_s_Delete_Game_008009fc = (undefined *)FUN_004f8e90("GEN_DELETEGAME");
  PTR_s_Save_Successful_00800a00 = (undefined *)FUN_004f8e90("GEN_GAMESAVED");
  PTR_s_Overwrite_Successful_00800a04 = (undefined *)FUN_004f8e90("GEN_GAMEOVERWRITTEN");
  PTR_s_Game_Loaded_00800a08 = (undefined *)FUN_004f8e90("GEN_GAMELOADED");
  PTR_s_Deleting_data__00800a0c = (undefined *)FUN_004f8e90("GEN_DELETING");
  PTR_s_Formatting__00800a10 = (undefined *)FUN_004f8e90("GEN_FORMATTING");
  PTR_s_Load_Corrupted_00800a18 = (undefined *)FUN_004f8e90("GEN_CORRUPTLOAD");
  PTR_s_Confirm_Load__00800a1c = (undefined *)FUN_004f8e90("GEN_CONFIRMLOAD");
  PTR_s_Confirm_Save__00800a20 = (undefined *)FUN_004f8e90("GEN_CONFIRMSAVE");
  PTR_s_Are_you_sure_you_wish_to_overwri_00800a24 =
       (undefined *)FUN_004f8e90("GEN_CONFIRMOVERWRITE");
  PTR_s_Do_you_want_to_start_the_game__00800a28 = (undefined *)FUN_004f8e90("GEN_DOYOUWANTTOSTART");
  PTR_s_Do_you_want_to_cancel_the_Save__00800a2c = (undefined *)FUN_004f8e90("GEN_DOYOUWANTTOABORT")
  ;
  PTR_s_Do_you_want_to_cancel_the_Load__00800a30 =
       (undefined *)FUN_004f8e90("GEN_DOYOUWANTTOABORTLOAD");
  PTR_s_Do_you_want_to_cancel_the_Format_00800a34 =
       (undefined *)FUN_004f8e90("GEN_DOYOUWANTTOABORTFORMAT");
  PTR_s_Continue_without_Saving_00800a38 = (undefined *)FUN_004f8e90("GEN_CONTINUEWITHOUTSAVING");
  PTR_s_Overwriting_data__00800a14 = (undefined *)FUN_004f8e90("GEN_GAMEOVERWRITING");
  PTR_s_New_Save_00800a3c = (undefined *)FUN_004f8e90("GEN_NEWSAVE");
  PTR_s_Continue_without_loading_00800a40 = (undefined *)FUN_004f8e90("GEN_CONTINUEWITHOUTLOADING");
  PTR_s_Completed_00800a44 = (undefined *)FUN_004f8e90("GEN_COMPLETED");
  PTR_s_Select_00800a48 = (undefined *)FUN_004f8e90("GEN_SELECT");
  PTR_DAT_00800a4c = (undefined *)FUN_004f8e90("GEN_BACK");
  PTR_s_Vibration_00800a50 = (undefined *)FUN_004f8e90("GEN_VIBRATION");
  PTR_s_Are_you_sure_you_wish_to_delete_t_00800a54 = (undefined *)FUN_004f8e90("GEN_CONFIRMDELETE");
  PTR_s_Progress____1f___00800a58 = (undefined *)FUN_004f8e90("GEN_PROGRESS");
  PTR_s_Time_Played___s_00800a5c = (undefined *)FUN_004f8e90("GEN_TIMEPLAYED");
  PTR_s_FE_Start__00800a68 = (undefined *)FUN_004f8e90("GEN_PCPRESSSTARTFE");
  PTR_DAT_00800a6c = (undefined *)FUN_004f8e90("GEN_PCPRESSSTARTP1");
  PTR_DAT_00800a70 = (undefined *)FUN_004f8e90("GEN_PCPRESSSTARTP2");
  PTR_s_Saving_game____00800a74 = (undefined *)FUN_004f8e90("PC_GAMESAVING");
  PTR_s_Loading_game____00800a78 = (undefined *)FUN_004f8e90("PC_GAMELOADING");
  PTR_s_Failed_to_Load_00800a7c = (undefined *)FUN_004f8e90("PC_FAILEDTOLOAD");
  PTR_s_Failed_to_Save_00800a80 = (undefined *)FUN_004f8e90("PC_FAILEDTOSAVE");
  PTR_s_Failed_to_Overwrite_00800a84 = (undefined *)FUN_004f8e90("PC_FAILEDTOOVERWRITE");
  PTR_s_No__s_data_present_00800a88 = (undefined *)FUN_004f8e90("PC_NODATAAVAILABLE");
  PTR_s_Autosave_will_now_use_Game__i_00800a8c = (undefined *)FUN_004f8e90("PC_AUTOSAVE_ENABLED");
  PTR_s_Formatting_complete_00800a90 = (undefined *)FUN_004f8e90("PC_FORMATTINGCOMPLETE");
  PTR_s_Delete_complete_00800a94 = (undefined *)FUN_004f8e90("PC_DELETECOMPLETE");
  PTR_s_Insufficient_drive_space_to_save_00800a98 = (undefined *)FUN_004f8e90("PC_NOTENOUGHSPACE");
  PTR_s_The_controller_in_controller_por_00800a60 =
       (undefined *)FUN_004f8e90("PC_CONTROLLERREMOVED");
  return;
}

