/* Ghidra pseudocode, not original source.
 * ev_97f4a3b699bb455f9f6d61621fe82dddba0f62005898969e9454d063fd653c3d
 * Entry: 0x5868b0; label: FUN_005868b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005868b0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    *(undefined1 *)(DAT_00954404 + 0x108 + iVar3) = 0xff;
    iVar1 = FUN_004f7fb0(param_1);
    if (iVar1 != 0) {
      uVar2 = FUN_004f29a0(*(undefined4 *)(param_1 + 0x510));
      if (uVar2 < 0x10) {
        *(char *)(DAT_00954404 + 0x108 + iVar3) = (char)uVar2;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  return;
}

