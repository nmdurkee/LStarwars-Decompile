/* Ghidra pseudocode, not original source.
 * ev_63eb9bd68174043ae1497f20c7ab174ab5c86e6d078dec24e1a9d3709ec9fcaa
 * Entry: 0x5fa6d0; label: FUN_005fa6d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005fa6d0(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  char *pcVar2;
  int unaff_EDI;
  
  pcVar2 = (char *)(*(int *)(in_EAX + 0x10) + 3 + (*(int *)(in_EAX + 4) * param_2 + param_1) * 4);
  iVar1 = 0;
  if (0 < unaff_EDI) {
    do {
      if (*(int *)(in_EAX + 8) <= iVar1 + param_2) {
        return 0;
      }
      if (*pcVar2 != '\0') {
        return 1;
      }
      iVar1 = iVar1 + 1;
      pcVar2 = pcVar2 + *(int *)(in_EAX + 4) * 4;
    } while (iVar1 < unaff_EDI);
  }
  return 0;
}

