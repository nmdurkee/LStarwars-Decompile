/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x5555a0; label: FUN_005555a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005555a0(undefined4 *param_1,int param_2)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  short *psVar6;
  undefined4 *puVar7;
  undefined4 local_40 [16];
  
  if (param_1 != (undefined4 *)0x0) {
    param_1 = (undefined4 *)*param_1;
    if (param_2 == 0) {
      *(byte *)(param_1 + 0x2b) = *(byte *)(param_1 + 0x2b) | 4;
      FUN_0067c930((int)*(short *)((int)param_1 + 0xae));
      iVar4 = 0;
      *(undefined2 *)((int)param_1 + 0xae) = 0xffff;
      if (*(char *)((int)param_1 + 0x8b) != '\0') {
        psVar6 = (short *)(param_1 + 0x3d);
        do {
          if (*psVar6 != -1) {
            FUN_0067c930((int)*psVar6);
            *psVar6 = -1;
          }
          iVar4 = iVar4 + 1;
          psVar6 = psVar6 + 0x22;
        } while (iVar4 < (int)(uint)*(byte *)((int)param_1 + 0x8b));
      }
      if (param_1[0xc0] != 0) {
        FUN_0059a6b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x510c),param_1[0xc0]);
        param_1[0xc0] = 0;
      }
    }
    else {
      *(byte *)(param_1 + 0x2b) = *(byte *)(param_1 + 0x2b) & 0xfb;
      if (*(short *)((int)param_1 + 0xae) == -1) {
        uVar3 = FUN_005cffb0(param_1 + 0x14);
        FUN_0067c760(uVar3);
        FUN_005b44e0(local_40);
        FUN_005b4670(local_40,0);
        FUN_005b4f70(local_40,*(undefined2 *)(param_1 + 0x1f));
        FUN_005b4900(local_40,param_1 + 0x17);
        puVar5 = local_40;
        puVar7 = param_1;
        for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar7 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
        }
        iVar4 = FUN_005d0450(param_1 + 0x14,&DAT_0093b118);
        if (iVar4 == 0) {
          uVar1 = FUN_0067bf50(param_1,uVar3);
          *(undefined2 *)((int)param_1 + 0xae) = uVar1;
        }
        else {
          if (DAT_008025b4 == -1) {
            *(undefined2 *)((int)param_1 + 0xae) = 0xffff;
          }
          else {
            uVar1 = FUN_0067c4f0(param_1,DAT_008025b4);
            *(undefined2 *)((int)param_1 + 0xae) = uVar1;
          }
          iVar4 = 0;
          if (*(char *)((int)param_1 + 0x8b) != '\0') {
            psVar6 = (short *)(param_1 + 0x3d);
            do {
              if (DAT_008025b8 == -1) {
                *psVar6 = -1;
              }
              else {
                sVar2 = FUN_0067c4f0(psVar6 + -0x20,DAT_008025b8);
                *psVar6 = sVar2;
              }
              FUN_0067c7b0((int)*psVar6,1);
              iVar4 = iVar4 + 1;
              psVar6 = psVar6 + 0x22;
            } while (iVar4 < (int)(uint)*(byte *)((int)param_1 + 0x8b));
          }
        }
      }
      if (param_1[0xc0] == 0) {
        uVar3 = FUN_0059afc0(*(undefined4 *)(PTR_DAT_00802c54 + 0x510c),param_1 + 0x17,0x3f28f5c3,
                             0x3f800000,0x3f800000,*(undefined2 *)(param_1 + 0x1f),0,0);
        param_1[0xc0] = uVar3;
        return;
      }
    }
  }
  return;
}

