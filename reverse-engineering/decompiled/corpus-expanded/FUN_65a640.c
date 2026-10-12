/* Ghidra pseudocode, not original source.
 * ev_04b6c5fb0da19ab46b9dcd6e2bf7aaf6621f6765e7317b7c56ac1531caca2973
 * Entry: 0x65a640; label: FUN_0065a640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065a640(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (((*(int *)((int)&DAT_02961f80 + iVar1) != 0) && (*(int *)((int)&DAT_02947c7c + iVar1) != 0))
       && (*(int *)((int)&DAT_0292fd80 + iVar1) == 0)) {
      *(undefined4 *)((int)&DAT_0292fd80 + iVar1) = 1;
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x20);
  return;
}

