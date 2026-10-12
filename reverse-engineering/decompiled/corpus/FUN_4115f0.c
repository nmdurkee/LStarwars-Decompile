/* Ghidra analysis pseudocode, not original source.
 * ev_67a1dd79f1152a4a8dc944803f9da200f64b6e45b6a6754633c37085e261482d
 * Entry: 0x4115f0; label: FUN_004115f0
 */

int FUN_004115f0(void)

{
  int iVar1;
  int *piVar2;
  
  if (*(int *)(PTR_DAT_00802c54 + 0x511c) != 0) {
    iVar1 = 0;
    piVar2 = (int *)(*(int *)(PTR_DAT_00802c54 + 0x511c) + 0x708);
    do {
      if (*piVar2 == 0) {
        return iVar1 * 0x680 + 0xa0 + *(int *)(PTR_DAT_00802c54 + 0x511c);
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x1a0;
    } while (iVar1 < 8);
  }
  return 0;
}

