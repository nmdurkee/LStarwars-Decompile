/* Ghidra pseudocode, not original source.
 * ev_8c08cb58b3e2eca2ce3b645626710873c7692325f2a23ef4bde2c2500b41a2fb
 * Entry: 0x442d70; label: FUN_00442d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442d70(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &DAT_0093d7f0;
  while ((((iVar1 = *piVar2, iVar1 == 0 || ((*(uint *)(iVar1 + 0x1fc) & 1) == 0)) ||
          ((*(uint *)(iVar1 + 0x1fc) & 0x1000) == 0)) ||
         (((*(byte *)(iVar1 + 0xef3) & 1) != 0 ||
          ((*(byte *)(*(int *)(iVar1 + 0x54) + 4) & 0x10) == 0))))) {
    piVar2 = piVar2 + 1;
    if (0x93d80f < (int)piVar2) {
      return (float10)0;
    }
  }
  return (float10)1;
}

