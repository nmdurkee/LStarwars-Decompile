/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a0c20; label: FUN_005a0c20
 */

undefined4
FUN_005a0c20(int param_1,float *param_2,float *param_3,int param_4,int param_5,int param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  float10 fVar9;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  undefined4 local_40 [16];
  
  bVar4 = false;
  if (((param_1 != 0) && (param_2 != (float *)0x0)) && (*(char *)(param_1 + 8) != '\0')) {
    piVar7 = *(int **)(param_1 + 0x18);
    local_84 = 1e+09;
    local_80 = 1e+09;
    local_7c = 1e+09;
    local_78 = -1e+09;
    local_74 = -1e+09;
    local_70 = -1e+09;
    if (piVar7 != (int *)0x0) {
      do {
        if ((*(byte *)(piVar7 + 8) & 1) == 0) {
          if (piVar7[4] == 0) {
            if (param_6 != 0) {
              puVar5 = (undefined4 *)FUN_005d0330(piVar7 + 1);
              puVar8 = local_40;
              for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
                *puVar8 = *puVar5;
                puVar5 = puVar5 + 1;
                puVar8 = puVar8 + 1;
              }
              goto LAB_005a0d0c;
            }
          }
          else if (param_5 != 0) {
            if (param_4 == 0) {
              iVar6 = piVar7[6];
            }
            else if (param_4 == 1) {
              iVar6 = piVar7[7];
            }
            else {
              iVar6 = *(int *)(piVar7[4] + 0x4c);
            }
            FUN_005526c0(piVar7 + 1,iVar6,local_40,1);
LAB_005a0d0c:
            FUN_005d0260(piVar7 + 1,&local_50,&local_60);
            local_60 = local_60 * 0.75;
            local_44 = 0x3f800000;
            FUN_005c03e0(&local_50,&local_50,local_40);
            local_5c = local_50 - local_60;
            local_58 = local_4c - local_60;
            local_54 = local_48 - local_60;
            if (local_5c < local_84) {
              local_84 = local_5c;
            }
            if (local_58 < local_80) {
              local_80 = local_58;
            }
            if (local_54 < local_7c) {
              local_7c = local_54;
            }
            if (local_78 < local_60 + local_50) {
              local_78 = local_60 + local_50;
            }
            if (local_74 < local_4c + local_60) {
              local_74 = local_4c + local_60;
            }
            if (local_70 < local_60 + local_48) {
              local_70 = local_60 + local_48;
            }
            bVar4 = true;
          }
        }
        piVar7 = (int *)*piVar7;
      } while (piVar7 != (int *)0x0);
      if (bVar4) {
        *param_2 = (local_78 + local_84) * 0.5;
        param_2[1] = (local_80 + local_74) * 0.5;
        param_2[2] = (local_7c + local_70) * 0.5;
        if (param_3 == (float *)0x0) {
          return 1;
        }
        fVar1 = (local_78 - local_84) * 0.5;
        fVar2 = (local_74 - local_80) * 0.5;
        fVar3 = (local_70 - local_7c) * 0.5;
        fVar1 = fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2;
        *param_3 = fVar1;
        fVar9 = (float10)FUN_005c0240(fVar1);
        *param_3 = (float)fVar9;
        return 1;
      }
    }
  }
  return 0;
}

