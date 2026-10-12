/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c23f0; label: FUN_006c23f0
 */

void FUN_006c23f0(void)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)*in_ECX;
  while (piVar1 != (int *)0x0) {
    if (*piVar1 == 0) {
      in_ECX[1] = piVar1[1];
    }
    else {
      *(int *)(*piVar1 + 4) = piVar1[1];
    }
    if ((int *)piVar1[1] == (int *)0x0) {
      *in_ECX = *piVar1;
    }
    else {
      *(int *)piVar1[1] = *piVar1;
    }
    *piVar1 = 0;
    piVar1[1] = 0;
    in_ECX[2] = in_ECX[2] + -1;
    FUN_006334d0(piVar1,0x50);
    piVar1 = (int *)*in_ECX;
  }
  return;
}

