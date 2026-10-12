/* Ghidra analysis pseudocode, not original source.
 * ev_7cebcd231b4f420658515fe731eecd90e8f898d61da81d56368ea9915da5e025
 * Entry: 0x596950; label: thunk_FUN_005d05b0
 */

void thunk_FUN_005d05b0(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_00966384 != 0) {
    do {
      piVar1 = &DAT_0096d9d0 + iVar2;
      iVar2 = iVar2 + 1;
      *(undefined4 *)(*piVar1 + 0x824) = 0;
    } while (iVar2 != DAT_00966384);
  }
  DAT_00966384 = 0;
  DAT_009715a0 = 0;
  return;
}

