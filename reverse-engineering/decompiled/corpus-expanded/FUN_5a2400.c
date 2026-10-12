/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a2400; label: FUN_005a2400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005a2400(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort *in_ECX;
  int iVar5;
  
  iVar4 = *(int *)(in_ECX + 4);
  iVar2 = *(int *)(in_ECX + 6);
  if (in_ECX[1] < *in_ECX) {
    piVar1 = (int *)(iVar4 + 0x78);
    if (*piVar1 == iVar4) {
      iVar5 = 0;
    }
    else {
      *(undefined4 *)(*piVar1 + 0x7c) = *(undefined4 *)(iVar4 + 0x7c);
      *(int *)(*(int *)(iVar4 + 0x7c) + 0x78) = *piVar1;
      iVar5 = *piVar1;
    }
    if (iVar2 == 0) {
      *piVar1 = iVar4;
      *(int *)(iVar4 + 0x7c) = iVar4;
    }
    else {
      iVar3 = *(int *)(iVar2 + 0x78);
      *piVar1 = iVar3;
      *(int *)(iVar3 + 0x7c) = iVar4;
      *(int *)(iVar4 + 0x7c) = iVar2;
      *(int *)(iVar2 + 0x78) = iVar4;
    }
    in_ECX[1] = in_ECX[1] + 1;
    *(int *)(in_ECX + 4) = iVar5;
    *(int *)(in_ECX + 6) = iVar4;
    if (in_ECX[1] == *in_ECX) {
      in_ECX[4] = 0;
      in_ECX[5] = 0;
      return iVar4;
    }
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}

