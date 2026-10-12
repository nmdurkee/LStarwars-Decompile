/* Ghidra pseudocode, not original source.
 * ev_63eb9bd68174043ae1497f20c7ab174ab5c86e6d078dec24e1a9d3709ec9fcaa
 * Entry: 0x5fa690; label: FUN_005fa690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005fa690(int param_1,int param_2)

{
  byte *pbVar1;
  int in_ECX;
  int iVar2;
  int unaff_ESI;
  uint unaff_EDI;
  
  iVar2 = 0;
  pbVar1 = (byte *)(*(int *)(in_ECX + 4) * param_2 + *(int *)(in_ECX + 0x10) + param_1);
  if (0 < unaff_ESI) {
    do {
      if (*pbVar1 != unaff_EDI) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      pbVar1 = pbVar1 + *(int *)(in_ECX + 4);
    } while (iVar2 < unaff_ESI);
  }
  return 0;
}

