/* Ghidra analysis pseudocode, not original source.
 * ev_9e834adbd1be5074ad62417c72633ab4044f13767a5707860f49455a6f85e9eb
 * Entry: 0x407b60; label: FUN_00407b60
 */

void FUN_00407b60(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x50);
  iVar2 = *(int *)(param_1 + 0x54);
  uVar4 = *(uint *)(iVar2 + 0x44);
  *(uint *)(param_1 + 0x4bc) = uVar4 | 0x20000040;
  if ((*(int *)(*(int *)(iVar1 + 0xc) + 0x220) != 0) &&
     (*(int *)(*(int *)(iVar1 + 0xc) + 0x224) != 0)) {
    if ((*(uint *)(*(int *)(iVar2 + 0x24) + 0x90) & 0x80000) == 0) {
      uVar4 = uVar4 | 0x20080040;
    }
    else {
      uVar4 = uVar4 | 0x20040040;
    }
    *(uint *)(param_1 + 0x4bc) = uVar4;
  }
  iVar3 = *(int *)(iVar1 + 0xc);
  if (((*(int *)(iVar3 + 0x228) != 0) && (*(int *)(iVar3 + 0x22c) != 0)) &&
     (*(int *)(iVar3 + 0x230) != 0)) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x400000;
  }
  if (*(int *)(*(int *)(iVar1 + 0xc) + 0x334) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x100000;
  }
  if (*(int *)(*(int *)(iVar1 + 0xc) + 0x18) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 1;
  }
  if ((*(uint *)(*(int *)(iVar2 + 0x24) + 0x90) & 0x400000) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x20;
  }
  if ((*(uint *)(*(int *)(iVar2 + 0x24) + 0x90) & 0x40000000) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 2;
  }
  if (*(int *)(param_1 + 0xcbc) != 0) {
    *(uint *)(param_1 + 0x4bc) =
         *(uint *)(param_1 + 0x4bc) | *(uint *)(*(int *)(param_1 + 0xcbc) + 0x10);
  }
  if ((*(uint *)(param_1 + 0x1f8) & 1) == 0) {
    if ((*(uint *)(param_1 + 0x1f8) & 4) == 0) {
      *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x80;
    }
  }
  else {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x100;
  }
  *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x1000;
  if ((*(uint *)(iVar2 + 4) & 0x40000) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x10;
  }
  if ((*(uint *)(iVar2 + 4) & 0x100000) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 8;
  }
  if ((*(uint *)(iVar2 + 4) & 0x2000) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x10000;
  }
  if (((*(byte *)(iVar2 + 4) & 0x88) != 0) ||
     ((*(byte *)(*(int *)(iVar2 + 0x24) + 0x90) & 0x40) != 0)) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x8000;
  }
  if (*(char *)(param_1 + 0x280) != -1) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x20000;
  }
  if ((*(uint *)(*(int *)(iVar2 + 0x24) + 0x90) & 0x4000000) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x800000;
  }
  return;
}

