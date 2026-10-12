/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x534110; label: FUN_00534110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00534110(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(DAT_009238e4 + 0x4868) != 0) {
    iVar2 = (param_1 + 10) * 0x10;
    FUN_005f35e0(DAT_009738b8,iVar2,param_2 * 8 + -0x28,0x10,"Edit Routes (Path = \"%s\")",
                 *(int *)(DAT_009238e4 + 0x4868) + 8);
    FUN_005d1060(DAT_009738b8,0x80000000);
    FUN_005d0fe0(DAT_009738b8,param_3,param_4);
    iVar1 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28);
    if (iVar1 == 0) {
      FUN_005f35e0(DAT_009738b8,iVar2,param_2 * 8 + 0x78,0x10,"NO ROUTES AVAILABLE");
    }
    else {
      FUN_005f35e0(DAT_009738b8,iVar2,param_2 * 8 + 0x78,0x10,&DAT_007608a4,iVar1);
    }
    if (*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) != 0) {
      FUN_005f35e0(DAT_009738b8,iVar2,param_2 * 8 + 0xf0,0x10,"SQR - Sub menu");
      FUN_005f35e0(DAT_009738b8,iVar2,param_2 * 8 + 0x168,0x10,"SELECT - Select nearest");
      iVar1 = *(int *)(DAT_009238e4 + 0x4868);
      if ((*(int *)(iVar1 + 0x24) != 0) && (*(int *)(iVar1 + 0x24) != *(int *)(iVar1 + 0x20))) {
        FUN_005f35e0(DAT_009738b8,iVar2,param_2 * 8 + 0x1e0,0x10,"X - Select");
      }
      if (((*(byte *)(DAT_009238e4 + 0x43828) & 1) == 0) &&
         (*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x24) != 0)) {
        FUN_005f35e0(DAT_009738b8,iVar2,param_2 * 8 + 0x2d0,0x10,"O - Add/remove cnx to route.");
      }
    }
  }
  FUN_00524190();
  if (((byte)DAT_00921f50 & 8) != 0) {
    FUN_0052a760();
  }
  FUN_00521800();
  FUN_005226b0();
  FUN_00528010();
  return;
}

