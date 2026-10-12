/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62e000; label: FUN_0062e000
 */

undefined2 FUN_0062e000(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 != 0) {
    for (piVar2 = *(int **)(param_1 + 0x10); (piVar2 != (int *)0x0 && (*piVar2 != 0));
        piVar2 = piVar2 + 0x13) {
      iVar1 = FUN_004f8b10(param_2,*piVar2);
      if (iVar1 == 0) {
        return (short)piVar2[2];
      }
    }
  }
  return 0xffff;
}

