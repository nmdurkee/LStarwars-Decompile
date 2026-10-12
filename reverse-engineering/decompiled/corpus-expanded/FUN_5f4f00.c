/* Ghidra pseudocode, not original source.
 * ev_73151266ff1c8f163ed19691e079968d47cc326d45708775e4f70bdc31fc3cf9
 * Entry: 0x5f4f00; label: FUN_005f4f00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f4f00(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  
  puVar2 = (undefined4 *)FUN_005ef1d0(param_1,&param_2,param_3);
  if ((puVar2 != (undefined4 *)0x0) && (1 < param_4)) {
    iVar1 = param_4 * 4;
    iVar8 = param_4 + -1;
    uVar6 = *param_1 + 0x1fU & 0xffffffe0;
    iVar5 = 0;
    *param_1 = (*param_1 + 0x1fU & 0xffffffe0) + iVar1;
    if (0 < iVar8) {
      do {
        *(uint *)(uVar6 + iVar5 * 4) = *param_1 + 0x1fU & 0xffffffe0;
        *param_1 = (*param_1 + 0x1fU & 0xffffffe0) + 0x20c;
        puVar7 = puVar2;
        puVar9 = *(undefined4 **)(uVar6 + iVar5 * 4);
        for (iVar4 = 0x83; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar9 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar9 = puVar9 + 1;
        }
        uVar3 = FUN_005f0470(puVar2[0x44],param_1,param_2);
        *(undefined4 *)(*(int *)(uVar6 + iVar5 * 4) + 0x110) = uVar3;
        iVar4 = *(int *)(uVar6 + iVar5 * 4);
        iVar5 = iVar5 + 1;
        *(int *)(*(int *)(iVar4 + 0x110) + 0x78) = iVar4;
      } while (iVar5 < iVar8);
    }
    *(undefined4 *)(iVar1 + -4 + uVar6) = 0;
    puVar2[0x10] = uVar6;
  }
  return;
}

