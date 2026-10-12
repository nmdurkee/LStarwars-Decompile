/* Ghidra pseudocode, not original source.
 * ev_2dc15e7d3c3d1805147447414f3f14c0abe3c311ca5fc4e615c2e0419915bb96
 * Entry: 0x5c5c30; label: FUN_005c5c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c5c30(char param_1)

{
  undefined4 *puVar1;
  int *in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int local_18;
  int local_14;
  
  uVar2 = 0;
  if (((param_1 == '\0') || (uVar2 = DAT_0097383c, uVar3 = DAT_00973840, (char)in_ECX[4] == '\0'))
     && (uVar3 = uVar2, (char)in_ECX[4] == '\0')) {
    FUN_00607ec0(0xc,5,uVar2,0);
    local_14 = 0;
    if (in_ECX[3] != 0) {
      local_18 = 0;
      do {
        puVar5 = (undefined4 *)(*in_ECX + local_18);
        FUN_005c1f70();
        puVar1 = (undefined4 *)*DAT_02854d10;
        uVar2 = puVar5[1];
        uVar3 = puVar5[2];
        *puVar1 = *puVar5;
        puVar1[1] = uVar2;
        *(undefined4 *)(*DAT_02854d10 + 8) = uVar3;
        *DAT_02854d10 = *DAT_02854d10 + 0x18;
        DAT_02854d14 = DAT_02854d14 + 1;
        FUN_005c1f70();
        uVar2 = puVar5[5];
        uVar3 = puVar5[6];
        puVar1 = (undefined4 *)*DAT_02854d10;
        *puVar1 = puVar5[4];
        puVar1[1] = uVar2;
        *(undefined4 *)(*DAT_02854d10 + 8) = uVar3;
        *DAT_02854d10 = *DAT_02854d10 + 0x18;
        DAT_02854d14 = DAT_02854d14 + 1;
        FUN_005c1f70();
        uVar2 = puVar5[9];
        uVar3 = puVar5[10];
        puVar1 = (undefined4 *)*DAT_02854d10;
        *puVar1 = puVar5[8];
        puVar1[1] = uVar2;
        *(undefined4 *)(*DAT_02854d10 + 8) = uVar3;
        *DAT_02854d10 = *DAT_02854d10 + 0x18;
        DAT_02854d14 = DAT_02854d14 + 1;
        FUN_005c1f70();
        uVar2 = puVar5[9];
        uVar3 = puVar5[10];
        puVar1 = (undefined4 *)*DAT_02854d10;
        *puVar1 = puVar5[8];
        puVar1[1] = uVar2;
        *(undefined4 *)(*DAT_02854d10 + 8) = uVar3;
        *DAT_02854d10 = *DAT_02854d10 + 0x18;
        DAT_02854d14 = DAT_02854d14 + 1;
        FUN_005c1f70();
        uVar2 = puVar5[0xd];
        uVar3 = puVar5[0xe];
        puVar1 = (undefined4 *)*DAT_02854d10;
        *puVar1 = puVar5[0xc];
        puVar1[1] = uVar2;
        *(undefined4 *)(*DAT_02854d10 + 8) = uVar3;
        *DAT_02854d10 = *DAT_02854d10 + 0x18;
        DAT_02854d14 = DAT_02854d14 + 1;
        FUN_005c1f70();
        uVar2 = puVar5[1];
        uVar3 = puVar5[2];
        puVar1 = (undefined4 *)*DAT_02854d10;
        local_18 = local_18 + 0xa0;
        *puVar1 = *puVar5;
        puVar1[1] = uVar2;
        *(undefined4 *)(*DAT_02854d10 + 8) = uVar3;
        *DAT_02854d10 = *DAT_02854d10 + 0x18;
        DAT_02854d14 = DAT_02854d14 + 1;
        local_14 = local_14 + 1;
      } while (local_14 != in_ECX[3]);
    }
    FUN_006009c0();
    return;
  }
  DAT_02854d1c = DAT_02854d1c + 1;
  FUN_00600b20(1);
  FUN_00607d70(0xc,5,uVar3);
  local_18 = 0;
  if (in_ECX[3] != 0) {
    do {
      iVar4 = *(int *)(in_ECX[1] + local_18 * 4);
      if (((iVar4 != -1) && (iVar4 = iVar4 * 0xa0 + *in_ECX, 0.0 <= *(float *)(iVar4 + 0x90))) &&
         (0.0 <= *(float *)(iVar4 + 0x94))) {
        FUN_005c1f70();
        FUN_006009e0(*(undefined4 *)(iVar4 + 0x40),*(float *)(iVar4 + 0x44) * -1.0,
                     *(undefined4 *)(iVar4 + 0x48));
        FUN_005c1f70();
        FUN_006009e0(*(undefined4 *)(iVar4 + 0x50),*(float *)(iVar4 + 0x54) * -1.0,
                     *(undefined4 *)(iVar4 + 0x58));
        FUN_005c1f70();
        FUN_006009e0(*(undefined4 *)(iVar4 + 0x60),*(float *)(iVar4 + 100) * -1.0,
                     *(undefined4 *)(iVar4 + 0x68));
        FUN_005c1f70();
        FUN_006009e0(*(undefined4 *)(iVar4 + 0x60),*(float *)(iVar4 + 100) * -1.0,
                     *(undefined4 *)(iVar4 + 0x68));
        FUN_005c1f70();
        FUN_006009e0(*(undefined4 *)(iVar4 + 0x70),*(float *)(iVar4 + 0x74) * -1.0,
                     *(undefined4 *)(iVar4 + 0x78));
        FUN_005c1f70();
        FUN_006009e0(*(undefined4 *)(iVar4 + 0x40),*(float *)(iVar4 + 0x44) * -1.0,
                     *(undefined4 *)(iVar4 + 0x48));
      }
      local_18 = local_18 + 1;
    } while (local_18 != in_ECX[3]);
  }
  FUN_006009a0();
  iVar4 = DAT_02854d1c * 4;
  DAT_02854d1c = DAT_02854d1c + -1;
  FUN_00600b20(*(undefined4 *)(&DAT_00981c4c + iVar4));
  return;
}

