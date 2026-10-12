/* Ghidra pseudocode, not original source.
 * ev_46856ff831ab396d087503af3f2d098038d70627b695f8c2598b186b09430fbf
 * Entry: 0x530b30; label: FUN_00530b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00530b30(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  char *pcVar4;
  undefined1 local_c [12];
  
  iVar2 = (param_1 + 10) * 0x10;
  FUN_005f35e0(DAT_009738b8,iVar2,param_2 * 8 + -0x28,0x10,"Area Editor");
  FUN_005d1060(DAT_009738b8,0x80000000);
  if (*(int *)(DAT_009238e4 + 0x383c8) == 0) {
    if (*(int *)(DAT_009238e4 + 0x383cc) != 0) {
      iVar1 = *(int *)(DAT_009238e4 + 0x383cc);
      goto LAB_00530b99;
    }
  }
  else {
    iVar1 = *(int *)(DAT_009238e4 + 0x383c8);
LAB_00530b99:
    if (iVar1 != 0) {
      fVar3 = (float10)FUN_005bed80(iVar1 + 0x18,DAT_009238e4 + 0x28,local_c);
      param_2 = param_2 + 0xf;
      FUN_005f35e0(DAT_009738b8,iVar2,param_2 * 8,0x10,"\"%s\", xzrng=%.2f",iVar1 + 8,
                   (double)(float)fVar3);
    }
  }
  FUN_005f35e0(DAT_009738b8,iVar2,(param_2 + 0xf) * 8,0x10,"SQR - Options");
  iVar1 = param_2 + 0x1e;
  if (*(int *)(DAT_009238e4 + 0x383cc) == 0) {
    FUN_005f35e0(DAT_009738b8,iVar2,iVar1 * 8,0x10,"X - Create area");
    pcVar4 = "SELECT - Select nearest";
LAB_00530d8e:
    iVar1 = iVar1 * 8 + 0x78;
  }
  else if (*(int *)(DAT_009238e4 + 0x383c8) == *(int *)(DAT_009238e4 + 0x383cc)) {
    FUN_005f35e0(DAT_009738b8,iVar2,iVar1 * 8,0x10,"X - Move selected/Adjust size");
    if ((*(byte *)(DAT_009238e4 + 0xc3938) & 0x40) != 0) {
      if ((*(byte *)(*(int *)(DAT_009238e4 + 0x383cc) + 0x33) & 1) != 0) {
        FUN_005f35e0(DAT_009738b8,iVar2,iVar1 * 8 + 0x78,0x10,"LRIGHT/LLEFT - Adjust Radius");
        goto LAB_00530da7;
      }
      iVar1 = param_2 + 0x2d;
      FUN_005f35e0(DAT_009738b8,iVar2,iVar1 * 8,0x10,"LRIGHT/LLEFT - Adjust X size");
      pcVar4 = "LUP/LDOWN - Adjust Z size";
      goto LAB_00530d8e;
    }
    iVar1 = param_2 + 0x2d;
    FUN_005f35e0(DAT_009738b8,iVar2,iVar1 * 8,0x10,"TRI - Delete selected");
    if ((*(byte *)(*(int *)(DAT_009238e4 + 0x383cc) + 0x33) & 1) == 0) {
      iVar1 = param_2 + 0x3c;
      FUN_005f35e0(DAT_009738b8,iVar2,iVar1 * 8,0x10,"LLEFT/LRIGHT - Rotate");
    }
    FUN_005f35e0(DAT_009738b8,iVar2,(iVar1 + 0xf) * 8,0x10,"LUP - Increase height");
    pcVar4 = "LDOWN - Decrease height";
    iVar1 = (iVar1 + 0xf) * 8 + 0x78;
  }
  else {
    FUN_005f35e0(DAT_009738b8,iVar2,iVar1 * 8,0x10,"X - Select area");
    pcVar4 = "SELECT - Select nearest";
    iVar1 = iVar1 * 8 + 0x78;
  }
  FUN_005f35e0(DAT_009738b8,iVar2,iVar1,0x10,pcVar4);
LAB_00530da7:
  FUN_00521800();
  FUN_00524190();
  if (((byte)DAT_00921f50 & 8) != 0) {
    FUN_0052a760();
  }
  FUN_00528010();
  FUN_005226b0();
  return;
}

