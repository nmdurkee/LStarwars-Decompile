/* Ghidra analysis pseudocode, not original source.
 * ev_f70dbfb4dc55c21d9a8b2990429bfe298595e1ea041c5f65e2960caacde39e05
 * Entry: 0x448bf0; label: FUN_00448bf0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00448bf0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  bool bVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  int iVar9;
  float10 fVar10;
  float local_27c;
  int local_278;
  undefined1 local_270 [12];
  undefined1 local_264 [12];
  undefined1 local_258 [600];
  
  iVar9 = 0;
  bVar5 = false;
  local_278 = 0;
  if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
     (*piVar2 != 0)) {
    iVar3 = *piVar2;
    if (param_6 != 0) {
      *(undefined4 *)(param_3 + 0x180) = _DAT_007f6824;
      *(undefined4 *)(param_2 + 0x74) = _DAT_007f6828;
      if (0 < param_5) {
        do {
          iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),&DAT_0075782c);
          if (iVar6 == 0) {
            iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"fireinterval");
            if (iVar6 == 0) {
              iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"nearest");
              if (iVar6 == 0) {
                iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"predictive");
                if (iVar6 != 0) {
                  *(undefined1 *)(param_2 + 0x68) = 1;
                }
              }
              else {
                bVar5 = true;
              }
            }
            else {
              fVar10 = (float10)FUN_005147c0(param_2,iVar6 + 0xd);
              *(float *)(param_2 + 0x74) = (float)fVar10;
            }
          }
          else {
            local_278 = iVar6 + 5;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < param_5);
      }
      fVar10 = (float10)FUN_005b9dd0();
      *(float *)(param_2 + 0x9c) = (float)(fVar10 * (float10)*(float *)(param_2 + 0x74));
      if (local_278 != 0) {
        if (bVar5) {
          iVar9 = FUN_005cf8a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),local_258,local_278,0x32,0)
          ;
          if ((iVar9 != 0) && (local_27c = 1e+09, 0 < iVar9)) {
            puVar8 = local_258;
            do {
              uVar7 = FUN_005cf9e0(puVar8);
              fVar10 = (float10)FUN_005b3c50(*(int *)(param_3 + 0xd0) + 0x5c,uVar7,local_264);
              if ((float)fVar10 < local_27c) {
                *(undefined4 *)(param_2 + 0x6c) = uVar7;
                local_27c = (float)fVar10;
              }
              puVar8 = puVar8 + 0xc;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
        }
        else {
          iVar9 = FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),local_270,local_278,1);
          if (iVar9 != 0) {
            uVar7 = FUN_005cf9e0(local_270);
            *(undefined4 *)(param_2 + 0x6c) = uVar7;
          }
        }
      }
      if (*(int *)(param_2 + 0x6c) != 0) {
        *(uint *)(iVar3 + 0xeec) = *(uint *)(iVar3 + 0xeec) | 0x10000;
        fVar10 = (float10)FUN_005b9dd0();
        *(float *)(iVar3 + 0xd58) = (float)(fVar10 * (float10)*(float *)(param_2 + 0x74));
      }
    }
    if (*(int *)(param_2 + 0x6c) != 0) {
      *(int *)(param_3 + 0x1e4) = *(int *)(param_2 + 0x6c);
      puVar4 = *(undefined4 **)(param_2 + 0x6c);
      *(float *)(param_2 + 0x9c) = *(float *)(param_2 + 0x9c) - param_7;
      *(undefined4 *)(iVar3 + 0xe4c) = *puVar4;
      *(undefined4 *)(iVar3 + 0xe50) = puVar4[1];
      uVar7 = puVar4[2];
      *(uint *)(iVar3 + 0xeec) = *(uint *)(iVar3 + 0xeec) | 0x8020;
      *(undefined4 *)(iVar3 + 0xe54) = uVar7;
      if (*(float *)(param_2 + 0x9c) <= 0.0) {
        *(uint *)(iVar3 + 0xeec) =
             ((uint)*(byte *)(param_2 + 0x68) << 0x11 ^ *(uint *)(iVar3 + 0xeec)) & 0x20000 ^
             *(uint *)(iVar3 + 0xeec);
        fVar10 = (float10)FUN_005b9dd0();
        *(float *)(param_2 + 0x9c) =
             (float)((float10)*(float *)(param_2 + 0x74) * (float10)0.5 +
                    fVar10 * (float10)*(float *)(param_2 + 0x74));
        puVar1 = (uint *)(*(int *)(iVar3 + 0xca4) + 8);
        *puVar1 = *puVar1 | DAT_0080227c;
      }
    }
    return 0;
  }
  return 1;
}

