/* Ghidra pseudocode, not original source.
 * ev_ea16e91579c763516a5ec9191881acc35a0dcfc8106f35e62baf3c19fc401ba6
 * Entry: 0x448fe0; label: FUN_00448fe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00448fe0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  uint *puVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float10 fVar8;
  undefined8 uVar9;
  int local_24;
  int local_20;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  iVar6 = 0;
  local_24 = 0;
  local_20 = 0;
  if (((param_3 == 0) || (piVar3 = *(int **)(param_3 + 0xd0), piVar3 == (int *)0x0)) ||
     (*piVar3 == 0)) {
    return 1;
  }
  iVar4 = *piVar3;
  if (param_6 != 0) {
    *(undefined4 *)(param_2 + 0x78) = 0;
    *(undefined4 *)(param_2 + 0x7c) = 0;
    *(undefined4 *)(param_2 + 0x80) = 0x3f800000;
    fVar7 = (float10)FUN_005b9dd0();
    if (0 < param_5) {
      do {
        iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"start=");
        if (iVar5 == 0) {
          iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),&DAT_00757a28);
          if (iVar5 == 0) {
            iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"firerange");
            if (iVar5 == 0) {
              iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"fireinterval");
              if (iVar5 != 0) {
                fVar8 = (float10)FUN_005147c0(param_2,iVar5 + 0xd);
                *(float *)(param_2 + 0x74) = (float)fVar8;
              }
            }
            else {
              fVar8 = (float10)FUN_005147c0(param_2,iVar5 + 10);
              *(float *)(param_2 + 0x70) = (float)fVar8;
            }
          }
          else {
            local_20 = FUN_0051ac10(param_1,iVar5 + 4);
          }
        }
        else {
          local_24 = FUN_0051ac10(param_1,iVar5 + 6);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_5);
      if ((local_24 != 0) && (local_20 != 0)) {
        iVar6 = param_2 + 0x78;
        FUN_005b3800(iVar6,local_20 + 0x10,local_24 + 0x10);
        FUN_005b3b30(iVar6,iVar6);
      }
    }
    *(float *)(param_2 + 0x9c) = *(float *)(param_2 + 0x74) * (float)fVar7;
    FUN_005b3830(param_2 + 0x78,param_2 + 0x78,_DAT_007f6830);
  }
  FUN_005b37d0(local_18,iVar4 + 0x5c,param_2 + 0x78);
  FUN_0052fcb0(param_3,local_18,0,0,1,0);
  if (((0.0 < *(float *)(param_2 + 0x70)) && (iVar6 = *(int *)(param_3 + 0xe4), iVar6 != 0)) &&
     (*(int *)(iVar6 + 4) != 0)) {
    fVar7 = (float10)FUN_005b3c50(*(int *)(param_3 + 0xd0) + 0x5c,iVar6 + 0x5c,local_c);
    piVar3 = *(int **)(param_3 + 0xe4);
    bVar2 = *(byte *)(iVar4 + 0x28d);
    uVar9 = __allshl();
    if ((((((uint)uVar9 & *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 8 + (uint)bVar2 * 8)) != 0
           || ((uint)((ulonglong)uVar9 >> 0x20) &
              *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0xc + (uint)bVar2 * 8)) != 0) &&
         (*(char *)(iVar4 + 0x288) != '\0')) &&
        ((float)fVar7 < *(float *)(param_2 + 0x70) * *(float *)(param_2 + 0x70))) &&
       ((*(char *)((int)piVar3 + 0x28b) == '\0' || (0.0 < *(float *)(*piVar3 + 0x1010))))) {
      param_7 = *(float *)(param_2 + 0x9c) - param_7;
      *(float *)(param_2 + 0x9c) = param_7;
      if ((*(char *)(*(int *)(param_3 + 0xe4) + 0x28b) == '\0') && (param_7 <= 0.0)) {
        fVar7 = (float10)FUN_005b9dd0();
        *(float *)(param_2 + 0x9c) =
             (float)((float10)*(float *)(param_2 + 0x74) * (float10)0.5 +
                    fVar7 * (float10)*(float *)(param_2 + 0x74));
        puVar1 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
        *puVar1 = *puVar1 | DAT_0080227c;
        *(undefined4 *)(iVar4 + 0xea0) = **(undefined4 **)(param_3 + 0xe4);
        return 0;
      }
    }
  }
  return 0;
}

