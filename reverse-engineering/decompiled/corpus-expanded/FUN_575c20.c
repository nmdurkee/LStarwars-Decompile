/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x575c20; label: FUN_00575c20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00575c20(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int *piVar5;
  
  if ((*(byte *)(param_2 + 0xf5) & 0x10) != 0) {
    if (DAT_0093d7f0 == 0) {
      return;
    }
    if ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) == 0) {
      return;
    }
    if (DAT_0093d7f4 == 0) {
      return;
    }
    if ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) == 0) {
      return;
    }
  }
  if (DAT_00951b80 != 0) {
    return;
  }
  if (*(short *)(param_2 + 0xf0) == -1) goto LAB_00575ead;
  FUN_004f1f10(&DAT_009513b8,param_2);
  if ((*(int *)(param_2 + 0x120) == 0) ||
     (iVar2 = FUN_0057cdd0(*(int *)(param_2 + 0x120)), iVar2 != 0)) {
    DAT_00951384 = 0;
LAB_00575ce4:
    iVar2 = FUN_0055c690();
    if (((iVar2 == 0) ||
        (iVar2 = (int)*(short *)(param_2 + 0xf0), iVar2 == *(int *)(param_1 + 0x11c))) &&
       ((iVar2 = FUN_0055c690(), iVar2 != 0 ||
        (iVar2 = (int)*(short *)(param_2 + 0xf2), iVar2 == *(int *)(param_1 + 0x11c))))) {
      FUN_00575820();
      FUN_0055c5f0();
      piVar5 = &DAT_0093d7f4;
      puVar4 = &DAT_0093d519;
      do {
        iVar2 = piVar5[-1];
        if (iVar2 != 0) {
          puVar4[2] = *(char *)(iVar2 + 0xe32) == '\x01';
          if (*(char *)(iVar2 + 0x28b) == '\0') {
            uVar1 = *(undefined1 *)(iVar2 + 0xe39);
          }
          else {
            uVar1 = 4;
          }
          *puVar4 = uVar1;
        }
        iVar2 = *piVar5;
        if (iVar2 != 0) {
          puVar4[0x12] = *(char *)(iVar2 + 0xe32) == '\x01';
          if (*(char *)(iVar2 + 0x28b) == '\0') {
            uVar1 = *(undefined1 *)(iVar2 + 0xe39);
          }
          else {
            uVar1 = 4;
          }
          puVar4[0x10] = uVar1;
        }
        iVar2 = piVar5[1];
        if (iVar2 != 0) {
          puVar4[0x22] = *(char *)(iVar2 + 0xe32) == '\x01';
          if (*(char *)(iVar2 + 0x28b) == '\0') {
            uVar1 = *(undefined1 *)(iVar2 + 0xe39);
          }
          else {
            uVar1 = 4;
          }
          puVar4[0x20] = uVar1;
        }
        iVar2 = piVar5[2];
        if (iVar2 != 0) {
          puVar4[0x32] = *(char *)(iVar2 + 0xe32) == '\x01';
          if (*(char *)(iVar2 + 0x28b) == '\0') {
            uVar1 = *(undefined1 *)(iVar2 + 0xe39);
          }
          else {
            uVar1 = 4;
          }
          puVar4[0x30] = uVar1;
        }
        piVar5 = piVar5 + 4;
        puVar4 = puVar4 + 0x40;
      } while ((int)piVar5 < 0x93d814);
      DAT_00951428 = 1;
    }
    else {
      DAT_00951b80 = iVar2 * 0x130 + DAT_00951b78;
      if ((DAT_0093b2a4 != 0) && ((*(byte *)(DAT_00951b80 + 100) & 0x80) != 0)) {
        DAT_00951b80 = FUN_00573520(*(undefined4 *)(PTR_DAT_00802c54 + 300),0);
        if (DAT_00951b80 == 0) {
          DAT_00951b80 = iVar2 * 0x130 + DAT_00951b78;
        }
        else if (DAT_00856c08 != 0) {
          DAT_00856c08 = 4;
        }
      }
    }
  }
  else {
    iVar2 = *(int *)(param_2 + 0x120);
    if (iVar2 == 0) goto LAB_00575ce4;
    if (DAT_00951384 == 0) {
      DAT_00951c74 = iVar2;
      FUN_00575820();
      FUN_0055c5f0();
    }
    else {
      iVar3 = FUN_0055f450(0,0);
      FUN_0057cd30(iVar2,*(undefined4 *)(iVar3 + 0x2ab0));
    }
  }
  DAT_00803874 = (int)*(char *)(param_2 + 0xf4);
  FUN_00575710(param_2);
LAB_00575ead:
  _DAT_0093b2ac = _DAT_0093b2ac | 8;
  if ((DAT_00951b80 != 0) && (DAT_00951b80 != *(int *)(param_1 + 0x128))) {
    if (*(int *)(param_1 + 300) == DAT_00951364) {
      FUN_0047a990(&DAT_00951b80);
    }
    else if ((int)*(char *)(DAT_00951b80 + 0xa3) == *(int *)(param_1 + 0x120)) {
      DAT_00951388 = 1;
    }
  }
  DAT_009513b0 = param_2;
  if (DAT_00951430 != (code *)0x0) {
    (*DAT_00951430)(param_1,param_2);
  }
  return;
}

