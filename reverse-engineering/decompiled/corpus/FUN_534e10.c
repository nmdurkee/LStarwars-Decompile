/* Ghidra analysis pseudocode, not original source.
 * ev_b3428d17d7a525986d1be417305dad2f8f354c51dc50a167d24fd678dc156e11
 * Entry: 0x534e10; label: FUN_00534e10
 */

void FUN_00534e10(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if ((param_3 & 1) == 0) {
    iVar3 = *(int *)(param_2 + 4);
  }
  else {
    iVar5 = *(int *)(param_1 + 4);
    if ((*(int *)(iVar5 + 0x158) == 0) ||
       (iVar3 = *(int *)(param_2 + 4), *(int *)(iVar5 + 0x158) != *(int *)(iVar3 + 0x158))) {
      iVar3 = *(int *)(param_2 + 4);
      uVar4 = 7;
      iVar5 = iVar3 + 0x14c;
      goto LAB_00534edc;
    }
    if (((((*(byte *)(iVar3 + 0x166) & 1) == 0) &&
         (*(int *)(iVar5 + 0x15c) == *(int *)(iVar3 + 0x15c))) || (*(int *)(iVar5 + 0x15c) == 0)) ||
       (((*(int *)(iVar3 + 0x15c) == 0 || ((*(uint *)(iVar5 + 0x1e8) & 0x100000) != 0)) ||
        ((bVar2 = *(byte *)(*(int *)(iVar3 + 0x15c) + 0x10),
         *(char *)((uint)bVar2 +
                  *(int *)(*(int *)(*(int *)(iVar5 + 0x158) + 0x84) +
                          (uint)*(byte *)(*(int *)(iVar5 + 0x15c) + 0x10) * 4)) == -1 &&
         (*(byte *)(*(int *)(iVar5 + 0x15c) + 0x10) != bVar2)))))) {
      uVar4 = 7;
      iVar5 = iVar3 + 0x14c;
      goto LAB_00534edc;
    }
  }
  uVar4 = 1;
  iVar5 = iVar3 + 0x170;
LAB_00534edc:
  if ((param_3 & 2) == 0) {
    uVar1 = *(undefined4 *)(iVar3 + 0x120);
  }
  else {
    uVar1 = 0;
  }
  FUN_0052fcb0(*(undefined4 *)(param_1 + 4),iVar5,uVar1,iVar3 + 0x158,uVar4,param_4);
  return;
}

