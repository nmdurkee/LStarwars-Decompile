/* Ghidra pseudocode, not original source.
 * ev_b786d52b0c6475300075d44c367bc307b08211d5064c161e2619fa192a4bae5f
 * Entry: 0x56f6a0; label: FUN_0056f6a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056f6a0(int *param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  undefined4 uVar11;
  
  iVar6 = FUN_0055f450();
  if (param_1 == (int *)0x0) {
    return;
  }
  iVar4 = *param_1;
  *(byte *)(iVar4 + 0x17) =
       *(byte *)(iVar4 + 0x17) ^ ((param_2 != 0) * '\x02' ^ *(byte *)(iVar4 + 0x17)) & 2;
  if (param_2 != 0) {
    FUN_005738c0(param_1,iVar4);
    puVar5 = PTR_PTR_008033b0;
    bVar1 = *(byte *)(iVar4 + 0x17);
    if ((bVar1 & 2) != 0) {
      *(byte *)(iVar4 + 0x17) = bVar1 | 0x80;
      if (((bVar1 & 0x40) == 0) || (cVar2 = puVar5[0xc], uVar7 = (uint)cVar2, cVar2 == -1)) {
        uVar7 = (uint)*(byte *)(iVar4 + 0x25);
      }
      iVar9 = *(int *)puVar5 + uVar7 * 0x38;
      if (DAT_00856c08 == 0) {
        if ((*(byte *)(iVar9 + 0xe) & 0x20) != 0) goto LAB_0056f79c;
      }
      else if ((*(byte *)(iVar9 + 0xe) & 0x20) == 0) goto LAB_0056f79c;
      iVar8 = FUN_0058a900(0);
      if (iVar8 == 0) {
        if (*(int *)(iVar9 + 4) != 0) {
          FUN_00681f40(*(int *)(iVar9 + 4),iVar4 + 8);
        }
        sVar3 = *(short *)(iVar9 + 0x2c);
        if (sVar3 != -1) {
          if ((*(byte *)(iVar4 + 0x17) & 0x40) == 0) {
            uVar11 = *(undefined4 *)(iVar6 + 0x134);
          }
          else {
            sVar3 = *(short *)(*(int *)PTR_PTR_008033b0 + 0x2c + (char)PTR_PTR_008033b0[0xb] * 0x38)
            ;
            uVar11 = *(undefined4 *)(iVar6 + 0x134);
          }
          FUN_0062c560(uVar11,(int)sVar3,iVar4 + 8);
        }
      }
    }
  }
LAB_0056f79c:
  if (*(char *)(iVar4 + 0x18) != '\0') {
    iVar9 = 0;
    if (0 < (*(int **)(iVar6 + 0x50b8))[2]) {
      pbVar10 = (byte *)(**(int **)(iVar6 + 0x50b8) + 0x17);
      do {
        if (pbVar10[1] == *(byte *)(iVar4 + 0x18)) {
          *pbVar10 = *pbVar10 & 0xf9 | ((byte)param_2 & 1) * '\x02' | ((byte)param_2 & 1) * '\x04';
        }
        iVar9 = iVar9 + 1;
        pbVar10 = pbVar10 + 0x2c;
      } while (iVar9 < *(int *)(*(int *)(iVar6 + 0x50b8) + 8));
    }
  }
  return;
}

