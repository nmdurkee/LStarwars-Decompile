/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x569980; label: FUN_00569980
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00569980(int param_1,float param_2,float param_3,float param_4,int param_5,uint param_6,
                uint param_7,uint param_8)

{
  float fVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float local_1c;
  int local_10;
  undefined1 local_c [8];
  float local_4;
  
  iVar7 = *(int *)(PTR_DAT_00802c54 + 0x50c8);
  iVar6 = 0;
  if (iVar7 == 0) {
    return 0;
  }
  DAT_00950bb0 = 0;
  local_1c = param_2 * param_2;
  local_10 = 0;
  if (0 < *(int *)(PTR_DAT_00802c54 + 0x50c0)) {
    do {
      uVar2 = *(uint *)(iVar7 + 0x94);
      if ((((((uVar2 & 1) == 0) && ((uVar2 & 0x4000) != 0)) && ((uVar2 & 0x800000) != 0)) &&
          ((uVar2 & 0x8000) != 0)) &&
         ((((*(byte *)(param_1 + 0x1fc) & 0x80) == 0 || (*(short *)(iVar7 + 0x102) == -1)) ||
          (*(short *)(iVar7 + 0x102) != *(short *)(param_1 + 0x27e))))) {
        uVar2 = *(uint *)(iVar7 + 0x98);
        if (((uVar2 & 0x20) == 0) || (DAT_0087baf0 != 0)) {
          if (param_6 == 0) {
LAB_00569a60:
            if ((param_8 == 0) || ((*(uint *)(iVar7 + 0x9c) & param_8) != 0)) {
              if (param_5 == 4) {
                if ((char)uVar2 < '\0') {
LAB_00569a81:
                  if (*(float *)(iVar7 + 0x5c) <= *(float *)(param_1 + 0x188)) {
                    fVar8 = (float10)FUN_005b3c50(param_1 + 0x80,iVar7 + 0x4c,local_c);
                    goto LAB_00569aac;
                  }
                }
              }
              else {
                if (param_5 != 5) goto LAB_00569a81;
                if (((*(float *)(param_1 + 0x188) - *(float *)(param_1 + 0x17c)) * 1.5 +
                     *(float *)(param_1 + 0x188) < *(float *)(iVar7 + 0x5c)) ||
                   (*(float *)(iVar7 + 0x68) < *(float *)(param_1 + 0x17c))) goto LAB_00569c1d;
                fVar8 = (float10)FUN_005b3cf0(param_1 + 0x80,iVar7 + 0x4c,local_c);
LAB_00569aac:
                fVar1 = (float)fVar8;
                if (fVar1 < local_1c) {
                  if (param_5 == 2) {
                    DAT_00950bb0 = 0;
                    iVar6 = iVar7;
                    local_1c = fVar1;
                  }
                  else if ((param_3 <= 0.0) ||
                          ((fVar4 = *(float *)(param_1 + 0x1dc) + *(float *)(iVar7 + 0xa8),
                           fVar3 = param_3 + fVar4, fVar3 = fVar3 * fVar3,
                           fVar3 < fVar1 == (fVar3 == fVar1) &&
                           ((param_4 <= 0.0 || (fVar4 = fVar4 + param_4, fVar4 * fVar4 <= fVar1)))))
                          ) {
                    FUN_005b3620(local_c,local_c,-(uint)*(ushort *)(param_1 + 0x5a));
                    if (NAN(local_4) || 0.0 < local_4 == (local_4 == 0.0)) {
                      uVar5 = 0;
                    }
                    else {
                      uVar5 = 1;
                      if (((param_5 != 4) || (DAT_00804c1c == -1)) ||
                         (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c1c * 4) == 0
                         )) goto LAB_00569c1d;
                    }
                    if (fVar1 < local_1c) {
                      iVar6 = iVar7;
                      DAT_00950bb0 = uVar5;
                      local_1c = fVar1;
                    }
                  }
                }
              }
            }
          }
          else if (param_7 == 0) {
            if ((param_6 & uVar2) != 0) goto LAB_00569a60;
          }
          else if ((uVar2 & param_6) == param_7) goto LAB_00569a60;
        }
      }
LAB_00569c1d:
      local_10 = local_10 + 1;
      iVar7 = iVar7 + 0x114;
    } while (local_10 < *(int *)(PTR_DAT_00802c54 + 0x50c0));
  }
  _DAT_00950bb4 = local_1c;
  return iVar6;
}

