/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x5342d0; label: FUN_005342d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005342d0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined1 local_c [12];
  
  iVar3 = (param_1 + 10) * 0x10;
  FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + -0x28,0x10,"Antinode Editor");
  FUN_005d1060(DAT_009738b8,0x80000000);
  FUN_005d0fe0(DAT_009738b8,param_3,param_4);
  if (*(int *)(DAT_009238e4 + 0x4381c) == 0) {
    if (*(int *)(DAT_009238e4 + 0x43820) != 0) {
      iVar2 = *(int *)(DAT_009238e4 + 0x43820);
      goto LAB_00534345;
    }
  }
  else {
    iVar2 = *(int *)(DAT_009238e4 + 0x4381c);
LAB_00534345:
    if (iVar2 != 0) {
      FUN_005bed80(iVar2 + 8,DAT_009238e4 + 0x28,local_c);
    }
  }
  if (*(int *)(DAT_009238e4 + 0x43820) == 0) {
    FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0xf0,0x10,"X - Create antinode");
    pcVar4 = "SELECT - Select nearest";
    iVar2 = param_2 * 8 + 0x168;
  }
  else if (*(int *)(DAT_009238e4 + 0x4381c) == *(int *)(DAT_009238e4 + 0x43820)) {
    iVar2 = FUN_005cfa50();
    if (iVar2 == 0) {
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x78,0x10,"Not attached to platform");
    }
    else {
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x78,0x10,"Platform=%s",iVar2);
    }
    FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0xf0,0x10,"X - Move selected/Adjust size");
    FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x168,0x10,"TRI - Delete selected");
    iVar2 = *(int *)(DAT_009238e4 + 0x4381c);
    if (*(char *)(iVar2 + 0x49) == '\0') {
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x1e0,0x10,"LRIGHT - Increase radius, %.2f",
                   (double)*(float *)(iVar2 + 0x14));
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 600,0x10,"LLEFT - Decrease radius");
      goto LAB_00534699;
    }
    uVar1 = *(uint *)(DAT_009238e4 + 0xc3938);
    if ((uVar1 & 0x40) != 0) {
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x1e0,0x10,"LRIGHT - Increase X, %.2f",
                   (double)*(float *)(iVar2 + 0x40));
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 600,0x10,"LLEFT - Decrease X");
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x2d0,0x10,"LUP - Increase Z, %.2f",
                   (double)*(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x44));
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x348,0x10,"LDOWN - Decrease Z");
      goto LAB_00534699;
    }
    if (((int)(DAT_00921f50 << 0x17) < 0) && ((uVar1 & 0x1000) != 0)) {
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x1e0,0x10,"L1 - Increase upper height");
      pcVar4 = "R1 - Decrease upper height";
      iVar2 = param_2 * 8 + 600;
    }
    else if (((int)(DAT_00921f50 << 0x17) < 0) && ((uVar1 & 0x4000) != 0)) {
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x1e0,0x10,"L1 - Increase lower height");
      pcVar4 = "R1 - Decrease lower height";
      iVar2 = param_2 * 8 + 600;
    }
    else {
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x1e0,0x10,"LLEFT - Rotate left");
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 600,0x10,"LRIGHT - Rotate right");
      if ((DAT_00921f50 & 0x100) == 0) goto LAB_00534699;
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x2d0,0x10,"LUP - Adjust upper height");
      pcVar4 = "LDOWN - Adjust lower height";
      iVar2 = param_2 * 8 + 0x348;
    }
  }
  else {
    FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0xf0,0x10,"X - Select antinode");
    pcVar4 = "SELECT - Select nearest";
    iVar2 = param_2 * 8 + 0x168;
  }
  FUN_005f35e0(DAT_009738b8,iVar3,iVar2,0x10,pcVar4);
LAB_00534699:
  FUN_00528010();
  FUN_00521800();
  FUN_00524190();
  if ((DAT_00921f50 & 8) != 0) {
    FUN_0052a760();
  }
  FUN_005226b0();
  return;
}

