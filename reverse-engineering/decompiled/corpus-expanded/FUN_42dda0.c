/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x42dda0; label: FUN_0042dda0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0042dda0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return;
  }
  iVar1 = *(int *)(param_1 + 0xa4);
  if (iVar1 == 0) {
    return;
  }
  iVar2 = *(int *)(PTR_DAT_00802c54 + 300);
  if (iVar2 == 0) {
    return;
  }
  if (DAT_00951b50 != 0) {
    return;
  }
  if ((iVar2 == DAT_0087afa4) || (iVar2 == DAT_00951364)) {
    iVar1 = FUN_005cfa50(iVar1 + 0x30);
    if (iVar1 == 0) {
      return;
    }
    iVar2 = FUN_004f8a70(iVar1,"bin_lid");
    if (iVar2 != 0) {
      return;
    }
    iVar1 = FUN_004f8a70(iVar1,&DAT_007552ac);
    if (iVar1 == 0) {
      return;
    }
    iVar1 = FUN_0054fa60();
    if (0x4a < iVar1 / 0x290) {
      return;
    }
  }
  else {
    if (iVar2 != DAT_0087afa0) {
      if (iVar2 != DAT_0087b02c) {
        return;
      }
      if (4 < DAT_00876857) {
        return;
      }
      iVar1 = FUN_005cfa50(iVar1 + 0x30);
      if (iVar1 == 0) {
        return;
      }
      iVar2 = FUN_004f8a70(iVar1,&DAT_007552cc);
      if ((iVar2 == 0) && (iVar1 = FUN_004f8a70(iVar1,&DAT_007552c8), iVar1 == 0)) {
        return;
      }
      FUN_0043d890((int)DAT_007f1ac4,param_1 + 0x30,0,"blowup_spider",0,0,1,0,0,0,0x10);
      return;
    }
    iVar1 = FUN_005cfa50(iVar1 + 0x30);
    if (iVar1 == 0) {
      return;
    }
    iVar1 = FUN_004f8a70(iVar1,"womp_gen");
    if (iVar1 == 0) {
      return;
    }
  }
  FUN_0043d890((int)DAT_007f18c4,param_1 + 0x30,0,"spawned_womprat",0,0,1,0,0,0,0x10);
  return;
}

