/* Ghidra pseudocode, not original source.
 * ev_17ab6c5fe37e6a0cb1bfccbcd3c83c7368534626b2237569a9f579541a9c35f4
 * Entry: 0x58baf0; label: FUN_0058baf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058baf0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  
  if ((param_1 != 0) && (iVar4 = 0, 0 < *(int *)(param_1 + 4))) {
    iVar3 = param_1 + 8;
    do {
      if (*(short *)(iVar3 + 0xc) != -1) {
        uVar7 = 0;
        iVar1 = 0;
        iVar5 = DAT_0093d504;
        if (0 < DAT_0093d500) {
LAB_0058bb33:
          if (((((*(uint *)(iVar5 + 0x1fc) & 1) == 0) || ((*(uint *)(iVar5 + 0x1fc) & 0x1000) == 0))
              || (*(char *)(iVar5 + 0x28b) != '\0')) ||
             (*(short *)(iVar5 + 0x1070) != *(short *)(iVar3 + 0xe))) goto LAB_0058bb5c;
          puVar2 = (undefined4 *)FUN_005d0330(iVar3);
          if (puVar2 != (undefined4 *)0x0) {
            puVar6 = (undefined4 *)(iVar5 + 0xb8);
            puVar8 = puVar2;
            for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
              *puVar8 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar8 = puVar8 + 1;
            }
            if (_DAT_0092505c + _DAT_0092505c < 1.0) {
              puVar2[0xd] = (float)puVar2[0xd] - (1.0 - (_DAT_0092505c + _DAT_0092505c));
            }
            FUN_005ea660(iVar3);
          }
          uVar7 = 1;
        }
LAB_0058bbc2:
        FUN_005cfc00(iVar3,uVar7);
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x14;
    } while (iVar4 < *(int *)(param_1 + 4));
  }
  return;
LAB_0058bb5c:
  iVar1 = iVar1 + 1;
  iVar5 = iVar5 + 0x10d8;
  if (DAT_0093d500 <= iVar1) goto LAB_0058bbc2;
  goto LAB_0058bb33;
}

