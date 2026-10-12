/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5ca1f0; label: FUN_005ca1f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ca1f0(int param_1,int *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *param_2;
  uVar2 = iVar3 + 0xfU & 0xfffffff0;
  *param_2 = uVar2 + 0x10;
  puVar1 = (undefined4 *)(iVar3 + 0xfU & 0xfffffff0);
  puVar1[2] = uVar2 + 0x10;
  iVar3 = (*param_2 + 0xfU & 0xfffffff0) + param_1 * 0x30;
  *param_2 = iVar3;
  puVar1[3] = iVar3;
  *param_2 = *param_2 + param_1;
  *(short *)(puVar1 + 1) = (short)param_1;
  *puVar1 = 0;
  return;
}

