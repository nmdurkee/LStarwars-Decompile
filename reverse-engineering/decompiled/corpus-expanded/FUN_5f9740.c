/* Ghidra pseudocode, not original source.
 * ev_742d340bc2a041ef5ff6078bdc4a89a7f4acdb81012c0f9f5c92fd03ca8daa18
 * Entry: 0x5f9740; label: FUN_005f9740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f9740(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int unaff_EBX;
  int iVar3;
  uint uStack_3c;
  float *pfStack_2c;
  undefined8 uStack_28;
  int iStack_1c;
  
  uStack_3c = 0x20;
  (**(code **)(*param_3 + 0x90))(param_3,"mtxWaterTable",&DAT_028358a8);
  if (DAT_02854bec == 0) {
    FUN_006e4810(96000,0x208,0,0,&DAT_02854bec);
  }
  FUN_006e5b90(*(int *)(*(int *)(param_2 + 0x2c) + 0x3c) * 0x24,*(int *)(param_2 + 0x10) * 0x24,
               &pfStack_2c,0,*(undefined4 *)(param_2 + 0x48));
  FUN_006e5b90(0,0,&stack0xffffffd0,0x2000,DAT_02854bec);
  iVar3 = 0;
  iStack_1c = unaff_EBX;
  if (0 < *(int *)(param_2 + 0x10)) {
    do {
      uStack_28._0_4_ = (uint)(longlong)ROUND(*pfStack_2c);
      uVar2 = (uint)uStack_28;
      uStack_28 = (ulonglong)ROUND(pfStack_2c[2]);
      uStack_3c = ((uint)uStack_28 * 4 ^ uVar2) * 8 ^ (uint)uStack_28 * uVar2;
      FUN_005b9d90(&uStack_3c);
      iVar1 = FUN_006e6b90();
      uStack_28._0_4_ = iVar1;
      FUN_005b9d90(&uStack_3c);
      iVar1 = FUN_006e6b90();
      uVar2 = iVar1 + (uint)uStack_28;
      uStack_28 = CONCAT44(uStack_28._4_4_,uVar2) & 0xffffffff0000001f;
      iVar3 = iVar3 + 1;
      *(float *)(iStack_1c + -4 + iVar3 * 4) = (float)(uVar2 & 0x1f);
      pfStack_2c = pfStack_2c + 9;
    } while (iVar3 < *(int *)(param_2 + 0x10));
  }
  FUN_006e5bc0(*(undefined4 *)(param_2 + 0x48));
  FUN_006e5bc0(DAT_02854bec);
  if ((*(int *)(param_2 + 0x6c) != 0x400) && (*(int *)(param_2 + 0x6c) != 0x480)) {
    FUN_006e5590(1,DAT_02854bec,0,4);
    return;
  }
  FUN_006e5590(2,DAT_02854bec,0,4);
  return;
}

