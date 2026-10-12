/* Ghidra pseudocode, not original source.
 * ev_846633128d4cd55df9225f061f87b742b0c1598eeb1c7e5f9192575f77c77f04
 * Entry: 0x50ec40; label: FUN_0050ec40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050ec40(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  
  if (param_1 == 0) {
    param_1 = DAT_00921e8c;
  }
  iVar6 = param_2;
  if (param_2 == 0) {
    iVar6 = DAT_00921ea4;
  }
  if ((param_1 != 0) && (iVar6 != 0)) {
    fVar1 = *(float *)(param_1 + 0x14);
    fVar2 = *(float *)(iVar6 + 0x14);
    param_2 = 0;
    if (0 < *(int *)(iVar6 + 0xc)) {
      do {
        iVar4 = 0;
        if (0 < *(int *)(param_1 + 0xc)) {
          uVar3 = *(ushort *)(*(int *)(iVar6 + 0x38) + param_2 * 4);
          puVar5 = *(ushort **)(param_1 + 0x38);
          do {
            if (*puVar5 == uVar3) {
              if ((0x530 < uVar3) && (uVar3 < 0x540)) {
                *(float *)(*(int *)(param_1 + 0x34) + 8 +
                          (uint)(*(ushort **)(param_1 + 0x38))[iVar4 * 2 + 1] * 0xc) =
                     *(float *)(*(int *)(iVar6 + 0x34) + 8 +
                               (uint)*(ushort *)(*(int *)(iVar6 + 0x38) + param_2 * 4 + 2) * 0xc) *
                     (fVar1 / fVar2);
              }
              break;
            }
            iVar4 = iVar4 + 1;
            puVar5 = puVar5 + 2;
          } while (iVar4 < *(int *)(param_1 + 0xc));
        }
        param_2 = param_2 + 1;
      } while (param_2 < *(int *)(iVar6 + 0xc));
    }
  }
  return;
}

