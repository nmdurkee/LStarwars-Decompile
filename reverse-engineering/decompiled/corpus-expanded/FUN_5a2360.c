/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a2360; label: FUN_005a2360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a2360(uint *param_1,int *param_2,undefined4 param_3,uint param_4)

{
  ushort uVar1;
  undefined2 *puVar2;
  undefined4 extraout_ECX;
  
  puVar2 = (undefined2 *)(*param_2 + 3U & 0xfffffffc);
  *param_2 = (int)(puVar2 + 10);
  *param_1 = (uint)puVar2;
  param_4 = param_4 & ((int)param_4 < 1) - 1;
  if (0x3f < (int)param_4) {
    param_4 = 0x40;
  }
  *puVar2 = (short)param_4;
  *(undefined2 *)(*param_1 + 2) = 0;
  uVar1 = *(ushort *)*param_1;
  *param_2 = (uint)uVar1 * 0x80 + (*param_2 + 0x7fU & 0xffffff80);
  FUN_005a2250();
  DAT_00956628 = *param_2 + 3U & 0xfffffffc;
  *param_2 = DAT_00956628 + (uint)uVar1 * 4;
  *(undefined4 *)(*param_1 + 4) = extraout_ECX;
  *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(*param_1 + 4);
  *(undefined4 *)(*param_1 + 0xc) = 0;
  *(undefined4 *)(*param_1 + 0x10) = 0;
  return;
}

