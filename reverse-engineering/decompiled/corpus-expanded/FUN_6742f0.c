/* Ghidra pseudocode, not original source.
 * ev_ea7efa1563e3e8089df6b32d8c4fce6d2180bcae0d447e350c78ef2ad3ca8169
 * Entry: 0x6742f0; label: FUN_006742f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006742f0(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float10 fVar4;
  
  if ((-*(float *)(DAT_0292186c + 0x50) - param_2 <= param_1[2]) &&
     (param_1[2] <= param_2 + *(float *)(DAT_0292186c + 0x50) + *(float *)(DAT_0292186c + 0x4c))) {
    fVar1 = *param_1 * *param_1 + param_1[1] * param_1[1];
    param_2 = param_2 + *(float *)(DAT_0292186c + 0x50);
    param_2 = param_2 * param_2;
    if (fVar1 <= param_2) {
      fVar4 = (float10)FUN_005c0240(param_2 - fVar1);
      iVar3 = DAT_0292186c;
      fVar2 = param_1[2] - (float)fVar4;
      if ((0.0 <= fVar2) && (fVar2 <= *(float *)(DAT_0292186c + 0x4c))) {
        fVar2 = fVar2 / *(float *)(DAT_0292186c + 0x4c);
        if (*(float *)(DAT_0292186c + 0x98) <= fVar2) {
          return 0;
        }
        *(float *)(DAT_0292186c + 0x98) = fVar2;
        *(undefined1 *)(iVar3 + 0x88) = 4;
        *(float *)(iVar3 + 0xa8) = -*param_1;
        *(float *)(iVar3 + 0xac) = -param_1[1];
        *(float *)(iVar3 + 0xb0) = -(float)fVar4;
        return 1;
      }
      fVar1 = param_1[2] * param_1[2] + fVar1;
      if (fVar1 < param_2) {
        fVar4 = (float10)FUN_005c0240(fVar1);
        fVar4 = (float10)FUN_0064fde0(0x3f800000,(float)fVar4);
        iVar3 = DAT_0292186c;
        fVar1 = (float)fVar4;
        *(undefined4 *)(DAT_0292186c + 0x98) = 0;
        *(undefined1 *)(iVar3 + 0x88) = 0x14;
        *(float *)(iVar3 + 0xa8) = fVar1 * -*param_1;
        *(float *)(iVar3 + 0xac) = -param_1[1] * fVar1;
        *(float *)(iVar3 + 0xb0) = -param_1[2] * fVar1;
        return 1;
      }
    }
  }
  return 0;
}

