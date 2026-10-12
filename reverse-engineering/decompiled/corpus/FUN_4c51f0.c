/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c51f0; label: FUN_004c51f0
 */

void FUN_004c51f0(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 float param_5,ushort param_6,ushort param_7,ushort param_8)

{
  int iVar1;
  uint local_58;
  uint local_54;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [48];
  undefined4 local_10;
  float local_c;
  undefined4 local_8;
  
  if ((param_2 != (undefined4 *)0x0) && (iVar1 = FUN_005cfac0(param_1), iVar1 != 0)) {
    local_58 = (uint)param_6;
    local_54 = (uint)param_7;
    local_50 = (uint)param_8;
    thunk_FUN_005b5300(local_40,&local_58);
    local_44 = param_3;
    local_48 = param_3;
    local_4c = param_3;
    thunk_FUN_005b4a50(local_40,&local_4c);
    local_10 = *param_2;
    local_8 = param_2[2];
    local_c = (float)param_2[1] + param_5;
    FUN_005f33b0(param_1,local_40);
  }
  return;
}

