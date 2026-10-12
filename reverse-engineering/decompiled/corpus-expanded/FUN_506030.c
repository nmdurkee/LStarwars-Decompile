/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x506030; label: FUN_00506030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00506030(int param_1,int param_2)

{
  float fVar1;
  uint uVar2;
  byte bVar3;
  
  uVar2 = *(uint *)(param_1 + 0x88);
  if ((uVar2 & 2) == 0) {
    if ((uVar2 & 0x1000) == 0) {
      if (param_2 == 0) {
        return;
      }
      if (*(float *)(param_1 + 0x98) < 0.0) {
        *(float *)(param_1 + 0x98) = -*(float *)(param_1 + 0x98);
      }
      FUN_00505f20(param_1);
      return;
    }
    if (param_2 != 0) {
      return;
    }
    *(uint *)(param_1 + 0x88) = uVar2 & 0xffffefff | 2;
    *(float *)(param_1 + 0x90) = *(float *)(*(int *)(param_1 + 0x58) + 8) - 1.0;
    bVar3 = 0.0 < *(float *)(param_1 + 0x98) |
            (byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x98)) << 10) >> 8);
  }
  else {
    fVar1 = *(float *)(param_1 + 0x98);
    bVar3 = 0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8);
    if (param_2 != 0) {
      if (0.0 <= fVar1) {
        return;
      }
      *(float *)(param_1 + 0x98) = -*(float *)(param_1 + 0x98);
      return;
    }
  }
  if ((POPCOUNT(bVar3) & 1U) == 0) {
    return;
  }
  *(float *)(param_1 + 0x98) = -*(float *)(param_1 + 0x98);
  return;
}

