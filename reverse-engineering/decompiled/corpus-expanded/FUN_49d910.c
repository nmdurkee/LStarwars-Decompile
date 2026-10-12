/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x49d910; label: FUN_0049d910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0049d910(float param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  float10 fVar4;
  
  iVar3 = (int)param_1;
  if (*(int *)(*(int *)(*(int *)((int)param_1 + 0x50) + 0xc) + *(short *)((int)param_1 + 0x7aa) * 4)
      == 0) {
    fVar4 = (float10)*(float *)(*(int *)(*(int *)((int)param_1 + 0x54) + 0x24) + 0x1c);
  }
  else {
    fVar4 = (float10)FUN_0062f1c0(*(int *)((int)param_1 + 0x50),
                                  (int)*(short *)((int)param_1 + 0x7aa));
  }
  iVar1 = *(int *)((int)param_1 + 0x798);
  param_1 = (float)fVar4;
  if (iVar1 != 0) {
    param_1 = param_1 * 0.25;
  }
  *(float *)(iVar3 + 0xf18) = param_1 * (float)(&DAT_029899a0)[*(ushort *)(iVar3 + 0x5a) >> 1];
  *(float *)(iVar3 + 0xf20) =
       param_1 * (float)(&DAT_029899a0)[(int)(*(ushort *)(iVar3 + 0x5a) + 0x4000) >> 1 & 0x7fff];
  if (iVar1 == 0) {
    if ((*(byte *)(iVar3 + 0x1fc) & 0x80) == 0) {
      uVar2 = 0xbec00000;
    }
    else {
      uVar2 = 0xbf000000;
    }
    *(undefined4 *)(iVar3 + 0xf1c) = uVar2;
    if (*(float *)(iVar3 + 0x77c) < 0.5) {
      *(float *)(iVar3 + 0xf1c) =
           (*(float *)(iVar3 + 0x77c) + *(float *)(iVar3 + 0x77c)) * *(float *)(iVar3 + 0xf1c);
      return 1;
    }
  }
  return 1;
}

