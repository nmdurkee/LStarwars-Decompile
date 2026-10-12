/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x5339d0; label: FUN_005339d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005339d0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined8 uVar5;
  
  if (*(int *)(DAT_009238e4 + 0x4868) == 0) goto LAB_00533d5d;
  iVar3 = (param_1 + 10) * 0x10;
  if (((byte)DAT_00921f50 & 1) == 0) {
    FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + -0x28,0x10,"AI Path Editor: \"%s\"",
                 *(int *)(DAT_009238e4 + 0x4868) + 8);
    FUN_005d1060(DAT_009738b8,0x80000000);
    FUN_005d0fe0(DAT_009738b8,param_3,param_4);
    iVar2 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
    if (iVar2 == 0) {
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x78,0x10,"%d nodes",
                   (int)*(short *)(*(int *)(DAT_009238e4 + 0x4868) + 0x36));
    }
    else {
      pcVar4 = (char *)(iVar2 + 8);
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      if (pcVar4 == (char *)(iVar2 + 9)) {
        uVar5 = CONCAT44((int)*(short *)(*(int *)(DAT_009238e4 + 0x4868) + 0x36),
                         (int)*(short *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0x90));
        pcVar4 = "ix=%d, %d nodes";
      }
      else {
        uVar5 = CONCAT44((int)*(short *)(*(int *)(DAT_009238e4 + 0x4868) + 0x36),
                         *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 8);
        pcVar4 = "\"%s\" %d nodes";
      }
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x78,0x10,pcVar4,uVar5);
    }
    FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0xf0,0x10,"SQR - Sub menu");
    FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x168,0x10,"SELECT - Select nearest");
    if ((*(byte *)(DAT_009238e4 + 0x43828) & 1) == 0) {
      if (*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x24) != 0) {
        FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x1e0,0x10,"X - Select");
        pcVar4 = "O - Link/unlink to selected";
        iVar2 = param_2 * 8 + 0x2d0;
        goto LAB_00533d28;
      }
      pcVar4 = "X - Create";
      iVar2 = param_2 * 8 + 0x1e0;
    }
    else {
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x1e0,0x10,"X - Move selected");
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 600,0x10,"TRI - Delete selected");
      if ((*(int *)(DAT_009238e4 + 0x4868) == 0) ||
         (iVar2 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20), iVar2 == 0)) {
        FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x348,0x10,"LRIGHT - Increase radius");
      }
      else {
        FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x348,0x10,"LRIGHT - Increase radius, %.2f",
                     (double)*(float *)(iVar2 + 0x24));
      }
      pcVar4 = "LLEFT - Decrease radius";
      iVar2 = param_2 * 8 + 0x3c0;
    }
    FUN_005f35e0(DAT_009738b8,iVar3,iVar2,CONCAT44(pcVar4,0x10));
  }
  else {
    FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + -0x28,0x10,"Show Routes : \"%s\"",
                 *(int *)(DAT_009238e4 + 0x4868) + 8);
    FUN_005d1060(DAT_009738b8,0x80000000);
    FUN_005d0fe0(DAT_009738b8,param_3,param_4);
    FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x78,0x10,&DAT_007608a4,
                 *(int *)(DAT_009238e4 + 0x4868) + 8);
    FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0xf0,0x10,"SQR - Sub menu");
    FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x168,0x10,"SELECT - Goto nearest");
    if (*(short *)(*(int *)(DAT_009238e4 + 0x4868) + 0x34) < 0) goto LAB_00533d5d;
    FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x1e0,0x10,"TRI - Set as start of route");
    pcVar4 = "X - Set as end of route";
    iVar2 = param_2 * 8 + 600;
LAB_00533d28:
    FUN_005f35e0(DAT_009738b8,iVar3,iVar2,0x10,pcVar4);
  }
LAB_00533d5d:
  if (((byte)DAT_00921f50 & 1) != 0) {
    FUN_00524b70();
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

