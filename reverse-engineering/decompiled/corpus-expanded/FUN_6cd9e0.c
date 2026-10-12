/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6cd9e0; label: FUN_006cd9e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cd9e0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uStack_118;
  int local_114;
  int local_110;
  undefined1 local_10c [4];
  undefined1 auStack_108 [256];
  uint uStack_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&uStack_118;
  local_114 = param_2;
  local_110 = param_4;
  iVar3 = (**(code **)(*param_1 + 0x18))("Object");
  if (iVar3 != 0) {
    if (param_2 != 0) {
      for (iVar3 = *(int *)(param_3 + 8); iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
        piVar4 = (int *)FUN_006c6920(*(undefined4 *)(iVar3 + 0x10),0);
        if (piVar4 == (int *)0x0) {
          iVar8 = *(int *)(iVar3 + 0xc);
          if ((iVar8 < 0) || (*(int *)(param_4 + 0x1c) <= iVar8)) {
            puVar6 = (undefined4 *)0x0;
          }
          else {
            puVar6 = (undefined4 *)(*(int *)(param_4 + 4) + iVar8 * 0xc);
          }
          if (*(int *)(iVar3 + 0x18) < 1) {
            (**(code **)(*param_1 + 4))(puVar6[1],1);
          }
          else {
            iVar8 = FUN_004f8b10(*puVar6,"String");
            if (iVar8 == 0) {
              (**(code **)(*param_1 + 8))(local_10c,4);
              (**(code **)(*param_1 + 4))(uStack_118,1);
            }
            else {
              (**(code **)(*param_1 + 4))(*(undefined4 *)(iVar3 + 0x18),1);
            }
          }
        }
        else {
          iVar8 = param_1[2];
          if (iVar8 == 1) {
LAB_006cda98:
            if ((piVar4[7] & 0x80000000U) == 0) {
              iVar1 = piVar4[3];
              if ((iVar1 < 0) || (DAT_02973ba4 <= iVar1)) {
                iVar7 = 0;
              }
              else {
                iVar7 = DAT_02973b8c + iVar1 * 0xc;
              }
              iVar9 = piVar4[6];
              if (iVar9 < 1) {
                iVar9 = *(int *)(iVar7 + 4);
              }
              if (iVar8 == 2) {
                (**(code **)(*piVar4 + 4))(uStack_118,iVar1,auStack_108,0x100);
              }
              (**(code **)(iVar7 + 8))(param_1,auStack_108,iVar9);
              param_4 = local_114;
              if (param_1[2] == 1) {
                (**(code **)(*piVar4 + 8))(uStack_118,piVar4[3],auStack_108,0x100,0);
                param_4 = local_114;
              }
            }
            else {
              iVar8 = *(int *)(iVar3 + 0xc);
              if ((iVar8 < 0) || (*(int *)(param_4 + 0x24) <= iVar8)) {
                iVar8 = 0;
              }
              else {
                iVar8 = *(int *)(param_4 + 8) + iVar8 * 0x18;
              }
              uVar5 = (**(code **)*piVar4)(uStack_118);
              FUN_006cd9e0(param_1,uVar5,iVar8,local_114);
              param_4 = local_114;
            }
          }
          else if (iVar8 == 2) {
            if ((param_1[7] & 0x400000U) == 0) {
              uVar2 = piVar4[7] & 0x10000000;
            }
            else {
              uVar2 = piVar4[7] & 0x400000;
            }
            if (uVar2 == 0) goto LAB_006cda98;
          }
        }
      }
      if (*(int *)(local_110 + 0x14) != 0) {
        (**(code **)(**(int **)(local_110 + 0x14) + 100))(param_1,uStack_118);
      }
    }
    (**(code **)(*param_1 + 0x1c))();
  }
  __security_check_cookie(uStack_8 ^ (uint)&stack0xfffffee4);
  return;
}

