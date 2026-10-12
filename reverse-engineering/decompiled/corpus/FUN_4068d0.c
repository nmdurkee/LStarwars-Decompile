/* Ghidra analysis pseudocode, not original source.
 * ev_9e834adbd1be5074ad62417c72633ab4044f13767a5707860f49455a6f85e9eb
 * Entry: 0x4068d0; label: FUN_004068d0
 */

undefined4 FUN_004068d0(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *param_3;
  if (*(char *)(iVar1 + 0x1087) == '\0') {
    if (*(char *)(iVar1 + 0x7b5) == '\x0f') {
      iVar2 = *(int *)(iVar1 + 0x44c);
      *(undefined4 *)(iVar1 + 0x3cc) = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)(iVar1 + 0x3d0) = *(undefined4 *)(iVar2 + 8);
      uVar3 = *(undefined4 *)(iVar2 + 0xc);
      *(undefined4 *)(iVar1 + 0x3d8) = 0;
      *(undefined4 *)(iVar1 + 0x3d4) = uVar3;
      *(ushort *)((int)param_3 + 0x292) = *(ushort *)((int)param_3 + 0x292) | 0x4000;
      return 1;
    }
    *(undefined1 *)(iVar1 + 0x1087) = 1;
    *(undefined4 *)(iVar1 + 0x1090) = 0x3f800000;
  }
  else if (*(char *)(iVar1 + 0x1087) != '\x01') {
    return 0;
  }
  iVar2 = *(int *)(iVar1 + 0x44c);
  *(undefined4 *)(iVar1 + 0x3cc) = *(undefined4 *)(iVar2 + 4);
  *(undefined4 *)(iVar1 + 0x3d0) = *(undefined4 *)(iVar2 + 8);
  uVar3 = *(undefined4 *)(iVar2 + 0xc);
  *(undefined4 *)(iVar1 + 0x3d8) = 0;
  *(undefined4 *)(iVar1 + 0x3d4) = uVar3;
  if (((int)*(short *)(iVar1 + 0x3ec) != (iVar2 - *(int *)(*(int *)(iVar1 + 0x420) + 0x7c)) / 0x5c)
     && (*(float *)(iVar1 + 0x1090) != 0.0)) {
    *(ushort *)((int)param_3 + 0x292) = *(ushort *)((int)param_3 + 0x292) | 0x4000;
    return 1;
  }
  FUN_0043cbf0(iVar1);
  return 0;
}

