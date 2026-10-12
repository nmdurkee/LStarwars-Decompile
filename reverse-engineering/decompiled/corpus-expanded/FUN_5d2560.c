/* Ghidra pseudocode, not original source.
 * ev_e6f703959aeb52fdf2ce751bd65c36cac7164cfc40610a61221749966f801066
 * Entry: 0x5d2560; label: FUN_005d2560
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d2560(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = FUN_004f9e70(param_1);
  if (iVar3 == 0) {
    iVar3 = 0x7fffffff;
  }
  uVar2 = FUN_004f9e70(param_1);
  iVar1 = DAT_00971580;
  *(undefined2 *)(DAT_00971580 + 0x1ba + *(short *)(DAT_00971580 + 0x1b4) * 2) = 0xd;
  *(short *)(iVar1 + 0x1b4) = *(short *)(iVar1 + 0x1b4) + 1;
  *(short *)(iVar1 + 0x1ba + *(short *)(iVar1 + 0x1b4) * 2) = (short)iVar3;
  *(short *)(iVar1 + 0x1b4) = *(short *)(iVar1 + 0x1b4) + 1;
  *(undefined2 *)(iVar1 + 0x1ba + *(short *)(iVar1 + 0x1b4) * 2) = uVar2;
  *(short *)(iVar1 + 0x1b4) = *(short *)(iVar1 + 0x1b4) + 1;
  return;
}

