/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d2690; label: FUN_005d2690
 */

void FUN_005d2690(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  FUN_004f7fb0(param_1);
  iVar2 = DAT_00971580;
  *(undefined1 *)(*(int *)(param_1 + 0x510) + 0x20) = 0;
  pcVar3 = *(char **)(param_1 + 0x510);
  pcVar4 = (char *)(iVar2 + 8);
  do {
    cVar1 = *pcVar3;
    *pcVar4 = cVar1;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  return;
}

