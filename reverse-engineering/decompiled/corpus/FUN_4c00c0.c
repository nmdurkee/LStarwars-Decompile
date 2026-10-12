/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4c00c0; label: FUN_004c00c0
 */

void FUN_004c00c0(void)

{
  int iVar1;
  int *piVar2;
  
  DAT_0087baf0 = 0;
  piVar2 = &DAT_0093d7f0;
  while (((*piVar2 == 0 || (iVar1 = *(int *)(*piVar2 + 0xcbc), iVar1 == 0)) ||
         ((*(byte *)(iVar1 + 0xc) & 1) == 0))) {
    piVar2 = piVar2 + 1;
    if (0x93d80f < (int)piVar2) {
      return;
    }
  }
  DAT_0087baf0 = 1;
  return;
}

