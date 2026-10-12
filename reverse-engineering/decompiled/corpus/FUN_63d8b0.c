/* Ghidra analysis pseudocode, not original source.
 * ev_9b402c9e9507e171b8c16fab1dff2f919b44cba00aab1d6e0da1cdd21bc5614e
 * Entry: 0x63d8b0; label: FUN_0063d8b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063d8b0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar4;
  undefined8 uVar3;
  undefined8 uVar5;
  char *local_4c [18];
  
  local_4c[0] = "INVALID";
  local_4c[1] = "SPHERICAL";
  local_4c[2] = "ALSO INVALID";
  FUN_005d0fb0();
  uVar5 = CONCAT44(_DAT_0080fe00,_DAT_0080fe00);
  uVar4 = DAT_009738b8;
  FUN_005d0fe0();
  uVar3 = CONCAT44(uVar4,0x80ffffff);
  uVar4 = DAT_009738b8;
  FUN_005d1060();
  FUN_005d0e80(DAT_009738b8,uVar4,uVar3,uVar5);
  iVar1 = FUN_006e6b90();
  if (DAT_02913814 != 0) {
    FUN_005db880(0x80,0x200 - iVar1,0x12c0,0x5a0,0x20000080,DAT_029135f4);
    FUN_005d0fb0(DAT_009738b8);
    FUN_005f35e0(DAT_009738b8,0x280,0x200,0x10,"Fog Editor");
    iVar2 = iVar1 * 2 + 0x200;
    FUN_005f35e0();
    FUN_005f35e0(DAT_009738b8,0x280,iVar2,0x10,"POS: %.03f %.03f %.03f",
                 (double)*(float *)(DAT_02913814 + 0x20),(double)*(float *)(DAT_02913814 + 0x24),
                 (double)*(float *)(DAT_02913814 + 0x28));
    iVar2 = iVar2 + iVar1;
    FUN_005f35e0(DAT_009738b8,0x280,iVar2,0x10,"TYPE: %s",local_4c[*(int *)(DAT_02913814 + 0x14)]);
    FUN_005f35e0(DAT_009738b8,0x280,iVar1 + iVar2,0x10,"RADIUS: %.03f",
                 (double)*(float *)(DAT_02913814 + 0x1c));
    return;
  }
  FUN_005db880(0x80,0x200 - iVar1,0x12c0,(iVar1 * 5) / 2,0x20000080,DAT_029135f4);
  FUN_005d0fb0(DAT_009738b8);
  FUN_005f35e0(DAT_009738b8,0x280,0x200,0x10,"Fog Editor");
  FUN_005f35e0();
  FUN_005f35e0(DAT_009738b8,0x280,iVar1 * 2 + 0x200,0x10,"POS: %.03f %.03f %.03f",
               (double)DAT_029134a4,(double)DAT_029134a8,(double)DAT_029134ac);
  return;
}

