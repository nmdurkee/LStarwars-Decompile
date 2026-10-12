/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x4812e0; label: FUN_004812e0
 */

undefined4 FUN_004812e0(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *param_3;
  if (*(char *)(iVar1 + 0x1087) == '\0') {
    if (*(char *)(iVar1 + 0x7b5) == 'G') {
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
     && (0.0 < *(float *)(iVar1 + 0x1090))) {
    *(ushort *)((int)param_3 + 0x292) = *(ushort *)((int)param_3 + 0x292) | 0x4000;
    return 1;
  }
  FUN_0043cbf0(iVar1);
  return 0;
}

