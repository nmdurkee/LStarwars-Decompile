/* Ghidra pseudocode, not original source.
 * ev_554bacc3f16b6ba5ba2e9bdc745347cbc06d0daeabfbc4224973a16c83b60b9e
 * Entry: 0x4c00c0; label: FUN_004c00c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

