/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6bdfe0; label: FUN_006bdfe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006bdfe0(int param_1)

{
  int iVar1;
  
  do {
    iVar1 = param_1;
    if (iVar1 == 0) {
      return 0;
    }
    param_1 = *(int *)(iVar1 + 0x3c);
  } while (*(int *)(iVar1 + 0x3c) != 0);
  return iVar1;
}

