/* Ghidra pseudocode, not original source.
 * ev_22f771e0c18b367a4d7c01bf756cd775085513b89e8d82bf660ad444254c899f
 * Entry: 0x6bee00; label: FUN_006bee00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bee00(void)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int unaff_retaddr;
  
  iVar2 = (**(code **)(*in_ECX + 0x14))(0);
  while (iVar1 = iVar2, iVar1 != 0) {
    iVar2 = (**(code **)(*in_ECX + 0x14))(iVar1);
    if (*(short *)(iVar1 + 6) == unaff_retaddr) {
      (**(code **)(*in_ECX + 0x1c))(iVar1,0);
    }
  }
  iVar2 = 0;
  do {
    if (unaff_retaddr == iVar2) {
      in_ECX[iVar2 + 7] = 0;
      in_ECX[iVar2 + 0x11] = 0;
      return;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 10);
  return;
}

