/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4ba4d0; label: FUN_004ba4d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ba4d0(int param_1,undefined4 param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  float local_20;
  float local_1c;
  uint local_c [3];
  
  if ((_DAT_00950780 == 0.0) && (0 < param_4)) {
    iVar5 = 0;
    local_c[0] = 0;
    local_c[1] = 0;
    local_c[2] = 0;
    if (0 < param_4) {
      puVar6 = local_c;
      do {
        if (*(short *)(param_1 + iVar5 * 2) == -1) {
          puVar6 = puVar6 + 1;
        }
        else {
          *puVar6 = *puVar6 + 1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_4);
    }
    fVar1 = _DAT_007fc3a8 * _DAT_007fc3a4;
    iVar7 = 0;
    iVar5 = 0;
    fVar2 = _DAT_007fc3b0 * _DAT_007fc3a8;
    fVar3 = _DAT_007fc3a8 * _DAT_007fc3b4;
    local_20 = -(fVar2 * (float)(int)(local_c[0] - 1) * 0.5);
    local_1c = _DAT_007fc3ac - fVar3;
    if (0 < param_4) {
      do {
        if (*(short *)(param_1 + iVar5 * 2) == -1) {
          iVar4 = iVar7 + 1;
          local_1c = local_1c + fVar3;
          puVar6 = local_c + iVar7;
          iVar7 = iVar7 + 1;
          iVar5 = iVar5 + 1;
          local_20 = -((float)(int)local_c[iVar4] * fVar2 * 0.5);
          if (((local_c[iVar4] - (*puVar6 & 0x80000001)) + iVar7 & 1) == 0) {
            local_20 = fVar2 * 0.5 + local_20;
          }
        }
        FUN_0055b830((int)*(short *)(param_1 + iVar5 * 2),local_20,local_1c,0,fVar1,0xa7,
                     *(undefined4 *)(param_3 + iVar5 * 4),*(undefined4 *)(param_3 + iVar5 * 4),1,0);
        iVar5 = iVar5 + 1;
        local_20 = fVar2 + local_20;
      } while (iVar5 < param_4);
      return;
    }
  }
  return;
}

