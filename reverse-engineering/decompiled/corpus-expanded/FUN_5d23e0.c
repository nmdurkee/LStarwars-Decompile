/* Ghidra pseudocode, not original source.
 * ev_e6f703959aeb52fdf2ce751bd65c36cac7164cfc40610a61221749966f801066
 * Entry: 0x5d23e0; label: FUN_005d23e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d23e0(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  FUN_004f7fb0(param_1);
  uVar2 = FUN_005d1ea0(*(undefined4 *)(param_1 + 0x510));
  iVar1 = DAT_00971580;
  *(undefined2 *)(DAT_00971580 + 0x1ba + *(short *)(DAT_00971580 + 0x1b4) * 2) = 0x11;
  *(short *)(iVar1 + 0x1b4) = *(short *)(iVar1 + 0x1b4) + 1;
  *(undefined2 *)(iVar1 + 0x1ba + *(short *)(iVar1 + 0x1b4) * 2) = uVar2;
  *(short *)(iVar1 + 0x1b4) = *(short *)(iVar1 + 0x1b4) + 1;
  return;
}

