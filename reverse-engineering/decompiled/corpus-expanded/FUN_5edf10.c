/* Ghidra pseudocode, not original source.
 * ev_fbc0fd73cf89a7f733f4465e4ab1049333b8e7c593c45a6546f4f82b49062809
 * Entry: 0x5edf10; label: FUN_005edf10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005edf10(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float local_30;
  int local_2c;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 local_18 [12];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (DAT_0097398c != 0) {
    if (DAT_0097394c == 1) {
      FUN_00603cc0(&DAT_00973760);
    }
    iVar5 = (int)*(short *)(param_1 + 0x14);
    iVar4 = 0;
    if (0 < iVar5) {
      local_30 = 0.0;
      do {
        iVar4 = iVar4 + 1;
        puVar1 = (undefined4 *)((int)local_30 + *(int *)(param_1 + 0x10));
        puVar2 = (undefined4 *)(*(int *)(param_1 + 0x10) + (iVar4 % iVar5) * 0xc);
        FUN_005b3800(local_18,puVar1,puVar2);
        FUN_005dc050(*puVar1,puVar1[1],puVar1[2],*puVar2,puVar2[1],puVar2[2],0xffff00ff);
        iVar5 = (int)*(short *)(param_1 + 0x14);
        local_30 = (float)((int)local_30 + 0xc);
      } while (iVar4 < iVar5);
    }
    iVar4 = 0;
    local_2c = 0;
    if (0 < *(short *)(param_1 + 0x14)) {
      do {
        FUN_005b3800(local_18,*(int *)(param_1 + 0x10) + iVar4,&DAT_00971894);
        FUN_005b3b30(local_18,local_18);
        local_30 = 3.4028235e+38;
        iVar5 = 0;
        if (*(char *)(param_2 + 0xe) != '\0') {
          iVar6 = 0;
          do {
            fVar7 = (float10)FUN_005b9290(*(int *)(param_2 + 4) + iVar6,
                                          *(int *)(param_1 + 0x10) + iVar4,local_18,&uStack_c);
            fVar3 = (float)fVar7;
            if ((0.0 < fVar3) && (fVar3 < local_30)) {
              uStack_24 = uStack_c;
              uStack_20 = uStack_8;
              uStack_1c = uStack_4;
              local_30 = fVar3;
            }
            iVar5 = iVar5 + 1;
            iVar6 = iVar6 + 0x10;
          } while (iVar5 < (int)(uint)*(byte *)(param_2 + 0xe));
        }
        puVar1 = (undefined4 *)(iVar4 + *(int *)(param_1 + 0x10));
        FUN_005dc050(uStack_24,uStack_20,uStack_1c,*puVar1,puVar1[1],
                     *(undefined4 *)(iVar4 + 8 + *(int *)(param_1 + 0x10)),0xffff00ff);
        local_2c = local_2c + 1;
        iVar4 = iVar4 + 0xc;
      } while (local_2c < *(short *)(param_1 + 0x14));
    }
    if (DAT_0097394c == 1) {
      FUN_00603cc0(&DAT_00971b00);
    }
  }
  return;
}

