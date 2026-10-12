/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x4191d0; label: FUN_004191d0
 */

void FUN_004191d0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_ESI;
  int iVar3;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  iVar2 = *(int *)(*(int *)(unaff_ESI + 0x54) + 0x24);
  iVar3 = (int)*(char *)(iVar2 + 0x10d);
  if (((*(char *)(unaff_ESI + 0xe38) != '\0') || (*(char *)(iVar2 + 0xf5) == '\0')) ||
     (*(float *)(unaff_ESI + 0xd34) <= 0.0)) {
    if (*(float *)(unaff_ESI + 0xd30) <= 0.0) {
      return;
    }
    local_8c = *(undefined4 *)(unaff_ESI + 0xd30);
  }
  else {
    if (1 < ((byte)DAT_00925068 & 3)) {
      return;
    }
    local_8c = 0x3f800000;
  }
  local_88 = local_8c;
  local_84 = local_8c;
  FUN_005b45a0(local_80,&local_8c);
  if ((iVar3 == -1) || (*(int *)(*(int *)(unaff_ESI + 0x50) + 0x14 + iVar3 * 4) == 0)) {
    iVar2 = unaff_ESI + 0x80;
  }
  else {
    iVar2 = iVar3 * 0x40 + 0x834 + unaff_ESI;
  }
  FUN_005b4900(local_80,iVar2);
  uVar1 = 0x70;
  if (*(float *)(unaff_ESI + 0xd34) <= 0.0) {
    uVar1 = 0x6f;
  }
  FUN_00552bc0(0,uVar1,local_80);
  if ((param_1 != 0) &&
     (iVar2 = FUN_00550490(local_80,*(undefined1 *)(unaff_ESI + 0x107b),
                           *(undefined4 *)(unaff_ESI + 0x1014),
                           *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),local_40),
     iVar2 != 0)) {
    FUN_005d4690(0);
    uVar1 = 0x93;
    if (*(float *)(unaff_ESI + 0xd34) <= 0.0) {
      uVar1 = 0x92;
    }
    FUN_00552bc0(0,uVar1,local_40);
    FUN_005d46b0();
  }
  return;
}

