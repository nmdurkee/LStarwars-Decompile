/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x655380; label: FUN_00655380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00655380(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 1;
  iVar2 = DAT_0296209c;
  if (1 < DAT_02962098) {
    do {
      if ((*(int *)(iVar2 + iVar1 * 4) != 0) && (*(int *)(*(int *)(iVar2 + iVar1 * 4) + 0x2a8) != 0)
         ) {
        DAT_02924b44 = DAT_02924b44 + -1;
        *(undefined4 *)(DAT_02962090 + DAT_02924b44 * 4) =
             *(undefined4 *)(*(int *)(iVar2 + iVar1 * 4) + 0x2a8);
        *(undefined4 *)(*(int *)(DAT_0296209c + iVar1 * 4) + 0x2a8) = 0;
        iVar2 = DAT_0296209c;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_02962098);
  }
  return;
}

