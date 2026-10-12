/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5d0080; label: FUN_005d0080
 */

undefined4 FUN_005d0080(int *param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  float *pfVar5;
  int iVar6;
  
  if (param_1[1] == 0) {
    iVar3 = param_1[2];
    if (iVar3 == 0) {
      return 0;
    }
    pfVar5 = *(float **)(iVar3 + 0xbc);
    iVar6 = 0;
    fVar2 = *pfVar5;
    while (fVar2 != 0.0) {
      pfVar1 = pfVar5 + 1;
      pfVar5 = pfVar5 + 1;
      iVar6 = iVar6 + 1;
      fVar2 = *pfVar1;
    }
    return *(undefined4 *)
            (*(int *)(*(int *)(*param_1 + 0x110) + 0x50) +
            *(int *)(*(int *)(*(int *)(iVar3 + 0xb0) + 4 + iVar6 * 0xc) + param_2 * 4) * 4);
  }
  iVar3 = *(int *)(*(int *)(*param_1 + 0x18) + *(short *)(*(int *)(param_1[1] + 0x40) + 0x40) * 4);
  for (iVar6 = *(int *)(iVar3 + 0x4c); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x4c)) {
    iVar3 = iVar6;
  }
  puVar4 = *(undefined4 **)(iVar3 + 0xc);
  while( true ) {
    if (param_2 == 0) {
      return puVar4[1];
    }
    if (puVar4 == (undefined4 *)0x0) break;
    param_2 = param_2 + -1;
    puVar4 = (undefined4 *)*puVar4;
  }
  return 0;
}

