/* Ghidra pseudocode, not original source.
 * ev_97f4a3b699bb455f9f6d61621fe82dddba0f62005898969e9454d063fd653c3d
 * Entry: 0x586d20; label: FUN_00586d20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00586d20(int param_1)

{
  undefined2 uVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  psVar2 = (short *)(DAT_00954404 + 0xd0);
  do {
    if (*psVar2 == -1) {
      if ((iVar4 < 6) && (iVar3 = FUN_004f7fb0(param_1), iVar3 != 0)) {
        uVar1 = FUN_00650dc0(*(undefined4 *)(param_1 + 0x510));
        *(undefined2 *)(DAT_00954404 + 0xd0 + iVar4 * 2) = uVar1;
      }
      break;
    }
    iVar4 = iVar4 + 1;
    psVar2 = psVar2 + 1;
  } while (iVar4 < 6);
  if (iVar4 + 1 < 6) {
    *(undefined2 *)(DAT_00954404 + 0xd0 + (iVar4 + 1) * 2) = 0xffff;
  }
  return;
}

