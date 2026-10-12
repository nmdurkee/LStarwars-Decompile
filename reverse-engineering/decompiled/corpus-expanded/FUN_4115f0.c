/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x4115f0; label: FUN_004115f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

