/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c81b0; label: FUN_006c81b0
 */

int FUN_006c81b0(char *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  undefined4 unaff_ESI;
  char *pcVar3;
  
  pcVar3 = param_1;
  if (param_1 == (char *)0x0) {
    pcVar3 = "(NULL)";
  }
  iVar1 = FUN_004f1ff0(pcVar3);
  param_1 = (char *)(iVar1 + 1);
  iVar1 = (**(code **)(*in_ECX + 8))(&param_1,4,1);
  iVar2 = (**(code **)(*in_ECX + 8))(pcVar3,1,unaff_ESI);
  return iVar2 + iVar1;
}

