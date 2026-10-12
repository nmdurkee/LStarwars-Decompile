/* Ghidra pseudocode, not original source.
 * ev_4db18bd42a1a952b6bcb755249e03b5029cd140d39c0a6d9a87cb77874782c83
 * Entry: 0x575470; label: FUN_00575470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00575470(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  int local_8;
  int local_4;
  
  DAT_0095142c = 0;
  local_8 = *(int *)(param_1 + 0x4698);
  *(undefined4 *)(param_1 + 0x46a0) = 0;
  if ((local_8 != 0) && (local_4 = 0, 0 < *(int *)(param_1 + 0x469c))) {
    iVar6 = local_8 + 0xd4;
    do {
      iVar2 = *(int *)(*(int *)(iVar6 + -0x34) + 8);
      FUN_005b37d0(iVar6,iVar2,iVar2 + 0xc);
      FUN_005b37d0(iVar6,iVar6,*(int *)(*(int *)(iVar6 + -0x34) + 8) + 0x18);
      FUN_005b37d0(iVar6,iVar6,*(int *)(*(int *)(iVar6 + -0x34) + 8) + 0x24);
      FUN_005b3830(iVar6,iVar6,0x3e800000);
      fVar7 = (float10)FUN_005becc0(iVar6,*(undefined4 *)(*(int *)(iVar6 + -0x34) + 8),0);
      *(float *)(iVar6 + 0xc) = (float)fVar7;
      fVar7 = (float10)FUN_005becc0(iVar6,*(int *)(*(int *)(iVar6 + -0x34) + 8) + 0xc,0);
      if (*(float *)(iVar6 + 0xc) < (float)fVar7) {
        *(float *)(iVar6 + 0xc) = (float)fVar7;
      }
      fVar7 = (float10)FUN_005becc0(iVar6,*(int *)(*(int *)(iVar6 + -0x34) + 8) + 0x18,0);
      if (*(float *)(iVar6 + 0xc) < (float)fVar7) {
        *(float *)(iVar6 + 0xc) = (float)fVar7;
      }
      fVar7 = (float10)FUN_005becc0(iVar6,*(int *)(*(int *)(iVar6 + -0x34) + 8) + 0x24,0);
      if (*(float *)(iVar6 + 0xc) < (float)fVar7) {
        *(float *)(iVar6 + 0xc) = (float)fVar7;
      }
      *(float *)(iVar6 + 0xc) = *(float *)(iVar6 + 0xc) * 1.01;
      iVar2 = *(int *)(*(int *)(iVar6 + -0x34) + 8);
      FUN_005b3bb0(iVar6 + 0x10,iVar2,iVar2 + 0xc,iVar2 + 0x24);
      iVar3 = *(int *)(iVar6 + -0x34);
      puVar4 = *(undefined4 **)(iVar3 + 8);
      *(undefined4 *)(iVar6 + -0x30) = *puVar4;
      *(undefined4 *)(iVar6 + -0x2c) = puVar4[1];
      iVar2 = iVar6 + -0x30;
      *(undefined4 *)(iVar6 + -0x28) = puVar4[2];
      iVar5 = *(int *)(iVar3 + 8);
      *(undefined4 *)(iVar6 + -0x24) = *(undefined4 *)(iVar5 + 0xc);
      iVar1 = iVar6 + -0x24;
      *(undefined4 *)(iVar6 + -0x20) = *(undefined4 *)(iVar5 + 0x10);
      *(undefined4 *)(iVar6 + -0x1c) = *(undefined4 *)(iVar5 + 0x14);
      iVar5 = *(int *)(iVar3 + 8);
      *(undefined4 *)(iVar6 + -0xc) = *(undefined4 *)(iVar5 + 0x24);
      *(undefined4 *)(iVar6 + -8) = *(undefined4 *)(iVar5 + 0x28);
      iVar3 = iVar6 + -0x18;
      *(undefined4 *)(iVar6 + -4) = *(undefined4 *)(iVar5 + 0x2c);
      FUN_005b37d0(iVar3,iVar1,(undefined4 *)(iVar6 + -0xc));
      FUN_005b3830(iVar3,iVar3,0x3f000000);
      FUN_005b3800(iVar3,iVar3,iVar2);
      FUN_005b3830(iVar3,iVar3,0x40000000);
      FUN_005b37d0(iVar3,iVar3,iVar2);
      FUN_005b3bb0(iVar6 + 0x10,iVar2,iVar1,iVar6 + -0xc);
      FUN_005b8f40(iVar6 + 0x3c,iVar2,iVar1,iVar6 + -0xc);
      if (((*(int *)(param_1 + 0x46a0) == 0) && ((*(byte *)(iVar6 + 0x21) & 8) != 0)) &&
         (5 < **(short **)(iVar6 + -0x34))) {
        *(int *)(param_1 + 0x46a0) = local_8;
      }
      local_8 = local_8 + 0x128;
      local_4 = local_4 + 1;
      iVar6 = iVar6 + 0x128;
    } while (local_4 < *(int *)(param_1 + 0x469c));
  }
  return;
}

