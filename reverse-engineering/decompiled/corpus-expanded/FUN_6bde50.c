/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6bde50; label: FUN_006bde50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006bde50(int param_1)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(in_ECX + 0x70)) {
    piVar1 = (int *)(in_ECX + 0x18);
    do {
      if ((*(int *)(param_1 + 4) == piVar1[-1]) && (*(int *)(param_1 + 8) == *piVar1)) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 3;
    } while (iVar2 < *(int *)(in_ECX + 0x70));
  }
  return 0;
}

