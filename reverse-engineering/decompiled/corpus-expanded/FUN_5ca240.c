/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5ca240; label: FUN_005ca240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ca240(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  
  _DAT_00973870 = param_1;
  iVar2 = *param_2;
  uVar1 = iVar2 + 0xfU & 0xfffffff0;
  *param_2 = uVar1 + 0x10;
  DAT_00973880 = (undefined4 *)(iVar2 + 0xfU & 0xfffffff0);
  DAT_00973880[2] = uVar1 + 0x10;
  iVar2 = (*param_2 + 0xfU & 0xfffffff0) + param_1 * 0x30;
  *param_2 = iVar2;
  DAT_00973880[3] = iVar2;
  *param_2 = *param_2 + param_1;
  *(short *)(DAT_00973880 + 1) = (short)param_1;
  *DAT_00973880 = 0;
  return;
}

