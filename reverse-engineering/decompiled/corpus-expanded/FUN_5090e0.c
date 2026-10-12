/* Ghidra pseudocode, not original source.
 * ev_0b3cdb0849a5c3a2f544331fa814d8282bd684db9c1ec6ffa505f1c54b54b4d0
 * Entry: 0x5090e0; label: FUN_005090e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005090e0(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(in_ECX + 0x640);
  while (((iVar1 == 0 || (*(char *)(in_ECX + 0x63c) == '\0')) || (*piVar2 == -1))) {
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
    if (iVar1 == 5) {
      return 0;
    }
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}

