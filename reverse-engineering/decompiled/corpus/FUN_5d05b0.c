/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d05b0; label: FUN_005d05b0
 */

void FUN_005d05b0(void)

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

