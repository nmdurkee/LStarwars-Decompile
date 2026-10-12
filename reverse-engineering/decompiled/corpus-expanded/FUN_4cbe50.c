/* Ghidra pseudocode, not original source.
 * ev_2c33bc1d2955cf32f461d40ab407fc477c117f7bb728ceb3ddb2ece88215ba87
 * Entry: 0x4cbe50; label: FUN_004cbe50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004cbe50(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x54);
  uVar2 = *(uint *)(iVar1 + 0x44);
  *(uint *)(param_1 + 0x4bc) = uVar2 | 0x20180040;
  if ((*(uint *)(param_1 + 0x1f8) & 1) == 0) {
    if ((*(uint *)(param_1 + 0x1f8) & 4) != 0) goto LAB_004cbe8b;
    uVar2 = uVar2 | 0x201800c0;
  }
  else {
    uVar2 = uVar2 | 0x20180140;
  }
  *(uint *)(param_1 + 0x4bc) = uVar2;
LAB_004cbe8b:
  if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x18) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 1;
  }
  if (((*(uint *)(iVar1 + 4) & 0x200000) == 0) && ((*(uint *)(iVar1 + 4) & 8) != 0)) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x1000;
  }
  if ((*(byte *)(iVar1 + 4) & 8) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 3;
  }
  if ((*(uint *)(*(int *)(iVar1 + 0x24) + 0x90) & 0x400000) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x23;
  }
  if ((*(uint *)(iVar1 + 4) & 0x40000) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x10;
  }
  if ((*(byte *)(iVar1 + 4) & 0x40) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x4004;
  }
  if ((*(uint *)(iVar1 + 4) & 0x100000) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 8;
  }
  if ((*(uint *)(iVar1 + 4) & 0x2000) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x10000;
  }
  if (((*(byte *)(iVar1 + 4) & 0x88) != 0) ||
     ((*(byte *)(*(int *)(iVar1 + 0x24) + 0x90) & 0x40) != 0)) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x8000;
  }
  if (*(char *)(param_1 + 0x280) != -1) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x20000;
  }
  if (*(short *)(param_1 + 0x1064) == DAT_007f18bc) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x4000;
  }
  return;
}

