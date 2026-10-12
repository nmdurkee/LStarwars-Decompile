/* Ghidra pseudocode, not original source.
 * ev_7d1c367504044a8aaca3f86d1c78a9fb18090d1bc2abefa9dee9498b100eab75
 * Entry: 0x594640; label: FUN_00594640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00594640(uint param_1,uint param_2,uint *param_3,uint param_4,uint param_5,uint param_6,
                 int param_7,undefined2 param_8,int *param_9,undefined4 param_10,int param_11,
                 uint param_12)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  short *psVar8;
  undefined4 *puVar9;
  int iVar10;
  
  puVar4 = param_3;
  iVar5 = *param_9;
  param_3[4] = param_12;
  iVar6 = 0;
  *param_3 = iVar5 + 3U & 0xfffffffc;
  *(undefined2 *)(param_3 + 1) = param_8;
  *(undefined2 *)((int)param_3 + 6) = 0;
  param_3[3] = param_1;
  param_3[2] = param_2;
  if (param_11 == 0) {
    if (0 < _DAT_00955878) {
      param_3 = (uint *)_DAT_00955878;
      psVar7 = DAT_0095587c;
      do {
        iVar5 = (int)*psVar7;
        if ((((param_5 == 0) ||
             ((*(uint *)(*(int *)(DAT_029130e4 + 0x20) + 4 + iVar5 * 0x4c) & param_5) == 0)) &&
            ((param_7 == 0 || ((char)psVar7[4] != '\0')))) &&
           (((param_6 == 0 ||
             ((*(uint *)(iVar5 * 0x120 + 0x90 + DAT_0093b284) & param_6) == param_6)) &&
            ((param_4 == 0 || ((*(uint *)(iVar5 * 0x4c + 4 + DAT_0093b274) & param_4) == param_4))))
           )) {
          psVar8 = psVar7;
          puVar9 = (undefined4 *)(*puVar4 + (uint)*(ushort *)((int)puVar4 + 6) * 0x1c);
          for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar9 = *(undefined4 *)psVar8;
            psVar8 = psVar8 + 2;
            puVar9 = puVar9 + 1;
          }
          *(short *)((int)puVar4 + 6) = *(short *)((int)puVar4 + 6) + 1;
        }
        psVar7 = psVar7 + 0xe;
        param_3 = (uint *)((int)param_3 + -1);
      } while (param_3 != (uint *)0x0);
    }
  }
  else {
    iVar5 = 0;
    if (0 < DAT_0093b278) {
      iVar10 = 0;
      do {
        if ((((param_5 == 0) ||
             ((*(uint *)(iVar10 + 4 + *(int *)(DAT_029130e4 + 0x20)) & param_5) == 0)) &&
            ((param_6 == 0 || ((*(uint *)(iVar6 + 0x90 + DAT_0093b284) & param_6) == param_6)))) &&
           ((param_4 == 0 || ((*(uint *)(iVar10 + 4 + DAT_0093b274) & param_4) == param_4)))) {
          uVar2 = *(ushort *)((int)param_3 + 6);
          uVar3 = *param_3;
          *(undefined4 *)(uVar3 + (uint)uVar2 * 0x1c) = 0;
          iVar1 = uVar3 + (uint)uVar2 * 0x1c;
          *(undefined4 *)(iVar1 + 4) = 0;
          *(undefined4 *)(iVar1 + 8) = 0;
          *(undefined4 *)(iVar1 + 0xc) = 0;
          *(undefined4 *)(iVar1 + 0x10) = 0;
          *(undefined4 *)(iVar1 + 0x14) = 0;
          *(undefined4 *)(iVar1 + 0x18) = 0;
          *(short *)(*param_3 + (uint)*(ushort *)((int)param_3 + 6) * 0x1c) = (short)iVar5;
          *(short *)((int)param_3 + 6) = *(short *)((int)param_3 + 6) + 1;
        }
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 0x120;
        iVar10 = iVar10 + 0x4c;
      } while (iVar5 < DAT_0093b278);
    }
  }
  *param_9 = *puVar4 + (uint)*(ushort *)((int)puVar4 + 6) * 0x1c;
  return;
}

