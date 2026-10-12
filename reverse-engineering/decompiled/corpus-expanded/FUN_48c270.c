/* Ghidra pseudocode, not original source.
 * ev_2b5797dc97ed4bbab0de865ef61fef56a3505bfdb1fb7c8af1c17efd4ff63982
 * Entry: 0x48c270; label: FUN_0048c270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048c270(int param_1,void *param_2,int param_3)

{
  uint *puVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint local_18;
  undefined1 local_c [12];
  
  if ((param_1 != 0) && (param_2 != (void *)0x0)) {
    _memset(param_2,0,0x2800);
    iVar3 = FUN_005cfed0(param_1);
    iVar6 = 0;
    if (0 < iVar3) {
      do {
        if (iVar6 == 0) {
          FUN_005cfef0(param_1,local_c,1);
        }
        else {
          FUN_005cff50(local_c);
        }
        iVar4 = FUN_005cfd60(local_c);
        puVar1 = (uint *)((int)param_2 + iVar6 * 8);
        *puVar1 = *puVar1 ^ (iVar4 << 0xb ^ *(uint *)((int)param_2 + iVar6 * 8)) & 0x800;
        if (((*(int *)(param_1 + 0x54) != 0) && (iVar4 = FUN_005d0420(local_c), iVar4 != 0)) &&
           (*(int *)(*(int *)(param_1 + 0x54) + (uint)*(ushort *)(iVar4 + 0x5c) * 4) != 0)) {
          if ((2048.0 < *(float *)(iVar4 + 0x4c)) ||
             (fVar2 = *(float *)(iVar4 + 0x4c), NAN(fVar2) || 0.0 < fVar2 == (fVar2 == 0.0))) {
            *(uint *)((int)param_2 + iVar6 * 8) =
                 *(uint *)((int)param_2 + iVar6 * 8) & 0xfffff801 | 1;
          }
          else {
            local_18 = (uint)(longlong)ROUND(*(float *)(iVar4 + 0x4c));
            puVar1 = (uint *)((int)param_2 + iVar6 * 8);
            *puVar1 = *puVar1 ^ (local_18 ^ *(uint *)((int)param_2 + iVar6 * 8)) & 0x7ff;
          }
          puVar1 = (uint *)((int)param_2 + iVar6 * 8);
          *puVar1 = *puVar1 ^ (*(int *)(iVar4 + 0x50) << 0xc ^ *(uint *)((int)param_2 + iVar6 * 8))
                              & 0x1000;
          uVar5 = *(uint *)((int)param_2 + iVar6 * 8);
          uVar5 = (*(int *)(iVar4 + 0x50) << 0xb ^ uVar5) & 0x2000 ^ uVar5;
          *(uint *)((int)param_2 + iVar6 * 8) = uVar5;
          *(uint *)((int)param_2 + iVar6 * 8) =
               (*(int *)(iVar4 + 0x50) << 0xb ^ uVar5) & 0x4000 ^ uVar5;
          *(undefined4 *)((int)param_2 + iVar6 * 8 + 4) = *(undefined4 *)(iVar4 + 0x40);
          if (param_3 != 0) {
            *(undefined4 *)(iVar4 + 0x54) = *(undefined4 *)(iVar4 + 0x40);
          }
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar3);
    }
  }
  return;
}

