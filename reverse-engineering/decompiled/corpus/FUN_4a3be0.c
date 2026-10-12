/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a3be0; label: FUN_004a3be0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a3be0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  uint local_c;
  float local_8;
  float local_4;
  
  if ((((*(char *)(unaff_EDI + 0x7b5) == '\x1c') &&
       (iVar2 = *(int *)(unaff_EDI + 0x790), iVar2 != 0)) && (*(char *)(iVar2 + 0x7b5) == '\x1b'))
     && ((((*(uint *)(iVar2 + 0xe20) & 0x100) == 0 && (-1 < (char)*(uint *)(unaff_EDI + 0xe20))) &&
         ((*(uint *)(unaff_EDI + 0xe20) & 0x200) == 0)))) {
    if ((*(char *)(unaff_EDI + 0x7b8) == '\x04') && (iVar3 = FUN_0056e160(0x13), iVar3 != 0)) {
      if ((*(uint *)(iVar2 + 0x1e8) & *(uint *)(unaff_EDI + 0x1f0)) != 0 ||
          (*(uint *)(iVar2 + 0x1ec) & *(uint *)(unaff_EDI + 500)) != 0) {
        local_8 = *(float *)(iVar2 + 0x80) - *(float *)(unaff_EDI + 0x80);
        local_c = FUN_005be2d0(local_8,*(float *)(iVar2 + 0x88) - *(float *)(unaff_EDI + 0x88));
        local_c = local_c & 0xffff;
        DAT_00955580 = &local_c;
        iVar3 = FUN_00438230(0);
        if (iVar3 == 2) {
          FUN_0054a850(**(undefined4 **)(iVar2 + 0xca4),0x3f000000,0);
          FUN_0054a8a0(**(undefined4 **)(iVar2 + 0xca4),0x3dcccccd,0);
          FUN_00549f10();
          return;
        }
      }
    }
    else if ((DAT_0087b908 != 0) && (local_8 = 0.0, iVar3 = DAT_0093d504, 0 < DAT_0093d500)) {
      do {
        iVar4 = FUN_004a3b60();
        if ((iVar4 != 0) &&
           (((*(short *)(iVar3 + 0x1064) != DAT_007f1a50 || (*(char *)(iVar3 + 0x7b5) != '\x17')) &&
            ((*(uint *)(iVar3 + 0x1e8) & *(uint *)(unaff_EDI + 0x1f0)) != 0 ||
             (*(uint *)(iVar3 + 0x1ec) & *(uint *)(unaff_EDI + 500)) != 0)))) {
          if (*(short *)(iVar3 + 0x1064) == DAT_007f1a50) {
            FUN_00432620(iVar3,_DAT_00804b04,0);
          }
          else {
            local_4 = *(float *)(iVar3 + 0x80) - *(float *)(unaff_EDI + 0x80);
            local_c = FUN_005be2d0(local_4,*(float *)(iVar3 + 0x88) - *(float *)(unaff_EDI + 0x88));
            local_c = local_c & 0xffff;
            DAT_00955580 = &local_c;
            iVar4 = FUN_00438230(0,iVar3,0xffffffff,0,0,1);
            if (iVar4 != 2) goto LAB_004a3e84;
            cVar1 = *(char *)(iVar2 + 0x280);
            if (((cVar1 == '\0') || (cVar1 == '\x01')) &&
               ((*(char *)(iVar3 + 0x280) == -1 && (DAT_0093b324 != 0)))) {
              FUN_00476010((int)cVar1);
            }
          }
          FUN_0054a850(**(undefined4 **)(iVar2 + 0xca4),0x3f000000,0);
          FUN_0054a8a0(**(undefined4 **)(iVar2 + 0xca4),0x3dcccccd,0);
          FUN_00549f10();
        }
LAB_004a3e84:
        local_8 = (float)((int)local_8 + 1);
        iVar3 = iVar3 + 0x10d8;
      } while ((int)local_8 < DAT_0093d500);
    }
  }
  return;
}

