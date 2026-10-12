/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x523640; label: FUN_00523640
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00523640(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8)

{
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  local_c = *param_1;
  local_8 = (float)param_1[1] + _DAT_00801cc8;
  local_4 = param_1[2];
  if (param_8 != 0) {
    FUN_0051f720(&local_c,param_2,param_3,param_4,param_5,param_6,param_7);
    return;
  }
  FUN_0051fab0(&local_c,param_2,param_5,param_6,param_7);
  return;
}

