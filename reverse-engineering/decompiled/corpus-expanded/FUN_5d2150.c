/* Ghidra pseudocode, not original source.
 * ev_e6f703959aeb52fdf2ce751bd65c36cac7164cfc40610a61221749966f801066
 * Entry: 0x5d2150; label: FUN_005d2150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d2150(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  undefined2 uVar3;
  
  FUN_004f9e70(param_1);
  FUN_004f9e70(param_1);
  iVar2 = DAT_00971580;
  *(undefined2 *)(DAT_00971580 + 0x1ba + *(short *)(DAT_00971580 + 0x1b4) * 2) = 4;
  *(short *)(iVar2 + 0x1b4) = *(short *)(iVar2 + 0x1b4) + 1;
  sVar1 = *(short *)(iVar2 + 0x1b4);
  uVar3 = FUN_006e6b90();
  *(undefined2 *)(iVar2 + 0x1ba + sVar1 * 2) = uVar3;
  *(short *)(iVar2 + 0x1b4) = *(short *)(iVar2 + 0x1b4) + 1;
  sVar1 = *(short *)(iVar2 + 0x1b4);
  uVar3 = FUN_006e6b90();
  *(undefined2 *)(iVar2 + 0x1ba + sVar1 * 2) = uVar3;
  *(short *)(iVar2 + 0x1b4) = *(short *)(iVar2 + 0x1b4) + 1;
  return;
}

