/* Ghidra analysis pseudocode, not original source.
 * ev_40d9be8e3a3402c331433b8a2d08079ac53cd459e8d3bded6c92f46fa7f98a9b
 * Entry: 0x65a640; label: FUN_0065a640
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

