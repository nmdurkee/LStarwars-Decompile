/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x597620; label: FUN_00597620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00597620(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_40 [48];
  float local_10;
  float local_c;
  float local_8;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x10ac) != 0)) &&
     (uVar3 = 0, *(short *)(*(int *)(param_1 + 0x10ac) + 0x10c) != 0)) {
    iVar4 = 0;
    do {
      *(undefined4 *)(param_1 + 0xff8) = *(undefined4 *)(*(int *)(param_1 + 0x10ac) + 0x108);
      local_48 = FUN_005be590(*(undefined4 *)(iVar4 + 0x10 + *(int *)(param_1 + 0x10ac)),0x8000);
      local_4c = *(undefined4 *)(iVar4 + 0x14 + *(int *)(param_1 + 0x10ac));
      FUN_005c0820(local_40,&local_4c);
      if (*(float *)(*(int *)(param_1 + 0x10ac) + 0x108) != 1.0) {
        local_58 = *(undefined4 *)(*(int *)(param_1 + 0x10ac) + 0x108);
        local_54 = local_58;
        local_50 = local_58;
        FUN_005b4c30(local_40,&local_58);
      }
      iVar2 = *(int *)(param_1 + 0x10ac);
      local_10 = *(float *)(iVar4 + iVar2) + local_10;
      local_c = *(float *)(iVar2 + 0x108) * _DAT_00805140 + *(float *)(iVar4 + 4 + iVar2) + local_c;
      local_8 = *(float *)(iVar4 + 8 + iVar2) + local_8;
      if (uVar3 == *(ushort *)(iVar2 + 0x10c) - 1) {
        uVar1 = 2;
      }
      else {
        uVar1 = uVar3 & 0x80000001;
        if ((int)uVar1 < 0) {
          uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
        }
      }
      iVar2 = FUN_005cfac0(&DAT_00955b48 + uVar1 * 0xc);
      if (iVar2 != 0) {
        FUN_005f33b0(&DAT_00955b48 + uVar1 * 0xc,local_40);
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 0x18;
    } while ((int)uVar3 < (int)(uint)*(ushort *)(*(int *)(param_1 + 0x10ac) + 0x10c));
  }
  return;
}

