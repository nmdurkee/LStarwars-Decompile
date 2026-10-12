/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6be260; label: FUN_006be260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006be260(code *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))(param_1);
  while ((iVar1 != 0 && (iVar2 = (*param_1)(iVar1), iVar2 == 0))) {
    iVar1 = (**(code **)(*in_ECX + 0x14))(iVar1);
  }
  return iVar1;
}

