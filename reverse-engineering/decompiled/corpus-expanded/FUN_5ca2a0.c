/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5ca2a0; label: FUN_005ca2a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ca2a0(undefined4 *param_1)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 != (undefined4 *)0x0) {
    sVar1 = *(short *)(DAT_00973880 + 4);
    *(short *)(param_1 + 1) = sVar1;
    *param_1 = 0;
    iVar2 = FUN_006de8d0((sVar1 + 1) * 0x30);
    param_1[2] = iVar2 + 0xfU & 0xfffffff0;
    uVar3 = FUN_006de8d0((int)*(short *)(param_1 + 1));
    param_1[3] = uVar3;
  }
  return;
}

