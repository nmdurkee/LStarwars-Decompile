/* Ghidra analysis pseudocode, not original source.
 * ev_4eb19e57a9d3b9beba017312b3b21652588e9c732adfcebbbddaeb757a53089f
 * Entry: 0x403450; label: FUN_00403450
 */

int FUN_00403450(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  float10 fVar5;
  float local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_20;
  undefined4 local_1c;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  iVar4 = *(int *)(param_1 + 0x5090);
  if (iVar4 != 0) {
    local_40 = 64.0;
    iVar2 = 0;
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x5094)) {
      do {
        bVar1 = *(byte *)(iVar4 + 0x3c);
        if (((((bVar1 & 1) != 0) && ((bVar1 & 2) != 0)) && ((bVar1 & 0x10) != 0)) &&
           ((((bVar1 & 0xc) == 0 &&
             (ABS(*(float *)(iVar4 + 0x28) - *(float *)(unaff_EDI + 0x748)) < 0.2)) &&
            (ABS(*(float *)(iVar4 + 0x2c) - *(float *)(unaff_EDI + 0x74c)) < 0.2)))) {
          fVar5 = (float10)FUN_005b3c50(iVar4 + 0x10,unaff_EDI + 0x80,local_c);
          if ((float)fVar5 < local_40) {
            iVar3 = iVar4;
            local_40 = (float)fVar5;
          }
        }
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x54;
      } while (iVar2 < *(int *)(param_1 + 0x5094));
    }
    if (iVar3 != 0) {
      local_24 = *(undefined4 *)(unaff_EDI + 0x80);
      local_20 = (*(float *)(unaff_EDI + 0x194) + *(float *)(unaff_EDI + 0x84)) * 0.5;
      local_1c = *(undefined4 *)(unaff_EDI + 0x88);
      local_28 = 0;
      local_30 = 0;
      local_2c = 0x3d4ccccd;
      if (*(short *)(iVar3 + 0x38) != 0) {
        FUN_005b3690(&local_30,&local_30,*(short *)(iVar3 + 0x38));
      }
      if (*(short *)(iVar3 + 0x36) != 0) {
        FUN_005b35a0(&local_30,&local_30,*(short *)(iVar3 + 0x36));
      }
      FUN_005b37d0(&local_30,&local_30,iVar3 + 0x10);
      FUN_005b3800(local_18,&local_30,&local_24);
      iVar4 = FUN_0067b430(&local_24,local_18,0,0x3f800000,0,0x1f);
      if (iVar4 != 0) {
        iVar3 = 0;
      }
    }
    return iVar3;
  }
  return 0;
}

