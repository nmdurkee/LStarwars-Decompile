/* Ghidra pseudocode, not original source.
 * ev_2c33bc1d2955cf32f461d40ab407fc477c117f7bb728ceb3ddb2ece88215ba87
 * Entry: 0x4cb4d0; label: FUN_004cb4d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004cb4d0(undefined4 param_1,undefined4 param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = *param_3;
  if (*(char *)(iVar2 + 0x1087) == '\0') {
    cVar1 = *(char *)(iVar2 + 0x7b5);
    if (((cVar1 == '\x0f') || (cVar1 == 'G')) ||
       ((cVar1 == '\0' && (*(char *)(iVar2 + 0x7b8) == '\x06')))) {
      iVar3 = *(int *)(iVar2 + 0x44c);
      *(undefined4 *)(iVar2 + 0x3cc) = *(undefined4 *)(iVar3 + 4);
      *(undefined4 *)(iVar2 + 0x3d0) = *(undefined4 *)(iVar3 + 8);
      uVar4 = *(undefined4 *)(iVar3 + 0xc);
      *(undefined4 *)(iVar2 + 0x3d8) = 0;
      *(undefined4 *)(iVar2 + 0x3d4) = uVar4;
      *(ushort *)((int)param_3 + 0x292) = *(ushort *)((int)param_3 + 0x292) | 0x4000;
      return 1;
    }
    *(undefined1 *)(iVar2 + 0x1087) = 1;
    *(undefined4 *)(iVar2 + 0x1090) = 0x3f800000;
  }
  else if (*(char *)(iVar2 + 0x1087) != '\x01') {
    return 0;
  }
  iVar3 = *(int *)(iVar2 + 0x44c);
  *(undefined4 *)(iVar2 + 0x3cc) = *(undefined4 *)(iVar3 + 4);
  *(undefined4 *)(iVar2 + 0x3d0) = *(undefined4 *)(iVar3 + 8);
  uVar4 = *(undefined4 *)(iVar3 + 0xc);
  *(undefined4 *)(iVar2 + 0x3d8) = 0;
  *(undefined4 *)(iVar2 + 0x3d4) = uVar4;
  if (((int)*(short *)(iVar2 + 0x3ec) != (iVar3 - *(int *)(*(int *)(iVar2 + 0x420) + 0x7c)) / 0x5c)
     && (0.0 < *(float *)(iVar2 + 0x1090))) {
    *(ushort *)((int)param_3 + 0x292) = *(ushort *)((int)param_3 + 0x292) | 0x4000;
    return 1;
  }
  FUN_0043cbf0(iVar2);
  return 0;
}

