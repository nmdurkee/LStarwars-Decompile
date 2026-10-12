/* Ghidra analysis pseudocode, not original source.
 * ev_df641eda8072cee71ca3b2626b4685e3428f565924a572e6fdc3ba5eae4c5d68
 * Entry: 0x57c110; label: FUN_0057c110
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057c110(undefined4 param_1,undefined4 param_2,uint *param_3,undefined4 param_4,int param_5
                 ,undefined4 param_6)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 in_ECX;
  undefined4 in_EDX;
  int iVar4;
  uint *puVar5;
  undefined4 local_19c;
  int local_198;
  uint local_194;
  uint local_190;
  undefined4 local_18c;
  undefined4 local_188;
  uint local_184 [32];
  undefined1 local_104 [128];
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_19c;
  local_188 = param_1;
  local_190 = *param_3;
  DAT_00951bec = param_4;
  puVar5 = (uint *)(local_190 + 3 & 0xfffffffc);
  *param_3 = (uint)(puVar5 + 3);
  puVar5[2] = (uint)(puVar5 + 3);
  iVar4 = 0;
  *param_3 = *param_3 + 3 +
             ((int)(DAT_0093b278 + 0x1f + (DAT_0093b278 + 0x1f >> 0x1f & 0x1fU)) >> 5) * 4 &
             0xfffffffc;
  DAT_00951c60 = param_6;
  local_198 = 0;
  DAT_00951c64 = puVar5;
  local_19c = in_EDX;
  local_18c = in_ECX;
  if (0 < DAT_00951ca8) {
    do {
      if (*(short *)(iVar4 + 8 + DAT_00951ca4) == param_5) {
        local_194 = *param_3;
        local_184[puVar5[1]] = local_194;
        *param_3 = local_194 + 0x193 & 0xfffffffc;
        piVar1 = (int *)local_184[puVar5[1]];
        FUN_004f1f10(local_104,&DAT_007625c8);
        FUN_004f1e80(local_104,*(undefined4 *)(iVar4 + DAT_00951ca4));
        FUN_004f1e80(local_104,&DAT_0075a204);
        FUN_004f1e80(local_104,*(undefined4 *)(iVar4 + 4 + DAT_00951ca4));
        FUN_004f1f10(local_84,local_104);
        FUN_004f1e80(local_84,&DAT_0075d39c);
        FUN_0057bd50(local_84);
        if ((((piVar1[0x14] & 0x800U) != 0) || (iVar3 = FUN_0055c690(), iVar3 != 0)) ||
           ((*(byte *)(param_5 * 0x130 + 100 + DAT_00951b78) & 0xe0) != 0)) {
          FUN_004f1f10(local_84,local_104);
          FUN_004f1e80(local_84,&DAT_0075eb00);
          iVar3 = FUN_00505820(local_84,param_3,local_19c,0);
          *piVar1 = iVar3;
          if (iVar3 != 0) {
            FUN_004f1f10(piVar1 + 2,*(undefined4 *)(iVar4 + 4 + DAT_00951ca4));
            FUN_00505b40(*piVar1,local_188,0,param_2);
            FUN_00505bb0(*piVar1,local_18c);
            iVar3 = FUN_00505cf0(*piVar1,0,0,*(undefined4 *)(iVar4 + 4 + DAT_00951ca4),param_3,0);
            piVar1[1] = iVar3;
            if (iVar3 != 0) {
              *(float *)(iVar3 + 0x98) = (float)piVar1[0x17] * _DAT_0092501c;
              *param_3 = *param_3 + 0xf & 0xfffffff0;
            }
            puVar5[1] = puVar5[1] + 1;
            goto LAB_0057c36e;
          }
        }
        *param_3 = local_194;
      }
LAB_0057c36e:
      local_198 = local_198 + 1;
      iVar4 = iVar4 + 0xc;
    } while (local_198 < DAT_00951ca8);
  }
  if ((int)puVar5[1] < 1) {
    *param_3 = local_190;
  }
  else {
    uVar2 = *param_3;
    iVar4 = puVar5[1] * 4;
    *puVar5 = uVar2;
    FUN_004ef660(uVar2,local_184,iVar4);
    *param_3 = puVar5[1] * iVar4 + 3 + *param_3 & 0xfffffffc;
  }
  __security_check_cookie(local_4 ^ (uint)&local_19c);
  return;
}

