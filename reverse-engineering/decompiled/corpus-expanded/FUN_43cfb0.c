/* Ghidra pseudocode, not original source.
 * ev_26d1fac8fd457d7aa06190d117e50b4f3cb6f2e0dd1b5e3302fd798cb5ca6742
 * Entry: 0x43cfb0; label: FUN_0043cfb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0043cfb0(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
    return;
  }
  iVar3 = 1;
  switch(*(undefined1 *)(param_1 + 0xa4)) {
  case 0:
    iVar2 = FUN_005d0420((int *)(param_1 + 0xc));
    if ((iVar2 != 0) &&
       (iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x54) +
                        (uint)*(ushort *)(iVar2 + 0x5c) * 4), iVar2 != 0)) {
      FUN_005ca4b0(iVar2);
      goto LAB_0043d017;
    }
    break;
  case 1:
    goto LAB_0043d017;
  case 2:
  case 3:
  case 4:
  case 6:
    goto LAB_0043d0a0;
  case 5:
LAB_0043d017:
    iVar3 = FUN_006e6b90();
    if (0x400 < iVar3) {
      iVar3 = 0x400;
    }
  }
  iVar2 = iVar3;
  if ((param_2 != -1) && (iVar2 = param_2, param_2 == -2)) {
    iVar2 = iVar3 + -1;
  }
  iVar4 = iVar3;
  if ((param_3 != -1) && (iVar4 = param_3, param_3 == -2)) {
    iVar4 = iVar3 + -1;
  }
  if (iVar2 < 1) {
    iVar2 = 1;
  }
  if (iVar3 < iVar4) {
    iVar4 = iVar3;
  }
  for (iVar2 = iVar2 + -1; iVar2 <= iVar4 + -1; iVar2 = iVar2 + 1) {
    puVar1 = (uint *)(param_1 + 0x24 + ((int)(iVar2 + (iVar2 >> 0x1f & 0x1fU)) >> 5) * 4);
    *puVar1 = *puVar1 | 1 << ((byte)iVar2 & 0x1f);
  }
LAB_0043d0a0:
  return;
}

